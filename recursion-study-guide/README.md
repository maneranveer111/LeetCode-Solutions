# Recursion – Complete Study Guide

---

## 1. What is Recursion?

**Recursion** is a programming technique where a function calls **itself** to solve a smaller version of the same problem, until it reaches a simple enough case (called the **base case**) that can be solved directly.

> "To understand recursion, you must first understand recursion."

### Real-life analogy
Imagine standing between two mirrors facing each other – you see a reflection inside a reflection inside a reflection… Recursion works the same way: a problem contains a smaller copy of itself.

---

## 2. How Recursion Works

Every recursive function has two essential parts:

| Part | Description |
|------|-------------|
| **Base Case** | The condition under which the function stops calling itself. Without this, you get infinite recursion (stack overflow). |
| **Recursive Case** | The part where the function calls itself with a **simpler / smaller** input, making progress toward the base case. |

### Execution model – the Call Stack
Each recursive call is pushed onto the **call stack**. When the base case is reached, calls start returning and are popped off the stack one by one.

```
factorial(3)
  └─ factorial(2)
       └─ factorial(1)
            └─ factorial(0)  ← base case returns 1
            returns 1
       returns 1 * 1 = 1
  returns 2 * 1 = 2
returns 3 * 2 = 6
```

---

## 3. Anatomy of a Recursive Function (C++)

```cpp
returnType solve(parameters) {
    // 1. Base case – stop the recursion
    if (base_condition) {
        return base_value;
    }

    // 2. Recursive case – reduce the problem and recurse
    return solve(smaller_parameters);
}
```

---

## 4. Key Recursion Patterns

### Pattern 1 – Linear Recursion (one call per step)
The function makes **exactly one** recursive call per invocation.

**Example:** Factorial
```
factorial(n) = n * factorial(n-1)
Base case   : factorial(0) = 1
```

---

### Pattern 2 – Tree / Binary Recursion (multiple calls per step)
The function makes **two or more** recursive calls per invocation, creating a tree of calls.

**Examples:** Fibonacci, Binary Tree traversal, Merge Sort, Quick Sort.

```
fib(n) = fib(n-1) + fib(n-2)
Base cases: fib(0) = 0, fib(1) = 1
```

Call tree for fib(4):
```
            fib(4)
           /      \
        fib(3)   fib(2)
        /    \   /    \
     fib(2) fib(1) fib(1) fib(0)
     /    \
  fib(1) fib(0)
```

---

### Pattern 3 – Head Recursion vs Tail Recursion

- **Head Recursion:** The recursive call happens **before** any work is done.
- **Tail Recursion:** The recursive call is the **last operation** in the function (no pending work after the call returns). Compilers can optimize tail recursion into a loop.

```cpp
// Head recursion – call first, then print
void headPrint(int n) {
    if (n == 0) return;
    headPrint(n - 1);   // call first
    cout << n << " ";   // work after
}
// Output for n=3: 1 2 3

// Tail recursion – work first, then call
void tailPrint(int n) {
    if (n == 0) return;
    cout << n << " ";   // work first
    tailPrint(n - 1);   // call last
}
// Output for n=3: 3 2 1
```

---

### Pattern 4 – Divide and Conquer
Split the problem into independent sub-problems, solve each recursively, then combine results.

**Examples:** Merge Sort, Quick Sort, Binary Search.

```
mergeSort(arr):
  ├─ mergeSort(left half)
  ├─ mergeSort(right half)
  └─ merge(left, right)
```

---

### Pattern 5 – Backtracking
Try a choice, recurse, then **undo** the choice (backtrack) and try the next option.

**Examples:** N-Queens, Sudoku, Permutations, Subsets.

```
solve(choices):
  for each choice:
    make choice
    solve(remaining choices)   ← recurse
    undo choice                ← backtrack
```

---

### Pattern 6 – Memoization (Top-Down Dynamic Programming)
Cache the result of each sub-problem so it is computed only once.

```
fib(n, memo):
  if n in memo  → return memo[n]
  memo[n] = fib(n-1, memo) + fib(n-2, memo)
  return memo[n]
```

---

## 5. How to Recognize a Recursion Problem

Ask yourself the following questions when you see a problem:

| Question | If YES → likely recursive |
|----------|--------------------------|
| Can the problem be broken into **identical smaller sub-problems**? | ✅ |
| Is the input a **tree, graph, or linked list**? | ✅ |
| Does the problem involve **all subsets, permutations, or combinations**? | ✅ |
| Do you need to **explore all paths** (e.g., maze, grid)? | ✅ |
| Is the problem naturally **defined recursively** (e.g., factorial, Fibonacci)? | ✅ |
| Does the problem say "find all", "count all", or "generate all"? | ✅ |
| Does the problem involve **balanced parentheses, expressions, or grammars**? | ✅ |

### Common LeetCode problem categories that use recursion
- Tree problems (DFS traversals, path sums, lowest common ancestor)
- Graph problems (DFS, connected components)
- Backtracking (subsets, permutations, combinations, N-Queens, Sudoku)
- Divide and conquer (sort algorithms, binary search)
- Dynamic programming (top-down with memoization)
- String problems (palindrome partitioning, word break)

---

## 6. Time and Space Complexity

| Recursion Type | Time Complexity | Space (Call Stack) |
|----------------|-----------------|--------------------|
| Linear (factorial) | O(n) | O(n) |
| Binary (naive Fibonacci) | O(2ⁿ) | O(n) |
| Memoized Fibonacci | O(n) | O(n) |
| Merge Sort | O(n log n) | O(n) |
| Backtracking (permutations) | O(n!) | O(n) |

---

## 7. Common Mistakes

1. **Missing base case** → infinite recursion → stack overflow.
2. **Base case never reached** → the recursive call does not make progress toward the base case.
3. **Wrong return value** → forgetting to `return` the result of the recursive call.
4. **Modifying shared state without backtracking** → incorrect backtracking solutions.

---

## 8. Tips

- Always write the **base case first**.
- **Trust the recursion** – assume the function correctly solves a smaller problem and build on it.
- Draw the **recursion tree** on paper for small inputs to understand the flow.
- Use **memoization** when overlapping sub-problems appear (same call with same args).
- Convert to iteration only when recursion depth causes a stack overflow.

---

## 9. C++ Code Reference

See **[recursion-examples.cpp](./recursion-examples.cpp)** for runnable C++ implementations of all the patterns above.
