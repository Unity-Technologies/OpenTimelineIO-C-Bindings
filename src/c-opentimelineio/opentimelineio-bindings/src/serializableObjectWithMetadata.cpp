#include "copentimelineio/serializableObjectWithMetadata.h"
#include <opentimelineio/serializableObjectWithMetadata.h>
#include <string.h>

#ifdef __cplusplus
extern "C"
{
#endif
    SerializableObjectWithMetadata* SerializableObjectWithMetadata_create(
        const char* name, AnyDictionary* metadata)
    {
        std::string name_str = std::string();
        if(name != NULL) { name_str = name; }
        OTIO_NS::AnyDictionary metadataDictionary = OTIO_NS::AnyDictionary();
        if(metadata != NULL)
        {
            metadataDictionary =
                *reinterpret_cast<OTIO_NS::AnyDictionary*>(metadata);
        }
        return reinterpret_cast<SerializableObjectWithMetadata*>(
            new OTIO_NS::SerializableObjectWithMetadata(
                name_str, metadataDictionary));
    }
    const char*
    SerializableObjectWithMetadata_name(SerializableObjectWithMetadata* self)
    {
        std::string returnStr =
            reinterpret_cast<OTIO_NS::SerializableObjectWithMetadata*>(self)
                ->name();
        char* charPtr = (char*) malloc((returnStr.size() + 1) * sizeof(char));
        strcpy(charPtr, returnStr.c_str());
        return charPtr;
    }
    void SerializableObjectWithMetadata_set_name(
        SerializableObjectWithMetadata* self, const char* name)
    {
        reinterpret_cast<OTIO_NS::SerializableObjectWithMetadata*>(self)
            ->set_name(name);
    }
    AnyDictionary* SerializableObjectWithMetadata_metadata(
        SerializableObjectWithMetadata* self)
    {
        OTIO_NS::AnyDictionary anyDictionary =
            reinterpret_cast<OTIO_NS::SerializableObjectWithMetadata*>(self)
                ->metadata();
        return reinterpret_cast<AnyDictionary*>(
            new OTIO_NS::AnyDictionary(anyDictionary));
    }
    bool SerializableObjectWithMetadata_possibly_delete(
        SerializableObjectWithMetadata* self)
    {
        return SerializableObject_possibly_delete((SerializableObject*) self);
    }
    bool SerializableObjectWithMetadata_to_json_file(
        SerializableObjectWithMetadata* self,
        const char*                     file_name,
        OTIOErrorStatus*                error_status,
        int                             indent)
    {
        return SerializableObject_to_json_file(
            (SerializableObject*) self, file_name, error_status, indent);
    }
    const char* SerializableObjectWithMetadata_to_json_string(
        SerializableObjectWithMetadata* self,
        OTIOErrorStatus*                error_status,
        int                             indent)
    {
        return SerializableObject_to_json_string(
            (SerializableObject*) self, error_status, indent);
    }
    bool SerializableObjectWithMetadata_is_equivalent_to(
        SerializableObjectWithMetadata* self, SerializableObject* other)
    {
        return SerializableObject_is_equivalent_to(
            (SerializableObject*) self, other);
    }
    SerializableObjectWithMetadata* SerializableObjectWithMetadata_clone(
        SerializableObjectWithMetadata* self, OTIOErrorStatus* error_status)
    {
        return (SerializableObjectWithMetadata*) SerializableObject_clone(
            (SerializableObject*) self, error_status);
    }
    bool SerializableObjectWithMetadata_is_unknown_schema(
        SerializableObjectWithMetadata* self)
    {
        return SerializableObject_is_unknown_schema((SerializableObject*) self);
    }
    const char* SerializableObjectWithMetadata_schema_name(
        SerializableObjectWithMetadata* self)
    {
        return SerializableObject_schema_name((SerializableObject*) self);
    }
    int SerializableObjectWithMetadata_schema_version(
        SerializableObjectWithMetadata* self)
    {
        return SerializableObject_schema_version((SerializableObject*) self);
    }
#ifdef __cplusplus
}
#endif
