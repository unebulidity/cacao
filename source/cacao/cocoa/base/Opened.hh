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
///   File: Opened.hh
///
/// Author: $author$
///   Date: 8/31/2016
///////////////////////////////////////////////////////////////////////
#ifndef _CACAO_COCOA_BASE_OPENED_HH
#define _CACAO_COCOA_BASE_OPENED_HH

#include "cacao/cocoa/base/Attached.hh"

namespace cacao {
namespace cocoa {

///////////////////////////////////////////////////////////////////////
///  Class: OpenerT
///////////////////////////////////////////////////////////////////////
template <class TImplements = ImplementBase>
class _EXPORT_CLASS OpenerT: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    enum Exception {
        FailedToOpen,
        FailedToClose
    };
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Open() {
        return false;
    }
    virtual bool Close() {
        return false;
    }
    virtual bool Closed() {
        if ((IsOpen())) {
            return Close();
        }
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetIsOpen(bool isOpen = true) {
        return false;
    }
    virtual bool IsOpen() const {
        return false;
    }
    virtual bool IsClosed() const {
        return !IsOpen();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef OpenerT<> Opener;

///////////////////////////////////////////////////////////////////////
///  Class: OpenedT
///////////////////////////////////////////////////////////////////////
template
<class TAttached,
 class TUnattached = TAttached, TUnattached VUnattached = 0,
 class TImplement = OpenerT
 <AttacherT<TAttached, TUnattached, VUnattached, ImplementBase> >,
 class TExtend = AttachedT
 <TAttached, TUnattached, VUnattached, TImplement, Base> >

class _EXPORT_CLASS OpenedT: virtual public TImplement, public TExtend {
public:
    typedef TImplement Implements;
    typedef TExtend Extends;
    typedef TAttached Attached;
    static const TUnattached Unattached = VUnattached;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    OpenedT
    (Attached attachedTo = ((Attached)(Unattached)), bool isOpen=false)
    : Extends(attachedTo), m_isOpen(isOpen) {
    }
    virtual ~OpenedT() {
        if (!(this->Closed())) {
            Opener::Exception e = Opener::FailedToClose;
            LOG_ERROR("throw (e = Opener::FailedToClose)...");
            throw (e);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual Attached AttachOpened(Attached attachedTo) {
        m_isOpen = ((attachedTo = this->Attach(attachedTo)) != ((Attached)Unattached));
        return attachedTo;
    }
    virtual Attached Detach(bool& isOpen) {
        isOpen = m_isOpen;
        return Detach();
    }
    virtual Attached Detach() {
        m_isOpen = false;
        return Extends::Detach();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool SetIsOpen(bool isOpen = true) {
        m_isOpen = isOpen;
        return m_isOpen;
    }
    virtual bool IsOpen() const {
        return m_isOpen;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    bool m_isOpen;
};

} // namespace cocoa
} // namespace cacao 

#endif // _CACAO_COCOA_BASE_OPENED_HH 
