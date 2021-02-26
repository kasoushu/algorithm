package main

import "fmt"



const n,m =8,6
var p1=[]int{0,3,5,6,8,9,10,14}
var p2=[]int{0,3,4,6,7,8}
var c =[n][m]int{{0}}



func main() {
	//fmt.Println(getMax(p1,p2,5,5)) fmt.Println(LCS)
	for i :=0;i<n;i++{
		c[i][0]=0
	}
	for j :=0 ; j<m;j++ {
		c[0][j]=0
	}
	l,LCS:=UseDpToResolveLcs(c,p1,p2)
	fmt.Println(l)
	fmt.Println(LCS)
	
}

//动态规划求解

func UseDpToResolveLcs(c [n][m]int,p1,p2 []int)(int,[]int){
	LCS :=make([]int,0)
	for i:=1;i<n;i++ {
		for j :=1;j<m;j++ {
			if p1[i]==p2[j] {
				LCS=append(LCS, p1[i])
				c[i][j]=c[i-1][j-1]+1
			}else if c[i-1][j]>c[i][j-1] {
				c[i][j]=c[i-1][j]
			}else {
				c[i][j]=c[i][j-1]
			}
		}
	}
	return  c[n-1][m-1],LCS
}


//递归解
func getMax(p1,p2 []int , i,j int ) int{

	if i<0||j<0 {
		return 0
	}
	if p1[i]==p2[j]{
		return getMax(p1,p2,i-1,j-1)+1
	}else{
		return Max(getMax(p1,p2,i-1,j),getMax(p1,p2,i,j-1))
	}
}

func Max(i,j int) int  {
	if i<j {
		return j
	}else {
		return i
	}
}