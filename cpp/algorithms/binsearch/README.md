# Binary Search

## Overview

Binary search is a search algorithm used to find the position of a target value within a sorted array. The algorithm works by repeatedly dividing the search interval in half until the target value is found or the search interval is empty. It is an efficient algorithm with a time complexity of O(log n), where n is the number of elements in the array.

Here's how binary search works:
- Find the middle element of the array.
- If the middle element is the target value, return its position.
- If the target value is less than the middle element, repeat the search on the left half of the array.
- If the target value is greater than the middle element, repeat the search on the right half of the array.
- If the target value is not found and the search interval is empty, the target value is not in the array.

For example, suppose we want to find the position of the name "John" in a phone book. We open the book to the middle and find the name "Michael." Since "John" comes before "Michael" alphabetically, we repeat the search on the left half of the book. We now have a new search interval that is the left half of the original interval. We continue this process of dividing the search interval in half until we find the name "John" or the search interval is empty.

## "Animation"

Here's an "animation" of binary search in action:

---


```sql
Initial array: [1, 3, 5, 7, 9, 11, 13, 15]

Search for value 9:

  1   3   5   7   9  11  13  15
  ----------------------------
              ^   ^

Middle element is 7, which is less than 9. Discard left half:

  1   3   5   7   9  11  13  15
                  -------
                  ^   ^

Middle element is 9, which is the target. Return its position.

  1   3   5   7   9  11  13  15
                  -------
                      ^
```

### Space/Time Complexity
The iterative version of binary search has a space complexity of O(1) because it only uses a few variables to keep track of the search interval. Its time complexity is O(log n) because it halves the search interval on each iteration.

The recursive version of binary search also has a space complexity of O(log n) because it uses the call stack to keep track of the search interval. Its time complexity is also O(log n) because it divides the search interval in half on each recursive call.
