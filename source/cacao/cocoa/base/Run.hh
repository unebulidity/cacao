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
///   File: Run.hh
///
/// Author: $author$
///   Date: 9/1/2016
///////////////////////////////////////////////////////////////////////
#ifndef _CACAO_COCOA_BASE_RUNNER_HH
#define _CACAO_COCOA_BASE_RUNNER_HH

#include "cacao/cocoa/base/Base.hh"

namespace cacao {
namespace cocoa {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
template <class TImplements = ImplementBase>
class _EXPORT_CLASS RunT: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    enum RunStatus {
        RunSuccess,
        RunFailed,
        RunInvalid
    };
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual RunStatus operator()() { return RunSuccess; }
};
typedef RunT<> Run;

} // namespace cocoa 
} // namespace cacao 

#endif // _CACAO_COCOA_BASE_RUNNER_HH 
