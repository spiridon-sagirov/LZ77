

using namespace std;
class SlidingWindow
{
public:
	int* buffer;
	fstream searchBuffer;
	int* 
	int size;

	void OpenRead(string filePath,int searchBufferSize, int lookAheadBufferSize);
	//GetBuffers(*searchBuffer, *lookAheadBuffer);
	//Read(bytesCount);
	bool EndOfFile();
	//Write(buffer)
	//Close()
};