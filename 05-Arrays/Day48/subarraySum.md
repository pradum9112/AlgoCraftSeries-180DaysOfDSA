# 📘 Day 48 — Subarray Sum Equals K

## Problem Statement

Given an integer array `nums` and an integer `k`, find the **total number of continuous subarrays** whose sum is exactly equal to `k`.

---

## Example

### Input

```text
5 2
1 1 1 1 1
```

Here:

```text
n = 5
k = 2
```

Subarrays having sum `2`:

```text
[1, 1] → indices 0-1
[1, 1] → indices 1-2
[1, 1] → indices 2-3
[1, 1] → indices 3-4
```

Therefore:

```text
Output = 4
```

---

# Approach 1 — Brute Force

The most direct way is to generate every possible subarray and calculate its sum.

We use three loops:

```text
i → starting point

j → ending point

K → calculate sum from i to j
```

Conceptually:

```text
i
 ↓
[ start ]

j
 ↓
[ end ]

K
 ↓
calculate sum
```

Code:

```cpp
for (int i = 0; i < n; i++) {

    for (int j = i; j < n; j++) {

        int sum = 0;

        for (int K = i; K <= j; K++) {
            sum += nums[K];
        }

        if (sum == k) {
            count++;
        }
    }
}
```

## Complexity

```text
Time = O(n³)
Space = O(1)
```

---

# Approach 2 — Better: Running Sum

We notice something unnecessary in the brute-force solution.

Suppose:

```text
nums = [1, 2, 3]
```

For:

```text
i = 0
```

we calculate:

```text
[1]       → 1
[1,2]     → 3
[1,2,3]   → 6
```

Instead of calculating the complete sum again, keep a running sum.

```cpp
int sum = 0;

for (int j = i; j < n; j++) {

    sum += nums[j];

    if (sum == k) {
        count++;
    }
}
```

So:

```text
sum
 ↓
1
 ↓
1 + 2 = 3
 ↓
1 + 2 + 3 = 6
```

We removed one loop.

## Complexity

```text
Time = O(n²)
Space = O(1)
```

---

# Approach 3 — Optimal: Prefix Sum + HashMap

Now we try to remove the second loop as well.

The key idea is **prefix sum**.

Suppose:

```text
nums = [1, 2, 3]
```

Prefix sums are:

```text
1
3
6
```

Meaning:

```text
1          = 1

1 + 2      = 3

1 + 2 + 3  = 6
```

---

# The Important Formula

Suppose current prefix sum is:

```text
current_sum
```

We want some previous prefix sum such that:

```text
current_sum - previous_sum = k
```

Therefore:

```text
previous_sum = current_sum - k
```

This is the whole idea behind:

```cpp
int remove = current_sum - k;
```

---

# Example

Consider:

```text
nums = [1, 2, 3]
k = 3
```

At `2`:

```text
current_sum = 3
```

We need:

```text
previous_sum = current_sum - k

previous_sum = 3 - 3

previous_sum = 0
```

If prefix sum `0` existed before, then the subarray from the beginning has sum `3`.

That is why we initialize:

```cpp
mpp[0] = 1;
```

---

# Why `mpp[0] = 1`?

This is extremely important.

Suppose:

```text
nums = [3]
k = 3
```

First element:

```text
current_sum = 3
```

Then:

```text
remove = 3 - 3
remove = 0
```

We need to know:

> Has prefix sum `0` occurred before?

Yes — before starting the array, the prefix sum is considered:

```text
0
```

So:

```cpp
mpp[0] = 1;
```

allows us to count:

```text
[3]
```

---

# Why Do We Store Frequency?

We don't just store whether a prefix sum exists.

We store:

```text
prefix_sum → frequency
```

because the same prefix sum can occur multiple times.

For example:

```text
nums = [1, -1, 1, -1]
```

Prefix sums:

```text
1
0
1
0
```

Here `0` occurs multiple times.

Every occurrence can potentially create another subarray with sum `k`.

Therefore:

```cpp
mpp[current_sum]++;
```

---

# Optimal Algorithm

For every number:

### Step 1

Update prefix sum:

```cpp
current_sum += num;
```

### Step 2

Find required previous prefix sum:

```cpp
remove = current_sum - k;
```

### Step 3

If it exists:

```cpp
count += mpp[remove];
```

### Step 4

Store current prefix sum:

```cpp
mpp[current_sum]++;
```

---

# Dry Run

Consider:

```text
nums = [1, 2, 1, 2]
k = 3
```

We want subarrays with sum `3`.

Initialize:

```text
mpp = {0 : 1}
current_sum = 0
count = 0
```

---

## Element = 1

```text
current_sum = 1
```

Required:

```text
remove = 1 - 3
       = -2
```

`-2` doesn't exist.

Store:

```text
mpp[1]++
```

Now:

```text
mpp = {0:1, 1:1}
```

---

## Element = 2

```text
current_sum = 3
```

Required:

```text
remove = 3 - 3
       = 0
```

`0` exists once.

Therefore:

```text
count += 1
```

Now:

```text
count = 1
```

This represents:

```text
[1, 2]
```

Store:

```text
mpp[3]++
```

---

## Element = 1

```text
current_sum = 4
```

Required:

```text
remove = 4 - 3
       = 1
```

Prefix sum `1` exists once.

Therefore:

```text
count = 2
```

This represents:

```text
[2, 1]
```

Store:

```text
mpp[4]++
```

---

## Element = 2

```text
current_sum = 6
```

Required:

```text
remove = 6 - 3
       = 3
```

Prefix sum `3` exists once.

Therefore:

```text
count = 3
```

This represents:

```text
[1, 2]
```

Final:

```text
Answer = 3
```

---

# Three Approaches Compared

| Approach | Loops | Time | Extra Space |
|---|---:|---:|---:|
| Brute Force | 3 | O(n³) | O(1) |
| Running Sum | 2 | O(n²) | O(1) |
| Prefix Sum + HashMap | 1 | O(n) average | O(n) |

---

# Learning Progression

The important progression from this problem is:

```text
Brute Force
O(n³)
   ↓
Remove repeated sum calculation
   ↓
Running Sum
O(n²)
   ↓
Use Prefix Sum + HashMap
   ↓
O(n)
```

The biggest optimization is:

> Instead of repeatedly searching all previous subarrays, use previously calculated prefix sums stored in a HashMap.

---

# Important Connection With Day 33/34

This problem is closely related to the earlier:

```text
Longest Subarray with Sum K
```

There we used:

```text
Prefix Sum + HashMap
```

Here we use the **same fundamental idea**, but instead of finding the longest length, we count **how many subarrays** have sum `k`.

### Day 34

```text
Prefix Sum + HashMap
        ↓
Find longest length
```

### Day 48

```text
Prefix Sum + HashMap
        ↓
Count number of valid subarrays
```

This connection is important for recognizing the pattern in future problems.

---

# Key Revision

Remember these four lines:

```cpp
current_sum += num;

int remove = current_sum - k;

count += mpp[remove];

mpp[current_sum]++;
```

And before the loop:

```cpp
mpp[0] = 1;
```

The mental model:

```text
Current Prefix Sum
        -
Required Sum K
        =
Previous Prefix Sum
```

If that previous prefix sum has appeared:

```text
→ We found one or more valid subarrays.
```

### Optimal Complexity

```text
Time  = O(n) average
Space = O(n)
```