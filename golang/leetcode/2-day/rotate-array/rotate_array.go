func swapPosition(nums []int, lo, hi int) {
	nums[lo], nums[hi] = nums[hi], nums[lo]
}

func reverseRange(nums []int, start, end int) {
	for start < end {
		swapPosition(nums, start, end)
		start += 1
		end -= 1
	}
}

func rotate(nums []int, k int) {
	k = k % len(nums)
	if k == 0 || len(nums) == 0 {
		return
	} else {
		reverseRange(nums, 0, len(nums)-1)
		reverseRange(nums, 0, k-1)
		reverseRange(nums, k, len(nums)-1)
	}
}