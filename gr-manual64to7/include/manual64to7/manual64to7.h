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


#ifndef INCLUDED_MANUAL64TO7_MANUAL64TO7_H
#define INCLUDED_MANUAL64TO7_MANUAL64TO7_H

#include <manual64to7/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace manual64to7 {

    /*!
     * \brief <+description of block+>
     * \ingroup manual64to7
     *
     */
    class MANUAL64TO7_API manual64to7 : virtual public gr::block
    {
     public:
      typedef boost::shared_ptr<manual64to7> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of manual64to7::manual64to7.
       *
       * To avoid accidental use of raw pointers, manual64to7::manual64to7's
       * constructor is in a private implementation
       * class. manual64to7::manual64to7::make is the public interface for
       * creating new instances.
       */
      static sptr make();
    };

  } // namespace manual64to7
} // namespace gr

#endif /* INCLUDED_MANUAL64TO7_MANUAL64TO7_H */

