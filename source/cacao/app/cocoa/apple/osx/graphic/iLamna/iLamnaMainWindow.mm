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
///   File: iLamnaMainWindow.mm
///
/// Author: $author$
///   Date: 9/7/2016
///////////////////////////////////////////////////////////////////////
#include "cacao/app/cocoa/apple/osx/graphic/iLamna/iLamnaMainWindow.hh"
#include "cacao/cocoa/apple/osx/Logger.hh"

///////////////////////////////////////////////////////////////////////
/// Implentation: iLamnaMainWindow
///////////////////////////////////////////////////////////////////////
@implementation iLamnaMainWindow

    - (iLamnaMainWindow*)initWithContentRect:(NSRect)contentRect
                         application:(Application*)application {
        _mainView = nil;

        if (([super initWithContentRect:contentRect application:application])) {
            [self setOpaque:NO];
            [self setAlphaValue:1];
            [self setBackgroundColor:[NSColor clearColor]];
            [self setHasShadow:YES];
            [self setMovableByWindowBackground:YES];
            return self;
        }
        return nil;
    }

    - (MainView*)createViewWithContentRect:(NSRect)contentRect {
        Application* application = [self application];

        LOG_DEBUG("[[iLamnaMainView alloc] initWithFrame:contentRect application:application]...");
        if ((_mainView = [[iLamnaMainView alloc] initWithFrame:contentRect application:application])) {
            return _mainView;
        } else {
            LOG_ERROR("...failed on [[iLamnaMainView alloc] initWithFrame:contentRect application:application]");
        }
        return nil;
    }

    - (NSUInteger)windowStyle {
        return NSBorderlessWindowMask | NSResizableWindowMask;
    }
@end
        

