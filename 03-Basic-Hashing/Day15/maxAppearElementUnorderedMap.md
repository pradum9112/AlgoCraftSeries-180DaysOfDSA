# Most Frequent Element (Using `unordered_map`)

## 📌 Problem Statement

Given an integer array `nums`, return the element that appears **the maximum number of times**.

If two or more elements have the same highest frequency, return the **smallest element** among them.

---

## 📝 Example

### Input

```text
nums = [4, 5, 2, 5, 6, 7, 2, 2, 5]
```

### Output

```text
2
```

### Explanation

| Element | Frequency |
|:-------:|:---------:|
| 2 | 3 |
| 4 | 1 |
| 5 | 3 |
| 6 | 1 |
| 7 | 1 |

Both **2** and **5** have the highest frequency (**3**).

Since **2** is smaller than **5**, the answer is **2**.

---

# 💡 Approach

The problem can be solved in two steps:

### Step 1

Count the frequency of every element using an **unordered_map**.

### Step 2

Traverse the hash map and keep track of

- Maximum frequency found so far.
- Corresponding element.

If another element has the **same frequency**, choose the **smaller element**.

---

# 🧠 Dry Run (Code Wise)

## Input

```text
nums = [4, 5, 2, 5, 6, 7, 2, 2, 5]
```

---

## Step 1 : Create Hash Map

```cpp
unordered_map<int,int> mpp;
```

Initially

```text
mpp = { }
```

---

## Step 2 : Count Frequencies

```cpp
for(int i : nums)
    mpp[i]++;
```

### Iteration 1

```cpp
i = 4
```

Execute

```cpp
mpp[4]++;
```

Hash Map

```text
4 → 1
```

---

### Iteration 2

```cpp
i = 5
```

Execute

```cpp
mpp[5]++;
```

Hash Map

```text
4 → 1

5 → 1
```

---

### Iteration 3

```cpp
i = 2
```

Execute

```cpp
mpp[2]++;
```

Hash Map

```text
4 → 1

5 → 1

2 → 1
```

---

### Iteration 4

```cpp
i = 5
```

Execute

```cpp
mpp[5]++;
```

Hash Map

```text
4 → 1

5 → 2

2 → 1
```

---

### Iteration 5

```cpp
i = 6
```

Execute

```cpp
mpp[6]++;
```

Hash Map

```text
4 → 1

5 → 2

2 → 1

6 → 1
```

---

### Iteration 6

```cpp
i = 7
```

Execute

```cpp
mpp[7]++;
```

Hash Map

```text
4 → 1

5 → 2

2 → 1

6 → 1

7 → 1
```

---

### Iteration 7

```cpp
i = 2
```

Execute

```cpp
mpp[2]++;
```

Hash Map

```text
4 → 1

5 → 2

2 → 2

6 → 1

7 → 1
```

---

### Iteration 8

```cpp
i = 2
```

Execute

```cpp
mpp[2]++;
```

Hash Map

```text
4 → 1

5 → 2

2 → 3

6 → 1

7 → 1
```

---

### Iteration 9

```cpp
i = 5
```

Execute

```cpp
mpp[5]++;
```

Final Hash Map

```text
2 → 3

4 → 1

5 → 3

6 → 1

7 → 1
```

---

# Step 3 : Initialize Variables

```cpp
int max_appear = 0;
int result = -1;
```

Initially

```text
max_appear = 0

result = -1
```

---

# Step 4 : Traverse the Hash Map

```cpp
for(auto it : mpp)
```

Suppose the map is traversed like this

```text
4 → 1

5 → 3

2 → 3

6 → 1

7 → 1
```

> **Note:** `unordered_map` does not guarantee traversal order. The logic works correctly regardless of the order.

---

### Visit

```text
4 → 1
```

Condition

```cpp
if(it.second > max_appear)
```

Means

```text
1 > 0
```

✅ True

Update

```text
max_appear = 1

result = 4
```

---

### Visit

```text
5 → 3
```

Condition

```text
3 > 1
```

✅ True

Update

```text
max_appear = 3

result = 5
```

---

### Visit

```text
2 → 3
```

Condition

```text
3 > 3
```

❌ False

Move to

```cpp
else if(it.second == max_appear)
```

Check

```text
3 == 3
```

✅ True

Now compare

```cpp
if(it.first < result)
```

Means

```text
2 < 5
```

✅ True

Update

```text
result = 2
```

Current Values

```text
max_appear = 3

result = 2
```

---

### Visit

```text
6 → 1
```

Condition

```text
1 > 3
```

❌ False

No update.

---

### Visit

```text
7 → 1
```

Condition

```text
1 > 3
```

❌ False

No update.

---

# Final Answer

```cpp
return result;
```

Returns

```text
2
```

---

# 📊 Complexity Analysis

## Step 1 : Build Frequency Map

Traverse the array once.

```text
O(N)
```

---

## Step 2 : Traverse Hash Map

Suppose there are **K unique elements**.

```text
O(K)
```

Since

```text
K ≤ N
```

Overall Complexity

```text
O(N)
```

---

## ✅ Time Complexity

```text
O(N)
```

---

## ✅ Space Complexity

The hash map stores every unique element.

Worst case

```text
All elements are unique.
```

Hash Map Size

```text
N
```

Therefore

```text
O(N)
```

---

# ⚖️ Brute Force vs Hashing

| Approach | Time Complexity | Space Complexity |
|:---------|:---------------:|:----------------:|
| Brute Force | O(N²) | O(1) |
| unordered_map | O(N) | O(N) |

---

# ⚠️ Common Mistakes

❌ Forgetting to count frequencies before finding the answer.

❌ Returning the first maximum element without checking the tie condition.

❌ Using `>=` instead of `>` for updating the maximum frequency.

❌ Forgetting to compare the element values when frequencies are equal.

---

# 📚 What I Learned

- How to count frequencies efficiently using `unordered_map`.
- How to solve tie-breaking problems.
- How to update the answer while traversing a hash map.
- Why hashing reduces the complexity from **O(N²)** to **O(N)**.

---

# 📝 30-Second Revision Notes

✔ Build a frequency table using `unordered_map`.

✔ Traverse the map.

✔ Track:
- Maximum frequency
- Corresponding element

✔ If frequencies are equal, choose the **smaller element**.

✔ Time Complexity → **O(N)**

✔ Space Complexity → **O(N)**

---

# 💡 Interview Takeaways

Whenever a problem involves:

- Most frequent element
- Least frequent element
- Frequency comparison
- Tie-breaking
- Counting occurrences

👉 Think of **Hashing (`unordered_map`)** first.

> **Key Insight:** Build the frequency table in one traversal, then scan it once to find the answer. This two-pass hashing pattern is one of the most frequently used techniques in coding interviews.