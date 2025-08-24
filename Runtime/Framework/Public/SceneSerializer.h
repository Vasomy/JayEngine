#pragma once
#include"Scene.h"
#include"Serializer.h"
#include"Gen/SerializeTarget.h"
namespace Serialization
{
	const FString g_default_scene_serialize_path = "asset/Scenes/";
	class FSceneSerializier : public TSerializer<FScene>
	{
	public:

	public:
		FSceneSerializier(FScene* scene)
		{
			target = scene;
		}
		void Serialize(const FString& path)
		{
			FString to_path = g_default_scene_serialize_path + path;
			YAML::Emitter out;
			out << YAML::BeginMap;
			out << YAML::Key << "Scene" << YAML::Value << target->sceneName << '\n';
			out << YAML::Key << "Entities" << YAML::Value << YAML::BeginSeq;

			Yaml::FYamlGameObjectSerializer gos(g_null_gameobject,out);
			FGameObject obj{ g_null_entity_id,const_cast<FScene*>(target) };
			for (auto&ett : target->registry.view<entt::entity>())
			{
				obj.ettId = ett;
				Yaml::FYamlEntitySerializationContext::Serialize(obj, out);
			}

			out << YAML::EndSeq;
			out << YAML::EndMap;

			std::ofstream fout(to_path);
			fout << out.c_str();
		}
		void Deserialize(const FString& path)
		{

		}
	};
}