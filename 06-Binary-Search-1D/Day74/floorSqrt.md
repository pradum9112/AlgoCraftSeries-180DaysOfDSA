# Day 74 — Floor Square Root

## 📌 Problem

Given a non-negative integer `n`, find the **floor square root** of `n`.

The floor square root is the largest integer `x` such that:

```text
x² <= n
```

### Example

**Input**

```text
n = 28
```

**Output**

```text
5
```

Because:

```text
5² = 25 <= 28
6² = 36 > 28
```

So:

```text
floor(sqrt(28)) = 5
```

---

# 🔹 Approach 1 — Linear Search

## 💡 Idea

Start checking from `1`.

As long as:

```text
i * i <= n
```

`i` can be the answer.

The moment `i * i > n`, we stop.

The **last valid `i`** is the floor square root.

### Pattern Recognition Clue

Whenever a problem asks:

* largest integer satisfying a condition
* smallest/largest value with `x² <= n`
* answer lies in a numeric range
* condition changes from **valid → invalid**

think:

> **"Can I search over the answer?"**

Here, we can simply try every possible integer.

---

## 🔄 Dry Run

For:

```text
n = 28
```

| `i` | `i²` | `i² <= 28` | `ans` |
| --: | ---: | :--------: | ----: |
|   1 |    1 |      ✅     |     1 |
|   2 |    4 |      ✅     |     2 |
|   3 |    9 |      ✅     |     3 |
|   4 |   16 |      ✅     |     4 |
|   5 |   25 |      ✅     |     5 |
|   6 |   36 |      ❌     |  Stop |

Final answer:

```text
5
```

---



### Complexity

* **Time:** `O(√n)`
* **Space:** `O(1)`

---

# 🔹 Approach 2 — Binary Search

## 💡 Observation

We don't actually need to check every number.

For:

```text
n = 28
```

The possible answer lies between:

```text
0 ... 28
```

For a candidate `mid`:

```text
mid² <= n
```

If true:

```text
mid could be the answer
```

But there may be a larger valid value, so:

```text
low = mid + 1
```

If:

```text
mid² > n
```

then `mid` and everything larger than `mid` cannot be the answer.

So:

```text
high = mid - 1
```

This gives us a **Binary Search on Answer** pattern.

---

## 🧠 Pattern Recognition Clue

This is the important part to remember.

When you see:

> **Find the maximum/minimum value satisfying a monotonic condition**

ask yourself:

1. What is the possible answer range?
2. Can I check whether a candidate is valid?
3. Does the condition remain valid/invalid in one direction?

Here:

```text
1² <= n     ✅
2² <= n     ✅
3² <= n     ✅
4² <= n     ✅
5² <= n     ✅
6² <= n     ❌
7² <= n     ❌
...
```

The pattern is:

```text
VALID VALID VALID VALID VALID INVALID INVALID INVALID
```

That's a **monotonic condition**, so Binary Search can be used.

### 🔑 Recognition Formula

```text
Search space + monotonic condition
              ↓
       Binary Search
```

---

# 🔄 Dry Run — Binary Search

For:

```text
n = 28
```

Initial:

```text
low = 0
high = 28
ans = 0
```

### Step 1

```text
mid = 14
14² = 196
```

Too large:

```text
196 > 28
```

So:

```text
high = 13
```

---

### Step 2

```text
low = 0
high = 13

mid = 6
6² = 36
```

Too large:

```text
36 > 28
```

So:

```text
high = 5
```

---

### Step 3

```text
low = 0
high = 5

mid = 2
2² = 4
```

Valid:

```text
4 <= 28
```

So:

```text
ans = 2
low = 3
```

---

### Step 4

```text
low = 3
high = 5

mid = 4
4² = 16
```

Valid:

```text
ans = 4
low = 5
```

---

### Step 5

```text
low = 5
high = 5

mid = 5
5² = 25
```

Valid:

```text
ans = 5
low = 6
```

Now:

```text
low = 6
high = 5
```

Loop ends.

Final:

```text
ans = 5
```


# ⚠️ Important — Integer Overflow

Don't blindly write:

```cpp
if (mid * mid <= n)
```

For large `n`, `mid * mid` can overflow an `int`.

Safer:

```cpp
if ((long long)mid * mid <= n)
```

This converts the multiplication to `long long`.

---

# ⚖️ Approach Comparison

| Feature            | Linear Search     | Binary Search           |
| ------------------ | ----------------- | ----------------------- |
| Technique          | Sequential Search | Binary Search           |
| Search Space       | `1 ... √n`        | `0 ... n`               |
| Time               | `O(√n)`           | `O(log n)`              |
| Space              | `O(1)`            | `O(1)`                  |
| Easy to understand | ✅                 | ✅                       |
| Optimal            | ❌                 | ✅                       |
| Pattern            | Direct checking   | Binary Search on Answer |

### Best Approach

**Binary Search** is the optimal approach because:

```text
O(√n) → O(log n)
```

---

# 🧩 Core Pattern to Remember

The real learning from this problem isn't just square root.

It's:

> **Binary Search on Answer**

Whenever the problem asks for something like:

```text
maximum possible value
minimum possible value
largest value satisfying condition
smallest value satisfying condition
```

check whether the condition is **monotonic**.

For this problem:

```text
x² <= n
```

produces:

```text
TRUE TRUE TRUE TRUE FALSE FALSE FALSE
```

So Binary Search works.

---

# 🚨 Edge Cases

### 1. `n = 0`

```text
sqrt(0) = 0
```

Output:

```text
0
```

### 2. `n = 1`

```text
sqrt(1) = 1
```

Output:

```text
1
```

### 3. Perfect Square

```text
n = 25
```

Output:

```text
5
```

### 4. Non-perfect Square

```text
n = 28
```

Output:

```text
5
```

### 5. Large Number

Use:

```cpp
(long long)mid * mid
```

to avoid integer overflow.

---

# 🔧 Code Variations

## Variation 1 — Linear Search

```cpp
for (int i = 1; i * i <= n; i++) {
    ans = i;
}
```

## Variation 2 — Binary Search

```cpp
while (low <= high) {
    int mid = low + (high - low) / 2;

    if ((long long)mid * mid <= n) {
        ans = mid;
        low = mid + 1;
    }
    else {
        high = mid - 1;
    }
}
```

The important difference is:

```text
Linear → try every candidate

Binary → eliminate half of the candidates
```

---

# 🧠 What I Learned

* Floor square root means the **largest integer whose square is ≤ `n`**.
* A simple linear search can solve the problem.
* The optimized solution uses **Binary Search on Answer**.
* The key pattern is a **monotonic condition**.
* For `mid²`, use `long long` to avoid integer overflow.
* When looking for a maximum/minimum satisfying a condition, always ask:

  * What is my search space?
  * Can I validate a candidate?
  * Is the condition monotonic?
* Binary Search reduced the complexity from **`O(√n)` to `O(log n)`**.

---

# 🎯 Revision Shortcut

Remember this mental model:

```text
Need floor(sqrt(n))
        ↓
Answer is an integer
        ↓
Can check: mid² <= n ?
        ↓
Valid → go right
Invalid → go left
        ↓
Binary Search on Answer
```

**Pattern:** `Binary Search on Answer`

**Optimal Complexity:** `O(log n)` time, `O(1)` space.
