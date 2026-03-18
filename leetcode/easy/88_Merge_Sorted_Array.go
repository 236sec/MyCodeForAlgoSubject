package easy

func merge(nums1 []int, m int, nums2 []int, n int)  {
    left := m-1
    right := n-1
	current := m+n-1
    for {
		if left == -1 || right == -1 {
			break
		}
		if nums1[left] > nums2[right] {
			nums1[current] = nums1[left]
			current--
			left--
		} else {
			nums1[current] = nums2[right]
			current--
			right--
		}
	}
	for i := left ; i > -1 ; i-- {
		nums1[current] = nums1[i]
		current--
	}
	for i := right ; i > -1 ; i-- {
		nums1[current] = nums2[i]
		current--
	}
}