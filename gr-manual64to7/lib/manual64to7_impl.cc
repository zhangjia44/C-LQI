/* -*- c++ -*- */
/*
 * Copyright 2018 <+YOU OR YOUR COMPANY+>.
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "manual64to7_impl.h"

namespace gr {
  namespace manual64to7 {

    manual64to7::sptr
    manual64to7::make()
    {
      return gnuradio::get_initial_sptr
        (new manual64to7_impl());
    }

    /*
     * The private constructor
     */
    manual64to7_impl::manual64to7_impl()
      : gr::block("decycleprefix",
              gr::io_signature::make(1, 1, 64 * sizeof(gr_complex)),
              gr::io_signature::make(1, 1, 64 * sizeof(gr_complex)))
    {}

    /*
     * Our virtual destructor.
     */
    manual64to7_impl::~manual64to7_impl()
    {
    }

    void
    manual64to7_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
    {
      /* <+forecast+> e.g. ninput_items_required[0] = noutput_items */
    }

    int
    manual64to7_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
      const gr_complex *in = (const gr_complex *) input_items[0];
      gr_complex *out = (gr_complex *) output_items[0];

      int i = 0;
      int o = 0;
      gr_complex output[64];
      while(i < ninput_items[0] && o < noutput_items)
      {
        for(int j = 0; j < 29; j++) {
          *(out + o * 64 + j) = 0;
        }
        for(int j = 28; j < 35; j++) {
          *(out + o * 64 + j) = *(in + i * 64 + j - 28 + 44);
        }
        for(int j = 36; j < 64; j++) {
          *(out + o * 64 + j) = 0;
        }
        i++;
        o++;
      }
      consume_each (i);
      return o;
    }

  } /* namespace manual64to7 */
} /* namespace gr */
