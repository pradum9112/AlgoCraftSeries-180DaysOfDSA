# Day 79 — Capacity To Ship Packages Within D Days

## 📌 Problem

Given an array `weights`, where each element represents the weight of a package, find the **minimum ship capacity** required to ship all packages within exactly/at most `days` days.

Important condition:

* Packages must be shipped **in the given order**.
* A day's total package weight cannot exceed the ship capacity.
* We need the **minimum possible capacity**.

---

# 🔹 Approach 1 — Brute Force

## 💡 Idea

First identify the possible capacity range.

The minimum possible capacity is:

```text
maximum single package weight
```

because a package cannot be split.

The maximum possible capacity is:

```text
sum of all package weights
```

because with this capacity, everything can be shipped in one day.

So we try every capacity:

```text
max(weights) → sum(weights)
```

For every capacity, calculate how many days are required.

The first capacity that can ship everything within the given number of days is the answer.

---

## 🔍 Pattern Recognition Clue

Ask yourself:

> **"Am I searching for an actual array element, or am I searching for an answer value?"**

Here, we are searching for:

```text
minimum capacity
```

Then ask:

> **"Can I check whether a particular capacity works?"**

Yes.

For any capacity, we can calculate the number of days required.

So we have:

```text
candidate capacity
        ↓
Can I ship within D days?
        ↓
Yes / No
```

This is a strong signal for:

> **Binary Search on Answer**

The brute-force approach simply tries every possible answer.

---

## 🔄 Dry Run

Consider:

```text
weights = [1, 2, 3, 1, 1]
days = 4
```

Capacity range:

```text
max(weights) = 3
sum(weights) = 8
```

So possible capacities are:

```text
3, 4, 5, 6, 7, 8
```

### Capacity = 3

Packages are loaded in order:

```text
Day 1 → 1 + 2 = 3
Day 2 → 3
Day 3 → 1 + 1 = 2
```

Required days:

```text
3
```

Since:

```text
3 <= 4
```

capacity `3` is already valid.

Therefore:

```text
Answer = 3
```

---

## ⏱️ Time Complexity

Let:

```text
N = number of packages
D = sum(weights) - max(weights)
```

For every possible capacity, we scan the complete array.

Therefore:

```text
Time = O(N × D)
```

More explicitly:

```text
O(N × (sum(weights) - max(weights) + 1))
```

## 💾 Space Complexity

```text
O(1)
```

---

# 🔹 Approach 2 — Optimal — Binary Search on Answer

## 💡 Idea

We don't need to check every possible capacity.

The answer lies between:

```text
low  = max(weights)
high = sum(weights)
```

Choose:

```text
mid = low + (high - low) / 2
```

Then calculate how many days are required with capacity `mid`.

### If required days <= given days

The capacity works.

But we want the **minimum** valid capacity.

So search left:

```text
high = mid - 1
```

### If required days > given days

The capacity is too small.

We need more capacity:

```text
low = mid + 1
```

---

# 🧠 Pattern Recognition

This is another classic:

> **Binary Search on Answer**

Look for these three signals:

### 1. We need a minimum/maximum value

Here:

```text
Minimum ship capacity
```

### 2. We can verify a candidate

For a capacity `C`:

```text
How many days are required?
```

### 3. The condition is monotonic

If a capacity works, every larger capacity will also work.

Example:

```text
Capacity
3   → Possible
4   → Possible
5   → Possible
6   → Possible
7   → Possible
8   → Possible
```

If a smaller capacity fails:

```text
Capacity
1   → Impossible
2   → Impossible
3   → Possible
4   → Possible
5   → Possible
```

The pattern becomes:

```text
FALSE FALSE FALSE TRUE TRUE TRUE TRUE
                      ↑
                first valid answer
```

That's exactly what Binary Search is good at.

---

# 🔄 Dry Run — Binary Search

Example:

```text
weights = [1, 2, 3, 1, 1]
days = 4
```

Initial:

```text
low = 3
high = 8
```

### Step 1

```text
mid = 5
```

With capacity `5`:

```text
Day 1 → 1 + 2 = 3
Day 2 → 3 + 1 + 1 = 5
```

Required:

```text
2 days
```

Since:

```text
2 <= 4
```

capacity `5` works.

Save:

```text
ans = 5
```

Search smaller:

```text
high = 4
```

---

### Step 2

```text
low = 3
high = 4

mid = 3
```

With capacity `3`:

```text
Day 1 → 1 + 2 = 3
Day 2 → 3
Day 3 → 1 + 1 = 2
```

Required:

```text
3 days
```

Since:

```text
3 <= 4
```

capacity `3` works.

```text
ans = 3
high = 2
```

Now:

```text
low > high
```

Search ends.

Final answer:

```text
3
```

---

# ⏱️ Time Complexity

For one capacity, calculating required days takes:

```text
O(N)
```

Binary Search checks approximately:

```text
O(log(sum(weights) - max(weights)))
```

capacities.

Therefore:

```text
Time = O(N log(sum(weights) - max(weights)))
```

## 💾 Space Complexity

```text
O(1)
```

---

# ⚖️ Approach Comparison

| Feature         | Brute Force     | Binary Search           |
| --------------- | --------------- | ----------------------- |
| Search range    | `max → sum`     | `max → sum`             |
| Candidate check | Required days   | Required days           |
| Search method   | Sequential      | Binary Search           |
| Time            | `O(N × D)`      | `O(N log D)`            |
| Space           | `O(1)`          | `O(1)`                  |
| Pattern         | Direct checking | Binary Search on Answer |
| Optimal         | ❌               | ✅                       |

---

# 🎯 Most Important Pattern

The main lesson isn't shipping packages.

The reusable pattern is:

```text
Minimum/Maximum Answer
        ↓
Define possible answer range
        ↓
Create isPossible() / check() function
        ↓
Check whether condition is monotonic
        ↓
Binary Search on Answer
```

For this problem:

```text
Answer = Ship Capacity
```

```text
low = max(weights)
high = sum(weights)
```

```text
check(capacity)
        ↓
calculate required days
```

```text
requiredDays <= givenDays
        ↓
capacity is possible
```

Then:

```text
Possible → search left
Impossible → search right
```

---

# 🧠 What I Learned

* The minimum capacity cannot be smaller than the heaviest package.
* The maximum capacity can be the sum of all packages.
* Packages must remain in their original order.
* A candidate capacity can be verified by greedily filling each day until the next package doesn't fit.
* If capacity `C` works, every capacity greater than `C` also works.
* Therefore the feasibility condition is monotonic.
* This makes the problem a classic **Binary Search on Answer** problem.
* The optimal solution improves the search from checking every capacity to logarithmic search.

### Core Recognition

```text
Searching for minimum capacity
            ↓
Can check a capacity?
            ↓
Is the result monotonic?
            ↓
Binary Search on Answer
```

### Complexity

```text
Brute Force:
O(N × (sum - max))

Optimal:
O(N × log(sum - max))

Space:
O(1)
```
