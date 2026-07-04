# Day 02 :

# Count Digits

## 📌 Problem Statement 1

Given an integer `n`, return the total number of digits present in the number.

> **Note:**
>
> * The number will not contain leading zeroes.
> * The only exception is when the number itself is `0`.

---

## 📝 Example

**Input**

```text
n = 4
```

**Output**

```text
1
```

**Explanation**

The number `4` contains only one digit.

---

## 💡 Approach

The idea is to repeatedly remove the last digit of the number using integer division by `10`.

1. If `n` is `0`, return `1`.
2. Initialize a counter to `0`.
3. While `n > 0`:

   * Increment the counter.
   * Divide `n` by `10`.
4. Return the counter.

Since one digit is removed in each iteration, the total number of iterations equals the number of digits.

---

## ⏱️ Time Complexity

**O(log₁₀ n)**

The loop executes once for each digit in the number.

---

## 💾 Space Complexity

**O(1)**

Only a constant amount of extra space is used.

---

## 🎯 Concepts Practiced

* Integer Division (`/`)
* While Loop
* Counting Digits
* Mathematical Manipulation
* Time Complexity Analysis

---

## 📚 Learning Outcome

After solving this problem, you should be able to:

* Count the digits of an integer without converting it to a string.
* Understand how integer division removes the last digit.
* Analyze the time and space complexity of a simple mathematical algorithm.

---
---
---
# Reverse A Number

## 📌 Problem Statement 2

Given an integer `n`, reverse its digits and return the reversed number.

> **Note:**
>
> * The input number is non-negative.
> * Leading zeroes in the reversed number are automatically removed.

---

## 📝 Example

**Input**

```text
n = 1234
```

**Output**

```text
4321
```

**Explanation**

The digits of `1234` are reversed to form `4321`.

---

## 💡 Approach

The idea is to extract the last digit of the number one by one and build the reversed number.

1. Initialize a variable `reverseNumber` to `0`.
2. While `n > 0`:

   * Extract the last digit using `n % 10`.
   * Append the extracted digit to the reversed number using:
     `reverseNumber = reverseNumber * 10 + lastDigit`.
   * Remove the last digit from `n` using integer division by `10`.
3. Return the reversed number.

---

## ⏱️ Time Complexity

**O(log₁₀ n)**

The loop runs once for each digit of the number.

---

## 💾 Space Complexity

**O(1)**

Only a constant amount of extra space is used.

---

## 🎯 Concepts Practiced

* Modulo Operator (`%`)
* Integer Division (`/`)
* While Loop
* Number Manipulation
* Mathematical Logic

---

## 📚 Learning Outcome

After solving this problem, you should be able to:

* Reverse the digits of an integer without converting it to a string.
* Understand how `%` and `/` work together for digit manipulation.
* Build a new number digit by digit.
* Analyze the time and space complexity of the solution.
