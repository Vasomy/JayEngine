#include"FileSystem\FileSystem.h"
#include<codecvt>
#include<sstream>
#include"Log.h"
FFileSystem fs;

void FFileSystem::Check() {
	CORE_LOG_INFO(std::filesystem::current_path().string().c_str());
}

FFileStream::FFileStream(const FString& path)
{
	fs = std::fstream();
	fs.open(path);
}

bool FFileStream::Open(const FString& path)
{
	fs.open(path);
	if (!fs.is_open())
	{
		std::cout << "[Error] Core::FFileSystem::Failed to open file at "<<path<<"!\n";
		return false;
	}
	return true;
}

TArray<char8>FFileStream::ReadAllInChar()
{
	if (fs.is_open() == false)
		return {};
	FString content = ReadAll();
	TArray<char8>ret{ content.begin(), content.end() };
	ret.emplace_back('\0');
	return ret;
}

TArray<char16>FFileStream::ReadAllInChar16()
{
	if (fs.is_open() == false)
		return {};
	FString content = ReadAll();
	// in c++17 
	std::wstring_convert<std::codecvt_utf8<wchar_t>>convert;
	std::wstring wcontent = convert.from_bytes(content);
	return TArray<char16>{wcontent.begin(), wcontent.end()};
}

FString FFileStream::ReadAll()
{
	std::stringstream fileStream;
	fileStream << fs.rdbuf();
	FString ret = fileStream.str();
	return std::move(ret);
}

FString FFileStream::ReadOneLine()
{
	FString ret;
	std::getline(fs, ret);
	return ret;
}

TArray<FString> FFileStream::ReadByLines()
{
	TArray<FString> ret;
	do
	{
		ret.push_back(FString());
	} while (std::getline(fs, ret.back()));
	return ret;
}