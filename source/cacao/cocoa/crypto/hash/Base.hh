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
///   File: Base.hh
///
/// Author: $author$
///   Date: 9/2/2016
///////////////////////////////////////////////////////////////////////
#ifndef _CACAO_COCOA_CRYPTO_HASH_BASE_HH
#define _CACAO_COCOA_CRYPTO_HASH_BASE_HH

#include "cacao/cocoa/base/Base.hh"
#include "talas/crypto/hash/base.hpp"

namespace cacao {
namespace cocoa {
namespace crypto {

typedef talas::crypto::implement_baset
<cocoa::ImplementBase> ImplementBase;

typedef talas::crypto::baset
<cocoa::crypto::ImplementBase> Base;

namespace hash {

typedef talas::crypto::hash::base_implementt
<cocoa::crypto::ImplementBase> ImplementBase;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Implement: virtual public ImplementBase {
public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static Implement& TheDerived();
};

typedef crypto::Base Extend;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Base: virtual public Implement, public Extend {
public:
    typedef Implement Implements;
    typedef Extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Base() {
    }
    virtual ~Base() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t initialize(const void* key, size_t keylen) {
        return Implemented().initialize(key, keylen);
    }
    virtual ssize_t finalize(void* out, size_t outsize) {
        return Implemented().finalize(out, outsize);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t hash(const void* in, size_t inlen) {
        return Implemented().hash(in, inlen);
    }
    virtual ssize_t hash_size() const {
        return Implemented().hash_size();
    }
    virtual const char* name() const {
        return Implemented().name();
    }
protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual talas::crypto::hash::base_implements& Implemented() const = 0;
};

} // namespace hash
} // namespace crypto 
} // namespace cocoa 
} // namespace cacao 

#endif // _CACAO_COCOA_CRYPTO_HASH_BASE_HH 
