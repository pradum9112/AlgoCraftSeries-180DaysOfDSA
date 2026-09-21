# Day 75 — Nth Root of a Number

## 📌 Problem

Given two integers `N` and `M`, find the integer `x` such that:

`x^N = M`

If such an integer does not exist, return `-1`.

### Example

**Input**

```text
N = 3
M = 27
```

**Output**

```text
3
```

Because:

```text
3³ = 27
```

If:

```text
N = 3
M = 28
```

then the answer is:

```text
-1
```

because no integer has cube equal to `28`.

---

# 🔹 Approach 1 — Brute Force

## 💡 Idea

Try every possible answer starting from `1`.

For every candidate `i`, calculate `i^N`.

There are three possibilities:

* `i^N == M` → `i` is the answer.
* `i^N < M` → continue searching.
* `i^N > M` → stop because larger values will produce an even larger power.

The given implementation also stops the power calculation early when the current value becomes greater than `M`.

---

## 🧠 Pattern Recognition Clue

When a problem asks:

> Find an integer whose power is exactly equal to a given number.

First ask:

**"Can I try all possible answers?"**

If the answer range is small enough, brute force is the natural starting point.

But after identifying the brute-force search space, ask:

1. Is the answer ordered?
2. Does the value increase as the candidate increases?
3. Can I eliminate half of the candidates?

If yes, think about **Binary Search on Answer**.

---

## 🔄 Dry Run

Consider:

```text
N = 3
M = 27
```

| Candidate | Candidate³ | Result    |
| --------: | ---------: | :-------- |
|         1 |          1 | `< 27`    |
|         2 |          8 | `< 27`    |
|         3 |         27 | `== 27` ✅ |

Therefore:

```text
Answer = 3
```

### Another Example

```text
N = 3
M = 28
```

The relevant values are:

```text
1³ = 1
2³ = 8
3³ = 27
4³ = 64
```

We cross from:

```text
27 < 28
```

to:

```text
64 > 28
```

No exact root exists, so:

```text
Answer = -1
```

---

## ⏱️ Time Complexity

There can be up to `M` candidate values.

For every candidate, calculating its Nth power can take up to `N` operations.

**Time:** `O(N × M)`

**Space:** `O(1)`

---

# 🔹 Approach 2 — Binary Search

## 💡 Observation

As `x` increases, `x^N` also increases for positive `x`.

For example, when `N = 3`:

```text
1³ < 2³ < 3³ < 4³ < 5³ ...
```

Therefore, the answer space has a monotonic property.

For a candidate `mid`:

### Case 1 — Exact Match

```text
mid^N == M
```

We found the answer.

### Case 2 — Too Large

```text
mid^N > M
```

`mid` is too large, so the answer must be on the left.

Move:

```text
high = mid - 1
```

### Case 3 — Too Small

```text
mid^N < M
```

`mid` is too small, so search on the right.

Move:

```text
low = mid + 1
```

---

# 🧠 Pattern Recognition Clue

This is the **main pattern of Day75**.

Look for:

```text
Find x
such that
f(x) = target
```

where `f(x)` is monotonic.

Here:

```text
f(x) = x^N
```

and:

```text
x increases
     ↓
x^N increases
```

Therefore:

```text
Ordered Answer Space
        +
Monotonic Condition
        ↓
Binary Search on Answer
```

### Recognition Question

Whenever you see a problem asking for a:

* minimum value
* maximum value
* exact value
* smallest possible answer
* largest possible answer

ask:

> **"Can I binary search over the answer instead of the original data?"**

That question is more important than memorizing this particular solution.

---

# 🔄 Dry Run — Binary Search

Consider:

```text
N = 3
M = 27
```

Initial search space:

```text
low = 1
high = 27
```

### Step 1

Candidate:

```text
mid = 14
```

Since:

```text
14³ > 27
```

`14` is too large.

Search left:

```text
high = 13
```

---

### Step 2

```text
mid = 7
```

Again:

```text
7³ > 27
```

Search left:

```text
high = 6
```

---

### Step 3

```text
mid = 3
```

Now:

```text
3³ = 27
```

Exact match.

Therefore:

```text
Answer = 3
```

The important point is that Binary Search eliminated large portions of the answer space instead of checking every number.

---

# 🔄 Dry Run — No Exact Root

Consider:

```text
N = 3
M = 28
```

We know:

```text
3³ = 27
4³ = 64
```

So:

```text
3³ < 28
4³ > 28
```

There is no integer answer.

Binary Search keeps eliminating impossible candidates until:

```text
low > high
```

Then:

```text
Answer = -1
```

---

# ⚠️ Important Observation — Overflow

Power calculation can become very large.

For example:

```text
mid × mid × mid × ...
```

can exceed the range of a normal `int`.

The solution therefore uses `long long` for the intermediate power calculation.

Another useful optimization is **early stopping**:

Once:

```text
power > M
```

there is no need to continue calculating the remaining powers.

This saves unnecessary operations and prevents the intermediate value from growing unnecessarily large.

---

# ⚖️ Approach Comparison

| Feature           | Brute Force         | Binary Search           |
| ----------------- | ------------------- | ----------------------- |
| Search Method     | Try every candidate | Divide answer space     |
| Search Space      | `1 ... M`           | `1 ... M`               |
| Power Calculation | `O(N)`              | `O(N)`                  |
| Overall Time      | `O(N × M)`          | `O(N × log M)`          |
| Space             | `O(1)`              | `O(1)`                  |
| Pattern           | Direct Search       | Binary Search on Answer |
| Optimal           | ❌                   | ✅                       |

### Optimization

The major improvement is:

```text
O(N × M)
      ↓
O(N × log M)
```

The power-check itself still takes `O(N)`, but Binary Search reduces the number of candidates that need to be checked.

---

# 🚨 Edge Cases

### Exact Nth Root

```text
N = 3
M = 27
```

Output:

```text
3
```

### No Exact Nth Root

```text
N = 3
M = 28
```

Output:

```text
-1
```

### `M = 1`

For positive `N`:

```text
1^N = 1
```

So the answer is:

```text
1
```

### `N = 1`

The equation becomes:

```text
x¹ = M
```

Therefore the answer is `M`.

### Large Values

Use `long long` for the power calculation and stop early when the power becomes greater than `M`.

---

# 🧩 Code Variations

## Brute Force

The first solution directly checks every possible candidate and calculates its Nth power.

Its main idea is:

```text
Candidate → Power Check → Compare with M
```

---

## Binary Search

The second solution separates the power comparison into a helper function.

The helper determines whether:

```text
mid^N < M
mid^N = M
mid^N > M
```

The Binary Search then uses this information to decide which half of the answer space can be eliminated.

This separation makes the main Binary Search logic easier to understand.

---

# 🧠 What I Learned

* Nth Root problems can be solved by searching the possible answer.
* Brute force helps establish the basic solution.
* The function `x^N` is monotonic for positive `x`.
* A monotonic answer space allows **Binary Search on Answer**.
* The important pattern is not "Nth Root"; it is **Binary Search on a monotonic answer space**.
* Power calculations can overflow, so intermediate values need appropriate handling.
* If the calculated power already exceeds `M`, further multiplication is unnecessary.
* Binary Search reduces the candidate checks from `M` to approximately `log M`.

---

# 🎯 Revision Shortcut

Remember:

```text
Nth Root
   ↓
Find x such that x^N = M
   ↓
x increases → x^N increases
   ↓
Monotonic
   ↓
Binary Search on Answer
```

### Core Pattern

**Binary Search on Answer**

### Complexity

```text
Brute Force  → O(N × M)
Optimal      → O(N × log M)
Space        → O(1)
```
