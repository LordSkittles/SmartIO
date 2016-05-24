////////////////////////////////////////////////////
//	
//	© 2015 Turbulant Games, all rights reserved
//
//	File: Directory.hpp
//
//	CREATION
//  Creator: JAMES	
//	Time Created: 5/24/2016 9:57 AM
//
//	EDITS
//	Last Editor Name: JAMES
//	Last Edit Time: 5/24/2016 9:57 AM
//
////////////////////////////////////////////////////
#ifndef _DIRECTORY_H_
#define _DIRECTORY_H_

#include <vector>
#include <string>

namespace SmartIO
{
	//!The directory class contains the functions that allow the user to easily
	//manipulate the physical folder structure of the system. Relative to the 
	//working directory of the project.
	//
	//@author James Mills
	//@version 1.0
	class Directory
	{
	public:
		//!Checks if the passed relative directory path is a valid
		//!directory. Will not create the directory, only check if it
		//!actually exists.
		//!
		//!@param aDirectoryName - The path to the relative directory.
		//!@return bool - Whether or not the actual directory exists at the location.
		static bool Exists(const char* aDirectoryName);

		//!Attempts to create the directory at the path specified. If the second param
		//!is set (it defaults to true), the function will generate the path as it goes.
		//!
		//!@param aDirectoryName - The path to the relative directory.
		//!@param aAutoPathGenerate - Whether or not we are going to generate the path to
		//!the directory, if it doesn't exist, as we go.
		//!@return bool - Whether or not the actual directory was created at the location.
		static bool Create(const char* aDirectoryName, bool aAutoPathGenerate = true);

		//!Attempts to delete the directory at the path specified. WARNING: WILL DELETE
		//!SUBDIRECTORIES AND FILES!
		//!
		//!@param aDirectoryName - The path to the relative directory.
		//!@return bool - Whether or not the actual directory was created at the location.
		static bool Delete(const char* aDirectoryName);

		//!Attempts to find the passed file or directory in the passed directory path. If
		//!looking for a file, the function will accept '.*' for the extension to specify
		//!all file types.
		//!
		//!@param aDirectoryName - The path to the relative directory.
		//!@param aToFind - The file or directory we are attempting to find.
		//!@return bool - Whether or not the actual directory was created at the location.
		static bool Contains(const char* aDirectoryName, const char* aToFind);

		//!Get's all the directories and files found inside the passed directory and return
		//!a list of all the files.
		//!
		//!@param aDirectoryName - The path to the relative directory.
		//!@param aToFind - The file or directory we are attempting to find.
		//!@return bool - Whether or not the actual directory was created at the location.
		static std::vector<std::string> List(const char* aDirectoryName);

	};
}

#endif //_DIRECTORY_H_