package server

import (
	"sync"

	"github.com/realjf/stress-go/model"
	"github.com/realjf/stress-go/server/golink"
)

// 运行压测
func Run(concurrency, totalNumber uint64, request *model.Request, ch chan<- *model.RequestResults, endChan chan bool) {

	wg := sync.WaitGroup{}

	var i uint64
	for i = 0; i < concurrency; i++ {
		wg.Add(1)
		go func() {
			golink.Send(request, totalNumber, wg, ch)
		}()
	}
	wg.Wait()
	endChan <- true
}
