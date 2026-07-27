# Check if an Array is Sorted

## 📝 Problem Statement

Given an integer array `nums`, check whether the array is sorted in **non-decreasing order**.

Return:

- `true` if the array is sorted.
- `false` otherwise.

A non-decreasing array means every element is **greater than or equal to** its previous element.

---

## 💡 Approach

The idea is very simple.

We compare every element with its next element.

If at any position,

```
nums[i] > nums[i + 1]
```

then the array is **not sorted**, so we immediately return `false`.

If we complete the entire traversal without finding such a pair, the array is sorted and we return `true`.

This solution requires only one traversal of the array.

---

## 🔍 Dry Run

### Input

```
nums = [1, 2, 3, 4, 5]
```

Loop runs from

```
i = 0
```

to

```
i = n-2
```

because we compare with `i+1`.

---

### i = 0

Compare

```
nums[0] = 1
nums[1] = 2
```

Check

```
1 > 2 ?
```

No.

Move ahead.

---

### i = 1

Compare

```
nums[1] = 2
nums[2] = 3
```

Check

```
2 > 3 ?
```

No.

Move ahead.

---

### i = 2

Compare

```
nums[2] = 3
nums[3] = 4
```

Check

```
3 > 4 ?
```

No.

Move ahead.

---

### i = 3

Compare

```
nums[3] = 4
nums[4] = 5
```

Check

```
4 > 5 ?
```

No.

Loop finishes.

---

## ✅ Final Answer

```
true
```

The array is sorted.

---

# Another Dry Run

### Input

```
nums = [2, 4, 7, 5, 8]
```

Initially

```
i = 0
```

---

### i = 0

```
2 > 4 ?
```

No.

---

### i = 1

```
4 > 7 ?
```

No.

---

### i = 2

Compare

```
7
5
```

Check

```
7 > 5 ?
```

Yes.

Immediately return

```
false
```

No need to check the remaining elements.

---

## ⚠️ Edge Cases

### Case 1

```
[5]
```

Output

```
true
```

A single element is always sorted.

---

### Case 2

```
[3,3,3]
```

Output

```
true
```

Equal elements are allowed because the array is **non-decreasing**.

---

### Case 3

```
[9,8,7]
```

Output

```
false
```

The first comparison itself fails.

---

## ⏱️ Time Complexity

```
O(N)
```

We traverse the array only once.

---

## 💾 Space Complexity

```
O(1)
```

No extra data structure is used.

---

## 🎯 Why is this Optimal?

- Only one traversal of the array.
- Stops immediately when an unsorted pair is found.
- No sorting is performed.
- Constant extra memory.

---

## 📚 Key Learning

- Compare every element with its next element.
- If one pair violates the sorted order, the entire array becomes unsorted.
- Early return improves performance in many cases.
- Always loop till `n - 2` because we compare `i` with `i + 1`.