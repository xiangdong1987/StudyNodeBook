package main

import (
	"time"
	"math/rand"
	"fmt"
)

var goods chan int
var r  = rand.New(rand.NewSource(time.Now().UnixNano())) //定义一个随机数种子
var done chan struct{}

func produce()  {
	for i:=1; i<=10; i++ {
		goods <- i
		time.Sleep(time.Duration(r.Int31n(3))*time.Second)
	}
	done <- struct{}{}
}

func consume() {
	for i:=0; i<5; i++ {
		good := <- goods
		fmt.Printf("The goods size is : %v\n", 10-good+1)
		time.Sleep(time.Duration(r.Int31n(5))*time.Second)
	}
}

func main()  {
	goods = make(chan int)
	done = make(chan struct{})
	go produce()
	go consume()
	go consume()
	<- done
}
