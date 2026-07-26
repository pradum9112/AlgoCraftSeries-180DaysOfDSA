# Second Largest Element in an Array

## 📝 Problem Statement

Given an array of integers `nums`, return the **second largest distinct element** in the array.

If the second largest element does not exist, return **-1**.

---

## 💡 Approach

We maintain two variables throughout the traversal.

- **maxElement** → stores the largest element found so far.
- **secondMax** → stores the second largest distinct element.

Initially,

- maxElement = first element
- secondMax = -1

For every element:

### Case 1

If current element is greater than maxElement,

- current maximum becomes second maximum.
- current element becomes new maximum.

### Case 2

Otherwise,

If current element is

- smaller than maxElement
- greater than secondMax

then update secondMax.

Finally return secondMax.

---

## 🔍 Dry Run

### Input

```
nums = [8, 2, 5, 6, 8, 1]
```

Initially

```
maxElement = 8
secondMax = -1
```

---

### i = 0

Current = 8

```
8 > 8 ?
No
```

```
8 < 8 ?
No
```

No changes.

```
maxElement = 8
secondMax = -1
```

---

### i = 1

Current = 2

```
2 > 8 ?
No
```

```
2 < 8 && 2 > -1 ?
Yes
```

Update

```
secondMax = 2
```

Current state

```
maxElement = 8
secondMax = 2
```

---

### i = 2

Current = 5

```
5 > 8 ?
No
```

```
5 < 8 && 5 > 2 ?
Yes
```

Update

```
secondMax = 5
```

Current state

```
maxElement = 8
secondMax = 5
```

---

### i = 3

Current = 6

```
6 > 8 ?
No
```

```
6 < 8 && 6 > 5 ?
Yes
```

Update

```
secondMax = 6
```

Current state

```
maxElement = 8
secondMax = 6
```

---

### i = 4

Current = 8

```
8 > 8 ?
No
```

```
8 < 8 ?
No
```

Duplicate maximum.

Nothing changes.

```
maxElement = 8
secondMax = 6
```

---

### i = 5

Current = 1

```
1 > 8 ?
No
```

```
1 > 6 ?
No
```

No update.

---

## ✅ Final Answer

```
Second Largest = 6
```

---

## ⚠️ Edge Cases

### Case 1

```
[5,5,5]
```

Output

```
-1
```

Reason

No second largest distinct element exists.

---

### Case 2

```
[10]
```

Output

```
-1
```

Only one element.

---

### Case 3

```
[7,6]
```

Output

```
6
```

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

Only two extra variables are used.

---

## 🎯 Key Learning

- Track the largest and second largest together.
- Ignore duplicate maximum values.
- A single traversal is enough.
- No sorting is required.
- This is the optimal solution for finding the second largest element.