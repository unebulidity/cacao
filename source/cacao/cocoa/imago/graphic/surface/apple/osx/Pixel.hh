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
///   File: Pixel.hh
///
/// Author: $author$
///   Date: 10/11/2016
///////////////////////////////////////////////////////////////////////
#ifndef _CACAO_COCOA_IMAGO_GRAPHIC_SURFACE_APPLE_OSX_PIXEL_HH
#define _CACAO_COCOA_IMAGO_GRAPHIC_SURFACE_APPLE_OSX_PIXEL_HH

#include "cacao/cocoa/apple/osx/Cocoa.hh"
#include "imago/graphic/surface/Pixel.hpp"
#include "cacao/cocoa/apple/osx/Logger.hh"

namespace cacao {
namespace cocoa {
namespace imago {
namespace graphic {
namespace surface {
namespace apple {
namespace osx {

typedef ::imago::tInt tInt;
typedef ::imago::tLength tLength;
typedef ::imago::tOffset tOffset;
typedef ::imago::tSize tSize;

typedef ::imago::graphic::ColorSample ColorSample;

///////////////////////////////////////////////////////////////////////
///  Class: PixelImplementT
///////////////////////////////////////////////////////////////////////
template
<class TImplementBase = ::imago::graphic::surface::PixelImplement,
 class TColorSample = ColorSample,
 class TImplements = TImplementBase>
class _EXPORT_CLASS PixelImplementT: virtual public TImplements {
public:
    typedef TImplements Implements;
    typedef TColorSample tColorSample;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual operator NSColor*() const {
        return nil;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef PixelImplementT<> PixelImplement;

///////////////////////////////////////////////////////////////////////
///  Class: PixelT
///////////////////////////////////////////////////////////////////////
template
<class TImplementBase = PixelImplement,
 class TBase = ::imago::graphic::surface::Pixel,
 class TColorSample = ColorSample,
 class TImplements = TImplementBase, class TExtends = TBase>
class _EXPORT_CLASS PixelT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TColorSample tColorSample;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    PixelT
    (tColorSample r, tColorSample g, tColorSample b, tColorSample a)
    : Extends(r,g,b,a), m_color(nil) {
        m_color = MakeColor(r,g,b,a);
    }
    PixelT(tColorSample r, tColorSample g, tColorSample b)
    : Extends(r,g,b), m_color(nil) {
        m_color = MakeColor(r,g,b);
    }
    virtual ~PixelT() {
        if ((m_color)) {
            LOG_DEBUG("[m_color release]...");
            [m_color release];
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual NSColor* MakeColor
    (tColorSample r, tColorSample g, tColorSample b, tColorSample a) const {
        float red = ((float)r),
              green = ((float)g),
              blue = ((float)b),
              alpha = ((float)a);
        LOG_DEBUG("[[NSColor colorWithDeviceRed:red green:green blue:blue alpha:alpha] retain]...");
        NSColor* color = [[NSColor colorWithDeviceRed:red green:green blue:blue alpha:alpha] retain];
        return color;
    }
    virtual NSColor* MakeColor(tColorSample r, tColorSample g, tColorSample b) const {
        float red = ((float)r),
              green = ((float)g),
              blue = ((float)b),
              alpha = 1.0;
        LOG_DEBUG("[[NSColor colorWithDeviceRed:red green:green blue:blue alpha:alpha] retain]...");
        NSColor* color = [[NSColor colorWithDeviceRed:red green:green blue:blue alpha:alpha] retain];
        return color;
    }
    virtual operator NSColor*() const {
        return m_color;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    NSColor* m_color;
};
typedef PixelT<> Pixel;

} // namespace osx
} // namespace apple 
} // namespace surface 
} // namespace graphic 
} // namespace imago 
} // namespace cocoa 
} // namespace cacao 

typedef cacao::cocoa::imago::graphic::surface::apple::osx::ColorSample IGSColorSample;
typedef cacao::cocoa::imago::graphic::surface::apple::osx::Pixel IGSPixel;

#endif // _CACAO_COCOA_IMAGO_GRAPHIC_SURFACE_APPLE_OSX_PIXEL_HH 
