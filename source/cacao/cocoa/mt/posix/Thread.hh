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
///   File: Thread.hh
///
/// Author: $author$
///   Date: 9/1/2016
///////////////////////////////////////////////////////////////////////
#ifndef _CACAO_COCOA_MT_POSIX_THREAD_HH
#define _CACAO_COCOA_MT_POSIX_THREAD_HH

#include "cacao/cocoa/mt/Thread.hh"
#include "cacao/cocoa/base/Created.hh"

#include <pthread.h>
#include <time.h>
#include <errno.h>

#if defined(_POSIX_TIMEOUTS) && (_POSIX_TIMEOUTS >=0 )
#if !defined(PTHREAD_HAS_TRYJOIN)
#define PTHREAD_HAS_TRYJOIN
#endif // !defined(PTHREAD_HAS_TRYJOIN)
#if !defined(PTHREAD_HAS_TIMEDJOIN)
#define PTHREAD_HAS_TIMEDJOIN
#endif // !defined(PTHREAD_HAS_TIMEDJOIN)
#endif // defined(_POSIX_TIMEOUTS) && (_POSIX_TIMEOUTS >=0 )

namespace cacao {
namespace cocoa {
namespace mt {
namespace posix {

typedef CreatorT<mt::Thread> ThreadAttacherImplement;
typedef Base ThreadAttachedExtend;
typedef pthread_t* ThreadAttachedT;
typedef AttacherT<ThreadAttachedT, int, 0, ThreadAttacherImplement> ThreadAttacher;
typedef AttachedT<ThreadAttachedT, int, 0, ThreadAttacher, ThreadAttachedExtend> ThreadAttached;
typedef CreatedT<ThreadAttachedT, int, 0, ThreadAttacher, ThreadAttached> ThreadCreated;
typedef ThreadAttacher ThreadImplements;
typedef ThreadCreated ThreadExtends;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
template <class TImplements = ThreadImplements, class TExtends = ThreadExtends>
class _EXPORT_CLASS ThreadT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Implements::Waited Waited;
    typedef typename Implements::WaitStatus WaitStatus;
    static const WaitStatus WaitSuccess = Waited::WaitSuccess;
    static const WaitStatus WaitFailed = Waited::WaitFailed;
    static const WaitStatus WaitBusy = Waited::WaitBusy;
    static const WaitStatus WaitInterrupted = Waited::WaitInterrupted;
    static const WaitStatus WaitInvalid = Waited::WaitInvalid;
    typedef typename Implements::Run Run;
    typedef typename Implements::RunStatus RunStatus;
    static const RunStatus RunSuccess = Run::RunSuccess;
    static const RunStatus RunFailed = Run::RunFailed;
    static const RunStatus RunInvalid = Run::RunInvalid;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ThreadT(Run& run): m_run(run), m_forked(false) {
        if (!(this->Create())) {
            Creator::Exception e = Creator::FailedToCreate;
            LOG_ERROR("throw (e = Creator::FailedToCreate)...");
            throw (e);
        }
    }
    ThreadT(): m_run(*this), m_forked(false) {
        if (!(this->Create())) {
            Creator::Exception e = Creator::FailedToCreate;
            LOG_ERROR("throw (e = Creator::FailedToCreate)...");
            throw (e);
        }
    }
    virtual ~ThreadT() {
        if (!(this->Destroyed())) {
            Creator::Exception e = Creator::FailedToDestroy;
            LOG_ERROR("throw (e = Creator::FailedToDestroy)...");
            throw (e);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Create(bool initiallySuspended) {
        if (!(initiallySuspended)) {
            return this->Create(); }
        return false;
    }
    virtual bool Create() {
        if ((this->Destroyed())) {
            int err = 0;
            LOG_DEBUG("pthread_attr_init()...");
            if (!(err = pthread_attr_init(&m_attr))) {
                LOG_DEBUG("pthread_create()...");
                if (!(err = pthread_create(&m_thread, &m_attr, StartRoutine, (void*)(this)))) {
                    this->AttachCreated(&m_thread, m_forked = true);
                    if ((err = pthread_attr_destroy(&m_attr))) {
                        LOG_ERROR("...failed " << err << " on pthread_attr_destroy()");
                    }
                    return true;
                } else {
                    LOG_ERROR("...failed " << err << " on pthread_create()");
                }
                LOG_DEBUG("pthread_attr_destroy()...");
                if ((err = pthread_attr_destroy(&m_attr))) {
                    LOG_ERROR("...failed " << err << " on pthread_attr_destroy()");
                }
            } else {
                LOG_ERROR("...failed " << err << " on pthread_attr_init()");
            }
        }
        return false;
    }
    virtual bool Destroy() {
        if ((this->Joined())) {
            pthread_t* thread = 0;
            bool isCreated = false;
            if ((thread = this->DetachCreated(isCreated))) {
                return true;
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Join() {
        pthread_t* thread = 0;
        if ((thread = this->m_attachedTo)) {
            void* value = 0;
            int err = 0;
            LOG_DEBUG("pthread_join()...");
            if (!(err =  pthread_join(*thread, &value))) {
                return true;
            } else {
                LOG_ERROR("failed " << err << " on pthread_join()");
            }
        }
        return false;
    }
    virtual WaitStatus TryJoin() {
#if defined(PTHREAD_HAS_TRYJOIN)
        pthread_t* thread = 0;
        if ((thread = this->m_attachedTo)) {
            void* value = 0;
            int err = 0;
            if ((err =  pthread_tryjoin_np(*thread, &value))) {
                switch(err) {
                case ETIMEDOUT:
                    LOG_DEBUG("...timedout " << err << " on pthread_tryjoin_np()");
                    return WaitBusy;
                case EINTR:
                    LOG_ERROR("...interrupted " << err << " on pthread_tryjoin_np()");
                    return WaitInterrupted;
                default:
                    LOG_ERROR("...failed " << err << " on pthread_tryjoin_np()");
                }
            } else {
                return WaitSuccess;
            }
        }
        return WaitFailed;
#else // defined(PTHREAD_HAS_TRYJOIN)
        LOG_ERROR("...failed invalid on pthread_tryjoin()");
        return WaitInvalid;
#endif // defined(PTHREAD_HAS_TRYJOIN)
    }
    virtual WaitStatus TimedJoin(mseconds_t waitMilliseconds) {
        pthread_t* thread = 0;
        void* value = 0;
        int err = 0;
        if ((thread = this->m_attachedTo)) {
            if (0 < waitMilliseconds) {
#if defined(PTHREAD_HAS_TIMEDJOIN)
                struct timespec untilTime;
                clock_gettime(CLOCK_REALTIME, &untilTime);
                untilTime.tv_sec +=  waitMilliseconds/1000;
                untilTime.tv_nsec +=  (waitMilliseconds%1000)*1000;
                if ((err =  pthread_timedjoin_np(*thread, &value, &untilTime))) {
                    switch(err) {
                    case ETIMEDOUT:
                        LOG_DEBUG("...timedout " << err << " on pthread_timedjoin_np()");
                        return WaitBusy;
                    case EINTR:
                        LOG_ERROR("...interrupted " << err << " on pthread_timedjoin_np()");
                        return WaitInterrupted;
                    default:
                        LOG_ERROR("...failed " << err << " on pthread_timedjoin_np()");
                    }
                } else {
                    return WaitSuccess;
                }
#else // defined(PTHREAD_HAS_TIMEDJOIN)
                LOG_ERROR("...failed invalid on pthread_timedjoin()");
                return WaitInvalid;
#endif // defined(PTHREAD_HAS_TIMEDJOIN)
            } else {
                if (0 == waitMilliseconds) {
#if defined(PTHREAD_HAS_TRYJOIN)
                    if ((err =  pthread_tryjoin_np(*thread, &value))) {
                        switch(err) {
                        case ETIMEDOUT:
                            LOG_DEBUG("...timedout " << err << " on pthread_tryjoin_np()");
                            return WaitBusy;
                        case EINTR:
                            LOG_ERROR("...interrupted " << err << " on pthread_tryjoin_np()");
                            return WaitInterrupted;
                        default:
                            LOG_ERROR("...failed " << err << " on pthread_tryjoin_np()");
                        }
                    } else {
                        return WaitSuccess;
                    }
#else // defined(PTHREAD_HAS_TRYJOIN)
                    LOG_ERROR("...failed invalid on pthread_tryjoin()");
                    return WaitInvalid;
#endif // defined(PTHREAD_HAS_TRYJOIN)
                } else {
                    if ((err =  pthread_join(*thread, &value))) {
                        LOG_ERROR("...failed " << err << " on pthread_join()");
                    } else {
                        return WaitSuccess;
                    }
                }
            }
        }
        return WaitFailed;
    }
    virtual bool IsJoined() const {
        return !IsForked();
    }
    virtual bool IsForked() const {
        return m_forked;
    }
protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual RunStatus operator()() {
        LOG_DEBUG("return RunSuccess...");
        return RunSuccess;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static void* StartRoutine(void* param) {
        void* result = 0;
        ThreadT* t = 0;
        LOG_DEBUG("in...");
        if ((t = (ThreadT*)(param))) {
            LOG_DEBUG("t->m_run()...");
            RunStatus status = t->m_run();
            LOG_DEBUG("..." << String(status) << " = t->m_run()");
        } else {
            LOG_ERROR("void* param == 0");
        }
        LOG_DEBUG("...out");
        return result;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    Run& m_run;
    bool m_forked;
    pthread_t m_thread;
    pthread_attr_t m_attr;
};
typedef ThreadT<> Thread;

} // namespace posix
} // namespace mt
} // namespace cocoa
} // namespace cacao 

#endif // _CACAO_COCOA_MT_POSIX_THREAD_HH 
