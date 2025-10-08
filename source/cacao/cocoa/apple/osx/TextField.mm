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
///   File: TextField.mm
///
/// Author: $author$
///   Date: 8/30/2016
///////////////////////////////////////////////////////////////////////
#include "cacao/cocoa/apple/osx/TextField.hh"

///////////////////////////////////////////////////////////////////////
/// Implentation: TextField
///////////////////////////////////////////////////////////////////////
@implementation TextField
    - (TextField*)initWithFrame:(NSRect)rect stringValue:(NSString*)stringValue {
        if (([super initWithFrame:rect])) {
            if ((stringValue)) {
                [self setStringValue:stringValue];
            }
            return self;
        }
        return nil;
    }

    - (const char*)setTextUTF8String:(const String&)text {
        const char* chars = nil;
        if ((chars = text.chars())) {
            NSString* string;
            if ((string = [NSString stringWithUTF8String:chars])) {
                [self setStringValue:string];
                return chars;
            }
        }
        return nil;
    }
    - (const char*)getTextUTF8String:(String&)text {
        NSString* string = nil;
        if ((string = [self stringValue])) {
            const char* chars = nil;
            if ((chars = [string UTF8String])) {
                text.assign(chars);
                return text.chars();
            }
        }
        return nil;
    }
@end
