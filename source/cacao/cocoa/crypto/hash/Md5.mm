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
///   File: Md5.mm
///
/// Author: $author$
///   Date: 9/3/2016
///////////////////////////////////////////////////////////////////////
#include "cacao/cocoa/crypto/hash/Md5.hh"
#include "talas/crypto/hash/openssl/md5.cpp"

namespace cacao {
namespace cocoa {
namespace crypto {
namespace hash {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
Implement& Implement::TheDerived() {
    static Md5 md5;
    return md5;
}

} // namespace hash 
} // namespace crypto 
} // namespace cocoa 
} // namespace cacao 
