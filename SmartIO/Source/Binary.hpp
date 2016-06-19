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
//	Last Edit Time: 6/19/2016 7:24 PM
//
////////////////////////////////////////////////////
#ifndef _BINARY_H_
#define _BINARY_H_

#include <vector>

namespace SmartIO
{
	class File;
	class BinaryPlugin;

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

		//!The default constructor sets the internal file to null.
		Binary() = delete;

		//!The custom constructor is a short-hand to setting the target binary file when this object is created.
		//!
		//!@param aTarget - The name of the file this class will target as the binary file.
		Binary(const char* aTarget) { SetBinaryTarget(aTarget); }

		//!This will copy over member data from the other to this.
		//!
		//!@return Binary - This object.
		Binary(const Binary& aOtherBinary);

		//!The destructor which deletes the target file and any other members we have.
		~Binary();

		//!Sets the target filepath that will be used for all other operations. The target is where 
		//!files are encoded into, or decoded from.
		//!
		//!@param aFileLocation - The file and its directory. Eg, "/my_directory/my_resource.bin"
		//!@param aAutoGenerate - Whether to generate the file using the specified location and name, should it not exist.
		//!@return bool - Whether the target file could be set.
		bool SetBinaryTarget(const char* aFileLocation, bool aAutoGenerate = true);

		//!This will copy over member data from the other to this.
		//!
		//!@return Binary - This object.
		Binary& operator=(const Binary& aOtherBinary);

	private:

		File * mTargetBinFile;//!<The target binary file all operations are done on.

		std::vector<BinaryPlugin *> mBinaryPlugins;//!<The list of plugins avaliable to this Binary class
	};
}

#endif //_BINARY_H_