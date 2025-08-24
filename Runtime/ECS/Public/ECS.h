#pragma once

#include"entt\entt.hpp"


using ECSRegistry = entt::registry;

using EntityID = entt::entity;
constexpr static EntityID g_null_entity_id = (EntityID)0xffffffff;
