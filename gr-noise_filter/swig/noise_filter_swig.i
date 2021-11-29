/* -*- c++ -*- */

#define NOISE_FILTER_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "noise_filter_swig_doc.i"

%{
#include "noise_filter/noise_filter.h"
%}


%include "noise_filter/noise_filter.h"
GR_SWIG_BLOCK_MAGIC2(noise_filter, noise_filter);
