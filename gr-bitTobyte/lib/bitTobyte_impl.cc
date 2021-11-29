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
#include "bitTobyte_impl.h"

namespace gr {
  namespace bitTobyte {

    bitTobyte::sptr
    bitTobyte::make()
    {
      return gnuradio::get_initial_sptr
        (new bitTobyte_impl());
    }

    /*
     * The private constructor
     */
    bitTobyte_impl::bitTobyte_impl()
      : gr::block("bitTobyte",
              gr::io_signature::make(1, 1, 216),
              gr::io_signature::make(1, 1, 27))
    {}

    /*
     * Our virtual destructor.
     */
    bitTobyte_impl::~bitTobyte_impl()
    {
    }

    void
    bitTobyte_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
    {
      /* <+forecast+> e.g. ninput_items_required[0] = noutput_items */
    }

    int
    bitTobyte_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
      const uint8_t *in = (const uint8_t *) input_items[0];
      uint8_t *out = (uint8_t *) output_items[0];

      int i = 0;
      int o = 0;
      uint8_t out_byte[27];
      while(i < ninput_items[0] && o < noutput_items)
      {
        memset(out_byte, 0, 27);
        for(int j = 0; j < 216; j++)
        {
          out_byte[j/8] |= (*(in + i * 216 + j) & 0x1) << (j%8);
        }
        memcpy(out + o * 27, out_byte, 27);
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

  } /* namespace bitTobyte */
} /* namespace gr */
