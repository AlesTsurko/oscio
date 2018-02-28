//metadoc NetBytesToCharacterConverterMethod copyright Tonika, 2018
//metadoc NetBytesToCharacterConverterMethod license MIT

#ifndef IONETBYTESTOCHARACTERCONVERTERMETHOD_DEFINED
#define IONETBYTESTOCHARACTERCONVERTERMETHOD_DEFINED 1

#include "IoObject.h"

typedef IoObject IoNetBytesToCharacterConverterMethod;

IoNetBytesToCharacterConverterMethod *IoNetBytesToCharacterConverterMethod_proto(void *state);
IoNetBytesToCharacterConverterMethod *IoNetBytesToCharacterConverterMethod_rawClone(IoNetBytesToCharacterConverterMethod *self);
IoNetBytesToCharacterConverterMethod *IoNetBytesToCharacterConverterMethod_new(void *state);
void IoNetBytesToCharacterConverterMethod_free(IoNetBytesToCharacterConverterMethod *self);

IoObject *IoNetBytesToCharacterConverterMethod_convert(IoObject *, IoObject *, IoObject *);

#endif
