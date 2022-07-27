import string
import subprocess
import sys
import time
import  os,csv

#1, Run the LZ77.exe (or LZ77_fake.cmd at the beginning) to compress the input file
def run(OriginalFile,compressFile,decompressFile):
    start_time_compress=time.time()
    subprocess.run([r"C:\westernDigitalBootcamp\LZ77\Debug\LZ77.exe", "compress", OriginalFile, compressFile, "5"])
    calaulateTime(start_time_compress)
    calaulateSizePercent(inputFile, outputFile, action)

    #start_time_decompress = time.time();
   # subprocess.run([r"C:\westernDigitalBootcamp\LZ77\Debug\LZ77.exe", "decompress", compressFile, decompressFile, "5"])

    calaulateSize()

# Calculate the time spent in the compression/decompression
def calaulateTime(startTime):
    total_compress_time=time.time()-startTime
    return total_compress_time

# 3. Calculate the size of the compressed file
#6. Compare the decompressed file with the original one
def calaulateSizePercent(inputFile,outputFile,action):
    sizeOutputFile = os.stat(outputFile).st_size
    sizeInputFile=os.stat(inputFile).st_size
    return (sizeInputFile-sizeCompressFile)/100

#write the test output to excel file

def writeToClv(OriginalFile,compressFile,decompressFile):
    run(OriginalFile, compressFile, action="compress")
    run(compressFile, decompressFile, action="decompress")
    originalFileSize=calaulateSize(OriginalFile,compressFile,action="compress")
    data=[OriginalFile,(sizeDecompressFile-sizeCompressFile)/100,total_compress_time,total_decompress_time,'tamarr']
    with open('TestOutput.csv', 'a',newline="") as f:
        writer = csv.writer(f)
        writer.writerow(data)


