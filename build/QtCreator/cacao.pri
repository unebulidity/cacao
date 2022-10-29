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
#   File: cacao.pri
#
# Author: $author$
#   Date: 10/29/2022
#
# build specific QtCreator project .pri file for framework cacao
########################################################################
# Depends: nadir;rostra;lamna;talas

contains(BUILD_OS,Uname) {
UNAME = $$system(uname)

contains(UNAME,Darwin) {
BUILD_OS = macosx
} else {
contains(UNAME,Linux) {
BUILD_OS = linux
} else {
contains(UNAME,Windows) {
BUILD_OS = windows
} else {
BUILD_OS = os
} # contains(UNAME,Windows)
} # contains(UNAME,Linux)
} # contains(UNAME,Darwin)
} else {
contains(BUILD_OS,CACAO_OS) {
} else {
BUILD_OS = os
} # contains(BUILD_OS,CACAO_OS)
} # contains(BUILD_OS,Uname)

#BUILD_CPP_VERSION = 11

########################################################################
# nadir
#
# pkg-config --cflags --libs nadir
#

# build nadir INCLUDEPATH
#
build_nadir_INCLUDEPATH += \

# build nadir DEFINES
#
build_nadir_DEFINES += \

# build nadir FRAMEWORKS
#
build_nadir_FRAMEWORKS += \

# build nadir LIBS
#
build_nadir_LIBS += \

########################################################################
# rostra
#
# pkg-config --cflags --libs rostra
#

# build rostra INCLUDEPATH
#
build_rostra_INCLUDEPATH += \

# build rostra DEFINES
#
build_rostra_DEFINES += \

# build rostra FRAMEWORKS
#
build_rostra_FRAMEWORKS += \

# build rostra LIBS
#
build_rostra_LIBS += \

########################################################################
# lamna
#
# pkg-config --cflags --libs lamna
#

# build lamna INCLUDEPATH
#
build_lamna_INCLUDEPATH += \

# build lamna DEFINES
#
build_lamna_DEFINES += \

# build lamna FRAMEWORKS
#
build_lamna_FRAMEWORKS += \

# build lamna LIBS
#
build_lamna_LIBS += \

########################################################################
# talas
#
# pkg-config --cflags --libs talas
#

# build talas INCLUDEPATH
#
build_talas_INCLUDEPATH += \

# build talas DEFINES
#
build_talas_DEFINES += \

# build talas FRAMEWORKS
#
build_talas_FRAMEWORKS += \

# build talas LIBS
#
build_talas_LIBS += \

########################################################################
# cacao

# build cacao INCLUDEPATH
#
build_cacao_INCLUDEPATH += \
$${build_talas_INCLUDEPATH} \
$${build_lamna_INCLUDEPATH} \
$${build_rostra_INCLUDEPATH} \
$${build_nadir_INCLUDEPATH} \


# build cacao DEFINES
#
build_cacao_DEFINES += \
$${build_nadir_DEFINES} \
$${build_rostra_DEFINES} \
$${build_lamna_DEFINES} \
$${build_talas_DEFINES} \


# build cacao FRAMEWORKS
#
build_cacao_FRAMEWORKS += \
$${build_talas_FRAMEWORKS} \
$${build_lamna_FRAMEWORKS} \
$${build_rostra_FRAMEWORKS} \
$${build_nadir_FRAMEWORKS} \


# build cacao LIBS
#
build_cacao_LIBS += \
$${build_talas_LIBS} \
$${build_lamna_LIBS} \
$${build_rostra_LIBS} \
$${build_nadir_LIBS} \

########################################################################
