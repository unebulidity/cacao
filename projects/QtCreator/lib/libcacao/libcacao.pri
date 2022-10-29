########################################################################
# Copyright (c) 1988-2022 $organization$
#
# This software is provided by the author and contributors ``as is''
# and any express or implied warranties, including, but not limited to,
# the implied warranties of merchantability and fitness for a particular
# purpose are disclaimed. In no event shall the author or contributors
# be liable for any direct, indirect, incidental, special, exemplary,
# or consequential damages (including, but not limited to, procurement
# of substitute goods or services; loss of use, data, or profits; or
# business interruption) however caused and on any theory of liability,
# whether in contract, strict liability, or tort (including negligence
# or otherwise) arising in any way out of the use of this software,
# even if advised of the possibility of such damage.
#
#   File: libcacao.pri
#
# Author: $author$
#   Date: 10/29/2022
#
# generic QtCreator project .pri file for framework cacao static library libcacao
########################################################################

########################################################################
# libcacao
XOS_LIB_CACAO_VERSION_BUILD_DATE = 10/29/2022 #$$system(~/bin/utility/tdate)

# libcacao TARGET
#
libcacao_TARGET = cacao
libcacao_TEMPLATE = lib
libcacao_CONFIG += staticlib

# libcacao INCLUDEPATH
#
libcacao_INCLUDEPATH += \
$${cacao_INCLUDEPATH} \

# libcacao DEFINES
#
libcacao_DEFINES += \
$${cacao_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_LIB_CACAO_VERSION_BUILD_DATE=$${XOS_LIB_CACAO_VERSION_BUILD_DATE} \

########################################################################
# libcacao OBJECTIVE_HEADERS
#
libcacao_OBJECTIVE_HEADERS += \
$${CACAO_SRC}/cacao/icocoa/iMainCreator.hh \
$${CACAO_SRC}/cacao/icocoa/iMain.hh \
$${CACAO_SRC}/cacao/icocoa/iRun.hh \
$${CACAO_SRC}/cacao/icocoa/iOpt.hh \
$${CACAO_SRC}/cacao/icocoa/iDestroy.hh \
$${CACAO_SRC}/cacao/icocoa/apple/osx/iCocoa.hh \
$${CACAO_SRC}/cacao/icocoa/iCocoa.hh \
$${CACAO_SRC}/cacao/icocoa/iOsX.hh \
$${CACAO_SRC}/cacao/gui/main.hh \
$${CACAO_SRC}/cacao/console/main.hh \
$${CACAO_SRC}/cacao/console/main_opt.hh \
$${CACAO_SRC}/cacao/io/logger.hh \
$${CACAO_SRC}/cacao/base/base.hh \

# libcacao OBJECTIVE_SOURCES
#
libcacao_OBJECTIVE_SOURCES += \
$${CACAO_SRC}/cacao/icocoa/iMainCreator.mm \
$${CACAO_SRC}/cacao/icocoa/iMain.mm \
$${CACAO_SRC}/cacao/icocoa/iRun.mm \
$${CACAO_SRC}/cacao/icocoa/iOpt.mm \
$${CACAO_SRC}/cacao/icocoa/iDestroy.mm \
$${CACAO_SRC}/cacao/icocoa/iCocoa.mm \
$${CACAO_SRC}/cacao/icocoa/iOsX.mm \
$${CACAO_SRC}/cacao/gui/main.mm \
$${CACAO_SRC}/cacao/console/main_opt.mm \
$${CACAO_SRC}/cacao/io/logger.mm \
$${CACAO_SRC}/cacao/base/base.mm \

########################################################################
# libcacao HEADERS
#
libcacao_HEADERS += \

# libcacao SOURCES
#
libcacao_SOURCES += \

########################################################################

