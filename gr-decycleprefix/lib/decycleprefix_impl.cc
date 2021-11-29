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
#include "decycleprefix_impl.h"

namespace gr {
  namespace decycleprefix {

    decycleprefix::sptr
    decycleprefix::make()
    {
      return gnuradio::get_initial_sptr
        (new decycleprefix_impl());
    }

    /*
     * The private constructor
     */
    decycleprefix_impl::decycleprefix_impl()
      : gr::block("decycleprefix",
              gr::io_signature::make(1, 1, 80 * sizeof(gr_complex)),
              gr::io_signature::make(1, 1, 64 * sizeof(gr_complex))),
              count(0)
    {}

    /*
     * Our virtual destructor.
     */
    decycleprefix_impl::~decycleprefix_impl()
    {
    }

    void
    decycleprefix_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
    {
      /* <+forecast+> e.g. ninput_items_required[0] = noutput_items */
    }

    int
    decycleprefix_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
      const gr_complex *in = (const gr_complex *) input_items[0];
      gr_complex *out = (gr_complex *) output_items[0];

      int i = 0;
      int o = 0;
      gr_complex output[80];
      while(i < ninput_items[0] && o < noutput_items)
      {
        //cut 4/5
        //memcpy(out + o * 64, in + i * 80 + 16, 64 * sizeof(gr_complex));

        //optimize the CP

        memcpy(output, in + i * 80, 80 * sizeof(gr_complex));
        if((count % 4 == 1) || (count % 4 == 3))
        {
          //copy the first 1/5 to the end 1/5
          for(int j = 0; j < 16; j++)
            output[j + 64] = output[j];
        }
        memcpy(out + o * 64, output + 16, 64 * sizeof(gr_complex));

        i++;
        o++;
        count++;
      }
      // Do <+signal processing+>
      // Tell runtime system how many input items we consumed on
      // each input stream.
      consume_each (i);

      // Tell runtime system how many output items we produced.
      return o;
    }

  } /* namespace decycleprefix */
} /* namespace gr */
