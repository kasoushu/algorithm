package main

import "fmt"

//
//
//二叉树遍历
//生成二差搜索树

type BTree struct {
	value int
	leftTree *BTree
	rightTree *BTree
}



func createTree(value []int,left,right int) *BTree{
	if left>right {
		return nil
	}
	mid:=(left+right)/2
	head:=new(BTree)
	head.value=value[mid]
	head.rightTree=nil
	head.leftTree=nil
	if left == right {
		return head
	}else {
		head.leftTree=createTree(value,left,mid-1)
		head.rightTree=createTree(value,mid+1,right)
	}
	return head
}
//递归的先序遍历
func preTravel(tree *BTree)  {
	if tree!=nil {
		fmt.Print(tree.value)
		preTravel(tree.leftTree)
		preTravel(tree.rightTree)
	}
	return
}
func postTravel(tree *BTree)  {
	if tree!=nil {
		postTravel(tree.leftTree)
		postTravel(tree.rightTree)
		fmt.Print(tree.value)
	}
	return
}
func midTravel(tree *BTree)  {
	if tree!=nil {
		midTravel(tree.leftTree)
		fmt.Print(tree.value)
		midTravel(tree.rightTree)
	}
	return
}
func  levelTravel(tree *BTree)  {
	if tree.leftTree==nil&&tree.rightTree==nil {
		fmt.Print(tree.value)
		return
	}
	queue:=make([]*BTree,0)
	queue = append(queue, tree)
	n:=len(queue)
	for n>0 {
		p:=queue[0]
		//fmt.Println(queue)
		fmt.Printf(" %d ",p.value)
		if p.leftTree!=nil {
			queue=append(queue,p.leftTree)
		}
		if p.rightTree!=nil {
			queue=append(queue,p.rightTree)
		}
		queue=queue[1:]
		n= len(queue)
	}
	if tree!=nil {
	}
	return
}
//不使用递归的先中后遍历
func dfs_pre(tree *BTree)  {
	if tree==nil {
		retcurn
	}
	if tree.leftTree==nil&&tree.rightTree==nil{
		return
	}
	c:=make([]*BTree,0)
	c = append(c, tree)
	for len(c)>0 {
		p :=c[len(c)-1]
		fmt.Printf("  %d   ",p.value)
		c=c[:len(c)-1]
		if p.rightTree!=nil {
			c = append(c, p.rightTree)
		}
		if p.leftTree!=nil {
			c = append(c, p.leftTree)
		}
	}
}

//middle

func mid_dfs(tree *BTree)  {
	if tree==nil {
		return
	}
	if tree.leftTree==nil&&tree.rightTree==nil{
		return
	}
	c:=make([]*BTree,0)
	for tree!=nil{
		c=append(c, tree)
		tree=tree.leftTree
	}
	for len(c)>0 {

		p :=c[len(c)-1]
		c=c[:len(c)-1]
		fmt.Printf("  %d   ",p.value)
		if p.rightTree!=nil{
			p=p.rightTree
			c = append(c, p)
			for p.leftTree!=nil {
				c=append(c, p.leftTree)
				p=p.leftTree
			}
		}

	}
}

func post_dfs(tree *BTree)  {
	if tree==nil {
		return
	}
	if tree.leftTree==nil&&tree.rightTree==nil{
		fmt.Println(tree.value)
		return
	}
	c:=make([]*BTree,0)
	lastnode:=tree
	node:=tree
	for node!=nil||len(c)>0 {
		for node!=nil{
			c= append(c, node)
			node=node.leftTree
		}
		node =c[len(c)-1]
		if node.rightTree==nil||node.rightTree==lastnode {
			fmt.Printf("  %d  ",node.value)
			lastnode=node
			node=nil
			c=c[:len(c)-1]
			//fmt.Printf(le)
		}else {
			node=node.rightTree
		}
	}
}


func main() {
	v := []int{1,2,3,4,7,8,9}
	head := createTree(v, 0,len(v)-1)
	//preTravel(head)
	//dfs_pre(head)
	//fmt.Println()
	postTravel(head)
	//fmt.Println()
	//midTravel(head)
	fmt.Println()
	//mid_dfs(head)
	post_dfs(head)
}	//levelTravel(head)
