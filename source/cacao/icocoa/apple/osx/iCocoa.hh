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
///   File: iCocoa.hh
///
/// Author: $author$
///   Date: 7/10/2016
///////////////////////////////////////////////////////////////////////
#ifndef _CACAO_ICOCOA_APPLE_OSX_ICOCOA_HH
#define _CACAO_ICOCOA_APPLE_OSX_ICOCOA_HH

#include <Cocoa/Cocoa.h>
#include "cacao/base/base.hh"

typedef NSObject iObject;

typedef NSAutoreleasePool iAutoreleasePool;

typedef NSString iString;

#define iMakeRect NSMakeRect
typedef NSRect iRect;
#define iRectFill NSRectFill
#define iRectFillUsingOperation NSRectFillUsingOperation

#define iMakeSize NSMakeSize
typedef NSSize iSize;

#define iMakePoint NSMakePoint
typedef NSPoint iPoint;

typedef NSColor iColor;

typedef NSView iView;

typedef NSUInteger iWindowStyleMask;
enum {
    iTitledWindowMask = NSTitledWindowMask,
    iClosableWindowMask = NSClosableWindowMask,
    iMiniaturizableWindowMask = NSMiniaturizableWindowMask,
    iResizableWindowMask = NSResizableWindowMask
};
enum {
    iDefaultDesktopWindowMask
    = iTitledWindowMask | iClosableWindowMask
    | iMiniaturizableWindowMask | iResizableWindowMask
};
typedef NSBackingStoreType iBackingStoreType;
enum {
    iBackingStoreBuffered = NSBackingStoreBuffered
};
enum {
    iDefaultDesktopWindowBacking = iBackingStoreBuffered
};
typedef NSWindow iWindow;
@protocol iWindowDelegate <NSWindowDelegate>
@end

#define iApp NSApp
typedef NSApplication iApplication;

typedef NSNotification iNotification;

namespace cacao {
namespace icocoa {
namespace apple {
namespace osx {

} // namespace osx 
} // namespace apple 
} // namespace icocoa 
} // namespace cacao 

#endif // _CACAO_ICOCOA_APPLE_OSX_ICOCOA_HH 
