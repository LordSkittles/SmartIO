////////////////////////////////////////////////////
//	
//	© 2015 Turbulant Games, all rights reserved
//
//	File: Binary.cpp
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
#include "Binary.hpp"
#include ""

namespace SmartIO
{
	bool Binary::Exists(const char* aDirectoryName)
	{
		//Create the directory instance and attempt to open it
		DIR* directory;
		directory = opendir(aDirectoryName);

		//Check whether the directory exists or not
		bool exists = directory != NULL;

		//Close the directory for safety if it exists
		if (exists)
		{
			if (closedir(directory))
			{
				//We didn't close so print a message and exit the program
				fprintf(stderr, "Could not close '%s': %s\n", aDirectoryName, strerror(errno));
			}
		}

		//Return whether or not the directory exists
		return exists;
	}
}