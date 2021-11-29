/* -*- c++ -*- */

#define DEINTERLEAVER_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "deinterleaver_swig_doc.i"

%{
#include "deinterleaver/deinterleaver.h"
%}


%include "deinterleaver/deinterleaver.h"
GR_SWIG_BLOCK_MAGIC2(deinterleaver, deinterleaver);
