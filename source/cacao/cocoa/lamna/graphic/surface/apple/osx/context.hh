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
///   File: context.hh
///
/// Author: $author$
///   Date: 9/7/2016
///////////////////////////////////////////////////////////////////////
#ifndef _CACAO_COCOA_LAMNA_GRAPHIC_SURFACE_APPLE_OSX_CONTEXT_HH
#define _CACAO_COCOA_LAMNA_GRAPHIC_SURFACE_APPLE_OSX_CONTEXT_HH

#include "cacao/cocoa/lamna/graphic/surface/apple/osx/pixel.hh"
#include "lamna/graphic/surface/context.hpp"

namespace cacao {
namespace cocoa {
namespace lamna {
namespace graphic {
namespace surface {
namespace apple {
namespace osx {

///////////////////////////////////////////////////////////////////////
///  Class: context_interfacet
///////////////////////////////////////////////////////////////////////
template
<class TContextInterface = ::lamna::graphic::surface::context_interface,
 class TPixelInterface = pixel_interface,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 class TOffset = ssize_t,
 class TImplements = TContextInterface>

class _EXPORT_CLASS context_interfacet: virtual public TImplements {
public:
    typedef TImplements Implements;

    typedef TPixelInterface tPixelInterface;
    typedef TInt tInt;
    typedef TSize tSize;
    typedef TLength tLength;
    typedef TOffset tOffset;

    typedef ::lamna::graphic::eError eError;
    enum {
        e_ERROR_NONE = ::lamna::graphic::e_ERROR_NONE,
        e_ERROR_FAILED = ::lamna::graphic::e_ERROR_FAILED,
    };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual eError FillRectangle
    (tOffset x, tOffset y, tSize width, tSize height, const tPixelInterface& color) {
        eError error = e_ERROR_NONE;
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef context_interfacet<> context_interface;

///////////////////////////////////////////////////////////////////////
///  Class: contextt
///////////////////////////////////////////////////////////////////////
template
<class TContextInterface = context_interface,
 class TContext = ::lamna::graphic::surface::context,
 class TPixelInterface = pixel_interface,
 class TInt = int,
 class TSize = size_t,
 class TLength = ssize_t,
 class TOffset = ssize_t,
 class TImplements = TContextInterface, class TExtends = TContext>

class _EXPORT_CLASS contextt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef TPixelInterface tPixelInterface;
    typedef TInt tInt;
    typedef TSize tSize;
    typedef TLength tLength;
    typedef TOffset tOffset;

    typedef ::lamna::graphic::eError eError;
    enum {
        e_ERROR_NONE = ::lamna::graphic::e_ERROR_NONE,
        e_ERROR_FAILED = ::lamna::graphic::e_ERROR_FAILED,
    };

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    contextt(NSView* view): view_(view) {
    }
    virtual ~contextt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual eError FillRectangle
    (tOffset x, tOffset y, tSize width, tSize height, const tPixelInterface& color) {
        eError error = e_ERROR_NONE;
        NSRect rect = [view_ bounds];
        y = ((int)rect.size.height)-y-height;
        [((NSColor*)color) set];
        NSRectFill(NSMakeRect(x,y, width,height));
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    NSView* view_;
};
typedef contextt<> context;

} // namespace osx
} // namespace apple 
} // namespace surface 
} // namespace graphic 
} // namespace lamna 
} // namespace cocoa 
} // namespace cacao 

#endif // _CACAO_COCOA_LAMNA_GRAPHIC_SURFACE_APPLE_OSX_CONTEXT_HH 
