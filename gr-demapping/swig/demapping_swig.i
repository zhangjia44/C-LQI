/* -*- c++ -*- */

#define DEMAPPING_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "demapping_swig_doc.i"

%{
#include "demapping/my_demapping_64.h"
%}


%include "demapping/my_demapping_64.h"
GR_SWIG_BLOCK_MAGIC2(demapping, my_demapping_64);
