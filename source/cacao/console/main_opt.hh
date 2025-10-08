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
///   File: main_opt.hh
///
/// Author: $author$
///   Date: 7/10/2016
///////////////////////////////////////////////////////////////////////
#ifndef _CACAO_CONSOLE_MAIN_OPT_HH
#define _CACAO_CONSOLE_MAIN_OPT_HH

#include "cacao/base/base.hh"

#if !defined(USE_NADIR_BASE)
#include "xos/base/getopt/main.hpp"
#include "xos/base/getopt/main_opt.hpp"

#define CACAO_MAIN_LOGGING_OPTVAL_C XOS_MAIN_LOGGING_OPTVAL_C
#define CACAO_MAIN_LOGGING_OPTARG XOS_MAIN_LOGGING_OPTARG
#define CACAO_MAIN_LOGGING_OPTUSE XOS_MAIN_LOGGING_OPTUSE

#define CACAO_MAIN_HELP_OPTVAL_C XOS_MAIN_HELP_OPTVAL_C
#define CACAO_MAIN_HELP_OPTARG XOS_MAIN_HELP_OPTARG
#define CACAO_MAIN_HELP_OPTUSE XOS_MAIN_HELP_OPTUSE

#define CACAO_MAIN_OPTIONS_CHARS XOS_MAIN_OPTIONS_CHARS
#define CACAO_MAIN_OPTIONS_OPTIONS XOS_MAIN_OPTIONS_OPTIONS

enum {
    CACAO_MAIN_OPT_ARGUMENT_NONE     = XOS_MAIN_OPT_ARGUMENT_NONE,
    CACAO_MAIN_OPT_ARGUMENT_REQUIRED = XOS_MAIN_OPT_ARGUMENT_REQUIRED,
    CACAO_MAIN_OPT_ARGUMENT_OPTIONAL = XOS_MAIN_OPT_ARGUMENT_OPTIONAL
};
#else // !defined(USE_NADIR_BASE)
#endif // !defined(USE_NADIR_BASE)

namespace cacao {
namespace console {

typedef int main_opt_argument_t;
enum {
    MAIN_OPT_ARGUMENT_NONE     = CACAO_MAIN_OPT_ARGUMENT_NONE,
    MAIN_OPT_ARGUMENT_REQUIRED = CACAO_MAIN_OPT_ARGUMENT_REQUIRED,
    MAIN_OPT_ARGUMENT_OPTIONAL = CACAO_MAIN_OPT_ARGUMENT_OPTIONAL
};

} // namespace console

namespace app {
namespace console {

typedef cacao::console::main_opt_argument_t main_opt_argument_t;
enum {
    MAIN_OPT_ARGUMENT_NONE     = cacao::console::MAIN_OPT_ARGUMENT_NONE,
    MAIN_OPT_ARGUMENT_REQUIRED = cacao::console::MAIN_OPT_ARGUMENT_REQUIRED,
    MAIN_OPT_ARGUMENT_OPTIONAL = cacao::console::MAIN_OPT_ARGUMENT_OPTIONAL
};

} // namespace console
} // namespace app

} // namespace cacao

#endif // _CACAO_CONSOLE_MAIN_OPT_HH 
