#include "..\Catch.hpp"

#include <File.hpp>

using SmartIO::File;

TEST_CASE("File - Testing the Exists functionality.")
{
	File file("TestDirectory/SomeFile.txt");

	REQUIRE(file.Exists());
}

TEST_CASE("File - Testing the Create functionality.")
{
	File file("TestDirectory/SubDirectory/NewFile.txt");

	REQUIRE(file.Create(true));
}

TEST_CASE("File - Testing the Writing functionality.")
{
	File file("TestDirectory/SomeFile.txt");

	REQUIRE(file.Write("Something"));
}

TEST_CASE("File - Testing the Encryption functionality.")
{
	File file("TestDirectory/SomeFile.txt");

	REQUIRE(file.Encrypt());
}

TEST_CASE("File - Testing the Reading functionality.")
{
	File file("TestDirectory/SomeFile.txt");

	REQUIRE(file.ReadLine() != "");
}

TEST_CASE("File - Testing the Decryption functionality.")
{
	File file("TestDirectory/SomeFile.txt");

	REQUIRE(file.Decrypt());
}

TEST_CASE("File - Testing the Delete functionality.")
{
	File file("TestDirectory/SubDirectory/NewFile.txt");

	REQUIRE(file.Delete());
}