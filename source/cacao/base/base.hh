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
///   File: base.hh
///
/// Author: $author$
///   Date: 7/9/2016
///////////////////////////////////////////////////////////////////////
#ifndef _CACAO_BASE_BASE_HH
#define _CACAO_BASE_BASE_HH

#if !defined(USE_NADIR_BASE)
#include "xos/base/base.hpp"
#include "xos/base/array.hpp"
#include "xos/base/string.hpp"
#include "xos/base/date.hpp"
#include "xos/base/types.hpp"
#include "xos/base/opened.hpp"
#include "xos/base/opener.hpp"
#include "xos/base/created.hpp"
#include "xos/base/creator.hpp"
#include "xos/base/attached.hpp"
#include "xos/base/attacher.hpp"
#include "xos/base/wrapped.hpp"
#include "xos/base/to_string.hpp"
#else // !defined(USE_NADIR_BASE)
#include "nadir/base/array.hpp"
#include "nadir/base/string.hpp"
#include "nadir/base/opened.hpp"
#include "nadir/base/created.hpp"
#include "nadir/base/attached.hpp"
#endif // !defined(USE_NADIR_BASE)

namespace cacao {

#if !defined(USE_NADIR_BASE)
typedef xos::base::implement_base implement_base;
typedef xos::base::base base;

typedef xos::base::byte_array byte_array;
typedef xos::base::word_array word_array;

typedef xos::base::string string;
typedef xos::base::tstring tstring;
typedef xos::base::wstring wstring;

typedef xos::base::pointer_to_string pointer_to_string;

typedef xos::base::creator_exception create_exception;
#else // !defined(USE_NADIR_BASE)
typedef nadir::char_string string;
typedef nadir::tchar_string tstring;
typedef nadir::wchar_string wstring;

typedef nadir::create_exception create_exception;
#endif // !defined(USE_NADIR_BASE)

} // namespace cacao

#endif // _CACAO_BASE_BASE_HH
