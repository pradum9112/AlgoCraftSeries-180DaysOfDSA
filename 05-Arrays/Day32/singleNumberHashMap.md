# 📘 Day 32 - Single Number (Hashing)

## 🔹 Problem Statement

Given an integer array `nums`, every element appears **twice** except for one element, which appears **only once**.

Return that single element.

### Example 1

**Input**

```
nums = [2,2,1]
```

**Output**

```
1
```

---

### Example 2

**Input**

```
nums = [4,1,2,1,2]
```

**Output**

```
4
```

---

# 💡 Approach (Using Hash Map)

Create a frequency map.

- Traverse the array.
- Store frequency of every element.
- Traverse the map.
- The element whose frequency is **1** is the answer.

---

# 📝 Dry Run

## Input

```
nums = [4,1,2,1,2]
```

Initially

```
mp = { }
```

---

### Step 1

```
Read 4
```

```
mp[4]++

mp =

4 → 1
```

---

### Step 2

```
Read 1
```

```
mp =

4 → 1
1 → 1
```

---

### Step 3

```
Read 2
```

```
mp =

4 → 1
1 → 1
2 → 1
```

---

### Step 4

```
Read 1
```

```
mp =

4 → 1
1 → 2
2 → 1
```

---

### Step 5

```
Read 2
```

```
mp =

4 → 1
1 → 2
2 → 2
```

---

Now traverse the map.

```
4 → 1 ✅

Answer = 4
```

---

# ⏱️ Time Complexity

Building Hash Map

```
O(n)
```

Traversing Hash Map

```
O(n)
```

Overall

```
Time Complexity = O(n)
```

---

# 📦 Space Complexity

Hash map stores frequencies.

```
Space Complexity = O(n)
```

---

# 📚 Learning

### Pattern

- Hashing
- Frequency Counting

### Why O(n)?

Every element is visited only once.

### Can it be optimized?

Yes.

Instead of using extra space, we can solve it using **XOR**.

That gives

```
Time Complexity = O(n)

Space Complexity = O(1)
```

So XOR is the Optimal Solution.