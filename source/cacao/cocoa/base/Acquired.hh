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
///   File: Acquired.hh
///
/// Author: $author$
///   Date: 8/31/2016
///////////////////////////////////////////////////////////////////////
#ifndef _CACAO_COCOA_BASE_ACQUIRED_HH
#define _CACAO_COCOA_BASE_ACQUIRED_HH

#include "cacao/cocoa/base/Waited.hh"

namespace cacao {
namespace cocoa {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
template <class TImplements = Waited, class TWaited = Waited>
class _EXPORT_CLASS AcquiredT: virtual public TImplements {
public:
    typedef TImplements Implements;
    typedef TWaited Waited;
    typedef typename TWaited::WaitStatus WaitStatus;
    static const WaitStatus WaitSuccess = Waited::WaitSuccess;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    enum Exception {
        FailedToAcquire,
        FailedToRelease
    };
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Acquire() { return true; }
    virtual bool Release() { return true; }
    virtual ssize_t Acquire(size_t amount) { return amount; }
    virtual ssize_t Release(size_t amount) { return amount; }
    virtual bool IsAcquired() const { return false; }
    virtual ssize_t HasAcquired() const { return 0; }
    virtual WaitStatus TryAcquire() { return WaitSuccess; }
    virtual WaitStatus TimedAcquire
    (mseconds_t waitMilliSeconds) { return WaitSuccess; }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Wait() { return Acquire(); }
    virtual bool Continue() { return Release(); }
    virtual WaitStatus TryWait(){ return TryAcquire(); }
    virtual WaitStatus TimedWait(mseconds_t waitMilliSeconds)
    { return TimedAcquire(waitMilliSeconds); }
};
typedef AcquiredT<> Acquired;

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
template
<class TAcquired = Acquired,
 class TImplement = ImplementBase, class TExtend = Base>
class EXPORT_CLASS AcquirerT: virtual public TImplement, public TExtend {
public:
    typedef TImplement Implements;
    typedef TExtend Extends;
    typedef TAcquired AcquiredT;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    AcquirerT
    (AcquiredT& acquired, mseconds_t waitMilliseconds): m_acquired(acquired) {
        if (!(m_acquired.TimedAcquire(waitMilliseconds))){
            Acquired::Exception e = Acquired::FailedToAcquire;
            LOG_ERROR("throw (e = Acquired::FailedToAcquire)...");
            throw (e);
        }
    }
    AcquirerT(AcquiredT& acquired): m_acquired(acquired) {
        if (!(m_acquired.Acquire())){
            LOG_ERROR("throw (e = Acquired::FailedToAcquire)...");
            Acquired::Exception e = Acquired::FailedToAcquire;
            throw (e);
        }
    }
    virtual ~AcquirerT(){
        if (!(m_acquired.Release())) {
            LOG_ERROR("throw (e = Acquired::FailedToRelease)...");
            Acquired::Exception e = Acquired::FailedToRelease;
            throw (e);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    AcquiredT& m_acquired;
};
typedef AcquirerT<> Acquirer;

} // namespace cocoa
} // namespace cacao 

#endif // _CACAO_COCOA_BASE_ACQUIRED_HH 
