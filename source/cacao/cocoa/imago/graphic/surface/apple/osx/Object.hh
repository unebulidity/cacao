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
///   File: Object.hh
///
/// Author: $author$
///   Date: 10/14/2016
///////////////////////////////////////////////////////////////////////
#ifndef _CACAO_COCOA_IMAGO_GRAPHIC_SURFACE_APPLE_OSX_OBJECT_HH
#define _CACAO_COCOA_IMAGO_GRAPHIC_SURFACE_APPLE_OSX_OBJECT_HH

#include "cacao/cocoa/imago/graphic/surface/apple/osx/Image.hh"
#include "imago/graphic/surface/Object.hpp"

namespace cacao {
namespace cocoa {
namespace imago {
namespace graphic {
namespace surface {
namespace apple {
namespace osx {

///////////////////////////////////////////////////////////////////////
///  Class: ObjectT
///////////////////////////////////////////////////////////////////////
template
<class TObject = ::imago::graphic::surface::Object,
 class TImageImplement = ImageImplement,
 class TColorSample = ColorSample,
 class TExtends = TObject>

class _EXPORT_CLASS ObjectT: public TExtends {
public:
    typedef TExtends Extends;

    typedef TObject tObject;
    typedef TImageImplement tImageImplement;
    typedef TColorSample tColorSample;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ObjectT(tImageImplement& surfaceImage)
    : Extends(surfaceImage), m_surfaceImage(surfaceImage) {
    }
    virtual ~ObjectT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual tImageImplement& SurfaceImage() const {
        return (tImageImplement&)m_surfaceImage;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    tImageImplement& m_surfaceImage;
};
typedef ObjectT<> Object;

} // namespace osx 
} // namespace apple 
} // namespace surface 
} // namespace graphic 
} // namespace imago 
} // namespace cocoa 
} // namespace cacao 

typedef cacao::cocoa::imago::graphic::surface::apple::osx::Object IGSObject;

#endif // _CACAO_COCOA_IMAGO_GRAPHIC_SURFACE_APPLE_OSX_OBJECT_HH
        

