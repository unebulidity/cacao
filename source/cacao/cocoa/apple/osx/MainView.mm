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
///   File: MainView.mm
///
/// Author: $author$
///   Date: 8/30/2016
///////////////////////////////////////////////////////////////////////
#include "cacao/cocoa/apple/osx/MainView.hh"

///////////////////////////////////////////////////////////////////////
/// Implentation: MainView
///////////////////////////////////////////////////////////////////////
@implementation MainView

    - (MainView*)initWithFrame:(NSRect)rect application:(Application*)application {
        if (([super initWithFrame:rect])) {
            _application = application;
            return self;
        }
        return nil;
    }

    - (void)drawRect:(NSRect)rect {
        NSRect bounds = [self bounds];
        [[self backgroundColor] set];
        NSRectFill(bounds);
    }

    - (NSColor*)backgroundColor {
        return [NSColor whiteColor];
    }
    - (NSColor*)foregroundColor {
        return [NSColor blackColor];
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
