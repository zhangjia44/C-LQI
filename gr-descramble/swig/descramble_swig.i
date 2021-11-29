/* -*- c++ -*- */

#define DESCRAMBLE_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "descramble_swig_doc.i"

%{
#include "descramble/descramble.h"
%}


%include "descramble/descramble.h"
GR_SWIG_BLOCK_MAGIC2(descramble, descramble);
