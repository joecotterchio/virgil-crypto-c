//  @license
// --------------------------------------------------------------------------
//  Copyright (C) 2015-2018 Virgil Security Inc.
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
//  This module contains 'ctr drbg' implementation.
// --------------------------------------------------------------------------


//  @warning
// --------------------------------------------------------------------------
//  This file is partially generated.
//  Generated blocks are enclosed between tags [@<tag>, @end].
//  User's code can be added between tags [@end, @<tag>].
// --------------------------------------------------------------------------

#include "vscf_ctr_drbg.h"
#include "vscf_assert.h"
#include "vscf_memory.h"
#include "vscf_entropy_source.h"
#include "vscf_ctr_drbg_impl.h"
#include "vscf_ctr_drbg_internal.h"

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
//  Note, this method is called automatically when method vscf_ctr_drbg_init() is called.
//  Note, that context is already zeroed.
//
VSCF_PRIVATE void
vscf_ctr_drbg_init_ctx(vscf_ctr_drbg_impl_t *ctr_drbg_impl) {

    VSCF_ASSERT_PTR(ctr_drbg_impl);

    mbedtls_ctr_drbg_init(&ctr_drbg_impl->ctx);
}

//
//  Release resources of the implementation specific context.
//  Note, this method is called automatically once when class is completely cleaning up.
//  Note, that context will be zeroed automatically next this method.
//
VSCF_PRIVATE void
vscf_ctr_drbg_cleanup_ctx(vscf_ctr_drbg_impl_t *ctr_drbg_impl) {

    VSCF_ASSERT_PTR(ctr_drbg_impl);

    mbedtls_ctr_drbg_free(&ctr_drbg_impl->ctx);
}

//
//  Force entropy to be gathered at the beginning of every call to
//  the (.class_ctr_drbg_method_random)() method.
//  Note, use this if your entropy source has sufficient throughput.
//
VSCF_PUBLIC void
vscf_ctr_drbg_enable_prediction_resistance(vscf_ctr_drbg_impl_t *ctr_drbg_impl) {

    VSCF_ASSERT_PTR(ctr_drbg_impl);

    mbedtls_ctr_drbg_set_prediction_resistance(&ctr_drbg_impl->ctx, 1);
}

//
//  Sets the reseed interval.
//  Default value is reseed interval.
//
VSCF_PUBLIC void
vscf_ctr_drbg_set_reseed_interval(vscf_ctr_drbg_impl_t *ctr_drbg_impl, size_t interval) {

    VSCF_ASSERT_PTR(ctr_drbg_impl);
    VSCF_ASSERT(interval < INT_MAX);

    mbedtls_ctr_drbg_set_reseed_interval(&ctr_drbg_impl->ctx, (int)interval);
}

//
//  Sets the amount of entropy grabbed on each seed or reseed.
//  The default value is entropy len.
//
VSCF_PUBLIC void
vscf_ctr_drbg_set_entropy_len(vscf_ctr_drbg_impl_t *ctr_drbg_impl, size_t len) {

    VSCF_ASSERT_PTR(ctr_drbg_impl);
    VSCF_ASSERT(len < INT_MAX);

    mbedtls_ctr_drbg_set_entropy_len(&ctr_drbg_impl->ctx, (int)len);
}

//
//  Generate random bytes.
//
VSCF_PUBLIC vscf_error_t
vscf_ctr_drbg_random(vscf_ctr_drbg_impl_t *ctr_drbg_impl, size_t data_len, vsc_buffer_t *data) {

    VSCF_ASSERT_PTR(ctr_drbg_impl);
    VSCF_ASSERT(data_len > 0);
    VSCF_ASSERT_PTR(data);
    VSCF_ASSERT(vsc_buffer_left(data) >= data_len);

    int result = mbedtls_ctr_drbg_random(&ctr_drbg_impl->ctx, vsc_buffer_ptr(data), vsc_buffer_left(data));
    switch (result) {
    case 0:
        vsc_buffer_reserve(data, data_len);
        return vscf_SUCCESS;

    case MBEDTLS_ERR_CTR_DRBG_ENTROPY_SOURCE_FAILED:
        return vscf_error_ENTROPY_SOURCE_FAILED;

    case MBEDTLS_ERR_CTR_DRBG_REQUEST_TOO_BIG:
        return vscf_error_RNG_REQUESTED_DATA_TOO_BIG;

    default:
        // VSCF_ASSERT_UNHANDLED_ERROR(result);
        return vscf_error_UNHANDLED_THIRDPARTY_ERROR;
    }
}

//
//  Retreive new seed data from the entropy sources.
//
VSCF_PUBLIC void
vscf_ctr_drbg_reseed(vscf_ctr_drbg_impl_t *ctr_drbg_impl) {

    VSCF_ASSERT_PTR(ctr_drbg_impl);

    mbedtls_ctr_drbg_reseed(&ctr_drbg_impl->ctx, NULL, 0);
}
