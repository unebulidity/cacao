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
///   File: iImagoMainView.mm
///
/// Author: $author$
///   Date: 10/11/2016
///////////////////////////////////////////////////////////////////////
#include "cacao/app/cocoa/apple/osx/graphic/iImago/iImagoMainView.hh"
#include "cacao/cocoa/imago/graphic/surface/apple/osx/Color.hh"
#include "cacao/cocoa/imago/graphic/surface/apple/osx/Context.hh"
#include "cacao/cocoa/imago/graphic/surface/apple/osx/Image.hh"
#include "cacao/cocoa/imago/graphic/surface/apple/osx/Context.hh"
#include "cacao/cocoa/imago/graphic/surface/apple/osx/Pixel.hh"
#include "cacao/cocoa/apple/osx/Logger.hh"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
struct DrawContext {
    DrawContext(NSRect &_bounds, IGSImage &_image)
    : bounds(_bounds), image(_image) {
        width = bounds.size.width; height = bounds.size.height;
        cx = width / 2; cy = height / 2; r = (cx < cy)?(cx):(cy);
    }
    NSRect &bounds;
    IGSImage &image;
    size_t width,height, cx,cy, r;
};

///////////////////////////////////////////////////////////////////////
/// Implentation: iImagoMainView
///////////////////////////////////////////////////////////////////////
@implementation iImagoMainView
    - (iImagoMainView*)initWithFrame:(NSRect)rect
                       application:(Application*)application {

        _fgRed = CACAO_APP_COCOA_APPLE_OSX_GRAPHIC_IIMAGO_FG_RED;
        _fgGreen = CACAO_APP_COCOA_APPLE_OSX_GRAPHIC_IIMAGO_FG_GREEN;
        _fgBlue = CACAO_APP_COCOA_APPLE_OSX_GRAPHIC_IIMAGO_FG_BLUE;

        _bgRed = CACAO_APP_COCOA_APPLE_OSX_GRAPHIC_IIMAGO_BG_RED;
        _bgGreen = CACAO_APP_COCOA_APPLE_OSX_GRAPHIC_IIMAGO_BG_GREEN;
        _bgBlue = CACAO_APP_COCOA_APPLE_OSX_GRAPHIC_IIMAGO_BG_BLUE;

        _bdRed = CACAO_APP_COCOA_APPLE_OSX_GRAPHIC_IIMAGO_BD_RED;
        _bdGreen = CACAO_APP_COCOA_APPLE_OSX_GRAPHIC_IIMAGO_BD_GREEN;
        _bdBlue = CACAO_APP_COCOA_APPLE_OSX_GRAPHIC_IIMAGO_BD_BLUE;

        _drawContext = nil;
        _draw = @selector(drawTriangle);

        if (([super initWithFrame:rect application:application])) {
            return self;
        }
        return nil;
    }

    - (void)drawRect:(NSRect)rect {
        NSRect bounds = [self bounds];
        [[NSColor clearColor] set];
        NSRectFill(bounds);
        {
            ssize_t width = bounds.size.width, height = bounds.size.height,
                    cx = width / 2, cy = height / 2, r = (cx < cy)?(cx):(cy);
            IGSContext context(self);
            IGSImage image(context);
            IGSColor fgColor(image, _bdRed, _bdGreen, _bdBlue),
                     bgColor(image, _bgRed, _bgGreen, _bgBlue);

            image.SelectImage(&bgColor);
            image.FillRectangle(0,0, width,height);

            image.SelectImage(&fgColor);
            if ((_draw)) {
                DrawContext drawContext(bounds, image);
                _drawContext = &drawContext;
                [self performSelector:_draw];
                _drawContext = nil;
            }
        }
    }
    - (void)drawTriangle {
        if ((_drawContext)) {
            DrawContext &c = *_drawContext;
            IGSImage &image = c.image;
            ssize_t width = c.width, height = c.height,
                    cx = c.cx, cy = c.cy, r = c.r;
            image.DrawTriangle(cx,0, width-1,height-1, 0,height-1);
        }
    }
    - (void)fillTriangle {
        if ((_drawContext)) {
            DrawContext &c = *_drawContext;
            IGSImage &image = c.image;
            ssize_t width = c.width, height = c.height,
                    cx = c.cx, cy = c.cy, r = c.r;
            image.FillTriangle(cx,0, width-1,height-1, 0,height-1);
        }
    }
    - (void)drawCircle {
        if ((_drawContext)) {
            DrawContext &c = *_drawContext;
            IGSImage &image = c.image;
            ssize_t width = c.width, height = c.height,
                    cx = c.cx, cy = c.cy, r = c.r;
            image.DrawCircle(cx,cy,r);
        }
    }
    - (void)fillCircle {
        if ((_drawContext)) {
            DrawContext &c = *_drawContext;
            IGSImage &image = c.image;
            ssize_t width = c.width, height = c.height,
                    cx = c.cx, cy = c.cy, r = c.r;
            image.FillCircle(cx,cy,r);
        }
    }
    - (void)drawEllipse {
        if ((_drawContext)) {
            DrawContext &c = *_drawContext;
            IGSImage &image = c.image;
            ssize_t width = c.width, height = c.height,
                    cx = c.cx, cy = c.cy, r = c.r;
            image.DrawEllipse(cx,cy, cx,cy);
        }
    }
    - (void)fillEllipse {
        if ((_drawContext)) {
            DrawContext &c = *_drawContext;
            IGSImage &image = c.image;
            ssize_t width = c.width, height = c.height,
                    cx = c.cx, cy = c.cy, r = c.r;
            image.FillEllipse(cx,cy, cx,cy);
        }
    }

    - (void)rightMouseUp:(NSEvent*)theEvent {
        if (@selector(drawTriangle) != (_draw)) {
            if (@selector(fillTriangle) != (_draw)) {
                if (@selector(drawCircle) != (_draw)) {
                    if (@selector(fillCircle) != (_draw)) {
                        if (@selector(drawEllipse) != (_draw)) {
                            _draw = @selector(drawTriangle);
                            [self setNeedsDisplay:YES];
                        } else {
                            _draw = @selector(fillEllipse);
                            [self setNeedsDisplay:YES];
                        }
                    } else {
                        _draw = @selector(drawEllipse);
                        [self setNeedsDisplay:YES];
                    }
                } else {
                    _draw = @selector(fillCircle);
                    [self setNeedsDisplay:YES];
                }
            } else {
                _draw = @selector(drawCircle);
                [self setNeedsDisplay:YES];
            }
        } else {
            _draw = @selector(fillTriangle);
            [self setNeedsDisplay:YES];
        }
    }
@end

namespace cacao {
namespace app {
namespace cocoa {
namespace apple {
namespace osx {
namespace iImago {

} // namespace iImago 
} // namespace osx 
} // namespace apple 
} // namespace cocoa 
} // namespace app 
} // namespace cacao 
