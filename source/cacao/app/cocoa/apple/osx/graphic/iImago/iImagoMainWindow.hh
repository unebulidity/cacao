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
///   File: iImagoMainWindow.hh
///
/// Author: $author$
///   Date: 10/11/2016
///////////////////////////////////////////////////////////////////////
#ifndef _CACAO_APP_COCOA_APPLE_OSX_GRAPHIC_IIMAGO_IIMAGOMAINWINDOW_HH
#define _CACAO_APP_COCOA_APPLE_OSX_GRAPHIC_IIMAGO_IIMAGOMAINWINDOW_HH

#include "cacao/app/cocoa/apple/osx/graphic/iImago/iImagoMainView.hh"
#include "cacao/cocoa/apple/osx/MainWindow.hh"

///////////////////////////////////////////////////////////////////////
/// Interface: iImagoMainWindow
///////////////////////////////////////////////////////////////////////
@interface iImagoMainWindow: MainWindow {
    }
    @property (assign) iImagoMainView* mainView;

    - (iImagoMainWindow*)initWithContentRect:(NSRect)contentRect
                         application:(Application*)application;
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

#endif // _CACAO_APP_COCOA_APPLE_OSX_GRAPHIC_IIMAGO_IIMAGOMAINWINDOW_HH 
