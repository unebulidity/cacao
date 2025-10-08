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
#ifndef _CACAO_COCOA_MT_MUTEX_HH
#define _CACAO_COCOA_MT_MUTEX_HH

#include "cacao/cocoa/base/Created.hh"
#include "cacao/cocoa/base/Locked.hh"
#include "cacao/cocoa/base/Waited.hh"

namespace cacao {
namespace cocoa {
namespace mt {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS MutexImplements
: virtual public Waited, virtual public Locked, virtual public Creator {
public:
    typedef cocoa::Waited Waited;
    typedef Waited::WaitStatus WaitStatus;
    typedef cocoa::Locked Locked;
    typedef cocoa::Creator Creator;
};
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
template <class TImplements = MutexImplements>
class _EXPORT_CLASS MutexT: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using TImplements::Create;
    virtual bool Create(bool initallyLocked) { return false; }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Logging() const { return true; }
};
typedef MutexT<> Mutex;

} // namespace mt 
} // namespace cocoa 
} // namespace cacao 

#endif // _CACAO_COCOA_MT_MUTEX_HH 
