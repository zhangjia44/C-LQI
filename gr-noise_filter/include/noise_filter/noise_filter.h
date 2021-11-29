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


#ifndef INCLUDED_NOISE_FILTER_NOISE_FILTER_H
#define INCLUDED_NOISE_FILTER_NOISE_FILTER_H

#include <noise_filter/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace noise_filter {

    /*!
     * \brief <+description of block+>
     * \ingroup noise_filter
     *
     */
    class NOISE_FILTER_API noise_filter : virtual public gr::block
    {
     public:
      typedef boost::shared_ptr<noise_filter> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of noise_filter::noise_filter.
       *
       * To avoid accidental use of raw pointers, noise_filter::noise_filter's
       * constructor is in a private implementation
       * class. noise_filter::noise_filter::make is the public interface for
       * creating new instances.
       */
      static sptr make(float threshold);
    };

  } // namespace noise_filter
} // namespace gr

#endif /* INCLUDED_NOISE_FILTER_NOISE_FILTER_H */

