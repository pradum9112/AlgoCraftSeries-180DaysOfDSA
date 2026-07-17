# Most Frequent Element (Brute Force)

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

For every element in the array,

- Count how many times it appears by traversing the entire array again.
- Compare its frequency with the maximum frequency found so far.
- If the current frequency is greater, update the answer.
- If the frequencies are equal, choose the smaller element.

This is called the **Brute Force Approach** because every element is compared with every other element.

---

# 🧠 Dry Run (Code Wise)

## Input

```text
nums = [4, 5, 2, 5, 6, 7, 2, 2, 5]
```

Size

```cpp
n = 9
```

Initially

```cpp
max_appear = 0

result = -1
```

---

# First Outer Loop

```cpp
i = 0
```

Current element

```text
nums[i] = 4
```

Initialize

```cpp
count = 0;
```

---

### Inner Loop

Compare every element with **4**

| j | nums[j] | Equal? | count |
|:-:|:-------:|:------:|:-----:|
|0|4|✅|1|
|1|5|❌|1|
|2|2|❌|1|
|3|5|❌|1|
|4|6|❌|1|
|5|7|❌|1|
|6|2|❌|1|
|7|2|❌|1|
|8|5|❌|1|

Final

```text
count = 1
```

Check

```cpp
1 > 0
```

✅ True

Update

```text
max_appear = 1

result = 4
```

---

# Second Outer Loop

```cpp
i = 1
```

Current element

```text
nums[i] = 5
```

Count frequency

```text
5 appears 3 times
```

Now

```cpp
count = 3
```

Check

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

# Third Outer Loop

```cpp
i = 2
```

Current element

```text
nums[i] = 2
```

Count frequency

```text
2 appears 3 times
```

Now

```cpp
count = 3
```

Check

```cpp
count > max_appear
```

Means

```text
3 > 3
```

❌ False

Move to

```cpp
else if(count == max_appear)
```

Check

```text
3 == 3
```

✅ True

Now compare

```cpp
if(nums[i] < result)
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

Current

```text
max_appear = 3

result = 2
```

---

# Fourth Outer Loop

```cpp
i = 3
```

Current element

```text
nums[i] = 5
```

Frequency

```text
count = 3
```

Check

```text
3 > 3
```

❌ False

Tie

```text
3 == 3
```

✅ True

Compare

```text
5 < 2
```

❌ False

No update.

---

# Remaining Iterations

| Element | Frequency | Update? |
|:-------:|:---------:|:-------:|
|6|1|❌|
|7|1|❌|
|2|3|Tie → 2 < 2 ❌|
|2|3|Tie → 2 < 2 ❌|
|5|3|Tie → 5 < 2 ❌|

Final

```text
result = 2
```

Return

```cpp
return result;
```

---

# 🤔 Why is the same element counted multiple times?

Notice that the algorithm counts the frequency of **5** three different times because **5** appears three times.

Likewise, it counts the frequency of **2** three different times.

Example

```text
5 → Counted at i = 1

5 → Counted again at i = 3

5 → Counted again at i = 8
```

This repeated work is the main reason the algorithm is slow.

---

# 📊 Complexity Analysis

## Outer Loop

Runs for every element.

```text
N times
```

---

## Inner Loop

For each element, traverse the whole array again.

```text
N times
```

---

## Total Time Complexity

```text
O(N × N)

=

O(N²)
```

---

## Space Complexity

Only a few variables are used.

```text
count

max_appear

result
```

No extra array or hash map is created.

Therefore

```text
O(1)
```

---

# ⚖️ Brute Force vs Optimal

| Approach | Time | Space |
|:---------|:----:|:-----:|
| Brute Force | O(N²) | O(1) |
| Frequency Array | O(N) | O(1) |
| unordered_map | O(N) Average | O(N) |

---

# ⚠️ Common Mistakes

❌ Forgetting to reset

```cpp
count = 0;
```

inside the outer loop.

---

❌ Writing

```cpp
count++;
```

outside the `if` condition.

---

❌ Forgetting the tie-breaking condition.

---

❌ Returning the first maximum without checking for the smaller element.

---

# 📚 What I Learned

- How brute-force frequency counting works.
- Why nested loops lead to **O(N²)** time complexity.
- How to handle tie-breaking conditions.
- Why this solution performs repeated calculations.
- Why hashing or a frequency array is much more efficient.

---

# 📝 30-Second Revision Notes

✔ Pick one element.

✔ Count its frequency by traversing the entire array.

✔ Update the maximum frequency.

✔ If frequencies are equal, choose the smaller element.

✔ Repeat for every element.

✔ Time Complexity → **O(N²)**

✔ Space Complexity → **O(1)**

---

# 💡 Interview Takeaways

This solution is easy to understand but inefficient because it repeatedly counts the frequency of the same elements.

Example:

```text
Element 5

↓

Counted three different times.
```

A better approach is to calculate each element's frequency **once** using a **Frequency Array** or **`unordered_map`**, reducing the time complexity from **O(N²)** to **O(N)**.