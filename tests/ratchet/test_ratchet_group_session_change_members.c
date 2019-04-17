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

#define UNITY_BEGIN() UnityBegin(__FILENAME__)

#include <virgil/crypto/ratchet/vscr_memory.h>
#include <ed25519/ed25519.h>
#include <virgil/crypto/ratchet/private/vscr_ratchet_group_message_defs.h>
#include <virgil/crypto/foundation/vscf_raw_key.h>
#include <vscf_pkcs8_der_deserializer_internal.h>
#include "unity.h"
#include "test_utils.h"

// --------------------------------------------------------------------------
//  Should have it to prevent linkage errors in MSVC.
// --------------------------------------------------------------------------
// clang-format off
void setUp(void) { }
void tearDown(void) { }
void suiteSetUp(void) { }
int suiteTearDown(int num_failures) { return num_failures; }
// clang-format on

#define TEST_DEPENDENCIES_AVAILABLE VSCR_RATCHET_GROUP_SESSION
#if TEST_DEPENDENCIES_AVAILABLE

#include "vscr_ratchet_message_defs.h"
#include "vscr_ratchet_group_session.h"
#include "vscr_ratchet_group_ticket.h"
#include "test_utils_ratchet.h"
#include "msg_channel.h"

// --------------------------------------------------------------------------
//  Test functions.
// --------------------------------------------------------------------------

void
test__add_members__random_chat__should_continue_working(void) {
    vscf_ctr_drbg_t *rng = vscf_ctr_drbg_new();
    TEST_ASSERT_EQUAL(vscf_status_SUCCESS, vscf_ctr_drbg_setup_defaults(rng));

    vscr_ratchet_group_session_t **sessions = NULL;

    size_t group_size = generate_number(rng, 10, 50);

    initialize_random_group_chat(rng, group_size, &sessions, NULL);

    size_t number_of_iterations = 1000;

    encrypt_decrypt(rng, group_size, number_of_iterations, sessions, 0.75, 1.25, 0.25, NULL);

    size_t add_members_size = generate_number(rng, 10, 50);

    add_random_members(rng, group_size, add_members_size, &sessions);

    size_t new_size = group_size + add_members_size;

    encrypt_decrypt(rng, new_size, number_of_iterations, sessions, 0.75, 1.25, 0.25, NULL);

    for (size_t i = 0; i < new_size; i++) {
        vscr_ratchet_group_session_destroy(&sessions[i]);
    }

    vscr_dealloc(sessions);

    vscf_ctr_drbg_destroy(&rng);
}

void
test__remove_members__random_chat__should_continue_working(void) {
    vscf_ctr_drbg_t *rng = vscf_ctr_drbg_new();
    TEST_ASSERT_EQUAL(vscf_status_SUCCESS, vscf_ctr_drbg_setup_defaults(rng));

    vscr_ratchet_group_session_t **sessions = NULL;

    size_t group_size = generate_number(rng, 10, 50);

    initialize_random_group_chat(rng, group_size, &sessions, NULL);

    size_t number_of_iterations = 1000;

    encrypt_decrypt(rng, group_size, number_of_iterations, sessions, 0.75, 1.25, 0.25, NULL);

    size_t remove_members_size = generate_number(rng, 1, group_size - 2);

    remove_random_members(rng, group_size, remove_members_size, &sessions);

    size_t new_size = group_size - remove_members_size;

    encrypt_decrypt(rng, new_size, number_of_iterations, sessions, 0.75, 1.25, 0.25, NULL);

    for (size_t i = 0; i < new_size; i++) {
        vscr_ratchet_group_session_destroy(&sessions[i]);
    }

    vscr_dealloc(sessions);

    vscf_ctr_drbg_destroy(&rng);
}

#endif // TEST_DEPENDENCIES_AVAILABLE


// --------------------------------------------------------------------------
// Entrypoint.
// --------------------------------------------------------------------------
int
main(void) {
    UNITY_BEGIN();

#if TEST_DEPENDENCIES_AVAILABLE
    RUN_TEST(test__add_members__random_chat__should_continue_working);
    RUN_TEST(test__remove_members__random_chat__should_continue_working);
#else
    RUN_TEST(test__nothing__feature_disabled__must_be_ignored);
#endif

    return UNITY_END();
}