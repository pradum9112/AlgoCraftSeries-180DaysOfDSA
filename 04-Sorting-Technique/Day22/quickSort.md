# Quick Sort

## 📌 Problem Statement

Given an integer array `nums`, sort the array in **non-decreasing order** using the **Quick Sort** algorithm.

A non-decreasing array means every element is greater than or equal to its previous element.

---

## 📝 Example

### Input

```text
nums = [7,4,1,5,3]
```

### Output

```text
[1,3,4,5,7]
```

---

# 💡 Why is it called Quick Sort?

Quick Sort chooses one element called the **Pivot**.

The pivot is placed at its correct sorted position.

Then the array is divided into two parts.

- Left Part → Elements smaller than Pivot
- Right Part → Elements greater than Pivot

The same process is repeated recursively.

Since the array becomes sorted very quickly by repeatedly partitioning around the pivot, it is called **Quick Sort**.

---

# 💡 Approach

Our implementation uses the **Lomuto Partition Scheme**.

Steps

1. Choose the last element as Pivot.
2. Move all smaller elements to the left.
3. Place Pivot at its correct position.
4. Recursively sort the left half.
5. Recursively sort the right half.

---

# 🧠 Dry Run (Code Wise)

## Input

```text
nums = [7,4,1,5,3]
```

Initial Call

```cpp
helper(nums,0,4)
```

Current Array

```text
[7,4,1,5,3]
```

---

# Step 1

Pivot

```text
3
```

Initialize

```text
i = -1
```

Loop

```text
j = 0 → 3
```

---

## j = 0

```text
7 < 3 ?

No
```

Array

```text
[7,4,1,5,3]
```

---

## j = 1

```text
4 < 3 ?

No
```

---

## j = 2

```text
1 < 3 ?

Yes
```

Increase

```text
i = 0
```

Swap

```text
nums[0]

↓

nums[2]
```

Array

```text
[1,4,7,5,3]
```

---

## j = 3

```text
5 < 3 ?

No
```

Loop finishes.

Swap Pivot

```text
swap(nums[i+1],nums[high])

↓

swap(nums[1],nums[4])
```

Array

```text
[1,3,7,5,4]
```

Pivot

```text
3
```

is now at its correct position.

Partition Index

```text
1
```

---

# Recursive Calls

Left

```cpp
helper(nums,0,0)
```

One element.

Return.

---

Right

```cpp
helper(nums,2,4)
```

Current Array

```text
[7,5,4]
```

Pivot

```text
4
```

---

## Partition

Initialize

```text
i = 1
```

Loop

```text
7 <4

No
```

```text
5 <4

No
```

Swap Pivot

```text
swap(nums[2],nums[4])
```

Array

```text
[1,3,4,5,7]
```

Partition Index

```text
2
```

---

Next Recursive Calls

```text
helper(2,1)

Return
```

```text
helper(3,4)
```

Pivot

```text
7
```

Compare

```text
5 <7

Yes
```

Swap with itself.

Final Array

```text
[1,3,4,5,7]
```

Recursion Ends.

---

# Final Result

```text
[1,3,4,5,7]
```

---

# 🤔 Why do we use a Pivot?

The Pivot divides the array into two parts.

Example

```text
[7,4,1,5,3]

Pivot = 3
```

After partition

```text
[1] 3 [7,5,4]
```

Everything on the left is smaller.

Everything on the right is greater.

Now both parts can be sorted independently.

---

# 🤔 Why do we return Partition Index?

After partition,

Pivot reaches its final sorted position.

Example

```text
[1,3,7,5,4]
```

Pivot

```text
3
```

is now fixed forever.

No future recursive call touches it.

So we return its index.

---

# 📊 Time Complexity

## Best Case

Pivot divides the array equally.

Example

```text
8

↓

4 + 4

↓

2 + 2 + 2 + 2
```

Levels

```text
logN
```

Work per level

```text
N
```

Total

```text
O(NlogN)
```

---

## Average Case

Random Pivot positions.

```text
O(NlogN)
```

---

## Worst Case

Already sorted array.

Example

```text
1 2 3 4 5
```

Last element is always Pivot.

Division

```text
4 + 0

↓

3 + 0

↓

2 + 0

↓

1
```

Recursion becomes

```text
N
```

levels.

Each level performs

```text
N
```

work.

Therefore

```text
O(N²)
```

---

# 📊 Space Complexity

Only recursion stack.

## Best Case

```text
O(logN)
```

## Worst Case

```text
O(N)
```

No extra array is created.

---

# ⚠️ Common Mistakes

❌ Running loop till

```cpp
j <= high
```

Correct

```cpp
j < high
```

---

❌ Forgetting

```cpp
swap(nums[i+1],nums[high]);
```

Pivot never reaches its correct position.

---

❌ Returning

```cpp
i
```

instead of

```cpp
i+1
```

---

❌ Calling recursion including Pivot again.

Correct

```cpp
helper(low,pIndex-1);

helper(pIndex+1,high);
```

---

# 📚 What I Learned

- Quick Sort uses Divide and Conquer.
- Pivot divides the array into two parts.
- Partition places the Pivot at its correct position.
- Recursion sorts both halves independently.
- Average complexity is **O(N log N)**.
- Worst case occurs when partitions become highly unbalanced.

---

# 📝 30-Second Revision Notes

✔ Choose last element as Pivot.

✔ Move smaller elements to the left.

✔ Place Pivot correctly.

✔ Recursively sort left and right.

✔ Best → **O(N log N)**

✔ Average → **O(N log N)**

✔ Worst → **O(N²)**

✔ Auxiliary Space → **O(log N)** average, **O(N)** worst.

---

# 💡 Interview Takeaways

Quick Sort is one of the fastest practical sorting algorithms because it sorts **in-place** and usually produces balanced partitions, giving an average time complexity of **O(N log N)**.

> **Key Insight:** The partition step permanently places the Pivot in its correct sorted position, reducing the problem into two independent subproblems.