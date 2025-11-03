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
///   File: Derived.mm
///
/// Author: $author$
///   Date: 9/22/2025, 11/2/2025
//////////////////////////////////////////////////////////////////////////
#include "cacao/cocoa/crypto/hash/Derived.hh"
#include "talas/crypto/hash/derived.cpp"

namespace cacao {
namespace cocoa {
namespace crypto {
namespace hash {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
Implement& Implement::TheDerived() {
    static Derived the_Derived;
    return the_Derived;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
Implement& Implement::TheFileDerived() {
    static Derived the_FileDerived;
    return the_FileDerived;
}

} /// namespace hash 
} /// namespace crypto 
} /// namespace cocoa 
} /// namespace cacao 
