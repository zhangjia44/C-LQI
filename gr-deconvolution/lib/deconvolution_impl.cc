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
#include "deconvolution_impl.h"

const unsigned int IN_POS[] = {12,13,28,29,44,45,60,61,76,77,92,93,107,108,109,123,124,125,139,140,141,155,156,157,171,172,173,187,188,189,203,204,219,220,235,236,251,252,267,268,283,284};
const unsigned int OUT_POS[] = {9,21,33,45,57,69,80,81,92,93,104,105,116,167,128,129,140,141, 152,153,164,165,176,177,188,189,200,201,212,213};

namespace gr {
  namespace deconvolution {

    deconvolution::sptr
    deconvolution::make()
    {
      return gnuradio::get_initial_sptr
        (new deconvolution_impl());
    }

    /*
     * The private constructor
     */
    deconvolution_impl::deconvolution_impl()
      : gr::block("deconvolution",
              gr::io_signature::make(1, 1, 288),
              gr::io_signature::make(1, 1, 216))
    {
    }

    /*
     * Our virtual destructor.
     */
    deconvolution_impl::~deconvolution_impl()
    {
    }
    void deconvolution_impl::deconvolution288_216(const uint8_t *in,uint8_t *out) {
        for(int i = 0; i < 216; i++)
            out[i] = 0;
        for(int i = 0; i < 6; i++) {
            int desire = 2 * in[IN_POS[i * 2]] + in[IN_POS[i * 2 + 1]];
            switch (desire) {
                case 0:
                    //do nothing
                    break;
                case 1:
                    out[OUT_POS[i] - 1] = 1;
                    break;
                case 2:
                    out[OUT_POS[i] - 1] = 1;
                    out[OUT_POS[i]] = 1;
                    break;
                case 3:
                    out[OUT_POS[i]] = 1;
                    break;
                default:
                    break;
            }
        }
        for(int i = 0; i < 6; i ++) {
            int desire = 4 * in[IN_POS[12 + i * 3]] + 2 * in[IN_POS[12 + i * 3 + 1]] + in[IN_POS[12 + i * 3 + 2]];
            int p = 6 + i * 2;
            switch (desire) {
                case 0:
                    //do nothing
                    break;
                case 1:
                    out[OUT_POS[p] - 1] = 1;
                    out[OUT_POS[p]] = 1;
                    out[OUT_POS[p] + 1] = 1;
                    break;
                case 2:
                    out[OUT_POS[p] - 1] = 1;
                    out[OUT_POS[p]] = 1;
                    break;
                case 3:
                    out[OUT_POS[p] + 1] = 1;

                    break;
                case 4:
                    out[OUT_POS[p] - 1] = 1;
                    out[OUT_POS[p] + 1] = 1;
                    break;
                case 5:
                    out[OUT_POS[p]] = 1;
                    break;
                case 6:
                    out[OUT_POS[p]] = 1;
                    out[OUT_POS[p] + 1] = 1;
                    break;
                case 7:
                    out[OUT_POS[p] - 1] = 1;
                    break;
                default:
                    break;
            }
        }
        for(int i = 0; i < 6; i++) {
            int desire = 2 * in[IN_POS[30 + i * 2]] + in[IN_POS[30 + i * 2 + 1]];
            int p = 18 + i * 2;
            switch (desire) {
                case 0:
                    //do nothing
                    break;
                case 1:
                    out[OUT_POS[p] + 1] = 1;
                    break;
                case 2:
                    out[OUT_POS[p]] = 1;
                    break;
                case 3:
                    out[OUT_POS[p]] = 1;
                    out[OUT_POS[p] + 1] = 1;

                    break;
                default:
                    break;
            }
        }
    }
    void
    deconvolution_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
    {
      /* <+forecast+> e.g. ninput_items_required[0] = noutput_items */
    }

    int
    deconvolution_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
      const uint8_t *in = (const uint8_t *) input_items[0];
      uint8_t *out = (uint8_t *) output_items[0];
      int i = 0;
      int o = 0;
      while(i < ninput_items[0] && o < noutput_items)
      {
        deconvolution288_216(in + i * 288, out + o * 216);
        i++;
        o++;
      }
      // Do <+signal processing+>
      // Tell runtime system how many input items we consumed on
      // each input stream.
      consume_each (i);

      // Tell runtime system how many output items we produced.
      return o;
    }

  } /* namespace deconvolution */
} /* namespace gr */
