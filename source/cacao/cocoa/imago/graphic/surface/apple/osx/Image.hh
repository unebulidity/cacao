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
///   File: Image.hh
///
/// Author: $author$
///   Date: 10/14/2016
///////////////////////////////////////////////////////////////////////
#ifndef _CACAO_COCOA_IMAGO_GRAPHIC_SURFACE_APPLE_OSX_IMAGE_HH
#define _CACAO_COCOA_IMAGO_GRAPHIC_SURFACE_APPLE_OSX_IMAGE_HH

#include "cacao/cocoa/imago/graphic/surface/apple/osx/Context.hh"
#include "imago/graphic/surface/Image.hpp"

namespace cacao {
namespace cocoa {
namespace imago {
namespace graphic {
namespace surface {
namespace apple {
namespace osx {

///////////////////////////////////////////////////////////////////////
///  Class: ImageImplementT
///////////////////////////////////////////////////////////////////////
template
<class TImageImplement = ::imago::graphic::surface::ImageImplement,
 class TContextImplement = ContextImplement,
 class TColorSample = ColorSample,
 class TImplements = TImageImplement>

class _EXPORT_CLASS ImageImplementT: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef TContextImplement tContextImplement;
    typedef TColorSample tColorSample;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tContextImplement& SurfaceContext() const = 0;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef ImageImplementT<> ImageImplement;

///////////////////////////////////////////////////////////////////////
///  Class: ImageT
///////////////////////////////////////////////////////////////////////
template
<class TImageImplement = ImageImplement,
 class TImage = ::imago::graphic::surface::Image,
 class TContextImplement = ContextImplement,
 class TColorSample = ColorSample,
 class TImplements = TImageImplement, class TExtends = TImage>

class _EXPORT_CLASS ImageT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TImageImplement tImageImplement;
    typedef TImage tImage;
    typedef TContextImplement tContextImplement;
    typedef TColorSample tColorSample;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ImageT(tContextImplement& surfaceContext, tImageImplement* image = 0)
    : Extends(surfaceContext, image), m_surfaceContext(surfaceContext) {
    }
    virtual ~ImageT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tContextImplement& SurfaceContext() const {
        return (tContextImplement&)m_surfaceContext;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    tContextImplement& m_surfaceContext;
};
typedef ImageT<> Image;

} // namespace osx
} // namespace apple 
} // namespace surface 
} // namespace graphic 
} // namespace imago 
} // namespace cocoa 
} // namespace cacao 

typedef cacao::cocoa::imago::graphic::surface::apple::osx::Image IGSImage;

#endif // _CACAO_COCOA_IMAGO_GRAPHIC_SURFACE_APPLE_OSX_IMAGE_HH
        

