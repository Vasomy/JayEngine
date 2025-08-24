{
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
        \"Source\": \"f:\\\\myproject\\\\jayengine\\\\runtime\\\\render\\\\private\\\\rendercamera.cpp\",\
        \"ProvidedModule\": \"\",\
        \"Includes\": [\
            \"f:\\\\myproject\\\\jayengine\\\\runtime\\\\render\\\\public\\\\rendercamera.h\",\
            \"f:\\\\myproject\\\\jayengine\\\\runtime\\\\core\\\\public\\\\math\\\\math.h\",\
            \"f:\\\\myproject\\\\jayengine\\\\runtime\\\\core\\\\public\\\\coredevelopmarco.h\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\glm.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\_fixes.hpp\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\cmath\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\yvals.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\yvals_core.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\vcruntime.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\sal.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\concurrencysal.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\vadefs.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\xkeycheck.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\crtdbg.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\corecrt.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\vcruntime_new_debug.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\vcruntime_new.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\crtdefs.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\use_ansi.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\cstdlib\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\math.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\corecrt_math.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\stdlib.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\corecrt_malloc.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\corecrt_search.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\stddef.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\corecrt_wstdlib.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\limits.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\xtr1common\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\intrin0.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\intrin0.inl.h\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\setup.hpp\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\cassert\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\assert.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\cstddef\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\simd\\\\platform.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\cstdint\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\stdint.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\type_traits\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\xstddef\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\initializer_list\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\climits\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\cfloat\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\float.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\limits\",\
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
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\isa_availability.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\cassert\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\assert.h\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\fwd.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\qualifier.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\setup.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\vec2.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\vector_bool2.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\type_vec2.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\type_vec2.inl\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\compute_vector_relational.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\setup.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\vector_bool2_precision.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\vector_float2.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\vector_float2_precision.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\vector_double2.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\vector_double2_precision.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\vector_int2.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\vector_int2_sized.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\scalar_int_sized.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\setup.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\vector_uint2.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\vector_uint2_sized.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\scalar_uint_sized.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\setup.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\vec3.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\vector_bool3.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\type_vec3.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\type_vec3.inl\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\vector_bool3_precision.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\vector_float3.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\vector_float3_precision.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\vector_double3.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\vector_double3_precision.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\vector_int3.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\vector_int3_sized.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\vector_uint3.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\vector_uint3_sized.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\vec4.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\vector_bool4.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\type_vec4.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\type_vec4.inl\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\vector_bool4_precision.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\vector_float4.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\vector_float4_precision.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\vector_double4.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\vector_double4_precision.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\setup.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\vector_int4.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\vector_int4_sized.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\vector_uint4.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\vector_uint4_sized.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\mat2x2.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\matrix_double2x2.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\type_mat2x2.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\type_mat2x2.inl\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\matrix.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\setup.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\mat2x3.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\matrix_double2x3.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\type_mat2x3.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\type_mat2x3.inl\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\matrix_double2x3_precision.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\matrix_float2x3.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\matrix_float2x3_precision.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\mat2x4.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\matrix_double2x4.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\type_mat2x4.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\type_mat2x4.inl\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\matrix_double2x4_precision.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\matrix_float2x4.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\matrix_float2x4_precision.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\mat3x2.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\matrix_double3x2.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\type_mat3x2.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\type_mat3x2.inl\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\matrix_double3x2_precision.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\matrix_float3x2.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\matrix_float3x2_precision.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\mat3x3.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\matrix_double3x3.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\type_mat3x3.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\type_mat3x3.inl\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\matrix_double3x3_precision.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\matrix_float3x3.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\matrix_float3x3_precision.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\mat3x4.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\matrix_double3x4.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\type_mat3x4.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\type_mat3x4.inl\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\matrix_double3x4_precision.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\matrix_float3x4.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\matrix_float3x4_precision.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\mat4x2.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\matrix_double4x2.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\type_mat4x2.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\type_mat4x2.inl\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\matrix_double4x2_precision.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\matrix_float4x2.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\matrix_float4x2_precision.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\mat4x3.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\matrix_double4x3.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\type_mat4x3.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\type_mat4x3.inl\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\matrix_double4x3_precision.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\matrix_float4x3.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\matrix_float4x3_precision.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\mat4x4.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\matrix_double4x4.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\type_mat4x4.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\type_mat4x4.inl\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\matrix_double4x4_precision.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\matrix_float4x4.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\matrix_float4x4_precision.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\func_matrix.inl\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\geometric.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\func_geometric.inl\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\exponential.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\type_vec1.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\type_vec1.inl\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\func_exponential.inl\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\vector_relational.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\setup.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\func_vector_relational.inl\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\_vectorize.hpp\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\cassert\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\assert.h\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\common.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\_fixes.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\func_common.inl\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\compute_common.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\setup.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\matrix_double2x2_precision.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\matrix_float2x2.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\matrix_float2x2_precision.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\trigonometric.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\setup.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\func_trigonometric.inl\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\packing.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\func_packing.inl\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\type_half.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\setup.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\type_half.inl\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\integer.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\func_integer.inl\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\intrin.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\setjmp.h\",\
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
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\ammintrin.h\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\gtc\\\\matrix_transform.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\matrix_projection.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\gtc\\\\constants.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\scalar_constants.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\setup.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\scalar_constants.inl\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\gtc\\\\constants.inl\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\matrix_projection.inl\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\matrix_clip_space.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\matrix_clip_space.inl\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\matrix_transform.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\matrix_transform.inl\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\gtc\\\\matrix_transform.inl\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\gtx\\\\quaternion.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\gtc\\\\quaternion.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\vector_relational.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\vector_relational.inl\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\type_float.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\setup.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\quaternion_common.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\quaternion_geometric.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\quaternion_geometric.inl\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\quaternion_common.inl\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\quaternion_float.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\type_quat.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\quaternion_relational.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\quaternion_relational.inl\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\type_quat.inl\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\quaternion_float_precision.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\quaternion_double.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\quaternion_double_precision.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\quaternion_trigonometric.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\quaternion_trigonometric.inl\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\quaternion_transform.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\quaternion_transform.inl\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\gtc\\\\quaternion.inl\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\gtc\\\\epsilon.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\setup.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\gtc\\\\epsilon.inl\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\quaternion_exponential.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\quaternion_exponential.inl\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\gtx\\\\norm.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\gtx\\\\component_wise.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\detail\\\\setup.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\gtx\\\\component_wise.inl\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\scalar_common.hpp\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\ext\\\\scalar_common.inl\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\gtx\\\\norm.inl\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glm\\\\gtx\\\\quaternion.inl\",\
            \"f:\\\\myproject\\\\jayengine\\\\runtime\\\\core\\\\public\\\\numeric\\\\jnumeric.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\numbers\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\numeric\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\xutility\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\__msvc_iter_core.hpp\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\utility\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\cstring\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\string.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\corecrt_memory.h\"\
        ],\
        \"ImportedModules\": [],\
        \"ImportedHeaderUnits\": []\
    }\
}",
    files = {
        [[Runtime\Render\Private\RenderCamera.cpp]]
    },
    depfiles_format = "cl_json"
}