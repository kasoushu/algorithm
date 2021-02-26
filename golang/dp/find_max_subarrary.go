package main

//FIND_MAX_CROSSING_SUBARRARY
//AUTHOR:CAICAI
import "fmt"

func main() {
	v := []int{13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,- 22, 15,-4,7}
	l,h,s:=FIND_MAX_SUBARRARY(v,0,len(v)-1)
	fmt.Println(l,h,s)
}
func FIND_MAX_SUBARRARY(v []int,left,right int)(int,int,int){	
	if left==right {
		return v[left],left,right
	}
	mid:=(left+right)/2
	left_low,left_high,left_sum:=FIND_MAX_SUBARRARY(v,left,mid)
	right_low,right_high,right_sum:=FIND_MAX_SUBARRARY(v,mid+1,right)		
	cross_low,cross_high,cross_sum:=FIND_MAX_CROSSING_SUBARRARY(v,left,right,mid)		
	if left_sum>right_sum&&left_sum>cross_sum{
		return left_low,left_high,left_sum
	}else if (right_sum>left_sum&&right_sum>cross_sum){
		return right_low,right_high,right_sum
	}else{
		return cross_low,cross_high,cross_sum
	}

}

// find corossing subarrary
func FIND_MAX_CROSSING_SUBARRARY(v []int ,left,right,mid int)(int ,int,int){
	sum:=0	
	leftsum:=-10000
	rightsum:=-10000
	max_left:=mid
	max_right:=mid
	for i :=mid; i>=left; i-- {
		sum+=v[i]
		if sum>leftsum{
			leftsum=sum
			max_left=i
		}
		// fmt.Println(left,right,mid,sum)
	}
	sum=0
	for i :=mid+1; i<=right; i++ {
		sum+=v[i]
		if sum>rightsum{
			rightsum=sum
			max_right=i
		}
		// fmt.Println(left,right,mid,sum)
	}
	return max_left,max_right,leftsum+rightsum
}
