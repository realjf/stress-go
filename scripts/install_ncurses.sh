#!/bin/sh

# 下载地址： http://ftp.gnu.org/gnu/ncurses/
wget http://ftp.gnu.org/gnu/ncurses/ncurses-6.0.tar.gz
tar zxvf ncurses-6.0.tar.gz
cd ncurses-6.0
./configure --with-shared
make && make install
