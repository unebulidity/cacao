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
///   File: Sha256.hh
///
/// Author: $author$
///   Date: 11/2/2025
//////////////////////////////////////////////////////////////////////////
#ifndef CACAO_COCOA_CRYPTO_HASH_DERIVED_SHA256_HH
#define CACAO_COCOA_CRYPTO_HASH_DERIVED_SHA256_HH

#include "cacao/cocoa/apple/osx/Logger.hh"
#include "cacao/cocoa/crypto/hash/Sha256.hh"
#include "talas/crypto/hash/derived.hpp"

namespace cacao {
namespace cocoa {
namespace crypto {
namespace hash {
namespace derived {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Sha256: virtual public Implement, public Base {
public:
    typedef Implement Implements;
    typedef Base Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Sha256(): m_implement(*this), m_derived(m_implement, true) {
    }
    virtual ~Sha256() {
    }
protected:
    ///////////////////////////////////////////////////////////////////////
    /// class implement
    ///////////////////////////////////////////////////////////////////////
    class _EXPORT_CLASS implement: virtual public talas::crypto::hash::derived::implement {
    public:
        typedef talas::crypto::hash::derived::implement Implements;
        typedef implement Derives;
    
        ///////////////////////////////////////////////////////////////////////
        /// constructor / destructor
        ///////////////////////////////////////////////////////////////////////
        implement(Sha256 &derived): m_derived(derived) {
        }
        virtual ~implement() {
        }
    private:
        implement(const implement& copy): m_derived(copy.m_derived) {
        }
    public:
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        virtual void initial() {
            m_derived.initial();
        }
        virtual void final() {
            m_derived.final();
        }
        virtual void transform() {
            m_derived.transform();
        }
        virtual void update(const uint8_t* in, size_t inlen) {
            m_derived.update(in, inlen);
        }
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
    protected:
        Sha256 &m_derived;
    }; /// class implement
    //////////////////////////////////////////////////////////////////////////
    /// class implementation
    class exported implementation: public talas::crypto::hash::openssl::sha256 {
    public:
        typedef talas::crypto::hash::openssl::sha256 extends;
        typedef implementation derives;
    
        //////////////////////////////////////////////////////////////////////////
        /// constructor / destructor
        implementation(const implementation &copy): extends(copy) {
        }
        implementation() {
        }
        virtual ~implementation() {
        }
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        virtual bool encoded() const {
            return true;
        }
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        virtual void initial() {
            extends::initial();
        }
        virtual void final() {
            extends::final();
        }
        virtual void transform() {
            extends::transform();
        }
        virtual void update(const uint8_t* in, size_t inlen) {
            extends::update(in, inlen);
        }
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
    
        //////////////////////////////////////////////////////////////////////////
    protected:
    }; /// class implementation
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool encoded() const {
        return true;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void initial() {
        m_implementation.initial();
    }
    virtual void final() {
        m_implementation.final();
    }
    virtual void transform() {
        m_implementation.transform();
    }
    virtual void update(const uint8_t* in, size_t inlen) {
        m_implementation.update(in, inlen);
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual talas::crypto::hash::base_implements& Implemented() const {
        return (talas::crypto::hash::base_implements&)m_derived;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    implement m_implement;
    implementation m_implementation;
    talas::crypto::hash::derived m_derived;
};

} /// namespace derived 
} /// namespace hash 
} /// namespace crypto 
} /// namespace cocoa 
} /// namespace cacao 

#endif /// ndef CACAO_COCOA_CRYPTO_HASH_DERIVED_SHA256_HH

