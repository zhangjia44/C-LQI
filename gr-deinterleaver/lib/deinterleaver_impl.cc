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
#include "deinterleaver_impl.h"
#include <fstream>
namespace gr {
  namespace deinterleaver {

    deinterleaver::sptr
    deinterleaver::make()
    {
      return gnuradio::get_initial_sptr
        (new deinterleaver_impl());
    }

    /*
     * The private constructor
     */
    deinterleaver_impl::deinterleaver_impl()
      : gr::block("deinterleaver",
              gr::io_signature::make(1, 1, 48 * 6),
              gr::io_signature::make(1, 1, 48 * 6))
    {}

    /*
     * Our virtual destructor.
     */
    deinterleaver_impl::~deinterleaver_impl()
    {
    }

    void
    deinterleaver_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
    {
      /* <+forecast+> e.g. ninput_items_required[0] = noutput_items */
    }

    int
    deinterleaver_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
      const uint8_t *in = (const uint8_t *) input_items[0];
      uint8_t *out = (uint8_t *) output_items[0];
      int n_cbps = 288;
      int i = 0;
      int o = 0;
      uint8_t rx_bits[288];
      uint8_t deinterleaved_bits[288];
      while(i < ninput_items[0] && o < noutput_items)
      {

        memcpy(rx_bits, in + i * 288, 288);
        int first[n_cbps];
        int second[n_cbps];
        int s = 3;
        for(int j = 0; j < n_cbps; j++)
        {
            first[j] = s * (j / s) + ((j + int(floor(16.0 * j / n_cbps))) % s);
        }
        for(int j = 0; j < n_cbps; j++)
        {
            second[j] = 16 * j - (n_cbps - 1) * int(floor(16.0 * j / n_cbps));
        }

        for(int k = 0; k < n_cbps; k++)
        {
            deinterleaved_bits[second[first[k]]] = rx_bits[k];
        }

        memcpy(out + o * 48 * 6, deinterleaved_bits, 48 * 6);
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

  } /* namespace deinterleaver */
} /* namespace gr */
