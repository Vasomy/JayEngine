{
    depfiles_format = "cl_json",
    files = {
        [[ThirdParty\includes\imgui\backends\imgui_impl_glfw.cpp]]
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
        \"Source\": \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\imgui\\\\backends\\\\imgui_impl_glfw.cpp\",\
        \"ProvidedModule\": \"\",\
        \"Includes\": [\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\imgui\\\\backends\\\\imgui_impl_glfw.h\",\
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
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glfw\\\\glfw3.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\stdint.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\gl\\\\gl.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\winapifamily.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\winpackagefamily.h\",\
            \"f:\\\\myproject\\\\jayengine\\\\thirdparty\\\\includes\\\\glfw\\\\glfw3native.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\windows.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\sdkddkver.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\excpt.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\windef.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\minwindef.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\specstrings.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\specstrings_strict.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\specstrings_undef.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\driverspecs.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\sdv_driverspecs.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\winnt.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\ctype.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\corecrt_wctype.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\kernelspecs.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\basetsd.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\guiddef.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\pshpack4.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\poppack.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\pshpack4.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\poppack.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\pshpack4.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\pshpack2.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\poppack.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\pshpack2.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\pshpack2.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\poppack.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\poppack.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\pshpack8.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\poppack.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\pshpack1.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\poppack.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\pshpack1.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\poppack.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\poppack.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\apiset.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\ktmtypes.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\winbase.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\apisetcconv.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\minwinbase.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\apiquery2.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\processenv.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\fileapifromapp.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\fileapi.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\debugapi.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\utilapiset.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\handleapi.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\errhandlingapi.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\fibersapi.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\namedpipeapi.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\profileapi.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\heapapi.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\ioapiset.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\synchapi.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\interlockedapi.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\processthreadsapi.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\sysinfoapi.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\memoryapi.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\enclaveapi.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\threadpoollegacyapiset.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\threadpoolapiset.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\jobapi.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\jobapi2.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\wow64apiset.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\libloaderapi.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\securitybaseapi.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\namespaceapi.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\systemtopologyapi.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\processtopologyapi.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\securityappcontainer.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\realtimeapiset.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\winerror.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\timezoneapi.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\wingdi.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\pshpack1.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\poppack.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\pshpack2.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\poppack.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\pshpack2.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\poppack.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\pshpack4.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\poppack.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\pshpack4.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\poppack.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\winuser.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\pshpack2.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\poppack.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\tvout.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\winnls.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\datetimeapi.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\stringapiset.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\winnls.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\wincon.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\wincontypes.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\consoleapi.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\consoleapi2.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\consoleapi3.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\winver.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\verrsrc.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\winreg.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\reason.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\winnetwk.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\wnnc.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\cderr.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\dde.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\ddeml.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\dlgs.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\lzexpand.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\mmsystem.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\mmsyscom.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\pshpack1.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\poppack.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\pshpack1.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\mciapi.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\mmsyscom.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\mmiscapi.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\mmsyscom.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\mmiscapi2.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\mmsyscom.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\playsoundapi.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\mmsyscom.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\mmeapi.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\mmsyscom.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\timeapi.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\mmsyscom.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\joystickapi.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\mmsyscom.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\poppack.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\nb30.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\rpc.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\pshpack8.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\rpcdce.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\rpcdcep.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\rpcnsi.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\rpcnterr.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\rpcasync.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\pshpack8.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\poppack.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\poppack.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\shellapi.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\winperf.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\pshpack8.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\poppack.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\winsock.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\inaddr.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\wincrypt.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\bcrypt.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\ncrypt.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\dpapi.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\winefs.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\winscard.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\wtypes.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\rpcndr.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\pshpack8.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\rpcnsip.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\rpcsal.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\poppack.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\wtypesbase.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\guiddef.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\winioctl.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\pshpack1.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\poppack.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\pshpack1.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\poppack.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\pshpack1.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\poppack.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\pshpack1.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\poppack.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\pshpack1.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\poppack.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\pshpack1.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\poppack.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\pshpack1.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\poppack.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\winsmcrd.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\winspool.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\prsht.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\pshpack8.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\poppack.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\ole2.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\pshpack8.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\objbase.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\pshpack8.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\combaseapi.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\pshpack8.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\stdlib.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\corecrt_malloc.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\corecrt_search.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\ucrt\\\\corecrt_wstdlib.h\",\
            \"d:\\\\visual\\\\vc\\\\tools\\\\msvc\\\\14.35.32215\\\\include\\\\limits.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\unknwnbase.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\objidlbase.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\guiddef.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\cguid.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\poppack.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\coml2api.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\objidl.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\unknwn.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\propidlbase.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\oaidl.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\urlmon.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\oleidl.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\servprov.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\msxml.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\propidl.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\poppack.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\oleauto.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\pshpack8.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\poppack.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\poppack.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\commdlg.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\prsht.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\shared\\\\stralign.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\winsvc.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\mcx.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\imm.h\",\
            \"d:\\\\windows kits\\\\10\\\\include\\\\10.0.22621.0\\\\um\\\\ime_cmodes.h\"\
        ],\
        \"ImportedModules\": [],\
        \"ImportedHeaderUnits\": []\
    }\
}"
}