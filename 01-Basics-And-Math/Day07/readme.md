# Day 07 – Check Prime Number

## 📌 Problem Statement

Given an integer `n`, determine whether it is a **Prime Number**.

Return **true** if `n` is prime; otherwise, return **false**.

> **Prime Number:**  
> A prime number is a positive integer greater than `1` that has exactly **two distinct divisors**:
>
> - `1`
> - The number itself

---

## 📝 Example

**Input**

```text
n = 5
```

**Output**

```text
true
```

**Explanation**

The divisors of `5` are:

```text
1, 5
```

Since it has only two divisors, it is a **Prime Number**.

---

## 💡 Approach

A brute-force solution checks every number from `2` to `n-1`, resulting in **O(n)** time complexity.

An optimized solution is based on an important mathematical observation:

> **Factors always occur in pairs.**

For any divisor greater than `√n`, there is a corresponding divisor smaller than `√n`.

Therefore, it is sufficient to check divisibility only up to **√n**.

### Steps

1. If `n <= 1`, return `false`.
2. If `n == 2`, return `true`.
3. If `n` is even, return `false`.
4. Check only odd numbers from `3` to `√n`.
5. If any number divides `n`, it is **not prime**.
6. Otherwise, return **true**.

---

## 🧠 Dry Run

### Input

```text
n = 29
```

### Step 1

```text
29 <= 1 ?
No
```

### Step 2

```text
29 == 2 ?
No
```

### Step 3

```text
29 % 2 == 0 ?
No
```

Since `29` is odd, check only odd divisors.

### Loop

| i | i × i ≤ 29 | 29 % i | Result |
|:-:|:----------:|:------:|:------:|
|3|✅|2|Continue|
|5|✅|4|Continue|
|7|❌ (49 > 29)|Loop Ends|

No divisor is found.

```text
Return true
```

Hence, **29 is a Prime Number.**

---

## 🚀 Optimization

### Brute Force

Check every number from:

```text
2 → n-1
```

**Time Complexity**

```text
O(n)
```

---

### Optimized Approach

Check only up to:

```text
√n
```

because factors always occur in pairs.

Example:

```text
36

1 × 36
2 × 18
3 × 12
4 × 9
6 × 6
```

After reaching `√36 = 6`, every larger factor has already been paired with a smaller factor that has been checked.

Therefore, checking numbers beyond `√n` is unnecessary.

This reduces the number of iterations significantly.

---

## ⏱️ Time Complexity

```text
O(√n)
```

Only numbers up to the square root of `n` are checked.

Since all even numbers (except `2`) are skipped, the actual number of iterations is approximately half of `√n`, but the asymptotic complexity remains **O(√n)**.

---

## 💾 Space Complexity

```text
O(1)
```

No extra data structure is used.

---

## 🎯 Concepts Practiced

- Prime Numbers
- Mathematical Optimization
- Factor Pairs
- Square Root Logic
- Loop Optimization
- Time Complexity Analysis
- Early Exit Technique

---

## 📚 What I Learned

- A prime number has exactly two divisors.
- Brute-force checking is inefficient for large numbers.
- Factors always occur in pairs.
- If a factor is greater than `√n`, its paired factor must be less than or equal to `√n`.
- Therefore, checking divisibility only up to `√n` is sufficient.
- Skipping even numbers after checking `2` further reduces unnecessary iterations.
- Learned the difference between:
  - `i * i <= n`
  - `i <= n / i`
- Understood why `i <= n / i` is safer for very large integers as it avoids potential integer overflow.

---

> **Interview Takeaway 💡**
>
> Whenever you encounter problems involving **Prime Numbers**, **Divisors**, **Perfect Squares**, or **GCD**, always ask yourself:
>
> **"Can this problem be optimized using the √n factor-pair observation?"**
>
> This mathematical insight is one of the most frequently used optimizations in technical interviews.