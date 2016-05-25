#include "..\Catch.hpp"

#include <Directory.hpp>

using SmartIO::Directory;

TEST_CASE("Directory - Testing the Exists functionality.")
{
	REQUIRE(Directory::Exists("TestDirectory/SubDirectory"));
}

TEST_CASE("Directory - Testing the Create functionality.")
{
	REQUIRE(Directory::Create("TestDirectory/SubDirectory/NewDir"));
}

TEST_CASE("Directory - Testing the Contains functionality.")
{
	REQUIRE(Directory::Contains("TestDirectory/SubDirectory", "NewDir"));
	REQUIRE(Directory::Contains("TestDirectory/SubDirectory", "SomeFile.txt"));
	REQUIRE(Directory::Contains("TestDirectory/SubDirectory", "SomeFile.*"));
}

TEST_CASE("Directory - Testing the List functionality.")
{
	REQUIRE(Directory::List("TestDirectory/SubDirectory").size() > 0);
}

TEST_CASE("Directory - Testing the Delete functionality.")
{
	REQUIRE(Directory::Delete("TestDirectory/SubDirectory/NewDir"));
}