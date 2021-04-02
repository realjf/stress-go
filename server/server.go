package server

import (
	"github.com/realjf/gopool"
)

// 运行压测
func Run() {
	requestPool := pool.NewPool(10000)
	pool.SetTaskNum(10000) // 设置任务总数
	
	// 设置任务函数
	func taskFunc(args interface{}) (error, interface{}) {
		//fmt.Println("task ", args, "completed")
		_ = 1 + 1
		return nil, args
	}
	
	// 设置任务结果回调函数
	func callbackFunc(result interface{}) (error, interface{}) {
		// 处理
		//fmt.Println("callback completed [", result, "]")
		return nil, result
	}
	
	// 添加任务
	for i := 0; i < 1000000; i++ {
		pool.AddTask(NewTask(taskFunc, callbackFunc, i))
	}
	
	// 开始运行
	pool.Run()
	
	// 获取运行结果
	pool.GetResult()
	
	// 获取总运行时间
	pool.GetRunTime()
}

