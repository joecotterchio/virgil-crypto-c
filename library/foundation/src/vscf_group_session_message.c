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
//  Class represents group session message
// --------------------------------------------------------------------------


//  @warning
// --------------------------------------------------------------------------
//  This file is partially generated.
//  Generated blocks are enclosed between tags [@<tag>, @end].
//  User's code can be added between tags [@end, @<tag>].
// --------------------------------------------------------------------------

#include "vscf_group_session_message.h"
#include "vscf_memory.h"
#include "vscf_assert.h"
#include "vscf_group_session_message_internal.h"
#include "vscf_group_session_message_defs.h"

#include <pb_decode.h>
#include <pb_encode.h>
#include <virgil/crypto/common/vsc_buffer.h>

// clang-format on
//  @end


//  @generated
// --------------------------------------------------------------------------
// clang-format off
//  Generated section start.
// --------------------------------------------------------------------------

//
//  Perform context specific initialization.
//  Note, this method is called automatically when method vscf_group_session_message_init() is called.
//  Note, that context is already zeroed.
//
static void
vscf_group_session_message_init_ctx(vscf_group_session_message_t *self);

//
//  Release all inner resources.
//  Note, this method is called automatically once when class is completely cleaning up.
//  Note, that context will be zeroed automatically next this method.
//
static void
vscf_group_session_message_cleanup_ctx(vscf_group_session_message_t *self);

//
//  Return size of 'vscf_group_session_message_t'.
//
VSCF_PUBLIC size_t
vscf_group_session_message_ctx_size(void) {

    return sizeof(vscf_group_session_message_t);
}

//
//  Perform initialization of pre-allocated context.
//
VSCF_PUBLIC void
vscf_group_session_message_init(vscf_group_session_message_t *self) {

    VSCF_ASSERT_PTR(self);

    vscf_zeroize(self, sizeof(vscf_group_session_message_t));

    self->refcnt = 1;

    vscf_group_session_message_init_ctx(self);
}

//
//  Release all inner resources including class dependencies.
//
VSCF_PUBLIC void
vscf_group_session_message_cleanup(vscf_group_session_message_t *self) {

    if (self == NULL) {
        return;
    }

    vscf_group_session_message_cleanup_ctx(self);

    vscf_zeroize(self, sizeof(vscf_group_session_message_t));
}

//
//  Allocate context and perform it's initialization.
//
VSCF_PUBLIC vscf_group_session_message_t *
vscf_group_session_message_new(void) {

    vscf_group_session_message_t *self = (vscf_group_session_message_t *) vscf_alloc(sizeof (vscf_group_session_message_t));
    VSCF_ASSERT_ALLOC(self);

    vscf_group_session_message_init(self);

    self->self_dealloc_cb = vscf_dealloc;

    return self;
}

//
//  Release all inner resources and deallocate context if needed.
//  It is safe to call this method even if the context was statically allocated.
//
VSCF_PUBLIC void
vscf_group_session_message_delete(vscf_group_session_message_t *self) {

    if (self == NULL) {
        return;
    }

    size_t old_counter = self->refcnt;
    VSCF_ASSERT(old_counter != 0);
    size_t new_counter = old_counter - 1;

    #if defined(VSCF_ATOMIC_COMPARE_EXCHANGE_WEAK)
    //  CAS loop
    while (!VSCF_ATOMIC_COMPARE_EXCHANGE_WEAK(&self->refcnt, &old_counter, new_counter)) {
        old_counter = self->refcnt;
        VSCF_ASSERT(old_counter != 0);
        new_counter = old_counter - 1;
    }
    #else
    self->refcnt = new_counter;
    #endif

    if (new_counter > 0) {
        return;
    }

    vscf_dealloc_fn self_dealloc_cb = self->self_dealloc_cb;

    vscf_group_session_message_cleanup(self);

    if (self_dealloc_cb != NULL) {
        self_dealloc_cb(self);
    }
}

//
//  Delete given context and nullifies reference.
//  This is a reverse action of the function 'vscf_group_session_message_new ()'.
//
VSCF_PUBLIC void
vscf_group_session_message_destroy(vscf_group_session_message_t **self_ref) {

    VSCF_ASSERT_PTR(self_ref);

    vscf_group_session_message_t *self = *self_ref;
    *self_ref = NULL;

    vscf_group_session_message_delete(self);
}

//
//  Copy given class context by increasing reference counter.
//
VSCF_PUBLIC vscf_group_session_message_t *
vscf_group_session_message_shallow_copy(vscf_group_session_message_t *self) {

    VSCF_ASSERT_PTR(self);

    #if defined(VSCF_ATOMIC_COMPARE_EXCHANGE_WEAK)
    //  CAS loop
    size_t old_counter;
    size_t new_counter;
    do {
        old_counter = self->refcnt;
        new_counter = old_counter + 1;
    } while (!VSCF_ATOMIC_COMPARE_EXCHANGE_WEAK(&self->refcnt, &old_counter, new_counter));
    #else
    ++self->refcnt;
    #endif

    return self;
}


// --------------------------------------------------------------------------
//  Generated section end.
// clang-format on
// --------------------------------------------------------------------------
//  @end


//
//  Perform context specific initialization.
//  Note, this method is called automatically when method vscf_group_session_message_init() is called.
//  Note, that context is already zeroed.
//
static void
vscf_group_session_message_init_ctx(vscf_group_session_message_t *self) {

    VSCF_ASSERT_PTR(self);

    GroupMessage msg = GroupMessage_init_zero;

    self->message_pb = msg;
    // FIXME
    self->message_pb.version = 1;
    // FIXME
    //    vscr_ratchet_group_message_set_pb_encode_callback(self);
}

//
//  Release all inner resources.
//  Note, this method is called automatically once when class is completely cleaning up.
//  Note, that context will be zeroed automatically next this method.
//
static void
vscf_group_session_message_cleanup_ctx(vscf_group_session_message_t *self) {

    VSCF_ASSERT_PTR(self);

    if (self->message_pb.has_regular_message) {
        if (self->message_pb.regular_message.cipher_text.arg) {
            vsc_buffer_destroy((vsc_buffer_t **)&self->message_pb.regular_message.cipher_text.arg);
        }
    }

    vscf_dealloc(self->header_pb);
}

//
//  Returns message type.
//
VSCF_PUBLIC vscf_group_msg_type_t
vscf_group_session_message_get_type(const vscf_group_session_message_t *self) {

    VSCF_ASSERT_PTR(self);

    if (self->message_pb.has_regular_message) {
        return vscf_group_msg_type_REGULAR;
    } else {
        VSCF_ASSERT(self->message_pb.has_group_info);
        return vscf_group_msg_type_GROUP_INFO;
    }
}

//
//  Returns session id.
//  This method should be called only for group info type.
//
VSCF_PUBLIC vsc_data_t
vscf_group_session_message_get_session_id(const vscf_group_session_message_t *self) {

    VSCF_ASSERT_PTR(self);

    if (self->message_pb.has_group_info) {
        return vsc_data(self->message_pb.group_info.session_id, sizeof(self->message_pb.group_info.session_id));
    } else {
        VSCF_ASSERT_PTR(self->header_pb);
        return vsc_data(self->header_pb->session_id, sizeof(self->header_pb->session_id));
    }
}

//
//  Returns message sender id.
//  This method should be called only for regular message type.
//
VSCF_PUBLIC vsc_data_t
vscf_group_session_message_get_sender_id(const vscf_group_session_message_t *self) {

    VSCF_ASSERT_PTR(self);

    if (!self->message_pb.has_regular_message) {
        // FIXME
        return vsc_data_empty();
    }

    VSCF_ASSERT_PTR(self->header_pb);

    return vsc_data(self->header_pb->sender_id, sizeof(self->header_pb->sender_id));
}

//
//  Returns message epoch.
//
VSCF_PUBLIC uint32_t
vscf_group_session_message_get_epoch(const vscf_group_session_message_t *self) {

    VSCF_ASSERT_PTR(self);

    if (self->message_pb.has_regular_message) {
        VSCF_ASSERT_PTR(self->header_pb);
        return self->header_pb->epoch;
    } else {
        return self->message_pb.group_info.epoch;
    }
}

VSCF_PUBLIC void
vscf_group_session_message_set_type(vscf_group_session_message_t *self, vscf_group_msg_type_t type) {

    VSCF_ASSERT_PTR(self);

    GroupMessage msg = GroupMessage_init_zero;
    self->message_pb = msg;

    switch (type) {
    case vscf_group_msg_type_REGULAR:
        self->message_pb.has_regular_message = true;
        self->message_pb.has_group_info = false;
        self->header_pb = vscf_alloc(sizeof(RegularGroupMessageHeader));
        RegularGroupMessageHeader hdr = RegularGroupMessageHeader_init_zero;
        *self->header_pb = hdr;
        break;

    case vscf_group_msg_type_GROUP_INFO:
        self->message_pb.has_regular_message = false;
        self->message_pb.has_group_info = true;
        break;
    }

    // FIXME
    //    vscf_ratchet_group_message_set_pb_encode_callback(self);
}
