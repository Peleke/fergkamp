package main

import "fmt"

func reverseWord(s []rune, start, end int) {
	for start < end {
		s[start], s[end] = s[end], s[start]
		start += 1
		end -= 1
	}
}

func reverseWords(s string) string {
	runes := []rune(s)
	begindex := 0
	for index, value := range s {
		if value == ' ' {
			reverseWord(runes, begindex, index-1)
			begindex = index + 1
		} else if index == len(s)-1 {
			reverseWord(runes, begindex, index)
		}
	}
	return string(runes)
}

func main() {
	s := "salve, munde"
	fmt.Println(reverseWords(s))
}
