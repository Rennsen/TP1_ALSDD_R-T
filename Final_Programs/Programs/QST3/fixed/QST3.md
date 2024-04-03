# Complexity Analysis of displaySublist Function

The `displaySublist` function in the Linked List Abstract Machine Library is responsible for printing a sublist of prime numbers between a given start and end value. 

## Finding the Starting Point
- **Time Complexity:** O(n)
- **Explanation:** In the worst-case scenario, the function may need to iterate through the entire linked list to find the starting point. This would require traversing `n` nodes, where `n` is the number of nodes in the linked list.

## Printing the Sublist
- **Time Complexity:** O(m)
- **Explanation:** Once the starting point is found, the function iterates through the linked list until it reaches the end point or the end of the list, whichever comes first. In the worst-case scenario, it may need to iterate through `m` nodes, where `m` is the number of nodes in the sublist.

## Overall Complexity
- **Time Complexity:** O(n + m)
- **Explanation:** The overall time complexity of the `displaySublist` function is O(n + m), where `n` is the number of nodes in the linked list and `m` is the number of nodes in the sublist. If `m` is significantly smaller than `n`, the complexity can be approximated to O(n).
