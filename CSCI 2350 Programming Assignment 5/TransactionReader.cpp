<<<<<<< HEAD
// Test
=======
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream file;
	file.open("TestTransactionFile.txt");
	string line;
	while (getline(file, line))
	{
		cout << line << endl;
	}
	file.close();
	return 0;
}
>>>>>>> eedf48fcb9a40799510720225d98dc3881a644b3
