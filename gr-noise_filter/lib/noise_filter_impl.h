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

#ifndef INCLUDED_NOISE_FILTER_NOISE_FILTER_IMPL_H
#define INCLUDED_NOISE_FILTER_NOISE_FILTER_IMPL_H

#include <noise_filter/noise_filter.h>

namespace gr {
  namespace noise_filter {

    class noise_filter_impl : public noise_filter
    {
     private:
      // Nothing to declare in this block.
      int d_plateau;
      int d_state;
      int d_cnt;
      float d_threshold;
     public:
      noise_filter_impl(float threshold);
      ~noise_filter_impl();

      // Where all the action really happens
      void forecast (int noutput_items, gr_vector_int &ninput_items_required);

      int general_work(int noutput_items,
           gr_vector_int &ninput_items,
           gr_vector_const_void_star &input_items,
           gr_vector_void_star &output_items);
    };

  } // namespace noise_filter
} // namespace gr

#endif /* INCLUDED_NOISE_FILTER_NOISE_FILTER_IMPL_H */
