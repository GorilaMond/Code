#!/bin/bash
set -xe
sudo apt-get update
sudo apt-get install -y \
  libdw-dev \
  bison \
  cmake \
  flex \
  g++ \
  git \
  libelf-dev \
  zlib1g-dev \
  libfl-dev \
  systemtap-sdt-dev \
  binutils-dev \
  libcereal-dev \
  llvm-dev \
  llvm-runtime \
  libclang-dev \
  clang \
  libpcap-dev \
  libgtest-dev \
  libgmock-dev \
  asciidoctor \
  pahole
git clone https://github.com/iovisor/bpftrace --recurse-submodules
mkdir bpftrace/build; cd bpftrace/build;
../build-libs.sh
cmake -DCMAKE_BUILD_TYPE=Release ..
make -j8
sudo make install