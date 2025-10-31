//////////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2025 $organization$
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
///   File: iDentifyControlView.hh
///
/// Author: $author$
///   Date: 10/30/2025
//////////////////////////////////////////////////////////////////////////
#ifndef CACAO_APP_COCOA_APPLE_OSX_IDENTIFY_IDENTIFYCONTROLVIEW_HH
#define CACAO_APP_COCOA_APPLE_OSX_IDENTIFY_IDENTIFYCONTROLVIEW_HH

#include "cacao/app/cocoa/apple/osx/iDentify/iDentifyMainWindowPeer.hh"
#include "cacao/cocoa/lamna/graphic/surface/apple/osx/color.hh"
#include "cacao/cocoa/apple/osx/Edit.hh"
#include "cacao/cocoa/apple/osx/Static.hh"
#include "cacao/cocoa/apple/osx/Label.hh"
#include "cacao/cocoa/apple/osx/Check.hh"
#include "cacao/cocoa/apple/osx/Button.hh"
#include "cacao/cocoa/apple/osx/Progress.hh"

#define XOS_GUI_COCOA_CRYPTO_HASH_IHASH_HASH_SIZE 24
#define XOS_GUI_COCOA_CRYPTO_HASH_IHASH_HASH_NAME "Hash"

#define XOS_GUI_COCOA_CRYPTO_HASH_IHASH_CONTROL_HASH_SIZE XOS_GUI_COCOA_CRYPTO_HASH_IHASH_HASH_SIZE
#define XOS_GUI_COCOA_CRYPTO_HASH_IHASH_CONTROL_HASH_SIZE_MAX XOS_GUI_COCOA_CRYPTO_HASH_IHASH_HASH_SIZE

#define XOS_GUI_COCOA_CRYPTO_HASH_IHASH_CONTROL_BORDER 10
#define XOS_GUI_COCOA_CRYPTO_HASH_IHASH_CONTROL_LABEL_LENGTH 8
#define XOS_GUI_COCOA_CRYPTO_HASH_IHASH_CONTROL_HASH_LABEL "Hash"
#define XOS_GUI_COCOA_CRYPTO_HASH_IHASH_CONTROL_FILE_LABEL "File"
#define XOS_GUI_COCOA_CRYPTO_HASH_IHASH_CONTROL_TEXT_LABEL "Text"
#define XOS_GUI_COCOA_CRYPTO_HASH_IHASH_CONTROL_CASE_LABEL "Case"
#define XOS_GUI_COCOA_CRYPTO_HASH_IHASH_CONTROL_UPPER_LABEL "Upper"
#define XOS_GUI_COCOA_CRYPTO_HASH_IHASH_CONTROL_LOWER_LABEL "Lower"
#define XOS_GUI_COCOA_CRYPTO_HASH_IHASH_CONTROL_OK_LABEL "Ok"
#define XOS_GUI_COCOA_CRYPTO_HASH_IHASH_CONTROL_CANCEL_LABEL "Cancel"
#define XOS_GUI_COCOA_CRYPTO_HASH_IHASH_CONTROL_QUIT_LABEL "Quit"

#define XOS_GUI_COCOA_CRYPTO_HASH_IHASH_CONTROL_USER_LABEL "User"
#define XOS_GUI_COCOA_CRYPTO_HASH_IHASH_CONTROL_RESOURCE_LABEL "Resource"
#define XOS_GUI_COCOA_CRYPTO_HASH_IHASH_CONTROL_PASSWORD_LABEL "Password"

#define CACAO_APP_COCOA_APPLE_OSX_IDENTIFY_IDENTIFYCONTROLVIEW_FG_COLOR_R 0xDD
#define CACAO_APP_COCOA_APPLE_OSX_IDENTIFY_IDENTIFYCONTROLVIEW_FG_COLOR_G 0xDD
#define CACAO_APP_COCOA_APPLE_OSX_IDENTIFY_IDENTIFYCONTROLVIEW_FG_COLOR_B 0xDD

#define CACAO_APP_COCOA_APPLE_OSX_IDENTIFY_IDENTIFYCONTROLVIEW_BG_COLOR_R 0x00
#define CACAO_APP_COCOA_APPLE_OSX_IDENTIFY_IDENTIFYCONTROLVIEW_BG_COLOR_G 0x00
#define CACAO_APP_COCOA_APPLE_OSX_IDENTIFY_IDENTIFYCONTROLVIEW_BG_COLOR_B 0x00

#define CACAO_APP_COCOA_APPLE_OSX_IDENTIFY_IDENTIFYCONTROLVIEW_BD_COLOR_R 0x88
#define CACAO_APP_COCOA_APPLE_OSX_IDENTIFY_IDENTIFYCONTROLVIEW_BD_COLOR_G 0x88
#define CACAO_APP_COCOA_APPLE_OSX_IDENTIFY_IDENTIFYCONTROLVIEW_BD_COLOR_B 0x88

namespace cacao {
namespace app {
namespace cocoa {
namespace apple {
namespace osx {
namespace iDentify {

} /// namespace iDentify 
} /// namespace osx 
} /// namespace apple 
} /// namespace cocoa 
} /// namespace app 
} /// namespace cacao 

///////////////////////////////////////////////////////////////////////
/// Interface: iDentifyControlView
///////////////////////////////////////////////////////////////////////
@interface iDentifyControlView: NSView {
    }
    @property (assign) iDentifyMainWindowPeer* mainWindowPeer;

    @property (assign) Label* upperLabel;
    @property (assign) Label* hashLabel;
    @property (assign) Label* fileLabel;
    @property (assign) Label* textLabel;

    @property (assign) Edit* hashEdit;
    @property (assign) Edit* fileEdit;
    @property (assign) Edit* textEdit;

    @property (assign) Button* okButton;
    @property (assign) Button* cancelButton;
    @property (assign) Button* quitButton;

    @property (assign) Label* userLabel;
    @property (assign) Label* resourceLabel;
    @property (assign) Label* passwordLabel;

    @property (assign) Edit* userEdit;
    @property (assign) Edit* resourceEdit;
    @property (assign) Edit* passwordEdit;

    @property (assign) Check* upper;
    @property (assign) Progress* progress;

    @property (assign) int fgR;
    @property (assign) int fgG;
    @property (assign) int fgB;
    @property (assign) LGSPixel* fgPixel;
    @property (assign) NSColor* fgColor;
    
    @property (assign) int bgR;
    @property (assign) int bgG;
    @property (assign) int bgB;
    @property (assign) LGSPixel* bgPixel;
    @property (assign) NSColor* bgColor;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (iDentifyControlView*)initWithFrame:(NSRect)recttarget:(NSObject*)target
                         mainWindowPeer:(iDentifyMainWindowPeer*)mainWindowPeer;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (void)setHash:(const String&)text;
    - (void)getHash:(String&)text;
    - (BOOL)upperChecked;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (void)setFile:(const String&)text;
    - (void)getFile:(String&)text;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (void)setText:(const String&)text;
    - (void)getText:(String&)text;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (void)setUser:(const String&)text;
    - (void)getUser:(String&)text;
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (void)setResource:(const String&)text;
    - (void)getResource:(String&)text;
    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (void)setPassword:(const String&)text;
    - (void)getPassword:(String&)text;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (void)showProgress:(size_t)maximum amount:(size_t)amount;
    - (void)updateProgress:(size_t)amount;
    - (void)hideProgress;
@end

#endif /// ndef CACAO_APP_COCOA_APPLE_OSX_IDENTIFY_IDENTIFYCONTROLVIEW_HH

