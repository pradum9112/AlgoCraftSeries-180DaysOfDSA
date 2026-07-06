# Day 04 – Greatest Common Divisor (GCD)

## 📌 Problem Statement

Given two integers `n1` and `n2`, find and return their **Greatest Common Divisor (GCD)**.

> **Note:**
>
> * The Greatest Common Divisor (GCD) of two integers is the largest positive integer that divides both numbers without leaving a remainder.

---

## 📝 Example

**Input**

```text
n1 = 4, n2 = 6
```

**Output**

```text
2
```

**Explanation**

Divisors of `4` are: `1, 2, 4`

Divisors of `6` are: `1, 2, 3, 6`

The greatest common divisor of both numbers is **2**.

---

## 💡 Approach

Use the **Euclidean Algorithm**, which is based on the following observation:

* If `n2` becomes `0`, then `n1` is the GCD.
* Otherwise, repeatedly replace:

  * `n1` with `n2`
  * `n2` with `n1 % n2`
* Continue until `n2` becomes `0`.

The remaining value of `n1` is the Greatest Common Divisor.

---

## ⏱️ Time Complexity

**O(log(min(n1, n2)))**

The Euclidean Algorithm reduces the problem size in each iteration, making it much more efficient than checking every divisor.

---

## 💾 Space Complexity

**O(1)**

Only a constant amount of extra space is used.

---

## 🎯 Concepts Practiced

* Euclidean Algorithm
* Modulo Operator (`%`)
* While Loop
* Mathematical Optimization
* Time Complexity Analysis

---

## 📚 Learning Outcome

After solving this problem, you should be able to:

* Find the GCD of two integers efficiently.
* Understand why the Euclidean Algorithm is more efficient than the brute-force approach.
* Analyze the time and space complexity of an optimized mathematical algorithm.
* Apply the concept of GCD in future problems such as LCM, Fractions, and Number Theory.
