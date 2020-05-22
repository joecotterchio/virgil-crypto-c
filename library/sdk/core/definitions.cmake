#   @license
#   -------------------------------------------------------------------------
#   Copyright (C) 2015-2020 Virgil Security, Inc.
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

if(NOT TARGET core_sdk)
    message(FATAL_ERROR "Expected target 'core_sdk' to be defined first.")
endif()

target_compile_definitions(core_sdk
        PUBLIC
            $<BUILD_INTERFACE:VSSC_INTERNAL_BUILD>
            "VSSC_SHARED_LIBRARY=$<BOOL:${BUILD_SHARED_LIBS}>"
            "VSSC_LIBRARY=$<BOOL:${VSSC_LIBRARY}>"
            "VSSC_MULTI_THREADING=$<BOOL:${VSSC_MULTI_THREADING}>"
            "VSSC_ERROR=$<BOOL:${VSSC_ERROR}>"
            "VSSC_JSON_OBJECT=$<BOOL:${VSSC_JSON_OBJECT}>"
            "VSSC_BASE64_URL=$<BOOL:${VSSC_BASE64_URL}>"
            "VSSC_JWT=$<BOOL:${VSSC_JWT}>"
            "VSSC_JWT_HEADER=$<BOOL:${VSSC_JWT_HEADER}>"
            "VSSC_JWT_PAYLOAD=$<BOOL:${VSSC_JWT_PAYLOAD}>"
            "VSSC_JWT_GENERATOR=$<BOOL:${VSSC_JWT_GENERATOR}>"
            "VSSC_HTTP_HEADER=$<BOOL:${VSSC_HTTP_HEADER}>"
            "VSSC_HTTP_HEADER_LIST=$<BOOL:${VSSC_HTTP_HEADER_LIST}>"
            "VSSC_HTTP_REQUEST=$<BOOL:${VSSC_HTTP_REQUEST}>"
            "VSSC_HTTP_RESPONSE=$<BOOL:${VSSC_HTTP_RESPONSE}>"
        )
