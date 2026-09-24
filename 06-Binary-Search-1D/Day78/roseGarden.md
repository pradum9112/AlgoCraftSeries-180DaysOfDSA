# Day 78 — Rose Garden

## 📌 Problem

Given an array `nums`, where `nums[i]` represents the day on which the `i-th` flower blooms, find the **minimum number of days** required to make `m` bouquets.

Each bouquet requires exactly `k` **adjacent flowers** that have already bloomed.

If it is impossible to make `m` bouquets, return `-1`.

### Example

**Input**

```text
nums = [1, 10, 3, 10, 2]
m = 3
k = 1
```

**Output**

```text
3
```

By day `3`, flowers at positions `0`, `2`, and `4` have bloomed, giving 3 bouquets of 1 flower each.

---

# 🔹 Approach 1 — Brute Force

## 💡 Idea

The answer must lie between:

```text
minimum bloom day → maximum bloom day
```

So we check every possible day.

For each day:

1. Check which flowers have bloomed.
2. Count consecutive bloomed flowers.
3. Whenever `k` consecutive flowers are available, form one bouquet.
4. If at least `m` bouquets can be formed, that day is possible.
5. Return the first possible day.

Because we check days from smallest to largest, the first valid day is the answer.

---

## 🔍 Pattern Recognition Clue

Ask:

> **"What exactly are we searching for?"**

We are not directly searching for a flower or an array index.

We are searching for the **minimum day**.

Now ask:

> **"Can I check whether a particular day is possible?"**

Yes.

For any chosen day, we can determine whether `m` bouquets can be formed.

So we have:

```text
Candidate answer
       ↓
Can I check it?
       ↓
isPossible(day)
```

This is a strong signal for:

> **Binary Search on Answer**

For the brute-force version, however, we simply try every candidate day.

---

## 🔄 Dry Run

Consider:

```text
nums = [1, 10, 3, 10, 2]
m = 3
k = 1
```

### Day = 1

Bloomed:

```text
[✓, ✗, ✗, ✗, ✗]
```

Bouquets:

```text
1
```

Need:

```text
3
```

Not possible.

---

### Day = 2

Bloomed:

```text
[✓, ✗, ✗, ✗, ✓]
```

Bouquets:

```text
2
```

Still not possible.

---

### Day = 3

Bloomed:

```text
[✓, ✗, ✓, ✗, ✓]
```

Bouquets:

```text
3
```

Possible.

Therefore:

```text
Answer = 3
```

---

## ⏱️ Time Complexity

Let:

```text
N = number of flowers
D = max(nums) - min(nums)
```

For every possible day, we scan the entire array.

```text
Time = O(N × D)
```

## 💾 Space Complexity

Only a few variables are used:

```text
Space = O(1)
```

---

# 🔹 Approach 2 — Optimal — Binary Search on Answer

## 💡 Idea

Instead of checking every day one by one, we binary-search the answer.

The possible answer lies between:

```text
low = minimum bloom day
high = maximum bloom day
```

For a candidate day `mid`, call:

```text
isPossible(mid)
```

If we can make at least `m` bouquets:

```text
mid is a valid answer
```

But we want the **minimum** valid day.

So:

```text
answer possible
→ save mid
→ search left
```

Therefore:

```text
high = mid - 1
```

If we cannot make enough bouquets:

```text
mid is too early
```

So:

```text
low = mid + 1
```

---

# 🧠 Pattern Recognition

This is the most important part of the problem.

Look for these three things:

### 1. We are finding a minimum/maximum answer

Here:

```text
minimum number of days
```

### 2. We can verify a candidate answer

For a particular day:

```text
Can I make m bouquets?
```

### 3. The answer has monotonic behavior

Suppose making bouquets is possible on day `D`.

Then it will also be possible on:

```text
D + 1
D + 2
D + 3
...
```

Because more flowers can only bloom; already-bloomed flowers don't become unbloomed.

So the search pattern looks like:

```text
FALSE FALSE FALSE FALSE TRUE TRUE TRUE TRUE
                              ↑
                         first TRUE
```

We need the **first TRUE**.

Therefore:

```text
Binary Search on Answer
```

---

# 🔄 Dry Run — Binary Search

Example:

```text
nums = [1, 10, 3, 10, 2]
m = 3
k = 1
```

Search range:

```text
low = 1
high = 10
```

### Step 1

```text
mid = 5
```

By day `5`, flowers:

```text
[✓, ✗, ✓, ✗, ✓]
```

We can make 3 bouquets.

So `5` is possible.

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
low = 1
high = 4

mid = 2
```

By day `2`:

```text
[✓, ✗, ✗, ✗, ✓]
```

Only 2 bouquets.

Not possible.

So:

```text
low = 3
```

---

### Step 3

```text
low = 3
high = 4

mid = 3
```

By day `3`:

```text
[✓, ✗, ✓, ✗, ✓]
```

3 bouquets are possible.

So:

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

For every binary-search step, we scan the entire array.

Checking one day:

```text
O(N)
```

Binary search over the day range:

```text
O(log D)
```

Therefore:

```text
Time = O(N log D)
```

where:

```text
D = max(nums) - min(nums)
```

## 💾 Space Complexity

```text
O(1)
```

---

# ⚖️ Approach Comparison

| Feature           | Brute Force            | Binary Search           |
| ----------------- | ---------------------- | ----------------------- |
| Search method     | Check every day        | Binary Search           |
| Candidate range   | min → max bloom day    | min → max bloom day     |
| Feasibility check | `isPossible()`         | `isPossible()`          |
| Time              | `O(N × D)`             | `O(N log D)`            |
| Space             | `O(1)`                 | `O(1)`                  |
| Optimal           | ❌                      | ✅                       |
| Pattern           | Direct answer checking | Binary Search on Answer |

---

# ⚠️ Important Edge Case

Before searching, check:

```text
m × k > n
```

If this is true, there aren't enough flowers to make the required bouquets.

Example:

```text
n = 5
m = 3
k = 2
```

Required flowers:

```text
3 × 2 = 6
```

But only 5 flowers exist.

Therefore:

```text
Answer = -1
```

Use `long long` for this multiplication to avoid overflow.

---

# 🧠 What I Learned

* The problem asks for the **minimum day**, not an array element.
* Create a feasibility function: **can this day produce `m` bouquets?**
* `k` flowers must be **adjacent**, so consecutive counting is important.
* If a day is possible, every later day is also possible.
* This creates a monotonic:

```text
FALSE → TRUE
```

pattern.

* Therefore, the optimal technique is:

```text
Binary Search on Answer
```

### Core Pattern

```text
Minimum/Maximum Answer
        ↓
Can I check a candidate?
        ↓
isPossible(candidate)
        ↓
Monotonic TRUE/FALSE
        ↓
Binary Search on Answer
```

### Complexity

```text
Brute:   O(N × D)
Optimal: O(N log D)
Space:   O(1)
```
