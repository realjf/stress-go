package server

import (
	"github.com/realjf/gopool"
	"fmt"
	"github.com/realjf/stress-go/model"
	"github.com/realjf/stress-go/server/golink"
)

// 设置任务函数
func taskFunc(args interface{}) (error, interface{}) {
	//fmt.Println("task ", args, "completed")
	isSucceed, errCode, requestTime, contentLength := golink.Send(args.(*model.Request))
	result := []interface{}{}
	result = append(result, isSucceed, errCode, requestTime, contentLength)
	_ = 1 + 1
	return nil, result
}

// 设置任务结果回调函数
func callbackFunc(result interface{}) (error, interface{}) {
	// 处理
	//fmt.Println("callback completed [", result, "]")
	res := result.([]interface{})

	return nil, res[3]
}

// 运行压测
func Run(concurrency, totalNumber uint64, request *model.Request) {
	requestPool := gopool.NewPool(int(concurrency))
	requestPool.SetTaskNum(int(totalNumber)) // 设置任务总数
	
	// 添加任务
	go func(){
		for i := 0; i < int(totalNumber); i++ {
			requestPool.AddTask(gopool.NewTask(taskFunc, callbackFunc, request))
		}
	}()
	
	// 开始运行
	requestPool.Run()
	
	fmt.Println("result:")
	// 获取运行结果
	fmt.Println(requestPool.GetResult())
	
	// 获取总运行时间
	fmt.Println(requestPool.GetRunTime())
}

