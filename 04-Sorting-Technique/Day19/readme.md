# Merge Sort

## 📌 Problem Statement

Given an integer array `nums`, sort the array in **non-decreasing order** using the **Merge Sort** algorithm.

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

# 💡 Why is it called Merge Sort?

Merge Sort has two steps.

1. Divide the array into smaller parts.
2. Merge the sorted parts.

Example

```text
[7,4,1,5,3]

↓

Divide

[7,4,1]   [5,3]

↓

Divide Again

[7] [4] [1] [5] [3]

↓

Merge

[4,7]

↓

[1,4,7]

↓

[3,5]

↓

[1,3,4,5,7]
```

The sorting happens during the **Merge** step.

That's why it is called **Merge Sort**.

---

# 💡 Approach

Merge Sort follows **Divide and Conquer**.

For every recursive call

1. Find middle.
2. Divide into two halves.
3. Sort left half.
4. Sort right half.
5. Merge both halves.

---

# 🧠 Dry Run (Code Wise)

## Input

```text
nums = [7,4,1,5,3]
```

Call

```cpp
mergeSortHelper(nums,0,4)
```

Current Array

```text
[7,4,1,5,3]
```

---

# Step 1

```cpp
low = 0
high = 4

mid = 2
```

Split

```text
Left

[7,4,1]

Right

[5,3]
```

Recursion Tree

```text
                  (0,4)

              /           \

          (0,2)          (3,4)

         /     \        /     \

      (0,1)   (2,2)  (3,3)   (4,4)

      /   \

   (0,0) (1,1)
```

Notice

The recursion keeps dividing until

```text
low == high
```

because

```cpp
if(low>=high)
    return;
```

A single element is already sorted.

---

# Returning Starts

Now recursion starts returning.

The first merge is

```cpp
merge(0,0,1)
```

Current

```text
[7]

[4]
```

---

# Merge Function Dry Run

Pointers

```text
left = 0

right = 1

temp = {}
```

Compare

```text
7 <=4 ?

No
```

Take

```text
4
```

Temp

```text
[4]
```

Right side finished.

Copy remaining left

```text
7
```

Temp

```text
[4,7]
```

Copy back

Array becomes

```text
[4,7,1,5,3]
```

---

# Next Merge

Call

```cpp
merge(0,1,2)
```

Current

```text
Left

[4,7]

Right

[1]
```

Pointers

```text
left = 0

right = 2
```

Compare

```text
4<=1 ?

No
```

Take

```text
1
```

Temp

```text
[1]
```

Right finished.

Copy remaining

```text
4

7
```

Temp

```text
[1,4,7]
```

Array becomes

```text
[1,4,7,5,3]
```

---

# Right Half

Call

```cpp
merge(3,3,4)
```

Current

```text
Left

[5]

Right

[3]
```

Compare

```text
5<=3 ?

No
```

Take

```text
3
```

Temp

```text
[3]
```

Copy remaining

```text
5
```

Temp

```text
[3,5]
```

Array

```text
[1,4,7,3,5]
```

---

# Final Merge

Call

```cpp
merge(0,2,4)
```

Current

```text
Left

[1,4,7]

Right

[3,5]
```

Pointers

```text
left = 0

right = 3

temp = {}
```

---

Compare

```text
1<=3

Yes
```

Temp

```text
[1]
```

---

Compare

```text
4<=3

No
```

Temp

```text
[1,3]
```

---

Compare

```text
4<=5

Yes
```

Temp

```text
[1,3,4]
```

---

Compare

```text
7<=5

No
```

Temp

```text
[1,3,4,5]
```

---

Right side finished.

Copy remaining

```text
7
```

Temp

```text
[1,3,4,5,7]
```

Copy temp back

Final Array

```text
[1,3,4,5,7]
```

---

# Final Result

```text
[1,3,4,5,7]
```

---

# 🤔 Why do we use a Temporary Array?

Suppose

```text
Left

[4,7]

Right

[1]
```

If we overwrite directly

```text
nums
```

then

```text
7
```

may get lost before comparison.

So we first store everything in

```cpp
temp
```

Finally

```cpp
nums[i]=temp[i-low];
```

copies everything back safely.

---

# 🤔 Why Base Case?

```cpp
if(low>=high)
```

Example

```text
mergeSortHelper(2,2)
```

Only

```text
1
```

element remains.

A single element is already sorted.

So recursion stops.

---

# 📊 Time Complexity (Visualization)

Suppose

```text
N = 8
```

Level 0

```text
[8]

Work = 8
```

---

Level 1

```text
[4] [4]

Work = 8
```

---

Level 2

```text
[2][2][2][2]

Work = 8
```

---

Level 3

```text
[1][1][1][1][1][1][1][1]

Work = 8
```

---

Number of Levels

```text
log₂8

=

3
```

At every level

```text
Total Work = N
```

So

```text
N

×

logN
```

Hence

```text
Time Complexity

O(NlogN)
```

---

## Best Case

```text
O(NlogN)
```

---

## Average Case

```text
O(NlogN)
```

---

## Worst Case

```text
O(NlogN)
```

Merge Sort always divides and merges in the same way.

---

# 📊 Space Complexity

Temporary Array

```text
O(N)
```

Recursion Stack

```text
O(logN)
```

Overall Auxiliary Space

```text
O(N)
```

because

```text
N > logN
```

---

# ⚠️ Common Mistakes

❌ Forgetting

```cpp
if(low>=high)
```

Infinite recursion.

---

❌ Forgetting to copy

```cpp
temp

↓

nums
```

---

❌ Wrong middle calculation.

Always use

```cpp
mid = low + (high-low)/2;
```

---

❌ Forgetting to copy remaining elements from left or right.

---

# 📚 What I Learned

- Merge Sort follows Divide and Conquer.
- Recursion first divides the array.
- Sorting happens while merging.
- Temporary array is necessary for safe merging.
- Merge Sort guarantees **O(N log N)** in all cases.
- Merge Sort is a **Stable Sorting Algorithm**.

---

# 📝 30-Second Revision Notes

✔ Divide the array until one element remains.

✔ One element is already sorted.

✔ Merge two sorted arrays.

✔ Store merged elements in a temporary array.

✔ Copy temporary array back.

✔ Time Complexity → **O(N log N)**

✔ Space Complexity → **O(N)**

✔ Stable Sorting Algorithm.

---

# 💡 Interview Takeaways

Merge Sort is one of the most important sorting algorithms because it always runs in **O(N log N)** time, regardless of whether the input is already sorted, randomly ordered, or reverse sorted.

It is preferred when **consistent performance** and **stability** are required, although it uses extra memory for the temporary array.