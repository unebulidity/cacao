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
///   File: Os.hh
///
/// Author: $author$
///   Date: 8/31/2016
///////////////////////////////////////////////////////////////////////
#ifndef _CACAO_COCOA_OS_OS_HH
#define _CACAO_COCOA_OS_OS_HH

#if !defined(USE_NADIR_BASE)
#include "xos/base/platform_build.hpp"
#else // !defined(USE_NADIR_BASE)
#include "nadir/platform/platform_build.h"
#endif // !defined(USE_NADIR_BASE)

namespace cacao {
namespace cocoa {

namespace apple {
namespace osx {
} // namespace osx
namespace ios {
} // namespace ios
} // namespace apple

#if defined(MACOSX)
namespace os = apple::osx;
#else // defined(MACOSX)
#error Unsupported OS
#endif // defined(MACOSX)

} // namespace cocoa 
} // namespace cacao 

#endif // _CACAO_COCOA_OS_OS_HH 
