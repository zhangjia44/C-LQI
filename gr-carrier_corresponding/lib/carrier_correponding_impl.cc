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
#include "carrier_correponding_impl.h"

namespace gr {
  namespace carrier_corresponding {

    carrier_correponding::sptr
    carrier_correponding::make()
    {
      return gnuradio::get_initial_sptr
        (new carrier_correponding_impl());
    }

    /*
     * The private constructor
     */
    carrier_correponding_impl::carrier_correponding_impl()
      : gr::block("carrier_correponding",
              gr::io_signature::make(1, 1, 64),
              gr::io_signature::make(1, 1, 64))
    {}

    /*
     * Our virtual destructor.
     */
    carrier_correponding_impl::~carrier_correponding_impl()
    {
    }

    void
    carrier_correponding_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
    {
      /* <+forecast+> e.g. ninput_items_required[0] = noutput_items */
    }

    int
    carrier_correponding_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
      const uint8_t *in = (const uint8_t *) input_items[0];
      uint8_t *out = (uint8_t *) output_items[0];
      int i = 0;
      int o = 0;
      uint8_t output[64];
      uint8_t output_corresponding[64];
      while(i < ninput_items[0] && o < noutput_items)
      {
        memcpy(output, in + i * 64, 64);
        for(int j = 0; j < 44; j++)
          output_corresponding[j] = output[j];
        for(int j = 44; j < 51; j++)
          output_corresponding[j] = output[j - 44 + 28];
        for(int j = 51; j < 64; j++)
          output_corresponding[j] = output[j];


        memcpy(out + o * 64, output_corresponding, 64);
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

  } /* namespace carrier_corresponding */
} /* namespace gr */
