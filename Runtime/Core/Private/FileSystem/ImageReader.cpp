#include"FileSystem/ImageReader.h"

#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#include"stbimage/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include"stbimage/stb_image_write.h"

#endif // !STB_IMAGE_IMPLEMENTATION


FRawImageCache FRawImageCache::instance = FRawImageCache();

FRawImageInfo FImageReader::LoadRawImageFromFile(const char* file_path)
{
	// check if already read

	auto&cache = FRawImageCache::instance;
	if (cache.rawImageInfoMap.count(file_path))
	{
		return cache.rawImageInfoMap[file_path];
	}


	FRawImageInfo info;
	{
		//
		// load as float
		info.type = eFloat;
		info.data = stbi_loadf(file_path, &info.width, &info.height, &info.channels, 0);
	}

	//for (int i = 0; i < _msize(info.data)/4; i++)
	//{
	//	//std::cout << ((float*)info.data)[i] << '\n';
	//	((float*)info.data)[i] *= 255;
	//	if (i < 100)
	//		std::cout << ((float*)info.data)[i] << '\n';
	//}

	//stbi_write_jpg("EEEEE.jpg", info.width, info.height, info.channels, info.data, 0);
	//std::cout << "sasdasdsadasdasdasdasdsa\n";
	return info;
}