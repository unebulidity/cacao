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
///   File: Waited.hh
///
/// Author: $author$
///   Date: 8/31/2016
///////////////////////////////////////////////////////////////////////
#ifndef _CACAO_COCOA_BASE_WAITED_HH
#define _CACAO_COCOA_BASE_WAITED_HH

#include "cacao/cocoa/base/Base.hh"

namespace cacao {
namespace cocoa {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
template <class TImplements = ImplementBase>
class _EXPORT_CLASS WaitedT: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    enum {
        WaitForever = -1
    };
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    enum WaitStatus {
        WaitSuccess,
        WaitFailed,
        WaitBusy,
        WaitInterrupted,
        WaitInvalid
    };
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Wait() { return false; }
    virtual bool Continue() { return false; }
    virtual WaitStatus TryWait() { return WaitFailed; }
    virtual WaitStatus TimedWait
    (mseconds_t waitMilliSeconds) { return WaitFailed; }
};
typedef WaitedT<> Waited;

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
template
<class TWaited = Waited,
 class TImplement = ImplementBase, class TExtend = Base>
class _EXPORT_CLASS WaiterT: virtual public TImplement, public TExtend {
public:
    typedef TImplement Implements;
    typedef TExtend Extends;
    typedef TWaited Waited;
    typedef typename Waited::WaitStatus WaitStatus;
    static const WaitStatus WaitSuccess = Waited::WaitSuccess;
    static const WaitStatus WaitFailed = Waited::WaitFailed;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    WaiterT(Waited& waited, mseconds_t waitMilliSeconds) {
        WaitStatus status = WaitFailed;
        if (WaitSuccess != (status = waited.TimedWait(waitMilliSeconds))) {
            throw (status);
        }
    }
    WaiterT(Waited& waited) {
        if (!(waited.Wait())) {
            WaitStatus status = WaitFailed;
            throw (status);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef WaiterT<> Waiter;

} // namespace cocoa
} // namespace cacao 

#endif // _CACAO_COCOA_BASE_WAITED_HH
