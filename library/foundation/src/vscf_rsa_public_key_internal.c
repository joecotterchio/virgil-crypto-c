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


//  @description
// --------------------------------------------------------------------------
//  This module contains logic for interface/implementation architecture.
//  Do not use this module in any part of the code.
// --------------------------------------------------------------------------


//  @warning
// --------------------------------------------------------------------------
//  This file is partially generated.
//  Generated blocks are enclosed between tags [@<tag>, @end].
//  User's code can be added between tags [@end, @<tag>].
// --------------------------------------------------------------------------

#include "vscf_rsa_public_key_internal.h"
#include "vscf_memory.h"
#include "vscf_assert.h"
#include "vscf_rsa_public_key.h"
#include "vscf_rsa_public_key_impl.h"
#include "vscf_key_api.h"
#include "vscf_public_key_api.h"
#include "vscf_encrypt2_api.h"
#include "vscf_verify_api.h"
#include "vscf_export_public_key_api.h"
#include "vscf_import_public_key_api.h"
#include "vscf_hash.h"
#include "vscf_random.h"
#include "vscf_asn1_reader.h"
#include "vscf_asn1_writer.h"
//  @end


//  @generated
// --------------------------------------------------------------------------
// clang-format off
//  Generated section start.
// --------------------------------------------------------------------------

//
//  Configuration of the interface API 'key api'.
//
static const vscf_key_api_t key_api = {
    //
    //  API's unique identifier, MUST be first in the structure.
    //  For interface 'key' MUST be equal to the 'vscf_api_tag_KEY'.
    //
    vscf_api_tag_KEY,
    //
    //  Implementation unique identifier, MUST be second in the structure.
    //
    vscf_impl_tag_RSA_PUBLIC_KEY,
    //
    //  Length of the key in bytes.
    //
    (vscf_key_api_key_len_fn)vscf_rsa_public_key_key_len,
    //
    //  Length of the key in bits.
    //
    (vscf_key_api_key_bitlen_fn)vscf_rsa_public_key_key_bitlen
};

//
//  Configuration of the interface API 'public key api'.
//
static const vscf_public_key_api_t public_key_api = {
    //
    //  API's unique identifier, MUST be first in the structure.
    //  For interface 'public_key' MUST be equal to the 'vscf_api_tag_PUBLIC_KEY'.
    //
    vscf_api_tag_PUBLIC_KEY,
    //
    //  Implementation unique identifier, MUST be second in the structure.
    //
    vscf_impl_tag_RSA_PUBLIC_KEY,
    //
    //  Link to the inherited interface API 'key'.
    //
    &key_api
};

//
//  Configuration of the interface API 'encrypt2 api'.
//
static const vscf_encrypt2_api_t encrypt2_api = {
    //
    //  API's unique identifier, MUST be first in the structure.
    //  For interface 'encrypt2' MUST be equal to the 'vscf_api_tag_ENCRYPT2'.
    //
    vscf_api_tag_ENCRYPT2,
    //
    //  Implementation unique identifier, MUST be second in the structure.
    //
    vscf_impl_tag_RSA_PUBLIC_KEY,
    //
    //  Encrypt given data.
    //
    (vscf_encrypt2_api_encrypt_fn)vscf_rsa_public_key_encrypt,
    //
    //  Calculate required buffer length to hold the encrypted data.
    //
    (vscf_encrypt2_api_encrypted_len_fn)vscf_rsa_public_key_encrypted_len
};

//
//  Configuration of the interface API 'verify api'.
//
static const vscf_verify_api_t verify_api = {
    //
    //  API's unique identifier, MUST be first in the structure.
    //  For interface 'verify' MUST be equal to the 'vscf_api_tag_VERIFY'.
    //
    vscf_api_tag_VERIFY,
    //
    //  Implementation unique identifier, MUST be second in the structure.
    //
    vscf_impl_tag_RSA_PUBLIC_KEY,
    //
    //  Verify data with given public key and signature.
    //
    (vscf_verify_api_verify_fn)vscf_rsa_public_key_verify
};

//
//  Configuration of the interface API 'export public key api'.
//
static const vscf_export_public_key_api_t export_public_key_api = {
    //
    //  API's unique identifier, MUST be first in the structure.
    //  For interface 'export_public_key' MUST be equal to the 'vscf_api_tag_EXPORT_PUBLIC_KEY'.
    //
    vscf_api_tag_EXPORT_PUBLIC_KEY,
    //
    //  Implementation unique identifier, MUST be second in the structure.
    //
    vscf_impl_tag_RSA_PUBLIC_KEY,
    //
    //  Export public key in the binary format.
    //
    (vscf_export_public_key_api_export_public_key_fn)vscf_rsa_public_key_export_public_key,
    //
    //  Return length in bytes required to hold exported public key.
    //
    (vscf_export_public_key_api_exported_public_key_len_fn)vscf_rsa_public_key_exported_public_key_len
};

//
//  Configuration of the interface API 'import public key api'.
//
static const vscf_import_public_key_api_t import_public_key_api = {
    //
    //  API's unique identifier, MUST be first in the structure.
    //  For interface 'import_public_key' MUST be equal to the 'vscf_api_tag_IMPORT_PUBLIC_KEY'.
    //
    vscf_api_tag_IMPORT_PUBLIC_KEY,
    //
    //  Implementation unique identifier, MUST be second in the structure.
    //
    vscf_impl_tag_RSA_PUBLIC_KEY,
    //
    //  Import public key from the binary format.
    //
    (vscf_import_public_key_api_import_public_key_fn)vscf_rsa_public_key_import_public_key
};

//
//  Null-terminated array of the implemented 'Interface API' instances.
//
static const vscf_api_t *api_array[] = {
    (const vscf_api_t *)&key_api,
    (const vscf_api_t *)&public_key_api,
    (const vscf_api_t *)&encrypt2_api,
    (const vscf_api_t *)&verify_api,
    (const vscf_api_t *)&export_public_key_api,
    (const vscf_api_t *)&import_public_key_api,
    NULL
};

//
//  Compile-time known information about 'rsa public key' implementation.
//
static const vscf_impl_info_t info = {
    //
    //  Implementation unique identifier, MUST be first in the structure.
    //
    vscf_impl_tag_RSA_PUBLIC_KEY,
    //
    //  NULL terminated array of the implemented interfaces.
    //  MUST be second in the structure.
    //
    api_array,
    //
    //  Release acquired inner resources.
    //
    (vscf_impl_cleanup_fn)vscf_rsa_public_key_cleanup,
    //
    //  Self destruction, according to destruction policy.
    //
    (vscf_impl_delete_fn)vscf_rsa_public_key_delete
};

//
//  Perform initialization of preallocated implementation context.
//
VSCF_PUBLIC void
vscf_rsa_public_key_init(vscf_rsa_public_key_impl_t *rsa_public_key_impl) {

    VSCF_ASSERT_PTR(rsa_public_key_impl);
    VSCF_ASSERT_PTR(rsa_public_key_impl->info == NULL);

    rsa_public_key_impl->info = &info;

    rsa_public_key_impl->hash = NULL;

    rsa_public_key_impl->random = NULL;

    rsa_public_key_impl->asn1rd = NULL;

    rsa_public_key_impl->asn1wr = NULL;

    rsa_public_key_impl->is_owning_random = false;

    rsa_public_key_impl->is_owning_asn1rd = false;

    rsa_public_key_impl->is_owning_asn1wr = false;

    vscf_rsa_public_key_init_ctx(rsa_public_key_impl);
}

//
//  Cleanup implementation context and it's dependencies.
//  This is a reverse action of the function 'vscf_rsa_public_key_init()'.
//  All dependencies that is under ownership will be destroyed.
//  All dependencies that is not under ownership will untouched.
//
VSCF_PUBLIC void
vscf_rsa_public_key_cleanup(vscf_rsa_public_key_impl_t *rsa_public_key_impl) {

    VSCF_ASSERT_PTR(rsa_public_key_impl);

    if (rsa_public_key_impl->info == NULL) {
        return;
    }

    //   Cleanup dependency: 'random'.
    if (rsa_public_key_impl->random) {

        if (rsa_public_key_impl->is_owning_random) {
            vscf_impl_destroy(&rsa_public_key_impl->random);

        } else {
            rsa_public_key_impl->random = NULL;
        }

        rsa_public_key_impl->is_owning_random = 0;
    }

    //   Cleanup dependency: 'asn1rd'.
    if (rsa_public_key_impl->asn1rd) {

        if (rsa_public_key_impl->is_owning_asn1rd) {
            vscf_impl_destroy(&rsa_public_key_impl->asn1rd);

        } else {
            rsa_public_key_impl->asn1rd = NULL;
        }

        rsa_public_key_impl->is_owning_asn1rd = 0;
    }

    //   Cleanup dependency: 'asn1wr'.
    if (rsa_public_key_impl->asn1wr) {

        if (rsa_public_key_impl->is_owning_asn1wr) {
            vscf_impl_destroy(&rsa_public_key_impl->asn1wr);

        } else {
            rsa_public_key_impl->asn1wr = NULL;
        }

        rsa_public_key_impl->is_owning_asn1wr = 0;
    }

    //   Release dependency: 'hash'.
    if (rsa_public_key_impl->hash) {
        rsa_public_key_impl->hash = NULL;
    }

    vscf_rsa_public_key_cleanup_ctx(rsa_public_key_impl);

    rsa_public_key_impl->info = NULL;
}

//
//  Allocate implementation context and perform it's initialization.
//  Postcondition: check memory allocation result.
//
VSCF_PUBLIC vscf_rsa_public_key_impl_t *
vscf_rsa_public_key_new(void) {

    vscf_rsa_public_key_impl_t *rsa_public_key_impl = (vscf_rsa_public_key_impl_t *) vscf_alloc(sizeof (vscf_rsa_public_key_impl_t));
    VSCF_ASSERT_ALLOC(rsa_public_key_impl);

    vscf_rsa_public_key_init(rsa_public_key_impl);

    rsa_public_key_impl->refcnt = 1;

    return rsa_public_key_impl;
}

//
//  Delete given implementation context and it's dependencies.
//  This is a reverse action of the function 'vscf_rsa_public_key_new()'.
//  All dependencies that is not under ownership will be cleaned up.
//  All dependencies that is under ownership will be destroyed.
//
VSCF_PUBLIC void
vscf_rsa_public_key_delete(vscf_rsa_public_key_impl_t *rsa_public_key_impl) {

    if (rsa_public_key_impl && (--rsa_public_key_impl->refcnt == 0)) {
        vscf_rsa_public_key_cleanup(rsa_public_key_impl);
        vscf_dealloc(rsa_public_key_impl);
    }
}

//
//  Destroy given implementation context and it's dependencies.
//  This is a reverse action of the function 'vscf_rsa_public_key_new()'.
//  All dependencies that is not under ownership will be cleaned up.
//  All dependencies that is under ownership will be destroyed.
//  Given reference is nullified.
//
VSCF_PUBLIC void
vscf_rsa_public_key_destroy(vscf_rsa_public_key_impl_t **rsa_public_key_impl_ref) {

    VSCF_ASSERT_PTR(rsa_public_key_impl_ref);

    vscf_rsa_public_key_impl_t *rsa_public_key_impl = *rsa_public_key_impl_ref;
    *rsa_public_key_impl_ref = NULL;

    vscf_rsa_public_key_delete(rsa_public_key_impl);
}

//
//  Copy given implementation context by increasing reference counter.
//  If deep copy is required interface 'clonable' can be used.
//
VSCF_PUBLIC vscf_rsa_public_key_impl_t *
vscf_rsa_public_key_copy(vscf_rsa_public_key_impl_t *rsa_public_key_impl) {

    // Proxy to the parent implementation.
    return (vscf_rsa_public_key_impl_t *)vscf_impl_copy((vscf_impl_t *)rsa_public_key_impl);
}

//
//  Returns instance of the implemented interface 'public key'.
//
VSCF_PUBLIC const vscf_public_key_api_t *
vscf_rsa_public_key_public_key_api(void) {

    return &public_key_api;
}

//
//  Setup dependency to the interface 'hash' and keep ownership.
//
VSCF_PUBLIC void
vscf_rsa_public_key_use_hash_api(vscf_rsa_public_key_impl_t *rsa_public_key_impl, const vscf_hash_api_t *hash) {

    VSCF_ASSERT_PTR(rsa_public_key_impl);
    VSCF_ASSERT_PTR(hash);
    VSCF_ASSERT_PTR(rsa_public_key_impl->hash == NULL);

    rsa_public_key_impl->hash = hash;
}

//
//  Setup dependency to the interface 'random' and keep ownership.
//
VSCF_PUBLIC void
vscf_rsa_public_key_use_random(vscf_rsa_public_key_impl_t *rsa_public_key_impl, vscf_impl_t *random) {

    VSCF_ASSERT_PTR(rsa_public_key_impl);
    VSCF_ASSERT_PTR(random);
    VSCF_ASSERT_PTR(rsa_public_key_impl->random == NULL);

    VSCF_ASSERT(vscf_random_is_implemented(random));

    rsa_public_key_impl->random = random;

    rsa_public_key_impl->is_owning_random = 0;
}

//
//  Setup dependency to the interface 'random' and transfer ownership.
//
VSCF_PUBLIC void
vscf_rsa_public_key_take_random(vscf_rsa_public_key_impl_t *rsa_public_key_impl, vscf_impl_t **random_ref) {

    VSCF_ASSERT_PTR(rsa_public_key_impl);
    VSCF_ASSERT_PTR(random_ref);
    VSCF_ASSERT_PTR(rsa_public_key_impl->random == NULL);

    vscf_impl_t *random = *random_ref;
    *random_ref = NULL;
    VSCF_ASSERT_PTR(random);

    VSCF_ASSERT(vscf_random_is_implemented(random));

    rsa_public_key_impl->random = random;

    rsa_public_key_impl->is_owning_random = 1;
}

//
//  Setup dependency to the interface 'asn1 reader' and keep ownership.
//
VSCF_PUBLIC void
vscf_rsa_public_key_use_asn1_reader(vscf_rsa_public_key_impl_t *rsa_public_key_impl, vscf_impl_t *asn1rd) {

    VSCF_ASSERT_PTR(rsa_public_key_impl);
    VSCF_ASSERT_PTR(asn1rd);
    VSCF_ASSERT_PTR(rsa_public_key_impl->asn1rd == NULL);

    VSCF_ASSERT(vscf_asn1_reader_is_implemented(asn1rd));

    rsa_public_key_impl->asn1rd = asn1rd;

    rsa_public_key_impl->is_owning_asn1rd = 0;
}

//
//  Setup dependency to the interface 'asn1 reader' and transfer ownership.
//
VSCF_PUBLIC void
vscf_rsa_public_key_take_asn1_reader(vscf_rsa_public_key_impl_t *rsa_public_key_impl, vscf_impl_t **asn1rd_ref) {

    VSCF_ASSERT_PTR(rsa_public_key_impl);
    VSCF_ASSERT_PTR(asn1rd_ref);
    VSCF_ASSERT_PTR(rsa_public_key_impl->asn1rd == NULL);

    vscf_impl_t *asn1rd = *asn1rd_ref;
    *asn1rd_ref = NULL;
    VSCF_ASSERT_PTR(asn1rd);

    VSCF_ASSERT(vscf_asn1_reader_is_implemented(asn1rd));

    rsa_public_key_impl->asn1rd = asn1rd;

    rsa_public_key_impl->is_owning_asn1rd = 1;
}

//
//  Setup dependency to the interface 'asn1 writer' and keep ownership.
//
VSCF_PUBLIC void
vscf_rsa_public_key_use_asn1_writer(vscf_rsa_public_key_impl_t *rsa_public_key_impl, vscf_impl_t *asn1wr) {

    VSCF_ASSERT_PTR(rsa_public_key_impl);
    VSCF_ASSERT_PTR(asn1wr);
    VSCF_ASSERT_PTR(rsa_public_key_impl->asn1wr == NULL);

    VSCF_ASSERT(vscf_asn1_writer_is_implemented(asn1wr));

    rsa_public_key_impl->asn1wr = asn1wr;

    rsa_public_key_impl->is_owning_asn1wr = 0;
}

//
//  Setup dependency to the interface 'asn1 writer' and transfer ownership.
//
VSCF_PUBLIC void
vscf_rsa_public_key_take_asn1_writer(vscf_rsa_public_key_impl_t *rsa_public_key_impl, vscf_impl_t **asn1wr_ref) {

    VSCF_ASSERT_PTR(rsa_public_key_impl);
    VSCF_ASSERT_PTR(asn1wr_ref);
    VSCF_ASSERT_PTR(rsa_public_key_impl->asn1wr == NULL);

    vscf_impl_t *asn1wr = *asn1wr_ref;
    *asn1wr_ref = NULL;
    VSCF_ASSERT_PTR(asn1wr);

    VSCF_ASSERT(vscf_asn1_writer_is_implemented(asn1wr));

    rsa_public_key_impl->asn1wr = asn1wr;

    rsa_public_key_impl->is_owning_asn1wr = 1;
}

//
//  Return size of 'vscf_rsa_public_key_impl_t' type.
//
VSCF_PUBLIC size_t
vscf_rsa_public_key_impl_size(void) {

    return sizeof (vscf_rsa_public_key_impl_t);
}

//
//  Cast to the 'vscf_impl_t' type.
//
VSCF_PUBLIC vscf_impl_t *
vscf_rsa_public_key_impl(vscf_rsa_public_key_impl_t *rsa_public_key_impl) {

    VSCF_ASSERT_PTR(rsa_public_key_impl);
    return (vscf_impl_t *)(rsa_public_key_impl);
}


// --------------------------------------------------------------------------
//  Generated section end.
// clang-format on
// --------------------------------------------------------------------------
//  @end