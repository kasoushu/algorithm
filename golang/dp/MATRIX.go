package main

import "fmt"

func main() {
	//
	var p =[7]int{5,10,3,12,5,50,6}
	var m = [7][7]int{}
	var s = [7][7]int{}
	for i :=0;i<len(m);i++ {
		m[i][i]=0
	}
	var n =len(p)-1
	for l :=2;l<=n;l++ {
		for i :=1;i<=n-l+1;i++ {
			j:=i+l-1
			m[i][j]=2<<31
			for k :=i;k<=j-1;k++ {
				q:=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j]
				//fmt.Println(q)
				if q<m[i][j] {
					m[i][j]=q
					s[i][j]=k
				}
			}
		}
	}
	fmt.Println(s)
	//fmt.Println(m)
	//fmt.Println(m[1][6])
}