# Day 65 — Floor and Ceil in a Sorted Array

## 📌 Problem Statement

Given a **sorted array** `nums` and an integer `x`, find:

* **Floor of x** → the largest element in the array that is `<= x`.
* **Ceil of x** → the smallest element in the array that is `>= x`.

Return the result as:

```text
{floor, ceil}
```

If floor or ceil does not exist, return `-1` for that value.

### Example

```text
Input:
nums = [1, 2, 4, 6, 8]
x = 5

Output:
Floor = 4
Ceil = 6
```

---

# 🧠 Understanding Floor and Ceil

For:

```text
nums = [1, 2, 4, 6, 8]
             ↑  ↑
           Floor Ceil
             5
```

For `x = 5`:

```text
Floor → 4
Ceil  → 6
```

### Floor

The greatest value satisfying:

```text
nums[i] <= x
```

### Ceil

The smallest value satisfying:

```text
nums[i] >= x
```

---

# Approach 1 — Linear Search

## 💡 Idea

Traverse the entire array.

For every element:

### Finding Floor

If:

```text
nums[i] <= x
```

then it can be a floor candidate.

Because the array is sorted, every later valid value will be greater, so we keep updating:

```cpp
floorVal = nums[i];
```

### Finding Ceil

If:

```text
nums[i] >= x
```

and we have not already found a ceil, then this is the first valid value and therefore the smallest possible ceil.

```cpp
if (nums[i] >= x && ceilVal == -1)
    ceilVal = nums[i];
```

---

## 🔍 Dry Run

```text
nums = [1, 2, 4, 6, 8]
x = 5
```

| i | nums[i] | Floor | Ceil |
| - | ------: | ----: | ---: |
| 0 |       1 |     1 |   -1 |
| 1 |       2 |     2 |   -1 |
| 2 |       4 |     4 |   -1 |
| 3 |       6 |     4 |    6 |
| 4 |       8 |     4 |    6 |

Final:

```text
Floor = 4
Ceil = 6
```

### Complexity

```text
Time  : O(N)
Space : O(1)
```

---

# Approach 2 — Binary Search

Since the array is **sorted**, we can use Binary Search.

Instead of checking every element, we eliminate half of the search space at every step.

## 💡 Main Idea

At every `mid`:

### Case 1 — `nums[mid] == x`

We found both:

```text
Floor = x
Ceil = x
```

So return immediately.

---

### Case 2 — `nums[mid] < x`

`nums[mid]` can be a possible **floor**.

But there might be a larger value that is still `<= x`.

Therefore:

```cpp
floorVal = nums[mid];
low = mid + 1;
```

We move right to search for a better floor.

---

### Case 3 — `nums[mid] > x`

`nums[mid]` can be a possible **ceil**.

But there might be a smaller value that is still `>= x`.

Therefore:

```cpp
ceilVal = nums[mid];
high = mid - 1;
```

We move left to search for a better ceil.

---

# 🔍 Binary Search Dry Run

```text
nums = [1, 2, 4, 6, 8]
x = 5
```

### Step 1

```text
low = 0
high = 4

mid = 2
nums[mid] = 4
```

Since:

```text
4 < 5
```

So:

```text
floor = 4
```

Move right:

```text
low = 3
```

---

### Step 2

```text
low = 3
high = 4

mid = 3
nums[mid] = 6
```

Since:

```text
6 > 5
```

So:

```text
ceil = 6
```

Move left:

```text
high = 2
```

---

Now:

```text
low > high
```

Search ends.

Final:

```text
Floor = 4
Ceil = 6
```

### Complexity

```text
Time  : O(log N)
Space : O(1)
```

---

# 🧠 How to Recognize This Pattern

This problem is strongly connected to the previous Binary Search problems.

Look for these keywords:

```text
Sorted Array
      +
First / Last / Closest
      +
<= / >= / > / <
```

Then think about **Boundary Binary Search**.

### Connection with previous Days

| Day    | Problem                | Binary Search Condition            |
| ------ | ---------------------- | ---------------------------------- |
| Day 62 | Lower Bound            | First `>= x`                       |
| Day 63 | Upper Bound            | First `> x`                        |
| Day 64 | Search Insert Position | First `>= target`                  |
| Day 65 | Floor & Ceil           | Largest `<= x` and smallest `>= x` |

So Day 65 is a natural continuation of the previous three problems.

---

# ⭐ Pattern Clue

When you see:

> "Find the largest value smaller than or equal to X"

Think:

```text
FLOOR
```

When you see:

> "Find the smallest value greater than or equal to X"

Think:

```text
CEIL
```

And because the array is sorted:

```text
→ Binary Search
```

---

# ⚠️ Common Mistakes

### 1. Moving in the wrong direction for Floor

If:

```cpp
nums[mid] < x
```

we found a possible floor.

We need to search for a **larger** floor:

```cpp
low = mid + 1;
```

---

### 2. Moving in the wrong direction for Ceil

If:

```cpp
nums[mid] > x
```

we found a possible ceil.

We need to search for a **smaller** ceil:

```cpp
high = mid - 1;
```

---

### 3. Forgetting the `-1` case

If there is no floor:

```text
x < smallest element
```

then:

```text
floor = -1
```

If there is no ceil:

```text
x > largest element
```

then:

```text
ceil = -1
```

---

# 🧪 Test Cases

### Test Case 1

```text
Input:
nums = [1, 2, 4, 6, 8]
x = 5

Output:
Floor = 4
Ceil = 6
```

### Test Case 2 — Exact Match

```text
Input:
nums = [1, 2, 4, 6, 8]
x = 4

Output:
Floor = 4
Ceil = 4
```

### Test Case 3 — No Floor

```text
Input:
nums = [2, 4, 6, 8]
x = 1

Output:
Floor = -1
Ceil = 2
```

### Test Case 4 — No Ceil

```text
Input:
nums = [2, 4, 6, 8]
x = 10

Output:
Floor = 8
Ceil = -1
```

---

# 📊 Approach Comparison

| Approach      |     Time | Space | Requirement          |
| ------------- | -------: | ----: | -------------------- |
| Linear Search |     O(N) |  O(1) | Works by traversal   |
| Binary Search | O(log N) |  O(1) | Array must be sorted |

### Best Approach

For a sorted array:

```text
Binary Search → O(log N)
```

The important learning is not just solving Floor & Ceil, but recognizing that this is another **boundary-search problem**.
