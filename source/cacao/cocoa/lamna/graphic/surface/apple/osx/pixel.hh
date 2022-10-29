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
///   File: pixel.hh
///
/// Author: $author$
///   Date: 9/7/2016
///////////////////////////////////////////////////////////////////////
#ifndef _CACAO_COCOA_LAMNA_GRAPHIC_SURFACE_APPLE_OSX_PIXEL_HH
#define _CACAO_COCOA_LAMNA_GRAPHIC_SURFACE_APPLE_OSX_PIXEL_HH

#include "cacao/cocoa/apple/osx/Cocoa.hh"
#include "lamna/graphic/surface/pixel.hpp"

namespace cacao {
namespace cocoa {
namespace lamna {
namespace graphic {
namespace surface {
namespace apple {
namespace osx {

///////////////////////////////////////////////////////////////////////
///  Class: pixel_interfacet
///////////////////////////////////////////////////////////////////////
template
<class TPixelInterface = ::lamna::graphic::surface::pixel_interface,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 class TOffset = ssize_t,
 TSize VRGBAxisSize = LAMNA_GRAPHIC_SURFACE_PIXEL_RGB_AXIS_SIZE,
 class TImplements = TPixelInterface>

class _EXPORT_CLASS pixel_interfacet: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual operator NSColor*() const = 0;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef pixel_interfacet<> pixel_interface;

///////////////////////////////////////////////////////////////////////
///  Class: pixelt
///////////////////////////////////////////////////////////////////////
template
<class TQPixelInterface = pixel_interface,
 class TPixel = ::lamna::graphic::surface::pixel,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 class TOffset = ssize_t,
 TSize VRGBAxisSize = LAMNA_GRAPHIC_SURFACE_PIXEL_RGB_AXIS_SIZE,
 class TImplements = TQPixelInterface, class TExtends = TPixel>

class _EXPORT_CLASS pixelt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    pixelt(int r, int g, int b, int a): NSColor_(make_color(r,g,b,a)) {
    }
    pixelt(int r, int g, int b): NSColor_(make_color(r,g,b)) {
    }
    pixelt(): NSColor_(make_color(0,0,0)) {
    }
    virtual ~pixelt() {
        if ((NSColor_)) {
            [NSColor release];
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual NSColor* make_color(int r, int g, int b, int a) const {
        float red = this->rgb_axis_to_float(r),
              green = this->rgb_axis_to_float(g),
              blue = this->rgb_axis_to_float(b),
              alpha = this->rgb_axis_to_float(a);
        NSColor* color = make_color(red, green, blue, alpha);
        return color;
    }
    virtual NSColor* make_color(int r, int g, int b) const {
        float red = this->rgb_axis_to_float(r),
              green = this->rgb_axis_to_float(g),
              blue = this->rgb_axis_to_float(b),
              alpha = 1.0;
        NSColor* color = make_color(red, green, blue, alpha);
        return color;
    }
    virtual NSColor* make_color
    (const float& red, const float& green, const float& blue, const float& alpha) const {
        //NSColor* color = [NSColor colorWithRed:red green:green blue:blue alpha:alpha];
        NSColor* color = [NSColor colorWithDeviceRed:red green:green blue:blue alpha:alpha];
        return color;
    }
    virtual operator NSColor*() const {
        return NSColor_;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    NSColor* NSColor_;
};
typedef pixelt<> pixel;

} // namespace osx
} // namespace apple 
} // namespace surface 
} // namespace graphic 
} // namespace lamna 
} // namespace cocoa 
} // namespace cacao 

#endif // _CACAO_COCOA_LAMNA_GRAPHIC_SURFACE_APPLE_OSX_PIXEL_HH 
