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
///   File: Derived.hh
///
/// Author: $author$
///   Date: 9/22/2025
//////////////////////////////////////////////////////////////////////////
#ifndef CACAO_COCOA_CRYPTO_HASH_DERIVED_HH
#define CACAO_COCOA_CRYPTO_HASH_DERIVED_HH

#include "cacao/cocoa/apple/osx/Logger.hh"
#include "cacao/cocoa/crypto/hash/Base.hh"
#include "talas/crypto/hash/derived.hpp"

namespace cacao {
namespace cocoa {
namespace crypto {
namespace hash {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Derived: virtual public Implement, public Base {
public:
    typedef Implement Implements;
    typedef Base Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Derived(): m_implement(*this), m_derived(m_implement) {
    }
    virtual ~Derived() {
    }
protected:
    typedef string string_t;
    typedef string::char_t char_t;
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
        implement(Derived &derived): m_derived(derived) {
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
            LOG_DEBUG("...initial()");
            LOG_DEBUG("m_source.clear()...");
            m_source.clear();
            LOG_DEBUG("initial()...");
        }
        virtual void final() {
            LOG_DEBUG("...final()");
            LOG_DEBUG("transform()...");
            transform();
            LOG_DEBUG("m_source.clear()...");
            m_source.clear();
            LOG_DEBUG("final()...");
        }
        virtual void transform() {
            size_t length = 0;
            const char* chars = 0;
            const uint8_t* in = 0;
            LOG_DEBUG("...transform()");
            LOG_DEBUG("((0 < (length = m_derived.Transform(m_target, \"" << m_source << "\"))))...");
            if ((0 < (length = m_derived.Transform(m_target, m_source)))) {
                LOG_DEBUG("((0 != (in = (const uint8_t*)(chars = m_target.has_chars(length)))))...");
                if ((0 != (in = (const uint8_t*)(chars = m_target.has_chars(length))))) {
                    LOG_DEBUG("this->assign(m_derived.m_derived, \"" << chars << "\", " << length << ")...");
                    this->assign(m_derived.m_derived, in, length);
                } else {}
            } else {}
            LOG_DEBUG("transform()...");
        }
        virtual void update(const uint8_t* in, size_t inlen) {
            const char* inchars = 0;
            LOG_DEBUG("...update(in, inlen = " << inlen << ")");
            if ((0 != (inchars = (const char*)(in))) && (0 < (inlen))) {
                LOG_DEBUG("m_source.append(in = \"" << inchars << "\", inlen = " << inlen << ")...");
                m_source.append(inchars, inlen);
            } else {}
            LOG_DEBUG("update(in, inlen = " << inlen << ")...");
        }
        virtual string& set_target(const char_t *to, size_t length) {
            if ((0 != (to)) && (0 < (length))) {
                m_target.assign(to, length);
            } else {}
            return m_target;
        }
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
    protected:
        Derived &m_derived;
        string m_target, m_source;
    }; /// class implement
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual size_t Transform(string &target, const string &source) {
        size_t length = 0;
        LOG_DEBUG("target.assign(\"" << source << "\")...");
        target.assign(source);
        LOG_DEBUG("length = target.length()...");
        length = target.length();
        LOG_DEBUG("return length = " << length << "...");
        return length;
    }
    virtual size_t TransformedTo(const char_t *chars, size_t length) {
        if ((0 != (chars)) && (0 < (length))) {
            m_implement.set_target(chars, length);
        } else {}
        return length;
    }
    virtual talas::crypto::hash::base_implements& Implemented() const {
        return (talas::crypto::hash::base_implements&)m_derived;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    implement m_implement;
    talas::crypto::hash::derived m_derived;
};

} /// namespace hash 
} /// namespace crypto 
} /// namespace cocoa 
} /// namespace cacao 

#endif /// ndef CACAO_COCOA_CRYPTO_HASH_DERIVED_HH
