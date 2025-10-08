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
///   File: iImagoMainWindow.mm
///
/// Author: $author$
///   Date: 10/11/2016
///////////////////////////////////////////////////////////////////////
#include "cacao/app/cocoa/apple/osx/graphic/iImago/iImagoMainWindow.hh"

#include "cacao/cocoa/apple/osx/Logger.hh"

///////////////////////////////////////////////////////////////////////
/// Implentation: iImagoMainWindow
///////////////////////////////////////////////////////////////////////
@implementation iImagoMainWindow

    - (iImagoMainWindow*)initWithContentRect:(NSRect)contentRect
                         application:(Application*)application {
        _mainView = nil;

        if (([super initWithContentRect:contentRect application:application])) {
            [self setOpaque:NO];
            [self setAlphaValue:1];
            [self setBackgroundColor:[NSColor clearColor]];
            [self setHasShadow:YES];
            [self setMovableByWindowBackground:YES];
            [self centerInScreen];
            return self;
        }
        return nil;
    }

    - (MainView*)createViewWithContentRect:(NSRect)contentRect {
        Application* application = [self application];

        LOG_DEBUG("[[iImagoMainView alloc] initWithFrame:contentRect application:application]...");
        if ((_mainView = [[iImagoMainView alloc] initWithFrame:contentRect application:application])) {
            return _mainView;
        } else {
            LOG_ERROR("...failed on [[iImagoMainView alloc] initWithFrame:contentRect application:application]");
        }
        return nil;
    }

    - (NSUInteger)windowStyle {
        return NSBorderlessWindowMask | NSResizableWindowMask;
    }

    - (void)centerInScreen {
        NSRect rect = [self frame],
               screenRect = NSMakeRect(0,0, 0,0);
        NSScreen* screen = nil;

        if ((screen = [self screen])) {
            screenRect = [screen frame];

            if ((rect.size.width <= screenRect.size.width)) {
                rect.origin.x = (screenRect.size.width - rect.size.width)/2;
            } else {
                rect.origin.x = 0;
            }
            if ((rect.size.height <= screenRect.size.height)) {
                rect.origin.y = (screenRect.size.height - rect.size.height)/2;
            } else {
                rect.origin.y = screenRect.size.height;
            }
            [self setFrameOrigin:rect.origin];
        } else {
        }
    }

    - (BOOL)canBecomeKeyWindow {
        return YES;
    }
    - (BOOL)canBecomeMainWindow {
        return YES;
    }
@end

namespace cacao {
namespace app {
namespace cocoa {
namespace apple {
namespace osx {
namespace iImago {

} // namespace iImago 
} // namespace osx 
} // namespace apple 
} // namespace cocoa 
} // namespace app 
} // namespace cacao 
