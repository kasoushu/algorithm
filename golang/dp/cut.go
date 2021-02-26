package main

import "fmt"

func main() {
	const n = 5
	var r = [n]int{0}
	var p = [11]int{0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30}
	r[0] = 0
	for i := 1; i <= 4; i++ {
		q := -1
		for j := 1; j <= i; j++ {
			q = max(q, p[j]+r[i-j])
		}
		r[i] = q
	}
	fmt.Println(r)
	fmt.Println(r[4])

}
func max(a, b int) int {
	if a < b {
		return b
	} else {

		return a
	}
}
