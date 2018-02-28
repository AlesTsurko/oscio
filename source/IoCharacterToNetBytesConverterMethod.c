//metadoc CharacterToNetBytesConverterMethod copyright Tonika, 2018
//metadoc CharacterToNetBytesConverterMethod license MIT
//metadoc CharacterToNetBytesConverterMethod category API
//metadoc CharacterToNetBytesConverterMethod description Converts character to netbytes.

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

#include "IoCharacterToNetBytesConverterMethod.h"

static const char *protoId = "CharacterToNetBytesConverterMethod";

// Io's API
IoTag *IoCharacterToNetBytesConverterMethod_newTag(void *state) {
    IoTag *tag = IoTag_newWithName_(protoId);

    IoTag_state_(tag, state);

    IoTag_freeFunc_(tag, (IoTagFreeFunc *)IoCharacterToNetBytesConverterMethod_free);

    IoTag_cloneFunc_(tag, (IoTagCloneFunc *)IoCharacterToNetBytesConverterMethod_rawClone);

    return tag;
}

IoCharacterToNetBytesConverterMethod *IoCharacterToNetBytesConverterMethod_proto(void *state) {
    IoObject *self = IoObject_new(state);
    IoObject_tag_(self, IoCharacterToNetBytesConverterMethod_newTag(state));

    IoState_registerProtoWithFunc_(state, self, IoCharacterToNetBytesConverterMethod_proto);

    {
        IoMethodTable methodTable[] = {
            {"convert", IoCharacterToNetBytesConverterMethod_convert},
            {NULL, NULL},
        };

        IoObject_addMethodTable_(self, methodTable);
    }

    IoObject_setSlot_to_(self, IOSYMBOL("typeTag"), IOSYMBOL("c"));
    IoObject_setSlot_to_(self, IOSYMBOL("size"), IONUMBER(4));

    return self;
}

IoCharacterToNetBytesConverterMethod *IoCharacterToNetBytesConverterMethod_rawClone(IoCharacterToNetBytesConverterMethod *proto) {
    IoCharacterToNetBytesConverterMethod *self = IoObject_rawClonePrimitive(proto);
    return self;
}

IoCharacterToNetBytesConverterMethod *IoCharacterToNetBytesConverterMethod_new(void *state) {
    IoObject *proto = IoState_protoWithId_(state, protoId);
    return IOCLONE(proto);
}

void IoCharacterToNetBytesConverterMethod_free(IoCharacterToNetBytesConverterMethod *self) { }

//doc CharacterToNetBytesConverterMethod convert(value)
IoObject *IoCharacterToNetBytesConverterMethod_convert(IoCharacterToNetBytesConverterMethod *self, IoObject *locals, IoMessage *m) { 
    osc32_t converter;
    converter.c = *IoMessage_locals_cStringArgAt_(m, locals, 0);
    converter.u = htonl(converter.u);

    return IoSeq_newWithData_length_(IOSTATE, converter.b, 4);
}
