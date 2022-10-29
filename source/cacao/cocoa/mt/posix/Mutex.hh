///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2016 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: Mutex.hh
///
/// Author: $author$
///   Date: 9/4/2016
///////////////////////////////////////////////////////////////////////
#ifndef _CACAO_COCOA_MT_POSIX_MUTEX_HH
#define _CACAO_COCOA_MT_POSIX_MUTEX_HH

#include "cacao/cocoa/mt/Mutex.hh"

#include <pthread.h>
#include <time.h>
#include <errno.h>

#if defined(_POSIX_TIMEOUTS) && (_POSIX_TIMEOUTS >=0 )
#if !defined(PTHREAD_MUTEX_HAS_TIMEDLOCK)
#define PTHREAD_MUTEX_HAS_TIMEDLOCK
#endif // !defined(PTHREAD_MUTEX_HAS_TIMEDLOCK)
#endif // defined(_POSIX_TIMEOUTS) && (_POSIX_TIMEOUTS >=0 )

namespace cacao {
namespace cocoa {
namespace mt {
namespace posix {

typedef mt::Mutex MutexAttacherImplement;
typedef Base MutexAttachedExtend;
typedef pthread_mutex_t* MutexAttachedT;
typedef AttacherT<MutexAttachedT, int, 0, MutexAttacherImplement> MutexAttacher;
typedef AttachedT<MutexAttachedT, int, 0, MutexAttacher, MutexAttachedExtend> MutexAttached;
typedef CreatedT<MutexAttachedT, int, 0, MutexAttacher, MutexAttached> MutexCreated;
typedef MutexAttacher MutexImplements;
typedef MutexCreated MutexExtends;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
template
<class TImplements = MutexImplements, class TExtends = MutexExtends>
class _EXPORT_CLASS MutexT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename TImplements::WaitStatus WaitStatus;
    static const WaitStatus WaitSuccess = WaitStatus::WaitSuccess;
    static const WaitStatus WaitFailed = WaitStatus::WaitFailed;
    static const WaitStatus WaitBusy = WaitStatus::WaitBusy;
    static const WaitStatus WaitInterrupted = WaitStatus::WaitInterrupted;
    static const WaitStatus WaitInvalid = WaitStatus::WaitInvalid;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    MutexT(pthread_mutex_t* attachedTo, bool isCreated)
    : Extends(attachedTo, isCreated) {
    }
    MutexT(pthread_mutex_t* attachedTo): Extends(attachedTo) {
    }
    MutexT(bool initallyLocked) {
        if (!(this->Create(initallyLocked))) {
            Creator::Exception e = Creator::FailedToCreate;
            throw (e);
        }
    }
    MutexT() {
        if (!(this->Create())) {
            Creator::Exception e = Creator::FailedToCreate;
            if ((this->Logging()))
            { LOG_ERROR("throw (e = Creator::FailedToCreate)..."); }
            throw (e);
        }
    }
    virtual ~MutexT() {
        if (!(this->Destroyed())) {
            Creator::Exception e = Creator::FailedToDestroy;
            if ((this->Logging()))
            { LOG_ERROR("throw (e = Creator::FailedToDestroy)..."); }
            throw (e);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Create(bool initallyLocked) {
        if (!(initallyLocked)) {
            return this->Create();
        }
        return false;
    }
    virtual bool Create() {
        if ((this->Destroyed())) {
            int err = 0;

            if ((this->Logging()))
            { LOG_DEBUG("pthread_mutexattr_init(&m_mutexattr)..."); }
            if (!(err = pthread_mutexattr_init(&m_mutexattr))) {

                if ((this->Logging()))
                { LOG_DEBUG("pthread_mutex_init(&m_mutex, &m_mutexattr)..."); }
                if (!(err = pthread_mutex_init(&m_mutex, &m_mutexattr))) {
                    this->AttachCreated(&m_mutex);

                    if ((this->Logging()))
                    { LOG_DEBUG("pthread_mutexattr_destroy(&m_mutexattr)..."); }
                    if ((err = pthread_mutexattr_destroy(&m_mutexattr))) {
                        if ((this->Logging()))
                        { LOG_ERROR("...failed err = " << err << " on pthread_mutexattr_destroy(&m_mutexattr)"); }
                    }
                    return true;
                }
                if ((this->Logging()))
                { LOG_DEBUG("pthread_mutexattr_destroy(&m_mutexattr)..."); }
                if ((err = pthread_mutexattr_destroy(&m_mutexattr))) {
                    if ((this->Logging()))
                    { LOG_ERROR("...failed err = " << err << " on pthread_mutexattr_destroy(&m_mutexattr)"); }
                }
            }
        }
        return false;
    }
    virtual bool Destroy() {
        pthread_mutex_t* mutex = 0;
        if ((mutex = this->Detach())) {
            int err = 0;

            if ((this->Logging()))
            { LOG_DEBUG("pthread_mutex_destroy(mutex)..."); }
            if ((err = pthread_mutex_destroy(mutex))) {

                if ((this->Logging()))
                { LOG_ERROR("...failed err = " << err << " on pthread_mutex_destroy(mutex)"); }
            } else {
                return true;
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Lock() {
        pthread_mutex_t* mutex = 0;
        int err = 0;
        if ((this->Logging()))
        { LOG_TRACE("pthread_mutex_lock(mutex)..."); }
        if ((mutex = this->m_attachedTo)) {
            if ((err = pthread_mutex_lock(mutex))) {
                if ((this->Logging()))
                { LOG_ERROR("...failed err = " << err << " on pthread_mutex_lock(mutex)"); }
            } else {
                return true;
            }
        }
        return false;
    }
    virtual bool Unlock() {
        pthread_mutex_t* mutex = 0;
        int err = 0;
        if ((this->Logging()))
        { LOG_TRACE("pthread_mutex_unlock(mutex)..."); }
        if ((mutex = this->m_attachedTo)) {
            if ((err = pthread_mutex_unlock(mutex))) {
                if ((this->Logging()))
                { LOG_ERROR("...failed err = " << err << " on pthread_mutex_unlock(mutex)"); }
            } else {
                return true;
            }
        }
        return false;
    }
    virtual WaitStatus TryLock() {
        pthread_mutex_t* mutex = 0;
        if ((mutex = this->m_attachedTo)) {
            int err = 0;
            if ((this->Logging()))
            { LOG_TRACE("pthread_mutex_trylock(mutex)..."); }
            if ((err =  pthread_mutex_trylock(mutex))) {
                switch(err) {
                case ETIMEDOUT:
                    if ((this->Logging()))
                    { LOG_TRACE("timedout err = " << err << " on pthread_mutex_trylock(mutex)"); }
                    return WaitBusy;
                case EINTR:
                    if ((this->Logging()))
                    { LOG_ERROR("interrupted err = " << err << " on pthread_mutex_trylock(mutex)"); }
                    return WaitInterrupted;
                default:
                    if ((this->Logging()))
                    { LOG_ERROR("failed err = " << err << " on pthread_mutex_trylock(mutex)"); }
                }
            } else {
                return WaitSuccess;
            }
        }
        return WaitFailed;
    }
    virtual WaitStatus TimedLock(mseconds_t waitMilliseconds) {
        pthread_mutex_t* mutex = 0;
        if ((mutex = this->m_attachedTo)) {
            int err = 0;

            if (0 < waitMilliseconds) {
#if defined(PTHREAD_MUTEX_HAS_TIMEDLOCK)
                struct timespec untilTime;
                clock_gettime(CLOCK_REALTIME, &untilTime);
                untilTime.tv_sec +=  waitMilliseconds/1000;
                untilTime.tv_nsec +=  (waitMilliseconds%1000)*1000;

                if ((this->Logging()))
                { LOG_TRACE("pthread_mutex_timedlock(mutex, &untilTime)..."); }
                if ((err = pthread_mutex_timedlock(mutex, &untilTime))) {
                    switch(err) {
                    case ETIMEDOUT:
                        if ((this->Logging()))
                        { LOG_TRACE("...timedout err = " << err << " on pthread_mutex_timedlock(mutex, &untilTime)"); }
                        return WaitBusy;
                    case EINTR:
                        if ((this->Logging()))
                        { LOG_ERROR("...interrupted err = " << err << " on pthread_mutex_timedlock(mutex, &untilTime)"); }
                        return WaitInterrupted;
                    default:
                        if ((this->Logging()))
                        { LOG_ERROR("...failed err = " << err << " on pthread_mutex_timedlock(mutex, &untilTime)"); }
                    }
                } else {
                    return WaitSuccess;
                }
#else // defined(PTHREAD_MUTEX_HAS_TIMEDLOCK)
                if ((this->Logging()))
                { LOG_ERROR("...failed invalid operation pthread_mutex_timedlock(mutex, &untilTime)"); }
                return WaitInvalid;
#endif // defined(PTHREAD_MUTEX_HAS_TIMEDLOCK)
            } else {
                if (0 == waitMilliseconds) {
                    if ((this->Logging()))
                    { LOG_TRACE("pthread_mutex_trylock(mutex)..."); }
                    if ((err =  pthread_mutex_trylock(mutex))) {
                        switch(err) {
                        case ETIMEDOUT:
                            if ((this->Logging()))
                            { LOG_TRACE("...timedout err = " << err << " on pthread_mutex_trylock(mutex)"); }
                            return WaitBusy;
                        case EINTR:
                            if ((this->Logging()))
                            { LOG_ERROR("...interrupted err = " << err << " on pthread_mutex_trylock(mutex)"); }
                            return WaitInterrupted;
                        default:
                            if ((this->Logging()))
                            { LOG_ERROR("...failed err = " << err << " on pthread_mutex_trylock(mutex)"); }
                        }
                    } else {
                        return WaitSuccess;
                    }
                } else {
                    if ((err =  pthread_mutex_lock(mutex))) {
                        if ((this->Logging()))
                        { LOG_ERROR("...failed err = " << err << " on pthread_mutex_lock(mutex)"); }
                    } else {
                        return WaitSuccess;
                    }
                }
            }
        }
        return WaitFailed;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    pthread_mutexattr_t m_mutexattr;
    pthread_mutex_t m_mutex;
};
typedef MutexT<> Mutex;

} // namespace posix 
} // namespace mt 
} // namespace cocoa 
} // namespace cacao 

#endif // _CACAO_COCOA_MT_POSIX_MUTEX_HH 
