//metadoc CharacterToNetBytesConverterMethod copyright Tonika, 2018
//metadoc CharacterToNetBytesConverterMethod license MIT

#ifndef IOCHARACTERTONETBYTESCONVERTERMETHOD_DEFINED
#define IOCHARACTERTONETBYTESCONVERTERMETHOD_DEFINED 1

#include "IoObject.h"

typedef IoObject IoCharacterToNetBytesConverterMethod;

IoCharacterToNetBytesConverterMethod *IoCharacterToNetBytesConverterMethod_proto(void *state);
IoCharacterToNetBytesConverterMethod *IoCharacterToNetBytesConverterMethod_rawClone(IoCharacterToNetBytesConverterMethod *self);
IoCharacterToNetBytesConverterMethod *IoCharacterToNetBytesConverterMethod_new(void *state);
void IoCharacterToNetBytesConverterMethod_free(IoCharacterToNetBytesConverterMethod *self);

IoObject *IoCharacterToNetBytesConverterMethod_convert(IoObject *, IoObject *, IoObject *);

#endif
