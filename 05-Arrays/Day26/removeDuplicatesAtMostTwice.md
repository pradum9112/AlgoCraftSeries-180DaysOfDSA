# Remove Duplicates from Sorted Array II

## 📝 Problem Statement

Given a sorted integer array `nums`, remove the duplicates **in-place** such that each unique element appears **at most two times**.

Return the new length of the array after removing extra duplicates.

The first `k` elements should contain the final answer.

---

## 💡 Approach

Since the array is already sorted, duplicate elements appear together.

We use **Two Pointers**.

- `i` → Position where the next valid element should be placed.
- `j` → Traverses the array.

The first **two elements** are always valid because every number can appear twice.

So,

```
i = 2
```

Now traverse from

```
j = 2
```

For every element,

compare it with

```
nums[i-2]
```

If

```
nums[j] != nums[i-2]
```

then the current element has appeared **less than two times**.

So,

- Copy it to index `i`
- Increment `i`

Otherwise,

ignore it because it would become the third occurrence.

Finally,

```
Return i
```

---

# 🔍 Dry Run

## Input

```
nums = [1,1,1,2,2,3]
```

Initially

```
i = 2
```

Array

```
Index

0 1 2 3 4 5

Value

1 1 1 2 2 3
```

---

## Step 1

```
j = 2
```

Compare

```
nums[j] = 1

nums[i-2] = nums[0] = 1
```

```
1 != 1 ?
```

No.

Third occurrence.

Ignore.

```
i = 2
```

Array

```
1 1 1 2 2 3
```

---

## Step 2

```
j = 3
```

Compare

```
nums[3] = 2

nums[0] = 1
```

```
2 != 1
```

Yes.

Copy

```
nums[2] = 2
```

Increment

```
i = 3
```

Array becomes

```
1 1 2 2 2 3
```

---

## Step 3

```
j = 4
```

Compare

```
nums[4] = 2

nums[1] = 1
```

```
2 != 1
```

Yes.

Copy

```
nums[3] = 2
```

Increment

```
i = 4
```

Array becomes

```
1 1 2 2 2 3
```

Now two occurrences of 2 are allowed.

---

## Step 4

```
j = 5
```

Compare

```
nums[5] = 3

nums[2] = 2
```

```
3 != 2
```

Yes.

Copy

```
nums[4] = 3
```

Increment

```
i = 5
```

Array becomes

```
1 1 2 2 3 3
```

Loop finishes.

---

## ✅ Final Answer

```
Length = 5
```

Valid Array

```
[1,1,2,2,3]
```

---

# 📄 Pen & Paper Table

| Step | i | j | Compare | Action | Valid Part |
|------|---|---|---------|--------|------------|
|Start|2|-|-|-|1 1|
|1|2|2|1==1|Ignore|1 1|
|2|3|3|2!=1|Copy 2|1 1 2|
|3|4|4|2!=1|Copy 2|1 1 2 2|
|4|5|5|3!=2|Copy 3|1 1 2 2 3|

---

## 🧠 Why Compare with `i-2`?

Suppose

```
Current Valid Array

1 1
```

The next element is

```
1
```

Compare with

```
nums[i-2]

↓

nums[0]

↓

1
```

Since both are equal,

this means two copies already exist.

So,

ignore the current element.

---

Suppose the valid array is

```
1 1 2 2
```

Next element

```
3
```

Compare

```
nums[i-2]

↓

nums[2]

↓

2
```

```
3 != 2
```

So 3 can safely be inserted.

---

## ⚠️ Edge Cases

### Case 1

```
[1,1]
```

Output

```
[1,1]
```

Already valid.

---

### Case 2

```
[2,2,2]
```

Output

```
[2,2]
```

Only two copies remain.

---

### Case 3

```
[1,2,3]
```

Output

```
[1,2,3]
```

No duplicates.

---

### Case 4

```
[5,5,5,5]
```

Output

```
[5,5]
```

Extra duplicates are removed.

---

## ⏱️ Time Complexity

```
O(N)
```

Only one traversal of the array.

---

## 💾 Space Complexity

```
O(1)
```

The array is modified in-place.

---

## 🎯 Key Learning

- This is an extension of the classic **Remove Duplicates** problem.
- The first **two elements** are always valid.
- `i` points to the next insertion position.
- `j` scans the remaining elements.
- Comparing with `nums[i-2]` ensures that no element appears more than twice.
- No extra array is required.
- This is the optimal in-place solution.