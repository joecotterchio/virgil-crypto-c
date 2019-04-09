#   @license
#   -------------------------------------------------------------------------
#   Copyright (C) 2015-2019 Virgil Security, Inc.
#
#   All rights reserved.
#
#   Redistribution and use in source and binary forms, with or without
#   modification, are permitted provided that the following conditions are
#   met:
#
#       (1) Redistributions of source code must retain the above copyright
#       notice, this list of conditions and the following disclaimer.
#
#       (2) Redistributions in binary form must reproduce the above copyright
#       notice, this list of conditions and the following disclaimer in
#       the documentation and/or other materials provided with the
#       distribution.
#
#       (3) Neither the name of the copyright holder nor the names of its
#       contributors may be used to endorse or promote products derived from
#       this software without specific prior written permission.
#
#   THIS SOFTWARE IS PROVIDED BY THE AUTHOR ''AS IS'' AND ANY EXPRESS OR
#   IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
#   WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
#   DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
#   INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
#   (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
#   SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
#   HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
#   STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
#   IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
#   POSSIBILITY OF SUCH DAMAGE.
#
#   Lead Maintainer: Virgil Security Inc. <support@virgilsecurity.com>
#   -------------------------------------------------------------------------

#   @warning
#   -------------------------------------------------------------------------
#   This file is fully generated by script 'cmake_files_codegen.gsl'.
#   It can be changed temporary for debug purposes only.
#   -------------------------------------------------------------------------
#   @end


include_guard()

if(NOT TARGET ratchet)
    message(FATAL_ERROR "Expected target 'ratchet' to be defined first.")
endif()

target_compile_definitions(ratchet
        PUBLIC
            $<BUILD_INTERFACE:VSCR_INTERNAL_BUILD>
            "VSCR_LIBRARY=$<BOOL:${VSCR_LIBRARY}>"
            "VSCR_RATCHET_COMMON=$<BOOL:${VSCR_RATCHET_COMMON}>"
            "VSCR_RATCHET_COMMON_HIDDEN=$<BOOL:${VSCR_RATCHET_COMMON_HIDDEN}>"
            "VSCR_RATCHET_KEY_UTILS=$<BOOL:${VSCR_RATCHET_KEY_UTILS}>"
            "VSCR_ERROR=$<BOOL:${VSCR_ERROR}>"
            "VSCR_RATCHET_X3DH=$<BOOL:${VSCR_RATCHET_X3DH}>"
            "VSCR_RATCHET_SKIPPED_MESSAGES=$<BOOL:${VSCR_RATCHET_SKIPPED_MESSAGES}>"
            "VSCR_RATCHET_RECEIVER_CHAINS=$<BOOL:${VSCR_RATCHET_RECEIVER_CHAINS}>"
            "VSCR_RATCHET_MESSAGE=$<BOOL:${VSCR_RATCHET_MESSAGE}>"
            "VSCR_RATCHET_CIPHER=$<BOOL:${VSCR_RATCHET_CIPHER}>"
            "VSCR_RATCHET_CHAIN_KEY=$<BOOL:${VSCR_RATCHET_CHAIN_KEY}>"
            "VSCR_RATCHET_MESSAGE_KEY=$<BOOL:${VSCR_RATCHET_MESSAGE_KEY}>"
            "VSCR_RATCHET_RECEIVER_CHAIN=$<BOOL:${VSCR_RATCHET_RECEIVER_CHAIN}>"
            "VSCR_RATCHET_RECEIVER_CHAIN_LIST_NODE=$<BOOL:${VSCR_RATCHET_RECEIVER_CHAIN_LIST_NODE}>"
            "VSCR_RATCHET_SKIPPED_MESSAGE_KEY=$<BOOL:${VSCR_RATCHET_SKIPPED_MESSAGE_KEY}>"
            "VSCR_RATCHET_SKIPPED_MESSAGE_KEY_LIST_NODE=$<BOOL:${VSCR_RATCHET_SKIPPED_MESSAGE_KEY_LIST_NODE}>"
            "VSCR_RATCHET_SENDER_CHAIN=$<BOOL:${VSCR_RATCHET_SENDER_CHAIN}>"
            "VSCR_RATCHET_KEYS=$<BOOL:${VSCR_RATCHET_KEYS}>"
            "VSCR_RATCHET=$<BOOL:${VSCR_RATCHET}>"
            "VSCR_RATCHET_SESSION=$<BOOL:${VSCR_RATCHET_SESSION}>"
            "VSCR_RATCHET_GROUP_PARTICIPANT_DATA=$<BOOL:${VSCR_RATCHET_GROUP_PARTICIPANT_DATA}>"
            "VSCR_RATCHET_GROUP_MESSAGE=$<BOOL:${VSCR_RATCHET_GROUP_MESSAGE}>"
            "VSCR_RATCHET_SKIPPED_GROUP_MESSAGE_KEY_NODE=$<BOOL:${VSCR_RATCHET_SKIPPED_GROUP_MESSAGE_KEY_NODE}>"
            "VSCR_RATCHET_SKIPPED_GROUP_MESSAGE_KEY_ROOT_NODE=$<BOOL:${VSCR_RATCHET_SKIPPED_GROUP_MESSAGE_KEY_ROOT_NODE}>"
            "VSCR_RATCHET_SKIPPED_GROUP_MESSAGES=$<BOOL:${VSCR_RATCHET_SKIPPED_GROUP_MESSAGES}>"
            "VSCR_RATCHET_GROUP_SESSION=$<BOOL:${VSCR_RATCHET_GROUP_SESSION}>"
            "VSCR_RATCHET_GROUP_TICKET=$<BOOL:${VSCR_RATCHET_GROUP_TICKET}>"
        PRIVATE
            $<$<BOOL:${BUILD_SHARED_LIBS}>:VSCR_BUILD_SHARED_LIBS>
        )
