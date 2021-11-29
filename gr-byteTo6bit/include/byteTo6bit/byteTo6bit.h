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


#ifndef INCLUDED_BYTETO6BIT_BYTETO6BIT_H
#define INCLUDED_BYTETO6BIT_BYTETO6BIT_H

#include <byteTo6bit/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace byteTo6bit {

    /*!
     * \brief <+description of block+>
     * \ingroup byteTo6bit
     *
     */
    class BYTETO6BIT_API byteTo6bit : virtual public gr::block
    {
     public:
      typedef boost::shared_ptr<byteTo6bit> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of byteTo6bit::byteTo6bit.
       *
       * To avoid accidental use of raw pointers, byteTo6bit::byteTo6bit's
       * constructor is in a private implementation
       * class. byteTo6bit::byteTo6bit::make is the public interface for
       * creating new instances.
       */
      static sptr make();
    };

  } // namespace byteTo6bit
} // namespace gr

#endif /* INCLUDED_BYTETO6BIT_BYTETO6BIT_H */

