////////////////////////////////////////////////////
//	
//	© 2015 Turbulant Games, all rights reserved
//
//	File: Binary.hpp
//
//	CREATION
//  Creator: JESSE	
//	Time Created: 5/25/2016 1:17 PM
//
//	EDITS
//	Last Editor Name: JESSE
//	Last Edit Time: 5/25/2016 1:17 PM
//
////////////////////////////////////////////////////
#ifndef _BINARY_H_
#define _BINARY_H_

namespace SmartIO
{
	//!The binary class provides functionality to interchange between
	//!binary files and standard, non-binary files. The user can encode
	//!and decode data using a list of "format plugins"; which define
	//!how the type of file (that the plugin is dedicated to) interchanges
	//!between binary and standard format.
	//!
	//!@author Jesse Farag
	//!@version 1.0
	class Binary
	{
	public:
		//!Checks if the passed relative directory path is a valid
		//!directory. Will not create the directory, only check if it
		//!actually exists.
		//!
		//!@param aDirectoryName - The path to the relative directory.
		//!@return bool - Whether or not the actual directory exists at the location.
		static bool Exists(const char* aDirectoryName);

	};
}

#endif //_BINARY_H_