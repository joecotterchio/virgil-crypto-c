/*
* Copyright (C) 2015-2019 Virgil Security, Inc.
*
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are
* met:
*
* (1) Redistributions of source code must retain the above copyright
* notice, this list of conditions and the following disclaimer.
*
* (2) Redistributions in binary form must reproduce the above copyright
* notice, this list of conditions and the following disclaimer in
* the documentation and/or other materials provided with the
* distribution.
*
* (3) Neither the name of the copyright holder nor the names of its
* contributors may be used to endorse or promote products derived from
* this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE AUTHOR ''AS IS'' AND ANY EXPRESS OR
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
* IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*
* Lead Maintainer: Virgil Security Inc. <support@virgilsecurity.com>
*/

package com.virgilsecurity.crypto.ratchet;

import com.virgilsecurity.crypto.foundation.*;

/*
* Class represents ratchet group message
*/
public class RatchetGroupMessage implements AutoCloseable {

    public long cCtx;

    /* Create underlying C context. */
    public RatchetGroupMessage() {
        super();
        this.cCtx = RatchetJNI.INSTANCE.ratchetGroupMessage_new();
    }

    /*
    * Acquire C context.
    * Note. This method is used in generated code only, and SHOULD NOT be used in another way.
    */
    public RatchetGroupMessage(long cCtx) {
        super();
        this.cCtx = cCtx;
    }

    /* Close resource. */
    public void close() {
        RatchetJNI.INSTANCE.ratchetGroupMessage_close(this.cCtx);
    }

    /*
    * Returns message type.
    */
    public GroupMsgType getType() {
        return RatchetJNI.INSTANCE.ratchetGroupMessage_getType(this.cCtx);
    }

    /*
    * Returns session id.
    * This method should be called only for group info type.
    */
    public byte[] getSessionId() {
        return RatchetJNI.INSTANCE.ratchetGroupMessage_getSessionId(this.cCtx);
    }

    /*
    * Returns number of public keys.
    * This method should be called only for group info message type.
    */
    public int getPubKeyCount() {
        return RatchetJNI.INSTANCE.ratchetGroupMessage_getPubKeyCount(this.cCtx);
    }

    /*
    * Returns public key id for some participant id.
    * This method should be called only for group info message type.
    */
    public byte[] getPubKeyId(byte[] participantId) throws RatchetException {
        return RatchetJNI.INSTANCE.ratchetGroupMessage_getPubKeyId(this.cCtx, participantId);
    }

    /*
    * Returns message sender id.
    * This method should be called only for regular message type.
    */
    public byte[] getSenderId() {
        return RatchetJNI.INSTANCE.ratchetGroupMessage_getSenderId(this.cCtx);
    }

    /*
    * Buffer len to serialize this class.
    */
    public int serializeLen() {
        return RatchetJNI.INSTANCE.ratchetGroupMessage_serializeLen(this.cCtx);
    }

    /*
    * Serializes instance.
    */
    public byte[] serialize() {
        return RatchetJNI.INSTANCE.ratchetGroupMessage_serialize(this.cCtx);
    }

    /*
    * Deserializes instance.
    */
    public static RatchetGroupMessage deserialize(byte[] input) throws RatchetException {
        return RatchetJNI.INSTANCE.ratchetGroupMessage_deserialize(input);
    }
}
