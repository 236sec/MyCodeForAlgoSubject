package easy

func longestCommonPrefix(strs []string) string {
    val := -1
    isGood := true
    for {
        if !isGood || val + 1 >= len(strs[0]) {
            break
        }
        checkChar := strs[0][val+1]
        for row := 0 ; row < len(strs) ; row++ {
            if val+1 >= len(strs[row]) || strs[row][val+1] != checkChar {
                isGood = false
                break
            }
        }
        if isGood {
            val++
        }
    }
    if val == -1 {
        return ""
    } else {
        return strs[0][:val+1]
    }
}