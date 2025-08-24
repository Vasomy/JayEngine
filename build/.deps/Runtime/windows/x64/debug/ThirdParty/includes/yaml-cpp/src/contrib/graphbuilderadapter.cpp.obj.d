{
    depfiles_format = "cl_json",
    files = {
        [[ThirdParty\includes\yaml-cpp\src\contrib\graphbuilderadapter.cpp]]
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
        \"Source\": \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\yaml-cpp\\\\src\\\\contrib\\\\graphbuilderadapter.cpp\",\
        \"ProvidedModule\": \"\",\
        \"Includes\": [\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\yaml-cpp\\\\src\\\\contrib\\\\graphbuilderadapter.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\cstdlib\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\yvals_core.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\vcruntime.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\sal.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\concurrencysal.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\vadefs.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\xkeycheck.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\math.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\corecrt_math.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\corecrt.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\stdlib.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\corecrt_malloc.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\corecrt_search.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\stddef.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\corecrt_wstdlib.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\limits.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\map\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\tuple\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\__msvc_iter_core.hpp\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\utility\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\type_traits\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\cstdint\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\stdint.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\xstddef\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\cstddef\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\xtr1common\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\initializer_list\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\xtree\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\xmemory\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\limits\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\cfloat\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\float.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\climits\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\cwchar\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\cstdio\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\stdio.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\corecrt_wstdio.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\corecrt_stdio_config.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\wchar.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\corecrt_memcpy_s.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\errno.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\vcruntime_string.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\corecrt_wconio.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\corecrt_wctype.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\corecrt_wdirect.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\corecrt_wio.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\corecrt_share.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\corecrt_wprocess.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\corecrt_wstring.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\corecrt_wtime.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\sys\\\\stat.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\sys\\\\types.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\intrin0.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\intrin0.inl.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\isa_availability.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\new\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\exception\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\yvals.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\crtdbg.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\vcruntime_new_debug.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\vcruntime_new.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\crtdefs.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\use_ansi.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\malloc.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\vcruntime_exception.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\eh.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\corecrt_terminate.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\xatomic.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\xutility\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\cstring\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\string.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\corecrt_memory.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\xnode_handle.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\xpolymorphic_allocator.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\stack\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\deque\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\yaml-cpp\\\\anchor.h\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\yaml-cpp\\\\contrib\\\\anchordict.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\vector\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\yaml-cpp\\\\emitterstyle.h\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\yaml-cpp\\\\eventhandler.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\string\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\xstring\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\iosfwd\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\cctype\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\ctype.h\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\yaml-cpp\\\\contrib\\\\graphbuilder.h\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\yaml-cpp\\\\mark.h\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\yaml-cpp\\\\dll.h\"\
        ],\
        \"ImportedModules\": [],\
        \"ImportedHeaderUnits\": []\
    }\
}"
}