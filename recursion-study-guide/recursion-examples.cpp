/*
 * =====================================================================
 *  Recursion – C++ Reference Examples
 * =====================================================================
 *
 *  Covers:
 *    1. Factorial           – Linear recursion
 *    2. Power (x^n)         – Linear recursion with optimization
 *    3. Fibonacci (naive)   – Tree / Binary recursion
 *    4. Fibonacci (memo)    – Memoization (Top-Down DP)
 *    5. Sum of Digits       – Linear recursion
 *    6. Binary Search       – Divide & Conquer recursion
 *    7. Merge Sort          – Divide & Conquer recursion
 *    8. Head vs Tail Print  – Head / Tail recursion patterns
 *    9. Reverse a String    – Linear recursion on arrays
 *   10. Generate Subsets    – Backtracking / Subset pattern
 *   11. Generate Permutations – Backtracking pattern
 *   12. Tower of Hanoi      – Classic multi-step recursion
 *
 *  Compile & run:
 *    g++ -std=c++17 -o recursion recursion-examples.cpp && ./recursion
 * =====================================================================
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;  // acceptable in competitive / study code; avoid in production

// ─────────────────────────────────────────────────────────────────────
// 1. Factorial – n! = n * (n-1)!
//    Base case : 0! = 1
//    Pattern   : Linear recursion
// ─────────────────────────────────────────────────────────────────────
long long factorial(int n) {
    if (n == 0) return 1;          // base case
    return n * factorial(n - 1);  // recursive case
}

// ─────────────────────────────────────────────────────────────────────
// 2. Power – x^n using fast exponentiation
//    Base case : x^0 = 1
//    Pattern   : Divide & Conquer (halves the problem at each step)
// ─────────────────────────────────────────────────────────────────────
double power(double x, int n) {
    if (n == 0) return 1.0;                     // base case
    if (n < 0)  return 1.0 / power(x, -n);     // handle negative exponent

    double half = power(x, n / 2);
    if (n % 2 == 0) return half * half;         // even power
    return x * half * half;                     // odd power
}

// ─────────────────────────────────────────────────────────────────────
// 3. Fibonacci (naive) – fib(n) = fib(n-1) + fib(n-2)
//    Base cases: fib(0) = 0, fib(1) = 1
//    Pattern   : Tree (binary) recursion  –  O(2^n) time
// ─────────────────────────────────────────────────────────────────────
int fibNaive(int n) {
    if (n <= 1) return n;                        // base cases
    return fibNaive(n - 1) + fibNaive(n - 2);  // two recursive calls
}

// ─────────────────────────────────────────────────────────────────────
// 4. Fibonacci (memoized) – same recurrence, but cache results
//    Pattern: Top-Down Dynamic Programming  –  O(n) time
// ─────────────────────────────────────────────────────────────────────
int fibMemo(int n, vector<int>& memo) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];           // already computed
    memo[n] = fibMemo(n - 1, memo) + fibMemo(n - 2, memo);
    return memo[n];
}

// ─────────────────────────────────────────────────────────────────────
// 5. Sum of Digits – sum of all decimal digits of n
//    Base case : n < 10  →  return n
//    Pattern   : Linear recursion
// ─────────────────────────────────────────────────────────────────────
int sumOfDigits(int n) {
    if (n < 10) return n;                       // base case
    return (n % 10) + sumOfDigits(n / 10);     // last digit + recurse
}

// ─────────────────────────────────────────────────────────────────────
// 6. Binary Search (recursive)
//    Base case : lo > hi  →  element not found
//    Pattern   : Divide & Conquer
// ─────────────────────────────────────────────────────────────────────
int binarySearch(const vector<int>& arr, int lo, int hi, int target) {
    if (lo > hi) return -1;                     // base case: not found

    int mid = lo + (hi - lo) / 2;
    if (arr[mid] == target) return mid;         // found

    if (arr[mid] > target)
        return binarySearch(arr, lo, mid - 1, target);  // search left
    return binarySearch(arr, mid + 1, hi, target);      // search right
}

// ─────────────────────────────────────────────────────────────────────
// 7. Merge Sort
//    Pattern : Divide & Conquer
// ─────────────────────────────────────────────────────────────────────
void merge(vector<int>& arr, int lo, int mid, int hi) {
    vector<int> temp;
    int i = lo, j = mid + 1;

    while (i <= mid && j <= hi) {
        if (arr[i] <= arr[j]) temp.push_back(arr[i++]);
        else                  temp.push_back(arr[j++]);
    }
    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= hi)  temp.push_back(arr[j++]);

    for (int k = lo; k <= hi; k++)
        arr[k] = temp[k - lo];
}

void mergeSort(vector<int>& arr, int lo, int hi) {
    if (lo >= hi) return;                       // base case: single element

    int mid = lo + (hi - lo) / 2;
    mergeSort(arr, lo, mid);                    // sort left half
    mergeSort(arr, mid + 1, hi);               // sort right half
    merge(arr, lo, mid, hi);                   // combine
}

// ─────────────────────────────────────────────────────────────────────
// 8a. Head Recursion – recursive call BEFORE the work
//     Output: ascending order  (1 2 3 ... n)
// ─────────────────────────────────────────────────────────────────────
void headPrint(int n) {
    if (n == 0) return;
    headPrint(n - 1);     // recurse first
    cout << n << " ";     // work after returning
}

// 8b. Tail Recursion – recursive call AFTER the work (last operation)
//     Output: descending order  (n ... 2 1)
void tailPrint(int n) {
    if (n == 0) return;
    cout << n << " ";     // work first
    tailPrint(n - 1);     // recurse last
}

// ─────────────────────────────────────────────────────────────────────
// 9. Reverse a String in-place
//    Base case : lo >= hi  (empty or single character segment)
//    Pattern   : Linear recursion with two-pointer approach
// ─────────────────────────────────────────────────────────────────────
void reverseString(string& s, int lo, int hi) {
    if (lo >= hi) return;                       // base case
    swap(s[lo], s[hi]);
    reverseString(s, lo + 1, hi - 1);          // recurse on inner part
}

// ─────────────────────────────────────────────────────────────────────
// 10. Generate All Subsets (Power Set)
//     Pattern : Backtracking / include-exclude
// ─────────────────────────────────────────────────────────────────────
void generateSubsets(const vector<int>& nums, int index,
                     vector<int>& current, vector<vector<int>>& result) {
    if (index == (int)nums.size()) {            // base case: processed all elements
        result.push_back(current);
        return;
    }

    // Choice 1: include nums[index]
    current.push_back(nums[index]);
    generateSubsets(nums, index + 1, current, result);

    // Choice 2: exclude nums[index]  (backtrack)
    current.pop_back();
    generateSubsets(nums, index + 1, current, result);
}

// ─────────────────────────────────────────────────────────────────────
// 11. Generate All Permutations
//     Pattern : Backtracking (swap-based)
// ─────────────────────────────────────────────────────────────────────
void generatePermutations(vector<int>& nums, int start,
                           vector<vector<int>>& result) {
    if (start == (int)nums.size()) {            // base case: one complete permutation
        result.push_back(nums);
        return;
    }

    for (int i = start; i < (int)nums.size(); i++) {
        swap(nums[start], nums[i]);             // make a choice
        generatePermutations(nums, start + 1, result);  // recurse
        swap(nums[start], nums[i]);             // undo the choice (backtrack)
    }
}

// ─────────────────────────────────────────────────────────────────────
// 12. Tower of Hanoi
//     Move n disks from source peg to destination peg using auxiliary peg.
//     Base case : n == 1  →  move directly
//     Pattern   : Multi-step recursion
// ─────────────────────────────────────────────────────────────────────
void towerOfHanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        cout << "  Move disk 1 from " << from << " to " << to << "\n";
        return;
    }
    towerOfHanoi(n - 1, from, aux, to);   // move top (n-1) disks to aux
    cout << "  Move disk " << n << " from " << from << " to " << to << "\n";
    towerOfHanoi(n - 1, aux, to, from);   // move (n-1) disks from aux to to
}

// ─────────────────────────────────────────────────────────────────────
// main – demonstrate all examples
// ─────────────────────────────────────────────────────────────────────
int main() {
    cout << "=== 1. Factorial ===\n";
    for (int i = 0; i <= 6; i++)
        cout << i << "! = " << factorial(i) << "\n";

    cout << "\n=== 2. Power ===\n";
    cout << "2^10 = " << power(2, 10) << "\n";
    cout << "3^0  = " << power(3, 0)  << "\n";
    cout << "2^-3 = " << power(2, -3) << "\n";

    cout << "\n=== 3. Fibonacci (naive) ===\n";
    for (int i = 0; i <= 8; i++)
        cout << "fib(" << i << ") = " << fibNaive(i) << "\n";

    cout << "\n=== 4. Fibonacci (memoized) ===\n";
    {
        int n = 10;
        vector<int> memo(n + 1, -1);
        for (int i = 0; i <= n; i++)
            cout << "fib(" << i << ") = " << fibMemo(i, memo) << "\n";
    }

    cout << "\n=== 5. Sum of Digits ===\n";
    cout << "sumOfDigits(1234) = " << sumOfDigits(1234) << "\n";   // 10
    cout << "sumOfDigits(999)  = " << sumOfDigits(999)  << "\n";   // 27

    cout << "\n=== 6. Binary Search ===\n";
    {
        vector<int> arr = {1, 3, 5, 7, 9, 11, 13};
        cout << "Search 7  → index " << binarySearch(arr, 0, arr.size()-1, 7)  << "\n";
        cout << "Search 6  → index " << binarySearch(arr, 0, arr.size()-1, 6)  << "\n";
        cout << "Search 13 → index " << binarySearch(arr, 0, arr.size()-1, 13) << "\n";
    }

    cout << "\n=== 7. Merge Sort ===\n";
    {
        vector<int> arr = {5, 2, 8, 1, 9, 3};
        cout << "Before: ";
        for (int x : arr) cout << x << " ";
        cout << "\n";
        mergeSort(arr, 0, arr.size() - 1);
        cout << "After : ";
        for (int x : arr) cout << x << " ";
        cout << "\n";
    }

    cout << "\n=== 8. Head vs Tail Recursion (n=5) ===\n";
    cout << "Head print (ascending) : ";
    headPrint(5);
    cout << "\n";
    cout << "Tail print (descending): ";
    tailPrint(5);
    cout << "\n";

    cout << "\n=== 9. Reverse String ===\n";
    {
        string s = "recursion";
        reverseString(s, 0, s.size() - 1);
        cout << "Reversed: " << s << "\n";
    }

    cout << "\n=== 10. All Subsets of {1,2,3} ===\n";
    {
        vector<int> nums = {1, 2, 3};
        vector<int> current;
        vector<vector<int>> result;
        generateSubsets(nums, 0, current, result);
        for (auto& subset : result) {
            cout << "{ ";
            for (int x : subset) cout << x << " ";
            cout << "}\n";
        }
    }

    cout << "\n=== 11. All Permutations of {1,2,3} ===\n";
    {
        vector<int> nums = {1, 2, 3};
        vector<vector<int>> result;
        generatePermutations(nums, 0, result);
        for (auto& perm : result) {
            for (int x : perm) cout << x << " ";
            cout << "\n";
        }
    }

    cout << "\n=== 12. Tower of Hanoi (n=3) ===\n";
    towerOfHanoi(3, 'A', 'C', 'B');

    return 0;
}
