VERSION="0.1.0"
BIN="bin/stress-go"
ARCH="amd64"



# 安装依赖
NCURSES_V ?= 6.5
# 下载地址： http://ftp.gnu.org/gnu/ncurses/
.PHONY: deps
deps:
	rm -rf deps lib
	mkdir -p deps lib
	cd deps && wget -c http://ftp.gnu.org/gnu/ncurses/ncurses-${NCURSES_V}.tar.gz
	tar -zxvf deps/ncurses-${NCURSES_V}.tar.gz -C deps/
	cd deps/ncurses-${NCURSES_V} && ./configure --with-shared && make && mv lib/* ../../lib/




CFLAGS="-Wno-unused-variable -Wno-unused-function -Wno-format-security -Iinclude -Ideps/ncurses-${NCURSES_V}/include -fPIC"
CXXFLAGS="-Wno-unused-variable -Wno-unused-function -Wno-format-security -Iinclude -Ideps/ncurses-${NCURSES_V}/include -fPIC"
LDFLAGS="-Llib -lncursesw"

.PHONY: build
build:
	@echo 'building...'
	@env CGO_ENABLED=1 GOOS=linux GOARCH=${ARCH} CGO_CFLAGS=${CFLAGS} CGO_CXXFLAGS=${CXXFLAGS} CGO_LDFLAGS=${LDFLAGS} go build -ldflags '-s -w -X main.Version=${VERSION}' -gcflags="all=-trimpath=${PWD}" -asmflags="all=-trimpath=${PWD}" -o ${BIN}-linux-${ARCH}_${VERSION} main.go





.PHONY: push
push:
	@-git add -A
	@-git commit -m "update"
	@-git push origin master
