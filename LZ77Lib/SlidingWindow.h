

using namespace std;
class SlidingWindow
{
public:
	char* buffer;
	fstream pointer;
	char* searchBuffer, * lookAheadBuffer;
	int searchBufferSize, lookAheadBufferSize,size;

	void OpenRead(string filePath);
	void Read(int bytesCount);
	bool EndOfFile();
	//Write(buffer)
	void Close();

};