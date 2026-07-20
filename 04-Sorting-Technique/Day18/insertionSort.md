# Insertion Sort

## 📌 Problem Statement

Given an integer array `nums`, sort the array in **non-decreasing order** using the **Insertion Sort** algorithm.

A non-decreasing array means every element is greater than or equal to its previous element.

---

## 📝 Example

### Input

```text
nums = [7, 4, 1, 5, 3]
```

### Output

```text
[1, 3, 4, 5, 7]
```

### Explanation

The array after sorting becomes

```text
1 ≤ 3 ≤ 4 ≤ 5 ≤ 7
```

Hence it is sorted in non-decreasing order.

---

# 💡 Why is it called **Insertion Sort**?

The word **Insertion** means **to insert something at its correct position**.

In this algorithm, we don't repeatedly swap elements.

Instead,

- Pick one element.
- Find its correct position in the already sorted part.
- Insert it there.

Example

Initially

```text
[7] | [4,1,5,3]
```

The first element (7) is considered sorted.

Now pick **4**.

Remove it temporarily.

Shift all larger elements one position to the right.

Insert **4** in its correct position.

Result

```text
[4,7] | [1,5,3]
```

Again,

Pick **1**

Insert it into

```text
[4,7]
```

Result

```text
[1,4,7]
```

Every pass inserts one element into its correct position.

That's why the algorithm is called **Insertion Sort**.

---

# 💡 Approach

Insertion Sort divides the array into two parts.

```text
Sorted Part | Unsorted Part
```

Initially

```text
[7] | [4,1,5,3]
```

The first element is already sorted.

Now,

for every remaining element,

- Store it as **key**.
- Compare it with elements on the left.
- Shift larger elements one step to the right.
- Insert the key into its correct position.

Repeat until every element has been inserted.

---

# 🧠 Dry Run (Code Wise)

## Input

```text
nums = [7,4,1,5,3]
```

Initially

```text
[7] | [4,1,5,3]
```

Left side is sorted.

---

# Pass 1

```cpp
i = 1
```

```cpp
key = 4
```

```cpp
j = 0
```

Compare

```text
7 > 4
```

✅ Yes

Shift

```text
[7,7,1,5,3]
```

Decrease

```cpp
j = -1
```

Insert

```cpp
nums[j+1] = key
```

Array

```text
[4,7,1,5,3]
```

Sorted Part

```text
[4,7]
```

---

# Pass 2

```cpp
i = 2
```

```cpp
key = 1
```

Compare

```text
7 > 1
```

Shift

```text
[4,7,7,5,3]
```

Compare

```text
4 > 1
```

Shift

```text
[4,4,7,5,3]
```

Insert

```text
[1,4,7,5,3]
```

Sorted Part

```text
[1,4,7]
```

---

# Pass 3

```cpp
i = 3
```

```cpp
key = 5
```

Compare

```text
7 > 5
```

Shift

```text
[1,4,7,7,3]
```

Compare

```text
4 > 5
```

❌ No

Insert

```text
[1,4,5,7,3]
```

Sorted Part

```text
[1,4,5,7]
```

---

# Pass 4

```cpp
i = 4
```

```cpp
key = 3
```

Compare

```text
7 > 3
```

Shift

```text
[1,4,5,7,7]
```

Compare

```text
5 > 3
```

Shift

```text
[1,4,5,5,7]
```

Compare

```text
4 > 3
```

Shift

```text
[1,4,4,5,7]
```

Compare

```text
1 > 3
```

❌ No

Insert

```text
[1,3,4,5,7]
```

---

# Final Answer

```text
[1,3,4,5,7]
```

---

# 🤔 Why do we store `key`?

Suppose

```text
[7,4]
```

If we immediately overwrite

```text
4
```

while shifting,

we lose its value forever.

So first we save

```cpp
key = nums[i];
```

Now we are free to shift larger elements.

Finally,

```cpp
nums[j+1] = key;
```

puts the element back into its correct position.

---

# 🤔 Why do we shift instead of swap?

Selection Sort and Bubble Sort mainly use swaps.

Insertion Sort uses **shifting** because only one element needs to be inserted.

Example

```text
[1,4,7] + key = 5
```

Instead of multiple swaps

```text
Swap 7 and 5
```

We simply shift

```text
7 →

[1,4,7,7]
```

and insert

```text
5

↓

[1,4,5,7]
```

This makes Insertion Sort **stable**.

---

# 📊 Complexity Analysis

## Best Case

Already sorted array.

```text
O(N)
```

No shifting is required.

---

## Average Case

```text
O(N²)
```

---

## Worst Case

Reverse sorted array.

Every element shifts completely.

```text
O(N²)
```

---

## Space Complexity

Only

```text
key

j
```

are used.

Therefore

```text
O(1)
```

---

# ⚖️ Selection Sort vs Insertion Sort

| Feature | Selection Sort | Insertion Sort |
|:--------|:--------------:|:--------------:|
| Finds Minimum | ✅ | ❌ |
| Uses Shifting | ❌ | ✅ |
| Uses Swapping | ✅ | Rarely |
| Stable | ❌ | ✅ |
| Best Case | O(N²) | O(N) |
| Worst Case | O(N²) | O(N²) |
| Space | O(1) | O(1) |

---

# ⚠️ Common Mistakes

❌ Writing

```cpp
key = i;
```

Instead of

```cpp
key = nums[i];
```

---

❌ Using

```cpp
>>
```

instead of

```cpp
>
```

inside the while loop.

---

❌ Forgetting

```cpp
nums[j+1] = key;
```

after the while loop.

---

❌ Starting outer loop from

```cpp
i = 0
```

instead of

```cpp
i = 1
```

---

# 📚 What I Learned

- Why Insertion Sort is called "Insertion" Sort.
- How the array is divided into sorted and unsorted parts.
- Why we store the current element in `key`.
- Why elements are shifted instead of swapped.
- Why Insertion Sort is stable.
- Why it performs very well on nearly sorted arrays.

---

# 📝 30-Second Revision Notes

✔ First element is already sorted.

✔ Pick the next element as **key**.

✔ Shift larger elements to the right.

✔ Insert the key into its correct position.

✔ Repeat until the array is sorted.

✔ Best Case → **O(N)**

✔ Average Case → **O(N²)**

✔ Worst Case → **O(N²)**

✔ Space → **O(1)**

---

# 💡 Interview Takeaways

Insertion Sort is efficient for **small datasets** and **nearly sorted arrays** because it performs very few shifts when elements are already close to their correct positions.

> **Key Insight:** Insertion Sort builds the final sorted array one element at a time by inserting each new element into its correct position within the already sorted portion of the array.