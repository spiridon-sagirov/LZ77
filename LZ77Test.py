import string
import subprocess
import sys
import time
import os,csv

# Run the LZ77.exe to compress the input file
def run(OriginalFile,compressFile,decompressFile):
    start_time_compress=time.time()
    subprocess.run([r"C:\westernDigitalBootcamp\LZ77\Debug\LZ77.exe", "compress", OriginalFile, compressFile, "5"])

    ctc=calaulateTime(start_time_compress)
    ctp=calaulateSizePercent(OriginalFile, compressFile)
    start_time_decompress = time.time()
    time.sleep(1.0)
    subprocess.run([r"C:\westernDigitalBootcamp\LZ77\lz77_fake.cmd", "decompress", compressFile, decompressFile, "5"])
    ctd=calaulateTime(start_time_decompress)
    cf=compareOfileAndDfile(OriginalFile, decompressFile)
    writeToClv(OriginalFile, ctc, ctp, ctd, cf)

# Calculate the time spent in the compression/decompression
def calaulateTime(startTime):
    total_compress_time=time.time()-startTime
    return total_compress_time

# Calculate the size of the compressed file
def calaulateSizePercent(inputFile,outputFile):
    sizeOutputFile = os.stat(outputFile).st_size
    sizeInputFile=os.stat(inputFile).st_size
    return (sizeInputFile-sizeOutputFile)/100

# compare the originalFile and the decompressFile
def compareOfileAndDfile(OriginalFile,decompressFile):
    sizeOriginalFile = os.stat(OriginalFile).st_size
    sizedecompressFile = os.stat(decompressFile).st_size
    return sizeOriginalFile == sizedecompressFile

# write the test output to excel file
def writeToClv(OriginalFile,ctc,ctp,ctd,cf):
    data=[OriginalFile,os.stat(OriginalFile).st_size,ctp,ctc,ctd,cf]
    with open('TestOutput.csv', 'a',newline="") as f:
        writer = csv.writer(f)
        writer.writerow(data)

run("source.txt","sourceCompress.txt","sourceDecompress.txt")