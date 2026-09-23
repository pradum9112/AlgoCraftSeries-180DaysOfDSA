# Day 77 — Minimum Rate to Eat Bananas

## 📌 Problem

Given an array `nums` where `nums[i]` represents the number of bananas in the `i-th` pile, and an integer `h` representing the total available hours, find the **minimum eating speed** such that all bananas can be eaten within `h` hours.

For a chosen speed `k`, the hours required for a pile of `x` bananas are:

`ceil(x / k)`

The goal is to find the smallest `k` for which:

`totalHours <= h`

---

# 🔹 Approach 1 — Brute Force

## 💡 Idea

Try every possible eating speed starting from `1`.

The maximum useful speed is the largest pile:

`max(nums)`

For every speed:

1. Calculate the total hours required.
2. If total hours are less than or equal to `h`, return that speed.
3. The first valid speed is the minimum answer.

## 🔍 Pattern Recognition Clue

Whenever the problem asks:

* minimum possible value
* maximum possible value
* find the smallest/largest rate
* a candidate answer can be checked
* the validity of the candidate changes monotonically

ask:

> **"Can I search over the answer?"**

Here the possible speed is:

`1 ... max(nums)`

For each speed we can check whether Koko can finish within `h` hours.

This immediately suggests:

> **Binary Search on Answer**

The brute-force approach simply checks every possible answer one by one.

---

## 🔄 Dry Run

Input:

`nums = [3, 6, 7, 11]`

`h = 8`

Try speed `1`:

* 3 → 3 hours
* 6 → 6 hours
* 7 → 7 hours
* 11 → 11 hours

Total:

`27`

Not possible.

Try speed `2`:

* 3 → 2 hours
* 6 → 3 hours
* 7 → 4 hours
* 11 → 6 hours

Total:

`15`

Not possible.

Try speed `3`:

* 3 → 1 hour
* 6 → 2 hours
* 7 → 3 hours
* 11 → 4 hours

Total:

`10`

Not possible.

Continue checking speeds.

At speed `4`:

* 3 → 1
* 6 → 2
* 7 → 2
* 11 → 3

Total:

`8`

Valid.

Therefore:

`answer = 4`

---

## ⏱ Complexity

Let:

`M = max(nums)`

For every speed we scan the entire array.

* **Time:** `O(n × M)`
* **Space:** `O(1)`

---

# 🔹 Approach 2 — Binary Search on Answer

## 💡 Observation

We don't need to try every speed.

The possible answer lies between:

`1 ... max(nums)`

For a particular speed `k`, calculate the total required hours.

If:

`totalHours <= h`

then `k` is a valid speed.

But we need the **minimum** valid speed, so we try smaller speeds.

If:

`totalHours > h`

then `k` is too slow.

We need a larger speed.

Therefore:

* Valid → move **left**
* Invalid → move **right**

---

# 🧠 Pattern Recognition

This problem is a classic:

> **Binary Search on Answer**

Look for these three things:

### 1. There is a range of possible answers

Here:

`1 ... max(nums)`

### 2. We can validate a candidate

For speed `k`:

`totalHours = sum(ceil(nums[i] / k))`

Then check:

`totalHours <= h`

### 3. The condition is monotonic

As eating speed increases, required hours never increase.

Example:

`speed`

`1 → 2 → 3 → 4 → 5 → 6 ...`

Required hours:

`27 → 15 → 10 → 8 → 7 → 6 ...`

The condition looks like:

`INVALID INVALID INVALID VALID VALID VALID ...`

This is exactly the type of pattern where Binary Search can work.

---

## 🔑 Recognition Shortcut

Whenever you see:

> **"Find the minimum rate/capacity/speed such that a condition becomes possible."**

Think:

```text
Answer Range
     ↓
Can I check one candidate?
     ↓
Does validity change monotonically?
     ↓
Binary Search on Answer
```

Common examples:

* Koko Eating Bananas
* Smallest Divisor
* Capacity to Ship Packages
* Minimum Days to Make Bouquets
* Aggressive Cows
* Allocate Books

---

# 🔄 Dry Run — Binary Search

Input:

`nums = [3, 6, 7, 11]`

`h = 8`

Initial:

`low = 1`

`high = 11`

### Step 1

`mid = 6`

Required hours:

* 3 → 1
* 6 → 1
* 7 → 2
* 11 → 2

Total:

`6`

Since:

`6 <= 8`

Speed `6` is valid.

We need a smaller speed:

`high = 5`

---

### Step 2

`low = 1`

`high = 5`

`mid = 3`

Required hours:

* 3 → 1
* 6 → 2
* 7 → 3
* 11 → 4

Total:

`10`

Since:

`10 > 8`

Speed `3` is too slow.

Move right:

`low = 4`

---

### Step 3

`low = 4`

`high = 5`

`mid = 4`

Required hours:

* 3 → 1
* 6 → 2
* 7 → 2
* 11 → 3

Total:

`8`

Valid.

Store:

`ans = 4`

Try smaller:

`high = 3`

---

Now:

`low = 4`

`high = 3`

Loop ends.

Final answer:

`4`

---

# ⚖️ Approach Comparison

| Feature            | Brute Force        | Binary Search           |
| ------------------ | ------------------ | ----------------------- |
| Search method      | Check every speed  | Search answer range     |
| Search range       | `1 ... max(nums)`  | `1 ... max(nums)`       |
| Candidate checking | Yes                | Yes                     |
| Time               | `O(n × M)`         | `O(n × log M)`          |
| Space              | `O(1)`             | `O(1)`                  |
| Optimal            | ❌                  | ✅                       |
| Pattern            | Direct enumeration | Binary Search on Answer |

Where:

`M = max(nums)`

The major optimization is:

`O(n × M) → O(n × log M)`

---

# ⚠️ Important Detail — Ceiling Division

For a pile containing `num` bananas and eating speed `speed`:

`ceil(num / speed)`

Instead of using floating-point arithmetic, we can calculate it using:

`(num + speed - 1) / speed`

For example:

`num = 7`

`speed = 3`

Then:

`(7 + 3 - 1) / 3`

`= 9 / 3`

`= 3`

So 7 bananas require 3 hours at speed 3.

---

# 🎯 Core Pattern

The main lesson is not Koko specifically.

The important pattern is:

## Binary Search on Answer

```text
Possible answers
       ↓
    1 ... M
       ↓
Check candidate
       ↓
Is it valid?
   ↙       ↘
 Yes       No
  ↓         ↓
go left   go right
       ↓
Minimum valid answer
```

### Mental Trigger

If a problem asks:

> **"What is the minimum X such that condition becomes possible?"**

immediately ask:

> **"Can I binary-search X?"**

---

# 🧠 What I Learned

* How to calculate the hours required for a given eating speed.
* How ceiling division works without floating-point arithmetic.
* How to identify the answer range.
* How to convert brute-force answer checking into Binary Search.
* The importance of recognizing monotonic conditions.
* **Binary Search on Answer** reduces the search from every possible speed to logarithmically many candidate speeds.
* The optimal complexity is **`O(n log M)`**.

---

# 🎯 Revision Shortcut

Remember:

```text
Minimum Speed
      ↓
Possible speed = 1 ... max(nums)
      ↓
Check total hours
      ↓
Hours <= h ?
   ↙       ↘
 YES       NO
  ↓         ↓
left      right
  ↓         ↓
Binary Search on Answer
```

**Pattern:** Binary Search on Answer

**Optimal:** `O(n log M)` time, `O(1)` extra space.
