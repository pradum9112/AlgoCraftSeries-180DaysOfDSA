# Remove Duplicates from Sorted Array

## 📝 Problem Statement

Given a **sorted array**, remove the duplicate elements **in-place** such that each unique element appears only once.

Return the number of unique elements.

The first `k` elements of the array should contain all unique elements in sorted order.

---

## 💡 Approach

Since the array is already sorted, all duplicate elements appear together.

We use **Two Pointers**.

- `i` → Points to the last unique element.
- `j` → Traverses the entire array.

Initially,

```
i = 0
```

Now move `j` from index `1` to `n-1`.

Whenever

```
nums[j] != nums[i]
```

it means we found a new unique element.

So,

- Move `i` one step ahead.
- Copy the new element to index `i`.

Finally,

```
Number of unique elements = i + 1
```

---

# 🔍 Dry Run (Pen & Paper)

## Input

```
nums = [1,1,2,2,3,4,4,5]
```

Initially

```
i = 0
```

```
j starts from 1
```

Array

```
Index

0 1 2 3 4 5 6 7

Value

1 1 2 2 3 4 4 5
```

---

## Step 1

```
i = 0
j = 1
```

Compare

```
nums[i] = 1

nums[j] = 1
```

Same

Do nothing.

```
i = 0
```

---

## Step 2

```
j = 2
```

Compare

```
1

2
```

Different

Move i

```
i = 1
```

Copy

```
nums[1] = 2
```

Array becomes

```
1 2 2 2 3 4 4 5
```

---

## Step 3

```
j = 3
```

Compare

```
nums[i]=2

nums[j]=2
```

Same

Nothing changes.

---

## Step 4

```
j = 4
```

Compare

```
2

3
```

Different

```
i = 2
```

Copy

```
nums[2]=3
```

Array

```
1 2 3 2 3 4 4 5
```

---

## Step 5

```
j = 5
```

Compare

```
3

4
```

Different

```
i = 3
```

Copy

```
nums[3]=4
```

Array

```
1 2 3 4 3 4 4 5
```

---

## Step 6

```
j = 6
```

Compare

```
4

4
```

Same

Nothing changes.

---

## Step 7

```
j = 7
```

Compare

```
4

5
```

Different

```
i = 4
```

Copy

```
nums[4]=5
```

Final array

```
1 2 3 4 5 4 4 5
```

Only the first

```
i+1 = 5
```

elements are valid.

---

## ✅ Final Answer

Unique Length

```
5
```

Valid Array

```
[1,2,3,4,5]
```

---

# 📄 Pen & Paper Table

| Step | i | j | Compare | Action | Array (Valid Part) |
|------|---|---|---------|--------|--------------------|
|Start|0|-|-|-|1|
|1|0|1|1==1|Nothing|1|
|2|1|2|1!=2|Copy 2|1 2|
|3|1|3|2==2|Nothing|1 2|
|4|2|4|2!=3|Copy 3|1 2 3|
|5|3|5|3!=4|Copy 4|1 2 3 4|
|6|3|6|4==4|Nothing|1 2 3 4|
|7|4|7|4!=5|Copy 5|1 2 3 4 5|

---

## 🧠 Why does this work?

The array is sorted.

That means duplicates are always adjacent.

Whenever we find a different number,

we know it is the next unique element.

We simply move it next to the previous unique element.

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

Everything is done in-place.

---

## 🎯 Key Learning

- This is a classic **Two Pointer** problem.
- `i` always points to the last unique element.
- `j` scans the remaining array.
- We overwrite duplicates instead of creating a new array.
- The answer is always `i + 1`.