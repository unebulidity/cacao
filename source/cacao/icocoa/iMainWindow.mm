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
///   File: iMainWindow.mm
///
/// Author: $author$
///   Date: 7/11/2016
///////////////////////////////////////////////////////////////////////
#include "cacao/icocoa/iMainWindow.hh"

///////////////////////////////////////////////////////////////////////
/// Implentation: iMainWindow
///////////////////////////////////////////////////////////////////////
@implementation iMainWindow
    - (iMainWindow*)initWithRect:(iRect)contentRect argc:(int)argc argv:(char**)argv env:(char**)env {
        iWindowStyleMask style = CACAO_ICOCOA_IMAINWINDOW_STYLE;
        iBackingStoreType backing = (iBackingStoreType)CACAO_ICOCOA_IMAINWINDOW_BACKING;
        BOOL defer = CACAO_ICOCOA_IMAINWINDOW_DEFER;
        mainView_ = 0;
        app_ = 0;
        [super initWithContentRect:contentRect styleMask:style backing:backing defer:defer];
        [self setDelegate:self];
        return self;
    }
    - (iString*)setMainTitle:(int)argc argv:(char**)argv env:(char**)env {
        iString* mainTitle = [iString stringWithUTF8String:[self mainTitleUTF8String:argc argv:argv env:env]];
        [self setTitle:mainTitle];
        return mainTitle;
    }
    - (iView*)createMainView:(int)argc argv:(char**)argv env:(char**)env {
        mainView_ = [[iMainView alloc] init];
        return mainView_;
    }
    - (const char*)mainTitleUTF8String:(int)argc argv:(char**)argv env:(char**)env {
        return CACAO_ICOCOA_IMAINWINDOW_TITLE;
    }
    - (iApplication*)setApplication:(iApplication*)app {
        app_ = app;
        return app_;
    }
    - (iApplication*)application {
        return app_;
    }
    -(void)windowWillClose:(iNotification*)notification {
        iApplication* app;
        if ((app = [self application]))
            [app stop:self];
    }
@end

namespace cacao {
namespace icocoa {

} // namespace icocoa 
} // namespace cacao 
