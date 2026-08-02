# Union of Two Sorted Arrays (Optimal - Two Pointer)

## 📝 Problem Statement

Given two **sorted arrays** `nums1` and `nums2`, return the **union** of both arrays.

The union should contain **only unique elements** in **sorted order**.

---

## Example 1

### Input

```
nums1 = [1,2,2,3,5]

nums2 = [2,3,4,4,6]
```

### Output

```
[1,2,3,4,5,6]
```

### Explanation

Both arrays contain duplicate elements.

The union contains every distinct element only once.

---

# 💡 Approach Used

Since **both arrays are already sorted**, we can solve this problem using the **Two Pointer Technique**.

Maintain two pointers:

```
i → nums1

j → nums2
```

At every step

- Compare both elements.
- Insert the smaller element into the answer.
- If both are equal, insert only one copy.
- Skip duplicates by checking the last inserted element.
- Continue until both arrays are completely traversed.

---

# 🔍 Dry Run

## Input

```
nums1 = [1,2,2,3,5]

nums2 = [2,3,4,4,6]
```

Initially

```
i = 0

j = 0

unionArr = [ ]
```

---

## Step 1

```
nums1[i] = 1

nums2[j] = 2
```

```
1 <= 2
```

Insert

```
unionArr

[1]
```

Move

```
i++
```

---

## Step 2

```
nums1[i] = 2

nums2[j] = 2
```

Insert only one copy

```
unionArr

[1,2]
```

Since both are equal

```
i++

j++
```

---

## Step 3

```
nums1[i] = 2

nums2[j] = 3
```

Current answer

```
[1,2]
```

Last inserted element is already **2**

So

```
Do not insert duplicate.
```

Move

```
i++
```

---

## Step 4

```
nums1[i]=3

nums2[j]=3
```

Insert

```
3
```

Answer becomes

```
[1,2,3]
```

Move both pointers.

---

## Step 5

```
nums1[i]=5

nums2[j]=4
```

Insert

```
4
```

Answer

```
[1,2,3,4]
```

Move

```
j++
```

---

## Step 6

Again

```
nums2[j]=4
```

Last inserted element is already

```
4
```

Duplicate

Skip it.

Move

```
j++
```

---

## Step 7

```
nums1[i]=5

nums2[j]=6
```

Insert

```
5
```

Answer

```
[1,2,3,4,5]
```

Move

```
i++
```

---

Main loop finishes because

```
i == n
```

Remaining element

```
6
```

Insert

```
unionArr

[1,2,3,4,5,6]
```

---

## Final Answer

```
[1,2,3,4,5,6]
```

---

# 📄 Understanding the Duplicate Removal Logic

The most important line is

```cpp
if(unionArr.empty() || unionArr.back()!=nums1[i])
```

Let's understand it.

### Case 1

```
unionArr

[ ]
```

```
empty()

↓

true
```

So first element is always inserted.

---

### Case 2

Current Answer

```
[1,2]
```

Current element

```
2
```

```
unionArr.back()

↓

2
```

Check

```
2 != 2

↓

False
```

Duplicate found.

Do not insert.

---

### Case 3

Current Answer

```
[1,2]
```

Current element

```
3
```

Check

```
2 != 3

↓

True
```

Insert

```
3
```

Answer becomes

```
[1,2,3]
```

---

# 🧠 Why do we increment both pointers when elements are equal?

Suppose

```
nums1

2

nums2

2
```

If only

```
i++
```

is performed,

then the next comparison becomes

```
3

2
```

The second **2** will again be processed.

Therefore, whenever

```
nums1[i] == nums2[j]
```

both pointers are moved.

```
i++

j++
```

This avoids unnecessary comparisons.

---

# 🚀 Complexity Analysis

## ✅ Current Solution Used

### Approach

Two Pointer Technique

### Time Complexity

```
O(n + m)
```

where

```
n = size of nums1

m = size of nums2
```

Each pointer visits every element only once.

---

### Space Complexity

```
O(n + m)
```

The output union array stores all unique elements.

---

# ⚡ Can This Be Optimized?

### If Arrays are Sorted

Current solution is already the **best possible solution**.

Time Complexity

```
O(n+m)
```

No algorithm can do better because every element must be seen at least once.

---

### If Arrays are Unsorted

One possible approach is

```
unordered_set
```

Time Complexity

```
O(n+m)
```

Average case

But the final answer may need sorting if sorted output is required.

---

# 📊 Complexity Comparison

| Approach | Arrays | Time | Space |
|----------|--------|------|-------|
| Brute Force | Sorted | O((n+m) log(n+m)) or worse | O(n+m) |
| Hash Set | Unsorted | O(n+m) Average | O(n+m) |
| Two Pointer | Sorted | **O(n+m)** | O(n+m) |

---

# 🧠 Interview Thinking

Whenever you see

- Two sorted arrays
- Merge
- Union
- Intersection

Immediately think about

```
Two Pointer Technique
```

Because sorting allows us to process both arrays together in a single traversal.

---

# 🎯 Learning From This Problem

✅ Two Pointer Technique

✅ Working with two sorted arrays

✅ Removing duplicates efficiently

✅ Using `vector::back()`

✅ Using `vector::empty()`

✅ Merge-like traversal

✅ Why sorted arrays help reduce complexity

---

# ⭐ Key Takeaway

- Sorted arrays unlock the **Two Pointer Technique**.
- Compare elements from both arrays simultaneously.
- Insert only unique elements.
- `unionArr.back()` helps avoid duplicates.
- The optimal time complexity is **O(n + m)** because every element is visited only once.