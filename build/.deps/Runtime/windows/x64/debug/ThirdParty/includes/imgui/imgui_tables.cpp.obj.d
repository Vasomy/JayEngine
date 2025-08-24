{
    depfiles_format = "cl_json",
    files = {
        [[ThirdParty\includes\imgui\imgui_tables.cpp]]
    },
    values = {
        [[D:\visual\VC\Tools\MSVC\14.35.32215\bin\HostX64\x64\cl.exe]],
        {
            "-nologo",
            "-Zi",
            "-FS",
            [[-Fdbuild\windows\x64\debug\compile.Runtime.pdb]],
            "-Ox",
            "-std:c++17",
            [[-IRuntime\Component\Public]],
            [[-IRuntime\Core\Public]],
            [[-IRuntime\ECS\Public]],
            [[-IRuntime\Engine\Public]],
            [[-IRuntime\EntryPoint\Public]],
            [[-IRuntime\Framework\Public]],
            [[-IRuntime\Input\Public]],
            [[-IRuntime\Render\Public]],
            [[-IRuntime\RHI\Public]],
            [[-IRuntime\RHIOpenGL3\Public]],
            [[-IRuntime\Serialization\Public]],
            [[-IRuntime\TEST\Public]],
            [[-IRuntime\WindowClient\Public]],
            [[-IThirdParty\includes]],
            [[-Ibuild\.gens\Runtime\windows\x64\debug\platform\windows\idl]],
            "-DFMT_UNICODE=0",
            "-D_GLFW_WIN32",
            "-DRUNTIME_EXPORT=1",
            "-DSPDLOG_COMPILED_LIB",
            "-Dyaml_cpp_EXPORTS",
            "/EHsc",
            "/MTd",
            "/utf-8"
        }
    },
    depfiles = "{\
    \"Version\": \"1.2\",\
    \"Data\": {\
        \"Source\": \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\imgui\\\\imgui_tables.cpp\",\
        \"ProvidedModule\": \"\",\
        \"Includes\": [\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\imgui\\\\imgui.h\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\imgui\\\\imconfig.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\float.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\corecrt.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\vcruntime.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\sal.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\concurrencysal.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\vadefs.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\stdarg.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\stddef.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\string.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\corecrt_memory.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\corecrt_memcpy_s.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\errno.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\vcruntime_string.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\corecrt_wstring.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\assert.h\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\imgui\\\\imgui_internal.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\stdio.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\corecrt_wstdio.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\corecrt_stdio_config.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\stdlib.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\corecrt_malloc.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\corecrt_search.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\corecrt_wstdlib.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\limits.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\math.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\corecrt_math.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\immintrin.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\wmmintrin.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\nmmintrin.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\smmintrin.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\tmmintrin.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\pmmintrin.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\emmintrin.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\xmmintrin.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\mmintrin.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\malloc.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\zmmintrin.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\stdint.h\"\
        ],\
        \"ImportedModules\": [],\
        \"ImportedHeaderUnits\": []\
    }\
}"
}