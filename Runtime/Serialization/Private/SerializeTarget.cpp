#include"Gen\SerializeTarget.h"
#include"Scene.h"

namespace Serialization::Yaml{

	int a[3][2] = { {1},{1,2} };
	using namespace YAML;
	YAML::Emitter& operator<<(YAML::Emitter& out, const glm::vec2& v)
	{
		out << YAML::Flow;
		out << YAML::BeginSeq << v.x << v.y << YAML::EndSeq;
		return out;
	}

	YAML::Emitter& operator<<(YAML::Emitter& out, const glm::vec3& v)
	{
		out << YAML::Flow;
		out << YAML::BeginSeq << v.x << v.y << v.z << YAML::EndSeq;
		return out;
	}

	YAML::Emitter& operator<<(YAML::Emitter& out, const glm::vec4& v)
	{
		out << YAML::Flow;
		out << YAML::BeginSeq << v.x << v.y << v.z << v.w << YAML::EndSeq;
		return out;
	}
	class FYamlComponentSerializer
	{
	public:
		virtual void Serialize(::FGameObject id, Emitter& out)
		{

		}
		virtual void Deserialize(::FGameObject id, YAML::detail::iterator_value& it)
		{

		}
	};

	class FYamlFTransformComponentSerializer : public FYamlComponentSerializer
	{
	public:
		void Serialize(::FGameObject id,YAML::Emitter& out)override
		{
			
			if (id.HasComponent<FTransformComponent>())
			{
				const auto& tc = id.GetComponent<FTransformComponent>();
				out << YAML::Key << "TransformComponent";
 				out << YAML::BeginMap;
				out << YAML::Key << "Translation" << YAML::Value << tc.transform.position;
				out << YAML::Key << "Rotation" << YAML::Value << tc.transform.rotation;
				out << YAML::Key << "Scale" << YAML::Value << tc.transform.scale;
				out << YAML::EndMap;
			}
		}
		void Deserialize(::FGameObject id, YAML::detail::iterator_value& it)override
		{

		}
	};

	FYamlEntitySerializationContext g_YamlEntitySerializationContext;

	FYamlFTransformComponentSerializer g_YamlFTransformComponentSerializer;

	FYamlEntitySerializationContext::FYamlEntitySerializationContext()
	{
		targets.push_back(&g_YamlFTransformComponentSerializer);
	}
	void FYamlEntitySerializationContext::Serialize(::FGameObject id, YAML::Emitter& out)
	{
		out << BeginMap;
		out << Key << "Entity" << Value << (int)id.GetEntityId();
		for (auto& target : g_YamlEntitySerializationContext.targets)
		{
			target->Serialize(id, out);
		}
		out << EndMap;
	}
	void FYamlEntitySerializationContext::Deserialize(FGameObject id, YAML::detail::iterator_value& it)
	{
	}
}