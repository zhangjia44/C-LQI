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
#include "noise_filter_impl.h"

namespace gr {
  namespace noise_filter {
    const int SEARCH = 0;
    const int COPY = 1;
    noise_filter::sptr
    noise_filter::make(float threshold)
    {
      return gnuradio::get_initial_sptr
        (new noise_filter_impl(threshold));
    }

    /*
     * The private constructor
     */
    noise_filter_impl::noise_filter_impl(float threshold)
      : gr::block("noise_filter",
                  gr::io_signature::make2(2, 2, sizeof(gr_complex), sizeof(float)),
                  gr::io_signature::make(1, 1, sizeof(gr_complex)))
    {
      d_plateau = 0;
      d_state = SEARCH;
      d_threshold = threshold;
      d_cnt = 0;
    }

    /*
     * Our virtual destructor.
     */
    noise_filter_impl::~noise_filter_impl()
    {
    }

    void
    noise_filter_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
    {
      /* <+forecast+> e.g. ninput_items_required[0] = noutput_items */
    }

    int
    noise_filter_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
      const gr_complex *in = (const gr_complex *) input_items[0];
      const float *cor = (const float *) input_items[1];
      gr_complex *out = (gr_complex *) output_items[0];
      int noutput = noutput_items;
      int ninput = std::min(ninput_items[0], ninput_items[1]);
      switch (d_state) {
        case SEARCH:
          int i;
          for(i = 0; i < ninput; i++) {
            if(cor[i] > d_threshold) {
              if(d_plateau < 2) {
                d_plateau++;
              }
              else {
                d_state = COPY;
                d_plateau = 0;
                break;
              }
            }
            else {
              d_plateau = 0;
            }
            out[i] = gr_complex(0,0);
          }
          consume_each(i);
          return i;
        case COPY:
          int o = 0;
          while(o < ninput && o < noutput) {
            //d_cnt ++;
            if(cor[o] > d_threshold) {
              d_plateau = 0;
            }
            else {
              d_plateau++;
              if(d_plateau > 5) {
                d_plateau = 0;
                d_state = SEARCH;
                consume_each(o);
                return o;
              }
            }
            out[o] = in[o];
            o++;
          }
          consume_each(o);
          return o;
      }

      // Do <+signal processing+>
      // Tell runtime system how many input items we consumed on
      // each input stream.

      // Tell runtime system how many output items we produced.
      return 0;
    }

  } /* namespace noise_filter */
} /* namespace gr */
