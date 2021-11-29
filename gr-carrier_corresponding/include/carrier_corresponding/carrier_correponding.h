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


#ifndef INCLUDED_CARRIER_CORRESPONDING_CARRIER_CORREPONDING_H
#define INCLUDED_CARRIER_CORRESPONDING_CARRIER_CORREPONDING_H

#include <carrier_corresponding/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace carrier_corresponding {

    /*!
     * \brief <+description of block+>
     * \ingroup carrier_corresponding
     *
     */
    class CARRIER_CORRESPONDING_API carrier_correponding : virtual public gr::block
    {
     public:
      typedef boost::shared_ptr<carrier_correponding> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of carrier_corresponding::carrier_correponding.
       *
       * To avoid accidental use of raw pointers, carrier_corresponding::carrier_correponding's
       * constructor is in a private implementation
       * class. carrier_corresponding::carrier_correponding::make is the public interface for
       * creating new instances.
       */
      static sptr make();
    };

  } // namespace carrier_corresponding
} // namespace gr

#endif /* INCLUDED_CARRIER_CORRESPONDING_CARRIER_CORREPONDING_H */

