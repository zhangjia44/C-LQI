INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_DEMAPPING demapping)

FIND_PATH(
    DEMAPPING_INCLUDE_DIRS
    NAMES demapping/api.h
    HINTS $ENV{DEMAPPING_DIR}/include
        ${PC_DEMAPPING_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    DEMAPPING_LIBRARIES
    NAMES gnuradio-demapping
    HINTS $ENV{DEMAPPING_DIR}/lib
        ${PC_DEMAPPING_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(DEMAPPING DEFAULT_MSG DEMAPPING_LIBRARIES DEMAPPING_INCLUDE_DIRS)
MARK_AS_ADVANCED(DEMAPPING_LIBRARIES DEMAPPING_INCLUDE_DIRS)

