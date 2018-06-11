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


//  @warning
// --------------------------------------------------------------------------
//  This file is partially generated.
//  Generated blocks are enclosed between tags [@<tag>, @end].
//  User's code can be added between tags [@end, @<tag>].
// --------------------------------------------------------------------------


//  @description
// --------------------------------------------------------------------------
//  Provide Pythia implementation based on the Virgil Security.
// --------------------------------------------------------------------------

#ifndef VSCP_PYTHIA_H_INCLUDED
#define VSCP_PYTHIA_H_INCLUDED

#include "vscp_library.h"
#include "vscp_error.h"

#include <virgil/common/vsc_data.h>
#include <virgil/common/vsc_buffer.h>
//  @end


#ifdef __cplusplus
extern "C" {
#endif


//  @generated
// --------------------------------------------------------------------------
// clang-format off
//  Generated section start.
// --------------------------------------------------------------------------

//
//  Handle 'pythia' context.
//
typedef struct vscp_pythia_t vscp_pythia_t;

//
//  Perform initialization of pre-allocated context.
//
VSCP_PUBLIC vscp_error_t
vscp_pythia_init(vscp_pythia_t* pythia_ctx);

//
//  Release all inner resources.
//
VSCP_PUBLIC void
vscp_pythia_cleanup(vscp_pythia_t* pythia_ctx);

//
//  Allocate context and perform it's initialization.
//
VSCP_PUBLIC vscp_pythia_t*
vscp_pythia_new(void);

//
//  Release all inner resorces and deallocate context if needed.
//  It is safe to call this method even if context was allocated by the caller.
//
VSCP_PUBLIC void
vscp_pythia_delete(vscp_pythia_t* pythia_ctx);

//
//  Delete given context and nullifies reference.
//  This is a reverse action of the function 'vscp_pythia_new ()'.
//
VSCP_PUBLIC void
vscp_pythia_destroy(vscp_pythia_t** pythia_ctx_ref);

//
//  Performs global initialization of the pythia library.
//  Must be called once for entire application at startup.
//
VSCP_PUBLIC void
vscp_init(void);

//
//  Performs global cleanup of the pythia library.
//  Must be called once for entire application before exit.
//
VSCP_PUBLIC void
vscp_cleanup(void);

//
//  Return length of the buffer needed to hold 'blinded password'.
//
VSCP_PUBLIC size_t
vscp_pythia_blinded_password_buf_len(void);

//
//  Return length of the buffer needed to hold 'deblinded password'.
//
VSCP_PUBLIC size_t
vscp_pythia_deblinded_password_buf_len(void);

//
//  Return length of the buffer needed to hold 'blinding secret'.
//
VSCP_PUBLIC size_t
vscp_pythia_blinding_secret_buf_len(void);

//
//  Return length of the buffer needed to hold 'transformation private key'.
//
VSCP_PUBLIC size_t
vscp_pythia_transformation_private_key_buf_len(void);

//
//  Return length of the buffer needed to hold 'transformation public key'.
//
VSCP_PUBLIC size_t
vscp_pythia_transformation_public_key_buf_len(void);

//
//  Return length of the buffer needed to hold 'transformed password'.
//
VSCP_PUBLIC size_t
vscp_pythia_transformed_password_buf_len(void);

//
//  Return length of the buffer needed to hold 'transformed tweak'.
//
VSCP_PUBLIC size_t
vscp_pythia_transformed_tweak_buf_len(void);

//
//  Return length of the buffer needed to hold 'proof value'.
//
VSCP_PUBLIC size_t
vscp_pythia_proof_value_buf_len(void);

//
//  Blinds password. Turns password into a pseudo-random string.
//  This step is necessary to prevent 3rd-parties from knowledge of end user's password.
//
VSCP_PUBLIC vscp_error_t
vscp_pythia_blind(vscp_pythia_t* pythia_ctx, const vsc_data_t password, vsc_buffer_t* blinded_password,
        vsc_buffer_t* blinding_secret);

//
//  Deblinds 'transformed password' value with previously returned 'blinding secret' from blind().
//
VSCP_PUBLIC vscp_error_t
vscp_pythia_deblind(vscp_pythia_t* pythia_ctx, const vsc_data_t transformed_password, const vsc_data_t blinding_secret,
        vsc_buffer_t* deblinded_password);

//
//  Computes transformation private and public key.
//
VSCP_PUBLIC vscp_error_t
vscp_pythia_compute_transformation_key_pair(vscp_pythia_t* pythia_ctx, const vsc_data_t transformation_key_id,
        const vsc_data_t pythia_secret, const vsc_data_t pythia_scope_secret, vsc_buffer_t* transformation_private_key,
        vsc_buffer_t* transformation_public_key);

//
//  Transforms blinded password using transformation private key.
//
VSCP_PUBLIC vscp_error_t
vscp_pythia_transform(vscp_pythia_t* pythia_ctx, const vsc_data_t blinded_password, const vsc_data_t tweak,
        const vsc_data_t transformation_private_key, vsc_buffer_t* transformed_password,
        vsc_buffer_t* transformed_tweak);

//
//  Generates proof that server possesses secret values that were used to transform password.
//
VSCP_PUBLIC vscp_error_t
vscp_pythia_prove(vscp_pythia_t* pythia_ctx, const vsc_data_t transformed_password, const vsc_data_t blinded_password,
        const vsc_data_t transformed_tweak, const vsc_data_t transformation_private_key,
        const vsc_data_t transformation_public_key, vsc_buffer_t* proof_value_c, vsc_buffer_t* proof_value_u);

//
//  This operation allows client to verify that the output of transform() is correct,
//  assuming that client has previously stored transformation public key.
//
VSCP_PUBLIC vscp_error_t
vscp_pythia_verify(vscp_pythia_t* pythia_ctx, const vsc_data_t transformed_password, const vsc_data_t blinded_password,
        const vsc_data_t tweak, const vsc_data_t transformation_public_key, const vsc_data_t proof_value_c,
        const vsc_data_t proof_value_u);


// --------------------------------------------------------------------------
//  Generated section end.
// clang-format on
// --------------------------------------------------------------------------
//  @end


#ifdef __cplusplus
}
#endif


//  @footer
#endif // VSCP_PYTHIA_H_INCLUDED
//  @end
