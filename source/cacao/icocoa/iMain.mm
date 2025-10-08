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
///   File: iMain.mm
///
/// Author: $author$
///   Date: 7/10/2016
///////////////////////////////////////////////////////////////////////
#include "cacao/icocoa/iMain.hh"

///////////////////////////////////////////////////////////////////////
/// Implentation: iMain
///////////////////////////////////////////////////////////////////////
@implementation iMain
    - (int)run:(int)argc argv:(char**)argv env:(char**)env {
        int err = 0;
        CACAO_LOG_TRACE("in...");
        CACAO_LOG_TRACE("...out");
        return err;
    }
    - (int)beforeRun:(int)argc argv:(char**)argv env:(char**)env {
        int err = 0;
        CACAO_LOG_TRACE("in...");
        CACAO_LOG_TRACE("...out");
        return err;
    }
    - (int)afterRun:(int)argc argv:(char**)argv env:(char**)env {
        int err = 0;
        CACAO_LOG_TRACE("in...");
        CACAO_LOG_TRACE("...out");
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    @synthesize main = _main;
    - (id)init:(cacao::gui::main*)main {
        [super init];
        _main = main;
        return self;
    }
    - (int)main:(int)argc argv:(char**)argv env:(char**)env {
        int err = 0;
        CACAO_LOG_TRACE("in...");
        if (!(err = [self beforeRun:argc argv:argv env:env])) {
            int err2 = 0;
            if ((err = [self run:argc argv:argv env:env]))
                CACAO_LOG_TRACE("...error " << err << " on [run]");
            if ((err2 = [self afterRun:argc argv:argv env:env])) {
                CACAO_LOG_TRACE("...error " << err << " on [afterRun]");
                if (!err) err = err2;
            }
        } else {
            CACAO_LOG_TRACE("...error " << err << " on [beforeRun]");
        }
        CACAO_LOG_TRACE("...out");
        return err;
    }
    - (int)beforeMain:(int)argc argv:(char**)argv env:(char**)env {
        int err = 0;
        CACAO_LOG_TRACE("in...");
        CACAO_LOG_TRACE("...out");
        return err;
    }
    - (int)afterMain:(int)argc argv:(char**)argv env:(char**)env {
        int err = 0;
        CACAO_LOG_TRACE("in...");
        CACAO_LOG_TRACE("...out");
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (int)usage:(int)argc argv:(char**)argv env:(char**)env {
        int err = 0;
        err = _main->__usage(argc, argv, env);
        return err;
    }
    - (int)onOption:(int)optval optarg:(const char*)optarg optname:(const char*)optname optind:(int)optind argc:(int)argc argv:(char**)argv env:(char**)env {
        int err = 0;
        switch(optval) {
        default:
            err = _main->__on_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        }
        return err;
    }
    - (int)onArgument:(const char*)arg argind:(int)argind argc:(int)argc argv:(char**)argv env:(char**)env {
        int err = 0;
        switch(argind) {
        default:
            err = _main->__on_argument(arg, argind, argc, argv, env);
            break;
        }
        return err;
    }
    - (const char*)optionUsage:(const char*&)optarg longopt:(const struct option*)longopt {
        const char* chars = "";
        switch(longopt->val) {
        default:
            chars = _main->__option_usage(optarg, longopt);
            break;
        }
        return chars;
    }
    - (const char*)options:(const struct option*&)longopts {
        static struct option optstruct[] = {{0, 0, 0, 0}};
        const char* chars = "";
        longopts = optstruct;
        chars = _main->__options(longopts);
        return chars;
    }
    - (const char*)arguments:(const char**&)args {
        const char* chars = 0;
        args = 0;
        chars = _main->__arguments(args);
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (void)destroy {
    }
@end

namespace cacao {
namespace icocoa {

} // namespace icocoa 
} // namespace cacao 
