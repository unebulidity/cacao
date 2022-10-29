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
///   File: iHashControlView.hh
///
/// Author: $author$
///   Date: 8/30/2016
///////////////////////////////////////////////////////////////////////
#ifndef _CACAO_APP_COCOA_APPLE_OSX_CRYPTO_IHASH_IHASHCONTROLVIEW_HH
#define _CACAO_APP_COCOA_APPLE_OSX_CRYPTO_IHASH_IHASHCONTROLVIEW_HH

#include "cacao/app/cocoa/apple/osx/crypto/iHash/iHashMainWindowPeer.hh"
#include "cacao/cocoa/apple/osx/Edit.hh"
#include "cacao/cocoa/apple/osx/Static.hh"
#include "cacao/cocoa/apple/osx/Label.hh"
#include "cacao/cocoa/apple/osx/Check.hh"
#include "cacao/cocoa/apple/osx/Button.hh"
#include "cacao/cocoa/apple/osx/Progress.hh"

#define XOS_GUI_COCOA_CRYPTO_HASH_IHASH_HASH_SIZE 20
#define XOS_GUI_COCOA_CRYPTO_HASH_IHASH_HASH_NAME "Hash"

#define XOS_GUI_COCOA_CRYPTO_HASH_IHASH_CONTROL_HASH_SIZE 20
#define XOS_GUI_COCOA_CRYPTO_HASH_IHASH_CONTROL_HASH_SIZE_MAX 48

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

///////////////////////////////////////////////////////////////////////
/// Interface: iHashControlView
///////////////////////////////////////////////////////////////////////
@interface iHashControlView: NSView {
    }
    @property (assign) iHashMainWindowPeer* mainWindowPeer;

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

    @property (assign) Check* upper;
    @property (assign) Progress* progress;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (iHashControlView*)initWithFrame:(NSRect)recttarget:(NSObject*)target
                         mainWindowPeer:(iHashMainWindowPeer*)mainWindowPeer;

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
    - (void)showProgress:(size_t)maximum amount:(size_t)amount;
    - (void)updateProgress:(size_t)amount;
    - (void)hideProgress;
@end
#endif // _CACAO_APP_COCOA_APPLE_OSX_CRYPTO_IHASH_IHASHCONTROLVIEW_HH
        

