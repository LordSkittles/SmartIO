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
//	Last Editor Name: JESSE
//	Last Edit Time: 5/25/2016 2:02 PM
//
////////////////////////////////////////////////////
#ifndef _FILE_H_
#define _FILE_H_

#include <vector>
#include <string>

namespace SmartIO
{
	//!The file class contains the functions that allow the user to easily
	//!manipulate the files found in physical folder structure of the system. 
	//!
	//!@author James Mills
	//!@version 1.0
	class File
	{
	public:
		//Remove the default constructor.
		File() = delete;

		//!The custom constructor sets the internal file name to the passed char string.
		//!
		//!@param aFileName - The name of the file this class will be associated with.
		File(const char* aFileName);

		//!The copy constructor copies all members over from the other to this.
		//!
		//!@param aOtherFile - The object to copy from.
		File(const File& aOtherFile);

		//!The destructor deletes any memory allocated by this class.
		File::~File();

		//!This will attempt to create the file with the path (if one is specified).
		//!The file will have '- Copy' added to the end of the name if a file with the
		//!same name and extension is found in that folder.
		//!
		//!@param aOverrite - Whether or not to overrite existing files.
		//!@return bool - Whether or not the file was successfully created.
		bool Create(bool aOverrite = false);

		//!This will attempt to delete the file at the path (if one is specified).
		//!All data in the file will be removed from the computer. Will not be moved to
		//!the Recycle Bin.
		//!
		//!@param aFileName - The name of the file we are attempting to delete.
		//!@return bool - Whether or not the file was successfully deleted.
		bool Delete();

		//!This will attempt to find the file at the path (if one is specified).
		//!If the file is found the function will return true signifying the file did
		//!exist.
		//!
		//!@param aFileName - The name of the file we are attempting to find.
		//!@return bool - Whether or not the file was successfully found.
		bool Exists();

		//!This will attempt to encrypt the file. The file when encrypted, will become 
		//!unreadable by any user.
		//!
		//!@return bool - Whether or not the file was successfully encrypted.
		bool Encrypt();

		//!This will attempt to decrypt the file. The file when decrypted, will
		//!become readable by any user.
		//!
		//!@return bool - Whether or not the file was successfully decrypted.
		bool Decrypt();

		//!This will attempt to move the file to the new location specified.
		//!
		//!@param aNewLocation - The new location the file is being moved to.
		//!@return bool - Whether or not the file was successfully moved.
		bool Move(const char* aNewLocation);

		//!This will attempt to write to the file. This will return false if the file 
		//!couldn't be opened for write.
		//!
		//!@param aDataToWrite - The data being written to the file specified.
		//!@param aAppend - Whether or not to append the string to the end of the file.
		//!@return bool - Whether or not the file was successfully written to.
		bool Write(const char* aDataToWrite, bool aAppend = false);

		//!This will attempt to read the next line from the file and return it.
		//!
		//!@return string - The data being read from the file at the next line.
		std::string ReadLine();

		//!This will attempt to read the line specified from the file and return it.
		//!
		//!@return string - The data being read from the file at the specified line.
		std::string ReadLineAt(unsigned int aLineIndex);

		//!This will attempt to read every line from the file and put it into a vector
		//!of strings. 
		//!
		//!@return vector<string> - The data being read from the file specified.
		std::vector<std::string> ReadAll();

		//!This will copy over member data from the other to this.
		//!
		//!@return File - This object.
		File& operator=(const File& aOtherFile)
		{
			//If the other's mFileName is null, make this null.
			if (aOtherFile.mFileName == nullptr)
			{
				mFileName = nullptr;
				return;
			}

			//Allocate a size for mFileName, and copy the string over.
			mFileName = static_cast<char*>(malloc(strlen(aOtherFile.mFileName)));
			strcpy(mFileName, aOtherFile.mFileName);
		}

	protected:
		char* mFileName; //!< The name of the file the instance of this class will be associated with.

	};
}

#endif //_FILE_H_