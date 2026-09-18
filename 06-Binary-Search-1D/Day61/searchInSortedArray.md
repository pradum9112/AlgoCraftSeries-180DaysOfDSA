# Day 61 — Search in Sorted Array

## Problem Statement

Given a **sorted array** `nums` and an integer `target`, return the index of `target` if it exists in the array.

If `target` is not present, return `-1`.

### Example

**Input:**

```text
6
1 3 5 7 9 11
7
```

**Output:**

```text
3
```

Because `7` index `3` par present hai.

---

# 1. Problem ko Dekhte Hi Kya Sochna Hai?

Sabse important skill hai **approach identify karna**.

Question ko directly code mein convert nahi karna.

Pehle properties identify karo:

```text
Search karna hai
      ↓
Array sorted hai
      ↓
Kya sorted property ka advantage le sakte hain?
      ↓
YES
      ↓
Binary Search
```

Yahan `sorted` word sabse important clue hai.

---

# 2. Pattern Recognition Clue

## 🔑 Strong Pattern

> **Sorted Array + Search → Binary Search**

Agar question mein ye combination mile:

* sorted array
* find target
* search element
* return index
* search in sorted sequence

toh sabse pehle **Binary Search** ke baare mein socho.

### Quick Recognition

```text
Search Problem
      ↓
Is data sorted?
   ↙       ↘
 NO        YES
 ↓          ↓
Linear    Binary
Search    Search
```

---

# 3. Approach 1 — Linear Search

## Idea

Array ke elements ko ek-ek karke check karo.

```text
nums[0]
   ↓
nums[1]
   ↓
nums[2]
   ↓
nums[3]
   ↓
...
```

Jab target mil jaaye, uska index return kar do.

Agar poora array check karne ke baad target nahi mila:

```cpp
return -1;
```

---

## Algorithm

1. `i = 0` se start karo.
2. `nums[i]` ko target se compare karo.
3. Agar equal hai → `i` return karo.
4. Otherwise next element par jao.
5. Array khatam ho jaaye → `-1` return karo.

---

## Code Variation — Linear Search

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n = nums.size();

        for (int i = 0; i < n; i++) {

            if (nums[i] == target) {
                return i;
            }
        }

        return -1;
    }
};

int main() {

    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cin >> target;

    Solution obj;

    cout << obj.search(nums, target) << endl;

    return 0;
}
```

---

# 4. Linear Search Dry Run

Array:

```text
[1, 3, 5, 7, 9, 11]
```

Target:

```text
7
```

| Index `i` | `nums[i]` | `nums[i] == target`? |
| --------: | --------: | -------------------- |
|         0 |         1 | No                   |
|         1 |         3 | No                   |
|         2 |         5 | No                   |
|         3 |         7 | Yes                  |

Target index `3` par mil gaya.

```text
Answer = 3
```

### Visualization

```text
Index:   0   1   2   3   4    5
         ↓   ↓   ↓   ↓
Array:  [1] [3] [5] [7] [9] [11]
                     ↑
                   Target
```

---

# 5. Linear Search ki Limitation

Maan lo:

```text
N = 1,000,000
```

aur target last position par hai.

Linear Search ko potentially:

```text
1,000,000
```

elements check karne padenge.

Therefore:

```text
Time = O(N)
```

Lekin yahan array **sorted** hai.

Toh humein har element check karne ki zaroorat nahi hai.

---

# 6. Approach 2 — Binary Search

Binary Search sorted array ki property ka advantage leta hai.

Hum poore array ko search nahi karte.

Har step mein search space ko approximately **half** kar dete hain.

Initially:

```text
low = 0
high = n - 1
```

Phir middle element:

```cpp
mid = low + (high - low) / 2;
```

Check karo:

```text
nums[mid]
```

---

# 7. Binary Search ke 3 Cases

## Case 1 — Target mil gaya

```cpp
nums[mid] == target
```

Then:

```cpp
return mid;
```

---

## Case 2 — `nums[mid] < target`

Example:

```text
nums[mid] = 7
target    = 9
```

Array sorted hai.

Agar middle `7` hai aur target `9` hai, toh target **left side mein nahi ho sakta**.

So left half discard karo.

```cpp
low = mid + 1;
```

---

## Case 3 — `nums[mid] > target`

Example:

```text
nums[mid] = 11
target    = 9
```

Target chhota hai.

Sorted array hone ki wajah se target right side mein nahi ho sakta.

So right half discard karo.

```cpp
high = mid - 1;
```

---

# 8. Binary Search Code Variation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n = nums.size();

        int low = 0;
        int high = n - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            else if (nums[mid] < target) {
                low = mid + 1;
            }

            else {
                high = mid - 1;
            }
        }

        return -1;
    }
};

int main() {

    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cin >> target;

    Solution obj;

    cout << obj.search(nums, target) << endl;

    return 0;
}
```

---

# 9. Binary Search Dry Run

Array:

```text
[1, 3, 5, 7, 9, 11, 13]
```

Target:

```text
9
```

Indices:

```text
Index:   0   1   2   3   4    5    6
Array:  [1] [3] [5] [7] [9]  [11] [13]
```

---

## Step 1

Initially:

```text
low = 0
high = 6
```

Calculate:

```text
mid = low + (high - low) / 2

mid = 0 + (6 - 0) / 2
mid = 3
```

So:

```text
nums[mid] = nums[3] = 7
```

Compare:

```text
7 == 9 → No
7 < 9  → Yes
```

Target right side mein hoga.

Therefore:

```cpp
low = mid + 1;
```

So:

```text
low = 4
high = 6
```

Search space:

```text
[9, 11, 13]
 ↑       ↑
low     high
```

---

## Step 2

```text
low = 4
high = 6
```

Calculate:

```text
mid = 4 + (6 - 4) / 2
mid = 5
```

So:

```text
nums[5] = 11
```

Compare:

```text
11 == 9 → No
11 > 9  → Yes
```

Target left side mein hoga.

Therefore:

```cpp
high = mid - 1;
```

Now:

```text
low = 4
high = 4
```

Search space:

```text
[9]
 ↑
low/high
```

---

## Step 3

```text
low = 4
high = 4
```

Therefore:

```text
mid = 4
```

```text
nums[4] = 9
```

Compare:

```text
9 == 9
```

Target mil gaya.

```text
Answer = 4
```

---

# 10. Binary Search ka Main Logic

Binary Search ko ratne ke bajay ye logic samjho:

```text
                Middle
                  ↓
             nums[mid]
                  ↓
        ┌─────────┴─────────┐
        ↓                   ↓
   nums[mid] < target   nums[mid] > target
        ↓                   ↓
  Left discard          Right discard
        ↓                   ↓
 low = mid + 1       high = mid - 1
```

Aur:

```text
nums[mid] == target
        ↓
   return mid
```

---

# 11. Search Space Half Kaise Ho Raha Hai?

Suppose:

```text
N = 16
```

Linear Search:

```text
16 → potentially 16 checks
```

Binary Search:

```text
16
 ↓
8
 ↓
4
 ↓
2
 ↓
1
```

Har iteration mein:

```text
Search Space → Search Space / 2
```

Therefore:

```text
O(log₂N)
```

Big-O mein:

```text
O(log N)
```

---

# 12. Linear Search vs Binary Search

| Property                       | Linear Search | Binary Search         |
| ------------------------------ | ------------- | --------------------- |
| Sorted array required?         | ❌ No          | ✅ Yes                 |
| Search method                  | One by one    | Middle element        |
| Sorted property use karta hai? | ❌ No          | ✅ Yes                 |
| Best Case                      | O(1)          | O(1)                  |
| Average Case                   | O(N)          | O(log N)              |
| Worst Case                     | O(N)          | O(log N)              |
| Space                          | O(1)          | O(1)                  |
| Implementation                 | Very simple   | Slightly more complex |
| Large sorted array             | Slow          | Very fast             |

---

# 13. Time Complexity — Detailed

## Linear Search

### Best Case

Target first element hai:

```text
[7, 1, 3, 5, 9]
 ↑
target
```

Only one comparison.

```text
O(1)
```

### Worst Case

Target last mein hai ya present nahi hai.

```text
N elements check
```

Therefore:

```text
O(N)
```

### Overall

```text
Best    = O(1)
Average = O(N)
Worst   = O(N)
```

---

# 14. Binary Search Complexity

Binary Search mein search space:

```text
N
N/2
N/4
N/8
N/16
...
1
```

Har step mein half ho raha hai.

Therefore number of steps approximately:

```text
log₂(N)
```

So:

```text
Best    = O(1)
Average = O(log N)
Worst   = O(log N)
```

---

# 15. Space Complexity

Dono approaches mein hum sirf kuch variables use kar rahe hain.

Linear:

```cpp
int i;
```

Binary:

```cpp
int low;
int high;
int mid;
```

Koi extra array/hashmap/recursion nahi.

Therefore:

```text
Linear Search  → O(1)
Binary Search  → O(1)
```

---

# 16. Important Code Detail — `mid`

Ye dono mathematically same hain:

```cpp
mid = (low + high) / 2;
```

and:

```cpp
mid = low + (high - low) / 2;
```

Lekin preferred form:

```cpp
mid = low + (high - low) / 2;
```

Reason:

`low + high` bahut large integer values par overflow kar sakta hai.

Isliye safer calculation:

```cpp
low + (high - low) / 2
```

use karte hain.

---

# 17. Approach Select Karne ka Interview Framework

Question dekhte hi ye process follow karo:

### Step 1 — Problem Type

```text
Mujhe element search karna hai.
```

### Step 2 — Data ki Property

```text
Array sorted hai.
```

### Step 3 — Optimization Opportunity

```text
Sorted hone ka advantage le sakta hoon?
```

Yes.

### Step 4 — Pattern

```text
Sorted + Search
      ↓
Binary Search
```

### Step 5 — Complexity Compare

```text
Linear Search  → O(N)
Binary Search  → O(log N)
```

Therefore binary search better choice hai.

---

# 18. Kab Linear Search Choose Karna Hai?

Agar array sorted nahi hai:

```text
[8, 2, 10, 1, 7, 4]
```

aur target search karna hai:

```text
7
```

toh normal case mein:

```text
Linear Search
```

use karenge.

Because Binary Search ke liye sorted order ka required property available nahi hai.

---

# 19. Kab Binary Search Choose Karna Hai?

Example:

```text
[1, 3, 5, 7, 9, 11, 13]
```

Target:

```text
11
```

Array sorted hai.

So:

```text
Sorted
  +
Search
  ↓
Binary Search
```

---

# 20. Common Mistakes

## Mistake 1 — Unsorted Array par Binary Search

Wrong:

```text
[5, 2, 9, 1, 7]
```

Is par normal binary search valid nahi hai.

---

## Mistake 2 — `low = mid`

Wrong:

```cpp
low = mid;
```

Correct:

```cpp
low = mid + 1;
```

Because `mid` already check ho chuka hai.

---

## Mistake 3 — `high = mid`

Wrong:

```cpp
high = mid;
```

Correct:

```cpp
high = mid - 1;
```

Again, `mid` already check ho chuka hai.

---

## Mistake 4 — Wrong Loop Condition

Exact target search ke standard implementation mein:

```cpp
while (low <= high)
```

use karte hain.

---

# 21. Code Variations

## Variation 1 — Linear Search

```cpp
for (int i = 0; i < n; i++) {
    if (nums[i] == target)
        return i;
}

return -1;
```

---

## Variation 2 — Iterative Binary Search

```cpp
int low = 0;
int high = n - 1;

while (low <= high) {

    int mid = low + (high - low) / 2;

    if (nums[mid] == target)
        return mid;

    else if (nums[mid] < target)
        low = mid + 1;

    else
        high = mid - 1;
}

return -1;
```

**Day 61 mein ye iterative Binary Search preferred solution hai.**

---

# 22. Side-by-Side Dry Run

Array:

```text
[1, 3, 5, 7, 9, 11, 13]
```

Target:

```text
9
```

### Linear Search

```text
1 → No
3 → No
5 → No
7 → No
9 → YES
```

5 elements check hue.

---

### Binary Search

```text
7 → target right
      ↓
11 → target left
      ↓
9 → FOUND
```

Sirf 3 comparisons mein target mil gaya.

---

# 23. Complexity Comparison Example

Suppose:

```text
N = 1,000,000
```

### Linear Search

Worst case:

```text
1,000,000 checks
```

### Binary Search

Approximately:

```text
log₂(1,000,000) ≈ 20
```

Yani roughly 20 search steps.

Isi wajah se sorted data par Binary Search extremely powerful hai.

---

# 24. Final Pattern Recognition Cheat Sheet

```text
                SEARCH
                  ↓
          Array / Data sorted?
             ↙           ↘
           NO             YES
            ↓              ↓
      Linear Search    Binary Search
            ↓              ↓
          O(N)           O(log N)
```

### Golden Rule

> **Sorted Array + Search = Binary Search**

---

# 25. Test Cases

## Test Case 1 — Target Present

**Input:**

```text
6
1 3 5 7 9 11
7
```

**Output:**

```text
3
```

---

## Test Case 2 — Target Not Present

**Input:**

```text
6
1 3 5 7 9 11
8
```

**Output:**

```text
-1
```

---

## Test Case 3 — Target First Element

**Input:**

```text
5
2 4 6 8 10
2
```

**Output:**

```text
0
```

---

## Test Case 4 — Target Last Element

**Input:**

```text
5
2 4 6 8 10
10
```

**Output:**

```text
4
```

---

# Final Learning

Day 61 ka actual goal sirf Binary Search ka code yaad karna nahi hai.

Goal hai question ko dekhkar pattern recognize karna:

```text
Search Problem
      ↓
Sorted Array
      ↓
Sorted property ka advantage
      ↓
Search Space ko half karo
      ↓
Binary Search
      ↓
O(log N)
```

Linear Search bhi correct solution hai, lekin sorted array ki property ko use nahi karta.

Binary Search wahi problem ko **O(N) se O(log N)** tak improve karta hai.

**Most Important Clue:**

> **`Sorted + Search → Binary Search`**
