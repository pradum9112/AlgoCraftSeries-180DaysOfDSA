# Day 87 — Minimize Maximum Distance Between Gas Stations

## 📌 Problem

Given a sorted array `arr` representing the positions of existing gas stations and an integer `k`, place `k` new gas stations such that the **maximum distance between any two consecutive gas stations is minimized**.

Return the minimum possible value of this maximum distance.

### Example

**Input**

```text
arr = [1, 2, 3, 4, 5]
k = 4
```

**Output**

```text
0.5
```

The new stations can be placed between the existing stations so that the largest distance becomes `0.5`.

---

# 🔹 Approach 1 — Greedy / Brute Force

## 💡 Idea

We have `k` new stations to place.

At every step:

1. Look at every existing gap.
2. Calculate the current maximum section length of each gap.
3. Place the next station inside the gap having the **largest current section**.
4. Repeat this process `k` times.

We maintain an array:

```text
howMany[i]
```

which stores how many new stations have been placed inside the gap between:

```text
arr[i] and arr[i+1]
```

If the original gap is:

```text
arr[i+1] - arr[i]
```

and `howMany[i]` stations have been inserted, the current section length becomes:

```text
gap / (howMany[i] + 1)
```

The greedy choice is:

> Always place the next station in the gap currently having the largest section.

---

## 🔍 Pattern Recognition

When you see:

* A fixed number `k` of operations/stations/items to distribute.
* Each operation improves the current worst/biggest value.
* We need to minimize the **maximum** value.
* At every step, choosing the current maximum gap gives the best immediate improvement.

Think:

> **Greedy — repeatedly improve the current worst gap.**

The key observation is:

```text
Minimize the maximum gap
        ↓
Look for the current maximum gap
        ↓
Place the next station there
```

---

## 🔄 Dry Run

Consider:

```text
arr = [1, 2, 3, 4, 5]
k = 4
```

Initial gaps:

```text
1 | 1 | 1 | 1
```

### Station 1

All gaps are equal:

```text
1 | 1 | 1 | 1
```

Place station in one gap.

That gap becomes:

```text
1 / 2 = 0.5
```

Now:

```text
0.5 | 1 | 1 | 1
```

### Station 2

Largest gap = `1`.

Place station there:

```text
0.5 | 0.5 | 1 | 1
```

### Station 3

Again choose a gap of `1`:

```text
0.5 | 0.5 | 0.5 | 1
```

### Station 4

Place the final station in the remaining largest gap:

```text
0.5 | 0.5 | 0.5 | 0.5
```

Therefore:

```text
Maximum gap = 0.5
```

---

## ⏱️ Time Complexity

For every one of the `k` stations, we scan all `n-1` gaps.

```text
O(k × n)
```

So:

**Time:** `O(k × n)`

**Space:** `O(n)`

---

# 🔹 Approach 2 — Binary Search on Answer

## 💡 Idea

Instead of actually placing stations one by one, we ask:

> Can we make the maximum gap at most `dist` using at most `k` new stations?

This converts the problem into a **decision problem**.

For every existing gap:

```text
gap = arr[i] - arr[i-1]
```

we calculate how many stations are required so that every resulting section has length at most `dist`.

The number of required stations depends on `dist`.

If:

```text
requiredStations > k
```

then `dist` is too small.

We need a larger allowed distance:

```text
low = mid
```

If:

```text
requiredStations <= k
```

then `dist` is possible.

We try to reduce it further:

```text
high = mid
```

Because the answer can be decimal, binary search continues until the required precision is reached.

---

## 🔍 Pattern Recognition

This is the most important learning from the problem.

Whenever you see:

> **Minimize the maximum possible value**

ask:

```text
Can I guess the answer?
        ↓
Can I check whether the guessed answer is possible?
        ↓
Does feasibility change monotonically?
        ↓
Binary Search on Answer
```

Here, suppose we guess:

```text
maximum allowed gap = X
```

We can calculate how many stations are needed.

The pattern looks like:

```text
X too small   → Need too many stations ❌
X slightly larger → Possible
X even larger → Possible
```

So feasibility is monotonic.

Therefore:

```text
Binary Search on Answer
```

is applicable.

---

## 🧠 Why Binary Search Works

Suppose `X` is a possible maximum gap.

Then any value greater than `X` is also possible because allowing a larger gap can never require **more** stations.

So the answer follows this structure:

```text
Impossible  Impossible  Impossible  Possible  Possible  Possible
                                      ↑
                                   Answer
```

We need to find the **smallest possible value**.

That's exactly a Binary Search on Answer problem.

---

## 🔄 Dry Run

Consider:

```text
arr = [1, 2, 3, 4, 5]
k = 4
```

The largest original gap is:

```text
1
```

So the search range is:

```text
low = 0
high = 1
```

Suppose we test:

```text
mid = 0.5
```

Each gap is:

```text
1
```

To make every section at most `0.5`, each gap needs:

```text
1 new station
```

There are four gaps:

```text
4 stations required
```

And:

```text
k = 4
```

Therefore:

```text
requiredStations <= k
```

So `0.5` is possible.

We try an even smaller value.

Eventually binary search converges around:

```text
0.5
```

Therefore:

```text
Answer = 0.5
```

---

# ⚠️ Important Precision Point

This problem has a **decimal answer**.

Therefore, normal integer binary search cannot be used directly.

Instead, we continue searching until:

```text
high - low <= 1e-6
```

This gives sufficient precision.

The final answer is approximately:

```text
high
```

---

# ⚖️ Approach Comparison

| Feature                | Greedy                            | Binary Search on Answer       |
| ---------------------- | --------------------------------- | ----------------------------- |
| Technique              | Greedy placement                  | Binary Search                 |
| Main idea              | Place each station in largest gap | Guess maximum gap             |
| Decision function      | Not required                      | Required                      |
| Handles decimal answer | Yes                               | Yes                           |
| Time                   | `O(k × n)`                        | `O(n × log(range/precision))` |
| Space                  | `O(n)`                            | `O(1)`                        |
| Efficiency             | Better than naive direct search   | Much better for large `k`     |
| Optimal                | ❌                                 | ✅                             |

---

# 🧩 Core Pattern to Remember

The important pattern is not gas stations.

It's:

> **Binary Search on Answer with a feasibility check**

Mental model:

```text
Need to minimize maximum value
            ↓
Guess an answer
            ↓
Check whether guess is possible
            ↓
Too small?
    ↓
Move right

Possible?
    ↓
Try smaller
    ↓
Move left
```

---

# 🎯 Pattern Recognition Shortcut

Whenever you see:

```text
minimum possible maximum
maximum possible minimum
smallest value satisfying a condition
largest value satisfying a condition
```

ask:

```text
Can I define a check(mid)?
```

If yes, then ask:

```text
Is check(mid) monotonic?
```

If yes:

```text
Binary Search on Answer
```

---

# 🚨 Edge Cases

### 1. Only one gap

```text
arr = [1, 10]
```

All new stations have to be placed inside this single gap.

---

### 2. `k = 0`

No new station is added.

Answer is simply the largest existing gap.

---

### 3. Multiple equal gaps

The greedy approach can choose any one of the equal maximum gaps.

---

### 4. Large gaps

Use `long double`/`double` carefully because the answer can be fractional.

---

### 5. Very high precision requirement

Binary search should continue until:

```text
high - low <= 1e-6
```

or the precision specified by the problem.

---

# 🧠 What I Learned

* The problem asks us to **minimize the maximum distance**.
* Greedy can place every new station into the current largest gap.
* The optimized approach does not actually place stations one by one.
* Instead, we **guess the maximum allowed distance**.
* A feasibility function calculates how many stations are required.
* The feasibility condition is monotonic.
* Therefore, **Binary Search on Answer** can be applied.
* Because the answer can be decimal, floating-point binary search is required.
* Precision such as `1e-6` is commonly used.
* The key question for this type of problem is:

```text
Can I check whether a guessed answer is feasible?
```

If yes and the condition is monotonic:

```text
Binary Search on Answer
```

---

# 🎯 Revision Shortcut

```text
Minimize Maximum Gap
        ↓
Guess maximum allowed gap
        ↓
Calculate stations required
        ↓
Required > k
        → Gap too small
        → low = mid

Required <= k
        → Gap possible
        → high = mid
        ↓
Continue until required precision
        ↓
Final minimum maximum gap
```

**Pattern:** `Binary Search on Answer`

**Brute Force:** `O(k × n)`

**Optimal:** `O(n × log(range / precision))`

**Space:** `O(1)` for the binary-search approach.

---

# ✅ Final Takeaway

The real DSA pattern is:

```text
Optimization Problem
        ↓
Convert optimization into feasibility
        ↓
Check(mid)
        ↓
Monotonic condition
        ↓
Binary Search on Answer
```

This same pattern appears in:

* Koko Eating Bananas
* Minimum Days to Make Bouquets
* Smallest Divisor
* Ship Packages Within D Days
* Allocate Books
* Painter's Partition
* Aggressive Cows
* Minimize Maximum Distance
