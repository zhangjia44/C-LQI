/* -*- c++ -*- */

#define CARRIER_CORRESPONDING_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "carrier_corresponding_swig_doc.i"

%{
#include "carrier_corresponding/carrier_correponding.h"
%}


%include "carrier_corresponding/carrier_correponding.h"
GR_SWIG_BLOCK_MAGIC2(carrier_corresponding, carrier_correponding);
