package medium

func minimumTotal(triangle [][]int) int {
    memo := make([][]int,len(triangle))
    for i := 0 ; i < len(triangle) ; i++ {
        memo[i] = make([]int,len(triangle[i]))
    }
    minValue := 100000
    for i := 0 ; i < len(triangle[len(triangle)-1]) ; i++ {
        minValue = min(minValue,triangle[len(triangle)-1][i])
        memo[len(triangle)-1][i] = triangle[len(triangle)-1][i]
    }
    if len(triangle) == 1 {
        return minValue
    }
    for i := len(triangle) - 2 ; i >= 0 ; i-- {
        for j := 0 ; j < len(triangle[i]) ; j++ {
            memo[i][j] = min(memo[i+1][j],memo[i+1][j+1])+triangle[i][j]
        }
    }
    return memo[0][0]
}