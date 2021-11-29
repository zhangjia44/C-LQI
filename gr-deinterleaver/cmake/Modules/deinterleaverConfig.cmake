INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_DEINTERLEAVER deinterleaver)

FIND_PATH(
    DEINTERLEAVER_INCLUDE_DIRS
    NAMES deinterleaver/api.h
    HINTS $ENV{DEINTERLEAVER_DIR}/include
        ${PC_DEINTERLEAVER_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    DEINTERLEAVER_LIBRARIES
    NAMES gnuradio-deinterleaver
    HINTS $ENV{DEINTERLEAVER_DIR}/lib
        ${PC_DEINTERLEAVER_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(DEINTERLEAVER DEFAULT_MSG DEINTERLEAVER_LIBRARIES DEINTERLEAVER_INCLUDE_DIRS)
MARK_AS_ADVANCED(DEINTERLEAVER_LIBRARIES DEINTERLEAVER_INCLUDE_DIRS)
