VERSION="v0.0.1"
BIN="bin/stress-go"
ARCH="amd64"

build:
	@echo 'building...'
	@env CGO_ENABLED=1 GOOS=linux GOARCH=${ARCH} CGO_CFLAGS="-Wno-unused-variable -Wno-unused-function -Wno-format-security" CGO_CXXFLAGS="-Wno-unused-variable -Wno-unused-function -Wno-format-security" go build -ldflags '-s -w -X main.Version=${VERSION}' -gcflags="all=-trimpath=${PWD}" -asmflags="all=-trimpath=${PWD}" -o ${BIN}-linux-${ARCH}_${VERSION} main.go
