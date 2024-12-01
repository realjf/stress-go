VERSION="0.1.1"
BIN="bin/stress-go"
ARCH="amd64"
OS=linux
PWD=$(shell pwd)


# install dependencies
NCURSES_V ?= 6.5
# ncurses download url： http://ftp.gnu.org/gnu/ncurses/
.PHONY: deps
deps:
	rm -rf deps lib build
	mkdir -p deps/ncurses-${NCURSES_V} lib build
	cd build && wget -c http://ftp.gnu.org/gnu/ncurses/ncurses-${NCURSES_V}.tar.gz
	tar -zxvf build/ncurses-${NCURSES_V}.tar.gz -C build/
	cd build/ncurses-${NCURSES_V} && ./configure --with-shared --prefix=${PWD}/deps/ncurses-${NCURSES_V} && make && make install
	cp -r ${PWD}/deps/ncurses-${NCURSES_V}/lib/* lib/

# mv lib/* ../../lib/

CFLAGS="-Wno-unused-variable -Wno-unused-function -Wno-format-security -I. -I./cgo -I./deps/ncurses-${NCURSES_V}/include -std=gnu11 -Wall"
CXXFLAGS="-Wno-unused-variable -Wno-unused-function -Wno-format-security -I. -I./cgo -I./deps/ncurses-${NCURSES_V}/include"
LDFLAGS="-L./lib -lncursesw"

.PHONY: build
build:
	@echo 'building...'
	@env CGO_ENABLED=1 GOOS=${OS} GOARCH=${ARCH} CGO_CFLAGS=${CFLAGS} CGO_CXXFLAGS=${CXXFLAGS} CGO_LDFLAGS=${LDFLAGS} go build -ldflags '-s -w -X main.Version=${VERSION}' -gcflags="all=-trimpath=${PWD}" -asmflags="all=-trimpath=${PWD}" -o ${BIN}-linux-${ARCH}_${VERSION} main.go


# generate cgo middle code
.PHONY: cgo
cgo:
	@env CGO_ENABLED=1 GOOS=${OS} GOARCH=${ARCH} CGO_CFLAGS=${CFLAGS} CGO_CXXFLAGS=${CXXFLAGS} CGO_LDFLAGS=${LDFLAGS} go build -work -x ./...



.PHONY: clean
clean:
	@go clean -cache


# install xdotool
.PHONY: tool
tool:
	@sudo apt-get install xdotool -y

# refresh
.PHONY: reload
reload:
	@echo "reload code..."
	@xdotool key ctrl+shift+P ctrl+R Return


.PHONY: all
all:
	make deps
	make cgo
	make build



.PHONY: push
push:
	@-git add -A
	@-git commit -m "update"
	@-git push origin master
