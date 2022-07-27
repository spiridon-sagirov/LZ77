import string
import subprocess
import sys
import time
import  os,csv

#1, Run the LZ77.exe (or LZ77_fake.cmd at the beginning) to compress the input file
def run(inputFile,outputFile,action):
    start_time=time.time();
    subprocess.run(["C:\\westernDigitalBootcamp\\LZ77\\x64\\Debug\\LZ77.exe",action,inputFile,outputFile])
    calaulateTime(start_time,action)
    calaulateSize(inputFile,outputFile,action)
    calaulateSize()

#2. Calculate the time spent in the compression
#5. Calculate the time spent in decompression

def calaulateTime(startTime,action):
    total_compress_time=time.time()-startTime;
    print("the time spent in the ",action,total_compress_time);

# 3. Calculate the size of the compressed file
#6. Compare the decompressed file with the original one

def calaulateSize(inputFile,outputFile,action):
    sizeCompressFile = os.stat(outputFile).st_size
    sizeInputFile=os.stat(inputFile).st_size
    print("the size of the ",action, "file",sizeCompressFile,"bytes")
    print(" The file has ",action," by ",(sizeInputFile-sizeCompressFile)/100," percent")
    return sizeCompressFile

#write the test output to excel file

def writeToClv(OriginalFile,compressFile,decompressFile):
    run(OriginalFile, compressFile, action="compress")
    run(compressFile, decompressFile, action="decompress")
    originalFileSize=calaulateSize(OriginalFile,compressFile,action="compress")
    data=[OriginalFile,(sizeDecompressFile-sizeCompressFile)/100,total_compress_time,total_decompress_time,'tamarr']
    with open('TestOutput.csv', 'a',newline="") as f:
        writer = csv.writer(f)
        writer.writerow(data)


