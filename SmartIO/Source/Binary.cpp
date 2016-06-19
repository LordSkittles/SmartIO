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
//	Last Edit Time: 5/25/2016 2:30 PM
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

		//We've succeeded in creating the binary file.
		return true;
	}

	Binary& Binary::operator=(const Binary& aOtherBinary)
	{
		//If the other binary object doesn't have a target, no need to do anything.
		if (aOtherBinary.mTargetBinFile == nullptr)
		{
			return *this;
		}

		//If mTargetBinFile already exists, delete it.
		if (mTargetBinFile != nullptr)
		{
			delete mTargetBinFile;
		}

		//Create a copy of the other binary's target.
		mTargetBinFile = new File(*aOtherBinary.mTargetBinFile);

		return *this;
	}
}