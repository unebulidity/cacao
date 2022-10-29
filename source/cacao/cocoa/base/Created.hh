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
///   File: Created.hh
///
/// Author: $author$
///   Date: 8/31/2016
///////////////////////////////////////////////////////////////////////
#ifndef _CACAO_COCOA_BASE_CREATED_HH
#define _CACAO_COCOA_BASE_CREATED_HH

#include "cacao/cocoa/base/Attached.hh"

namespace cacao {
namespace cocoa {

///////////////////////////////////////////////////////////////////////
///  Class: CreatorT
///////////////////////////////////////////////////////////////////////
template <class TImplements = ImplementBase>
class _EXPORT_CLASS CreatorT: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///  Enum: Exception
    ///////////////////////////////////////////////////////////////////////
    enum Exception {
        FailedToCreate,
        FailedToDestroy
    };
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Create() {
        return false;
    }
    virtual bool Destroy() {
        return false;
    }
    virtual bool Destroyed() {
        if ((IsCreated())) {
            return Destroy();
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetIsCreated(bool isTrue = true) {
        return false;
    }
    virtual bool IsCreated() const {
        return false;
    }
    virtual bool IsDestroyed() const {
        return !IsCreated();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef CreatorT<> Creator;

typedef Creator CreatedImplements;
typedef Base CreatedExtends;
///////////////////////////////////////////////////////////////////////
///  Class: CreatedT
///////////////////////////////////////////////////////////////////////
template
<typename TAttached,
 typename TUnattached = TAttached, TUnattached VUnattached = 0,
 class TImplement = AttacherT
 <TAttached, TUnattached, VUnattached, CreatedImplements>,
 class TExtend = AttachedT
 <TAttached, TUnattached, VUnattached, TImplement, CreatedExtends> >

class _EXPORT_CLASS CreatedT: virtual public TImplement, public TExtend {
public:
    typedef TImplement Implements;
    typedef TExtend Extends;
    typedef TAttached Attached;
    static const TUnattached Unattached = VUnattached;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    CreatedT
    (Attached attachedTo = ((Attached)(Unattached)), bool isCreated = false)
    : Extends(attachedTo), m_isCreated(isCreated) {
    }
    virtual ~CreatedT() {
        if (!(this->Destroyed())) {
            Creator::Exception e = Creator::FailedToDestroy;
            LOG_ERROR("throw (e = Creator::FailedToDestroy)...");
            throw (e);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual Attached AttachCreated(Attached attachedTo, bool isCreated = true) {
        attachedTo = this->Attach(attachedTo);
        this->SetIsCreated(isCreated);
        return attachedTo;
    }
    virtual Attached DetachCreated(bool& isCreated){
        Attached detached = this->Detach();
        isCreated = this->IsCreated();
        this->SetIsCreated(false);
        return detached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual Attached Attach(Attached attachedTo) {
        attachedTo = Extends::Attach(attachedTo);
        this->SetIsCreated(false);
        return attachedTo;
    }
    virtual Attached Detach(){
        Attached detached = Extends::Detach();
        this->SetIsCreated(false);
        return detached;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetIsCreated(bool isTrue = true) {
        m_isCreated = isTrue;
        return m_isCreated;
    }
    virtual bool IsCreated() const {
        return m_isCreated;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    bool m_isCreated;
};

} // namespace cocoa

namespace app {
namespace cocoa {

typedef cacao::cocoa::Creator Creator;

} // namespace cocoa
} // namespace app

} // namespace cacao

#endif // _CACAO_COCOA_BASE_CREATED_HH 
