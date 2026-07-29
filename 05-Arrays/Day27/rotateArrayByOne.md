# Rotate Array by One Position (Left Rotation)

## 📝 Problem Statement

Given an array `nums` of size `N`, rotate the array by **one position towards the left**.

The first element should move to the last position.

The rotation must be performed **in-place**.

---

## Example

### Input

```
nums = [1,2,3,4,5]
```

### Output

```
[2,3,4,5,1]
```

---

## 💡 Approach

Store the first element in a temporary variable.

```
temp = nums[0]
```

Now shift every element one position towards the left.

```
nums[i] = nums[i+1]
```

Finally,

place the stored first element at the last position.

```
nums[n-1] = temp
```

No extra array is required.

---

# 🔍 Dry Run

## Input

```
nums = [1,2,3,4,5]
```

Initially

```
temp = 1
```

Array

```
1 2 3 4 5
```

---

## Iteration 1

```
i = 0
```

```
nums[0] = nums[1]
```

Array

```
2 2 3 4 5
```

---

## Iteration 2

```
i = 1
```

```
nums[1] = nums[2]
```

Array

```
2 3 3 4 5
```

---

## Iteration 3

```
i = 2
```

```
nums[2] = nums[3]
```

Array

```
2 3 4 4 5
```

---

## Iteration 4

```
i = 3
```

```
nums[3] = nums[4]
```

Array

```
2 3 4 5 5
```

---

Loop finishes.

Now place the saved element.

```
nums[4] = temp
```

Array becomes

```
2 3 4 5 1
```

---

## ✅ Final Answer

```
[2,3,4,5,1]
```

---

# 📄 Pen & Paper Table

| Step | temp | Operation | Array |
|------|------|-----------|-------|
|Start|1|Store first element|1 2 3 4 5|
|1|1|nums[0]=nums[1]|2 2 3 4 5|
|2|1|nums[1]=nums[2]|2 3 3 4 5|
|3|1|nums[2]=nums[3]|2 3 4 4 5|
|4|1|nums[3]=nums[4]|2 3 4 5 5|
|End|1|nums[4]=temp|2 3 4 5 1|

---

## 🧠 Why does this work?

Before shifting, we save the first element.

Then every element moves one position to the left.

After shifting, the last position becomes empty.

Finally, we place the saved first element there.

Thus, the array gets rotated by one position.

---

## ⚠️ Edge Cases

### Case 1

```
[5]
```

Output

```
[5]
```

---

### Case 2

```
[]
```

Output

```
[]
```

---

### Case 3

```
[7,8]
```

Output

```
[8,7]
```

---

## ⏱️ Time Complexity

```
O(N)
```

Each element is shifted exactly once.

---

## 💾 Space Complexity

```
O(1)
```

Only one temporary variable is used.

---

## 🎯 Key Learning

- In-place left rotation by one position.
- Save the first element before shifting.
- Shift all elements left.
- Place the saved element at the last index.
- No extra array is required.