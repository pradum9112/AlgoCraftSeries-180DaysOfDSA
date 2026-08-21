# 📘 Day 50 — Majority Element II

## Problem Statement

Given an integer array `nums` of size `n`, find all elements that appear **more than `n / 3` times**.

There can be **at most 2 such elements**.

---

## Example

### Input

```text
8
1 2 2 3 2 1 1 1
```

Frequencies:

```text
1 → 4
2 → 3
3 → 1
```

Since:

```text
n = 8

n / 3 = 2
```

We need elements whose frequency is:

```text
> 2
```

Therefore:

```text
1 and 2
```

### Output

```text
1 2
```

---

# Why Can There Be At Most 2 Answers?

This is the first important observation.

We need:

```text
frequency > n/3
```

Suppose there were 3 different elements satisfying this.

Then their total frequency would be:

```text
> n/3 + n/3 + n/3
```

Therefore:

```text
> n
```

But the array contains only `n` elements.

Impossible.

Therefore:

```text
Maximum possible answers = 2
```

This is the reason the optimal algorithm only maintains:

```text
Candidate 1
Candidate 2
```

---

# Approach 1 — Brute Force

For every element:

1. Count how many times it appears.
2. If frequency is greater than `n/3`, add it to the answer.
3. Don't add the same candidate again.

Code concept:

```cpp
for (int i = 0; i < n; i++) {

    int cnt = 0;

    for (int j = 0; j < n; j++) {

        if (nums[j] == nums[i]) {
            cnt++;
        }
    }

    if (cnt > n / 3) {
        ans.push_back(nums[i]);
    }
}
```

## Complexity

```text
Time = O(n²)
Space = O(1) extra
```

This is the easiest approach to understand, but inefficient for large arrays.

---

# Approach 2 — HashMap

Instead of counting the same number repeatedly, store its frequency.

```cpp
unordered_map<int, int> mpp;
```

Then:

```cpp
for (int num : nums) {
    mpp[num]++;
}
```

Now we have:

```text
value → frequency
```

For example:

```text
nums = [1,2,2,3,2,1,1,1]
```

Map:

```text
1 → 4
2 → 3
3 → 1
```

Then check:

```cpp
if (it.second > n / 3)
```

---

## Complexity

Average case:

```text
Time = O(n)
Space = O(n)
```

This is much better than brute force.

But we can still improve the space.

---

# Approach 3 — Extended Boyer-Moore Voting Algorithm

This is the optimal approach.

The normal Boyer-Moore algorithm from the previous majority-element problem finds an element occurring more than:

```text
n / 2
```

Here the threshold is:

```text
n / 3
```

Therefore we can have:

```text
at most 2 candidates
```

So we maintain:

```text
el1 → candidate 1
cnt1 → count 1

el2 → candidate 2
cnt2 → count 2
```

---

# Step 1 — Candidate Selection

We process every number.

### Case 1

If candidate 1 has no votes:

```cpp
if (cnt1 == 0 && num != el2)
```

make the current number candidate 1.

```cpp
cnt1 = 1;
el1 = num;
```

---

### Case 2

Otherwise, if candidate 2 has no votes:

```cpp
else if (cnt2 == 0 && num != el1)
```

make the current number candidate 2.

```cpp
cnt2 = 1;
el2 = num;
```

---

### Case 3

If the number matches candidate 1:

```cpp
else if (num == el1)
```

increase its count:

```cpp
cnt1++;
```

---

### Case 4

If it matches candidate 2:

```cpp
else if (num == el2)
```

increase candidate 2's count:

```cpp
cnt2++;
```

---

### Case 5 — Different From Both

If the current number is different from both candidates:

```cpp
else
```

we decrease both counts:

```cpp
cnt1--;
cnt2--;
```

This is the **cancellation idea**.

---

# Cancellation Visualization

Suppose currently:

```text
Candidate 1 = 1
Candidate 2 = 2
```

and we encounter:

```text
3
```

We have:

```text
1
2
3
```

Three different elements.

We can cancel one occurrence of each:

```text
1 ❌
2 ❌
3 ❌
```

Therefore:

```text
cnt1--
cnt2--
```

The idea is that groups of three different elements cannot produce an element appearing more than `n/3` times.

---

# Example Dry Run

Consider:

```text
nums = [1,2,2,3,2,1,1,1]
```

Initially:

```text
el1 = INT_MIN
el2 = INT_MIN

cnt1 = 0
cnt2 = 0
```

---

## Number = 1

`cnt1 == 0`

So:

```text
el1 = 1
cnt1 = 1
```

---

## Number = 2

`cnt2 == 0`

So:

```text
el2 = 2
cnt2 = 1
```

Current:

```text
Candidate 1 → 1 (count 1)
Candidate 2 → 2 (count 1)
```

---

## Number = 2

Matches candidate 2:

```text
cnt2++
```

Now:

```text
1 → count 1
2 → count 2
```

---

## Number = 3

`3` is different from both candidates.

Therefore:

```text
cnt1--
cnt2--
```

Now:

```text
cnt1 = 0
cnt2 = 1
```

Candidate 1 has lost its current vote.

---

## Number = 2

Matches candidate 2:

```text
cnt2++
```

Now:

```text
cnt2 = 2
```

---

## Number = 1

Candidate 1 count is zero:

```text
el1 = 1
cnt1 = 1
```

---

## Number = 1

Matches candidate 1:

```text
cnt1++
```

Now:

```text
cnt1 = 2
cnt2 = 2
```

---

## Number = 1

Matches candidate 1:

```text
cnt1++
```

Final candidates:

```text
el1 = 1
el2 = 2
```

But this is only the **candidate selection phase**.

---

# Why Do We Need Verification?

This is extremely important.

The first pass does **not guarantee** that both candidates actually occur more than `n/3` times.

It only tells us:

```text
These are the only possible candidates.
```

Therefore we must count them again.

```cpp
cnt1 = 0;
cnt2 = 0;

for (int num : nums) {

    if (num == el1) {
        cnt1++;
    }
    else if (num == el2) {
        cnt2++;
    }
}
```

Then:

```cpp
if (cnt1 > n / 3)
    ans.push_back(el1);

if (cnt2 > n / 3)
    ans.push_back(el2);
```

---

# Why Is Verification Necessary?

Consider an array where no element appears more than `n/3` times.

The cancellation process can still leave some candidates at the end.

But those candidates may not actually satisfy:

```text
frequency > n/3
```

Therefore:

```text
First Pass
    ↓
Find possible candidates

Second Pass
    ↓
Verify actual frequency
```

This distinction is very important.

---

# Three Approaches Comparison

| Approach | Time | Extra Space | Learning |
|---|---:|---:|---|
| Brute Force | O(n²) | O(1) | Basic frequency counting |
| HashMap | O(n) average | O(n) | Frequency + HashMap |
| **Boyer-Moore** | **O(n)** | **O(1)** | **Optimal / cancellation** |

---

# Connection With Day 39

Previously we solved:

```text
Majority Element
frequency > n/2
```

There can only be:

```text
1 candidate
```

So normal Boyer-Moore maintained:

```text
candidate
count
```

Now:

```text
Majority Element II
frequency > n/3
```

There can be:

```text
maximum 2 candidates
```

Therefore we maintain:

```text
candidate 1
count 1

candidate 2
count 2
```

This is the **extended Boyer-Moore Voting Algorithm**.

---

# Key Pattern

Remember:

```text
Threshold > n/2
        ↓
At most 1 candidate
        ↓
Boyer-Moore

Threshold > n/3
        ↓
At most 2 candidates
        ↓
Extended Boyer-Moore
```

More generally:

```text
Frequency > n/k
        ↓
At most k - 1 candidates
```

---

# Day 50 Learning Focus

The important learning progression is:

```text
Brute Force
    ↓
HashMap
    ↓
Boyer-Moore
```

You are learning to recognize:

```text
Frequency problem
      ↓
Can HashMap solve it?
      ↓
Can we reduce O(n) space?
      ↓
Use candidate + cancellation technique
```

### Optimal Complexity

```text
Time  = O(n)
Space = O(1)
```

The most important concepts from Day 50 are:

```text
1. At most 2 answers can exist.

2. Maintain 2 candidates.

3. Different element → cancel both counts.

4. First pass finds candidates.

5. Second pass verifies candidates.
```