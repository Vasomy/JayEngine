#pragma once

#ifndef HASH_MAP_H

#define HASH_MAP_H
#include"CoreDevelopMarco.h"

#if OWN_CONTAINERS_HASH_MAP

#else
	#include<unordered_map>
	#include<unordered_set>

	template<typename key,typename val>
	using HashMap = std::unordered_map<key, val>;
	template<typename key>
	using HashSet = std::unordered_set<key>;
#endif

#endif // !HASH_MAP_H
