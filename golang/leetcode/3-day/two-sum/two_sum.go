package main

func search(numbers []int, target int) int {
	// binary search for `target` that satisfies difference equation
	lo := 0
	hi := len(numbers) - 1
	for lo <= hi {
		mid := lo + (hi-lo)/2
		if numbers[mid] == target {
			return mid
		} else if numbers[mid] < target {
			lo = mid + 1
		} else if numbers[mid] > target {
			hi = mid - 1
		}
	}
	return -1
}

func justifyLeft(numbers []int) []int {
	// force expected order in output pair (i.e., [index1, index2] s.t. index1 < index2)
	if numbers[0] > numbers[1] {
		return []int{numbers[1], numbers[0]}
	}
	return numbers
}

func twoSum(numbers []int, target int) []int {
	ret := []int{-1, -1}
	// fix `k` on each iteration and search for `element == target - k`
	for index, value := range numbers {
		match_index := search(numbers, target-value)
		if match_index != -1 && match_index != index {
			ret = []int{match_index + 1, index + 1}
		}
	}
	return justifyLeft(ret)
}
