import string
import subprocess
import sys
import time
import  os,csv

#1, Run the LZ77.exe (or LZ77_fake.cmd at the beginning) to compress the input file
inputFile="sourceFile.txt"
outputFile="destination.txt"
start_time=time.time();
subprocess.run(["C:\\westernDigitalBootcamp\\LZ77\\lz77_fake.cmd", "compress",inputFile,outputFile])

#2. Calculate the time spent in the compression
total_compress_time=time.time()-start_time;
print("the time spent in the compression",total_compress_time);

# 3. Calculate the size of the compressed file
sizeCompressFile = os.stat(outputFile).st_size
sizeInputFile=os.stat(inputFile).st_size
print("the size of the compressed file",sizeCompressFile,"bytes")
print(" The file has compressed by ",(sizeInputFile-sizeCompressFile)/100," percent")

#4. Run the LZ77.exe (or LZ77_fake.cmd at the beginning) to decompress the output file
subprocess.run(["C:\\westernDigitalBootcamp\\LZ77\\lz77_fake.cmd", "decompress",inputFile,outputFile])

#5. Calculate the time spent in decompression
total_decompress_time=time.time()-start_time;
print("the time spent in the decompression",total_decompress_time);

#6. Compare the decompressed file with the original one
sizeDecompressFile = os.stat(outputFile).st_size
sizeInputFile=os.stat(inputFile).st_size
print("the size of the decompressed file",sizeDecompressFile,"bytes")
print(" The file has compressed by ",(sizeInputFile-sizeDecompressFile)/100," percent")

#write the test output to excel file
data=[inputFile,sizeInputFile,(sizeDecompressFile-sizeCompressFile)/100,total_compress_time,total_decompress_time,'aaffff5']
with open('TestOutput.csv', 'a',newline="") as f:
    writer = csv.writer(f)
    writer.writerow(data)
















