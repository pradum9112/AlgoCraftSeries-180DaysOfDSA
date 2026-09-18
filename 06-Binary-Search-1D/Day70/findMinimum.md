# Day70 - Find Minimum in Rotated Sorted Array

## Problem Statement

Given a rotated sorted array, find the minimum element using Binary Search.

The array was originally sorted in ascending order but then rotated at some point.

### Example

**Input**

```text
5
4 5 1 2 3
```

**Output**

```text
1
```

---

## Approaches

### Approach 1: Linear Search

Simply traverse the complete array and keep track of the minimum element.

```cpp
int ans = INT_MAX;

for (int num : arr) {
    ans = min(ans, num);
}
```

### Time Complexity

```text
O(N)
```

### Space Complexity

```text
O(1)
```

This works, but because the array is a **rotated sorted array**, we can use Binary Search.

---

# Optimal Approach - Binary Search

The important observation is that a rotated sorted array consists of two sorted parts.

For example:

```text
1 2 3 4 5 6 7
      ↓ rotation

4 5 6 7 1 2 3
```

There are two sorted portions:

```text
4 5 6 7
1 2 3
```

The minimum element is at the point where the rotation happened.

---

## Main Idea

We maintain:

```text
low
high
```

and calculate:

```text
mid
```

At every step, we determine which half is sorted.

### Case 1: Entire search space is sorted

If:

```cpp
arr[low] <= arr[high]
```

then the current range is already sorted.

Therefore:

```text
arr[low]
```

is the minimum.

So we can directly update the answer and stop.

---

### Case 2: Left Half Is Sorted

If:

```cpp
arr[low] <= arr[mid]
```

then:

```text
low -------- mid
  sorted
```

The minimum of this sorted half is:

```text
arr[low]
```

So we store it.

Then eliminate the left half:

```cpp
low = mid + 1;
```

Why?

Because the actual minimum, if it is not `arr[low]`, must be in the other half.

---

### Case 3: Right Half Is Sorted

Otherwise:

```text
mid -------- high
      sorted
```

The minimum of this sorted half is:

```text
arr[mid]
```

So we store:

```cpp
ans = min(ans, arr[mid]);
```

Then search the left side:

```cpp
high = mid - 1;
```

because the rotation point and therefore the minimum can be there.

---

# Pattern Recognition Clue

### How can I recognize this Binary Search pattern?

Whenever you see:

* sorted array
* rotated sorted array
* minimum/maximum
* search in a rotated array
* `O(log N)` expected

Think:

```text
"Which half is sorted?"
        ↓
Can I eliminate one half?
        ↓
Binary Search
```

For this problem, don't think:

> "Where is the minimum?"

Think:

> **"Which half is sorted, and where can the rotation point be?"**

That is the key pattern.

---

# Dry Run

Consider:

```text
arr = [4, 5, 6, 7, 1, 2, 3]
```

We want:

```text
minimum = 1
```

### Step 1

```text
low = 0
high = 6

arr[low]  = 4
arr[high] = 3
```

Check:

```text
4 <= 3 ❌
```

So the complete range is not sorted.

Calculate:

```text
mid = 3
arr[mid] = 7
```

Check left half:

```text
arr[low] <= arr[mid]

4 <= 7 ✅
```

Therefore left half is sorted:

```text
[4 5 6 7] [1 2 3]
 ↑        ↑
low      mid
```

The minimum of the sorted left half is `4`.

```text
ans = 4
```

Now eliminate left half:

```text
low = mid + 1
low = 4
```

---

### Step 2

Now:

```text
[4 5 6 7 1 2 3]
          ↑   ↑
         low high
```

Actually:

```text
low = 4
high = 6

arr[low] = 1
arr[high] = 3
```

Check:

```text
1 <= 3 ✅
```

The current search space is already sorted:

```text
[1 2 3]
 ↑   ↑
low high
```

Therefore:

```text
arr[low] = 1
```

is the minimum.

```text
ans = 1
```

Break the loop.

### Final Answer

```text
1
```

---

# Code

```cpp
class Solution {
public:
    int findMin(vector<int>& arr) {
        int low = 0;
        int high = arr.size() - 1;
        int ans = INT_MAX;

        while (low <= high) {

            if (arr[low] <= arr[high]) {
                ans = min(ans, arr[low]);
                break;
            }

            int mid = low + (high - low) / 2;

            if (arr[low] <= arr[mid]) {
                ans = min(ans, arr[low]);
                low = mid + 1;
            }
            else {
                ans = min(ans, arr[mid]);
                high = mid - 1;
            }
        }

        return ans;
    }
};
```

---

# Why `ans` Is Needed?

Har step par humein ek possible minimum mil sakta hai.

Example:

```text
[4 5 6 7 1 2 3]
```

Pehle sorted half se:

```text
possible minimum = 4
```

Baad mein:

```text
possible minimum = 1
```

Isliye:

```cpp
ans = min(ans, candidate);
```

use karte hain.

Finally `ans` mein smallest candidate rahega.

---

# Time Complexity

Har step mein search space approximately half ho jata hai.

```text
N
N/2
N/4
N/8
...
```

Therefore:

```text
Time Complexity = O(log N)
```

---

# Space Complexity

Hum sirf kuch variables use kar rahe hain:

```text
low
high
mid
ans
```

Therefore:

```text
Space Complexity = O(1)
```

---

# Complexity Comparison

| Approach      |         Time |    Space |
| ------------- | -----------: | -------: |
| Linear Search |         O(N) |     O(1) |
| Binary Search | **O(log N)** | **O(1)** |

---

# What I Learned

* Rotated sorted array ko dekhkar Binary Search pattern recognize karna.
* Har step mein identify karna ki kaunsa half sorted hai.
* Sorted half ka minimum directly identify karna.
* Unnecessary half ko eliminate karna.
* `low + (high - low) / 2` se safe `mid` calculate karna.
* Sorted search space mil jaane par directly `arr[low]` ko minimum consider karna.

## Key Takeaway

```text
Rotated Sorted Array
        ↓
Which half is sorted?
        ↓
Find possible minimum
        ↓
Eliminate one half
        ↓
Binary Search
        ↓
O(log N)
```
