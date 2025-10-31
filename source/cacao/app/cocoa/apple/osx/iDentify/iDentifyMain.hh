//////////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2025 $organization$
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
///   File: iDentifyMain.hh
///
/// Author: $author$
///   Date: 10/30/2025
//////////////////////////////////////////////////////////////////////////
#ifndef CACAO_APP_COCOA_APPLE_OSX_IDENTIFY_IDENTIFYMAIN_HH
#define CACAO_APP_COCOA_APPLE_OSX_IDENTIFY_IDENTIFYMAIN_HH

#include "cacao/app/cocoa/apple/osx/iDentify/iDentifyMainWindow.hh"
#include "cacao/cocoa/apple/osx/Main.hh"

namespace cacao {
namespace app {
namespace cocoa {
namespace apple {
namespace osx {
namespace iDentify {

} /// namespace iDentify 
} /// namespace osx 
} /// namespace apple 
} /// namespace cocoa 
} /// namespace app 
} /// namespace cacao 

///////////////////////////////////////////////////////////////////////
/// Interface: iDentifyMain
///////////////////////////////////////////////////////////////////////
@interface iDentifyMain: Main {
    }
    @property (assign) iDentifyMainWindowPeer* mainWindowPeer;

    - (iDentifyMain*)initWithApplication:(Application*)application;
@end

#endif /// ndef CACAO_APP_COCOA_APPLE_OSX_IDENTIFY_IDENTIFYMAIN_HH

