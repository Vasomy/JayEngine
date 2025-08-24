#pragma once

#include"CoreDevelopMarco.h"

#if OWN_CONTAINERS_FUNCTION

#else
#include<functional>
template<typename _ft>
using TFunction = std::function<_ft>;
#endif