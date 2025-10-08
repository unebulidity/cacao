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
///   File: Semaphore.hh
///
/// Author: $author$
///   Date: 9/4/2016
///////////////////////////////////////////////////////////////////////
#ifndef _CACAO_COCOA_MT_APPLE_MACH_SEMAPHORE_HH
#define _CACAO_COCOA_MT_APPLE_MACH_SEMAPHORE_HH

#include "cacao/cocoa/mt/Semaphore.hh"
#include "cacao/cocoa/base/Waited.hh"

#include <mach/task.h>
#include <mach/mach.h>
#include <mach/semaphore.h>

namespace cacao {
namespace cocoa {
namespace mt {
namespace apple {
namespace mach {

typedef mt::Semaphore SemaphoreAttacherImplement;
typedef Base SemaphoreAttachedExtend;
typedef semaphore_t* SemaphoreAttachedT;
typedef AttacherT
<SemaphoreAttachedT, int, 0, SemaphoreAttacherImplement> SemaphoreAttacher;
typedef AttachedT
<SemaphoreAttachedT, int, 0, SemaphoreAttacher, SemaphoreAttachedExtend> SemaphoreAttached;
typedef CreatedT
<SemaphoreAttachedT, int, 0, SemaphoreAttacher, SemaphoreAttached> SemaphoreCreated;
typedef SemaphoreAttacher SemaphoreImplements;
typedef SemaphoreCreated SemaphoreExtends;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
template
<class TImplements = SemaphoreImplements, class TExtends = SemaphoreExtends>
class _EXPORT_CLASS SemaphoreT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename TImplements::Waited Waited;
    typedef typename TImplements::WaitStatus WaitStatus;
    static const WaitStatus WaitSuccess = Waited::WaitSuccess;
    static const WaitStatus WaitFailed = Waited::WaitFailed;
    static const WaitStatus WaitBusy = Waited::WaitBusy;
    static const WaitStatus WaitInterrupted = Waited::WaitInterrupted;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    SemaphoreT(semaphore_t* attachedTo, bool isCreated)
    : Extends(attachedTo, isCreated) {
    }
    SemaphoreT(semaphore_t* attachedTo): Extends(attachedTo) {
    }
    SemaphoreT(size_t initialCount) {
        if (!(this->Create(initialCount))) {
            Creator::Exception e = Creator::FailedToCreate;
            LOG_ERROR("throw (e = Creator::FailedToCreate)...");
            throw (e);
        }
    }
    SemaphoreT() {
        if (!(this->Create())) {
            Creator::Exception e = Creator::FailedToCreate;
            LOG_ERROR("throw (e = Creator::FailedToCreate)...");
            throw (e);
        }
    }
    virtual ~SemaphoreT() {
        if (!(this->Destroyed())) {
            Creator::Exception e = Creator::FailedToDestroy;
            LOG_ERROR("throw (e = Creator::FailedToDestroy)...");
            throw (e);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Create() {
        return Create(0);
    }
    virtual bool Create(size_t initialCount) {
        if ((this->Destroyed())) {
            task_t task = mach_task_self();
            sync_policy_t syncPolicy = SYNC_POLICY_FIFO;
            int err = 0;
            LOG_DEBUG("semaphore_create(task, &m_sem, syncPolicy, initialCount)...");
            if ((KERN_SUCCESS == (err = semaphore_create
                (task, &m_sem, syncPolicy, initialCount)))) {
                this->AttachCreated(&m_sem);
                return true;
            } else {
                LOG_ERROR("...failed " << err << " on semaphore_create(task, &m_sem, syncPolicy, initialCount)");
            }
        }
        return false;
    }
    virtual bool Destroy() {
        task_t task = mach_task_self();
        semaphore_t* sem = 0;
        if ((sem = this->Detach())) {
            int err = 0;
            LOG_DEBUG("semaphore_cdestroy(task, *sem)...");
            if ((KERN_SUCCESS == (err = semaphore_destroy(task, *sem)))) {
                return true;
            } else {
                LOG_ERROR("...failed " << err << " on semaphore_destroy(task, *sem)");
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Acquire() {
        semaphore_t* sem = 0;
        if ((sem = this->m_attachedTo)) {
            int err = 0;
            LOG_TRACE("semaphore_wait(*sem)...");
            if ((KERN_SUCCESS == (err = semaphore_wait(*sem)))) {
                LOG_DEBUG("...waited on semaphore_wait()");
                return true;
            } else {
                LOG_ERROR("...failed " << err << " on semaphore_wait(*sem)");
            }
        }
        return false;
    }
    virtual bool Release() {
        semaphore_t* sem = 0;
        if ((sem = this->m_attachedTo)) {
            int err = 0;
            LOG_TRACE("semaphore_signal(*sem)...");
            if ((KERN_SUCCESS == (err = semaphore_signal(*sem)))) {
                return true;
            } else {
                LOG_ERROR("failed " << err << " on semaphore_signal(*sem)");
            }
        }
        return false;
    }
    virtual WaitStatus TryAcquire() {
        return TimedAcquire(0);
    }
    virtual WaitStatus TimedAcquire(mseconds_t waitMilliseconds) {
        semaphore_t* sem = 0;
        if ((sem = this->m_attachedTo)) {
            int err = 0;
            if (0 <= (waitMilliseconds)) {
                mach_timespec_t waitTime;
                waitTime.tv_sec = waitMilliseconds/1000;
                waitTime.tv_nsec = (waitMilliseconds%1000)*1000;

                LOG_TRACE("semaphore_timedwait(*sem, waitTime)...");
                if (KERN_SUCCESS == (err = semaphore_timedwait(*sem, waitTime))) {
                    LOG_TRACE("...semaphore_timedwait(*sem, waitTime)");
                    return WaitSuccess;
                } else {
                    if (KERN_OPERATION_TIMED_OUT == (err)) {
                        LOG_TRACE("...KERN_OPERATION_TIMED_OUT on semaphore_timedwait(*sem, waitTime)");
                        return WaitBusy;
                    } else {
                        if (KERN_ABORTED == (err)) {
                            LOG_TRACE("...KERN_ABORTED on semaphore_timedwait(*sem, waitTime)");
                            return WaitInterrupted;
                        } else {
                            LOG_TRACE("...failed " << err << " on semaphore_timedwait(*sem, waitTime)");
                        }
                    }
                }
            } else {
                LOG_TRACE("semaphore_wait(*sem)...");
                if (KERN_SUCCESS == (err = semaphore_wait(*sem))) {
                    LOG_TRACE("...semaphore_wait(*sem)");
                    return WaitSuccess;
                } else {
                    LOG_ERROR("...failed " << err << " on semaphore_wait(*sem)");
                }
            }
        }
        return WaitFailed;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    semaphore_t m_sem;
};
typedef SemaphoreT<> Semaphore;

} // namespace mach
} // namespace apple 
} // namespace mt 
} // namespace cocoa 
} // namespace cacao 

#endif // _CACAO_COCOA_MT_APPLE_MACH_SEMAPHORE_HH 
