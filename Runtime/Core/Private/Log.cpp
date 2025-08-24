#include"Log.h"
#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>
namespace Log
{
	TSmartPtr<spdlog::logger> FLog::coreLogger;
	TSmartPtr<spdlog::logger> FLog::editorLogger;

	void FLog::Init()
	{
		std::vector<spdlog::sink_ptr> coreLogSinks;
		coreLogSinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_st>());
		coreLogSinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_st>("EngineCore.log", true));

		coreLogSinks[0]->set_pattern("%^[%T] %n: %v%$");
		coreLogSinks[1]->set_pattern("[%T] [%l] %n: %v");

		coreLogger.reset(new spdlog::logger("Core",std::begin(coreLogSinks),std::end(coreLogSinks)));
		spdlog::register_logger(coreLogger);
		coreLogger->set_level(spdlog::level::trace);
		coreLogger->flush_on(spdlog::level::trace);

		std::vector<spdlog::sink_ptr> editorLogSinks;
		editorLogSinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_st>());
		editorLogSinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_st>("EngineEditor.log", true));
	
		editorLogSinks[0]->set_pattern("%^[%T] %n: %v%$");
		editorLogSinks[1]->set_pattern("[%T] [%l] %n: %v");

		editorLogger.reset(new spdlog::logger("Editor", std::begin(editorLogSinks), std::end(editorLogSinks)));
		spdlog::register_logger(editorLogger);
		editorLogger->set_level(spdlog::level::trace);
		editorLogger->flush_on(spdlog::level::trace);
	}

	TSmartPtr<spdlog::logger>& FLog::GetCoreLogger()
	{
		return coreLogger;
	}
	TSmartPtr<spdlog::logger>& FLog::GetEditorLogger()
	{
		return editorLogger;
	}
}