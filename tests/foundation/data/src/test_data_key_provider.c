//  Copyright (C) 2015-2019 Virgil Security, Inc.
//
//  All rights reserved.
//
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions are
//  met:
//
//      (1) Redistributions of source code must retain the above copyright
//      notice, this list of conditions and the following disclaimer.
//
//      (2) Redistributions in binary form must reproduce the above copyright
//      notice, this list of conditions and the following disclaimer in
//      the documentation and/or other materials provided with the
//      distribution.
//
//      (3) Neither the name of the copyright holder nor the names of its
//      contributors may be used to endorse or promote products derived from
//      this software without specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE AUTHOR ''AS IS'' AND ANY EXPRESS OR
//  IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
//  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
//  DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
//  INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
//  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
//  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
//  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
//  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
//  IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
//  POSSIBILITY OF SUCH DAMAGE.
//
//  Lead Maintainer: Virgil Security Inc. <support@virgilsecurity.com>


#include "vsc_data.h"

const byte MESSAGE_SHA512_DIGEST[] = {
    0x6d, 0x49, 0xd5, 0xe3, 0x4a, 0xd7, 0xa0, 0x35,
    0x9f, 0xb0, 0x06, 0x28, 0xaa, 0xcd, 0x41, 0xda,
    0x3c, 0x62, 0x34, 0x1e, 0xf2, 0x04, 0x00, 0x8e,
    0xa8, 0x7d, 0x40, 0x72, 0x9a, 0xa5, 0xfb, 0xd8,
    0x1c, 0xc1, 0x80, 0x97, 0x62, 0xa8, 0x05, 0x11,
    0x85, 0x26, 0x4d, 0xb0, 0x94, 0x04, 0x4e, 0xf8,
    0xe1, 0x2c, 0x4b, 0x27, 0x78, 0x1d, 0xe5, 0x58,
    0xf3, 0x97, 0xda, 0xa2, 0x07, 0x8c, 0x56, 0x8d,
};

const vsc_data_t test_key_provider_MESSAGE_SHA512_DIGEST = {
    MESSAGE_SHA512_DIGEST, sizeof(MESSAGE_SHA512_DIGEST)
};

const byte INVALID_KEY_VALID_MESSAGE_INFO_WITH_ENCRYPTED_DATA[] = {
    0x30, 0x82, 0x01, 0xe1, 0x02, 0x01, 0x00, 0x30,
    0x82, 0x01, 0x3f, 0x06, 0x09, 0x2a, 0x86, 0x48,
    0x86, 0xf7, 0x0d, 0x01, 0x07, 0x03, 0xa0, 0x82,
    0x01, 0x30, 0x30, 0x82, 0x01, 0x2c, 0x02, 0x01,
    0x02, 0x31, 0x81, 0xfe, 0x30, 0x81, 0xfb, 0x02,
    0x01, 0x02, 0xa0, 0x0a, 0x04, 0x08, 0x43, 0x28,
    0x8b, 0x2d, 0x8b, 0xfc, 0x1d, 0x68, 0x30, 0x05,
    0x06, 0x03, 0x2b, 0x65, 0x70, 0x04, 0x81, 0xe2,
    0x30, 0x81, 0xdf, 0x02, 0x01, 0x00, 0x30, 0x2a,
    0x30, 0x05, 0x06, 0x03, 0x2b, 0x65, 0x70, 0x03,
    0x21, 0x00, 0xdb, 0x8d, 0x9b, 0xea, 0x13, 0x6b,
    0x01, 0x42, 0xc8, 0x18, 0x3e, 0x59, 0x21, 0x64,
    0xc9, 0x3d, 0xfd, 0x28, 0xa7, 0x05, 0xe0, 0x7f,
    0x9c, 0xf8, 0x2b, 0x3a, 0xc7, 0x3e, 0xd0, 0x79,
    0x00, 0x70, 0x30, 0x18, 0x06, 0x07, 0x28, 0x81,
    0x8c, 0x71, 0x02, 0x05, 0x02, 0x30, 0x0d, 0x06,
    0x09, 0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04,
    0x02, 0x02, 0x05, 0x00, 0x30, 0x41, 0x30, 0x0d,
    0x06, 0x09, 0x60, 0x86, 0x48, 0x01, 0x65, 0x03,
    0x04, 0x02, 0x02, 0x05, 0x00, 0x04, 0x30, 0xe4,
    0xd0, 0x6c, 0x2d, 0xc2, 0xdb, 0x61, 0xd4, 0x64,
    0xc5, 0x3a, 0x8a, 0x29, 0x60, 0x8b, 0x77, 0xc6,
    0xe4, 0x0a, 0x13, 0x76, 0x6f, 0x7a, 0x2e, 0x8f,
    0x4e, 0xba, 0xa9, 0x9a, 0x09, 0xed, 0x28, 0x48,
    0xab, 0xad, 0xbf, 0x27, 0xa6, 0xd8, 0xee, 0x4b,
    0x3b, 0x61, 0xe1, 0x19, 0x28, 0x27, 0x07, 0x30,
    0x51, 0x30, 0x1d, 0x06, 0x09, 0x60, 0x86, 0x48,
    0x01, 0x65, 0x03, 0x04, 0x01, 0x2a, 0x04, 0x10,
    0xee, 0x76, 0x33, 0xe1, 0xee, 0xa6, 0xad, 0x90,
    0x38, 0xa3, 0x79, 0x03, 0x70, 0xd2, 0xec, 0x72,
    0x04, 0x30, 0x49, 0x8c, 0x55, 0xd5, 0x23, 0xe1,
    0x8f, 0x56, 0x11, 0xb1, 0x7f, 0x63, 0xaf, 0xe4,
    0xb9, 0xd4, 0x42, 0x84, 0x89, 0x85, 0x59, 0x04,
    0xe6, 0xb4, 0x35, 0x6b, 0x95, 0xb2, 0x6d, 0xd9,
    0x80, 0x25, 0xab, 0x3d, 0x40, 0x30, 0x68, 0xbe,
    0xa8, 0x7f, 0xe6, 0x15, 0x5e, 0xf8, 0x37, 0x22,
    0xc9, 0xa0, 0x30, 0x26, 0x06, 0x09, 0x2a, 0x86,
    0x48, 0x86, 0xf7, 0x0d, 0x01, 0x07, 0x01, 0x30,
    0x19, 0x06, 0x09, 0x60, 0x86, 0x48, 0x01, 0x65,
    0x03, 0x04, 0x01, 0x2e, 0x04, 0x0c, 0xa2, 0xed,
    0xd1, 0x5e, 0xf2, 0x2b, 0x22, 0x1d, 0xd6, 0x0f,
    0x81, 0x97, 0xa0, 0x81, 0x98, 0x31, 0x81, 0x95,
    0x30, 0x23, 0x0c, 0x15, 0x56, 0x49, 0x52, 0x47,
    0x49, 0x4c, 0x2d, 0x44, 0x41, 0x54, 0x41, 0x2d,
    0x53, 0x49, 0x47, 0x4e, 0x45, 0x52, 0x2d, 0x49,
    0x44, 0xa2, 0x0a, 0x04, 0x08, 0x43, 0x28, 0x8b,
    0x2d, 0x8b, 0xfc, 0x1d, 0x68, 0x30, 0x6e, 0x0c,
    0x15, 0x56, 0x49, 0x52, 0x47, 0x49, 0x4c, 0x2d,
    0x44, 0x41, 0x54, 0x41, 0x2d, 0x53, 0x49, 0x47,
    0x4e, 0x41, 0x54, 0x55, 0x52, 0x45, 0xa2, 0x55,
    0x04, 0x53, 0x30, 0x51, 0x30, 0x0d, 0x06, 0x09,
    0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x02,
    0x03, 0x05, 0x00, 0x04, 0x40, 0x9c, 0xd2, 0x0b,
    0x3c, 0x48, 0x48, 0x64, 0x30, 0x75, 0x4b, 0x46,
    0x0b, 0x0a, 0x51, 0xa1, 0x69, 0xb8, 0x7d, 0xe7,
    0xfd, 0xa8, 0xf2, 0xf7, 0x0b, 0xcb, 0x71, 0x92,
    0x0c, 0x60, 0xd0, 0x8c, 0x22, 0x93, 0x69, 0x87,
    0xa5, 0xb6, 0x80, 0xcf, 0xf0, 0xab, 0xa9, 0x25,
    0x89, 0x0c, 0xcd, 0xd6, 0x43, 0x98, 0x0c, 0x05,
    0x15, 0xc3, 0x4c, 0x3e, 0x79, 0x9a, 0x8f, 0x57,
    0x88, 0x6b, 0x7e, 0xd5, 0x09, 0x0b, 0x78, 0x88,
    0x15, 0x78, 0xea, 0xf8, 0x50, 0x53, 0xc9, 0x11,
    0xe1, 0x1d, 0x51, 0x7a, 0x5e, 0x28, 0x3a, 0x72,
    0x2b, 0x41, 0x03, 0x59, 0xea, 0xca, 0xa3, 0x1c,
    0x10, 0xfd, 0x26, 0x2b, 0x3e, 0x66, 0x22, 0x7f,
    0x03, 0x1e, 0x41, 0xc0, 0x20, 0x60, 0xad, 0x83,
    0x88, 0xda, 0xcd, 0xd3, 0x99, 0x0d, 0x4d, 0xf0,
    0xb4, 0xe0, 0x47, 0xf0, 0x34, 0x88, 0xac, 0x58,
    0xa5, 0x9d, 0x01, 0xd5, 0x3d
};

const vsc_data_t test_key_provider_INVALID_KEY_VALID_MESSAGE_INFO_WITH_ENCRYPTED_DATA = {
    INVALID_KEY_VALID_MESSAGE_INFO_WITH_ENCRYPTED_DATA, sizeof(INVALID_KEY_VALID_MESSAGE_INFO_WITH_ENCRYPTED_DATA)
};

const byte INVALID_KEY_VALID_MESSAGE_INFO[]= {
    0x30, 0x82, 0x01, 0xE1, 0x02, 0x01, 0x00, 0x30,
    0x82, 0x01, 0x3F, 0x06, 0x09, 0x2A, 0x86, 0x48,
    0x86, 0xF7, 0x0D, 0x01, 0x07, 0x03, 0xA0, 0x82,
    0x01, 0x30, 0x30, 0x82, 0x01, 0x2C, 0x02, 0x01,
    0x02, 0x31, 0x81, 0xFE, 0x30, 0x81, 0xFB, 0x02,
    0x01, 0x02, 0xA0, 0x0A, 0x04, 0x08, 0x43, 0x28,
    0x8B, 0x2D, 0x8B, 0xFC, 0x1D, 0x68, 0x30, 0x05,
    0x06, 0x03, 0x2B, 0x65, 0x70, 0x04, 0x81, 0xE2,
    0x30, 0x81, 0xDF, 0x02, 0x01, 0x00, 0x30, 0x2A,
    0x30, 0x05, 0x06, 0x03, 0x2B, 0x65, 0x70, 0x03,
    0x21, 0x00, 0xDB, 0x8D, 0x9B, 0xEA, 0x13, 0x6B,
    0x01, 0x42, 0xC8, 0x18, 0x3E, 0x59, 0x21, 0x64,
    0xC9, 0x3D, 0xFD, 0x28, 0xA7, 0x05, 0xE0, 0x7F,
    0x9C, 0xF8, 0x2B, 0x3A, 0xC7, 0x3E, 0xD0, 0x79,
    0x00, 0x70, 0x30, 0x18, 0x06, 0x07, 0x28, 0x81,
    0x8C, 0x71, 0x02, 0x05, 0x02, 0x30, 0x0D, 0x06,
    0x09, 0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04,
    0x02, 0x02, 0x05, 0x00, 0x30, 0x41, 0x30, 0x0D,
    0x06, 0x09, 0x60, 0x86, 0x48, 0x01, 0x65, 0x03,
    0x04, 0x02, 0x02, 0x05, 0x00, 0x04, 0x30, 0xE4,
    0xD0, 0x6C, 0x2D, 0xC2, 0xDB, 0x61, 0xD4, 0x64,
    0xC5, 0x3A, 0x8A, 0x29, 0x60, 0x8B, 0x77, 0xC6,
    0xE4, 0x0A, 0x13, 0x76, 0x6F, 0x7A, 0x2E, 0x8F,
    0x4E, 0xBA, 0xA9, 0x9A, 0x09, 0xED, 0x28, 0x48,
    0xAB, 0xAD, 0xBF, 0x27, 0xA6, 0xD8, 0xEE, 0x4B,
    0x3B, 0x61, 0xE1, 0x19, 0x28, 0x27, 0x07, 0x30,
    0x51, 0x30, 0x1D, 0x06, 0x09, 0x60, 0x86, 0x48,
    0x01, 0x65, 0x03, 0x04, 0x01, 0x2A, 0x04, 0x10,
    0xEE, 0x76, 0x33, 0xE1, 0xEE, 0xA6, 0xAD, 0x90,
    0x38, 0xA3, 0x79, 0x03, 0x70, 0xD2, 0xEC, 0x72,
    0x04, 0x30, 0x49, 0x8C, 0x55, 0xD5, 0x23, 0xE1,
    0x8F, 0x56, 0x11, 0xB1, 0x7F, 0x63, 0xAF, 0xE4,
    0xB9, 0xD4, 0x42, 0x84, 0x89, 0x85, 0x59, 0x04,
    0xE6, 0xB4, 0x35, 0x6B, 0x95, 0xB2, 0x6D, 0xD9,
    0x80, 0x25, 0xAB, 0x3D, 0x40, 0x30, 0x68, 0xBE,
    0xA8, 0x7F, 0xE6, 0x15, 0x5E, 0xF8, 0x37, 0x22,
    0xC9, 0xA0, 0x30, 0x26, 0x06, 0x09, 0x2A, 0x86,
    0x48, 0x86, 0xF7, 0x0D, 0x01, 0x07, 0x01, 0x30,
    0x19, 0x06, 0x09, 0x60, 0x86, 0x48, 0x01, 0x65,
    0x03, 0x04, 0x01, 0x2E, 0x04, 0x0C, 0xA2, 0xED,
    0xD1, 0x5E, 0xF2, 0x2B, 0x22, 0x1D, 0xD6, 0x0F,
    0x81, 0x97, 0xA0, 0x81, 0x98, 0x31, 0x81, 0x95,
    0x30, 0x23, 0x0C, 0x15, 0x56, 0x49, 0x52, 0x47,
    0x49, 0x4C, 0x2D, 0x44, 0x41, 0x54, 0x41, 0x2D,
    0x53, 0x49, 0x47, 0x4E, 0x45, 0x52, 0x2D, 0x49,
    0x44, 0xA2, 0x0A, 0x04, 0x08, 0x43, 0x28, 0x8B,
    0x2D, 0x8B, 0xFC, 0x1D, 0x68, 0x30, 0x6E, 0x0C,
    0x15, 0x56, 0x49, 0x52, 0x47, 0x49, 0x4C, 0x2D,
    0x44, 0x41, 0x54, 0x41, 0x2D, 0x53, 0x49, 0x47,
    0x4E, 0x41, 0x54, 0x55, 0x52, 0x45, 0xA2, 0x55,
    0x04, 0x53, 0x30, 0x51, 0x30, 0x0D, 0x06, 0x09,
    0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x02,
    0x03, 0x05, 0x00, 0x04, 0x40, 0x9C, 0xD2, 0x0B,
    0x3C, 0x48, 0x48, 0x64, 0x30, 0x75, 0x4B, 0x46,
    0x0B, 0x0A, 0x51, 0xA1, 0x69, 0xB8, 0x7D, 0xE7,
    0xFD, 0xA8, 0xF2, 0xF7, 0x0B, 0xCB, 0x71, 0x92,
    0x0C, 0x60, 0xD0, 0x8C, 0x22, 0x93, 0x69, 0x87,
    0xA5, 0xB6, 0x80, 0xCF, 0xF0, 0xAB, 0xA9, 0x25,
    0x89, 0x0C, 0xCD, 0xD6, 0x43, 0x98, 0x0C, 0x05,
    0x15, 0xC3, 0x4C, 0x3E, 0x79, 0x9A, 0x8F, 0x57,
    0x88, 0x6B, 0x7E, 0xD5, 0x09
};

const vsc_data_t test_key_provider_INVALID_KEY_VALID_MESSAGE_INFO = {
    INVALID_KEY_VALID_MESSAGE_INFO, sizeof(INVALID_KEY_VALID_MESSAGE_INFO)
};
