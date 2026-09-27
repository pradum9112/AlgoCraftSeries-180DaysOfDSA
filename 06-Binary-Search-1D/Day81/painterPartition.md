# Day 81 — Painter's Partition

## 📌 Problem

Given `A` painters and an array `C`, where `C[i]` represents the length of the `i-th` board, assign the boards to painters such that:

* Every board is painted completely.
* Boards must be assigned in **contiguous order**.
* Each painter can paint a continuous group of boards.
* All painters work simultaneously.
* We need to **minimize the maximum amount of board length assigned to any one painter**.

Each unit of board takes `B` units of time to paint.

The final answer is returned modulo:

```text
10000003
```

### Example

```text
A = 2
B = 1
C = [10, 20, 30, 40]
```

Possible partition:

```text
Painter 1 → [10, 20, 30] = 60
Painter 2 → [40]         = 40
```

Maximum workload:

```text
60
```

Another partition:

```text
Painter 1 → [10, 20] = 30
Painter 2 → [30, 40] = 70
```

Maximum workload:

```text
70
```

Therefore, the optimal maximum workload is:

```text
60
```

---

# 🔹 Approach 1 — Brute Force

## 💡 Idea

The answer represents the maximum amount of board length that one painter may receive.

The smallest possible capacity is:

```text
max(C)
```

because a painter must paint an entire board.

The largest possible capacity is:

```text
sum(C)
```

because one painter could paint all boards.

So the answer lies in:

```text
max(C) ... sum(C)
```

We can check every possible capacity.

For each capacity, determine whether all boards can be assigned using at most `A` painters.

The first feasible capacity is the answer.

---

## 🔍 Feasibility Check

For a selected capacity:

```text
capacity = X
```

we process boards from left to right.

Keep adding boards to the current painter.

If adding the next board exceeds `X`, assign that board to the next painter.

The important point is:

> Boards cannot be rearranged.

Therefore, we always process them in their original order.

If the number of painters required becomes greater than `A`, this capacity is not feasible.

---

## 🧠 Pattern Recognition Clue

This problem has a very important pattern.

Ask:

> **"What exactly am I minimizing?"**

We are not directly searching for a board.

We are searching for:

```text
minimum possible maximum workload
```

Then ask:

> **"Can I check whether a particular workload is possible?"**

Yes.

For any capacity `X`, we can check:

```text
Can A painters finish all boards if each painter can paint at most X?
```

This gives a **decision problem**.

The answer space looks like:

```text
Capacity

Too small  Too small  Too small  Feasible  Feasible  Feasible
   ❌          ❌          ❌          ✅         ✅         ✅
```

This is monotonic.

Therefore, we should think:

> **Binary Search on Answer**

---

## 🔄 Dry Run — Brute Force

Consider:

```text
A = 2
C = [10, 20, 30, 40]
```

Search range:

```text
low = 40
high = 100
```

Try:

```text
capacity = 40
```

Painter 1:

```text
10 + 20 = 30
```

Cannot add `30`:

```text
30 + 30 = 60 > 40
```

Painter 2:

```text
30
```

Cannot add `40`:

```text
30 + 40 > 40
```

Requires 3 painters.

Therefore:

```text
40 → ❌
```

Try:

```text
capacity = 50
```

Painter 1:

```text
10 + 20 = 30
```

Painter 2:

```text
30
```

Cannot add `40`.

So:

```text
Painter 1 → 10 + 20 = 30
Painter 2 → 30
```

`40` still needs another painter.

Therefore:

```text
50 → ❌
```

Try:

```text
capacity = 60
```

Painter 1:

```text
10 + 20 + 30 = 60
```

Painter 2:

```text
40
```

Only 2 painters required.

Therefore:

```text
60 → ✅
```

So the answer is:

```text
60
```

---

## ⏱️ Time Complexity

Let:

```text
N = number of boards
S = sum of all board lengths
```

There can be approximately `S` possible capacities.

Each feasibility check takes:

```text
O(N)
```

Therefore:

```text
Time: O(N × S)
```

Space:

```text
O(1)
```

---

# 🔹 Approach 2 — Binary Search on Answer

## 💡 Observation

We don't need to check every capacity.

The answer lies between:

```text
max(C)
```

and

```text
sum(C)
```

For every candidate capacity, the feasibility condition is monotonic.

If a capacity is feasible:

```text
X → ✅
```

then every larger capacity will also be feasible:

```text
X + 1 → ✅
X + 2 → ✅
X + 3 → ✅
```

If a capacity is not feasible:

```text
X → ❌
```

then every smaller capacity is also impossible.

So we have:

```text
❌ ❌ ❌ ❌ ❌ ✅ ✅ ✅ ✅
```

This is exactly the structure required for Binary Search.

---

# 🧠 Pattern Recognition

The most important learning from Day 81 is:

## Binary Search on Answer

Whenever you see:

```text
Minimize the maximum...
```

or:

```text
Maximize the minimum...
```

ask yourself:

### Step 1

What is the possible answer range?

Here:

```text
low = maximum board length
high = total board length
```

### Step 2

Can I check one candidate answer?

Here:

```text
isPossible(capacity)
```

checks whether `A` painters can handle all boards.

### Step 3

Is the condition monotonic?

Here:

```text
capacity too small → impossible
capacity large enough → possible
```

So:

```text
❌ ❌ ❌ ❌ ✅ ✅ ✅
```

### Step 4

Binary Search.

---

## 🔑 Recognition Formula

```text
Optimization Problem
        ↓
Define candidate answer
        ↓
Can I check candidate?
        ↓
Yes
        ↓
Is feasibility monotonic?
        ↓
Yes
        ↓
Binary Search on Answer
```

---

# 🔄 Dry Run — Binary Search

For:

```text
A = 2
C = [10, 20, 30, 40]
```

Initial:

```text
low = 40
high = 100
```

### Step 1

```text
mid = 70
```

Check capacity `70`.

Painter 1:

```text
10 + 20 + 30 = 60
```

Cannot add `40`.

Painter 2:

```text
40
```

Feasible:

```text
70 → ✅
```

Therefore, try smaller:

```text
high = 69
```

---

### Step 2

```text
low = 40
high = 69

mid = 54
```

Capacity `54`:

Painter 1:

```text
10 + 20 = 30
```

Next `30` would make:

```text
60 > 54
```

Painter 2:

```text
30
```

Next `40` would exceed capacity.

Requires 3 painters.

Therefore:

```text
54 → ❌
```

Move right:

```text
low = 55
```

---

### Step 3

```text
low = 55
high = 69

mid = 62
```

Painter 1:

```text
10 + 20 + 30 = 60
```

Painter 2:

```text
40
```

Feasible:

```text
62 → ✅
```

Move left:

```text
high = 61
```

---

### Step 4

```text
low = 55
high = 61

mid = 58
```

Requires 3 painters.

```text
58 → ❌
```

Move right:

```text
low = 59
```

---

### Step 5

```text
low = 59
high = 61

mid = 60
```

Painter 1:

```text
10 + 20 + 30 = 60
```

Painter 2:

```text
40
```

Feasible:

```text
60 → ✅
```

Try smaller:

```text
high = 59
```

---

### Step 6

```text
low = 59
high = 59

mid = 59
```

Capacity `59` cannot place:

```text
10 + 20 + 30
```

because:

```text
60 > 59
```

So:

```text
59 → ❌
```

Finally:

```text
low = 60
high = 59
```

Search ends.

Answer:

```text
60
```

---

# ⏱️ Time Complexity

Let:

```text
N = number of boards
S = sum of board lengths
```

Binary Search searches the capacity range:

```text
[max(C), sum(C)]
```

Number of binary-search iterations:

```text
O(log S)
```

Each feasibility check:

```text
O(N)
```

Therefore:

```text
Time: O(N log S)
```

Space:

```text
O(1)
```

---

# ⚖️ Approach Comparison

| Feature             | Brute Force          | Binary Search           |
| ------------------- | -------------------- | ----------------------- |
| Search Range        | `max(C)` → `sum(C)`  | `max(C)` → `sum(C)`     |
| Candidate Selection | Every capacity       | Middle capacity         |
| Feasibility Check   | `O(N)`               | `O(N)`                  |
| Time                | `O(N × S)`           | `O(N log S)`            |
| Space               | `O(1)`               | `O(1)`                  |
| Pattern             | Linear Answer Search | Binary Search on Answer |
| Optimal             | ❌                    | ✅                       |

---

# 🔥 Why `low = max(C)`?

Suppose:

```text
C = [10, 20, 30, 40]
```

If:

```text
capacity = 30
```

the board of length `40` cannot be painted by any painter.

A board cannot be split between painters.

Therefore:

```text
capacity >= maximum board length
```

So:

```text
low = max(C)
```

---

# 🔥 Why `high = sum(C)`?

The maximum possible workload occurs when one painter paints everything.

Therefore:

```text
high = sum(C)
```

So the complete answer space is:

```text
[max(C), sum(C)]
```

---

# ⚠️ Important Detail — Contiguous Allocation

The boards must remain in their original order.

For:

```text
[10, 20, 30, 40]
```

this is valid:

```text
Painter 1 → [10, 20]
Painter 2 → [30, 40]
```

But we cannot rearrange them like:

```text
Painter 1 → [10, 30]
Painter 2 → [20, 40]
```

The feasibility function must therefore process the boards from left to right.

---

# ⚠️ Important Detail — `long long`

The total board length can become large.

Therefore:

```text
sum(C)
```

and the candidate capacity should be stored in:

```text
long long
```

This prevents integer overflow during calculations.

---

# 🔧 Code Variations

### Brute Force

The main difference is that every possible capacity is checked sequentially:

```text
low → low + 1 → low + 2 → ...
```

until a feasible capacity is found.

### Optimal

Binary Search changes the candidate selection:

```text
mid
```

If feasible:

```text
answer may be smaller
→ search left
```

If not feasible:

```text
capacity must increase
→ search right
```

---

# 🧩 Core Pattern to Remember

Day 81 is another strong example of:

> **Binary Search on Answer**

Mental model:

```text
Need minimum maximum workload
            ↓
Find answer range
            ↓
max(board) ... sum(boards)
            ↓
Check candidate capacity
            ↓
Can A painters finish?
            ↓
Monotonic feasibility
            ↓
Binary Search
```

### Recognition Keywords

Whenever you see:

* minimize maximum
* maximum workload
* minimum capacity
* allocate among workers
* split into groups
* minimum time/capacity
* at most `K` workers
* contiguous allocation

think:

> **Binary Search on Answer + Greedy Feasibility Check**

---

# 🚨 Edge Cases

### 1. One painter

If:

```text
A = 1
```

one painter must paint all boards.

Answer:

```text
sum(C)
```

---

### 2. Number of painters ≥ number of boards

Each painter can potentially handle one board.

The minimum capacity becomes:

```text
max(C)
```

---

### 3. One very large board

For:

```text
C = [5, 5, 100, 5]
```

capacity cannot be less than:

```text
100
```

---

### 4. Large values

Use:

```text
long long
```

for total sums and capacity calculations.

---

# 🧠 What I Learned

* The problem is not directly asking us to search through boards.
* We are searching for the **minimum possible maximum workload**.
* The answer range is:

  * `max(board)` → minimum possible capacity.
  * `sum(board)` → maximum possible capacity.
* A candidate capacity can be checked using a **greedy contiguous allocation**.
* The feasibility condition is monotonic.
* This creates the pattern:
  `❌ ❌ ❌ ✅ ✅ ✅`
* Therefore, **Binary Search on Answer** is the optimal technique.
* The feasibility check runs in `O(N)`.
* Overall optimal complexity is `O(N log S)` where `S` is the total board length.
* `long long` is important when board lengths or their sum can be large.

---

# 🎯 Revision Shortcut

Remember:

```text
Painter Partition
        ↓
Minimum maximum workload
        ↓
low = max(board)
high = sum(board)
        ↓
isPossible(capacity)
        ↓
Greedy contiguous allocation
        ↓
❌ ❌ ❌ ✅ ✅ ✅
        ↓
Binary Search on Answer
```

**Pattern:** `Binary Search on Answer + Greedy`

**Optimal Complexity:** `O(N log S)` time, `O(1)` extra space.
