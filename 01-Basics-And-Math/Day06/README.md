# Day 06 – Square Root & Print All Divisors

Today, I solved two mathematical problems that strengthened my understanding of number theory and optimization techniques.

---

# 📌 Problem 1 – Find the Square Root of a Number

## 📝 Problem Statement

Given an integer `n`, find its square root.

Return the square root if `n` is a perfect square; otherwise, return the appropriate result according to the problem requirements.

---

## 📝 Example

**Input**

```text
n = 25
```

**Output**

```text
5
```

**Explanation**

Since `5 × 5 = 25`, the square root of `25` is `5`.

---

## 💡 Approach

The idea is to iterate from `1` while the square of the current number is less than or equal to `n`.

* Check whether `i × i` equals `n`.
* If it does, return `i`.
* Continue until `i × i` exceeds `n`.

This avoids checking unnecessary values greater than the square root.

---

## 🔍 Dry Run

**Input**

```text
n = 25
```

|  i | i × i | Result   |
| -: | ----: | :------- |
|  1 |     1 | Continue |
|  2 |     4 | Continue |
|  3 |     9 | Continue |
|  4 |    16 | Continue |
|  5 |    25 | Return 5 |

---

## ⚡ Optimization

### Brute Force

Check every number from `1` to `n`.

**Time Complexity:** `O(n)`

### Optimized

Stop the loop once `i × i` becomes greater than `n`.

Only values up to `√n` are checked.

**Time Complexity:** `O(√n)`

---

## ⏱️ Time Complexity

**O(√n)**

---

## 💾 Space Complexity

**O(1)**

---

## 📚 What I Learned

* How square root reduces the search space.
* Why checking beyond `√n` is unnecessary.
* How mathematical observations help optimize brute-force solutions.
* Importance of analyzing loop termination conditions.

---

# 📌 Problem 2 – Print All Divisors of a Number

## 📝 Problem Statement

Given an integer `n`, find and return all of its divisors in sorted order.

A divisor is a number that divides `n` completely without leaving a remainder.

---

## 📝 Example

**Input**

```text
n = 12
```

**Output**

```text
[1, 2, 3, 4, 6, 12]
```

**Explanation**

Each number in the output divides `12` exactly.

---

## 💡 Approach

Instead of checking every number from `1` to `n`, observe that divisors always occur in pairs.

If `i` divides `n`, then `n / i` is also a divisor.

* Iterate from `1` to `√n`.
* Whenever a divisor is found, store both `i` and `n / i`.
* Avoid duplicates when both divisors are the same (perfect square case).
* Sort the collected divisors before returning them.

---

## 🔍 Dry Run

**Input**

```text
n = 36
```

|  i | Divisor Pair  |
| -: | :------------ |
|  1 | (1, 36)       |
|  2 | (2, 18)       |
|  3 | (3, 12)       |
|  4 | (4, 9)        |
|  5 | Not a divisor |
|  6 | (6, 6)        |

Collected divisors:

```text
1, 36, 2, 18, 3, 12, 4, 9, 6
```

After sorting:

```text
1, 2, 3, 4, 6, 9, 12, 18, 36
```

---

## ⚡ Optimization

### Brute Force

Check every number from `1` to `n`.

**Time Complexity:** `O(n)`

### Optimized

Check only up to `√n`.

For every divisor found, its paired divisor is obtained immediately.

**Time Complexity:** `O(√n)`

---

## ⏱️ Time Complexity

* Finding divisor pairs: **O(√n)**
* Sorting the divisors: **O(k log k)**

Where `k` is the number of divisors.

Overall:

**O(√n + k log k)**

---

## 💾 Space Complexity

**O(k)**

Where `k` is the total number of divisors stored.

---

## 📚 What I Learned

* Divisors always exist in pairs.
* Why checking only up to `√n` is sufficient.
* How mathematical observations reduce unnecessary computations.
* How to use `vector` to store dynamic results.
* Why sorting is required before returning the final answer.
* Difference between brute-force and optimized approaches.
