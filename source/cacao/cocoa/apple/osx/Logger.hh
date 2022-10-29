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
///   File: Logger.hh
///
/// Author: $author$
///   Date: 8/29/2016
///////////////////////////////////////////////////////////////////////
#ifndef _CACAO_COCOA_APPLE_OSX_LOGGER_HH
#define _CACAO_COCOA_APPLE_OSX_LOGGER_HH

#include "cacao/cocoa/apple/osx/Cocoa.hh"
#include "cacao/io/logger.hh"

#if !defined(USE_NADIR_BASE)
#include "xos/io/logger.hpp"
#include "xos/mt/locker.hpp"
#include "xos/mt/lock.hpp"
#include "xos/mt/os/mutex.hpp"
#include <iostream>

#define CACAO_COCOA_APPLE_OSX_LOGGER_LEVELS_TRACE \
    (XOS_LOGGING_LEVELS_TRACE_MESSAGE | XOS_LOGGING_LEVELS_ERROR)

#define CACAO_COCOA_APPLE_OSX_LOGGER_LEVELS_DEBUG \
    (XOS_LOGGING_LEVELS_DEBUG_MESSAGE | XOS_LOGGING_LEVELS_ERROR)

#define CACAO_COCOA_APPLE_OSX_LOGGER_LEVELS_ERROR \
    (XOS_LOGGING_LEVELS_ERROR_MESSAGE | XOS_LOGGING_LEVELS_ERROR)

#define CACAO_COCOA_APPLE_OSX_LOGGER_LEVELS \
    CACAO_COCOA_APPLE_OSX_LOGGER_LEVELS_DEBUG

#if !defined(RELEASE_BUILD)
#define LOG_TRACE(args) CACAO_LOG_MESSAGE_TRACE(__FUNCTION__ << ": " << args)
#define LOG_DEBUG(args) CACAO_LOG_MESSAGE_DEBUG(__FUNCTION__ << ": " << args)
#else // !defined(RELEASE_BUILD)
#define LOG_TRACE(args)
#define LOG_DEBUG(args)
#endif // !defined(RELEASE_BUILD)

#define LOG_ERROR(args) CACAO_LOG_MESSAGE_ERROR(__FUNCTION__ << ": " << args)
#define LOGGER_INIT XOS_LOGGER_INIT
#define LOGGER_FINI XOS_LOGGER_FINI

#if !defined(STDERR_LOG)
#define STDERR_LOG(__message__) \
    std::cerr << __FILE__ << "[" << __LINE__ << "] " << __FUNCTION__ << " " << __message__ << "\n"
#endif // !defined(STDERR_LOG)

#if !defined(STDERR_LOG_DEBUG)
#if defined(DEBUG_BUILD)
#define STDERR_LOG_DEBUG(__message__) STDERR_LOG(__message__)
#else // defined(DEBUG_BUILD)
#define STDERR_LOG_DEBUG(__message__)
#endif // defined(DEBUG_BUILD)
#endif // !defined(STDERR_LOG_DEBUG)

#if !defined(STDERR_LOG_ERROR)
#define STDERR_LOG_ERROR(__message__) STDERR_LOG(__message__)
#endif // !defined(STDERR_LOG_ERROR)
#else // !defined(USE_NADIR_BASE)
#include "nadir/console/main_logger.hpp"
#include "nadir/console/main.hpp"
#include "nadir/mt/os/mutex.hpp"
#include "nadir/io/logger.hpp"
#endif // !defined(USE_NADIR_BASE)

namespace cacao {
namespace cocoa {
namespace apple {
namespace osx {

#if !defined(USE_NADIR_BASE)
typedef xos::mt::locker main_implements;
typedef xos::mt::os::mutex main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main
: virtual public main_implements, public main_extends {
public:
    typedef main_implements Implements;
    typedef main_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main(): Extends(false) {
    }
    virtual ~main() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t logfv(const char* format, va_list va) {
        ssize_t count = errfv(format, va);
        return count;
    }
    virtual ssize_t log(const char* out, ssize_t length = -1) {
        ssize_t count = err(out, length);
        return count;
    }
    virtual ssize_t logln() {
        ssize_t count = errln();
        err_flush();
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t errfv(const char* format, va_list va) {
        ssize_t count = this->outfv(this->std_err(), format, va);
        return count;
    }
    virtual ssize_t errln() {
        ssize_t count = this->outln(this->std_err());
        return count;
    }
    virtual ssize_t err(const char* out, ssize_t length = -1) {
        ssize_t count = this->out(this->std_err(), out, length);
        return count;
    }
    virtual ssize_t err_flush() {
        ssize_t count = this->out_flush(this->std_err());
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t outfv(FILE* f, const char* format, va_list va) {
        ssize_t count = 0;
        return count;
    }
    virtual ssize_t outln(FILE* f) {
        const char ln = ((char)'\n');
        ssize_t count = this->out(f, &ln, 1);
        return count;
    }
    virtual ssize_t out(FILE* f, const char* out, ssize_t length = -1) {
        ssize_t count = 0;
        if ((out) && (f)) {
            ssize_t amount;
            if (0 <= (length)) {
                if (0 < (amount = fwrite(out, sizeof(char), length, f)))
                    count += amount;
            } else {
                for (; *out; ++out) {
                    if (0 < (amount = fwrite(out, sizeof(char), 1, f)))
                        count += amount;
                }
            }
        }
        return count;
    }
    virtual ssize_t out_flush(FILE* f) {
        ssize_t count = 0;
        if ((f)) {
            fflush(f);
        }
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual FILE* std_err() const {
        return stderr;
    }
};

typedef xos::io::logger logger_implements;
typedef xos::base::base logger_extends;
///////////////////////////////////////////////////////////////////////
///  Class: logger
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS logger
: virtual public logger_implements, public logger_extends {
public:
    typedef logger_implements Implements;
    typedef logger_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    logger(level enabled_for = CACAO_COCOA_APPLE_OSX_LOGGER_LEVELS)
    : logger_(Implements::get_default()),
      enabled_for_(enabled_for) {
        Implements::set_default(this);
    }
    virtual ~logger() {
        if (this == (Implements::get_default())) {
            Implements::set_default(logger_);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void log
    (const level& _level, const location& _location, const message& _message) {
        xos::mt::lock lk(main_);
        if ((this->is_enabled_for(_level))) {
            this->log(_location);
            main_.log(_message.c_str());
            main_.logln();
        }
    }
    virtual void logf
    (const level& _level, const location& _location, const char* format, ...) {
        xos::mt::lock lk(main_);
        if ((this->is_enabled_for(_level))) {
            this->log(_location);
            if ((format)) {
                va_list va;
                va_start(va, format);
                main_.logfv(format, va);
                va_end(va);
            }
            main_.logln();
        }
    }
    virtual void logfv
    (const level& _level, const location& _location, const char* format, va_list va) {
        xos::mt::lock lk(main_);
        if ((this->is_enabled_for(_level))) {
            this->log(_location);
            if ((format)) {
                main_.logfv(format, va);
            }
            main_.logln();
        }
    }
    virtual void logfv
    (const level& _level, const location& _location,
     const message& _message, const char* format, va_list va) {
        xos::mt::lock lk(main_);
        if ((this->is_enabled_for(_level))) {
            this->log(_location);
            main_.log(_message.c_str());
            if ((format)) {
                main_.logfv(format, va);
            }
            main_.logln();
        }
    }
    ///////////////////////////////////////////////////////////////////////
    virtual void log
    (const level& _level, const message& _message) {
        xos::mt::lock lk(main_);
        if ((this->is_enabled_for(_level))) {
            main_.log(_message.c_str());
            main_.logln();
        }
    }
    virtual void logf
    (const level& _level, const char* format, ...) {
        xos::mt::lock lk(main_);
        if ((this->is_enabled_for(_level))) {
            if ((format)) {
                va_list va;
                va_start(va, format);
                main_.logfv(format, va);
                va_end(va);
            }
            main_.logln();
        }
    }
    virtual void logfv
    (const level& _level, const char* format, va_list va) {
        xos::mt::lock lk(main_);
        if ((this->is_enabled_for(_level))) {
            if ((format)) {
                main_.logfv(format, va);
            }
            main_.logln();
        }
    }
    virtual void logfv
    (const level& _level, const message& _message, const char* format, va_list va) {
        xos::mt::lock lk(main_);
        if ((this->is_enabled_for(_level))) {
            main_.log(_message.c_str());
            if ((format)) {
                main_.logfv(format, va);
            }
            main_.logln();
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void enable_for(const level& _level) {
        enabled_for_ = _level;
    }
    virtual level enabled_for() const {
        return enabled_for_;
    }
    virtual bool is_enabled_for(const level& _level) const {
        level::enable enabled_for = enabled_for_;
        level::enable enabled = _level;
        return ((enabled_for & enabled) == enabled);
    }
protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void log(const location& _location) {
        main_.log(_location.get_file_name().c_str());
        main_.log("[");
        main_.log(_location.get_line_number().c_str());
        main_.log("]");
        main_.log(" ");
        main_.log(_location.get_function_name().c_str());
        main_.log(" ");
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    main main_;
    Implements* logger_;
    level enabled_for_;
};
#else // !defined(USE_NADIR_BASE)
typedef nadir::base logger_extends;
///////////////////////////////////////////////////////////////////////
///  Class: logger
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS logger: public logger_extends {
public:
    typedef logger_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    logger(): mutex_(false), main_logger_(mutex_, main_) {}
    virtual ~logger() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    nadir::mt::os::mutex mutex_;
    nadir::console::main main_;
    nadir::console::main_logger main_logger_;
};
#endif // !defined(USE_NADIR_BASE)

} // namespace osx
} // namespace apple 
} // namespace cocoa 
} // namespace cacao 

#endif // _CACAO_COCOA_APPLE_OSX_LOGGER_HH 
