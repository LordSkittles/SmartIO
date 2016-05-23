#include <iostream>
#include <BinaryFormatter.hpp>

using SmartIO::BinaryFormatter;
using namespace std;

int main(int* argc, const char* argv)
{
	BinaryFormatter* serializer = new BinaryFormatter("somefile.dat");

	int* someint1 = new int(1);
	int* someint2 = new int(2);
	serializer->Write<int*>(2, someint1, someint2);

	delete someint1;
	delete someint2;

	serializer->Read<int*>(2, someint1, someint2);

	cout << "First: " << someint1 << ", Second: " << someint2 << endl;

	system("pause");

	return 0;
}