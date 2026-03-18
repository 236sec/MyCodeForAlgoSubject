package easy

func removeElement(nums []int, val int) int {
    current := 0
    for i := 0 ; i < len(nums) ; i++ {
        if nums[i] != val {
            nums[current] = nums[i]
            current++
        }
    }
    return current
}