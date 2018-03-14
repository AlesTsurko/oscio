//metadoc DoubleToNetBytesConverterMethod copyright Tonika, 2018
//metadoc DoubleToNetBytesConverterMethod license MIT
//metadoc DoubleToNetBytesConverterMethod category API
//metadoc DoubleToNetBytesConverterMethod description Converts double to netbytes.

#include <string.h>
#if _WIN32
#include <winsock2.h>
#else
#include <netinet/in.h>
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

#include "IoDoubleToNetBytesConverterMethod.h"

static const char *protoId = "DoubleToNetBytesConverterMethod";

// Io's API
IoTag *IoDoubleToNetBytesConverterMethod_newTag(void *state) {
    IoTag *tag = IoTag_newWithName_(protoId);

    IoTag_state_(tag, state);

    IoTag_freeFunc_(tag, (IoTagFreeFunc *)IoDoubleToNetBytesConverterMethod_free);

    IoTag_cloneFunc_(tag, (IoTagCloneFunc *)IoDoubleToNetBytesConverterMethod_rawClone);

    return tag;
}

IoDoubleToNetBytesConverterMethod *IoDoubleToNetBytesConverterMethod_proto(void *state) {
    IoObject *self = IoObject_new(state);
    IoObject_tag_(self, IoDoubleToNetBytesConverterMethod_newTag(state));

    IoState_registerProtoWithFunc_(state, self, IoDoubleToNetBytesConverterMethod_proto);

    {
        IoMethodTable methodTable[] = {
            {"convert", IoDoubleToNetBytesConverterMethod_convert},
            {NULL, NULL},
        };

        IoObject_addMethodTable_(self, methodTable);
    }

    IoObject_setSlot_to_(self, IOSYMBOL("typeTag"), IOSYMBOL("d"));
    IoObject_setSlot_to_(self, IOSYMBOL("size"), IONUMBER(8));

    return self;
}

IoDoubleToNetBytesConverterMethod *IoDoubleToNetBytesConverterMethod_rawClone(IoDoubleToNetBytesConverterMethod *proto) {
    IoDoubleToNetBytesConverterMethod *self = IoObject_rawClonePrimitive(proto);
    return self;
}

IoDoubleToNetBytesConverterMethod *IoDoubleToNetBytesConverterMethod_new(void *state) {
    IoObject *proto = IoState_protoWithId_(state, protoId);
    return IOCLONE(proto);
}

void IoDoubleToNetBytesConverterMethod_free(IoDoubleToNetBytesConverterMethod *self) { }

//doc DoubleToNetBytesConverterMethod convert(value)
IoObject *IoDoubleToNetBytesConverterMethod_convert(IoDoubleToNetBytesConverterMethod *self, IoObject *locals, IoMessage *m) { 
    osc64_t converter;
    converter.d = IoMessage_locals_doubleArgAt_(m, locals, 0);
    converter.u = htonll(converter.u);

    return IoSeq_newWithData_length_(IOSTATE, converter.b, 8);
}
