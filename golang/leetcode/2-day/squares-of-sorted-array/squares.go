package main

import (
	"fmt"
)

func findBoundaryLinear(nums []int) int {
	// linsearch to find boundary
	for index, num := range nums {
		// return index of first non-negative element
		if num >= 0 {
			return index
		}
	}
	return -1
}

func squareReverse(nums []int) []int {
	squared := make([]int, 0, len(nums))
	for i := len(nums) - 1; i >= 0; i -= 1 {
		squared = append(squared, nums[i]*nums[i])
	}
	return squared
}

func interweave(nums []int, pospointer, negpointer int) []int {
	interwoven := make([]int, 0, len(nums))

	// while pospointer and negpointer haven't both run off bounds...
	for pospointer < len(nums) || negpointer >= 0 {
		if negpointer < 0 {
			// exhaust pospointer
			interwoven = append(interwoven, nums[pospointer]*nums[pospointer])
			pospointer += 1
		} else if pospointer == len(nums) {
			// exhaust negpointer
			interwoven = append(interwoven, nums[negpointer]*nums[negpointer])
			negpointer -= 1
		} else {
			// identify and insert whichever square will be smaller
			if -nums[negpointer] <= nums[pospointer] {
				interwoven = append(interwoven, nums[negpointer]*nums[negpointer])
				negpointer -= 1
			} else {
				interwoven = append(interwoven, nums[pospointer]*nums[pospointer])
				pospointer += 1
			}
		}
	}
	return interwoven
}

func squareSlice(nums []int) []int {
	// pre-allocate slice
	squared := make([]int, 0, len(nums))
	// iterate and square each element
	for _, v := range nums {
		squared = append(squared, v*v)
	}
	// return squares
	return squared
}

func sortedSquares(nums []int) []int {
	// determine if `nums` contains negative numbers --
	// this implies two "regions" to be handled separately
	if nums[0] >= 0 {
		// if no negatives, simply square and return
		return squareSlice(nums)
	} else {
		// otherwise, identify boundary between regions...
		pospointer := findBoundaryLinear(nums)
		if pospointer == -1 {
			// reverse and square
			return squareReverse(nums)
		} else {
			// ...and "interweave" squares
			return interweave(nums, pospointer, pospointer-1)
		}
	}
}

func main() {
	// nums := []int{-10, -5, -1, 0, 1, 2, 3, 4, 5}
	nums := []int{-1}
	fmt.Println(sortedSquares(nums))
}
