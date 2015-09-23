call "D:/Program Files (x86)/Microsoft Visual Studio 9.0/VC/bin/vcvars32.bat"
set CFG=release
set OPENSSL_PATH=../../openssl-1.0.1i
set ZLIB_PATH=../../zlib-1.2.8
nmake -f Makefile.vc9

pause