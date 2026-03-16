package hard

func superEggDrop(k int, n int) int {
    memo := make([][]int, k+1)
    for i := range memo {
        memo[i] = make([]int, n+1)
        for j := range memo[i] {
            memo[i][j] = -1
        }
    }
	return find(k,n,memo)
}

func find(k int, n int, memo [][]int) int {
    if n == 0 {
        return 0
    }
	if n == 1 {
		return 1
	}
	if k == 1 {
		return n
	}
	if memo[k][n] != -1 {
		return memo[k][n]
	}
	ans := 10000
	for i := 1 ; i < n ; i++ {
		temp := max(find(k-1,i-1,memo),find(k,n-i,memo)) + 1
		ans = min(temp,ans)
	}
	memo[k][n] = ans
	return ans
}

func min(a, b int) int {
    if a < b { return a }
    return b
}

func max(a, b int) int {
    if a > b { return a }
    return b
}