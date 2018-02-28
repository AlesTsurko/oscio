//metadoc NetBytesToCharacterConverterMethod copyright Tonika, 2018
//metadoc NetBytesToCharacterConverterMethod license MIT
//metadoc NetBytesToCharacterConverterMethod category API
//metadoc NetBytesToCharacterConverterMethod description Converts netbytes to character.

#include <string.h>
#if _WIN32
#include <winsock2.h>
#define tosc_strncpy(_dst, _src, _len) strncpy_s(_dst, _len, _src, _TRUNCATE)
#else
#include <netinet/in.h>
#define tosc_strncpy(_dst, _src, _len) strncpy(_dst, _src, _len)
#endif
#if __unix__ && !__APPLE__
#include <endian.h>
#define htonll(x) htobe64(x)
#define ntohll(x) be64toh(x)
#endif

#include "osc_t.h"
#include "IoState.h"
#include "IoSeq.h"
#include "IoNumber.h"

#include "IoNetBytesToCharacterConverterMethod.h"

static const char *protoId = "NetBytesToCharacterConverterMethod";

// Io's API
IoTag *IoNetBytesToCharacterConverterMethod_newTag(void *state) {
    IoTag *tag = IoTag_newWithName_(protoId);

    IoTag_state_(tag, state);

    IoTag_freeFunc_(tag, (IoTagFreeFunc *)IoNetBytesToCharacterConverterMethod_free);

    IoTag_cloneFunc_(tag, (IoTagCloneFunc *)IoNetBytesToCharacterConverterMethod_rawClone);

    return tag;
}

IoNetBytesToCharacterConverterMethod *IoNetBytesToCharacterConverterMethod_proto(void *state) {
    IoObject *self = IoObject_new(state);
    IoObject_tag_(self, IoNetBytesToCharacterConverterMethod_newTag(state));

    IoState_registerProtoWithFunc_(state, self, IoNetBytesToCharacterConverterMethod_proto);

    {
        IoMethodTable methodTable[] = {
            {"convert", IoNetBytesToCharacterConverterMethod_convert},
            {NULL, NULL},
        };

        IoObject_addMethodTable_(self, methodTable);
    }

    IoObject_setSlot_to_(self, IOSYMBOL("typeTag"), IOSYMBOL("c"));
    IoObject_setSlot_to_(self, IOSYMBOL("size"), IONUMBER(4));

    return self;
}

IoNetBytesToCharacterConverterMethod *IoNetBytesToCharacterConverterMethod_rawClone(IoNetBytesToCharacterConverterMethod *proto) {
    IoNetBytesToCharacterConverterMethod *self = IoObject_rawClonePrimitive(proto);
    return self;
}

IoNetBytesToCharacterConverterMethod *IoNetBytesToCharacterConverterMethod_new(void *state) {
    IoObject *proto = IoState_protoWithId_(state, protoId);
    return IOCLONE(proto);
}

void IoNetBytesToCharacterConverterMethod_free(IoNetBytesToCharacterConverterMethod *self) { }

//doc NetBytesToCharacterConverterMethod convert(value)
IoObject *IoNetBytesToCharacterConverterMethod_convert(IoNetBytesToCharacterConverterMethod *self, IoObject *locals, IoMessage *m) { 
    osc32_t converter;
    char *value = IoMessage_locals_cStringArgAt_(m, locals, 0);
    converter.u = ntohl(*(uint32_t*)value);

    return IoSeq_newWithData_length_(IOSTATE, &converter.c, 1);
}
