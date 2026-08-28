# Day 55 — Merge Overlapping Intervals

## 📌 Problem Statement

Given a collection of intervals, merge all overlapping intervals.

---

## 🧪 Example

### Input

```text
4
1 3
2 6
8 10
9 11
```

### Your Output

```text
1 6
8 11
```

### Explanation

Initial intervals:

```text
[1,3]
[2,6]
[8,10]
[9,11]
```

`[1,3]` and `[2,6]` overlap:

```text
[1,6]
```

`[8,10]` and `[9,11]` overlap:

```text
[8,11]
```

Final answer:

```text
[1,6]
[8,11]
```

---

# 🔍 Pattern Recognition Clue

When you see:

> **Intervals + Merge + Overlap**

Immediately think:

```text
Intervals
   ↓
Sort by starting point
   ↓
Compare current interval
with previous merged interval
   ↓
Overlap?
   ↓
Merge
```

### Main trigger

```text
"Merge overlapping intervals"
        ↓
SORT FIRST
        ↓
Compare starts with previous end
```

---

# Approach 1 — Sort + Nested Loop

## 💡 Idea

First sort all intervals.

For example:

```text
[1,3] [2,6] [8,10] [9,11]
```

Then take one interval and look ahead to find all intervals that overlap with it.

```cpp
for (int i = 0; i < n; i++) {

    int start = arr[i][0];
    int end = arr[i][1];

    for (int j = i + 1; j < n; j++) {

        if (arr[j][0] <= end) {
            end = max(end, arr[j][1]);
        }
        else {
            break;
        }
    }

    ans.push_back({start, end});
}
```

### Overlap condition

```text
arr[j][0] <= end
```

Meaning:

```text
next interval ka START
        ≤
current merged interval ka END
```

then they overlap.

---

## Example

Current:

```text
[1,3]
```

Next:

```text
[2,6]
```

Check:

```text
2 <= 3
```

Yes → overlap.

Merge:

```text
start = 1
end = max(3,6)
    = 6
```

So:

```text
[1,6]
```

---

## Complexity

Sorting:

```text
O(n log n)
```

Nested loop:

```text
O(n²)
```

Overall:

```text
Time  = O(n²)
Space = O(n)
```

---

# Approach 2 — Optimal: Sort + One Loop

## 💡 Main Idea

Nested loop ki zarurat nahi hai.

Hum `ans` me already merged intervals rakh rahe hain.

Isliye current interval ko directly:

```cpp
ans.back()
```

se compare kar sakte hain.

---

## Important Visualization

Suppose:

```text
arr = [1,3] [2,6] [8,10] [9,11]
```

Initially:

```text
ans = []
```

First interval:

```text
[1,3]
```

No previous interval.

So:

```text
ans = [[1,3]]
```

---

### Next interval

```text
[2,6]
```

Previous merged interval:

```text
ans.back() = [1,3]
```

Compare:

```text
current start <= previous end

2 <= 3
```

Overlap!

So merge:

```text
end = max(3,6)
    = 6
```

Update:

```text
ans = [[1,6]]
```

---

### Next

```text
[8,10]
```

Previous merged:

```text
[1,6]
```

Compare:

```text
8 <= 6
```

False.

No overlap.

So add:

```text
ans = [[1,6], [8,10]]
```

---

### Next

```text
[9,11]
```

Previous:

```text
[8,10]
```

Compare:

```text
9 <= 10
```

True.

Merge:

```text
end = max(10,11)
    = 11
```

Final:

```text
ans = [[1,6], [8,11]]
```

---

# ⭐ The Two Important Conditions

## 1. Overlap

```cpp
if (!ans.empty() && start <= ans.back()[1])
```

Think:

```text
CURRENT START
      ≤
PREVIOUS MERGED END
```

→ overlap.

---

## 2. Merge

```cpp
end = max(ans.back()[1], end);
ans.back()[1] = end;
```

Why `max`?

Because the new interval can extend farther.

Example:

```text
Previous = [1,10]
Current  = [5,7]
```

Merged interval should remain:

```text
[1,10]
```

So:

```text
max(10,7) = 10
```

Another example:

```text
Previous = [1,6]
Current  = [4,12]
```

Merged:

```text
[1,12]
```

because:

```text
max(6,12) = 12
```

---

# 🧠 Why Does Sorting Help?

Without sorting:

```text
[8,10]
[1,3]
[2,6]
[9,11]
```

It becomes difficult to know which interval should be compared with which.

After sorting:

```text
[1,3]
[2,6]
[8,10]
[9,11]
```

Now intervals appear from left to right.

Therefore we only need to check:

```text
current interval
       ↓
last merged interval
```

This is the key reason sorting makes the problem easy.

---

# 🚀 Why Optimal Is Better

### Approach 1

```text
Sort
 ↓
i loop
 ↓
j loop
```

Time:

```text
O(n²)
```

### Approach 2

```text
Sort
 ↓
one loop
 ↓
ans.back()
```

Time:

```text
O(n log n)
```

Therefore Approach 2 is the **optimal solution**.

---

# 📊 Comparison

| Approach | Technique          |       Time | Space |
| -------- | ------------------ | ---------: | ----: |
| Better   | Sort + Nested Loop |      O(n²) |  O(n) |
| Optimal  | Sort + Single Loop | O(n log n) |  O(n) |

> Sorting itself takes `O(n log n)`, and the single traversal takes `O(n)`, so overall complexity remains `O(n log n)`.

---

# 🔥 Day55 Pattern to Remember

```text
INTERVAL PROBLEM
       ↓
SORT BY START
       ↓
CURRENT START <= LAST END ?
       ↓
     YES
       ↓
     MERGE
       ↓
max(previous end, current end)
```

### One-line memory trick:

```text
"Interval dikhe → sort karo → previous end se current start compare karo."
```

---

# 🎯 Key Code

```cpp
sort(arr.begin(), arr.end());

for (int i = 0; i < n; i++) {

    int start = arr[i][0];
    int end = arr[i][1];

    if (!ans.empty() && start <= ans.back()[1]) {

        ans.back()[1] = max(ans.back()[1], end);

    } else {

        ans.push_back({start, end});
    }
}
```

## Day55 Learning

* Intervals ko pehle sort karo.
* Sorting ke baad intervals left-to-right arranged hote hain.
* `ans.back()` last merged interval deta hai.
* `start <= ans.back()[1]` → overlap.
* Overlap hone par end ko maximum karo.
* Overlap na ho → new interval add karo.
* Optimal approach: **Sort + Single Loop = O(n log n)**.
* Pattern: **Intervals → Sort → Compare → Merge**.
