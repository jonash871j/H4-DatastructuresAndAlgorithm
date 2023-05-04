#pragma once
#include "en_def.h"

namespace GLEngine::FileHandling
{
	class BinaryReader
	{
	private:
		std::ifstream& inFile;
		int fileSize;

	public:
		BinaryReader(std::ifstream& inFile, int fileSize)
			: inFile(inFile), fileSize(fileSize)
		{
		}

		int GetFileSize()
		{
			return fileSize;
		}

		char* ReadBuffer(size_t size)
		{
			char* buffer = new char[size];
			inFile.read(buffer, size);
			return buffer;
		}

		template<typename T>
		T ReadPrimitive()
		{
			char type[sizeof(T)];
			inFile.read(type, sizeof(T));
			return *(T*)type;
		}

		template<class T>
		T* ReadStructureHeap()
		{
			char* type = new char[sizeof(T)];
			inFile.read(type, sizeof(T));
			return (T*)type;
		}

		template<class T>
		T ReadStructure()
		{
			char type[sizeof(T)];
			inFile.read((char*)type, sizeof(T));
			return *(T*)&type;
		}

		template<class T>
		vector<T> ReadCollection(int length)
		{
			vector<T> types;
			types.reserve(length);

			for (int i = 0; i < length; i++)
				types.push_back(ReadStructure<T>());

			return types;
		}
	};

	class BinaryWriter
	{
	private:
		std::ofstream& outFile;
		int fileSize;

	public:
		BinaryWriter(std::ofstream& outFile, int fileSize)
			: outFile(outFile), fileSize(fileSize)
		{
		}

		int GetFileSize()
		{
			return fileSize;
		}

		template<class T>
		void WriteData(T t)
		{
			outFile.write((char*)&t, sizeof(T));
		}

		template<class T>
		void WriteData(T* t)
		{
			outFile.write((char*)t, sizeof(T));
		}
	};

	class File
	{
	public:
		export static string ReadAllAsString(string path);
		export static void ReadAsBinary(string path, const std::function<void(BinaryReader&)> func);
		export static void WriteAsBinary(string path, const std::function<void(BinaryWriter&)> func);
		export static int GetFileSize(string path);
		export static bool GetFileExistence(string path);
	};

	class Directory
	{
	public:
		export static void GetFilePaths(std::vector<string>& filePaths, string path);
	};

	class FilePath
	{
	public:
		export static string GetFilenameWithoutExtention(string path);
	};
};