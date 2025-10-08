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
///   File: iWindowMain.mm
///
/// Author: $author$
///   Date: 7/11/2016
///////////////////////////////////////////////////////////////////////
#include "cacao/icocoa/iWindowMain.hh"

///////////////////////////////////////////////////////////////////////
/// Implentation: iWindowMain
///////////////////////////////////////////////////////////////////////
@implementation iWindowMain
    - (id)init:(cacao::gui::main*)main {
        [super init:main];
        mainWindow_ = 0;
        app_ = 0;
        pool_ = 0;
        return self;
    }
    - (iMainWindow*)createMainWindow:(iRect)contentRect argc:(int)argc argv:(char**)argv env:(char**)env {
        iMainWindow* mainWindow = [[iMainWindow alloc] initWithRect:contentRect argc:argc argv:argv env:env];
        return mainWindow;
    }
    - (iRect)contentRect:(int)argc argv:(char**)argv env:(char**)env {
        int x = CACAO_ICOCOA_IWINDOWMAIN_WINDOW_X,
            y = CACAO_ICOCOA_IWINDOWMAIN_WINDOW_Y,
            width = CACAO_ICOCOA_IWINDOWMAIN_WINDOW_WIDTH,
            height = CACAO_ICOCOA_IWINDOWMAIN_WINDOW_HEIGHT;
        iRect contentRect = iMakeRect(x,y, width,height);
        return contentRect;
    }
    - (const char*)titleUTF8String:(int)argc argv:(char**)argv env:(char**)env {
        return CACAO_ICOCOA_IWINDOWMAIN_WINDOW_TITLE;
    }
    - (int)runApplication:(iApplication*)app argc:(int)argc argv:(char**)argv env:(char**)env {
        int err = 0;
        [app run];
        return err;
    }
    - (int)beforeRunApplication:(iApplication*)app argc:(int)argc argv:(char**)argv env:(char**)env {
        int err = 0;
        return err;
    }
    - (int)run:(int)argc argv:(char**)argv env:(char**)env {
        iRect contentRect = [self contentRect:argc  argv:argv env:env];
        int err = 0;

        CACAO_LOG_TRACE("in...");
        if ((pool_ = [[iAutoreleasePool alloc] init])) {
            if ((app_ = [iApplication sharedApplication])) {
                if ((mainWindow_ = [self createMainWindow:contentRect argc:argc argv:argv env:env])) {
                    const char *title = [self titleUTF8String:argc argv:argv env:env];
                    iView* mainView = 0;

                    [mainWindow_ setTitle:[iString stringWithUTF8String:title]];
                    if ((mainView = [mainWindow_ createMainView:argc argv:argv env:env])) {
                        [mainWindow_ setApplication:app_];
                        [mainWindow_ setContentView:mainView];
                        [mainWindow_ makeKeyAndOrderFront: nil];
                        if (!(err = [self beforeRunApplication:app_ argc:argc argv:argv env:env])) {
                            err = [self runApplication:app_ argc:argc argv:argv env:env];
                        }
                    } else {
                        CACAO_LOG_ERROR("failed on [mainWindow_ createMainView:...]");
                        [mainWindow_ release];
                        mainWindow_ = 0;
                    }
                } else {
                    CACAO_LOG_ERROR("failed on [self createMainWindow...]");
                }
                app_ = 0;
            } else {
                CACAO_LOG_ERROR("failed on [iApplication sharedApplication]");
            }
            [pool_ release];
            pool_ = 0;
        } else {
            CACAO_LOG_ERROR("failed on [[iAutoreleasePool alloc] init]");
        }
        CACAO_LOG_TRACE("...out");
        return err;
    }
@end

namespace cacao {
namespace icocoa {

} // namespace icocoa 
} // namespace cacao 
