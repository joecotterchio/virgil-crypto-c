const initFoundation = require('../../dist/foundation/node.cjs');
const { hexToUint8Array } = require('../utils');

describe('RsaPrivateKey', () => {
  let foundation;
  let keyProvider;

  beforeEach(async () => {
    foundation = await initFoundation();
    keyProvider = new foundation.KeyProvider();
    keyProvider.setupDefaults();
  });

  test('len', () => {
    const privateKey = hexToUint8Array('308204bd020100300d06092a864886f70d0101010500048204a7308204a30201000282010100c73f6fd32119925e9fe5422ae4b2725b2ee5f32fee0d11680105128f3051ed98537504b58150a303919f25240873a78ca7dd93022c88b8a9a7345aec80f785da19e5de970e21ee42bd8fe4a0c4d2f00770695ef6da03b4397cf85ce45aed38a2933a26654076a7ffbef7f0a9974ad86441e37d0becd7abe679cc3611e604f48c8f5c46fb03c42f57cbba31d36981c58592ce5cf5c6544d349530ba8451a2154775b71413897c36ca3ff4f38cb538f4b22bd0fb7b315ca1de1858ed0e860aa6748bf3e97b62707d0407eeac7d521fcd50251fc2088b7122a379d3c7aec7eac9fa06585723d9daf0e59e900fbea715aa32d32aa5bfaab36bcc0772e93a62d1af0d02030100010282010021e28a787bfd16d4ebd977e6c68d0880b4599c018f38feb852d01387717ec56aedea8d39f6fb89359eaad38cacb94a89d3b48d7f45a69ccd1168087c87345139b5c4cf959dec2c52825d79d2d3965206d9d9b9b23e8279c07b1ddbe2640a4ae2ef29e904b83155c1db2edc696316f1f51ef57abb2ff4bfc1cafded461ef9c1c2e6f0ebb54045d4d6d829d9bfdc5746ce1a40125f255ee68aa9f8b7bfd27deb8ad0b782cd9645baea7e6b21ad2e249b3cec45a75a2721f0ecbf8c7ea9b3539ff1d917dda1039efdae500600a0db3088197079a3b9e527ecd3d4ae9b55791530dd572670d835c725081d261c56b4805436b53dbd95b626741bb15c18de6267006b02818100ea91b9db8404ee696de6751a0406ab2baf75d24bf7d52b1c45cb3186f7006816032d44077a33a0560960e98f631a8675b861906ea4c220c81b5b9e46dea03d4c394ba78d64a826c7593d06e169232de173e8966dd40814c4cc7157c44086007c6349205d26220614e5bc8adf83f5ebaa3936ee7c32e2c884d3482e1c0ffb45ef02818100d9739668f72c0b16841f8f409cc09d6ffe8f5d9ad348d921fad0fa8629ade23c04c61dfa76ba6dc557db7b4cabc86d1f18aeeca1f07b4fa706aa50f22b6ef9b0a47aa5cd1df92f4f2aecf00b03d12ba2a27d999135c437d9e357057120ecf59ff3c115d8c69839b23421333e8dc1a2bd88c5bf62582607c0956f0032a80536c302818068765170e3105724789f03537cab839b46de8fb2e941f39af9b20df26f19ad40f0553e509e2953a43d34fd8eafb1e66392a3507115caa652b76c4bc67fea98a1d37a4fb9f633b4615eea809fedf48ec032a0482dcd197436585db99a5aa9d2999295c465f74f7ba9decde282bbffceddd5f112b018f14a1f6d005e187d3d87dd02818100d89cb00437d483e7160e6a212f0520cfe380e4f9c9e7138529d8eaf6a2a6386b194651aea27eebc25dd6a168aae6a8ed05259b4b65c7307d6dc2538829840eeecba9f167f6a7b75ce1a1cd2cebcc7def30767577955bb55733840843bd4ccf115b3bc88b7ca93f302985b90a6323b4fda1357b8477d2ca7e295dbd90b89719090281803113295063fb431954b56710ee2cef6feb55465c432b709009c9bb7df189cc2b24ae6e4bd4fc46301145ccb6dd8bed3e55caeece8e45d467baeba576cbb47dae2c3f4893c4c041c1a97f8e92ce94732bb4984b9a16b2d13831a1ba0b808c9772f39072d6c3a31a2cb16d53853b93d536876640f7a56d302be73998ae170b4ee7');
    const rsaPrivateKey = keyProvider.importPrivateKey(privateKey);
    const keyLen = rsaPrivateKey.len();
    expect(keyLen).toBe(256);
  });

  test('export private key', () => {
    const privateKey = hexToUint8Array('308204bd020100300d06092a864886f70d0101010500048204a7308204a30201000282010100c73f6fd32119925e9fe5422ae4b2725b2ee5f32fee0d11680105128f3051ed98537504b58150a303919f25240873a78ca7dd93022c88b8a9a7345aec80f785da19e5de970e21ee42bd8fe4a0c4d2f00770695ef6da03b4397cf85ce45aed38a2933a26654076a7ffbef7f0a9974ad86441e37d0becd7abe679cc3611e604f48c8f5c46fb03c42f57cbba31d36981c58592ce5cf5c6544d349530ba8451a2154775b71413897c36ca3ff4f38cb538f4b22bd0fb7b315ca1de1858ed0e860aa6748bf3e97b62707d0407eeac7d521fcd50251fc2088b7122a379d3c7aec7eac9fa06585723d9daf0e59e900fbea715aa32d32aa5bfaab36bcc0772e93a62d1af0d02030100010282010021e28a787bfd16d4ebd977e6c68d0880b4599c018f38feb852d01387717ec56aedea8d39f6fb89359eaad38cacb94a89d3b48d7f45a69ccd1168087c87345139b5c4cf959dec2c52825d79d2d3965206d9d9b9b23e8279c07b1ddbe2640a4ae2ef29e904b83155c1db2edc696316f1f51ef57abb2ff4bfc1cafded461ef9c1c2e6f0ebb54045d4d6d829d9bfdc5746ce1a40125f255ee68aa9f8b7bfd27deb8ad0b782cd9645baea7e6b21ad2e249b3cec45a75a2721f0ecbf8c7ea9b3539ff1d917dda1039efdae500600a0db3088197079a3b9e527ecd3d4ae9b55791530dd572670d835c725081d261c56b4805436b53dbd95b626741bb15c18de6267006b02818100ea91b9db8404ee696de6751a0406ab2baf75d24bf7d52b1c45cb3186f7006816032d44077a33a0560960e98f631a8675b861906ea4c220c81b5b9e46dea03d4c394ba78d64a826c7593d06e169232de173e8966dd40814c4cc7157c44086007c6349205d26220614e5bc8adf83f5ebaa3936ee7c32e2c884d3482e1c0ffb45ef02818100d9739668f72c0b16841f8f409cc09d6ffe8f5d9ad348d921fad0fa8629ade23c04c61dfa76ba6dc557db7b4cabc86d1f18aeeca1f07b4fa706aa50f22b6ef9b0a47aa5cd1df92f4f2aecf00b03d12ba2a27d999135c437d9e357057120ecf59ff3c115d8c69839b23421333e8dc1a2bd88c5bf62582607c0956f0032a80536c302818068765170e3105724789f03537cab839b46de8fb2e941f39af9b20df26f19ad40f0553e509e2953a43d34fd8eafb1e66392a3507115caa652b76c4bc67fea98a1d37a4fb9f633b4615eea809fedf48ec032a0482dcd197436585db99a5aa9d2999295c465f74f7ba9decde282bbffceddd5f112b018f14a1f6d005e187d3d87dd02818100d89cb00437d483e7160e6a212f0520cfe380e4f9c9e7138529d8eaf6a2a6386b194651aea27eebc25dd6a168aae6a8ed05259b4b65c7307d6dc2538829840eeecba9f167f6a7b75ce1a1cd2cebcc7def30767577955bb55733840843bd4ccf115b3bc88b7ca93f302985b90a6323b4fda1357b8477d2ca7e295dbd90b89719090281803113295063fb431954b56710ee2cef6feb55465c432b709009c9bb7df189cc2b24ae6e4bd4fc46301145ccb6dd8bed3e55caeece8e45d467baeba576cbb47dae2c3f4893c4c041c1a97f8e92ce94732bb4984b9a16b2d13831a1ba0b808c9772f39072d6c3a31a2cb16d53853b93d536876640f7a56d302be73998ae170b4ee7');
    const rsaPrivateKey = keyProvider.importPrivateKey(privateKey);
    const result = keyProvider.exportPrivateKey(rsaPrivateKey);
    expect(result.toString()).toBe(privateKey.toString());
  });

  test('decrypt', () => {
    const privateKey = keyProvider.generatePrivateKey(foundation.AlgId.RSA);
    const publicKey = privateKey.extractPublicKey();
    const recipientId = hexToUint8Array('726563697069656e74');
    const data = hexToUint8Array('64617461');
    const recipientCipher = new foundation.RecipientCipher();
    recipientCipher.addKeyRecipient(recipientId, publicKey);
    recipientCipher.startEncryption();
    const messageInfo = recipientCipher.packMessageInfo();
    const processEncryption = recipientCipher.processEncryption(data);
    const finishEncryption = recipientCipher.finishEncryption();
    const encryptedMessage = new Uint8Array(
      messageInfo.length + processEncryption.length + finishEncryption.length,
    );
    encryptedMessage.set(messageInfo);
    encryptedMessage.set(processEncryption, messageInfo.length);
    encryptedMessage.set(finishEncryption, messageInfo.length + processEncryption.length);
    recipientCipher.startDecryptionWithKey(recipientId, privateKey, new Uint8Array());
    const processDecryption = recipientCipher.processDecryption(encryptedMessage);
    const finishDecryption = recipientCipher.finishDecryption();
    const result = new Uint8Array(processDecryption.length + finishDecryption.length);
    result.set(processDecryption);
    result.set(finishDecryption, processDecryption.length);
    expect(result.toString()).toBe(data.toString());
  });

  test('extract public key', () => {
    const privateKey = hexToUint8Array('308204bd020100300d06092a864886f70d0101010500048204a7308204a30201000282010100c73f6fd32119925e9fe5422ae4b2725b2ee5f32fee0d11680105128f3051ed98537504b58150a303919f25240873a78ca7dd93022c88b8a9a7345aec80f785da19e5de970e21ee42bd8fe4a0c4d2f00770695ef6da03b4397cf85ce45aed38a2933a26654076a7ffbef7f0a9974ad86441e37d0becd7abe679cc3611e604f48c8f5c46fb03c42f57cbba31d36981c58592ce5cf5c6544d349530ba8451a2154775b71413897c36ca3ff4f38cb538f4b22bd0fb7b315ca1de1858ed0e860aa6748bf3e97b62707d0407eeac7d521fcd50251fc2088b7122a379d3c7aec7eac9fa06585723d9daf0e59e900fbea715aa32d32aa5bfaab36bcc0772e93a62d1af0d02030100010282010021e28a787bfd16d4ebd977e6c68d0880b4599c018f38feb852d01387717ec56aedea8d39f6fb89359eaad38cacb94a89d3b48d7f45a69ccd1168087c87345139b5c4cf959dec2c52825d79d2d3965206d9d9b9b23e8279c07b1ddbe2640a4ae2ef29e904b83155c1db2edc696316f1f51ef57abb2ff4bfc1cafded461ef9c1c2e6f0ebb54045d4d6d829d9bfdc5746ce1a40125f255ee68aa9f8b7bfd27deb8ad0b782cd9645baea7e6b21ad2e249b3cec45a75a2721f0ecbf8c7ea9b3539ff1d917dda1039efdae500600a0db3088197079a3b9e527ecd3d4ae9b55791530dd572670d835c725081d261c56b4805436b53dbd95b626741bb15c18de6267006b02818100ea91b9db8404ee696de6751a0406ab2baf75d24bf7d52b1c45cb3186f7006816032d44077a33a0560960e98f631a8675b861906ea4c220c81b5b9e46dea03d4c394ba78d64a826c7593d06e169232de173e8966dd40814c4cc7157c44086007c6349205d26220614e5bc8adf83f5ebaa3936ee7c32e2c884d3482e1c0ffb45ef02818100d9739668f72c0b16841f8f409cc09d6ffe8f5d9ad348d921fad0fa8629ade23c04c61dfa76ba6dc557db7b4cabc86d1f18aeeca1f07b4fa706aa50f22b6ef9b0a47aa5cd1df92f4f2aecf00b03d12ba2a27d999135c437d9e357057120ecf59ff3c115d8c69839b23421333e8dc1a2bd88c5bf62582607c0956f0032a80536c302818068765170e3105724789f03537cab839b46de8fb2e941f39af9b20df26f19ad40f0553e509e2953a43d34fd8eafb1e66392a3507115caa652b76c4bc67fea98a1d37a4fb9f633b4615eea809fedf48ec032a0482dcd197436585db99a5aa9d2999295c465f74f7ba9decde282bbffceddd5f112b018f14a1f6d005e187d3d87dd02818100d89cb00437d483e7160e6a212f0520cfe380e4f9c9e7138529d8eaf6a2a6386b194651aea27eebc25dd6a168aae6a8ed05259b4b65c7307d6dc2538829840eeecba9f167f6a7b75ce1a1cd2cebcc7def30767577955bb55733840843bd4ccf115b3bc88b7ca93f302985b90a6323b4fda1357b8477d2ca7e295dbd90b89719090281803113295063fb431954b56710ee2cef6feb55465c432b709009c9bb7df189cc2b24ae6e4bd4fc46301145ccb6dd8bed3e55caeece8e45d467baeba576cbb47dae2c3f4893c4c041c1a97f8e92ce94732bb4984b9a16b2d13831a1ba0b808c9772f39072d6c3a31a2cb16d53853b93d536876640f7a56d302be73998ae170b4ee7');
    const rsaPrivateKey = keyProvider.importPrivateKey(privateKey);
    const publicKey = rsaPrivateKey.extractPublicKey();
    const key = keyProvider.exportPublicKey(publicKey);
    const expectedKey = hexToUint8Array('30820122300d06092a864886f70d01010105000382010f003082010a0282010100c73f6fd32119925e9fe5422ae4b2725b2ee5f32fee0d11680105128f3051ed98537504b58150a303919f25240873a78ca7dd93022c88b8a9a7345aec80f785da19e5de970e21ee42bd8fe4a0c4d2f00770695ef6da03b4397cf85ce45aed38a2933a26654076a7ffbef7f0a9974ad86441e37d0becd7abe679cc3611e604f48c8f5c46fb03c42f57cbba31d36981c58592ce5cf5c6544d349530ba8451a2154775b71413897c36ca3ff4f38cb538f4b22bd0fb7b315ca1de1858ed0e860aa6748bf3e97b62707d0407eeac7d521fcd50251fc2088b7122a379d3c7aec7eac9fa06585723d9daf0e59e900fbea715aa32d32aa5bfaab36bcc0772e93a62d1af0d0203010001');
    expect(publicKey).toBeInstanceOf(foundation.RsaPublicKey);
    expect(key.toString()).toBe(expectedKey.toString());
  });

  test('sign hash', () => {
    const privateKeyData = hexToUint8Array('308204bd020100300d06092a864886f70d0101010500048204a7308204a30201000282010100c73f6fd32119925e9fe5422ae4b2725b2ee5f32fee0d11680105128f3051ed98537504b58150a303919f25240873a78ca7dd93022c88b8a9a7345aec80f785da19e5de970e21ee42bd8fe4a0c4d2f00770695ef6da03b4397cf85ce45aed38a2933a26654076a7ffbef7f0a9974ad86441e37d0becd7abe679cc3611e604f48c8f5c46fb03c42f57cbba31d36981c58592ce5cf5c6544d349530ba8451a2154775b71413897c36ca3ff4f38cb538f4b22bd0fb7b315ca1de1858ed0e860aa6748bf3e97b62707d0407eeac7d521fcd50251fc2088b7122a379d3c7aec7eac9fa06585723d9daf0e59e900fbea715aa32d32aa5bfaab36bcc0772e93a62d1af0d02030100010282010021e28a787bfd16d4ebd977e6c68d0880b4599c018f38feb852d01387717ec56aedea8d39f6fb89359eaad38cacb94a89d3b48d7f45a69ccd1168087c87345139b5c4cf959dec2c52825d79d2d3965206d9d9b9b23e8279c07b1ddbe2640a4ae2ef29e904b83155c1db2edc696316f1f51ef57abb2ff4bfc1cafded461ef9c1c2e6f0ebb54045d4d6d829d9bfdc5746ce1a40125f255ee68aa9f8b7bfd27deb8ad0b782cd9645baea7e6b21ad2e249b3cec45a75a2721f0ecbf8c7ea9b3539ff1d917dda1039efdae500600a0db3088197079a3b9e527ecd3d4ae9b55791530dd572670d835c725081d261c56b4805436b53dbd95b626741bb15c18de6267006b02818100ea91b9db8404ee696de6751a0406ab2baf75d24bf7d52b1c45cb3186f7006816032d44077a33a0560960e98f631a8675b861906ea4c220c81b5b9e46dea03d4c394ba78d64a826c7593d06e169232de173e8966dd40814c4cc7157c44086007c6349205d26220614e5bc8adf83f5ebaa3936ee7c32e2c884d3482e1c0ffb45ef02818100d9739668f72c0b16841f8f409cc09d6ffe8f5d9ad348d921fad0fa8629ade23c04c61dfa76ba6dc557db7b4cabc86d1f18aeeca1f07b4fa706aa50f22b6ef9b0a47aa5cd1df92f4f2aecf00b03d12ba2a27d999135c437d9e357057120ecf59ff3c115d8c69839b23421333e8dc1a2bd88c5bf62582607c0956f0032a80536c302818068765170e3105724789f03537cab839b46de8fb2e941f39af9b20df26f19ad40f0553e509e2953a43d34fd8eafb1e66392a3507115caa652b76c4bc67fea98a1d37a4fb9f633b4615eea809fedf48ec032a0482dcd197436585db99a5aa9d2999295c465f74f7ba9decde282bbffceddd5f112b018f14a1f6d005e187d3d87dd02818100d89cb00437d483e7160e6a212f0520cfe380e4f9c9e7138529d8eaf6a2a6386b194651aea27eebc25dd6a168aae6a8ed05259b4b65c7307d6dc2538829840eeecba9f167f6a7b75ce1a1cd2cebcc7def30767577955bb55733840843bd4ccf115b3bc88b7ca93f302985b90a6323b4fda1357b8477d2ca7e295dbd90b89719090281803113295063fb431954b56710ee2cef6feb55465c432b709009c9bb7df189cc2b24ae6e4bd4fc46301145ccb6dd8bed3e55caeece8e45d467baeba576cbb47dae2c3f4893c4c041c1a97f8e92ce94732bb4984b9a16b2d13831a1ba0b808c9772f39072d6c3a31a2cb16d53853b93d536876640f7a56d302be73998ae170b4ee7');
    const rsaPrivateKey = keyProvider.importPrivateKey(privateKeyData);
    const digest = hexToUint8Array('77c7ce9a5d86bb386d443bb96390faa120633158699c8844c30b13ab0bf92760b7e4416aea397db91b4ac0e5dd56b8ef7e4b066162ab1fdc088319ce6defc876');
    const signer = new foundation.Signer();
    const hash = new foundation.Sha512();
    const fakeRandom = new foundation.FakeRandom();
    fakeRandom.setupSourceByte(0xab);
    signer.hash = hash;
    signer.random = fakeRandom;
    signer.reset();
    signer.appendData(digest);
    const signature = signer.sign(rsaPrivateKey);
    const expectedSignature = hexToUint8Array('30820113300d0609608648016503040203050004820100a5792acf886388f8c0fdae7676aceb0d6f9d92338a45d6eda4c0f39dad77169ea65de47ffe9721e3124f00d0e3b3426d57b6d538b5cf046e19df5ca2c83ef90da2c18e74a29ba3774ed3ddcfbd4b91f407ac0b6eaa6fece5ed385f9e9271525403159f5aee94558c0baa3e9df072541521294bce57fb347ee0d99b1ad984a50c6dbe547001248f6c5d24a29403c146f8c7b19663cf0cba5fcae0a281f65a8e8ba116ee2acd3ba0082dcc028d2449b9cf118e804cedae5ed206c769327f1b376d0af834e4502c0ff258b113c1f264d65e56642d0a44d04052038b0ab808d1d50e034bf0898fdabcf499c24182440eeee99954408991a10e486b62642cd6777040');
    expect(signature.toString()).toBe(expectedSignature.toString());
  });

  test('generate key', () => {
    const keyMaterialRng = new foundation.KeyMaterialRng();
    const keyMaterial = hexToUint8Array('77fa8f446f07587127700998742ba4c8e60bac5ef52e5326c7f928cc2a80ebe0');
    keyMaterialRng.resetKeyMaterial(keyMaterial);
    keyProvider.random = keyMaterialRng;
    keyProvider.setRsaParams(2048);
    const rsaPrivateKey = keyProvider.generatePrivateKey(foundation.AlgId.RSA);
    const key = keyProvider.exportPrivateKey(rsaPrivateKey);
    const expectedKey = hexToUint8Array('308204be020100300d06092a864886f70d0101010500048204a8308204a40201000282010100e3dbc3c888842df8bf63bcefb40c2e9db528a883d8dac65ac0e72074b21a500104a81bb5fcb4c115ae330e2161b9c2f655416e4b256812c6c770839ce5e02722b2775c591befa090be7a7059b09608ab90e2ee796434c326eb2c98243a980dc66310eda8791df01f84b9799befe9cb45107afba9d2ebd4086067bced0110ec99ff4882fa485f22122bb09fccfac8c579ad1b787e6282913b7ec72db7b5df0a27f4a3353b6a3b57b46932b277c08aef43cc4708a4f551fedc7844d35ac442494d1a3fd805b4d9967d864d88a18e54e73792b321e1b9370d6ec83d3a98963af3508c41c0d8fe64053131416f461566966391575e8d7fe57ddfd6ce50bf4decd88f0203010001028201006cf58b32daad327a8fb2f7073cf6d257d1e84664fe0ee7e93ff3861ea7885397990d766ad913ea7d1e97057bcb0a94834d1383d56566d60bbe153caa8b765be088acf1391f55c05756ee9fc913db3afc27c58cb9f9c40d4a100d7c175ef99524b7fcc158ddca06285c448135a34d0e49d16eade770981b05826c38f8b098d23a8eb04e6610961fb933ddc7b9647cf6a5b146e5b412504c6e42913f67aba23866f10936a5c53db1fbb2abd4e2255b56b8290c5b2be385c5ca077c931fffd4778931fe8a35decd07ad79d7e07cbed4d1489ea91ed4c74be50613b2808e3ffbd2467475b701ed54be6a5efd05df7bccdd80d74fd5c563f308cc8cb016565429ba4902818100f96d727b9ad54d11a8885804f86e80e63d08a362a28a0c9ff27050d3b118303533678e28fdba2687f3a2de2b9d9076d6b441d0ccd49201df45f3af599deccaae3313ce70c666bd26a1d36388369c013efc2d23f48d18bc86c4ee55d05780d04ed309e66b9deefb230b20193425c527ccfd13bcff447bcfeb6b2d5579309cc59b02818100e9dcd1eb56a990a6ca50ba267caf475f58ac69bb0a432c95bd80b625a55de8465fe4a238496eb66b3b09645210af44b6c718bf6f61fae60b70c958c513c5525524a6ef3399d2439a34efb0b8dbefd2ef2fac486d17fc3366abe3ca9434add0f0fce93dde41fd90bfa4e3b231636b68df5b1e4c9d80717daa235ced771f71c21d028181009728b9f9a8a2dddaf6bcf242c8e0072401170c154995ca02e0e52a46b08b8d23a0ac805ddd2e840d5e1c74f20fc22e12fe18e8d64978d6c39ddc0987910aa0e623343ca6e1c5ff99baf6a5da35e623672d6299e8a9ddb4db23dba08beb8bb8321cf961f8143571631269f87c3eeb95ac482f3f19a0423c865a6495e92509cd4302818100d1879555039a7d0dd32aacfe1aac788806ccc3165fc57bc6d5b8e279ac460cfc30a28a6d5fed9fe74747cce8722676ac4489f9caf3c076283def48679aa52a753a978ead6ede22cfa12a37ee08b0410f286975a2b8e0afb507c0da1a1b70b849926fef8c9917747f205f19a2826f13d13ab454f4b0c5fe4f57cbc4befc1f5249028180108e25d85152c4b419d5b9ee1ab2b3986e9042c1433d00977f77fc5d3ca600976676c3e115fa4d9e33565e0dcb1873ccae6550131c666d4a4b4f5d8b9559613ad88060e7a967a7d8119659018cdf312c79791c8fec5e879108272b40e6aef18f8f011a1df897f0c8e1b0224421efc79fe62a59ece4d3f59133cbc24e9d44cbd4');
    expect(key.toString()).toBe(expectedKey.toString());
  });
});
