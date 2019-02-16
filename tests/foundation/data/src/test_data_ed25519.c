#include "test_data_ed25519.h"

const byte test_ed25519_RANDOM_BYTES[] = {
    0x4D, 0x43, 0x34, 0x43, 0x41, 0x51, 0x41, 0x77,
    0x42, 0x51, 0x59, 0x44, 0x4B, 0x32, 0x56, 0x77,
    0x42, 0x43, 0x49, 0x45, 0x49, 0x45, 0x73, 0x43,
    0x4C, 0x48, 0x4E, 0x50, 0x63, 0x58, 0x50, 0x2B,
};

const vsc_data_t test_ed25519_RANDOM = {
    test_ed25519_RANDOM_BYTES, sizeof(test_ed25519_RANDOM_BYTES)
};

const byte test_ed25519_PRIVATE_KEY_BYTES[] = {
    0x04, 0x20, 0x4D, 0x43, 0x34, 0x43, 0x41, 0x51,
    0x41, 0x77, 0x42, 0x51, 0x59, 0x44, 0x4B, 0x32,
    0x56, 0x77, 0x42, 0x43, 0x49, 0x45, 0x49, 0x45,
    0x73, 0x43, 0x4C, 0x48, 0x4E, 0x50, 0x63, 0x58,
    0x50, 0x2B
};

const vsc_data_t test_ed25519_PRIVATE_KEY = {
    test_ed25519_PRIVATE_KEY_BYTES, sizeof(test_ed25519_PRIVATE_KEY_BYTES)
};

const byte test_ed25519_PUBLIC_KEY_BYTES[] = {
    0xE7, 0x34, 0x9D, 0xD5, 0xEB, 0x23, 0x23, 0x37,
    0x66, 0xF3, 0x19, 0x2E, 0x2D, 0x9D, 0x4D, 0x26,
    0xD8, 0xA2, 0x67, 0x1D, 0x71, 0xE8, 0xAE, 0xD4,
    0x80, 0x53, 0xB4, 0x7F, 0x55, 0xF4, 0x70, 0x32
};

const vsc_data_t test_ed25519_PUBLIC_KEY = {
    test_ed25519_PUBLIC_KEY_BYTES, sizeof(test_ed25519_PUBLIC_KEY_BYTES)
};

const byte test_ed25519_MESSAGE_BYTES[] = {
    0x32, 0x37, 0x64, 0x32, 0x30, 0x39, 0x34, 0x30,
    0x65, 0x66, 0x30, 0x36, 0x30, 0x34, 0x64, 0x32,
    0x32, 0x39, 0x63, 0x32, 0x34, 0x65, 0x35, 0x61,
    0x35, 0x65, 0x62, 0x32, 0x30, 0x62, 0x31, 0x36
};

const vsc_data_t test_ed25519_MESSAGE = {
    test_ed25519_MESSAGE_BYTES, sizeof(test_ed25519_MESSAGE_BYTES)
};

const byte test_ed25519_SIGNATURE_BYTES[] = {
    0x11, 0x55, 0x22, 0xCD, 0xB5, 0x30, 0x7E, 0x7B,
    0x9B, 0x30, 0x6E, 0x16, 0xC9, 0x96, 0x7E, 0x23,
    0xB9, 0xD6, 0xB3, 0x8C, 0x18, 0x33, 0x28, 0xDD,
    0x3F, 0xA6, 0x72, 0x7D, 0xA2, 0x8E, 0x22, 0xE5,
    0x5D, 0x39, 0x26, 0xAB, 0xF0, 0x24, 0x7D, 0x5C,
    0x7C, 0x99, 0x14, 0xB9, 0xF4, 0xBD, 0x18, 0x09,
    0x61, 0x68, 0x33, 0xBB, 0x79, 0x9C, 0xF7, 0x36,
    0x25, 0x1D, 0xFD, 0x29, 0xE2, 0x08, 0x51, 0x0C
};

const vsc_data_t test_ed25519_SIGNATURE = {
    test_ed25519_SIGNATURE_BYTES, sizeof(test_ed25519_SIGNATURE_BYTES)
};

const byte test_ed25519_PUBLIC_KEY_PKCS8_DER_BYTES[] = {
    0x30, 0x2A, 0x30, 0x05, 0x06, 0x03, 0x2B, 0x65,
    0x70, 0x03, 0x21, 0x00, 0xE7, 0x34, 0x9D, 0xD5,
    0xEB, 0x23, 0x23, 0x37, 0x66, 0xF3, 0x19, 0x2E,
    0x2D, 0x9D, 0x4D, 0x26, 0xD8, 0xA2, 0x67, 0x1D,
    0x71, 0xE8, 0xAE, 0xD4, 0x80, 0x53, 0xB4, 0x7F,
    0x55, 0xF4, 0x70, 0x32
};

const vsc_data_t test_ed25519_PUBLIC_KEY_PKCS8_DER = {
    test_ed25519_PUBLIC_KEY_PKCS8_DER_BYTES, sizeof(test_ed25519_PUBLIC_KEY_PKCS8_DER_BYTES)
};

const byte test_ed25519_PRIVATE_KEY_PKCS8_DER_BYTES[] = {
    0x30, 0x2E, 0x02, 0x01, 0x00, 0x30, 0x05, 0x06,
    0x03, 0x2B, 0x65, 0x70, 0x04, 0x22, 0x04, 0x20,
    0x4D, 0x43, 0x34, 0x43, 0x41, 0x51, 0x41, 0x77,
    0x42, 0x51, 0x59, 0x44, 0x4B, 0x32, 0x56, 0x77,
    0x42, 0x43, 0x49, 0x45, 0x49, 0x45, 0x73, 0x43,
    0x4C, 0x48, 0x4E, 0x50, 0x63, 0x58, 0x50, 0x2B
};

const vsc_data_t test_ed25519_PRIVATE_KEY_PKCS8_DER = {
    test_ed25519_PRIVATE_KEY_PKCS8_DER_BYTES, sizeof(test_ed25519_PRIVATE_KEY_PKCS8_DER_BYTES)
};
