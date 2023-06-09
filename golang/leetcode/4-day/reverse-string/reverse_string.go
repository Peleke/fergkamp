package main

import "fmt"

func reverseString(s []byte) {
	// init pointers to ends of slice
	lo := 0
	hi := len(s) - 1
	// swap position of elements as we walk towards middle
	for lo < hi {
		s[lo], s[hi] = s[hi], s[lo]
		lo += 1
		hi -= 1
	}
}

func main() {
	byte_string := []byte{'s', 'a', 'l', 'v', 'e', ' ', 'm', 'u', 'n', 'd', 'e'}
	reverseString((byte_string))
	fmt.Println(string(byte_string[:]))
}
