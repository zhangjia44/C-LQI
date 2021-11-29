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

list(APPEND manual64to7_sources
    manual64to7_impl.cc
)

set(manual64to7_sources "${manual64to7_sources}" PARENT_SCOPE)
if(NOT manual64to7_sources)
	MESSAGE(STATUS "No C++ sources... skipping lib/")
	return()
endif(NOT manual64to7_sources)

add_library(gnuradio-manual64to7 SHARED ${manual64to7_sources})
target_link_libraries(gnuradio-manual64to7 ${Boost_LIBRARIES} ${GNURADIO_ALL_LIBRARIES})
set_target_properties(gnuradio-manual64to7 PROPERTIES DEFINE_SYMBOL "gnuradio_manual64to7_EXPORTS")

if(APPLE)
    set_target_properties(gnuradio-manual64to7 PROPERTIES
        INSTALL_NAME_DIR "${CMAKE_INSTALL_PREFIX}/lib"
    )
endif(APPLE)

########################################################################
# Install built library files
########################################################################
include(GrMiscUtils)
GR_LIBRARY_FOO(gnuradio-manual64to7 RUNTIME_COMPONENT "manual64to7_runtime" DEVEL_COMPONENT "manual64to7_devel")

########################################################################
# Build and register unit test
########################################################################
include(GrTest)

include_directories(${CPPUNIT_INCLUDE_DIRS})

list(APPEND test_manual64to7_sources
    ${CMAKE_CURRENT_SOURCE_DIR}/test_manual64to7.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/qa_manual64to7.cc
)

add_executable(test-manual64to7 ${test_manual64to7_sources})

target_link_libraries(
  test-manual64to7
  ${GNURADIO_RUNTIME_LIBRARIES}
  ${Boost_LIBRARIES}
  ${CPPUNIT_LIBRARIES}
  gnuradio-manual64to7
)

GR_ADD_TEST(test_manual64to7 test-manual64to7)

########################################################################
# Print summary
########################################################################
message(STATUS "Using install prefix: ${CMAKE_INSTALL_PREFIX}")
message(STATUS "Building for version: ${VERSION} / ${LIBVER}")

