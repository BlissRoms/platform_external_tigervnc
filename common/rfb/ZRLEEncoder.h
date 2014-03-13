/* Copyright (C) 2002-2005 RealVNC Ltd.  All Rights Reserved.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307,
 * USA.
 */
#ifndef __RFB_ZRLEENCODER_H__
#define __RFB_ZRLEENCODER_H__

#include <rdr/MemOutStream.h>
#include <rdr/ZlibOutStream.h>
#include <rfb/Encoder.h>

namespace rfb {

  class ZRLEEncoder : public Encoder {
  public:
    static Encoder* create(SMsgWriter* writer);
    virtual bool writeRect(const Rect& r, TransImageGetter* ig, Rect* actual);
    virtual ~ZRLEEncoder();

  private:
    ZRLEEncoder(SMsgWriter* writer);
    SMsgWriter* writer;
    rdr::ZlibOutStream zos;
    rdr::MemOutStream mos;
  };
}
#endif
