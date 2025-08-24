#pragma once
#ifndef SERIALIZE_TARGET_H
#define SERIALIZE_TARGET_H
#include"yaml-cpp\yaml.h"
#include"Containers\Containers.h"
#include"Math\Math.h"
class FGameObject;
#include"Serializer.h"
namespace Serialization::Yaml {

	using namespace YAML;
	
	class FYamlComponentSerializer;
	class FYamlEntitySerializationContext
	{
	public:
		FYamlEntitySerializationContext();
		static void Serialize(FGameObject id, YAML::Emitter& out);
		static void Deserialize(FGameObject id,YAML::detail::iterator_value& it);
		TArray<FYamlComponentSerializer*> targets;
	};

	class FYamlGameObjectSerializer : public TSerializer<FGameObject>
	{
	public:
		FYamlGameObjectSerializer(const FGameObject& obj, YAML::Emitter& out)
			:out_(out)
		{
			target = &obj;
		}
		virtual void Serialize(const FString& path) override
		{
			
		}
	private:
		Emitter& out_;
	};
	
}
#endif // 
