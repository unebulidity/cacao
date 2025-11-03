///////////////////////////////////////////////////////////////////////
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
///   File: iDentify.mm
///
/// Author: $author$
///   Date: 9/23/2025
///////////////////////////////////////////////////////////////////////
#include "cacao/cocoa/crypto/hash/iDentify.hh"
//#include "cacao/cocoa/crypto/hash/derived/Sha256.hh"
#include "cacao/cocoa/crypto/hash/Sha256.hh"
#include "talas/crypto/hash/openssl/sha256.cpp"

namespace cacao {
namespace cocoa {
namespace crypto {
namespace hash {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
Implement& Implement::TheDerived() {
    static iDentify the_Derived;
    return the_Derived;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
Implement& Implement::TheFileDerived() {
    //static derived::Sha256 the_FileDerived;
    static Sha256 the_FileDerived;
    return the_FileDerived;
}

} /// namespace hash 
} /// namespace crypto 
} /// namespace cocoa 
} /// namespace cacao 
