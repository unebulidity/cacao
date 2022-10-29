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
///   File: iHashMainView.mm
///
/// Author: $author$
///   Date: 8/30/2016
///////////////////////////////////////////////////////////////////////
#include "cacao/app/cocoa/apple/osx/crypto/iHash/iHashMainView.hh"
#include "cacao/app/cocoa/apple/osx/crypto/iHash/MainWindow.hh"
#include "cacao/cocoa/apple/osx/Logger.hh"

///////////////////////////////////////////////////////////////////////
/// Implentation: iHashMainView
///////////////////////////////////////////////////////////////////////
@implementation iHashMainView

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (iHashMainView*)initWithFrame:(NSRect)rect
                      mainWindow:(MainWindow*)mainWindow
                      application:(Application*)application
                      mainWindowPeer:(iHashMainWindowPeer*)mainWindowPeer {

        _cornerRadius = CACAO_APP_COCOA_APPLE_OSX_CRYPTO_IHASH_IHASHMAINVIEW_CORNER_RADIUS;
        _colorRadius = CACAO_APP_COCOA_APPLE_OSX_CRYPTO_IHASH_IHASHMAINVIEW_COLOR_RADIUS;

        _fgR = CACAO_APP_COCOA_APPLE_OSX_CRYPTO_IHASH_IHASHMAINVIEW_FG_COLOR_R;
        _fgG = CACAO_APP_COCOA_APPLE_OSX_CRYPTO_IHASH_IHASHMAINVIEW_FG_COLOR_G;
        _fgB = CACAO_APP_COCOA_APPLE_OSX_CRYPTO_IHASH_IHASHMAINVIEW_FG_COLOR_B;
        _fgPixel = new LGSPixel(_fgR, _fgG, _fgB);
        _fgColor = (NSColor*)(*_fgPixel);

        _bgR = CACAO_APP_COCOA_APPLE_OSX_CRYPTO_IHASH_IHASHMAINVIEW_BG_COLOR_R;
        _bgG = CACAO_APP_COCOA_APPLE_OSX_CRYPTO_IHASH_IHASHMAINVIEW_BG_COLOR_G;
        _bgB = CACAO_APP_COCOA_APPLE_OSX_CRYPTO_IHASH_IHASHMAINVIEW_BG_COLOR_B;
        _bgPixel = new LGSPixel(_bgR, _bgG, _bgB);
        _bgColor = (NSColor*)(*_bgPixel);

        _bdR = CACAO_APP_COCOA_APPLE_OSX_CRYPTO_IHASH_IHASHMAINVIEW_BD_COLOR_R;
        _bdG = CACAO_APP_COCOA_APPLE_OSX_CRYPTO_IHASH_IHASHMAINVIEW_BD_COLOR_G;
        _bdB = CACAO_APP_COCOA_APPLE_OSX_CRYPTO_IHASH_IHASHMAINVIEW_BD_COLOR_B;
        _bdPixel = new LGSPixel(_bdR, _bdG, _bdB);
        _bdColor = (NSColor*)(*_bdPixel);

        _keyIconHeight = (_cornerRadius*18)/8;
        _keyIconWidth = (_keyIconHeight*8)/4;
        _keyIconX = (_cornerRadius*3)/2;
        _keyIconY = (_keyIconHeight-_cornerRadius+_colorRadius+_colorRadius);

        if (([super initWithFrame:rect application:application])) {
            _mainWindowPeer = mainWindowPeer;
            [self setAutoresizesSubviews:NO];

            if ((_control = [[iHashControlView alloc]
                              initWithFrame:rect target:mainWindow
                              mainWindowPeer:_mainWindowPeer])) {

                if ((_mainWindowPeer)) {
                    _mainWindowPeer->SetControlView(_control);
                }
                [self addSubview:_control];
                rect = [_control frame];
                rect.size.width += (_cornerRadius*2)-2;
                rect.size.height += (_cornerRadius*2)-2+_keyIconY;
                [self setFrameSize:rect.size];
                rect.origin.x = _cornerRadius-1;
                rect.origin.y = _cornerRadius-1;
                [_control setFrameOrigin:rect.origin];

                if ((_minButton = [NSWindow
                     standardWindowButton:NSWindowMiniaturizeButton
                     forStyleMask:NSBorderlessWindowMask])) {
                    NSRect minRect = [_minButton bounds];
                    NSTrackingAreaOptions minTrackingOptions = NSTrackingMouseEnteredAndExited
                                                               | NSTrackingActiveAlways;
                    NSTrackingArea* minTrackingArea = nil;
                    rect = [self frame];
                    rect.origin.x = _cornerRadius;
                    rect.origin.y = rect.size.height - _keyIconY - ((_cornerRadius - minRect.size.height)/2 + minRect.size.height);
                    [_minButton setFrameOrigin:rect.origin];
                    [self addSubview:_minButton];
                    _keyIconX += minRect.size.width;
                    if ((minTrackingArea = [[NSTrackingArea alloc]
                         initWithRect:minRect options:minTrackingOptions
                         owner:self userInfo:nil])) {
                        [_minButton addTrackingArea:minTrackingArea];
                    }
                }
                return self;
            }
        }
        return nil;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (void)windowDidBecomeMain:(NSNotification*)notification {
    }
    - (void)windowDidResignMain:(NSNotification*)notification {
    }
    - (void)windowDidBecomeKey:(NSNotification*)notification {
        LOG_DEBUG("[_minButton setState:NSOnState]...");
        [_minButton setState:NSOnState];
        [_minButton setNeedsDisplay:YES];
    }
    - (void)windowDidResignKey:(NSNotification*)notification {
        LOG_DEBUG("[_minButton setState:NSOffState]...");
        [_minButton setState:NSOffState];
        [_minButton setNeedsDisplay:YES];
    }
    - (void)mouseEntered:(NSEvent *)theEvent{
        LOG_DEBUG("[_minButton highlight:YES]...");
        [_minButton highlight:YES];
    }
    - (void)mouseExited:(NSEvent *)theEvent{
        LOG_DEBUG("[_minButton highlight:NO]...");
        [_minButton highlight:NO];
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (void)drawRect:(NSRect)rect {
        NSRect bounds = [self bounds];
        int w = bounds.size.width, h = bounds.size.height;
        [[NSColor clearColor] set];
        NSRectFill(bounds);
        if ((_cornerRadius*2 < w) && (_cornerRadius*2 < h)) {
            LGSContext context(self);
            LGSImage image(context);
            LGSColor fgColor(image, _fgR, _fgG, _fgB, _colorRadius, _colorRadius);
            LGSColor bgColor(image, _bgR, _bgG, _bgB, _colorRadius, _colorRadius);
            LGSColor bdColor(image, _bdR, _bdG, _bdB, _colorRadius, _colorRadius);
            LGSKeyIcon keyIcon
            (image, fgColor,bdColor,fgColor,bdColor,
             _keyIconWidth, _keyIconHeight, _colorRadius);
            image.SelectImage(&bgColor);
            image.FillRoundedRectangle
            (_cornerRadius,_cornerRadius+_keyIconY,
             w-_cornerRadius*2-_colorRadius+1,
             h-_cornerRadius*2-_colorRadius+1-_keyIconY, _cornerRadius);
            image.SelectImage(&bdColor);
            image.DrawRoundedRectangle
            (_cornerRadius,_cornerRadius+_keyIconY,
             w-_cornerRadius*2-_colorRadius+1,
             h-_cornerRadius*2-_colorRadius+1-_keyIconY, _cornerRadius);
            keyIcon.Plot(_keyIconX,_colorRadius);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (BOOL)upperChecked {
        return [_control upperChecked];
    }
    - (NSColor*)backgroundColor {
        return _bgColor;
    }
@end
