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
///   File: Main.hh
///
/// Author: $author$
///   Date: 8/29/2016
///////////////////////////////////////////////////////////////////////
#ifndef _CACAO_COCOA_APPLE_OSX_MAIN_HH
#define _CACAO_COCOA_APPLE_OSX_MAIN_HH

#include "cacao/cocoa/apple/osx/MainWindow.hh"
#include "cacao/cocoa/apple/osx/MainMenu.hh"
#include "cacao/cocoa/apple/osx/Application.hh"

///////////////////////////////////////////////////////////////////////
/// Protocol: Main
///////////////////////////////////////////////////////////////////////
@protocol Main
    - (int)run:(int)argc argv:(char**)argv env:(char**)env;
    - (void)destroy;
@end

///////////////////////////////////////////////////////////////////////
/// Interface: Main
///////////////////////////////////////////////////////////////////////
@interface Main: NSObject <Main> {
    }
    @property (assign) Application* application;
    @property (assign) MainWindow* window;
    @property (assign) MainMenu* menu;

    - (id<Main>)initWithApplication:(Application*)application;
    - (NSRect)windowContentRect;
    - (NSString*)windowTitle;
    - (NSString*)menuQuitTitle;
    - (NSString*)menuQuitKeyEquivalent;
@end

///////////////////////////////////////////////////////////////////////
/// Interface: ApplicationMain
///////////////////////////////////////////////////////////////////////
@interface ApplicationMain: NSObject {
    }
    + (id<Main>)createWithApplication:(Application*)application;
@end

namespace cacao {
namespace cocoa {
namespace apple {
namespace osx {

} // namespace osx 
} // namespace apple 
} // namespace cocoa 
} // namespace cacao 

#endif // _CACAO_COCOA_APPLE_OSX_MAIN_HH 
