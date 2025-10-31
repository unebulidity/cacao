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
///   File: iDentifyMain.mm
///
/// Author: $author$
///   Date: 10/30/2025
//////////////////////////////////////////////////////////////////////////
#include "cacao/app/cocoa/apple/osx/iDentify/iDentifyMain.hh"
#include "cacao/app/cocoa/apple/osx/iDentify/MainWindow.hh"
#include "cacao/cocoa/apple/osx/Logger.hh"

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
/// Implentation: iDentifyMain
///////////////////////////////////////////////////////////////////////
@implementation iDentifyMain

    - (iDentifyMain*)initWithApplication:(Application*)application {

        if (([super initWithApplication:application])) {

            if ((_mainWindowPeer = new iDentifyMainWindowPeer())) {
                return self;
            }
        }
        return nil;
    }

    - (MainWindow*)createWindow {
        NSRect contentRect = [self windowContentRect];
        Application* application = [super application];
        iDentifyMainWindow* window = nil;

        LOG_DEBUG("[[iDentifyMainWindow alloc] initWithContentRect:contentRect application:application mainWindowPeer:_mainWindowPeer]...");
        if ((window = [[iDentifyMainWindow alloc] initWithContentRect:contentRect application:application mainWindowPeer:_mainWindowPeer])) {
            return window;
        } else {
            LOG_ERROR("...failed on [[iDentifyMainWindow alloc] initWithContentRect:contentRect application:application mainWindowPeer:_mainWindowPeer]");
        }
        return nil;
    }

    - (NSRect)windowContentRect {
        return NSMakeRect(0,0, 640,480);
    }
@end
        
///////////////////////////////////////////////////////////////////////
/// Implentation: ApplicationMain
///////////////////////////////////////////////////////////////////////
@implementation ApplicationMain

    + (id<Main>)createWithApplication:(Application*)application {
        Main* main = nil;

        LOG_DEBUG("[[iDentifyMain alloc] initWithApplication:application]...");
        if ((main = [[iDentifyMain alloc] initWithApplication:application])) {
            return main;
        } else {
            LOG_ERROR("...failed on [[iDentifyMain alloc] initWithApplication:application]");
        }
        return nil;
    }
@end

