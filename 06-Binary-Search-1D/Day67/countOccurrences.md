# Day67 — Count Occurrences in a Sorted Array

## Problem

Given a **sorted array** `arr` and an integer `target`, count how many times `target` occurs in the array.

### Example

```text
Input:
arr = [1, 2, 2, 2, 3, 4]
target = 2

Output:
3
```

The target `2` occurs at indices `1, 2, 3`.

---

## Approach 1 — Linear Search

Traverse the complete array and increment `count` whenever:

```cpp
arr[i] == target
```

### Algorithm

1. Initialize `count = 0`.
2. Traverse the array.
3. If `arr[i] == target`, increment `count`.
4. Return `count`.

### Complexity

* Time: `O(N)`
* Space: `O(1)`

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countOccurrences(vector<int>& arr, int target) {
        int n = arr.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] == target) {
                count++;
            }
        }

        return count;
    }
};

int main() {
    Solution sol;

    vector<int> arr = {1, 2, 2, 2, 3, 4};
    int target = 2;

    cout << sol.countOccurrences(arr, target) << "\n";

    return 0;
}
```

---

## Approach 2 — Binary Search with First & Last Search

Because the array is sorted, we can use binary search.

Instead of counting every occurrence, find:

* **First occurrence** of target
* **Last occurrence** of target

Then:

```text
count = last - first + 1
```

### First Occurrence

When:

```cpp
arr[mid] == target
```

we found a target, but there might be another target on the left.

So:

```cpp
high = mid - 1;
```

We continue searching left.

### Last Occurrence

When:

```cpp
arr[mid] == target
```

we found a target, but there might be another target on the right.

So:

```cpp
low = mid + 1;
```

We continue searching right.

### Complexity

Two binary searches are performed:

```text
O(log N) + O(log N) = O(log N)
```

* Time: `O(log N)`
* Space: `O(1)`

---

## Approach 3 — Common `findBound()` Function

The first and last occurrence searches are almost identical.

The only difference is what we do when:

```cpp
arr[mid] == target
```

For first occurrence:

```cpp
high = mid - 1;
```

For last occurrence:

```cpp
low = mid + 1;
```

Therefore, we can create one reusable function:

```cpp
findBound(arr, target, isFirst)
```

If:

```cpp
isFirst == true
```

find the first occurrence.

If:

```cpp
isFirst == false
```

find the last occurrence.

This makes the code shorter and avoids duplicate binary-search logic.

### Complexity

* Time: `O(log N)`
* Space: `O(1)`

---

# Dry Run

```text
arr = [1, 2, 2, 2, 3, 4]
target = 2
```

## First Occurrence

Search for the first `2`.

```text
low = 0
high = 5
mid = 2
arr[mid] = 2
```

Target found.

Save:

```text
first = 2
```

But maybe another `2` exists on the left:

```text
high = mid - 1 = 1
```

Next:

```text
low = 0
high = 1
mid = 0
arr[mid] = 1
```

`1 < 2`

```text
low = 1
```

Next:

```text
low = 1
high = 1
mid = 1
arr[mid] = 2
```

Target found.

```text
first = 1
```

Continue left:

```text
high = 0
```

Search ends.

Therefore:

```text
first = 1
```

---

## Last Occurrence

Search for the last `2`.

Initially:

```text
low = 0
high = 5
mid = 2
arr[mid] = 2
```

Target found:

```text
last = 2
```

But maybe another `2` exists on the right:

```text
low = mid + 1 = 3
```

Next:

```text
low = 3
high = 5
mid = 4
arr[mid] = 3
```

`3 > 2`

```text
high = 3
```

Next:

```text
low = 3
high = 3
mid = 3
arr[mid] = 2
```

Target found:

```text
last = 3
```

Continue right:

```text
low = 4
```

Search ends.

Therefore:

```text
last = 3
```

---

## Final Count

```text
count = last - first + 1

      = 3 - 1 + 1

      = 3
```

### Answer

```text
3
```

---

# Pattern Recognition

Ye problem dekhte hi ye clues identify karo:

### Clue 1 — Array sorted hai

```text
[1, 2, 2, 2, 3, 4]
```

Sorted array → **Binary Search possible**

### Clue 2 — Repeated target hai

Question occurrence/count pooch raha hai.

So think:

```text
First Position
+
Last Position
```

### Clue 3 — Range of equal elements

Agar target ka range:

```text
[first ........ last]
```

hai, to number of elements:

```text
last - first + 1
```

---

# Connection with Previous Days

Day62:

```text
Lower Bound
→ first index where arr[i] >= target
```

Day63:

```text
Upper Bound
→ first index where arr[i] > target
```

Day64:

```text
Search Insert Position
→ first index where arr[i] >= target
```

Day65:

```text
Floor & Ceil
```

Day66:

```text
First & Last Position
```

Day67:

```text
Count Occurrences
→ Last Position - First Position + 1
```

Isliye **Day67 actually Day66 ka direct application hai.**

---

# Common Mistake

Target array mein nahi hai:

```text
arr = [1, 2, 3, 4]
target = 5
```

First occurrence:

```text
first = -1
```

To immediately:

```cpp
if (first == -1) return 0;
```

Otherwise `last - first + 1` invalid result de sakta hai.

---

# Important Assumption

Binary-search approaches ke liye array **sorted** hona chahiye.

Linear search ke liye sorted hona required nahi hai.

---

# One-Line Revision

> **Count Occurrences = Last Position − First Position + 1**

Aur yaad rakho:

> **First → LEFT | Last → RIGHT**
