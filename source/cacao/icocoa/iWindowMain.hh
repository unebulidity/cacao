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
///   File: iWindowMain.hh
///
/// Author: $author$
///   Date: 7/11/2016
///////////////////////////////////////////////////////////////////////
#ifndef _CACAO_ICOCOA_IWINDOWMAIN_HH
#define _CACAO_ICOCOA_IWINDOWMAIN_HH

#include "cacao/icocoa/iMainWindow.hh"
#include "cacao/icocoa/iMain.hh"

#define CACAO_ICOCOA_IWINDOWMAIN_WINDOW_TITLE "iWindowMain"
#define CACAO_ICOCOA_IWINDOWMAIN_WINDOW_X 0
#define CACAO_ICOCOA_IWINDOWMAIN_WINDOW_Y 2048
#define CACAO_ICOCOA_IWINDOWMAIN_WINDOW_WIDTH 256
#define CACAO_ICOCOA_IWINDOWMAIN_WINDOW_HEIGHT 256

///////////////////////////////////////////////////////////////////////
/// Interface: iWindowMain
///////////////////////////////////////////////////////////////////////
@interface iWindowMain: iMain {
    iMainWindow* mainWindow_;
    iApplication* app_;
    iAutoreleasePool* pool_;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (id)init:(cacao::gui::main*)main;
    - (iMainWindow*)createMainWindow:(iRect)contentRect argc:(int)argc argv:(char**)argv env:(char**)env;
    - (iRect)contentRect:(int)argc argv:(char**)argv env:(char**)env;
    - (const char*)titleUTF8String:(int)argc argv:(char**)argv env:(char**)env;
    - (int)runApplication:(iApplication*)app argc:(int)argc argv:(char**)argv env:(char**)env;
    - (int)beforeRunApplication:(iApplication*)app argc:(int)argc argv:(char**)argv env:(char**)env;
    - (int)run:(int)argc argv:(char**)argv env:(char**)env;
@end

namespace cacao {
namespace icocoa {

} // namespace icocoa 
} // namespace cacao 

#endif // _CACAO_ICOCOA_IWINDOWMAIN_HH 
