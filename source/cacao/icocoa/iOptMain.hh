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
///   File: iOptMain.hh
///
/// Author: $author$
///   Date: 7/10/2016
///////////////////////////////////////////////////////////////////////
#ifndef _CACAO_ICOCOA_IOPTMAIN_HH
#define _CACAO_ICOCOA_IOPTMAIN_HH

#include "cacao/icocoa/iMain.hh"
#include "cacao/icocoa/iOpt.hh"
#include "cacao/gui/main.hh"

///////////////////////////////////////////////////////////////////////
/// Interface: iOptMain
///////////////////////////////////////////////////////////////////////
@interface iOptMain: iMain {
    }
    @property cacao::gui::main* main;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (id)init:(cacao::gui::main*)main;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    - (int)usage:(int)argc argv:(char**)argv env:(char**)env;
    - (int)onOption:(int)optval optarg:(const char*)optarg optname:(const char*)optname optind:(int)optind argc:(int)argc argv:(char**)argv env:(char**)env;
    - (int)onArgument:(const char*)arg argind:(int)argind argc:(int)argc argv:(char**)argv env:(char**)env;
    - (const char*)optionUsage:(const char*&)optarg longopt:(const struct option*)longopt;
    - (const char*)options:(const struct option*&)longopts;
    - (const char*)arguments:(const char**&)args;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    + (id<iMain>)create:(cacao::gui::main*)main;
@end

namespace cacao {
namespace icocoa {

} // namespace icocoa 
} // namespace cacao 

#endif // _CACAO_ICOCOA_IOPTMAIN_HH 
