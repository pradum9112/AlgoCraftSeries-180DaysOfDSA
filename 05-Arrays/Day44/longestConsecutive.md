# 📘 Day 44 - Longest Consecutive Sequence

## Problem Statement

Given an unsorted array of integers, find the length of the longest sequence of consecutive integers.

The sequence does not need to appear next to each other in the original array.

### Example

```text
Input:
[100, 4, 200, 1, 3, 2]

Output:
4
```

Because the longest consecutive sequence is:

```text
1 2 3 4
```

Therefore:

```text
Answer = 4
```

---

# Important Observation

The array is **unsorted**.

Example:

```text
[100, 4, 200, 1, 3, 2]
```

The consecutive sequence:

```text
1 2 3 4
```

is scattered throughout the array.

So the main problem is:

> How can we efficiently find consecutive numbers?

---

# Approach 1 — Sorting

First sort the array:

```text
[100, 4, 200, 1, 3, 2]
```

becomes:

```text
[1, 2, 3, 4, 100, 200]
```

Now consecutive numbers become easy to identify.

We compare:

```text
2 = 1 + 1
3 = 2 + 1
4 = 3 + 1
```

Therefore:

```text
1 → 2 → 3 → 4
```

has length:

```text
4
```

---

## Handling Duplicates

Suppose:

```text
[1, 2, 2, 3]
```

After sorting:

```text
[1, 2, 2, 3]
```

The duplicate `2` should not break the sequence.

So:

```cpp
if (nums[i] == nums[i - 1]) {
    continue;
}
```

We simply ignore duplicates.

---

## Sorting Approach Complexity

Sorting takes:

```text
O(n log n)
```

The traversal takes:

```text
O(n)
```

Therefore:

```text
Time = O(n log n)
Space = O(1)
```

Ignoring the implementation-dependent space used internally by `sort`.

---

# Approach 2 — HashSet

The optimal approach uses:

```cpp
unordered_set<int> st;
```

A set stores unique values.

For:

```text
[100, 4, 200, 1, 3, 2]
```

we get:

```text
{100, 4, 200, 1, 3, 2}
```

Duplicates are automatically removed.

---

# Main Idea of HashSet Approach

Instead of sorting the numbers, ask:

> "Is this number the START of a consecutive sequence?"

For a number `num`, check:

```cpp
st.find(num - 1)
```

### If `num - 1` exists

Then `num` is NOT the beginning.

Example:

```text
1 2 3 4
  ↑
  2
```

For `2`:

```text
2 - 1 = 1
```

`1` exists.

Therefore:

```text
2 is not the starting point.
```

---

### If `num - 1` does NOT exist

Then `num` is the beginning.

Example:

```text
1 2 3 4
↑
1
```

For `1`:

```text
1 - 1 = 0
```

`0` does not exist.

Therefore:

```text
1 is the start.
```

---

# Why Checking the Start Is Important

Suppose:

```text
1 2 3 4
```

If we start checking the sequence from every number:

```text
1 → 2 → 3 → 4

2 → 3 → 4

3 → 4

4
```

We would repeat a lot of work.

Instead, only start from:

```text
1
```

because:

```text
0 doesn't exist
```

Then:

```text
1 → 2 → 3 → 4
```

is checked once.

This is the key optimization.

---

# Dry Run

Consider:

```text
nums = [100, 4, 200, 1, 3, 2]
```

Set:

```text
{100, 4, 200, 1, 3, 2}
```

---

## Check 100

Check:

```text
100 - 1 = 99
```

99 does not exist.

Therefore:

```text
100 is a starting point.
```

Check next:

```text
101
```

doesn't exist.

So:

```text
streak = 1
```

---

## Check 4

Check:

```text
4 - 1 = 3
```

3 exists.

Therefore:

```text
4 is NOT a starting point.
```

Skip it.

---

## Check 200

Check:

```text
200 - 1 = 199
```

199 doesn't exist.

So `200` is a starting point.

Check:

```text
201
```

doesn't exist.

Streak:

```text
1
```

---

## Check 1

Check:

```text
1 - 1 = 0
```

0 doesn't exist.

Therefore:

```text
1 is a starting point.
```

Now keep checking:

```text
2 exists
3 exists
4 exists
5 doesn't exist
```

Therefore:

```text
1 → 2 → 3 → 4
```

Streak:

```text
4
```

Update:

```text
longest = 4
```

Final answer:

```text
4
```

---

# Visualization

Think of the Set like a dictionary where we can quickly ask:

```text
"Does this number exist?"
```

For:

```text
1 2 3 4
```

we ask:

```text
Does 0 exist? ❌
        ↓
       1 START

Does 2 exist? ✅
        ↓
Does 3 exist? ✅
        ↓
Does 4 exist? ✅
        ↓
Does 5 exist? ❌
```

So:

```text
1 → 2 → 3 → 4

Length = 4
```

---

# Why HashSet Is Faster

With sorting, we first have to arrange:

```text
100 4 200 1 3 2
 ↓  ↓  ↓  ↓ ↓ ↓
1  2  3  4 100 200
```

That costs:

```text
O(n log n)
```

With HashSet, we don't need to sort.

We can approximately check whether a number exists in:

```text
O(1)
```

average time.

Therefore the overall average complexity becomes:

```text
O(n)
```

---

# Complexity Comparison

| Approach | Time | Space |
|---|---:|---:|
| Sorting | O(n log n) | O(1)* |
| HashSet | **O(n) average** | **O(n)** |

`*` Ignoring implementation-dependent auxiliary space used by sorting.

---

# Which Approach Is Better for Learning?

### First learn:

```text
Sorting Approach
```

because it makes the consecutive relationship visually obvious.

Then optimize to:

```text
HashSet Approach
```

The important jump in thinking is:

```text
Sorting:
"Let's arrange everything first."

HashSet:
"I don't need order.
I only need to know whether a number exists."
```

---

# Most Important Logic

Remember these two checks:

### 1. Is this the START?

```cpp
if (st.find(num - 1) == st.end())
```

Meaning:

```text
Previous number does NOT exist
        ↓
Current number is START
```

### 2. Continue the sequence

```cpp
while (st.find(currentNum + 1) != st.end())
```

Meaning:

```text
Next number exists
        ↓
Continue the streak
```

---

# Pattern to Remember

```text
Put everything in Set
        ↓
Find sequence START
        ↓
num - 1 doesn't exist
        ↓
Keep checking num + 1
        ↓
Count length
        ↓
Update longest
```

---

# Key Learning

This problem teaches an important optimization pattern:

```text
Don't unnecessarily sort
if you only need fast existence checking.
```

### Sorting:

```text
Need ORDER
↓
Sort
```

### HashSet:

```text
Need EXISTENCE
↓
HashSet
```

The optimal solution is:

```text
Average Time = O(n)
Space = O(n)
```