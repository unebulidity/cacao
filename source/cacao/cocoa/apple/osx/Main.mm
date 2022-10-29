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
///   File: Main.mm
///
/// Author: $author$
///   Date: 8/29/2016
///////////////////////////////////////////////////////////////////////
#include "cacao/cocoa/apple/osx/Main.hh"
#include "cacao/cocoa/apple/osx/Logger.hh"

///////////////////////////////////////////////////////////////////////
/// Implentation: Main
///////////////////////////////////////////////////////////////////////
@implementation Main

    - (id<Main>)initWithApplication:(Application*)application {
        if (([super init])) {
            _application = application;
            _window = nil;
            return self;
        }
        return nil;
    }

    - (MainWindow*)createWindow {
        NSRect contentRect = [self windowContentRect];
        MainWindow* window = nil;

        LOG_DEBUG("[[MainWindow alloc] initWithContentRect:contentRect application:_application]...");
        if ((window = [[MainWindow alloc] initWithContentRect:contentRect application:_application])) {
            return window;
        } else {
            LOG_ERROR("...failed on [[MainWindow alloc] initWithContentRect:contentRect application:_application]");
        }
        return nil;
    }
    - (NSRect)windowContentRect {
        return NSMakeRect(0,0, 640,480);
    }
    - (NSString*)windowTitle {
        if ((_menu)) {
            return [_menu title];
        }
        return @"";
    }

    - (MainMenu*)createMenu {
        NSString *quitTitle = nil, *quitKeyEquivalent = nil;
        MainMenu* menu = nil;

        if ((quitTitle = [self menuQuitTitle])
            && ((quitKeyEquivalent = [self menuQuitKeyEquivalent]))) {

            if ((menu = [[MainMenu alloc]
                 initWithQuitTitle:quitTitle keyEquivalent:quitKeyEquivalent
                 target:_application action:@selector(terminate:) application:_application])) {
                return menu;
            }
        }
        return nil;
    }
    - (NSString*)menuQuitTitle {
        return @CACAO_COCOA_APPLE_OSX_MAINMENU_QUITITEM_TITLE;
    }
    - (NSString*)menuQuitKeyEquivalent {
        return @CACAO_COCOA_APPLE_OSX_MAINMENU_QUITITEM_KEY;
    }

    - (int)run:(int)argc argv:(char**)argv env:(char**)env {
        int err = 0;

        LOG_DEBUG("[self createMenu]...");
        if ((_menu = [self createMenu])) {

            LOG_DEBUG("[self createWindow]...");
            if ((_window = [self createWindow])) {

                [_window setTitle:[self windowTitle]];

                LOG_DEBUG("[_application run]...");
                [_application run];
                LOG_DEBUG("...[_application run]");
            }
        }
        return err;
    }
    - (void)destroy {
    }
@end

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
int main(int argc, char **argv, char **env) {
    int err = 1;
    try {
        NSAutoreleasePool *autoreleasePool = nil;
        Application* sharedApplication = nil;
        id<Main> main = nil;
        cacao::cocoa::apple::osx::logger logger;

        // initialize logger
        //
        LOGGER_INIT();

        LOG_DEBUG("[[AutoreleasePool alloc] init]...");
        if ((autoreleasePool = [[NSAutoreleasePool alloc] init])) {

            LOG_DEBUG("[Application sharedApplication]...");
            if ((sharedApplication = [Application sharedApplication])) {

                LOG_DEBUG("[ApplicationMain createWithApplication:sharedApplication]...");
                if ((main = [ApplicationMain createWithApplication:sharedApplication])) {

                    LOG_DEBUG("[main run:argc argv:argv env:env]...");
                    err = [main run:argc argv:argv env:env];
                    LOG_DEBUG("..." << err << " = [main run:argc argv:argv env:env]");

                    LOG_DEBUG("[main destroy]...");
                    [main destroy];
                } else {
                    LOG_ERROR("...failed on [ApplicationMain createWithApplication:sharedApplication]");
                }
            } else {
                LOG_ERROR("...failed on [Application sharedApplication]");
            }

            LOG_DEBUG("[autoreleasePool release]...");
            [autoreleasePool release];
        } else {
            LOG_ERROR("...failed on [[NSAutoreleasePool alloc] init]");
        }

        // finalize logger
        //
        LOGGER_FINI();
    } catch (const cacao::create_exception& e) {
        STDERR_LOG_ERROR("...caught cacao::create_exception e = " << e << "");
    }
    return err;
}

namespace cacao {
namespace cocoa {
namespace apple {
namespace osx {

} // namespace osx 
} // namespace apple 
} // namespace cocoa 
} // namespace cacao 
