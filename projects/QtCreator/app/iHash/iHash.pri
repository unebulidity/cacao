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
#   File: iHash.pri
#
# Author: $author$
#   Date: 10/29/2022
#
# generic QtCreator project .pri file for framework cacao executable iHash
########################################################################

########################################################################
# iHash

# iHash TARGET
#
iHash_TARGET = iHash

# iHash INCLUDEPATH
#
iHash_INCLUDEPATH += \
$${cacao_INCLUDEPATH} \

# iHash DEFINES
#
iHash_DEFINES += \
$${cacao_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
NO_USE_NADIR_BASE \
NO_USE_XOS_LOGGER_INTERFACE \

########################################################################
# iHash OBJECTIVE_HEADERS
#
iHash_OBJECTIVE_HEADERS += \
$${CACAO_SRC}/cacao/cocoa/base/Run.hh \
$${CACAO_SRC}/cacao/cocoa/base/Joined.hh \
$${CACAO_SRC}/cacao/cocoa/base/Acquired.hh \
$${CACAO_SRC}/cacao/cocoa/base/Waited.hh \
$${CACAO_SRC}/cacao/cocoa/base/Locked.hh \
$${CACAO_SRC}/cacao/cocoa/base/Opened.hh \
$${CACAO_SRC}/cacao/cocoa/base/Created.hh \
$${CACAO_SRC}/cacao/cocoa/base/Attached.hh \
$${CACAO_SRC}/cacao/cocoa/base/Base.hh \
\
$${CACAO_SRC}/cacao/cocoa/mt/apple/osx/Thread.hh \
$${CACAO_SRC}/cacao/cocoa/mt/posix/Thread.hh \
$${CACAO_SRC}/cacao/cocoa/mt/Thread.hh \
$${CACAO_SRC}/cacao/cocoa/mt/apple/osx/Semaphore.hh \
$${CACAO_SRC}/cacao/cocoa/mt/apple/mach/Semaphore.hh \
$${CACAO_SRC}/cacao/cocoa/mt/Semaphore.hh \
$${CACAO_SRC}/cacao/cocoa/mt/apple/osx/Mutex.hh \
$${CACAO_SRC}/cacao/cocoa/mt/posix/Mutex.hh \
$${CACAO_SRC}/cacao/cocoa/mt/Mutex.hh \
\
$${CACAO_SRC}/cacao/cocoa/crypto/hash/Base.hh \
\
$${CACAO_SRC}/cacao/cocoa/apple/osx/Main.hh \
$${CACAO_SRC}/cacao/cocoa/apple/osx/MainWindow.hh \
$${CACAO_SRC}/cacao/cocoa/apple/osx/MainView.hh \
$${CACAO_SRC}/cacao/cocoa/apple/osx/MainMenu.hh \
$${CACAO_SRC}/cacao/cocoa/apple/osx/Application.hh \
$${CACAO_SRC}/cacao/cocoa/apple/osx/Static.hh \
$${CACAO_SRC}/cacao/cocoa/apple/osx/Edit.hh \
$${CACAO_SRC}/cacao/cocoa/apple/osx/Label.hh \
$${CACAO_SRC}/cacao/cocoa/apple/osx/TextField.hh \
$${CACAO_SRC}/cacao/cocoa/apple/osx/Check.hh \
$${CACAO_SRC}/cacao/cocoa/apple/osx/Button.hh \
$${CACAO_SRC}/cacao/cocoa/apple/osx/Progress.hh \
$${CACAO_SRC}/cacao/cocoa/apple/osx/Logger.hh \
$${CACAO_SRC}/cacao/cocoa/apple/osx/Cocoa.hh \
\
$${CACAO_SRC}/cacao/app/cocoa/crypto/iHash/MainWindow.hh \
$${CACAO_SRC}/cacao/app/cocoa/apple/osx/crypto/iHash/MainWindow.hh \
$${CACAO_SRC}/cacao/app/cocoa/apple/osx/crypto/iHash/iHashMain.hh \
$${CACAO_SRC}/cacao/app/cocoa/apple/osx/crypto/iHash/iHashMainWindow.hh \
$${CACAO_SRC}/cacao/app/cocoa/apple/osx/crypto/iHash/iHashMainView.hh \
$${CACAO_SRC}/cacao/app/cocoa/apple/osx/crypto/iHash/iHashControlView.hh \
$${CACAO_SRC}/cacao/app/cocoa/apple/osx/crypto/iHash/iHashMainWindowPeer.hh \

# iHash OBJECTIVE_SOURCES
#
iHash_OBJECTIVE_SOURCES += \
$${CACAO_SRC}/cacao/cocoa/base/Run.mm \
$${CACAO_SRC}/cacao/cocoa/base/Joined.mm \
$${CACAO_SRC}/cacao/cocoa/base/Acquired.mm \
$${CACAO_SRC}/cacao/cocoa/base/Waited.mm \
$${CACAO_SRC}/cacao/cocoa/base/Locked.mm \
$${CACAO_SRC}/cacao/cocoa/base/Opened.mm \
$${CACAO_SRC}/cacao/cocoa/base/Created.mm \
$${CACAO_SRC}/cacao/cocoa/base/Attached.mm \
\
$${CACAO_SRC}/cacao/cocoa/mt/apple/osx/Thread.mm \
$${CACAO_SRC}/cacao/cocoa/mt/apple/mach/Semaphore.mm \
$${CACAO_SRC}/cacao/cocoa/mt/apple/osx/Mutex.mm \
\
$${CACAO_SRC}/cacao/cocoa/crypto/hash/Base.mm \
\
$${CACAO_SRC}/cacao/cocoa/apple/osx/Main.mm \
$${CACAO_SRC}/cacao/cocoa/apple/osx/MainWindow.mm \
$${CACAO_SRC}/cacao/cocoa/apple/osx/MainView.mm \
$${CACAO_SRC}/cacao/cocoa/apple/osx/MainMenu.mm \
$${CACAO_SRC}/cacao/cocoa/apple/osx/Application.mm \
$${CACAO_SRC}/cacao/cocoa/apple/osx/Static.mm \
$${CACAO_SRC}/cacao/cocoa/apple/osx/Edit.mm \
$${CACAO_SRC}/cacao/cocoa/apple/osx/Label.mm \
$${CACAO_SRC}/cacao/cocoa/apple/osx/TextField.mm \
$${CACAO_SRC}/cacao/cocoa/apple/osx/Check.mm \
$${CACAO_SRC}/cacao/cocoa/apple/osx/Button.mm \
$${CACAO_SRC}/cacao/cocoa/apple/osx/Progress.mm \
$${CACAO_SRC}/cacao/cocoa/apple/osx/Logger.mm \
$${CACAO_SRC}/cacao/cocoa/apple/osx/Cocoa.mm \
\
$${CACAO_SRC}/cacao/app/cocoa/apple/osx/crypto/iHash/iHashMain.mm \
$${CACAO_SRC}/cacao/app/cocoa/apple/osx/crypto/iHash/iHashMainWindow.mm \
$${CACAO_SRC}/cacao/app/cocoa/apple/osx/crypto/iHash/iHashMainView.mm \
$${CACAO_SRC}/cacao/app/cocoa/apple/osx/crypto/iHash/iHashControlView.mm \
$${CACAO_SRC}/cacao/app/cocoa/apple/osx/crypto/iHash/iHashMainWindowPeer.mm \

########################################################################
# iHash HEADERS
#
iHash_HEADERS += \
$${LAMNA_SRC}/lamna/graphic/surface/shape/key_icon.hpp \

# iHash SOURCES
#
iHash_SOURCES += \
$${LAMNA_SRC}/lamna/graphic/surface/shape/key_icon.cpp \

########################################################################
# iHash OBJECTIVE_HEADERS
#
iHash_OBJECTIVE_HEADERS += \
$${CACAO_SRC}/cacao/cocoa/crypto/hash/Sha1.hh \

# iHash OBJECTIVE_SOURCES
#
iHash_OBJECTIVE_SOURCES += \
$${CACAO_SRC}/cacao/cocoa/crypto/hash/Sha1.mm \

########################################################################
# iHash FRAMEWORKS
#
iHash_FRAMEWORKS += \
$${cacao_FRAMEWORKS} \

# iHash LIBS
#
iHash_LIBS += \
$${cacao_LIBS} \

########################################################################
# NO Qt
QT -= gui core

