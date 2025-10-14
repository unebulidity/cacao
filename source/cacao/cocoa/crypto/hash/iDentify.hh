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
///   File: iDentify.hh
///
/// Author: $author$
///   Date: 9/23/2025
///////////////////////////////////////////////////////////////////////
#ifndef CACAO_COCOA_CRYPTO_HASH_IDENTIFY_HH
#define CACAO_COCOA_CRYPTO_HASH_IDENTIFY_HH

#include "cacao/cocoa/crypto/hash/Derived.hh"
#include "xos/network/os/sockets.hpp"
#include "xos/network/os/socket.hpp"
#include "xos/network/ip/v6/udp/transport.hpp"
#include "xos/network/ip/v6/tcp/transport.hpp"
#include "xos/network/ip/v6/endpoint.hpp"
#include "xos/network/ip/v4/udp/transport.hpp"
#include "xos/network/ip/v4/tcp/transport.hpp"
#include "xos/network/ip/v4/endpoint.hpp"
#include "xos/network/local/stream/transport.hpp"
#include "xos/network/local/dgram/transport.hpp"
#include "xos/network/local/endpoint.hpp"

#define XOS_APP_CONSOLE_IDENTIFY_PORTNO 8484
#define XOS_APP_CONSOLE_IDENTIFY_PORT XOS_BASE_2STRING(XOS_APP_CONSOLE_IDENTIFY_PORTNO)
#define XOS_APP_CONSOLE_IDENTIFY_HOST "identify"

namespace cacao {
namespace cocoa {
namespace crypto {
namespace hash {

///////////////////////////////////////////////////////////////////////
/// class iDentify
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS iDentify: virtual public Derived::Implements, public Derived {
public:
    typedef Derived::Implements Implements;
    typedef Derived Extends;
    typedef iDentify Derives;

    ///////////////////////////////////////////////////////////////////////
    /// constructor / destructor
    ///////////////////////////////////////////////////////////////////////
    iDentify()
    : run_(0),
      send_(&Derives::client_tcp_send),
      ep_(&Derives::ip_v4_ep),
      tp_(&Derives::ip_v4_tcp_tp),
      portno_(XOS_APP_CONSOLE_IDENTIFY_PORTNO),
      port_(XOS_APP_CONSOLE_IDENTIFY_PORT),
      host_(XOS_APP_CONSOLE_IDENTIFY_HOST) {
    }
    virtual ~iDentify() {
    }
private:
    iDentify(const iDentify& copy) {
    }
public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    typedef Extends::string_t string_t;
    typedef Extends::char_t char_t;
    typedef int (Derives::*run_t)(string &target, const string &source);
    typedef int (Derives::*send_t)(xos::network::socket& s, xos::network::endpoint& ep, const char_t* chars, size_t length);
    typedef int (Derives::*listen_t)(xos::network::socket& s, xos::network::endpoint& ep);
    typedef xos::network::endpoint* (Derives::*endpoint_t)();
    typedef xos::network::transport* (Derives::*transport_t)();
    typedef xos::network::endpoint_exception_t endpoint_exception_t;

protected:
    //////////////////////////////////////////////////////////////////////////
    /// ...Accept
    virtual int Accept(string &target, const string &source) {
        int err = 0;
        return err;
    }
    virtual int before_Accept(string &target, const string &source) {
        int err = 0;
        return err;
    }
    virtual int after_Accept(string &target, const string &source) {
        int err = 0;
        return err;
    }
    virtual int all_Accept(string &target, const string &source) {
        int err = 0;
        if (!(err = before_Accept(target, source))) {
            int err2 = 0;
            err = Accept(target, source);
            if ((err2 = after_Accept(target, source))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...Connect
    virtual int Connect(string &target, const string &source) {
        int err = 0;
        send_t send = 0;

        LOG_DEBUG("((send = (this->send_)))...");
        if ((send = (this->send_))) {
            string message(source);

            LOG_DEBUG("(!(err = before_Send(message, \"" << source << "\")))...");
            if (!(err = before_Send(message, source))) {
                const char* chars = 0;
                size_t length = 0;

                LOG_DEBUG("((chars = message.has_chars(length)))...");
                if ((chars = message.has_chars(length))) {
                    xos::network::endpoint* ep = 0;
        
                    LOG_DEBUG("((ep_) && (ep = ((this->*ep_)())))...");
                    if ((ep_) && (ep = ((this->*ep_)()))) {
                        xos::network::transport* tp = 0;
        
                        LOG_DEBUG("((tp_) && (tp = (this->*tp_)()))...");
                        if ((tp_) && (tp = (this->*tp_)())) {
                            xos::network::os::socket s;
        
                            LOG_DEBUG("if ((s.open(*tp)))...");
                            if ((s.open(*tp))) {

                                LOG_DEBUG("(this->*send)(s, *ep, chars, length)...");
                                (this->*send)(s, *ep, chars, length);
                                LOG_DEBUG("s.close()...");
                                s.close();
                            }
                            LOG_DEBUG("delete tp...");
                            delete tp;
                        }
                        LOG_DEBUG("delete ep...");
                        delete ep;
                    }
                } else {}
            } else {}
        } else {}        
        return err;
    }
    virtual int before_Connect(string &target, const string &source) {
        int err = 0;
        LOG_DEBUG("((xos::network::os::sockets::startup()))...");
        if ((xos::network::os::sockets::startup())) {} else {}
        return err;
    }
    virtual int after_Connect(string &target, const string &source) {
        int err = 0;
        LOG_DEBUG("((xos::network::os::sockets::cleanup()))...");
        if ((xos::network::os::sockets::cleanup())) {} else {}
        return err;
    }
    virtual int all_Connect(string &target, const string &source) {
        int err = 0;
        if (!(err = before_Connect(target, source))) {
            int err2 = 0;
            err = Connect(target, source);
            if ((err2 = after_Connect(target, source))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...Send
    virtual int Send(string &message, const string &source) {
        int err = 0;
        return err;
    }
    virtual int before_Send(string &message, const string &source) {
        int err = 0;
        const char_t cr = ((char_t)'\r'), lf = ((char_t)'\n');
        const char* chars = 0;
        size_t length = 0;

        LOG_DEBUG("((chars = source.has_chars(length)))...");
        if ((chars = source.has_chars(length))) {

            LOG_DEBUG("for (size_t index = " << length << "; index; --index) {...");
            for (size_t index = length; index; --index) {
                if ((lf != chars[index - 1])) {

                    LOG_DEBUG("((index = " << index << " < length = " << length << "))...");
                    if ((index < length)) {

                        LOG_DEBUG("message.assign(\"" << chars << "\", " << index << ")...");
                        message.assign(chars, index);
                    } else {}
                    break;
                }
            }
        }
        message.append(&cr,1);
        message.append(&lf,1);
        return err;
    }
    virtual int after_Send(string &message, const string &source) {
        int err = 0;
        return err;
    }
    virtual int all_Send(string &message, const string &source) {
        int err = 0;
        if (!(err = before_Send(message, source))) {
            int err2 = 0;
            err = Send(message, source);
            if ((err2 = after_Send(message, source))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int client_tcp_send
    (xos::network::socket& s, xos::network::endpoint& ep, const char_t* chars, size_t length) {

        LOG_DEBUG("s.connect()...");
        if ((s.connect(ep))) {
            ssize_t count;

            LOG_DEBUG("sending \"" << chars << "\"...");
            if (0 < (count = s.send(chars, length, 0))) {

                LOG_DEBUG("...sent \"" << chars << "\"");
                do {

                    LOG_DEBUG("recv[" << sizeof(chars_) << "]...");
                    if (0 < (count = s.recv(chars_, sizeof(chars_), 0))) {

                        LOG_DEBUG("...recv[" << count << "]");
                        TransformedTo(chars_, count);
                        continue;
                    } else {
                        LOG_DEBUG("...failed with recv[" << count << "]");
                    }
                    break;
                } while (0 < count);
            } else {
                LOG_ERROR("... failed to send \"" << chars << "\"");
            }
        } else {
            LOG_DEBUG("...failed on s.connect()");
        }
        return 0;
    }
    virtual int client_udp_send
    (xos::network::socket& s, xos::network::endpoint& ep, const char_t* chars, size_t length) {
        ssize_t count;

        LOG_DEBUG("sending \"" << chars << "\"...");
        if (0 < (count = s.sendto(chars, length, 0, ep))) {

            LOG_DEBUG("...sent \"" << chars << "\"");
        } else {
            LOG_ERROR("... failed to send \"" << chars << "\"");
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual xos::network::transport* ip_v4_tcp_tp() {
        xos::network::transport* tp = new xos::network::ip::v4::tcp::transport();
        return tp;
    }
    virtual xos::network::transport* ip_v4_udp_tp() {
        xos::network::transport* tp = new xos::network::ip::v4::udp::transport();
        return tp;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual xos::network::transport* ip_v6_tcp_tp() {
        xos::network::transport* tp = new xos::network::ip::v6::tcp::transport();
        return tp;
    }
    virtual xos::network::transport* ip_v6_udp_tp() {
        xos::network::transport* tp = new xos::network::ip::v6::udp::transport();
        return tp;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual xos::network::endpoint* ip_v4_ep() {
        const char_t* host;
        ushort port;
        try {
            if ((run_ != &Derives::Accept)) {
                if ((host = host_.has_chars()) && (0 < (port = portno_))) {
                    xos::network::endpoint* ep = new xos::network::ip::v4::endpoint(host, port);
                    return ep;
                }
            } else {
                if ((0 < (port = portno_))) {
                    xos::network::endpoint* ep = new xos::network::ip::v4::endpoint(port);
                    return ep;
                }
            }
        } catch(endpoint_exception_t){
            return 0;
        }
        return 0;
    }
    virtual xos::network::endpoint* ip_v6_ep() {
        const char_t* host;
        ushort port;
        try {
            if ((run_ != &Derives::Accept)) {
                if ((host = host_.has_chars()) && (0 < (port = portno_))) {
                    xos::network::endpoint* ep = new xos::network::ip::v6::endpoint(host, port);
                    return ep;
                }
            } else {
                if ((0 < (port = portno_))) {
                    xos::network::endpoint* ep = new xos::network::ip::v6::endpoint(port);
                    return ep;
                }
            }
        } catch(endpoint_exception_t){
            return 0;
        }
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void set_host(const char_t* to) {
        host_.assign(to);
    }
    virtual void set_port(const char_t* to) {
        std::stringstream ss(to);
        int no;
        ss >> no;
        if (0 < (no)) {
            portno_ = no;
            port_.assign(to);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void set_transport_tcp() {
        send_ = &Derives::client_tcp_send;
        ///listen_ = &Derives::server_tcp_listen;
        if ((&Derives::ip_v4_ep == ep_)) {
            tp_ = &Derives::ip_v4_tcp_tp;
        } else {
            if ((&Derives::ip_v6_ep == ep_)) {
                tp_ = &Derives::ip_v6_tcp_tp;
            } else {
            }
        }
    }
    virtual void set_transport_udp() {
        send_ = &Derives::client_udp_send;
        ///listen_ = &Derives::server_udp_listen;
        if ((&Derives::ip_v4_ep == ep_)) {
            tp_ = &Derives::ip_v4_udp_tp;
        } else {
            if ((&Derives::ip_v6_ep == ep_)) {
                tp_ = &Derives::ip_v6_udp_tp;
            } else {
            }
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void set_family_ip_v4() {
        ep_ = &Derives::ip_v4_ep;
        if ((is_stream_tp())) {
            tp_ = &Derives::ip_v4_tcp_tp;
        } else {
            if ((is_dgram_tp())) {
                tp_ = &Derives::ip_v4_udp_tp;
            } else {
            }
        }
    }
    virtual void set_family_ip_v6() {
        ep_ = &Derives::ip_v6_ep;
        if ((is_stream_tp())) {
            tp_ = &Derives::ip_v6_tcp_tp;
        } else {
            if ((is_dgram_tp())) {
                tp_ = &Derives::ip_v6_udp_tp;
            } else {
            }
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool is_stream_tp() const {
        if ((&Derives::ip_v4_tcp_tp == tp_)
            || (&Derives::ip_v6_tcp_tp == tp_)
            /*|| (&Derives::local_stream_tp == tp_)*/) {
            return true;
        }
        return false;
    }
    virtual bool is_dgram_tp() const {
        if ((&Derives::ip_v4_udp_tp == tp_)
            || (&Derives::ip_v6_udp_tp == tp_)
            /*|| (&Derives::local_dgram_tp == tp_)*/) {
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual size_t Transform(string &target, const string &source) {
        size_t length = 0;
        if ((0 < (length = Extends::Transform(target, source)))) {
            int err = 0;
            if (!(err = all_Connect(target, source))) {} else {}
        } else {}
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    run_t run_;
    send_t send_;
    listen_t listen_;
    endpoint_t ep_;
    transport_t tp_;
    ushort portno_;
    string_t port_, host_;
    char_t chars_[4096];
}; /// class iDentify

} /// namespace hash 
} /// namespace crypto 
} /// namespace cocoa 
} /// namespace cacao 

#endif /// ndef CACAO_COCOA_CRYPTO_HASH_IDENTIFY_HH
