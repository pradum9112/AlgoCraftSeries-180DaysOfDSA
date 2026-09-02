# Day 59 — Reverse Pairs

## 📌 Problem Statement

Given an array `nums`, count the number of reverse pairs.

A reverse pair is a pair of indices `(i, j)` such that:

```text
i < j
AND
nums[i] > 2 * nums[j]
```

Return the total number of reverse pairs.

---

## 🧪 Example

### Input

```text
5
1 3 2 3 1
```

### Your Output

```text
2
```

### Explanation

The reverse pairs are:

```text
(3, 1)
(3, 1)
```

For both pairs:

```text
3 > 2 × 1
```

Therefore:

```text
Answer = 2
```

---

# 🔍 Pattern Recognition Clue

This problem ko dekhte hi ye pattern identify karo:

```text
i < j
+
nums[i] > 2 × nums[j]
        ↓
Reverse Pair
```

### Strong clue

Agar question mein:

```text
i < j
```

ke saath koi **special comparison** diya ho, jaise:

```text
nums[i] > 2 * nums[j]
```

aur pairs count karne hain, toh brute force ke baad check karo:

```text
Can Merge Sort count these pairs?
```

Day58 mein:

```text
nums[i] > nums[j]
```

tha → **Inversion**

Day59 mein:

```text
nums[i] > 2 * nums[j]
```

hai → **Reverse Pair**

Dono ka core pattern:

```text
Pair Counting
     ↓
i < j
     ↓
Left value > some condition on Right value
     ↓
Merge Sort optimization
```

---

# Approach 1 — Brute Force

## 💡 Idea

Har possible pair `(i, j)` check karo.

Condition:

```text
i < j
```

and:

```text
nums[i] > 2 * nums[j]
```

Agar condition true hai:

```text
count++
```

### Example

```text
[1, 3, 2, 3, 1]
```

Check:

```text
3 > 2 × 1
```

True.

Do baar aisa pair milta hai.

Therefore:

```text
Answer = 2
```

### Complexity

```text
Time  = O(N²)
Space = O(1)
```

---

# Approach 2 — Merge Sort

Brute force mein problem ye hai ki hum har pair individually check kar rahe hain.

Merge Sort mein array ko:

```text
Left Half
Right Half
```

mein divide karte hain.

Dono halves ko sorted rakhkar hum efficiently cross reverse pairs count kar sakte hain.

---

# 🧠 Important Difference From Normal Inversion

Day58 mein condition thi:

```text
nums[i] > nums[j]
```

Day59 mein condition hai:

```text
nums[i] > 2 * nums[j]
```

Isliye normal merge comparison:

```text
nums[left] > nums[right]
```

se reverse pair count nahi hoga.

Humein **merge se pehle specially countPairs()** chalana hai.

---

# 🔥 `countPairs()` ka Main Logic

Suppose:

```text
Left  = [3, 4, 5]
Right = [1, 2]
```

Ab `3` ke liye:

```text
3 > 2 × 1
```

True.

So `1` ke saath pair hai.

Then:

```text
3 > 2 × 2
```

False.

So:

```text
3 → 1 reverse pair
```

Ab next left element `4`:

```text
4 > 2 × 1
4 > 2 × 2
```

Dono true.

So `4` ke 2 reverse pairs hain.

---

# 🚀 Why Pointer Doesn't Reset?

Code:

```cpp
int right = mid + 1;

for (int i = low; i <= mid; i++) {

    while (right <= high &&
           (long long)nums[i] > 2LL * nums[right]) {
        right++;
    }

    count += right - (mid + 1);
}
```

Important:

```text
right
```

ko har `i` ke liye wapas `mid + 1` nahi karte.

Reason:

Left half sorted hai.

Agar current left element ke liye kuch right elements condition satisfy nahi kar rahe, toh next left element bada hoga, isliye pointer sirf aage move kar sakta hai.

---

# 🔄 Dry Run

Consider:

```text
Left  = [3, 4]
Right = [1, 2]
```

### i = 3

Check:

```text
3 > 2 × 1
3 > 2
```

True.

`right` moves forward.

Now:

```text
3 > 2 × 2
3 > 4
```

False.

Therefore:

```text
count = 1
```

---

### i = 4

`right` already points to `2`.

Check:

```text
4 > 2 × 2
4 > 4
```

False.

So no new pair.

Total:

```text
count = 1
```

---

# ⚠️ Why `2LL`?

Code:

```cpp
(long long)nums[i] > 2LL * nums[right]
```

`nums[i]` is an `int`.

Multiplication:

```text
2 × nums[right]
```

integer overflow kar sakti hai.

Isliye:

```cpp
2LL
```

use karte hain.

`LL` means the calculation is performed using `long long`.

---

# 🧩 Merge Sort Flow

```text
Array
  ↓
Divide
  ↓
Left Half + Right Half
  ↓
Sort Left
  ↓
Sort Right
  ↓
Count Cross Reverse Pairs
  ↓
Merge
```

The important order is:

```text
COUNT
  ↓
MERGE
```

Not:

```text
MERGE
  ↓
COUNT
```

Because `countPairs()` ko dono halves sorted chahiye.

---

# 📊 Complexity

### Brute Force

```text
Time  = O(N²)
Space = O(1)
```

### Merge Sort

```text
Time  = O(N log N)
Space = O(N)
```

---

# 🎯 What You Learned

Day58:

```text
Inversion
→ nums[i] > nums[j]
→ Merge Sort
```

Day59:

```text
Reverse Pair
→ nums[i] > 2 × nums[j]
→ Merge Sort
→ Special countPairs()
```

The bigger pattern:

```text
Pair Counting
      ↓
i < j
      ↓
Special relation between nums[i] and nums[j]
      ↓
Brute Force O(N²)
      ↓
If N is large
      ↓
Think Merge Sort
```

---

# 🧠 One-Line Memory Trick

```text
Inversion:
left > right

Reverse Pair:
left > 2 × right
```

And:

```text
Large N + Pair Counting + Left/Right relationship
→ Think Merge Sort
```
