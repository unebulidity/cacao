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
#ifndef _CACAO_COCOA_MT_THREAD_HH
#define _CACAO_COCOA_MT_THREAD_HH

#include "cacao/cocoa/base/Created.hh"
#include "cacao/cocoa/base/Joined.hh"
#include "cacao/cocoa/base/Run.hh"

namespace cacao {
namespace cocoa {
namespace mt {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS ThreadImplements
: virtual public Joined, virtual public Creator, virtual public Run {
public:
};

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
template <class TImplements = ThreadImplements>
class _EXPORT_CLASS ThreadT: virtual public TImplements {
public:
    typedef TImplements Implements;
    typedef cocoa::Run Run;
    typedef Run::RunStatus RunStatus;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Implements::Create;
    virtual bool Create(bool initiallySuspended) { return false; }
    virtual bool Resume() { return false; }
    virtual bool Suspend() { return false; }
};
typedef ThreadT<> Thread;

} // namespace mt
} // namespace cocoa 
} // namespace cacao 

#endif // _CACAO_COCOA_MT_THREAD_HH 
