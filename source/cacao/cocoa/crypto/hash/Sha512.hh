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
///   File: Sha512.hh
///
/// Author: $author$
///   Date: 9/6/2016
///////////////////////////////////////////////////////////////////////
#ifndef _CACAO_COCOA_CRYPTO_HASH_SHA512_HH
#define _CACAO_COCOA_CRYPTO_HASH_SHA512_HH

#include "cacao/cocoa/crypto/hash/Base.hh"
#include "talas/crypto/hash/openssl/sha512.cpp"

namespace cacao {
namespace cocoa {
namespace crypto {
namespace hash {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Sha512: virtual public Implement, public Base {
public:
    typedef Implement Implements;
    typedef Base Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Sha512() {
    }
    virtual ~Sha512() {
    }
protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual talas::crypto::hash::base_implements& Implemented() const {
        return (talas::crypto::hash::base_implements&)m_sha512;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    talas::crypto::hash::openssl::sha512 m_sha512;
};

} // namespace hash
} // namespace crypto 
} // namespace cocoa 
} // namespace cacao 

#endif // _CACAO_COCOA_CRYPTO_HASH_SHA512_HH 
