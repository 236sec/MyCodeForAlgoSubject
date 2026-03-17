package medium

func minPathSum(grid [][]int) int {
    memo := make([][]int,len(grid))
    for i := 0 ; i < len(grid) ; i++ {
        memo[i] = make([]int,len(grid[i]))
    }
    // base case for first row
    memo[0][0] = grid[0][0]
    for j := 1 ; j < len(grid[0]) ; j++ {
        memo[0][j] = memo[0][j-1] + grid[0][j]
    }
    // base case for first col
    for i := 1 ; i < len(grid) ; i++ {
        memo[i][0] = memo[i-1][0] + grid[i][0]
    }
    for i := 1 ; i < len(grid) ; i++ {
        for j := 1 ; j < len(grid[i]) ; j++ {
            memo[i][j] = min(memo[i-1][j],memo[i][j-1]) + grid[i][j]
        }
    }
    return memo[len(memo)-1][len(memo[len(memo)-1])-1]
}