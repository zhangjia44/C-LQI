/* -*- c++ -*- */

#define DECYCLEPREFIX_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "decycleprefix_swig_doc.i"

%{
#include "decycleprefix/decycleprefix.h"
%}


%include "decycleprefix/decycleprefix.h"
GR_SWIG_BLOCK_MAGIC2(decycleprefix, decycleprefix);
