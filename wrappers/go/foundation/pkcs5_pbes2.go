package foundation

// #cgo CFLAGS: -I${SRCDIR}/../binaries/include/
// #cgo LDFLAGS: -L${SRCDIR}/../binaries/lib -lmbedcrypto -led25519 -lprotobuf-nanopb -lvsc_common -lvsc_foundation -lvsc_foundation_pb
// #include <virgil/crypto/foundation/vscf_foundation_public.h>
import "C"


/*
* Virgil Security implementation of the PBES2 (RFC 8018) algorithm.
*/
type Pkcs5Pbes2 struct {
    IAlg
    IEncrypt
    IDecrypt
    cCtx *C.vscf_pkcs5_pbes2_t /*ct10*/
}

func (obj *Pkcs5Pbes2) SetKdf (kdf ISaltedKdf) {
    C.vscf_pkcs5_pbes2_release_kdf(obj.cCtx)
    C.vscf_pkcs5_pbes2_use_kdf(obj.cCtx, (*C.vscf_impl_t)(kdf.ctx()))
}

func (obj *Pkcs5Pbes2) SetCipher (cipher ICipher) {
    C.vscf_pkcs5_pbes2_release_cipher(obj.cCtx)
    C.vscf_pkcs5_pbes2_use_cipher(obj.cCtx, (*C.vscf_impl_t)(cipher.ctx()))
}

/*
* Configure cipher with a new password.
*/
func (obj *Pkcs5Pbes2) Reset (pwd []byte) {
    pwdData := helperWrapData (pwd)

    C.vscf_pkcs5_pbes2_reset(obj.cCtx, pwdData)

    return
}

/* Handle underlying C context. */
func (obj *Pkcs5Pbes2) ctx () *C.vscf_impl_t {
    return (*C.vscf_impl_t)(obj.cCtx)
}

func NewPkcs5Pbes2 () *Pkcs5Pbes2 {
    ctx := C.vscf_pkcs5_pbes2_new()
    return &Pkcs5Pbes2 {
        cCtx: ctx,
    }
}

/* Acquire C context.
* Note. This method is used in generated code only, and SHOULD NOT be used in another way.
*/
func newPkcs5Pbes2WithCtx (ctx *C.vscf_pkcs5_pbes2_t /*ct10*/) *Pkcs5Pbes2 {
    return &Pkcs5Pbes2 {
        cCtx: ctx,
    }
}

/* Acquire retained C context.
* Note. This method is used in generated code only, and SHOULD NOT be used in another way.
*/
func newPkcs5Pbes2Copy (ctx *C.vscf_pkcs5_pbes2_t /*ct10*/) *Pkcs5Pbes2 {
    return &Pkcs5Pbes2 {
        cCtx: C.vscf_pkcs5_pbes2_shallow_copy(ctx),
    }
}

/// Release underlying C context.
func (obj *Pkcs5Pbes2) clear () {
    C.vscf_pkcs5_pbes2_delete(obj.cCtx)
}

/*
* Provide algorithm identificator.
*/
func (obj *Pkcs5Pbes2) AlgId () AlgId {
    proxyResult := /*pr4*/C.vscf_pkcs5_pbes2_alg_id(obj.cCtx)

    return AlgId(proxyResult) /* r8 */
}

/*
* Produce object with algorithm information and configuration parameters.
*/
func (obj *Pkcs5Pbes2) ProduceAlgInfo () (IAlgInfo, error) {
    proxyResult := /*pr4*/C.vscf_pkcs5_pbes2_produce_alg_info(obj.cCtx)

    return FoundationImplementationWrapIAlgInfo(proxyResult) /* r4 */
}

/*
* Restore algorithm configuration from the given object.
*/
func (obj *Pkcs5Pbes2) RestoreAlgInfo (algInfo IAlgInfo) error {
    proxyResult := /*pr4*/C.vscf_pkcs5_pbes2_restore_alg_info(obj.cCtx, (*C.vscf_impl_t)(algInfo.ctx()))

    err := FoundationErrorHandleStatus(proxyResult)
    if err != nil {
        return err
    }

    return nil
}

/*
* Encrypt given data.
*/
func (obj *Pkcs5Pbes2) Encrypt (data []byte) ([]byte, error) {
    outBuf, outBufErr := bufferNewBuffer(int(obj.EncryptedLen(uint32(len(data))) /* lg2 */))
    if outBufErr != nil {
        return nil, outBufErr
    }
    defer outBuf.clear()
    dataData := helperWrapData (data)

    proxyResult := /*pr4*/C.vscf_pkcs5_pbes2_encrypt(obj.cCtx, dataData, outBuf.ctx)

    err := FoundationErrorHandleStatus(proxyResult)
    if err != nil {
        return nil, err
    }

    return outBuf.getData() /* r7 */, nil
}

/*
* Calculate required buffer length to hold the encrypted data.
*/
func (obj *Pkcs5Pbes2) EncryptedLen (dataLen uint32) uint32 {
    proxyResult := /*pr4*/C.vscf_pkcs5_pbes2_encrypted_len(obj.cCtx, (C.size_t)(dataLen)/*pa10*/)

    return uint32(proxyResult) /* r9 */
}

/*
* Precise length calculation of encrypted data.
*/
func (obj *Pkcs5Pbes2) PreciseEncryptedLen (dataLen uint32) uint32 {
    proxyResult := /*pr4*/C.vscf_pkcs5_pbes2_precise_encrypted_len(obj.cCtx, (C.size_t)(dataLen)/*pa10*/)

    return uint32(proxyResult) /* r9 */
}

/*
* Decrypt given data.
*/
func (obj *Pkcs5Pbes2) Decrypt (data []byte) ([]byte, error) {
    outBuf, outBufErr := bufferNewBuffer(int(obj.DecryptedLen(uint32(len(data))) /* lg2 */))
    if outBufErr != nil {
        return nil, outBufErr
    }
    defer outBuf.clear()
    dataData := helperWrapData (data)

    proxyResult := /*pr4*/C.vscf_pkcs5_pbes2_decrypt(obj.cCtx, dataData, outBuf.ctx)

    err := FoundationErrorHandleStatus(proxyResult)
    if err != nil {
        return nil, err
    }

    return outBuf.getData() /* r7 */, nil
}

/*
* Calculate required buffer length to hold the decrypted data.
*/
func (obj *Pkcs5Pbes2) DecryptedLen (dataLen uint32) uint32 {
    proxyResult := /*pr4*/C.vscf_pkcs5_pbes2_decrypted_len(obj.cCtx, (C.size_t)(dataLen)/*pa10*/)

    return uint32(proxyResult) /* r9 */
}
