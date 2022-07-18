
//#include "TriplateFile.h"
//#include "Triplate.h"
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream f1;
	f1.open("f", ios::out);
	if (!f1)
	{
		cout << "File creation failed";
	}
	else
	{
		cout << "New file created \n";
	}
	/*Triplate t1(0, 0, 'a');
	TriplateFile tf;*/
	/*tf.Open("michal");
	tf.Close();
	cout << tf.EndOfFile();*/
}

