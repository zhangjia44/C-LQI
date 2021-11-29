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
#include "my_demapping_64_impl.h"

namespace gr {
  namespace demapping {

    my_demapping_64::sptr
    my_demapping_64::make(int carrier_number)
    {
      return gnuradio::get_initial_sptr
        (new my_demapping_64_impl(carrier_number));
    }

    /*
     * The private constructor
     */
    my_demapping_64_impl::my_demapping_64_impl(int carrier_number)
      : gr::block("my_demapping_64",
              gr::io_signature::make(1, 1, 64*sizeof(gr_complex)),
              gr::io_signature::make(1, 1, 64))
    {}
    /*
     * Our virtual destructor.
     */
    my_demapping_64_impl::~my_demapping_64_impl()
    {
    }

    void
    my_demapping_64_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
    {
      /* <+forecast+> e.g. ninput_items_required[0] = noutput_items */
    }

    int
    my_demapping_64_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {

      const gr_complex *in = (const gr_complex *) input_items[0];
      uint8_t *out = (uint8_t *) output_items[0];
      int i = 0;
	    int o = 0;

      while((i < ninput_items[0]) && (o < noutput_items))
      {
        for(int j = 0; j < 64; j++)
        {
          *(out + o * 64 + j) = decision_maker(in + i * 64 + j);
        }
        i++;
        o++;
      }
      // Do <+signal processing+>
      // Tell runtime system how many input items we consumed on
      // each input stream.
      //consume(0,i);
      consume_each(i);
      // Tell runtime system how many output items we produced.
      return o;
    }
    uint8_t my_demapping_64_impl::decision_maker(const gr_complex *sample)
    {

      uint8_t ret = 0;
      /*
    	const float level = sqrt(float(1/42.0));
  	  float re = sample->real() * 7 / 48 * sqrt(float(1/42.0));
  	  float im = sample->imag() * 7 / 48 * sqrt(float(1/42.0));
      */
      const float level = sqrt(float(1/42.0));
      float re = sample->real() * 7 / 48 * sqrt(float(1/42.0));
      float im = sample->imag() * 7 / 48 * sqrt(float(1/42.0));
  	  ret |= re > 0;
  	  ret |= (std::abs(re) < (4*level)) << 1;
  	  ret |= (std::abs(re) < (6*level) && std::abs(re) > (2*level)) << 2;
  	  ret |= (im > 0) << 3;
  	  ret |= (std::abs(im) < (4*level)) << 4;
  	  ret |= (std::abs(im) < (6*level) && std::abs(im) > (2*level)) << 5;

  	  return ret;
      /*
      d_constellation[ 0] = gr_complex(-7*level,-7*level);
      d_constellation[ 1] = gr_complex( 7*level,-7*level);
      d_constellation[ 2] = gr_complex(-1*level,-7*level);
      d_constellation[ 3] = gr_complex( 1*level,-7*level);
      d_constellation[ 4] = gr_complex(-5*level,-7*level);
      d_constellation[ 5] = gr_complex( 5*level,-7*level);
      d_constellation[ 6] = gr_complex(-3*level,-7*level);
      d_constellation[ 7] = gr_complex( 3*level,-7*level);
      d_constellation[ 8] = gr_complex(-7*level, 7*level);
      d_constellation[ 9] = gr_complex( 7*level, 7*level);
      d_constellation[10] = gr_complex(-1*level, 7*level);
      d_constellation[11] = gr_complex( 1*level, 7*level);
      d_constellation[12] = gr_complex(-5*level, 7*level);
      d_constellation[13] = gr_complex( 5*level, 7*level);
      d_constellation[14] = gr_complex(-3*level, 7*level);
      d_constellation[15] = gr_complex( 3*level, 7*level);
      d_constellation[16] = gr_complex(-7*level,-1*level);
      d_constellation[17] = gr_complex( 7*level,-1*level);
      d_constellation[18] = gr_complex(-1*level,-1*level);
      d_constellation[19] = gr_complex( 1*level,-1*level);
      d_constellation[20] = gr_complex(-5*level,-1*level);
      d_constellation[21] = gr_complex( 5*level,-1*level);
      d_constellation[22] = gr_complex(-3*level,-1*level);
      d_constellation[23] = gr_complex( 3*level,-1*level);
      d_constellation[24] = gr_complex(-7*level, 1*level);
      d_constellation[25] = gr_complex( 7*level, 1*level);
      d_constellation[26] = gr_complex(-1*level, 1*level);
      d_constellation[27] = gr_complex( 1*level, 1*level);
      d_constellation[28] = gr_complex(-5*level, 1*level);
      d_constellation[29] = gr_complex( 5*level, 1*level);
      d_constellation[30] = gr_complex(-3*level, 1*level);
      d_constellation[31] = gr_complex( 3*level, 1*level);
      d_constellation[32] = gr_complex(-7*level,-5*level);
      d_constellation[33] = gr_complex( 7*level,-5*level);
      d_constellation[34] = gr_complex(-1*level,-5*level);
      d_constellation[35] = gr_complex( 1*level,-5*level);
      d_constellation[36] = gr_complex(-5*level,-5*level);
      d_constellation[37] = gr_complex( 5*level,-5*level);
      d_constellation[38] = gr_complex(-3*level,-5*level);
      d_constellation[39] = gr_complex( 3*level,-5*level);
      d_constellation[40] = gr_complex(-7*level, 5*level);
      d_constellation[41] = gr_complex( 7*level, 5*level);
      d_constellation[42] = gr_complex(-1*level, 5*level);
      d_constellation[43] = gr_complex( 1*level, 5*level);
      d_constellation[44] = gr_complex(-5*level, 5*level);
      d_constellation[45] = gr_complex( 5*level, 5*level);
      d_constellation[46] = gr_complex(-3*level, 5*level);
      d_constellation[47] = gr_complex( 3*level, 5*level);
      d_constellation[48] = gr_complex(-7*level,-3*level);
      d_constellation[49] = gr_complex( 7*level,-3*level);
      d_constellation[50] = gr_complex(-1*level,-3*level);
      d_constellation[51] = gr_complex( 1*level,-3*level);
      d_constellation[52] = gr_complex(-5*level,-3*level);
      d_constellation[53] = gr_complex( 5*level,-3*level);
      d_constellation[54] = gr_complex(-3*level,-3*level);
      d_constellation[55] = gr_complex( 3*level,-3*level);
      d_constellation[56] = gr_complex(-7*level, 3*level);
      d_constellation[57] = gr_complex( 7*level, 3*level);
      d_constellation[58] = gr_c0omplex(-1*level, 3*level);
      d_constellation[59] = gr_complex( 1*level, 3*level);
      d_constellation[60] = gr_complex(-5*level, 3*level);
      d_constellation[61] = gr_complex( 5*level, 3*level);
      d_constellation[62] = gr_complex(-3*level, 3*level);
      d_constellation[63] = gr_complex( 3*level, 3*level);
      */
    }
  } /* namespace demapping */
} /* namespace gr */
