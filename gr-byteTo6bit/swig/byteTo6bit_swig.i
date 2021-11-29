/* -*- c++ -*- */

#define BYTETO6BIT_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "byteTo6bit_swig_doc.i"

%{
#include "byteTo6bit/byteTo6bit.h"
%}


%include "byteTo6bit/byteTo6bit.h"
GR_SWIG_BLOCK_MAGIC2(byteTo6bit, byteTo6bit);
