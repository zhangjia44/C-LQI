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


#ifndef INCLUDED_DEMAPPING_MY_DEMAPPING_64_H
#define INCLUDED_DEMAPPING_MY_DEMAPPING_64_H

#include <demapping/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace demapping {

    /*!
     * \brief <+description of block+>
     * \ingroup demapping
     *
     */
    class DEMAPPING_API my_demapping_64 : virtual public gr::block
    {
     public:
      typedef boost::shared_ptr<my_demapping_64> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of demapping::my_demapping_64.
       *
       * To avoid accidental use of raw pointers, demapping::my_demapping_64's
       * constructor is in a private implementation
       * class. demapping::my_demapping_64::make is the public interface for
       * creating new instances.
       */
      static sptr make(int carrier_number);
    };

  } // namespace demapping
} // namespace gr

#endif /* INCLUDED_DEMAPPING_MY_DEMAPPING_64_H */

