# 📘 Next Permutation

## Problem Statement

Given an array of integers, rearrange the elements into the **next lexicographically greater permutation**.

If the array is already the greatest possible permutation, rearrange it into the smallest possible permutation.

The modification must be done **in-place**.

---

# Example 1

## Input

```text
1 2 3
```

Possible permutations:

```text
123
132
213
231
312
321
```

Current:

```text
123
```

Next permutation:

```text
132
```

## Output

```text
1 3 2
```

---

# Example 2

## Input

```text
3 2 1
```

This is already the largest permutation.

Therefore, the next permutation wraps around to:

```text
1 2 3
```

## Output

```text
1 2 3
```

---

# Optimal Approach

We solve the problem using four steps.

```text
Step 1 → Find breakpoint
Step 2 → Find next greater element
Step 3 → Swap
Step 4 → Reverse suffix
```

Complexity:

```text
Time  = O(n)
Space = O(1)
```

---

# Step 1: Find the Breakpoint

Start from the right side.

Find the first index `i` such that:

```text
nums[i] < nums[i + 1]
```

This index is called the **breakpoint**.

Why do we search from the right?

Because we want to make the **smallest possible change** to obtain the next permutation.

---

# Example

Consider:

```text
1 2 3
```

Start from the right.

Compare:

```text
2 < 3
```

True.

Therefore:

```text
ind = 1
```

The breakpoint is:

```text
1 2 | 3
    ↑
  index 1
```

---

# Another Example

Consider:

```text
1 3 5 4 2
```

Start from right:

```text
4 > 2
```

No.

Then:

```text
5 > 4
```

No.

Then:

```text
3 < 5
```

Yes.

Therefore:

```text
ind = 1
```

Array becomes conceptually:

```text
1 3 | 5 4 2
  ↑
breakpoint
```

---

# Why Breakpoint?

The suffix after the breakpoint is already in **descending order**.

For:

```text
1 3 5 4 2
```

suffix:

```text
5 4 2
```

is descending.

That means this suffix is already the largest possible arrangement of those elements.

So to get the next permutation, we need to make a change at the breakpoint.

---

# Step 2: Find the Next Greater Element

After finding:

```text
ind
```

look from the right side.

Find the first element greater than:

```text
nums[ind]
```

Then swap them.

Example:

```text
1 3 | 5 4 2
```

Breakpoint:

```text
3
```

Look from right:

```text
2 → not greater than 3

4 → greater than 3
```

So swap:

```text
1 3 5 4 2
    ↓
1 4 5 3 2
```

---

# Why Search From Right?

The suffix is in descending order.

Therefore, when we search from the right and find the first element greater than `nums[ind]`, it is the **smallest element in that suffix that can make the number larger**.

This keeps the resulting permutation as close as possible to the original.

---

# Step 3: Swap

Before:

```text
1 3 5 4 2
```

Swap:

```text
3 ↔ 4
```

After:

```text
1 4 5 3 2
```

But this is not yet the final answer.

Why?

Because the suffix:

```text
5 3 2
```

is still in descending order.

We need the smallest possible suffix.

---

# Step 4: Reverse the Suffix

Reverse everything after the breakpoint.

Before:

```text
1 4 | 5 3 2
```

Reverse:

```text
2 3 5
```

Final:

```text
1 4 2 3 5
```

Therefore:

```text
Next Permutation = 1 4 2 3 5
```

---

# Complete Dry Run

Consider:

```text
nums = [1, 3, 5, 4, 2]
```

---

## Step 1 — Find Breakpoint

Start from right.

```text
4 < 2 ❌
```

```text
5 < 4 ❌
```

```text
3 < 5 ✅
```

Therefore:

```text
ind = 1
nums[ind] = 3
```

Visual:

```text
1 3 | 5 4 2
  ↑
breakpoint
```

---

## Step 2 — Find Greater Element

Search from right:

```text
2 > 3 ❌
```

```text
4 > 3 ✅
```

So choose:

```text
4
```

---

## Step 3 — Swap

Before:

```text
1 3 5 4 2
```

After:

```text
1 4 5 3 2
```

---

## Step 4 — Reverse Suffix

Suffix:

```text
5 3 2
```

Reverse:

```text
2 3 5
```

Final:

```text
1 4 2 3 5
```

Answer:

```text
1 4 2 3 5
```

---

# What If Breakpoint Doesn't Exist?

Consider:

```text
3 2 1
```

Check from right:

```text
2 < 1 ❌
```

```text
3 < 2 ❌
```

No breakpoint.

That means the entire array is descending:

```text
3 2 1
```

This is the largest permutation.

So the next permutation is the smallest one.

Reverse the entire array:

```text
3 2 1
 ↓ ↓ ↓
1 2 3
```

Answer:

```text
1 2 3
```

---

# Important Visualization

Think of a permutation like a number.

For example:

```text
1 3 5 4 2
```

We want the **smallest number greater than this**.

So:

```text
1 3 5 4 2
       ↓
   Make a small increase
```

We change:

```text
3 → 4
```

giving:

```text
1 4 5 3 2
```

Then make everything after it as small as possible:

```text
5 3 2
 ↓ ↓ ↓
2 3 5
```

Final:

```text
1 4 2 3 5
```

---

# The Four-Step Memory Trick

Remember:

```text
BREAK → SWAP → REVERSE
```

More precisely:

```text
1. Breakpoint find karo
2. Right se greater element find karo
3. Swap karo
4. Suffix reverse karo
```

---

# Why Is It O(n)?

### Step 1

Find breakpoint:

```text
O(n)
```

### Step 2

Find greater element:

```text
O(n)
```

### Step 3

Swap:

```text
O(1)
```

### Step 4

Reverse suffix:

```text
O(n)
```

Overall:

```text
O(n) + O(n) + O(1) + O(n)
```

Therefore:

```text
O(n)
```

---

# Space Complexity

We only use variables:

```text
ind
start
end
temp
```

No extra array is created.

Therefore:

```text
Space = O(1)
```

---

# Complexity

| Approach | Time | Space |
|---|---:|---:|
| Generate all permutations | O(n! × n) | O(n) |
| Optimal Next Permutation | **O(n)** | **O(1)** |

---

# Key Learning

The most important idea is:

> **Make the smallest possible increase from the right side.**

That's why:

```text
Right → Left
```

is important.

And after increasing the number:

```text
Suffix → Smallest possible order
```

That's why we reverse the suffix.

---

# Quick Revision

For:

```text
1 3 5 4 2
```

Remember:

```text
Step 1:
1 3 | 5 4 2
  ↑
breakpoint

Step 2:
3 → 4

Step 3:
1 4 5 3 2

Step 4:
1 4 | 2 3 5

Answer:
1 4 2 3 5
```

## Pattern

```text
Find breakpoint
      ↓
Find next greater
      ↓
     Swap
      ↓
Reverse suffix
```

**Time:** `O(n)`

**Space:** `O(1)`