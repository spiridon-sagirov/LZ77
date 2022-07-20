@echo off

IF "%1" == "" goto usage
IF "%1" == "compress" goto compress
IF "%1" == "decompress" goto decompress
goto usage

:usage
echo "Usage: lz77_fake.cmd [compress/decompress] <DecompressedFilePath> <CompressedFilePath>"
goto end
END

:compress
echo "Compressing"
copy %2 %3
goto end
END

:decompress
echo "Decompressing"
copy %3 %2
goto end
END

:end
