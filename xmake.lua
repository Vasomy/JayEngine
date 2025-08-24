add_rules("mode.debug", "mode.release")

add_cxflags("/utf-8",{force = true})
add_defines("FMT_UNICODE=0")
if is_mode("debug") then
    set_symbols("debug")
    set_optimize("faster")
    add_cxxflags("/MTd")
elseif is_mode("release") then
    set_symbols("hidden")
    set_optimize("fastest")
end

set_languages("c++17")

add_defines("_GLFW_WIN32")


target("Runtime") 
    add_defines("RUNTIME_EXPORT=1")

    add_links("gdi32")

    for _, dir in ipairs(os.dirs("Runtime/*/Public")) do
        add_includedirs(dir,{public = true})
        end

	set_kind("shared")
	add_files("Runtime/*/*/**.cpp")
    add_headerfiles("Runtime/*/Public/**.h")

    add_files("Runtime/EntryPoint")

    -- 添加第三方库
    add_includedirs("ThirdParty/includes",{public = true})

    add_headerfiles("ThirdParty/includes/**/*.h")
    add_headerfiles("ThirdParty/includes/**/*.hpp")

    add_linkdirs("ThirdParty/libs")
    add_links("glfw3.lib")

    add_files("ThirdParty/includes/**/*.cpp")
    add_files("ThirdParty/includes/**/*.c")

    -- 为第三方库添加宏定义
    add_defines("SPDLOG_COMPILED_LIB")
    add_defines("yaml_cpp_EXPORTS")


    

    
target("Test")
    set_targetdir("$(projectdir)/bin/$(mode)/$(arch)")

    add_deps("Runtime")
    set_kind("binary")
    add_files("Test/test.cpp")
    set_rundir("/")

    add_defines("RUNTIME_EXPORT=0")

