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
#include "my_decoder_impl.h"

namespace gr {
  namespace ieee802_11 {

    my_decoder::sptr
    my_decoder::make()
    {
      return gnuradio::get_initial_sptr
        (new my_decoder_impl());
    }

    /*
     * The private constructor
     */
    my_decoder_impl::my_decoder_impl()
      : gr::block("my_decoder",
              gr::io_signature::make(1, 1, 288),
              gr::io_signature::make(1, 1, 216))
    {}

    /*
     * Our virtual destructor.
     */
    my_decoder_impl::~my_decoder_impl()
    {
    }

    void
    my_decoder_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
    {
      /* <+forecast+> e.g. ninput_items_required[0] = noutput_items */
    }

    int
    my_decoder_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
      std::cout << "hello" << std::endl;
      const uint8_t *in = (const uint8_t *) input_items[0];
      uint8_t *out = (uint8_t *) output_items[0];
      int len_data = 0;
      int i = 0;
      int o = 0;
      ofdm_param ofdm = ofdm_param(QAM64_3_4);
      frame_param frame = frame_param(ofdm, len_data);
      uint8_t deinterleaved_bits[288];
      uint8_t *decoded;
      viterbi_decoder d_decoder;
      while(i < ninput_items[0] && o < noutput_items)
      {
          memcpy(deinterleaved_bits, in + i * 288, 288);
          decoded = deinterleaved_bits;
          //uint8_t *decoded = d_decoder.decode(&ofdm, &frame, deinterleaved_bits);
          memcpy(out + o * 216, decoded, 216);
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

  } /* namespace ieee802-11 */
} /* namespace gr */
