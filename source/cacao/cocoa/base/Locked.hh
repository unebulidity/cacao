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
///   File: Locked.hh
///
/// Author: $author$
///   Date: 8/31/2016
///////////////////////////////////////////////////////////////////////
#ifndef _CACAO_COCOA_BASE_LOCKED_HH
#define _CACAO_COCOA_BASE_LOCKED_HH

#include "cacao/cocoa/base/Attached.hh"
#include "cacao/cocoa/base/Waited.hh"

namespace cacao {
namespace cocoa {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
template <class TImplements = Waited, class TWaited = Waited>
class EXPORT_CLASS LockedT: virtual public TImplements {
public:
    typedef TImplements Implements;
    typedef TWaited Waited;
    typedef typename TWaited::WaitStatus WaitStatus;
    static const WaitStatus WaitSuccess = Waited::WaitSuccess;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    enum Exception {
        FailedToLock,
        FailedToUnlock
    };
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Lock() { return true; }
    virtual bool Unlock() { return true; }
    virtual WaitStatus TryLock() { return WaitSuccess; }
    virtual WaitStatus TimedLock
    (mseconds_t waitMilliseconds) { return WaitSuccess; }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Wait() { return Lock(); }
    virtual bool Continue() { return Unlock(); }
    virtual WaitStatus TryWait() { return TryLock(); }
    virtual WaitStatus TimedWait
    (mseconds_t waitMilliSeconds) { return TimedLock(waitMilliSeconds); }
};
typedef LockedT<> Locked;

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
template
<class TLocked = Locked,
 class TImplement = ImplementBase, class TExtend = Base>
class EXPORT_CLASS LockerT: virtual public TImplement, public TExtend {
public:
    typedef TImplement Implements;
    typedef TExtend Extends;
    typedef TLocked LockedT;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    LockerT
    (LockedT& locked, mseconds_t waitMilliseconds): m_locked(locked) {
        if (!(m_locked.TimedLock(waitMilliseconds))){
            Locked::Exception e = Locked::FailedToLock;
            LOG_ERROR("throw (e = Locked::FailedToLock)...");
            throw (e);
        }
    }
    LockerT(LockedT& locked): m_locked(locked) {
        if (!(m_locked.Lock())){
            LOG_ERROR("throw (e = Locked::FailedToLock)...");
            Locked::Exception e = Locked::FailedToLock;
            throw (e);
        }
    }
    virtual ~LockerT(){
        if (!(m_locked.Unlock())) {
            LOG_ERROR("throw (e = Locked::FailedToUnlock)...");
            Locked::Exception e = Locked::FailedToUnlock;
            throw (e);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    LockedT& m_locked;
};
typedef LockerT<> Locker;

} // namespace cocoa
} // namespace cacao 

#endif // _CACAO_COCOA_BASE_LOCKED_HH 
