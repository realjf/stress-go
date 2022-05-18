BIN="bin/stress-go"


build:
	echo 'building...'
	@env CGO_ENABLED=1 GOOS=linux GOARCH=amd64 go build -ldflags '-s -w' -gcflags="all=-trimpath=${PWD}" -asmflags="all=-trimpath=${PWD}" -o ${BIN} main.go
