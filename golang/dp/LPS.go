package main

import "fmt"
func main() {
	fmt.Println(LCS("abnmbbaca"))
	fmt.Println(LPSubstring("gcabacbc"))
}

func max(i1, i2 int) int {
	if i1 > i2 {
		return i1
	} else {
		return i2
	}
}

// 最长公共回文子序列
func LCS(s string) int { 
	n := len(s)
	c := make([][]int, n)
	for i := 0; i < n; i++ {
		c[i] = make([]int, n)
	}
	for i := 0; i < n; i++ {
		c[i][i] = 1
	}
	for i := n-1; i >=0; i-- {

		for j :=i+1; j < n; j++ {
			if s[i] == s[j] {
				c[i][j] = c[i+1][j-1] + 2
			} else { 
				c[i][j] = max(c[i][j-1], c[i+1][j])
			}
		}
	}
	return c[0][n-1]

}

//最长回文子串


func LPSubstring(s string) string {
	var ans string
	n:=len(s)
	c :=make([][]int, n)
	for i:=0;i<n;i++{
		c[i]=make([]int,n)
		c[i][i]=1
	}
	for i:=n-2;i>=0;i--{
		
		if s[i+1]==s[i]{
			c[i][i+1]=1
		} 
		for j:=i+2;j<n;j++{
			if s[i]==s[j]{
				c[i][j]=c[i+1][j-1]
			}
			if c[i][j]==1{
				ans=s[i:j+1]
			}
		}
	}
	return ans
}