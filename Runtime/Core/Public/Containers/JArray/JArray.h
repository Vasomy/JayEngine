#pragma once
#include"CoreDevelopMarco.h"
#if OWN_CONTAINERS_ARRAY == J_TRUE

#elif OWN_CONTAINERS_ARRAY == J_FALSE
#include<vector>
template<typename T>
using TArray = std::vector<T>;
#elif

#endif // OWN_CONTAINERS_DEFINE
