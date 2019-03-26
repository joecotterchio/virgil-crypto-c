//  @license
// --------------------------------------------------------------------------
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
// --------------------------------------------------------------------------
// clang-format off


//  @description
// --------------------------------------------------------------------------
//  This module contains 'iotelic public key' implementation.
// --------------------------------------------------------------------------


//  @warning
// --------------------------------------------------------------------------
//  This file is partially generated.
//  Generated blocks are enclosed between tags [@<tag>, @end].
//  User's code can be added between tags [@end, @<tag>].
// --------------------------------------------------------------------------

#include "vscf_iotelic_public_key.h"
#include "vscf_assert.h"
#include "vscf_memory.h"
#include "vscf_iotelic_public_key_defs.h"
#include "vscf_iotelic_public_key_internal.h"

#include <iotelic_sp_interface.h>

// clang-format on
//  @end


//  @generated
// --------------------------------------------------------------------------
// clang-format off
//  Generated section start.
// --------------------------------------------------------------------------


// --------------------------------------------------------------------------
//  Generated section end.
// clang-format on
// --------------------------------------------------------------------------
//  @end


//
//  Provides initialization of the implementation specific context.
//  Note, this method is called automatically when method vscf_iotelic_public_key_init() is called.
//  Note, that context is already zeroed.
//
VSCF_PRIVATE void
vscf_iotelic_public_key_init_ctx(vscf_iotelic_public_key_t *self) {

    //  TODO: This is STUB. Implement me.
}

//
//  Release resources of the implementation specific context.
//  Note, this method is called automatically once when class is completely cleaning up.
//  Note, that context will be zeroed automatically next this method.
//
VSCF_PRIVATE void
vscf_iotelic_public_key_cleanup_ctx(vscf_iotelic_public_key_t *self) {

    //  TODO: This is STUB. Implement me.
}

//
//  Provide algorithm identificator.
//
VSCF_PUBLIC vscf_alg_id_t
vscf_iotelic_public_key_alg_id(const vscf_iotelic_public_key_t *self) {

    //  TODO: This is STUB. Implement me.
}

//
//  Produce object with algorithm information and configuration parameters.
//
VSCF_PUBLIC vscf_impl_t *
vscf_iotelic_public_key_produce_alg_info(const vscf_iotelic_public_key_t *self) {

    //  TODO: This is STUB. Implement me.
}

//
//  Restore algorithm configuration from the given object.
//
VSCF_PUBLIC vscf_error_t
vscf_iotelic_public_key_restore_alg_info(vscf_iotelic_public_key_t *self, const vscf_impl_t *alg_info) {

    //  TODO: This is STUB. Implement me.
}

//
//  Length of the key in bytes.
//
VSCF_PUBLIC size_t
vscf_iotelic_public_key_key_len(const vscf_iotelic_public_key_t *self) {

    //  TODO: This is STUB. Implement me.
}

//
//  Length of the key in bits.
//
VSCF_PUBLIC size_t
vscf_iotelic_public_key_key_bitlen(const vscf_iotelic_public_key_t *self) {

    //  TODO: This is STUB. Implement me.
}

//
//  Verify data with given public key and signature.
//
VSCF_PUBLIC bool
vscf_iotelic_public_key_verify(vscf_iotelic_public_key_t *self, vsc_data_t data, vsc_data_t signature) {

    //  TODO: This is STUB. Implement me.
}

//
//  Export public key in the binary format.
//
//  Binary format must be defined in the key specification.
//  For instance, RSA public key must be exported in format defined in
//  RFC 3447 Appendix A.1.1.
//
VSCF_PUBLIC vscf_error_t
vscf_iotelic_public_key_export_public_key(const vscf_iotelic_public_key_t *self, vsc_buffer_t *out) {

    //  TODO: This is STUB. Implement me.
}

//
//  Return length in bytes required to hold exported public key.
//
VSCF_PUBLIC size_t
vscf_iotelic_public_key_exported_public_key_len(const vscf_iotelic_public_key_t *self) {

    //  TODO: This is STUB. Implement me.
}

//
//  Import public key from the binary format.
//
//  Binary format must be defined in the key specification.
//  For instance, RSA public key must be imported from the format defined in
//  RFC 3447 Appendix A.1.1.
//
VSCF_PUBLIC vscf_error_t
vscf_iotelic_public_key_import_public_key(vscf_iotelic_public_key_t *self, vsc_data_t data) {

    //  TODO: This is STUB. Implement me.
}
