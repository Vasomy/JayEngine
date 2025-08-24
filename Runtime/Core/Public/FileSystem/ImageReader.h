#pragma once

#ifndef IMAGE_READER_H
#define IMAGE_READER_H

#include"Numeric\JNumeric.h"

#include"Containers\Containers.h"


struct FRawImageInfo
{
	int32 width;
	int32 height;
	int32 channels;
	EBaseType type = eUnknow;

	void* data = nullptr;
};

class FImageReader
{
public:
	FImageReader() {}
	~FImageReader() {}

	static FRawImageInfo LoadRawImageFromFile(const char* file_path);

};
// 所有已经加载的图片会储存在这里

class FRawImageCache
{
	HashMap<FString, FRawImageInfo>rawImageInfoMap;

public:
	friend class FImageReader;
	static FRawImageCache instance;
};



#endif // !IMAGE_READER_H
