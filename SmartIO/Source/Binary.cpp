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
//	Last Edit Time: 5/25/2016 1:55 PM
//
////////////////////////////////////////////////////
#include "Binary.hpp"
#include "File.hpp"

namespace SmartIO
{
	Binary::Binary(const Binary& aOtherBinary)
	{
		*this = aOtherBinary;
	}

	Binary::~Binary()
	{
		//Release any memory we allocated.
		if (mTargetBinFile != nullptr)
		{
			delete mTargetBinFile;
		}
	}

	bool Binary::SetBinaryTarget(const char* aFileLocation, bool aAutoGenerate)
	{
		File binaryFile(aFileLocation);

		//If there is no file there...
		if (!binaryFile.Exists())
		{
			//...But we should create one...
			if (aAutoGenerate)
			{
				//Then, attempt to create the file and directory. If this fails, then fail SetBinaryTarget.
				if (!binaryFile.Create())
				{
					return false;
				}
			}

			//If we shouldn't create one, fail SetBinaryTarget.
			else
			{
				return false;
			}
		}

		//At this point, the directory and file exist without a doubt. Now we can start using it.

		//Delete and reassign mTargetBinFile;
		delete mTargetBinFile;
		mTargetBinFile = new File(binaryFile);
	}
}