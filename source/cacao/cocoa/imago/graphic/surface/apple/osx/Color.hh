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
///   File: Color.hh
///
/// Author: $author$
///   Date: 10/14/2016
///////////////////////////////////////////////////////////////////////
#ifndef _CACAO_COCOA_IMAGO_GRAPHIC_SURFACE_APPLE_OSX_COLOR_HH
#define _CACAO_COCOA_IMAGO_GRAPHIC_SURFACE_APPLE_OSX_COLOR_HH

#include "cacao/cocoa/imago/graphic/surface/apple/osx/Object.hh"
#include "imago/graphic/surface/Color.hpp"

namespace cacao {
namespace cocoa {
namespace imago {
namespace graphic {
namespace surface {
namespace apple {
namespace osx {

///////////////////////////////////////////////////////////////////////
///  Class: ColorT
///////////////////////////////////////////////////////////////////////
template
<class TObject = Object,
 class TImageImplement = ImageImplement,
 class TPixelImplement = PixelImplement,
 class TPixel = Pixel,
 class TColorSample = ColorSample,
 class TColor = ::imago::graphic::surface::ColorT
 <TObject, TImageImplement, TPixelImplement, TPixel>,
 class TImplements = TPixelImplement, class TExtends = TColor>

class _EXPORT_CLASS ColorT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TObject tObject;
    typedef TColor tColor;
    typedef TImageImplement tImageImplement;
    typedef TPixelImplement tPixelImplement;
    typedef TPixel tPixel;
    typedef TColorSample tColorSample;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ColorT
    (tImageImplement& surfaceImage,
     tColorSample r, tColorSample g, tColorSample b,
     tSize width = 1, tSize height = 1)
    : Extends(surfaceImage, r,g,b, width,height) {
    }
    virtual ~ColorT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void Fill(tOffset x, tOffset y, tSize w, tSize h) {
        ContextImplement& gc = this->SurfaceImage().SurfaceContext();
        const tPixelImplement& color = this->Color();
        w = w+this->Width()-1; h = h+this->Height()-1;
        gc.FillRectangle(x,y, w,h, color);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual operator NSColor*() const {
        return this->Color();
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef ColorT<> Color;

} // namespace osx
} // namespace apple 
} // namespace surface 
} // namespace graphic 
} // namespace imago 
} // namespace cocoa 
} // namespace cacao 

typedef cacao::cocoa::imago::graphic::surface::apple::osx::Color IGSColor;

#endif // _CACAO_COCOA_IMAGO_GRAPHIC_SURFACE_APPLE_OSX_COLOR_HH
