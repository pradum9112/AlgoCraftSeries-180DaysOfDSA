# Day 52 — 4Sum

## 📌 Problem Statement

Given an integer array `nums` and an integer `target`, find all unique quadruplets:

```text
nums[a] + nums[b] + nums[c] + nums[d] = target
```

Return all unique quadruplets.

Each index must be different.

---

## 🧪 Example

### Input

```text
6 0
1 0 -1 0 -2 2
```

### Array

```text
[1, 0, -1, 0, -2, 2]
```

### Target

```text
0
```

### Your Output

```text
-2 -1 1 2
-2 0 0 2
-1 0 0 1
```

---

# Approach 1 — Brute Force

## 💡 Idea

Four different elements choose karne ke liye **4 nested loops** use karenge.

```text
i → first element
j → second element
k → third element
l → fourth element
```

Har combination ke liye check:

```text
nums[i] + nums[j] + nums[k] + nums[l] == target
```

Agar sum target ke equal hai, quadruplet mil gaya.

Duplicate quadruplets ko remove karne ke liye `set<vector<int>>` use karenge.

### Duplicate handle karna

Quadruplet ko set me insert karne se pehle sort karenge.

Example:

```text
[2, 0, -2, 0]
```

becomes:

```text
[-2, 0, 0, 2]
```

Isse same quadruplet different order me duplicate nahi hoga.

## ⏱ Complexity

```text
Time  = O(n⁴)
Space = O(number of unique answers)
```

---

# Approach 2 — Better: HashSet

## 💡 Idea

4 loops ki jagah **3 elements fix** karenge.

Equation:

```text
a + b + c + d = target
```

Toh fourth element:

```text
d = target - (a + b + c)
```

Hum `i`, `j` aur `k` fix karenge aur check karenge ki required `fourth` element HashSet me already present hai ya nahi.

### Pattern

```text
Fix i
   ↓
Fix j
   ↓
Take k
   ↓
Calculate fourth
   ↓
Search fourth in HashSet
```

Example:

```text
target = 0

a = -2
b = -1
c = 1
```

Then:

```text
d = 0 - (-2 + -1 + 1)
  = 2
```

Agar `2` HashSet me hai:

```text
-2 + -1 + 1 + 2 = 0
```

Quadruplet mil gaya.

## ⏱ Complexity

Using `unordered_set`:

```text
Average Time = O(n³)
Space         = O(n)
```

Using `set`:

```text
Time ≈ O(n³ log n)
```

---

# Approach 3 — Optimal: Sorting + Two Pointer

## 💡 Main Idea

Pehle array ko sort karenge.

Phir **2 elements fix** karenge:

```text
nums[i]
nums[j]
```

Remaining two elements ko `left` aur `right` pointers se find karenge.

### Visualization

```text
[i] [j] [left ........ right]
```

Equation:

```text
nums[i] + nums[j] + nums[left] + nums[right] = target
```

---

## Step 1 — Sort

Example:

```text
[1, 0, -1, 0, -2, 2]
```

After sorting:

```text
[-2, -1, 0, 0, 1, 2]
```

Sorting important hai kyunki ab:

```text
left++
```

karne se sum increase hoga.

Aur:

```text
right--
```

karne se sum decrease hoga.

---

# Step 2 — First Element Fix

```text
i = 0

[-2, -1, 0, 0, 1, 2]
 ↑
 i
```

So:

```text
nums[i] = -2
```

---

# Step 3 — Second Element Fix

```text
j = 1

[-2, -1, 0, 0, 1, 2]
 ↑   ↑
 i   j
```

So:

```text
nums[i] = -2
nums[j] = -1
```

Now:

```text
left = j + 1
right = n - 1
```

Therefore:

```text
[-2, -1, 0, 0, 1, 2]
       ↑        ↑
      left     right
```

---

# Step 4 — Calculate Sum

```text
sum = nums[i] + nums[j] + nums[left] + nums[right]
```

Initially:

```text
-2 + (-1) + 0 + 2
= -1
```

Target:

```text
0
```

Since:

```text
-1 < 0
```

sum chhota hai.

Therefore:

```text
left++
```

---

# Why left++?

Array sorted hai.

Current:

```text
left = 0
```

Agar left ko right ki taraf move karenge, next value badi ya equal hogi.

Therefore sum increase hone ki possibility hai.

```text
sum < target
       ↓
   left++
```

---

# Why right--?

Agar:

```text
sum > target
```

hai, toh sum ko chhota karna hai.

Sorted array me right ko left ki taraf move karne se value chhoti hogi.

```text
sum > target
       ↓
   right--
```

---

# When sum == target?

Agar:

```text
sum == target
```

toh quadruplet mil gaya.

Example:

```text
-2 + (-1) + 1 + 2 = 0
```

So:

```text
[-2, -1, 1, 2]
```

answer me add hoga.

Then:

```text
left++
right--
```

---

# 🔄 Complete Dry Run

Input:

```text
nums = [1, 0, -1, 0, -2, 2]
target = 0
```

Sorted:

```text
[-2, -1, 0, 0, 1, 2]
```

### Combination 1

```text
i = -2
j = -1
left = 0
right = 2
```

```text
-2 + -1 + 0 + 2 = -1
```

Since:

```text
-1 < 0
```

Move:

```text
left++
```

---

### Combination 2

Now eventually:

```text
-2 + -1 + 1 + 2 = 0
```

✅ Found:

```text
-2 -1 1 2
```

---

### Another Combination

Fix:

```text
i = -2
j = 0
```

Then:

```text
-2 + 0 + 0 + 2 = 0
```

✅ Found:

```text
-2 0 0 2
```

---

### Another Combination

Fix:

```text
i = -1
j = 0
```

Then:

```text
-1 + 0 + 0 + 1 = 0
```

✅ Found:

```text
-1 0 0 1
```

---

## ✅ Final Output

```text
-2 -1 1 2
-2 0 0 2
-1 0 0 1
```

---

# 🔁 Duplicate Handling

Sorting ke baad duplicate values adjacent aa jaati hain.

For `i`:

```cpp
if (i > 0 && nums[i] == nums[i - 1])
    continue;
```

Example:

```text
[-2, -2, -1, 0, 1, 2]
```

Agar first `-2` already process ho chuka hai, second `-2` se same results dobara mil sakte hain.

Isliye duplicate `i` skip karte hain.

---

## Duplicate `j`

```cpp
if (j > i + 1 && nums[j] == nums[j - 1])
    continue;
```

Same reason — duplicate quadruplets avoid karne ke liye.

---

## Duplicate left and right

Quadruplet milne ke baad:

```cpp
left++;
right--;
```

Aur same values ko skip karte hain:

```cpp
while (left < right && nums[left] == nums[left - 1])
    left++;
```

```cpp
while (left < right && nums[right] == nums[right + 1])
    right--;
```

---

# ⚠️ Why `long long`?

Four integers ko add karne par `int` range exceed ho sakti hai.

Isliye:

```cpp
long long sum =
    (long long)nums[i]
    + nums[j]
    + nums[left]
    + nums[right];
```

use karna safer hai.

---

# 📊 Comparison of All Three Approaches

| Approach    | Time Complexity | Space Complexity | Technique             |
| ----------- | --------------: | ---------------: | --------------------- |
| Brute Force |           O(n⁴) |        O(answer) | 4 loops               |
| Better      |   O(n³) average |             O(n) | HashSet               |
| Optimal     |           O(n³) |       O(1) extra | Sorting + Two Pointer |

---

# 🧠 Day51 → Day52 Connection

Day51 me tumne **3Sum** kiya:

```text
Fix 1 element
      ↓
Two Pointer
```

```text
[i] [left ........ right]
```

Day52 me wahi idea ek level extend hua:

```text
Fix 2 elements
      ↓
Two Pointer
```

```text
[i] [j] [left ........ right]
```

So:

```text
3Sum → O(n²)

4Sum → O(n³)
```

---

# ⭐ Most Important Learning

4Sum ko ek completely new algorithm ki tarah mat yaad karo.

Isko aise visualize karo:

```text
4Sum
  ↓
Fix i
  ↓
Fix j
  ↓
Remaining problem = 2Sum
  ↓
Two Pointer
```

### Final Pattern

```text
3Sum:

[i] [left ........ right]


4Sum:

[i] [j] [left ........ right]
```

Ye Day52 ka main pattern hai.

---

# 📌 What I Learned

* 4Sum problem ko Brute Force se solve karna.
* 4 loops ko reduce karke HashSet approach banana.
* `a + b + c + d = target` se fourth element calculate karna.
* Sorting ke baad Two Pointer ka use karna.
* `sum < target` → `left++`
* `sum > target` → `right--`
* `sum == target` → answer found.
* Duplicate quadruplets ko skip karna.
* Integer overflow se bachne ke liye `long long` use karna.
* 3Sum aur 4Sum ke pattern ko connect karna.
