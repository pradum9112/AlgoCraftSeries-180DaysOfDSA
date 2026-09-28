# Day 82 — Aggressive Cows

## 📌 Problem

Given an array of stall positions and `k` cows, place the cows in the stalls such that the **minimum distance between any two cows is as large as possible**.

The stall positions are not necessarily sorted, so sorting is required first.

### Example

```text
Stalls = [1, 2, 4, 8, 9]
k = 3
```

After sorting:

```text
[1, 2, 4, 8, 9]
```

One optimal placement is:

```text
Cow 1 → 1
Cow 2 → 4
Cow 3 → 8
```

Distances:

```text
4 - 1 = 3
8 - 4 = 4
```

Minimum distance:

```text
3
```

So the answer is:

```text
3
```

---

# 🔹 Approach 1 — Brute Force

## 💡 Idea

We need to **maximize the minimum distance**.

After sorting the stalls, the smallest possible distance is:

```text
1
```

and the largest possible distance is:

```text
last stall - first stall
```

We can check every possible distance one by one.

For each distance `d`, check whether it is possible to place all `k` cows such that every two consecutive placed cows are at least `d` apart.

The first distance that becomes impossible tells us that the previous distance was the answer.

---

## 🔍 Feasibility Check

For a selected distance `d`:

1. Place the first cow at the first stall.
2. Move from left to right.
3. Whenever:

```text
current position - last cow position >= d
```

place another cow.
4. If we can place `k` cows, distance `d` is possible.

This greedy strategy works because placing each next cow at the **earliest possible stall** leaves maximum space for the remaining cows.

---

# 🧠 Pattern Recognition Clue

This is a classic:

> **Maximize the minimum**

problem.

Whenever you see:

* maximize minimum distance
* maximize minimum value
* place objects as far apart as possible
* largest possible minimum separation

ask:

> **Can I guess a minimum distance and check whether it is possible?**

Here:

```text
Candidate answer = minimum distance
```

Then ask:

```text
Can I place k cows with at least this distance?
```

If yes:

```text
distance can be increased
```

If no:

```text
distance must be decreased
```

That gives:

```text
✅ ✅ ✅ ✅ ❌ ❌ ❌
```

This is monotonic.

Therefore:

> **Binary Search on Answer**

---

# 🔄 Dry Run — Brute Force

Input:

```text
nums = [1, 2, 4, 8, 9]
k = 3
```

Sorted:

```text
[1, 2, 4, 8, 9]
```

Maximum possible distance:

```text
9 - 1 = 8
```

### Distance = 1

Place cows:

```text
1 → Cow 1
2 → Cow 2
4 → Cow 3
```

Possible:

```text
1 → ✅
```

### Distance = 2

```text
1 → Cow 1
4 → Cow 2
8 → Cow 3
```

Possible:

```text
2 → ✅
```

### Distance = 3

```text
1 → Cow 1
4 → Cow 2
8 → Cow 3
```

Distances:

```text
3
4
```

Possible:

```text
3 → ✅
```

### Distance = 4

Try:

```text
1 → Cow 1
8 → Cow 2
```

Cannot place a third cow with distance `4`.

Therefore:

```text
4 → ❌
```

So the previous valid distance was:

```text
3
```

### Final Answer

```text
3
```

---

## ⏱️ Time Complexity

Let:

```text
N = number of stalls
D = maximum possible distance
```

Sorting:

```text
O(N log N)
```

We check every possible distance:

```text
O(D)
```

Each feasibility check:

```text
O(N)
```

Therefore:

```text
O(N log N + N × D)
```

Space:

```text
O(1)
```

excluding sorting implementation details.

---

# 🔹 Approach 2 — Optimal: Binary Search on Answer

## 💡 Observation

We don't need to check:

```text
1
2
3
4
5
...
D
```

one by one.

The feasibility pattern is:

```text
Distance

1   → ✅
2   → ✅
3   → ✅
4   → ❌
5   → ❌
...
```

So we can Binary Search on the distance.

---

# 🧠 Pattern Recognition

The most important pattern is:

## Maximize the Minimum

When the problem says:

```text
maximize the minimum distance
```

think:

```text
Binary Search on Answer
```

### Step 1 — Identify the answer

The answer is:

```text
minimum distance between cows
```

### Step 2 — Find answer range

```text
low = 1
high = last stall - first stall
```

### Step 3 — Create feasibility check

Ask:

```text
Can I place k cows with at least mid distance?
```

### Step 4 — Observe monotonicity

```text
small distance → possible
large distance → may become impossible
```

Therefore:

```text
✅ ✅ ✅ ✅ ❌ ❌ ❌
```

### Step 5 — Binary Search

If `mid` is possible:

```text
answer may be larger
low = mid + 1
```

If `mid` is impossible:

```text
answer must be smaller
high = mid - 1
```

---

# 🔄 Dry Run — Binary Search

Input:

```text
nums = [1, 2, 4, 8, 9]
k = 3
```

Sorted:

```text
[1, 2, 4, 8, 9]
```

Initial:

```text
low = 1
high = 8
```

### Step 1

```text
mid = 4
```

Can we place 3 cows with minimum distance `4`?

```text
1 → Cow 1
8 → Cow 2
```

Only 2 cows.

So:

```text
4 → ❌
```

Move left:

```text
high = 3
```

---

### Step 2

```text
low = 1
high = 3

mid = 2
```

Place:

```text
1 → Cow 1
4 → Cow 2
8 → Cow 3
```

Possible.

```text
2 → ✅
```

Store:

```text
ans = 2
```

Try larger:

```text
low = 3
```

---

### Step 3

```text
low = 3
high = 3

mid = 3
```

Place:

```text
1 → Cow 1
4 → Cow 2
8 → Cow 3
```

Possible.

```text
3 → ✅
```

Update:

```text
ans = 3
low = 4
```

Now:

```text
low > high
```

Search ends.

Final:

```text
ans = 3
```

---

# ⏱️ Time Complexity

Sorting:

```text
O(N log N)
```

Binary Search over distance:

```text
O(log D)
```

Each feasibility check:

```text
O(N)
```

Therefore:

```text
O(N log N + N log D)
```

Space:

```text
O(1)
```

excluding sorting implementation details.

---

# ⚖️ Approach Comparison

| Feature           | Brute Force             | Binary Search           |
| ----------------- | ----------------------- | ----------------------- |
| Main Technique    | Linear Search on Answer | Binary Search on Answer |
| Answer            | Minimum distance        | Minimum distance        |
| Search Range      | `1 → D`                 | `1 → D`                 |
| Feasibility Check | Greedy                  | Greedy                  |
| Sorting           | `O(N log N)`            | `O(N log N)`            |
| Search Complexity | `O(D)`                  | `O(log D)`              |
| Total             | `O(N log N + N×D)`      | `O(N log N + N log D)`  |
| Optimal           | ❌                       | ✅                       |

---

# 🔥 Why Sorting Is Necessary

Suppose:

```text
[8, 1, 9, 4, 2]
```

Without sorting, it is difficult to greedily determine the next valid stall.

After sorting:

```text
[1, 2, 4, 8, 9]
```

we can simply move from left to right.

For a chosen distance `d`, we always select the earliest possible stall.

This leaves more room for the remaining cows.

---

# 🔥 Why Greedy Feasibility Works

Suppose:

```text
minimum distance = 3
```

and stalls are:

```text
[1, 2, 4, 8, 9]
```

Start with:

```text
1
```

The earliest stall at least `3` away is:

```text
4
```

Then the earliest stall at least `3` away from `4` is:

```text
8
```

We get:

```text
1 → 4 → 8
```

Choosing an earlier valid stall can never hurt the remaining cows because it leaves **more space to the right**.

Therefore, the greedy check correctly determines whether the distance is feasible.

---

# 🔑 Important Direction

This is where many Binary Search on Answer problems differ.

Here we want to:

```text
MAXIMIZE the minimum distance
```

Therefore:

### If `mid` is possible:

```text
Try larger
low = mid + 1
```

### If `mid` is impossible:

```text
Try smaller
high = mid - 1
```

Mental model:

```text
Possible → move RIGHT
Impossible → move LEFT
```

---

# 🧩 Core Pattern to Remember

```text
Aggressive Cows
       ↓
Maximize minimum distance
       ↓
Sort positions
       ↓
Guess a distance
       ↓
Greedy feasibility check
       ↓
Can k cows be placed?
       ↓
Possible → increase distance
Impossible → decrease distance
       ↓
Binary Search on Answer
```

### Recognition Keywords

Whenever you see:

* aggressive cows
* maximum minimum distance
* largest minimum separation
* place `K` elements as far apart as possible
* maximize the smallest gap

think:

> **Binary Search on Answer + Greedy**

---

# 🚨 Edge Cases

### 1. `k = 2`

The maximum distance is simply:

```text
last stall - first stall
```

because we can place the two cows at the extreme positions.

### 2. Adjacent stalls

Example:

```text
[1, 2, 3]
```

If:

```text
k = 3
```

the answer is:

```text
1
```

### 3. Unsorted input

Always sort first.

### 4. Duplicate positions

If two stalls have the same position, their distance is:

```text
0
```

The greedy check naturally handles this.

---

# 🧠 What I Learned

* This is a **Maximize the Minimum** problem.
* The answer is the minimum distance between any two cows.
* Sorting allows us to greedily place cows from left to right.
* For a fixed distance, we can check feasibility in `O(N)`.
* The feasibility condition is monotonic:
  `possible → possible → impossible`.
* Therefore, Binary Search can be applied to the answer.
* If a distance is possible, search for a **larger** distance.
* If a distance is impossible, search for a **smaller** distance.
* The optimal solution uses:
  **Binary Search on Answer + Greedy Feasibility**.

---

# 🎯 Revision Shortcut

Remember:

```text
MAXIMIZE MINIMUM
       ↓
Sort
       ↓
low = 1
high = maxPosition - minPosition
       ↓
mid = candidate distance
       ↓
Can K cows be placed?
       ↓
YES → increase distance
NO  → decrease distance
       ↓
Binary Search on Answer
```

**Pattern:** `Binary Search on Answer + Greedy`

**Optimal Complexity:** `O(N log N + N log D)` time, `O(1)` extra space.
