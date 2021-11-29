INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_DECYCLEPREFIX decycleprefix)

FIND_PATH(
    DECYCLEPREFIX_INCLUDE_DIRS
    NAMES decycleprefix/api.h
    HINTS $ENV{DECYCLEPREFIX_DIR}/include
        ${PC_DECYCLEPREFIX_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    DECYCLEPREFIX_LIBRARIES
    NAMES gnuradio-decycleprefix
    HINTS $ENV{DECYCLEPREFIX_DIR}/lib
        ${PC_DECYCLEPREFIX_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(DECYCLEPREFIX DEFAULT_MSG DECYCLEPREFIX_LIBRARIES DECYCLEPREFIX_INCLUDE_DIRS)
MARK_AS_ADVANCED(DECYCLEPREFIX_LIBRARIES DECYCLEPREFIX_INCLUDE_DIRS)
