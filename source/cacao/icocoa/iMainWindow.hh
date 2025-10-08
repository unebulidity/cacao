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
///   File: iMainWindow.hh
///
/// Author: $author$
///   Date: 7/11/2016
///////////////////////////////////////////////////////////////////////
#ifndef _CACAO_ICOCOA_IMAINWINDOW_HH
#define _CACAO_ICOCOA_IMAINWINDOW_HH

#include "cacao/icocoa/iMainView.hh"

#define CACAO_ICOCOA_IMAINWINDOW_TITLE "iMainWindow"
#define CACAO_ICOCOA_IMAINWINDOW_STYLE iDefaultDesktopWindowMask
#define CACAO_ICOCOA_IMAINWINDOW_BACKING iDefaultDesktopWindowBacking
#define CACAO_ICOCOA_IMAINWINDOW_DEFER NO

///////////////////////////////////////////////////////////////////////
/// Interface: iMainWindow
///////////////////////////////////////////////////////////////////////
@interface iMainWindow: iWindow <iWindowDelegate> {
    iView* mainView_;
    iApplication* app_;
    }
    - (iMainWindow*)initWithRect:(iRect)contentRect argc:(int)argc argv:(char**)argv env:(char**)env;
    - (iString*)setMainTitle:(int)argc argv:(char**)argv env:(char**)env;
    - (iView*)createMainView:(int)argc argv:(char**)argv env:(char**)env;
    - (const char*)mainTitleUTF8String:(int)argc argv:(char**)argv env:(char**)env;
    - (iApplication*)setApplication:(iApplication*)app;
    - (iApplication*)application;
    - (void)windowWillClose:(iNotification*)notification;
@end

namespace cacao {
namespace icocoa {

} // namespace icocoa 
} // namespace cacao 

#endif // _CACAO_ICOCOA_IMAINWINDOW_HH 
