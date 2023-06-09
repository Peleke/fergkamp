package main

func moveZeroes(nums []int) {
	// register point to which to move non-zero elements (i.e., start)
	insertion_point := 0

	for index, value := range nums {
		// swap position of zeros with non-zero elements
		if value != 0 {
			nums[index], nums[insertion_point] = nums[insertion_point], nums[index]
			insertion_point += 1
		}
	}
}

func main() {
	nums := []int{1, 0, 0, 2}
	moveZeroes(nums)
}
