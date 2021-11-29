# Copyright 2011,2012,2016 Free Software Foundation, Inc.
#
# This file is part of GNU Radio
#
# GNU Radio is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
#
# GNU Radio is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with GNU Radio; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.

########################################################################
# Setup library
########################################################################
include(GrPlatform) #define LIB_SUFFIX

include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIRS})

list(APPEND deconvolution_sources
    deconvolution_impl.cc
)

set(deconvolution_sources "${deconvolution_sources}" PARENT_SCOPE)
if(NOT deconvolution_sources)
	MESSAGE(STATUS "No C++ sources... skipping lib/")
	return()
endif(NOT deconvolution_sources)

add_library(gnuradio-deconvolution SHARED ${deconvolution_sources})
target_link_libraries(gnuradio-deconvolution ${Boost_LIBRARIES} ${GNURADIO_ALL_LIBRARIES})
set_target_properties(gnuradio-deconvolution PROPERTIES DEFINE_SYMBOL "gnuradio_deconvolution_EXPORTS")

if(APPLE)
    set_target_properties(gnuradio-deconvolution PROPERTIES
        INSTALL_NAME_DIR "${CMAKE_INSTALL_PREFIX}/lib"
    )
endif(APPLE)

########################################################################
# Install built library files
########################################################################
include(GrMiscUtils)
GR_LIBRARY_FOO(gnuradio-deconvolution RUNTIME_COMPONENT "deconvolution_runtime" DEVEL_COMPONENT "deconvolution_devel")

########################################################################
# Build and register unit test
########################################################################
include(GrTest)

include_directories(${CPPUNIT_INCLUDE_DIRS})

list(APPEND test_deconvolution_sources
    ${CMAKE_CURRENT_SOURCE_DIR}/test_deconvolution.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/qa_deconvolution.cc
)

add_executable(test-deconvolution ${test_deconvolution_sources})

target_link_libraries(
  test-deconvolution
  ${GNURADIO_RUNTIME_LIBRARIES}
  ${Boost_LIBRARIES}
  ${CPPUNIT_LIBRARIES}
  gnuradio-deconvolution
)

GR_ADD_TEST(test_deconvolution test-deconvolution)

########################################################################
# Print summary
########################################################################
message(STATUS "Using install prefix: ${CMAKE_INSTALL_PREFIX}")
message(STATUS "Building for version: ${VERSION} / ${LIBVER}")

