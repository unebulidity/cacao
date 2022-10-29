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
///   File: Context.hh
///
/// Author: $author$
///   Date: 10/13/2016
///////////////////////////////////////////////////////////////////////
#ifndef _CACAO_COCOA_IMAGO_GRAPHIC_SURFACE_APPLE_OSX_CONTEXT_HH
#define _CACAO_COCOA_IMAGO_GRAPHIC_SURFACE_APPLE_OSX_CONTEXT_HH

#include "cacao/cocoa/imago/graphic/surface/apple/osx/Pixel.hh"
#include "imago/graphic/surface/Context.hpp"

namespace cacao {
namespace cocoa {
namespace imago {
namespace graphic {
namespace surface {
namespace apple {
namespace osx {

///////////////////////////////////////////////////////////////////////
///  Class: ContextImplementT
///////////////////////////////////////////////////////////////////////
template
<class TPixelImplement = PixelImplement,
 class TImplementBase = ::imago::graphic::surface::ContextImplement,
 class TColorSample = ColorSample,
 class TImplements = TImplementBase>
class _EXPORT_CLASS ContextImplementT: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef TPixelImplement tPixelImplement;
    typedef TImplementBase tImplementBase;
    typedef TColorSample tColorSample;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void FillRectangle
    (tOffset x, tOffset y, tSize width, tSize height, const tPixelImplement& color) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef ContextImplementT<> ContextImplement;

///////////////////////////////////////////////////////////////////////
///  Class: ContextT
///////////////////////////////////////////////////////////////////////
template
<class TPixelImplement = PixelImplement,
 class TImplementBase = ContextImplement,
 class TBase = ::imago::graphic::surface::Context,
 class TColorSample = ColorSample,
 class TImplements = TImplementBase, class TExtends = TBase>
class _EXPORT_CLASS ContextT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TPixelImplement tPixelImplement;
    typedef TImplementBase tImplementBase;
    typedef TColorSample tColorSample;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ContextT(NSView* view): m_view(view) {
    }
    virtual ~ContextT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void FillRectangle
    (tOffset x, tOffset y, tSize width, tSize height, const tPixelImplement& color) {
        if ((width) && (height) && (m_view)) {
            NSRect rect = [m_view bounds];
            y = ((int)rect.size.height)-y-height;
            [((NSColor*)color) set];
            NSRectFill(NSMakeRect(x,y, width,height));
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    NSView* m_view;
};
typedef ContextT<> Context;

} // namespace osx
} // namespace apple 
} // namespace surface 
} // namespace graphic 
} // namespace imago 
} // namespace cocoa 
} // namespace cacao 

typedef cacao::cocoa::imago::graphic::surface::apple::osx::Context IGSContext;

#endif // _CACAO_COCOA_IMAGO_GRAPHIC_SURFACE_APPLE_OSX_CONTEXT_HH
