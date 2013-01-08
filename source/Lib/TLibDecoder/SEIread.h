/* The copyright in this software is being made available under the BSD
 * License, included below. This software may be subject to other third party
 * and contributor rights, including patent rights, and no such rights are
 * granted under this license.
 *
 * Copyright (c) 2010-2012, ITU/ISO/IEC
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  * Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *  * Neither the name of the ITU/ISO/IEC nor the names of its contributors may
 *    be used to endorse or promote products derived from this software without
 *    specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 \file     SEIread.h
 \brief    reading funtionality for SEI messages
 */

#ifndef __SEIREAD__
#define __SEIREAD__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//! \ingroup TLibDecoder
//! \{

#include "TLibCommon/SEI.h"
class TComInputBitstream;
class SEImessages;


class SEIReader: public SyntaxElementParser
{
public:
  SEIReader() {};
  virtual ~SEIReader() {};
#if SUFFIX_SEI_NUT_DECODED_HASH_SEI
  Void parseSEImessage(TComInputBitstream* bs, SEImessages& seis, const NalUnitType nalUnitType);
#else
  Void parseSEImessage(TComInputBitstream* bs, SEImessages& seis);
#endif
protected:
#if SUFFIX_SEI_NUT_DECODED_HASH_SEI
  Void xReadSEImessage                (SEImessages& seis, const NalUnitType nalUnitType);
#else
  Void xReadSEImessage                (SEImessages& seis);
#endif
  Void xParseSEIuserDataUnregistered  (SEIuserDataUnregistered &sei, UInt payloadSize);
  Void xParseSEIActiveParameterSets   (SEIActiveParameterSets  &sei, UInt payloadSize);
  Void xParseSEIDecodedPictureHash    (SEIDecodedPictureHash& sei, UInt payloadSize);
  Void xParseSEIBufferingPeriod       (SEIBufferingPeriod& sei, UInt payloadSize);
  Void xParseSEIPictureTiming         (SEIPictureTiming& sei, UInt payloadSize);
  Void xParseSEIRecoveryPoint         (SEIRecoveryPoint& sei, UInt payloadSize);
  Void xParseSEIFramePacking          (SEIFramePacking& sei, UInt payloadSize);
#if SEI_DISPLAY_ORIENTATION
  Void xParseSEIDisplayOrientation    (SEIDisplayOrientation &sei, UInt payloadSize);
#endif
#if SEI_TEMPORAL_LEVEL0_INDEX
  Void xParseSEITemporalLevel0Index   (SEITemporalLevel0Index &sei, UInt payloadSize);
#endif
#if SEI_GDR_INFO
  Void xParseSEIGradualDecodingRefreshInfo (SEIGradualDecodingRefreshInfo &sei, UInt payloadSize);
#endif
  Void xParseByteAlign();
};


//! \}

#endif
