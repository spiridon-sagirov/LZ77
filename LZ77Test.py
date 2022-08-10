import string
import subprocess
import sys
import time
import os,csv

# Run the LZ77.exe to compress the input file
def run(originalFile,compressFile,decompressFile):
    start_time_compress=time.time()
    os.chdir(r"C:\westernDigitalBootcamp\LZ77")
    subprocess.run([r"C:\westernDigitalBootcamp\LZ77\Debug\LZ77.exe", "compress", originalFile, compressFile, "10"])
    ctc=calaulateTime(start_time_compress)
    ctp=calaulateSizePercent(originalFile, compressFile)
    start_time_decompress = time.time()
    subprocess.run([r"C:\westernDigitalBootcamp\LZ77\Debug\LZ77.exe", "decompress", compressFile, decompressFile, "10"])
    ctd=calaulateTime(start_time_decompress)
    cf = compareOfileAndDfile(originalFile, decompressFile)
    writeToClv(originalFile, ctc, ctp, ctd, cf)
    originalFileContent=readFile(originalFile)
    decompressFileFileContent=readFile(decompressFile)
    if(originalFileContent!=decompressFileFileContent):
        print(originalFileContent)
        print(decompressFileFileContent)
        print("fail compress/decompress " + originalFile)


def readFile(originalFile):
    f = open(originalFile, "r")
    return f.read()



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
    data=[OriginalFile,os.stat(OriginalFile).st_size,ctp,ctc,ctd,cf,"comment!"]
    with open('TestOutput.csv', 'a',newline="") as f:
        writer = csv.writer(f)
        writer.writerow(data)


run("input.txt","Compress.txt","deCompress.txt")
run("input2.txt","Compress2.txt","deCompress2.txt")


#run("empty.txt","enptyCompress.txt","emptydeCompress.txt")
#run("image.jpg","Compress.jpg","deCompress.jpg")