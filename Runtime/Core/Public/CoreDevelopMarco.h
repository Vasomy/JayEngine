#pragma once

// �����ƿ�Core�㹦���Ƿ�ʹ�õ��Լ��������������ñ�׼�⣬�������⣩����

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

// 1Ϊʹ���Լ����������� 0 ��֮
#define OWN_CONTAINERS_STRING	J_FALSE
#define OWN_CONTAINERS_ARRAY	J_FALSE
#define OWN_CONTAINERS_HASH_MAP J_FALSE
#define OWN_MATH_VECTOR			J_FALSE
#define OWN_CONTAINERS_FUNCTION J_FALSE

#define DONE_LOG_SYSTEM			J_FALSE 

#define RUNTIME_COUT_INFO		J_TRUE

// where_ һ���ǳ��ִ���ķ��������࣬content_ Ϊԭ��
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

// Ϊ���Ա�������ɿ�����ʽ���õ�set����
#define GEN_CLASS_SET_INFO(data_type,data_name) data_type data_name; \
auto& Set##data_type(data_type& in##_##data_name){ data_name = in##_##data_name;return *this;}\
auto& Set##data_type(data_type&& in##_##data_name){data_name = in##_##data_name;return *this;}
#define GEN_CLASS_SET_INFO_RENAME(data_type,data_name,base_type) base_type data_name;\
auto& Set##data_type(base_type& in##_##data_name){ data_name = in##_##data_name;return *this;}\
base_type& Get##data_type(base_type&& in##_##data_name){return data_name;}


#define MAKE_NAME(content1,content2) content1##_##content2
#define REFLECTED_NAME(name) name

// Ϊ���Ա�������÷������
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

// λö�ٶ�����������룬��==��
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

// expr Ϊ�û�����Ҫ���������
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
// ��������̶�����ĳ���
// ����Ϊ�������������� T t[10],���ܴ���һ��ָ��
#ifndef __Count_Of
#define __Count_Of(Array) detail::d_count_of(Array)
#endif // !__Count_Of
