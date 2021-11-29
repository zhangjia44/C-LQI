/* -*- c++ -*- */

#define BITTOBYTE_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "bitTobyte_swig_doc.i"

%{
#include "bitTobyte/bitTobyte.h"
%}


%include "bitTobyte/bitTobyte.h"
GR_SWIG_BLOCK_MAGIC2(bitTobyte, bitTobyte);
