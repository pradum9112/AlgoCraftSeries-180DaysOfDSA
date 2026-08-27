# Day 54 — Count Subarrays with XOR K

## 📌 Problem Statement

Given an array `nums` and an integer `k`, count the number of subarrays whose XOR is equal to `k`.

---

## 🧪 Example

### Input

```text
5 6
4 2 2 6 4
```

### Your Output

```text
4
```

### Explanation

The subarrays having XOR `6` are:

```text
[4, 2]

[2, 2, 6]

[6]

[2, 6, 4]
```

Therefore:

```text
Answer = 4
```

---

# Approach 1 — Brute Force

## 💡 Idea

Generate every possible subarray using two loops:

```text
i → starting point
j → ending point
```

Then use a third loop to calculate the XOR of that subarray.

```cpp
for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {

        int current_xr = 0;

        for (int p = i; p <= j; p++) {
            current_xr = current_xr ^ nums[p];
        }

    }
}
```

If:

```text
current_xr == k
```

then increase `count`.

## Complexity

```text
Time  = O(n³)
Space = O(1)
```

---

# Approach 2 — Better: Running XOR

## 💡 Observation

In the brute-force approach, we repeatedly calculate XOR from `i` to `j`.

Instead, once `i` is fixed, maintain a running XOR.

```cpp
current_xr = current_xr ^ nums[j];
```

So:

```text
i fixed
   ↓
j moves →
   ↓
XOR keeps updating
```

Example:

```text
nums = [4, 2, 2]
```

For `i = 0`:

```text
j = 0

XOR = 0 ^ 4
    = 4
```

Next:

```text
j = 1

XOR = 4 ^ 2
    = 6
```

Next:

```text
j = 2

XOR = 6 ^ 2
    = 4
```

No third loop is needed.

## Complexity

```text
Time  = O(n²)
Space = O(1)
```

---

# Approach 3 — Optimal: Prefix XOR + HashMap

## ⭐ Main Idea

Exactly like Prefix Sum problems, but here we use **XOR instead of addition**.

Maintain:

```text
prefix XOR
```

Let current prefix XOR be:

```text
xr
```

We want some previous prefix XOR `x` such that:

```text
x XOR xr = k
```

Using XOR property:

```text
x = xr XOR k
```

Therefore we search:

```cpp
int x = xr ^ k;
```

in the HashMap.

---

# 🧠 XOR Property Used

The important property is:

```text
A ^ A = 0
```

and:

```text
A ^ 0 = A
```

Most importantly:

```text
A ^ B = C
```

can be rearranged as:

```text
A = B ^ C
```

because:

```text
B ^ C
= B ^ (A ^ B)
= A
```

This is why:

```cpp
int x = xr ^ k;
```

works.

---

# 🔍 Pattern Recognition Clue

## 🚨 When should you think of Prefix XOR + HashMap?

Look for these words:

```text
"Count subarrays"
        +
"XOR"
        +
"XOR equals K"
```

That should immediately make you think:

```text
Prefix XOR
      ↓
HashMap
      ↓
Previous XOR = current XOR ^ K
```

### Strong pattern:

If the problem says:

> **Count the number of subarrays with XOR equal to K**

your brain should recognize:

```text
Subarray + XOR + Count
          ↓
Prefix XOR + HashMap
```

---

# 🔗 Connection With Day53

This is very important because Day53 and Day54 are closely related.

### Day53

```text
Longest Subarray with Sum 0
```

We used:

```text
Prefix Sum + HashMap
```

Same prefix sum again means:

```text
middle sum = 0
```

### Day54

```text
Count Subarrays with XOR K
```

We use:

```text
Prefix XOR + HashMap
```

Previous XOR needed:

```text
current XOR ^ K
```

So don't learn Day54 as a completely new problem.

Think:

```text
DAY53
Prefix Sum
     ↓
HashMap
     ↓
Same prefix sum
```

```text
DAY54
Prefix XOR
     ↓
HashMap
     ↓
Find prefix XOR ^ K
```

---

# 🧠 Optimal Dry Run

Input:

```text
nums = [4, 2, 2, 6, 4]
k = 6
```

Initially:

```text
xr = 0
count = 0
```

HashMap:

```text
{0 : 1}
```

Why `0 : 1`?

Because before processing any element, prefix XOR is `0`.

---

## i = 0

```text
num = 4

xr = 0 ^ 4
   = 4
```

Required previous XOR:

```text
x = xr ^ k
  = 4 ^ 6
  = 2
```

Is `2` in map?

```text
NO
```

Store:

```text
4 → 1
```

---

## i = 1

```text
num = 2

xr = 4 ^ 2
   = 6
```

Required:

```text
x = 6 ^ 6
  = 0
```

Map contains:

```text
0 → 1
```

Therefore:

```text
count += 1
```

We found:

```text
[4, 2]
```

because:

```text
4 ^ 2 = 6
```

Then store:

```text
6 → 1
```

---

## i = 2

```text
num = 2

xr = 6 ^ 2
   = 4
```

Required:

```text
x = 4 ^ 6
  = 2
```

Map does not contain `2`.

Store:

```text
4 → 2
```

---

## i = 3

```text
num = 6

xr = 4 ^ 6
   = 2
```

Required:

```text
x = 2 ^ 6
  = 4
```

Map contains:

```text
4 → 2
```

Therefore:

```text
count += 2
```

Two valid subarrays end at this index.

They are:

```text
[2, 2, 6]
```

and:

```text
[6]
```

Now:

```text
count = 3
```

Store:

```text
2 → 1
```

---

## i = 4

```text
num = 4

xr = 2 ^ 4
   = 6
```

Required:

```text
x = 6 ^ 6
  = 0
```

Map contains:

```text
0 → 1
```

Therefore:

```text
count += 1
```

The additional subarray is:

```text
[2, 6, 4]
```

Final:

```text
count = 4
```

---

# ⭐ Why `mpp[0] = 1`?

This is the **base case**.

Suppose:

```text
nums = [6]
k = 6
```

At first:

```text
xr = 6
```

Required:

```text
x = 6 ^ 6
  = 0
```

We need `0` to already exist in the map.

That's why:

```cpp
mpp[0] = 1;
```

This represents:

```text
Before array starts:
prefix XOR = 0
```

Without this, subarrays starting from index `0` would be missed.

---

# 📊 Comparison

| Approach    |         Time | Space | Technique            |
| ----------- | -----------: | ----: | -------------------- |
| Brute Force |        O(n³) |  O(1) | 3 loops              |
| Better      |        O(n²) |  O(1) | Running XOR          |
| Optimal     | O(n) average |  O(n) | Prefix XOR + HashMap |

---

# 🧠 Final Pattern

```text
Current Prefix XOR = xr
             ↓
Need previous XOR = xr ^ k
             ↓
Search in HashMap
             ↓
Found?
             ↓
count += frequency
```

The most important line:

```cpp
int x = xr ^ k;
```

### Remember:

```text
SUM problem
→ Prefix Sum

XOR problem
→ Prefix XOR
```

And when the problem asks to **count subarrays**, HashMap frequency becomes especially useful.

---

# 🎯 Day54 Learning

* Brute Force → three loops.
* Better → running XOR reduces one loop.
* Optimal → Prefix XOR + HashMap.
* `A ^ A = 0`
* `A ^ 0 = A`
* Required previous XOR = `current XOR ^ K`.
* `mpp[0] = 1` handles subarrays starting from index `0`.
* HashMap stores **frequency**, not just first index, because multiple previous prefixes can produce valid subarrays.
* Day53's Prefix Sum pattern connects directly to Day54's Prefix XOR pattern.

## 🔥 Pattern Recognition

```text
Subarray
+
XOR
+
Count
        ↓
Prefix XOR + HashMap
```
