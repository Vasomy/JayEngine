#include"CoreDevelopMarco.h"


#if OWN_CONTAINERS_STRING == J_TRUE

JClass(JString)
{
};

JClass(JStringView)
{
};

#elif OWN_CONTAINERS_STRING == J_FALSE
#include<string>

using FString = std::string;
//using FStringView = std::string_view;

#endif