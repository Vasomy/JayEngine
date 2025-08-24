#pragma once
#ifndef FILE_SYSTEM_H
#define FILE_SYSTEM_H
#include"Numeric\JNumeric.h"
#include"CoreDevelopMarco.h"
#define SHADER_DIRECTORY(x) __parse_str(Asset/Shaders/x)

#include"Containers\Containers.h"

#include"ImageReader.h"

#include<iostream>
#include<istream>
#include<fstream>
#include<filesystem>

class API FFileSystem
{
public:
	FFileSystem() {
		
	}
	static void Check();
};

class FFileStream
{
public:
	FFileStream(const FString& path);
	FFileStream(const FFileStream& other) = delete;
	FFileStream(FFileStream&& other) = delete;

	FFileStream(){}
	~FFileStream() {
		if (fs.is_open())
		{
			fs.close();
		}
	}

	bool Open(const FString& path);

	TArray<char8> ReadAllInChar();
	TArray<char16>ReadAllInChar16(); // wchar_t
	FString ReadAll();
	FString ReadOneLine();
	TArray<FString> ReadByLines();

	void Close()
	{
		if(fs.is_open())
			fs.close();
	}

private:
	FString path;
	_STD fstream fs;
};

#endif // !FILE_SYSTEM_H
