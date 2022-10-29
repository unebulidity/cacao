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
///   File: Progress.mm
///
/// Author: $author$
///   Date: 8/30/2016
///////////////////////////////////////////////////////////////////////
#include "cacao/cocoa/apple/osx/Progress.hh"

///////////////////////////////////////////////////////////////////////
/// Implentation: Progress
///////////////////////////////////////////////////////////////////////
@implementation Progress
    - (Progress*)initWithFrame:(NSRect)rect {
        if (([super initWithFrame:rect])) {
            [self setMinValue:0];
            [self setMaxValue:100];
            [self setDoubleValue:[self maxValue]];
            [self setStyle:NSProgressIndicatorBarStyle];
            [self setIndeterminate:NO];
            [self setHidden:NO];
            return self;
        }
        return nil;
    }

    - (void)setPercentValue:(double)value {
        double amount = 0;
        if ((amount = [self maxValue] - [self minValue]) > 0) {
            amount = (value * 100) / amount;
        } else {
            amount = [self maxValue];
        }
        [self setDoubleValue:amount];
    }

    - (void)show {
        [self setHidden:NO];
        [self startAnimation:self];
    }
    - (void)hide {
        [self stopAnimation:self];
        [self setHidden:YES];
    }
@end
