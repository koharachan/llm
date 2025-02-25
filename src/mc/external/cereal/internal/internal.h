#pragma once

#include "mc/_HeaderOutputPredefine.h"

// auto generated inclusion list
#include "mc/deps/cereal/schema/BasicSchema.h"
#include "mc/deps/cereal/schema/ReflectedType.h"
#include "mc/deps/cereal/schema/SchemaTraits.h"

// auto generated forward declare list
// clang-format off
namespace cereal { class DynamicValue; }
namespace cereal { class SerializerContext; }
namespace cereal { struct ReflectionCtx; }
namespace cereal { struct SchemaDescription; }
namespace cereal { struct SchemaReader; }
namespace cereal { struct SchemaWriter; }
namespace cereal::internal { class BasicSchema; }
namespace cereal::internal { struct UserProperty; }
namespace cereal::util::internal { struct StringViewHash; }
// clang-format on

namespace cereal::internal {
// functions
// NOLINTBEGIN
MCAPI void derefAndLoad(
    ::cereal::internal::BasicSchema const& schema,
    ::cereal::SchemaReader&                reader,
    ::entt::meta_any&                      any,
    ::entt::meta_any const&                udata,
    ::cereal::SerializerContext&           context
);

MCAPI ::cereal::DynamicValue
dynamicValueFromProp(::cereal::ReflectionCtx const& ctx, ::cereal::internal::UserProperty const& prop);

MCAPI void fillEnumDescription(
    ::cereal::ReflectionCtx const&                   ctx,
    ::cereal::SchemaDescription&                     ret,
    ::entt::meta_type const&                         type,
    ::cereal::internal::BasicSchema::DescriptionMode mode
);

MCAPI ::cereal::internal::ReflectedType getReflectedType(::entt::meta_type const& type);

MCAPI ::std::string_view getSchemaName(::cereal::ReflectionCtx const& ctx, ::entt::type_info const& info);

MCAPI ::entt::dense_map<
    ::std::string,
    ::cereal::internal::UserProperty,
    ::cereal::util::internal::StringViewHash,
    ::std::equal_to<void>>*
getUserProperties(::entt::meta_data const& data);

MCAPI ::entt::dense_map<
    ::std::string,
    ::cereal::internal::UserProperty,
    ::cereal::util::internal::StringViewHash,
    ::std::equal_to<void>>*
getUserProperties(::entt::meta_type const& type);

MCAPI void iterateKeyValueAssociativeContainer(
    ::cereal::internal::BasicSchema const& keySchema,
    ::cereal::internal::BasicSchema const& mappedSchema,
    ::cereal::SchemaReader&                reader,
    ::entt::meta_any&                      any,
    ::entt::meta_any const&                udata,
    ::cereal::SerializerContext&           context
);

MCAPI void iterateSequenceContainer(
    ::cereal::internal::BasicSchema const& schema,
    ::cereal::SchemaReader&                reader,
    ::entt::meta_any&                      any,
    ::entt::meta_any const&                udata,
    ::cereal::SerializerContext&           context
);

MCAPI void loadEnumValue(
    ::entt::meta_type const&     type,
    ::cereal::SchemaReader&      reader,
    ::entt::meta_any&            any,
    ::cereal::SerializerContext& context
);

MCAPI ::cereal::internal::BasicSchema const* lookup(::cereal::ReflectionCtx const& ctx, ::entt::type_info info);

MCAPI void overrideCheck(::entt::meta_type type, uint currentMetaData, ::cereal::internal::SchemaTraits traits);

MCAPI ::std::map<::std::string, ::cereal::DynamicValue> pickUserProperties(
    ::cereal::ReflectionCtx const& ctx,
    ::entt::dense_map<
        ::std::string,
        ::cereal::internal::UserProperty,
        ::cereal::util::internal::StringViewHash,
        ::std::equal_to<void>> const& userProps
);

MCAPI void saveEnumValue(
    ::entt::meta_any const&      enumValue,
    ::entt::meta_type const&     type,
    ::cereal::SchemaWriter&      writer,
    ::cereal::SerializerContext& context
);

MCAPI void saveKeyValueAssociativeContainer(
    ::entt::meta_any const&                any,
    ::cereal::internal::BasicSchema const& keySchema,
    ::cereal::internal::BasicSchema const& mappedSchema,
    ::cereal::SchemaWriter&                writer,
    ::cereal::SerializerContext&           context
);

MCAPI void saveSequenceContainer(
    ::cereal::internal::BasicSchema const& schema,
    ::cereal::SchemaWriter&                value,
    ::entt::meta_any const&                any,
    ::cereal::SerializerContext&           context
);

MCAPI ::std::string toString(double d);
// NOLINTEND

} // namespace cereal::internal
