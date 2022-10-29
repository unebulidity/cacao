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
///   File: MainWindow.mm
///
/// Author: $author$
///   Date: 8/29/2016, 10/29/2022
///////////////////////////////////////////////////////////////////////
#include "cacao/cocoa/apple/osx/MainWindow.hh"
#include "cacao/cocoa/apple/osx/Logger.hh"

///////////////////////////////////////////////////////////////////////
/// Implentation: MainWindow
///////////////////////////////////////////////////////////////////////
@implementation MainWindow

    - (MainWindow*)initWithContentRect:(NSRect)contentRect application:(Application*)application {

        if (([super initWithContentRect:contentRect
                    styleMask:[self windowStyle] backing:[self bufferingType]
                    defer:[self deferCreation]])) {
            _application = application;

            LOG_DEBUG("[self createViewWithContentRect:contentRect]...");
            if ((_view = [self createViewWithContentRect:contentRect])) {
                [self setContentView:_view];
                [self makeKeyAndOrderFront:nil];
                [self setDelegate:self];
                return self;
            } else {
                LOG_ERROR("...failed on [self createViewWithContentRect:contentRect]");
            }
        }
        return nil;
    }
    - (MainView*)createViewWithContentRect:(NSRect)contentRect {
        Application* application = _application;
        MainView* view = nil;

        LOG_DEBUG("[[MainView alloc] initWithFrame:contentRect application:application]...");
        if ((view = [[MainView alloc] initWithFrame:contentRect application:application])) {
            return view;
        } else {
            LOG_ERROR("...failed on [[MainView alloc] initWithFrame:contentRect application:application]");
        }
        return nil;
    }

    - (void)windowWillClose:(NSNotification*)notification {
        LOG_DEBUG("[_application stop:self]...");
        [_application stop:self];
    }

    - (NSUInteger)windowStyle {
        return DefaultWindowStyle;
    }
    - (NSBackingStoreType)bufferingType {
        return (NSBackingStoreType)DefaultWindowBacking;
    }
    - (BOOL)deferCreation {
        return NO;
    }
@end

namespace cacao {
namespace cocoa {
namespace apple {
namespace osx {

} // namespace osx 
} // namespace apple 
} // namespace cocoa 
} // namespace cacao 
