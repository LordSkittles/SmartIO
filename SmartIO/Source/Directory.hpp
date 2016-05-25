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
	//!manipulate the physical folder structure of the system. Relative to the 
	//!working directory of the project.
	//!
	//!@author James Mills
	//!@version 1.0
	class Directory
	{
	public:
		//TODO: Add Copy and Move

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
		//!@return bool - Whether or not the actual directory was deleted from the location.
		static bool Delete(const char* aDirectoryName);

		//!Attempts to find the passed file or directory in the passed directory path. If
		//!looking for a file, the function will accept '.*' for the extension to specify
		//!all file types.
		//!
		//!@param aDirectoryName - The path to the relative directory.
		//!@param aToFind - The file or directory we are attempting to find.
		//!@return bool - Whether or not the actual directory contains the file/directory.
		static bool Contains(const char* aDirectoryName, const char* aToFind);

		//!Get's all the directories and files found inside the passed directory and return
		//!a list of all the files.
		//!
		//!@param aDirectoryName - The path to the relative directory.
		//!@param aToFind - The file or directory we are attempting to find.
		//!@return vector<string> - The vector of all the file/folder names in this directory.
		static std::vector<std::string> List(const char* aDirectoryName);

		//!Moves the directory specified to the new location. Takes all the files and sub-
		//!directories with it. Will always safely move all files.
		//!
		//!@param aDirectoryName - The path to the relative Directory.
		//!@param aNewLocation - The location that the folder being moved will be moved to.
		//!@return bool - Whether or not the folder was successfully moved to the new location.
		static bool Move(const char* aDirectoryName, const char* aNewLocation);

		//!Copies the directory specified to either a new location or the same location. 
		//!Takes all the files and sub-directories with it. Will always safely copy all files.
		//!
		//!@param aDirectoryName - The path to the relative Directory.
		//!@param aNewLocation - The location that the folder being moved will be moved to.
		//!@return bool - Whether or not the folder was successfully moved to the new location.
		static bool Copy(const char* aDirectoryName, const char* aNewLocation = "");

	};
}

#endif //_DIRECTORY_H_