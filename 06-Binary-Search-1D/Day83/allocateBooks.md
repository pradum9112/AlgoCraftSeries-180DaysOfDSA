# Day 83 — Allocate Books

## 📌 Problem

Given an array `nums` where each element represents the number of pages in a book, and `m` students, allocate the books to the students such that:

* Each student gets at least one book.
* Books are allocated **contiguously**.
* Every book must be allocated.
* The objective is to **minimize the maximum number of pages assigned to any student**.

Return the minimum possible maximum pages.

If the number of students is greater than the number of books, return `-1`.

### Example

```text
Input:
nums = [12, 34, 67, 90]
m = 2

Output:
113
```

One optimal allocation is:

```text
Student 1 → 12 + 34 + 67 = 113
Student 2 → 90
```

Maximum pages assigned to a student:

```text
113
```

---

# 🔹 Approach 1 — Linear Search

## 💡 Idea

We are trying to **minimize the maximum pages** assigned to a student.

First determine the possible answer range.

### Minimum possible answer

A student must receive an entire book, so the answer cannot be smaller than the largest book:

```text
low = max(nums)
```

### Maximum possible answer

If one student gets all books:

```text
high = sum(nums)
```

Therefore:

```text
answer lies between max(nums) and sum(nums)
```

We check every possible maximum page limit from `low` to `high`.

For each candidate limit, we ask:

> Can we allocate all books using at most `m` students if no student is allowed more than this many pages?

The first valid candidate is the answer.

---

## 🔍 Feasibility Check

For a candidate `mid`:

1. Start with the first student.
2. Keep adding consecutive books.
3. If adding the next book exceeds `mid`, assign that book to the next student.
4. Continue until all books are allocated.
5. If the required number of students is `<= m`, the candidate is possible.

---

# 🧠 Pattern Recognition Clue

This problem contains a very important phrase:

> **Minimize the maximum**

Whenever you see:

```text
minimum possible maximum
maximum possible minimum
smallest capacity
minimum required limit
```

ask:

> **Can I guess the answer and check whether it is possible?**

Here we guess:

```text
maximum pages allowed per student
```

Then check:

```text
Can all books be allocated within this limit?
```

This converts the optimization problem into a **feasibility problem**.

---

## 🔑 Search Space

```text
max(nums) → sum(nums)
```

For example:

```text
nums = [12, 34, 67, 90]
```

Then:

```text
low  = 90
high = 203
```

So the answer must lie between:

```text
90 ... 203
```

---

## 🔄 Dry Run — Linear Search

```text
nums = [12, 34, 67, 90]
m = 2
```

### Candidate = 90

Student 1:

```text
12 + 34 = 46
```

Adding `67`:

```text
46 + 67 = 113 > 90
```

So Student 2 gets:

```text
67
```

Adding `90`:

```text
67 + 90 = 157 > 90
```

This would require a third student.

Therefore:

```text
90 → NOT POSSIBLE
```

---

### Candidate = 113

Student 1:

```text
12 + 34 + 67 = 113
```

Student 2:

```text
90
```

Required students:

```text
2
```

Since:

```text
2 <= m
```

we have:

```text
113 → POSSIBLE
```

Because we are checking candidates from smallest to largest, the first possible value is the answer.

```text
Answer = 113
```

---

## ⏱️ Time Complexity

Finding the range:

```text
O(N)
```

Checking one candidate:

```text
O(N)
```

Trying every possible candidate:

```text
O(N × (sum(nums) - max(nums)))
```

Overall:

```text
O(N × sum(nums))
```

approximately.

## 💾 Space Complexity

```text
O(1)
```

---

# 🔹 Approach 2 — Binary Search on Answer

## 💡 Observation

We don't need to check every possible maximum page limit.

Suppose:

```text
90 → impossible
91 → impossible
92 → impossible
...
112 → impossible
113 → possible
114 → possible
115 → possible
...
```

The result has a monotonic pattern:

```text
FALSE FALSE FALSE FALSE TRUE TRUE TRUE TRUE
```

This is exactly what allows Binary Search.

---

# 🧠 Pattern Recognition

This is a classic **Binary Search on Answer** problem.

Look for:

### 1. Optimization

We need:

```text
minimum possible maximum
```

### 2. Candidate answer

We can choose a maximum page limit:

```text
mid
```

### 3. Feasibility function

We can check:

```text
Can we allocate all books using at most m students
with max pages per student <= mid?
```

### 4. Monotonicity

If `mid` is possible:

```text
mid = 113 → possible
```

then every larger value is also possible:

```text
114 → possible
115 → possible
116 → possible
```

If `mid` is impossible:

```text
112 → impossible
```

then every smaller value is also impossible.

Therefore:

```text
FALSE FALSE FALSE FALSE TRUE TRUE TRUE TRUE
```

Binary Search can find the **first TRUE**.

---

# 🔑 Core Pattern

Remember this:

```text
Minimize the maximum
        ↓
Guess maximum allowed value
        ↓
Check if allocation is possible
        ↓
Possible → try smaller
Impossible → try larger
        ↓
Binary Search on Answer
```

For this problem:

```text
Possible → high = mid - 1
Impossible → low = mid + 1
```

---

# 🔄 Binary Search Dry Run

```text
nums = [12, 34, 67, 90]
m = 2
```

Search space:

```text
low = 90
high = 203
```

### Step 1

```text
mid = 146
```

Can we allocate with maximum `146`?

```text
12 + 34 + 67 = 113
```

Adding `90`:

```text
113 + 90 = 203 > 146
```

So:

```text
Student 1 → 113
Student 2 → 90
```

2 students are enough.

Therefore:

```text
146 → POSSIBLE
```

Try smaller:

```text
high = 145
```

---

### Step 2

```text
low = 90
high = 145

mid = 117
```

Allocation:

```text
12 + 34 + 67 = 113
90
```

2 students.

Therefore:

```text
117 → POSSIBLE
```

Move left:

```text
high = 116
```

---

### Step 3

```text
low = 90
high = 116

mid = 103
```

Try allocation:

```text
12 + 34 = 46
```

Adding `67`:

```text
46 + 67 = 113 > 103
```

Student 2:

```text
67
```

Adding `90`:

```text
67 + 90 = 157 > 103
```

This requires 3 students.

Therefore:

```text
103 → IMPOSSIBLE
```

Move right:

```text
low = 104
```

---

### Step 4

The search continues until:

```text
low = 113
```

At:

```text
113
```

allocation is possible.

No smaller value is possible.

Therefore:

```text
Answer = 113
```

---

# ⚖️ Approach Comparison

| Feature           | Linear Search        | Binary Search   |
| ----------------- | -------------------- | --------------- |
| Search Technique  | Sequential           | Binary Search   |
| Search Space      | `max → sum`          | `max → sum`     |
| Feasibility Check | `O(N)`               | `O(N)`          |
| Answer Search     | Every value          | Half eliminated |
| Time              | `O(N × sum)` approx. | `O(N log(sum))` |
| Space             | `O(1)`               | `O(1)`          |
| Optimal           | ❌                    | ✅               |

---

# 🎯 Why Binary Search Is Better

Suppose the search range contains thousands or millions of possible answers.

Linear Search checks:

```text
one by one
```

Binary Search checks:

```text
middle
↓
eliminate half
↓
middle of remaining half
↓
eliminate half again
```

Therefore:

```text
Linear Search
O(N × answerRange)

        ↓

Binary Search
O(N × log(answerRange))
```

---

# 🚨 Important Edge Cases

### 1. More students than books

```text
m > nums.size()
```

Return:

```text
-1
```

Because every student must receive at least one book.

### 2. One student

If:

```text
m = 1
```

the answer is:

```text
sum(nums)
```

because one student must receive all books.

### 3. Number of students equals number of books

Every student gets exactly one book.

Answer:

```text
max(nums)
```

### 4. Large page values

The sum of pages can exceed the range of a normal `int` in some constraints.

Use an appropriately large integer type when required.

---

# 🧩 Similar Pattern Problems

This same pattern appears in:

* Painter's Partition
* Capacity to Ship Packages Within D Days
* Allocate Books
* Split Array Largest Sum
* Koko Eating Bananas
* Minimum Days to Make M Bouquets
* Smallest Divisor Given a Threshold

The exact feasibility function changes, but the thinking remains similar.

---

# 🧠 What I Learned

* The problem is an optimization problem: **minimize the maximum**.
* The answer lies between:

  * `max(nums)`
  * `sum(nums)`
* A greedy feasibility check can determine whether a candidate answer works.
* If a candidate maximum is possible, every larger maximum is also possible.
* Therefore the feasibility condition is monotonic.
* This gives the **Binary Search on Answer** pattern.
* For minimization:

  * **Possible → move left**
  * **Impossible → move right**

---

# 🎯 Revision Shortcut

```text
Allocate Books
      ↓
Minimize maximum pages
      ↓
Search space:
max(book pages) → sum(all pages)
      ↓
Guess maximum pages
      ↓
Can books be allocated to ≤ m students?
      ↓
YES → LEFT
NO  → RIGHT
      ↓
Binary Search on Answer
```

### Pattern

**Binary Search on Answer + Greedy Feasibility**

### Optimal Complexity

```text
Time:  O(N log(sum(nums)))
Space: O(1)
```
