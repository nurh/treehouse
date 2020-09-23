# treehouse

A beginner's operating system.

Currently it just boots, and prints a message on screen.

To build, you'll need a baremetal C compiler. 

Instructions on how to get one are on the OSDev wiki, but
here's a quick and dirty version using GCC:

Shell variables:
----------------
export PREFIX="$HOME/opt/cross"
export TARGET=i686-elf
export PATH="$PREFIX/bin:$PATH"

Binutils:
---------
cd $HOME/src
mkdir build-binutils
cd build-binutils
../binutils-x.y.z/configure --target=$TARGET --prefix="$PREFIX" --with-sysroot --disable-nls --disable-werror
make
make install

GCC:
----
cd $HOME/src
mv gmp-x.y.z gcc-x.y.z/gmp
mv mpfr-x.y.z gcc-x.y.z/mpfr
mv mpc-x.y.z gcc-x.y.z/mpc

mkdir build-gcc
cd build-gcc
../gcc-x.y.z/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --enable-languages=c,c++ --without-headers
make all-gcc
make all-target-libgcc
make install-gcc
make install-target-libgcc

----

Replace the x.y.z placeholders with the actual version of the tools you're using. 

Currently tested with gcc 8.1.0.
