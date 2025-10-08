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
///   File: logger.hh
///
/// Author: $author$
///   Date: 7/10/2016
///////////////////////////////////////////////////////////////////////
#ifndef _CACAO_IO_LOGGER_HH
#define _CACAO_IO_LOGGER_HH

#include "cacao/base/base.hh"

#if !defined(USE_NADIR_BASE)
#include "xos/io/logger.hpp"

#define CACAO_LOG_ANY XOS_LOG_ANY
#define CACAO_LOG_FATAL XOS_LOG_FATAL
#define CACAO_LOG_ERROR XOS_LOG_ERROR
#define CACAO_LOG_WARN XOS_LOG_WARN
#define CACAO_LOG_INFO XOS_LOG_INFO
#define CACAO_LOG_DEBUG XOS_LOG_DEBUG
#define CACAO_LOG_TRACE XOS_LOG_TRACE

#define CACAO_LOG_ANYF XOS_LOG_ANYF
#define CACAO_LOG_FATALF XOS_LOG_FATALF
#define CACAO_LOG_ERRORF XOS_LOG_ERRORF
#define CACAO_LOG_WARNF XOS_LOG_WARNF
#define CACAO_LOG_INFOF XOS_LOG_INFOF
#define CACAO_LOG_DEBUGF XOS_LOG_DEBUGF
#define CACAO_LOG_TRACEF XOS_LOG_TRACEF

#define CACAO_LOG_MESSAGE_ANY XOS_LOG_MESSAGE_ANY
#define CACAO_LOG_MESSAGE_FATAL XOS_LOG_MESSAGE_FATAL
#define CACAO_LOG_MESSAGE_ERROR XOS_LOG_MESSAGE_ERROR
#define CACAO_LOG_MESSAGE_WARN XOS_LOG_MESSAGE_WARN
#define CACAO_LOG_MESSAGE_INFO XOS_LOG_MESSAGE_INFO
#define CACAO_LOG_MESSAGE_DEBUG XOS_LOG_MESSAGE_DEBUG
#define CACAO_LOG_MESSAGE_TRACE XOS_LOG_MESSAGE_TRACE

#define CACAO_LOG_MESSAGE_ANYF XOS_LOG_MESSAGE_ANYF
#define CACAO_LOG_MESSAGE_FATALF XOS_LOG_MESSAGE_FATALF
#define CACAO_LOG_MESSAGE_ERRORF XOS_LOG_MESSAGE_ERRORF
#define CACAO_LOG_MESSAGE_WARNF XOS_LOG_MESSAGE_WARNF
#define CACAO_LOG_MESSAGE_INFOF XOS_LOG_MESSAGE_INFOF
#define CACAO_LOG_MESSAGE_DEBUGF XOS_LOG_MESSAGE_DEBUGF
#define CACAO_LOG_MESSAGE_TRACEF XOS_LOG_MESSAGE_TRACEF

#define CACAO_LOG_MESSAGE_ANYFV XOS_LOG_MESSAGE_ANYFV
#define CACAO_LOG_MESSAGE_FATALFV XOS_LOG_MESSAGE_FATALFV
#define CACAO_LOG_MESSAGE_ERRORFV XOS_LOG_MESSAGE_ERRORFV
#define CACAO_LOG_MESSAGE_WARNFV XOS_LOG_MESSAGE_WARNFV
#define CACAO_LOG_MESSAGE_INFOFV XOS_LOG_MESSAGE_INFOFV
#define CACAO_LOG_MESSAGE_DEBUGFV XOS_LOG_MESSAGE_DEBUGFV
#define CACAO_LOG_MESSAGE_TRACEFV XOS_LOG_MESSAGE_TRACEFV

#define CACAO_LOG_MESSAGE_ANYMFV XOS_LOG_MESSAGE_ANYMFV
#define CACAO_LOG_MESSAGE_FATALMFV XOS_LOG_MESSAGE_FATALMFV
#define CACAO_LOG_MESSAGE_ERRORMFV XOS_LOG_MESSAGE_ERRORMFV
#define CACAO_LOG_MESSAGE_WARNMFV XOS_LOG_MESSAGE_WARNMFV
#define CACAO_LOG_MESSAGE_INFOMFV XOS_LOG_MESSAGE_INFOMFV
#define CACAO_LOG_MESSAGE_DEBUGMFV XOS_LOG_MESSAGE_DEBUGMFV
#define CACAO_LOG_MESSAGE_TRACEMFV XOS_LOG_MESSAGE_TRACEMFV
#else // !defined(USE_NADIR_BASE)
#include "nadir/io/logger.hpp"
#endif // !defined(USE_NADIR_BASE)

namespace cacao {
namespace io {

} // namespace io 
} // namespace cacao 

#endif // _CACAO_IO_LOGGER_HH 
