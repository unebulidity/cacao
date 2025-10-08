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
///   File: iHashControlView.mm
///
/// Author: $author$
///   Date: 8/30/2016
///////////////////////////////////////////////////////////////////////
#include "cacao/app/cocoa/apple/osx/crypto/iHash/iHashControlView.hh"
#include "cacao/app/cocoa/apple/osx/crypto/iHash/MainWindow.hh"

///////////////////////////////////////////////////////////////////////
/// Implentation: iHashControlView
///////////////////////////////////////////////////////////////////////
@implementation iHashControlView

    - (iHashControlView*)initWithFrame:(NSRect)rect target:(NSObject*)target
                         mainWindowPeer:(iHashMainWindowPeer*)mainWindowPeer {
        const char* okLabel = XOS_GUI_COCOA_CRYPTO_HASH_IHASH_CONTROL_OK_LABEL;
        const char* cancelLabel = XOS_GUI_COCOA_CRYPTO_HASH_IHASH_CONTROL_CANCEL_LABEL;
        const char* quitLabel = XOS_GUI_COCOA_CRYPTO_HASH_IHASH_CONTROL_QUIT_LABEL;
        const char* upperLabel = XOS_GUI_COCOA_CRYPTO_HASH_IHASH_CONTROL_UPPER_LABEL;
        const char* textLabel = XOS_GUI_COCOA_CRYPTO_HASH_IHASH_CONTROL_TEXT_LABEL;
        const char* fileLabel = XOS_GUI_COCOA_CRYPTO_HASH_IHASH_CONTROL_FILE_LABEL;
        const char* hashLabel = XOS_GUI_COCOA_CRYPTO_HASH_IHASH_CONTROL_HASH_LABEL;

        size_t hashSize = XOS_GUI_COCOA_CRYPTO_HASH_IHASH_HASH_SIZE;
        size_t hashSizeMax = XOS_GUI_COCOA_CRYPTO_HASH_IHASH_CONTROL_HASH_SIZE_MAX;
        size_t labelLength = XOS_GUI_COCOA_CRYPTO_HASH_IHASH_CONTROL_LABEL_LENGTH;
        size_t buttonLabelLength = XOS_GUI_COCOA_CRYPTO_HASH_IHASH_CONTROL_LABEL_LENGTH;
        size_t border = XOS_GUI_COCOA_CRYPTO_HASH_IHASH_CONTROL_BORDER;

        size_t x = border, y = border;
        size_t width = border*2, height = width;
        size_t charWidth = 10, charHeight = 20;
        size_t rowWidth = width, rowSpacing = charWidth/2;
        size_t colSpacing = rowSpacing;
        size_t hashBorder = 1, hashWidth = 0, hashWidthMax = 0;
        size_t hashHeight = charHeight + hashBorder*2;

        NSRect frame;

        if (([super initWithFrame:rect])) {
            [self setAutoresizesSubviews:NO];

            if ((_mainWindowPeer = mainWindowPeer)) {
                hashSize = _mainWindowPeer->HashSize();
                hashLabel = _mainWindowPeer->HashName();
            }

            if (((hashWidth = hashSize*charWidth*2)
                > (hashWidthMax = hashSizeMax*charWidth*2))) {
                hashWidth = hashWidthMax;
            }

            frame = NSMakeRect(x+charWidth*labelLength + colSpacing, y, hashWidth, hashHeight);
            if ((_progress = [[Progress alloc] initWithFrame:frame])) {
                [_progress hide];
                [self addSubview:_progress];
                if (width < (rowWidth += frame.size.width)) {
                    width = rowWidth + border;
                }
                height += frame.size.height;
                frame.origin.x += frame.size.width + colSpacing;
                frame.size.width = charWidth*buttonLabelLength;

                if ((_quitButton = [[Button alloc] initWithFrame:frame
                     title:[NSString stringWithUTF8String:quitLabel]
                     target:target action:@selector(quitClicked:)])) {
                    [self addSubview:_quitButton];
                    if (width < (rowWidth += frame.size.width + colSpacing)) {
                        width = rowWidth + border;
                    }
                }
                y += frame.size.height + rowSpacing;
                rowWidth = border*2;
            }

            frame = NSMakeRect(x, y, charWidth*labelLength, hashHeight);
            if ((_textLabel = [[Label alloc] initWithFrame:frame
                 stringValue:[NSString stringWithUTF8String:textLabel]])) {
                [_textLabel setAlignment:NSRightTextAlignment];
                [self addSubview:_textLabel];
                if (width < (rowWidth += frame.size.width)) {
                    width = rowWidth + border;
                }
                height += frame.size.height + rowSpacing;
                frame.origin.x += frame.size.width + colSpacing;
                frame.size.width = hashWidth;

                if ((_textEdit = [[Edit alloc] initWithFrame:frame  stringValue:nil])) {
                    [self addSubview:_textEdit];
                    if (width < (rowWidth += frame.size.width)) {
                        width = rowWidth + border;
                    }
                    frame.origin.x += frame.size.width + colSpacing;
                    frame.size.width = charWidth*buttonLabelLength;

                    if ((_cancelButton = [[Button alloc] initWithFrame:frame
                         title:[NSString stringWithUTF8String:cancelLabel]
                         target:target action:@selector(cancelClicked:)])) {
                        [self addSubview:_cancelButton];
                        if (width < (rowWidth += frame.size.width + colSpacing)) {
                            width = rowWidth + border;
                        }
                    }
                }
                y += frame.size.height + rowSpacing;
                rowWidth = border*2;
            }

            frame = NSMakeRect(x, y, charWidth*labelLength, hashHeight);
            if ((_fileLabel = [[Label alloc] initWithFrame:frame
                 stringValue:[NSString stringWithUTF8String:fileLabel]])) {
                [_fileLabel setAlignment:NSRightTextAlignment];
                [self addSubview:_fileLabel];
                if (width < (rowWidth += frame.size.width)) {
                    width = rowWidth + border;
                }
                height += frame.size.height + rowSpacing;
                frame.origin.x += frame.size.width + colSpacing;
                frame.size.width = hashWidth;

                if ((_fileEdit = [[Edit alloc] initWithFrame:frame  stringValue:nil])) {
                    [self addSubview:_fileEdit];
                    if (width < (rowWidth += frame.size.width)) {
                        width = rowWidth + border;
                    }
                    frame.origin.x += frame.size.width + colSpacing;
                    frame.size.width = charWidth*buttonLabelLength;

                    if ((_okButton = [[Button alloc] initWithFrame:frame
                         title:[NSString stringWithUTF8String:okLabel]
                         target:target action:@selector(okClicked:)])) {
                        [self addSubview:_okButton];
                        if (width < (rowWidth += frame.size.width + colSpacing)) {
                            width = rowWidth + border;
                        }
                    }
                }
                y += frame.size.height + rowSpacing;
                rowWidth = border*2;
            }

            frame = NSMakeRect(x, y, charWidth*labelLength, hashHeight);
            if ((_hashLabel = [[Label alloc] initWithFrame:frame
                 stringValue:[NSString stringWithUTF8String:hashLabel]])) {
                [_hashLabel setAlignment:NSRightTextAlignment];
                [self addSubview:_hashLabel];
                if (width < (rowWidth += frame.size.width)) {
                    width = rowWidth + border;
                }
                height += frame.size.height + rowSpacing;
                frame.origin.x += frame.size.width + colSpacing;
                frame.size.width = hashWidth;

                if ((_hashEdit = [[Static alloc] initWithFrame:frame  stringValue:nil])) {
                    [self addSubview:_hashEdit];
                    if (width < (rowWidth += frame.size.width)) {
                        width = rowWidth + border;
                    }
                    frame.origin.x += frame.size.width + colSpacing;
                    frame.size.width = charWidth*buttonLabelLength;

                    if ((_upper = [[Check alloc] initWithFrame:frame
                         title:[NSString stringWithUTF8String:upperLabel]
                         target:target action:@selector(upperClicked:)])) {
                        [self addSubview:_upper];
                        if (width < (rowWidth += frame.size.width + colSpacing)) {
                            width = rowWidth + border;
                        }
                    }
                }
                y += frame.size.height + rowSpacing;
                rowWidth = border*2;
            }
            frame = [self frame];
            frame.size.width = width;
            frame.size.height = height;
            [self setFrameSize:frame.size];
            return self;
        }
        return nil;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (void)setHash:(const String&)text{
        if ((_hashEdit)) {
            [_hashEdit setTextUTF8String:text];
        }
    }
    - (void)getHash:(String&)text{
        if ((_hashEdit)) {
            [_hashEdit getTextUTF8String:text];
        }
    }
    - (BOOL)upperChecked {
        return [_upper checked];
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (void)setFile:(const String&)text{
        if ((_fileEdit)) {
            [_fileEdit setTextUTF8String:text];
        }
    }
    - (void)getFile:(String&)text{
        if ((_fileEdit)) {
            [_fileEdit getTextUTF8String:text];
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (void)setText:(const String&)text{
        if ((_textEdit)) {
            [_textEdit setTextUTF8String:text];
        }
    }
    - (void)getText:(String&)text{
        if ((_textEdit)) {
            [_textEdit getTextUTF8String:text];
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (void)showProgress:(size_t)maximum amount:(size_t)amount {
        if ((_progress)) {
            [_progress setMaxValue:maximum];
            [_progress setDoubleValue:amount];
            [_progress show];
        }
    }
    - (void)updateProgress:(size_t)amount {
        if ((_progress)) {
            [_progress setDoubleValue:amount];
        }
    }
    - (void)hideProgress {
        if ((_progress)) {
            [_progress hide];
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (void)drawRect:(NSRect)rect {
        NSRect bounds = [self bounds];
        [[self backgroundColor] set];
        NSRectFill(bounds);
    }
    - (NSColor*)backgroundColor {
        return [NSColor whiteColor];
    }
@end
        

