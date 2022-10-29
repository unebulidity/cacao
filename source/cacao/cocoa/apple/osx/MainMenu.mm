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
///   File: MainMenu.mm
///
/// Author: $author$
///   Date: 8/30/2016
///////////////////////////////////////////////////////////////////////
#include "cacao/cocoa/apple/osx/MainMenu.hh"
#include "cacao/cocoa/apple/osx/Logger.hh"

///////////////////////////////////////////////////////////////////////
/// Implentation: MainMenu
///////////////////////////////////////////////////////////////////////
@implementation MainMenu

- (MainMenu*)initWithQuitTitle:(NSString*)title
             keyEquivalent:(NSString*)keyEquivalent
             target:(NSObject*)target action:(SEL)action
             application:(Application*)application {
    NSString *appName = nil, *quitTitle = nil;
    NSMenuItem *appMenuItem = nil, *quitMenuItem = nil;
    NSMenu *appMenu = nil;

    if (([super init])) {

        LOG_DEBUG("[[NSProcessInfo processInfo] processName]...");
        if ((appName = [[NSProcessInfo processInfo] processName])) {

            [self setTitle:appName];

            LOG_DEBUG("[title stringByAppendingString:[@\" \" stringByAppendingString:appName]]...");
            if ((quitTitle = [title stringByAppendingString:[@" " stringByAppendingString:appName]])) {

                LOG_DEBUG("[[NSMenuItem alloc] initWithTitle:quitTitle action:action keyEquivalent:keyEquivalent]...");
                if ((quitMenuItem = [[NSMenuItem alloc]
                     initWithTitle:quitTitle action:action keyEquivalent:keyEquivalent])) {

                    LOG_DEBUG("[[NSMenu alloc] init]...");
                    if ((appMenu = [[NSMenu alloc] init])) {
                        [appMenu addItem:quitMenuItem];

                        LOG_DEBUG("[[NSMenuItem alloc] init]...");
                        if ((appMenuItem = [[NSMenuItem alloc] init])) {
                            [appMenuItem setSubmenu:appMenu];
                            [self addItem:appMenuItem];
                            [application setActivationPolicy:NSApplicationActivationPolicyRegular];
                            [application activateIgnoringOtherApps:NO];
                            [application setMainMenu:self];
                            return self;
                        }
                    }
                }
            }
        }
    }
    return nil;
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
