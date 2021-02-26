package main

import "fmt"

func main(){
	v :=[]int{1,5,2,4,8,3,9,6}
	// v2 :=2
	// MERGE_SORT(&v2)
	MERGE_SORT(&v,0,len(v)-1)
	// MERGE(&v,2,2,3)
	fmt.Println(v)
}


func MERGE_SORT(A *[]int,p,r int){
	if p<r{
		q:=(p+r)/2
		MERGE_SORT(A,p,q)
		MERGE_SORT(A,q+1,r)
		MERGE(A,p,q,r)
	}
}

func MERGE(A *[]int,p,q,r int){
	// fmt.Println(p,q,r)
	l1 :=make([]int,q+1-p)
	l2 :=make([]int,r-q)
	copy(l1,(*A)[p:q+1])
	copy(l2,(*A)[q+1:r+1])
	// fmt.Println(l1,l2)
	var x,y=0,0
	var  i =0
	for {
		if (x<len(l1)&&y<len(l2)){
			if l1[x]<=l2[y]{
				(*A)[p+i] =l1[x]
				// fmt.Println(l1[x])
				 x=x+1
			}else{
				(*A)[p+i]=l2[y]
				// fmt.Println(l2[y])
				y=y+1
		}
			i++
		}else {
			break
		}
	}
	// fmt.Println(x,y,i,r)
	if i<r-p+1{
		if x<len(l1){
			for i<r-p+1{
				(*A)[p+i]=l1[x]
				i+=1
				x+=1
			}
		}else{
			for i<r-p+1{
				// fmt.Println(y)
				(*A)[p+i]=l2[y]
				// fmt.Println(l)
				i+=1
				y+=1
			}
		}
	}

}