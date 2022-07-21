#include "TriplateFile.h"
#include "Triplate.h"

int main()
{
	fstream f1;
	f1.open("pppppppppp", std::ios_base::app );
	if (!f1)
	{
		cout << "File creation failed";
	}
//	f1 << "hello";
	char  num ; 
	f1 >> num;
	cout << "The next number is " << num ;
	f1.close();
	/*Triplate t1(21, 12, 'g');
	TriplateFile tf;
	tf.Open("qwertyuiop");
	tf.Write(t1);
	tf.Close();
	cout << tf.EndOfFile();*/
}

