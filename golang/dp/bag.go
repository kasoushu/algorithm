package main

import (
	"fmt"
	"sort"
)
//给定w表示weight，v表示value ，求当背包能带r 重量时，最佳分配方案
//first 分数背包，第二种0-1 背包
var w =[]int{2,5,4,9}
var v =[]int{6,10,12,18}
func main(){
	dpBag(w,v,5)
	fmt.Println(greedyBag(w,v,11))
}

type item struct {
	i int
	p int
}

type items []item
func (is items)Less(i,j int) bool{
	if is[i].p>is[j].p {
		return true
	}else {
		return false
	}
}
func (i items)Len()int{
	return len(i)
}
func (this items)Swap(i,j int){
	this[i],this[j]=this[j],this[i]
}
//o-1 Beibao
func dpBag(w []int,v []int,r int){
	n:=len(w)+1
	c:=make([][]int,n)
	for i :=0;i<n;i++{
		c[i]=make([]int,r+1)
	}

	for i:=1;i<=r;i++{
		for j:=1;j<n;j++{
			if w[j-1] > i {
				c[j][i]=c[j-1][i]
			}else {
				c[j][i]=max(c[j-1][i],c[j-1][i-w[j-1]]+v[j-1])
			}
		}
	}
	fmt.Println(c)
}
/////贪婪法求分数背包问题
func greedyBag(w []int,v []int,r int)float64{
	n:=len(w)
	//a为平均大小
	a:=make([]int,n)
	its :=make(items,n)
	for i :=0;i<n;i++ {
		a[i]=(v[i])/w[i]
		its[i].p=a[i]
		its[i].i=i
		//a[i]+=v[0]/w[0]
	}
	sort.Sort(its)

	fmt.Println(its)
	amount :=r
	value:=0.0
	for x:=0;x<n;x++ {
		i:=its[x].i
		if amount>0 {
			if w[i]>amount {
				value=value+float64(amount/w[i])*float64(amount)
				amount=0
			}else {
				value+=float64(v[i])
				amount-=w[i]
			}
		}else {
			break
		}
	}

	return value
}

func max(a,b int)int{
	if a<b{
		return b
	}else{
		return a
	}
}
