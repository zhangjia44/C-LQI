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
#include "byteTo6bit_impl.h"

namespace gr {
  namespace byteTo6bit {

    byteTo6bit::sptr
    byteTo6bit::make()
    {
      return gnuradio::get_initial_sptr
        (new byteTo6bit_impl());
    }

    /*
     * The private constructor
     */
    byteTo6bit_impl::byteTo6bit_impl()
      : gr::block("byteTo6bit",
              gr::io_signature::make(1, 1, 48),
              gr::io_signature::make(1, 1, 288))
    {}

    /*
     * Our virtual destructor.
     */
    byteTo6bit_impl::~byteTo6bit_impl()
    {
    }

    void
    byteTo6bit_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
    {
      /* <+forecast+> e.g. ninput_items_required[0] = noutput_items */
    }

    int
    byteTo6bit_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
      const uint8_t *in = (const uint8_t *) input_items[0];
      uint8_t *out = (uint8_t *) output_items[0];

      int i = 0;
      int o = 0;
      uint8_t rx_bits[288];
      uint8_t rx_symbols[48];
      while(i < ninput_items[0] && o < noutput_items)
      {
        memcpy(rx_symbols, in + i * 48, 48);
        for(int j = 0; j < 48; j++)
        {
          for(int k = 0; k < 6; k++)
            rx_bits[j*6+k] = !!(rx_symbols[j] & (1 << k));
        }
        memcpy(out + o * 288, rx_bits, 288);
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

  } /* namespace byteTo6bit */
} /* namespace gr */
