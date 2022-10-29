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
///   File: Joined.hh
///
/// Author: $author$
///   Date: 9/1/2016
///////////////////////////////////////////////////////////////////////
#ifndef _CACAO_COCOA_BASE_JOINED_HH
#define _CACAO_COCOA_BASE_JOINED_HH

#include "cacao/cocoa/base/Waited.hh"

namespace cacao {
namespace cocoa {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
template <class TImplements = Waited, class TWaited = Waited>
class _EXPORT_CLASS JoinedT: virtual public TImplements {
public:
    typedef TImplements Implements;
    typedef TWaited Waited;
    typedef typename TWaited::WaitStatus WaitStatus;
    static const WaitStatus WaitSuccess = Waited::WaitSuccess;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    enum Exception {
        FailedToJoin,
        FailedToFork
    };
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Join() { return true; }
    virtual bool Fork() { return false; }
    virtual bool Joined() {
        if ((IsForked())) { return Join(); }
        return true;
    }
    virtual bool Forked() {
        if ((IsJoined())) { return Fork(); }
        return true;
    }
    virtual bool IsJoined() const { return true; }
    virtual bool IsForked() const { return false; }
    virtual WaitStatus TryJoin() { return WaitSuccess; }
    virtual WaitStatus TimedJoin
    (mseconds_t waitMilliSeconds) { return WaitSuccess; }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Wait() { return Join(); }
    virtual bool Continue() { return Fork(); }
    virtual WaitStatus TryWait() { return TryJoin(); }
    virtual WaitStatus TimedWait(mseconds_t waitMilliSeconds)
    { return TimedJoin(waitMilliSeconds); }
};
typedef JoinedT<> Joined;

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
template
<class TJoined = Joined,
 class TImplement = ImplementBase, class TExtend = Base>
class EXPORT_CLASS JoinerT: virtual public TImplement, public TExtend {
public:
    typedef TImplement Implements;
    typedef TExtend Extends;
    typedef TJoined JoinedT;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    JoinerT
    (JoinedT& joined, mseconds_t waitMilliseconds): m_joined(joined) {
        if (!(m_joined.TimedJoin(waitMilliseconds))){
            Joined::Exception e = Joined::FailedToJoin;
            LOG_ERROR("throw (e = Joined::FailedToJoin)...");
            throw (e);
        }
    }
    JoinerT(JoinedT& joined): m_joined(joined) {
        if (!(m_joined.Join())){
            LOG_ERROR("throw (e = Joined::FailedToJoin)...");
            Joined::Exception e = Joined::FailedToJoin;
            throw (e);
        }
    }
    virtual ~JoinerT(){
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    JoinedT& m_joined;
};
typedef JoinerT<> Joiner;

} // namespace cocoa
} // namespace cacao 

#endif // _CACAO_COCOA_BASE_JOINED_HH 
        

