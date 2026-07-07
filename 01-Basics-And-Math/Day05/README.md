# Day 03 – Check if the Number is Armstrong

## 📌 Problem Statement

Given an integer `n`, determine whether it is an **Armstrong Number**.

Return `true` if the number is an Armstrong Number; otherwise, return `false`.

> **Note:**
>
> An Armstrong Number is a number that is equal to the sum of its digits, where each digit is raised to the power of the total number of digits.

---

## 📝 Example

**Input**

```text
n = 153
```

**Output**

```text
true
```

**Explanation**

Number of digits = **3**

```
1³ + 5³ + 3³
= 1 + 125 + 27
= 153
```

Since the calculated sum is equal to the original number, `153` is an Armstrong Number.

---

## 💡 Approach

The solution can be divided into two steps:

1. Count the total number of digits in the given number.
2. Traverse each digit again:

   * Extract the last digit.
   * Raise it to the power of the total number of digits.
   * Add the result to a running sum.
3. Compare the calculated sum with the original number.
4. If both are equal, return `true`; otherwise, return `false`.

---

## 🔍 Dry Run

**Input**

```text
n = 153
```

### Step 1: Count Digits

```
153 → 15 → 1 → 0

Digit Count = 3
```

### Step 2: Calculate Armstrong Sum

| Digit | Calculation | Running Sum |
| ----: | ----------: | ----------: |
|     3 |     3³ = 27 |          27 |
|     5 |    5³ = 125 |         152 |
|     1 |      1³ = 1 |         153 |

### Step 3: Compare

```
Calculated Sum = 153
Original Number = 153

153 == 153

Answer = true
```

---

## ⚡ Optimization

### Brute Force Thinking

A straightforward approach is to:

* Convert the number into a string.
* Count the digits using the string length.
* Compute the Armstrong sum.

Although this works, it relies on string conversion.

### Optimized Approach

Use pure mathematical operations:

* Count digits using integer division (`/ 10`).
* Extract digits using modulo (`% 10`).
* Compute the required power for each digit.
* Compare the final sum with the original number.

This approach avoids unnecessary string conversion and demonstrates stronger mathematical problem-solving skills, which is generally preferred in coding interviews.

---

## ⏱️ Time Complexity

**O(log₁₀ n)**

* Counting the digits takes **O(log₁₀ n)**.
* Calculating the Armstrong sum also takes **O(log₁₀ n)**.

Overall,

```
O(log n) + O(log n) = O(log n)
```

---

## 💾 Space Complexity

**O(1)**

Only a constant amount of extra space is used.

---

## 📚 What I Learned

* How to count the number of digits mathematically.
* How to extract digits using the modulo (`%`) operator.
* How integer division (`/`) removes the last digit.
* How to solve problems without converting numbers into strings.
* How to combine multiple mathematical concepts to solve a problem.
* Why the overall time complexity is **O(log n)**.
* The importance of preserving the original number before modifying it.
* The difference between a mathematical solution and a string-based solution.
