# Most Frequent Element (Using Frequency Array)

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

Both **2** and **5** appear **3** times.

Since **2** is smaller, the answer is **2**.

---

# 💡 Approach

Since the values are limited from **1 to 10000**, we can directly use an array where:

```text
Index  → Number

Value  → Frequency
```

Instead of storing frequencies in a hash map, every number directly becomes an index of the frequency array.

---

# 🧠 Dry Run (Code Wise)

## Input

```text
nums = [4, 5, 2, 5, 6, 7, 2, 2, 5]
```

---

## Step 1 : Create Frequency Array

```cpp
vector<int> freq(10001,0);
```

Initially every value is 0.

```text
Index : 0 1 2 3 4 5 6 7 ...

Value : 0 0 0 0 0 0 0 0 ...
```

---

## Step 2 : Count Frequencies

```cpp
for(int num : nums)
    freq[num]++;
```

Let's see every iteration.

---

### Iteration 1

```cpp
num = 4
```

Execute

```cpp
freq[4]++;
```

Frequency Array

```text
freq[4] = 1
```

---

### Iteration 2

```cpp
num = 5
```

Execute

```cpp
freq[5]++;
```

Frequency Array

```text
freq[4] = 1

freq[5] = 1
```

---

### Iteration 3

```cpp
num = 2
```

Execute

```cpp
freq[2]++;
```

Frequency Array

```text
freq[2] = 1

freq[4] = 1

freq[5] = 1
```

---

### Iteration 4

```cpp
num = 5
```

Execute

```cpp
freq[5]++;
```

Frequency Array

```text
freq[5] = 2
```

---

### Iteration 5

```cpp
num = 6
```

Execute

```cpp
freq[6]++;
```

Frequency Array

```text
freq[6] = 1
```

---

### Iteration 6

```cpp
num = 7
```

Execute

```cpp
freq[7]++;
```

Frequency Array

```text
freq[7] = 1
```

---

### Iteration 7

```cpp
num = 2
```

Execute

```cpp
freq[2]++;
```

Frequency Array

```text
freq[2] = 2
```

---

### Iteration 8

```cpp
num = 2
```

Execute

```cpp
freq[2]++;
```

Frequency Array

```text
freq[2] = 3
```

---

### Iteration 9

```cpp
num = 5
```

Execute

```cpp
freq[5]++;
```

Final Frequency Array

```text
freq[2] = 3

freq[4] = 1

freq[5] = 3

freq[6] = 1

freq[7] = 1
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

# Step 4 : Traverse Frequency Array

```cpp
for(int i = 1; i <= 10000; i++)
```

The loop checks every possible number.

Only these indices have non-zero frequency.

---

### When i = 2

```text
freq[2] = 3
```

Condition

```cpp
if(freq[2] > max_appear)
```

Means

```text
3 > 0
```

✅ True

Update

```text
max_appear = 3

result = 2
```

---

### When i = 4

```text
freq[4] = 1
```

Condition

```text
1 > 3
```

❌ False

No update.

---

### When i = 5

```text
freq[5] = 3
```

Condition

```text
3 > 3
```

❌ False

Notice that the condition uses **>** instead of **>=**.

Therefore **result remains 2**.

This automatically handles the tie.

---

### When i = 6

```text
freq[6] = 1
```

Condition

```text
1 > 3
```

❌ False

---

### When i = 7

```text
freq[7] = 1
```

Condition

```text
1 > 3
```

❌ False

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

# 🤔 Why does Tie-Breaking work automatically?

Suppose

```text
freq[2] = 3

freq[5] = 3
```

The loop runs from

```text
1 → 10000
```

So

```text
2
```

is visited first.

It becomes the answer.

Later

```text
5
```

also has frequency **3**.

Condition checks

```text
3 > 3
```

which is **False**.

So **5 never replaces 2**.

Hence, the smaller element is automatically returned without writing any extra `else if` condition.

---

# 📊 Complexity Analysis

## Step 1 : Build Frequency Array

Traverse the input array once.

```text
O(N)
```

---

## Step 2 : Traverse Frequency Array

The frequency array size is fixed.

```text
10000
```

So

```text
O(10000)
```

Since **10000 is a constant**, we treat it as

```text
O(1)
```

---

## ✅ Overall Time Complexity

```text
O(N)
```

---

## ✅ Space Complexity

Frequency Array Size

```text
10001
```

which is fixed.

Therefore

```text
O(1)
```

(Constant Extra Space)

---

# ⚖️ Frequency Array vs unordered_map

| Feature | Frequency Array | unordered_map |
|:---------|:---------------:|:-------------:|
| Time Complexity | O(N) | O(N) Average |
| Space Complexity | O(1) | O(N) |
| Supports Large Values | ❌ | ✅ |
| Supports Negative Values | ❌ | ✅ |
| Lookup Time | O(1) | O(1) Average |

---

# ⚠️ Common Mistakes

❌ Creating a frequency array smaller than the maximum possible value.

❌ Using `>=` instead of `>`.

❌ Forgetting that array indexing starts from **0**.

❌ Using this approach when numbers can be very large or negative.

---

# 📚 What I Learned

- How frequency arrays work.
- When frequency arrays are better than hashing.
- Why tie-breaking happens automatically by traversing from left to right.
- Why no extra condition is needed to choose the smaller element.

---

# 📝 30-Second Revision Notes

✔ Create a frequency array.

✔ Count occurrences.

✔ Traverse from **1 to 10000**.

✔ Update answer only if frequency becomes strictly larger.

✔ Tie is handled automatically because the smaller number is visited first.

✔ Time Complexity → **O(N)**

✔ Space Complexity → **O(1)**

---

# 💡 Interview Takeaways

Use a **Frequency Array** when:

- Values lie in a **small, fixed range**.
- Fast lookup is required.
- Constant extra space is acceptable.

Otherwise, prefer **`unordered_map`** for large or unknown ranges.

> **Key Insight:** A frequency array is often faster than `unordered_map` because it avoids hashing overhead and provides direct indexing. When the value range is small and fixed, it is one of the most efficient counting techniques.