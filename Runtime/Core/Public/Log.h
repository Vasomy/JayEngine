#pragma once
#ifndef CORE_LOG_H
#define CORE_LOG_H
#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)
#include"SmartPtr/SmartPtr.h"


namespace Log
{
	class API FLog
	{
	public:
		static void Init();
		static TSmartPtr<spdlog::logger>& GetCoreLogger();
		static TSmartPtr<spdlog::logger>& GetEditorLogger();
	private:
		static TSmartPtr<spdlog::logger> coreLogger;
		static TSmartPtr<spdlog::logger> editorLogger;
	};
}

#ifndef LOG_MARCO
#define LOG_MARCO
	
	#define MAKE_LOG_INFO(msg) #msg

	#define CORE_LOG_INFO(msg) ::Log::FLog::GetCoreLogger()->info(msg);
	#define CORE_LOG_ERROR(msg) ::Log::FLog::GetCoreLogger()->error(msg);
	
	#define CORE_LOG_INFO(where_,msg) ::Log::FLog::GetCoreLogger()->info(MAKE_LOG_INFO(where_##msg));
	#define CORE_LOG_ERROR(where_,msg) ::Log::FLog::GetCoreLogger()->error(MAKE_LOG_INFO(where_##msg));

	// assert & log
	#include<assert.h>
	#define CORE_ASSERT_ERROR(check,msg) if((check) == false){ CORE_LOG_ERROR(msg);assert(msg,check); }
#endif // !LOG_MARCO


#endif // !CORE_LOG_H
