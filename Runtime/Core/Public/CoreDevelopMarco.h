#pragma once

// 用于掌控Core层功能是否使用的自己开发（或者引用标准库，第三方库）开关

#ifndef CORE_DEVELOP_MARCO
#define CORE_DEVELOP_MARCO

#define __parse_str(str) #str

#define DLLIMPORT __declspec(dllimport)
#define DLLEXPORT __declspec(dllexport)

#ifdef RUNTIME_EXPORT
#define API DLLEXPORT
#else
#define API DLLIMPORT
#endif // RUNTIME_EXPORT

#define API DLLEXPORT

#define THIS this

#define J_TRUE					1
#define J_FALSE					0

// 1为使用自己开发的内容 0 反之
#define OWN_CONTAINERS_STRING	J_FALSE
#define OWN_CONTAINERS_ARRAY	J_FALSE
#define OWN_CONTAINERS_HASH_MAP J_FALSE
#define OWN_MATH_VECTOR			J_FALSE
#define OWN_CONTAINERS_FUNCTION J_FALSE

#define DONE_LOG_SYSTEM			J_FALSE 

#define RUNTIME_COUT_INFO		J_TRUE

// where_ 一般是出现错误的方法或者类，content_ 为原因
#define MAKE_ERROR_INFO(where_,content_)__parse_str([##where_##]::[ERROR]::##content_)
#define MAKE_WARNING_INFO(where_,content_)__parse_str([##where_##]::[WARNING]::##content_)

#define RUNTIME_COUT_ERROR_INFO(x,y)
#if		RUNTIME_COUT_INFO == J_TRUE

#define RUNTIME_COUT_ERROR_INFO(reason_where_,content) std::cout<<MAKE_ERROR_INFO(reason_where_,content)<<'\n';

#endif // 


#define LOG_INFO_MARCO(where_,content_) std::cout<<__parse_str([##where_##]::[LOG]::##content_)<<'\n';

#if DONE_LOG_SYSTEM == J_TRUE

#endif // DONE_LOG_SYSTEM == J_TRUE


#define FORCE_INLINE __forceinline
#define INLINE		 inline
#define CONSTEXPR    constexpr
#define NOEXCEPT     noexcept

#define COUT_ERROR_INFO(where_,content)std::cout<<__parse_str([##where_##]::[ERROR]::)<<content<<'\n';
#define LOG_ERROR_REASON(reason,content)RUNTIME_COUT_ERROR_INFO(reason,content)
#define LOG_WARRING_INFO(where_,content_) std::cout<<MAKE_WARNING_INFO(where_,content_)<<'\n';

#endif


#ifndef GENERATE_MARCO
#define GENERATE_MARCO

// 为类成员变量生成可以链式调用的set函数
#define GEN_CLASS_SET_INFO(data_type,data_name) data_type data_name; \
auto& Set##data_type(data_type& in##_##data_name){ data_name = in##_##data_name;return *this;}\
auto& Set##data_type(data_type&& in##_##data_name){data_name = in##_##data_name;return *this;}
#define GEN_CLASS_SET_INFO_RENAME(data_type,data_name,base_type) base_type data_name;\
auto& Set##data_type(base_type& in##_##data_name){ data_name = in##_##data_name;return *this;}\
base_type& Get##data_type(base_type&& in##_##data_name){return data_name;}


#define MAKE_NAME(content1,content2) content1##_##content2
#define REFLECTED_NAME(name) name

// 为类成员变量设置反射代码
#define GEN_REFLECTION_INFO(clazz,name)\
\
private:\
\
	clazz REFLECTED_NAME(name);\
\
public:\
\
	auto& Set##clazz##_##name(clazz& in##name) { REFLECTED_NAME(name) = in##name; return *this; }\
\
	clazz& Get##clazz##_##name () { return REFLECTED_NAME(name); }

// 位枚举定义运算符（与，或，==）
#define OPERATOR_ENUM(enum_type,base_type) \
INLINE CONSTEXPR enum_type operator|(enum_type&left,enum_type&right) NOEXCEPT \
{\
	return (enum_type)(static_cast<base_type>(left)|static_cast<base_type>(right));\
}\
INLINE CONSTEXPR enum_type operator&(enum_type& left, enum_type& right) NOEXCEPT \
{\
	return (enum_type)(static_cast<base_type>(left) & static_cast<base_type>(right));\
}\
INLINE CONSTEXPR bool operator==(enum_type& left, enum_type& right) NOEXCEPT \
{\
return (static_cast<base_type>(left) == static_cast<base_type>(right));\
}\

// expr 为用户不想要发生的情况
#define AssertIfCheckResult(expr , reason) if ( ( expr ) == J_TRUE ) \
{ LOG_ERROR_REASON(expr,reason) }





#endif // !GENERATE_MARCO


namespace detail
{
	template<typename T,size_t size>
	size_t d_count_of(T(&array)[size])
	{
		return size;
	}
}                                       
// 计算给定固定数组的长度
// 必须为这样声明的数组 T t[10],不能传递一个指针
#ifndef __Count_Of
#define __Count_Of(Array) detail::d_count_of(Array)
#endif // !__Count_Of
