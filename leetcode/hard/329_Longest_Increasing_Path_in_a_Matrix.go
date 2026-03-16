package hard

func checkFromThere(current int,i int,j int, matrix [][]int) bool {
	if i >= len(matrix) || i < 0 {
		return false
	}
	if j >= len(matrix[0]) || j < 0 {
		return false
	}
	if current > matrix[i][j] {
		return true
	}
	return false
}

func dp(i int,j int, memo [][]int, matrix [][]int) int {
	if memo[i][j] != 0 {
		return memo[i][j]
	}
	ans := 1
	if checkFromThere(matrix[i][j],i+1,j,matrix) {
		ans = max(ans,dp(i+1,j,memo,matrix) + 1)
	}
	if checkFromThere(matrix[i][j],i-1,j,matrix) {
		ans = max(ans,dp(i-1,j,memo,matrix) + 1)
	}
	if checkFromThere(matrix[i][j],i,j+1,matrix) {
		ans = max(ans,dp(i,j+1,memo,matrix) + 1)
	}
	if checkFromThere(matrix[i][j],i,j-1,matrix) {
		ans = max(ans,dp(i,j-1,memo,matrix) + 1)
	}
	memo[i][j] = ans
	return ans
}

func longestIncreasingPath(matrix [][]int) int {
    if len(matrix) == 0 {
        return 0
    }
    memo := make([][]int,len(matrix))
	for i := 0 ; i < len(matrix) ; i++ {
		memo[i] = make([]int,len(matrix[0]))
	}
    ans := 0
	for i := 0 ; i < len(matrix) ; i++ {
		for j := 0 ; j < len(matrix[i]) ; j++ {
			ans = max(ans,dp(i,j,memo,matrix))
		}
	}
	return ans
}