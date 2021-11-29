/* -*- c++ -*- */

#define MANUAL64TO7_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "manual64to7_swig_doc.i"

%{
#include "manual64to7/manual64to7.h"
%}


%include "manual64to7/manual64to7.h"
GR_SWIG_BLOCK_MAGIC2(manual64to7, manual64to7);
