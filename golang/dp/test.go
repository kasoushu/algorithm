package main

import "fmt"
func main(){
	x :=[]int{1,3,5,6}
	y :=make([]int,2)
	copy(y,x[0:2])
	x[1]=8
	fmt.Println(y)

}