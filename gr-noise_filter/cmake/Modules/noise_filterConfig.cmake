INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_NOISE_FILTER noise_filter)

FIND_PATH(
    NOISE_FILTER_INCLUDE_DIRS
    NAMES noise_filter/api.h
    HINTS $ENV{NOISE_FILTER_DIR}/include
        ${PC_NOISE_FILTER_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    NOISE_FILTER_LIBRARIES
    NAMES gnuradio-noise_filter
    HINTS $ENV{NOISE_FILTER_DIR}/lib
        ${PC_NOISE_FILTER_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(NOISE_FILTER DEFAULT_MSG NOISE_FILTER_LIBRARIES NOISE_FILTER_INCLUDE_DIRS)
MARK_AS_ADVANCED(NOISE_FILTER_LIBRARIES NOISE_FILTER_INCLUDE_DIRS)

