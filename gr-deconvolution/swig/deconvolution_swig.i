/* -*- c++ -*- */

#define DECONVOLUTION_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "deconvolution_swig_doc.i"

%{
#include "deconvolution/deconvolution.h"
%}


%include "deconvolution/deconvolution.h"
GR_SWIG_BLOCK_MAGIC2(deconvolution, deconvolution);
