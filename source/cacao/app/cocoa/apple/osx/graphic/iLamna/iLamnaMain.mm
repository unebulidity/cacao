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
///   File: iLamnaMain.mm
///
/// Author: $author$
///   Date: 9/7/2016
///////////////////////////////////////////////////////////////////////
#include "cacao/app/cocoa/apple/osx/graphic/iLamna/iLamnaMain.hh"
#include "cacao/cocoa/apple/osx/Logger.hh"

///////////////////////////////////////////////////////////////////////
/// Implentation: iLamnaMain
///////////////////////////////////////////////////////////////////////
@implementation iLamnaMain

    - (iLamnaMain*)initWithApplication:(Application*)application {
        _mainWindow = nil;

        if (([super initWithApplication:application])) {
            return self;
        }
        return nil;
    }

    - (MainWindow*)createWindow {
        NSRect contentRect = [self windowContentRect];
        Application* application = [self application];

        LOG_DEBUG("[[iLamnaMainWindow alloc] initWithContentRect:contentRect application:application]...");
        if ((_mainWindow = [[iLamnaMainWindow alloc] initWithContentRect:contentRect application:application])) {
            return _mainWindow;
        } else {
            LOG_ERROR("...failed on [[iLamnaMainWindow alloc] initWithContentRect:contentRect application:application]");
        }
        return nil;
    }

    - (NSRect)windowContentRect {
        return NSMakeRect(0,0, 480,200);
    }
@end

///////////////////////////////////////////////////////////////////////
/// Implentation: ApplicationMain
///////////////////////////////////////////////////////////////////////
@implementation ApplicationMain

    + (id<Main>)createWithApplication:(Application*)application {
        Main* main = nil;

        LOG_DEBUG("[[iLamnaMain alloc] initWithApplication:application]...");
        if ((main = [[iLamnaMain alloc] initWithApplication:application])) {
            return main;
        } else {
            LOG_ERROR("...failed on [[iLamnaMain alloc] initWithApplication:application]");
        }
        return nil;
    }
@end
