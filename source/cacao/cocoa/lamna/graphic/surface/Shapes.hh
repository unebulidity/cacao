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
///   File: Shapes.hh
///
/// Author: $author$
///   Date: 9/15/2016
///////////////////////////////////////////////////////////////////////
#ifndef _CACAO_COCOA_LAMNA_GRAPHIC_SURFACE_SHAPES_HH
#define _CACAO_COCOA_LAMNA_GRAPHIC_SURFACE_SHAPES_HH

#include "cacao/cocoa/os/Cocoa.hh"
#include "lamna/graphic/surface/shape/key_icon.hpp"
#include "lamna/graphic/surface/elliptical_rounded_rectangle.hpp"
#include "lamna/graphic/surface/rounded_rectangle.hpp"
#include "lamna/graphic/surface/rectangle.hpp"
#include "lamna/graphic/surface/filled_circle.hpp"
#include "lamna/graphic/surface/triangle.hpp"

typedef lamna::graphic::surface::shape::key_icon LGSKeyIcon;

typedef lamna::graphic::surface::elliptical_rounded_rectangle LGSEllipticalRoundedRectangle;
typedef lamna::graphic::surface::filled_elliptical_rounded_rectangle LGSFilledEllipticalRoundedRectangle;
typedef lamna::graphic::surface::hollowed_elliptical_rounded_rectangle LGSHollowedEllipticalRoundedRectangle;

typedef lamna::graphic::surface::rounded_rectangle LGSRoundedRectangle;
typedef lamna::graphic::surface::filled_rounded_rectangle LGSFilledRoundedRectangle;
typedef lamna::graphic::surface::hollowed_rounded_rectangle LGSHollowedRoundedRectangle;

typedef lamna::graphic::surface::rectangle LGSRectangle;
typedef lamna::graphic::surface::filled_rectangle LGSFilledRectangle;

typedef lamna::graphic::surface::triangle LGSTriangle;
typedef lamna::graphic::surface::filled_triangle LGSFilledTriangle;

namespace cacao {
namespace cocoa {
namespace lamna {
namespace graphic {
namespace surface {

} // namespace surface
} // namespace graphic
} // namespace lamna
} // namespace cocoa
} // namespace cacao

#endif // _CACAO_COCOA_LAMNA_GRAPHIC_SURFACE_SHAPES_HH