# Day 57 — Find Missing and Repeating Numbers

## 📌 Problem Statement

Given an array containing numbers from `1` to `N`, exactly:

* one number appears **twice**
* one number is **missing**

Find both numbers.

Return:

```text
[Repeating, Missing]
```

---

## 🧪 Example

### Input

```text
5
1 2 2 4 5
```

### Your Output

```text
Repeating: 2
Missing: 3
```

---

# 🔍 Pattern Recognition Clue

When you see:

```text
Numbers from 1 to N
+
One repeated
+
One missing
```

Think:

```text
FREQUENCY / COUNTING
```

Possible approaches:

```text
Brute Force
    ↓
Frequency Array / HashMap
    ↓
Mathematical / XOR optimization
```

### Important clue

Because numbers are from `1 → N`, we can use the number itself as an index:

```text
number 2 → freq[2]
number 5 → freq[5]
```

This makes a **frequency array** a natural solution.

---

# Approach 1 — Brute Force

## 💡 Idea

Check every expected number from:

```text
1 → N
```

For every number, scan the complete array and count how many times it occurs.

Example:

```text
nums = [1, 2, 2, 4, 5]
```

Check:

```text
1 → appears 1 time
2 → appears 2 times → Repeating
3 → appears 0 times → Missing
4 → appears 1 time
5 → appears 1 time
```

Therefore:

```text
Repeating = 2
Missing = 3
```

### Complexity

```text
Time  = O(N²)
Space = O(1)
```

---

# Approach 2 — Frequency Array

## 💡 Idea

Create:

```cpp
vector<int> freq(n + 1, 0);
```

Why `n + 1`?

Because our numbers are:

```text
1, 2, 3, ..., N
```

We want:

```text
freq[1]
freq[2]
freq[3]
...
freq[N]
```

Index `0` is simply unused.

---

## Step 1 — Count Frequency

For every number:

```cpp
freq[num]++;
```

Example:

```text
nums = [1, 2, 2, 4, 5]
```

Frequency:

```text
Number:  1  2  3  4  5
Freq:    1  2  0  1  1
```

---

## Step 2 — Find Repeating

If:

```text
freq[i] == 2
```

then:

```text
i = repeating
```

---

## Step 3 — Find Missing

If:

```text
freq[i] == 0
```

then:

```text
i = missing
```

---

# 🧠 Dry Run

Input:

```text
nums = [1, 2, 2, 4, 5]
n = 5
```

Expected:

```text
1 2 3 4 5
```

Create:

```text
freq = [0, 0, 0, 0, 0, 0]
```

Process `1`:

```text
freq[1]++

freq = [0, 1, 0, 0, 0, 0]
```

Process first `2`:

```text
freq[2]++

freq = [0, 1, 1, 0, 0, 0]
```

Process second `2`:

```text
freq[2]++

freq = [0, 1, 2, 0, 0, 0]
```

Process `4`:

```text
freq = [0, 1, 2, 0, 1, 0]
```

Process `5`:

```text
freq = [0, 1, 2, 0, 1, 1]
```

Now scan:

```text
i = 1 → freq[1] = 1 → normal
i = 2 → freq[2] = 2 → REPEATING
i = 3 → freq[3] = 0 → MISSING
i = 4 → freq[4] = 1 → normal
i = 5 → freq[5] = 1 → normal
```

Final:

```text
Repeating = 2
Missing = 3
```

---

# 📊 Comparison

| Approach        |  Time | Space |
| --------------- | ----: | ----: |
| Brute Force     | O(N²) |  O(1) |
| Frequency Array |  O(N) |  O(N) |

---

# 🎯 What You Learned

### Brute Force

```text
Expected number
      ↓
Scan complete array
      ↓
Count
```

### Frequency Array

```text
Number
   ↓
Use number as index
   ↓
freq[number]++
   ↓
freq == 2 → Repeating
freq == 0 → Missing
```

---

# 🧩 Pattern Recognition

Remember this pattern:

```text
"1 to N + missing/repeating"
            ↓
       COUNT/FREQUENCY
```

And because:

```text
Value range = 1 → N
```

you should immediately consider:

```text
Value as Index
```

---

# 🚀 Next Optimization

The frequency-array solution uses:

```text
O(N) extra space
```

There are more space-efficient approaches using:

* Mathematical equations
* XOR

The XOR approach is especially useful when the problem asks for:

```text
O(N) time
O(1) extra space
```

That is the next optimization to learn.
