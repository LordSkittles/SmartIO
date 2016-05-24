////////////////////////////////////////////////////
//	
//	© 2015 Turbulant Games, all rights reserved
//
//	File: Directory.cpp
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
#include "Directory.hpp"

#include <direct.h>

#include "External-Lib\dirent.h"

using std::string;
using std::vector;

namespace SmartIO
{
	bool Directory::Exists(const char* aDirectoryName)
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

	bool Directory::Create(const char* aDirectoryName, bool aAutoPathGenerate)
	{
		//Make a static version of the original directory name
		static string directory = aDirectoryName;

		//Get the first part of the path
		string directoryName = aDirectoryName;
		directoryName = directoryName.substr(0, directoryName.find_first_of("/"));
		string path = directory;
		path = path.substr(0, path.find(directoryName));

		//Check if we are auto generating the path as we go.
		if (aAutoPathGenerate)
		{
			//Check if the doesn't already exist
			if (!Exists((path + directoryName).c_str()))
			{
				//Create the directory
				_mkdir((path + directoryName).c_str());
			}

			//Get the new directory name and attempt to create it.
			string dir = aDirectoryName;

			//Check if there is a sub directory to create.
			if (dir.find_first_of("/") != string::npos)
			{
				string newDir = dir.substr(dir.find_first_of("/") + 1, string::npos);
				Create(newDir.c_str(), aAutoPathGenerate);
			}
		}
		else
		{
			//Check if the doesn't already exist
			if (!Exists(directoryName.c_str()))
			{
				//Create the directory
				_mkdir((path + directoryName).c_str());
			}
		}

		return true;
	}

	bool Directory::Delete(const char* aDirectoryName)
	{
		//Check if the folder exists and attempt to delete it if it does
		if (Exists(aDirectoryName))
		{
			_rmdir(aDirectoryName);

			//Check if it still exists and return based on that
			return !Exists(aDirectoryName);
		}

		//It didn't exist so return false.
		return false;
	}

	bool Directory::Contains(const char* aDirectoryName, const char* aToFind)
	{
		//Copy the file name and define the extension
		string file = aToFind;
		string extension = "";
		bool compareExtension = true;
		bool found = false;

		//Check if the directory exists
		if (Exists(aDirectoryName))
		{
			//Attempt to open the directory
			DIR* directory;
			directory = opendir(aDirectoryName);

			//Check if this is a file
			if (file.find_last_of(".") != string::npos)
			{
				//Get the extension of the thing we are trying to find.
				extension = file.substr(file.find_last_of("."), string::npos);
			}

			//Loop through all the files/folders in the folder
			while (true)
			{
				//Get the current entry
				struct dirent* entry;
				string entryName;
				entry = readdir(directory);

				//Check if this is the last entry
				if (!entry)
				{
					//It was so break from the loop.
					break;
				}

				//Set the entry name and compare it to the filename we are trying to find
				entryName = entry->d_name;

				//Check if we need to check the extension
				compareExtension = extension != "" && extension != ".*";

				//Get the name of the entry and passed file and the entry extension
				string entryExt = entryName.find_first_of(".") != string::npos ? entryName.substr(entryName.find_first_of("."), string::npos) : "";
				string entryNoExt = entryName.substr(0, entryName.find_first_of("."));
				string fileNoExt = file.substr(0, file.find_first_of("."));

				//Compare the entry and the fileName.
				if (strcmp(entryNoExt.c_str(), fileNoExt.c_str()) == 0)
				{
					//Check if both don't have an extension
					if (!(entry->d_type & DT_DIR))
					{
						//Check if we need to compare the extension.
						if (compareExtension)
						{
							//Check if the extensions are the same
							if (strcmp(entryExt.c_str(), extension.c_str()) == 0)
							{
								//Yay! This is the thing we are looking for so return true.
								found = true;
							}
							
							//They weren't so simply continue the loop.
							continue;
						}
						else
						{
							//Check if it is the variable extension
							if (extension == ".*")
							{
								//This entry has an extension, the same name and we
								//were looking for any file type so we found what
								//we were looking for!
								found = true;
							}
							
							continue;
						}
					}
					else
					{
						//Check if we were looking for an extension
						if (extension == "")
						{
							//We weren't looking for a file and this is not a file and the same name...
							//So this is the directory we are looking for.
							found = true;
						}
						
						continue;
					}
				}
			}

			//Close the directory
			if (closedir(directory))
			{
				//We couldn't close the directory!!!
				fprintf(stderr, "Could not close '%s': %s\n", aDirectoryName, strerror(errno));
			}
		}

		//The directory didn't exists or we didn't find the file. so we return false.
		return found;
	}

	vector<string> Directory::List(const char* aDirectoryName)
	{
		//Create temp vector for directory contents
		vector<string> contents;

		//Check if directory exists
		if (Exists(aDirectoryName))
		{
			//Open the directory.
			DIR* directory;
			directory = opendir(aDirectoryName);

			//Loop through all files in the directory.
			while (true)
			{
				//Get the current entry
				struct dirent* entry;
				const char* entryName;
				entry = readdir(directory);

				//Check if this is the last entry
				if (!entry)
				{
					//It was so break from the loop.
					break;
				}

				//Copy the directory name
				entryName = entry->d_name;

				//Check if this is a directory
				if (entry->d_type & DT_DIR)
				{
					//Check this isn't this directory to the previous dir
					if (strcmp(entryName, "..") != 0 && strcmp(entryName, ".") != 0)
					{
						//Create temp index and loop through all of the folder contents
						int index = 0;
						for (auto iter : contents)
						{
							//See if this index has an extension
							if (iter.find_first_of(".") != string::npos)
							{
								//It did so break from the loop.
								break;
							}

							//It wasn't a file, but a folder, so increment
							index++;
						}

						//Add it to the vector
						contents.insert(contents.begin() + index, entryName);
					}
				}
				else
				{
					//Check this isn't this directory to the previous dir
					if (strcmp(entryName, "..") != 0 && strcmp(entryName, ".") != 0)
					{
						//Add it to the vector.
						contents.push_back(entryName);
					}
				}
			}

			//Close the directory
			if (closedir(directory))
			{
				//We couldn't close the directory!!!
				fprintf(stderr, "Could not close '%s': %s\n", aDirectoryName, strerror(errno));
			}
		}
		else
		{
			//Print error message to let user know it does not exist.
			printf("Folder not found! No entries will be recorded.\n");
		}

		return contents;
	}
}