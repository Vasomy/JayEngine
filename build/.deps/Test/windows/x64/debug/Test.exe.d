{
    files = {
        [[build\.objs\Test\windows\x64\debug\Test\test.cpp.obj]]
    },
    values = {
        [[D:\visual\VC\Tools\MSVC\14.35.32215\bin\HostX64\x64\link.exe]],
        {
            "-nologo",
            "-dynamicbase",
            "-nxcompat",
            "-machine:x64",
            [[-libpath:build\windows\x64\debug]],
            "-debug",
            [[-pdb:F:\MyProject\JayEngine\bin\debug\x64\Test.pdb]],
            "Runtime.lib"
        }
    }
}