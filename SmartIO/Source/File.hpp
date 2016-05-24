////////////////////////////////////////////////////
//	
//	© 2015 Turbulant Games, all rights reserved
//
//	File: File.hpp
//
//	CREATION
//  Creator: JAMES	
//	Time Created: 5/24/2016 3:27 PM
//
//	EDITS
//	Last Editor Name: JAMES
//	Last Edit Time: 5/24/2016 3:27 PM
//
////////////////////////////////////////////////////
#ifndef _FILE_H_
#define _FILE_H_

namespace SmartIO
{
	//!The file class contains the functions that allow the user to easily
	//manipulate the files found in physical folder structure of the system. 
	//
	//@author James Mills
	//@version 1.0
	class File
	{
	public:
		static bool Create(const char* aFileName);

		static bool Delete(const char* aFileName);

		static bool Exists(const char* aFileName);

		static bool Encrypt(const char* aFileName);

		static bool Decrypt(const char* aFileName);

		static bool Move(const char* aFileName, const char* aNewLocation);

		static bool Copy(const char* aFileName, const char* aNewLocation = "");

		static bool Write(const char* aFileName);

		static const char* Read(const char* aFileName);

	};
}

#endif //_FILE_H_