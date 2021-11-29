/* -*- c++ -*- */

#define CARRIER48_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "carrier48_swig_doc.i"

%{
#include "carrier48/carrier48.h"
%}


%include "carrier48/carrier48.h"
GR_SWIG_BLOCK_MAGIC2(carrier48, carrier48);
