# Day 03 – Palindrome Number

## 📌 Problem Statement

Given an integer `n`, determine whether it is a **palindrome number**.

A palindrome number reads the same from **left to right** and **right to left**.

Return:

- `true` → If the number is a palindrome.
- `false` → Otherwise.

> **Note:**
>
> - Negative numbers are **not** palindrome numbers.
> - Any number ending with `0` (except `0` itself) is **not** a palindrome.

---

## Example

**Input**

```text
n = 121
```

**Output**

```text
true
```

**Explanation**

When read from left to right:

```text
121
```

When read from right to left:

```text
121
```

Since both are the same, the number is a palindrome.

---

# Approach 1 – Reverse the Entire Number (Brute Force)

## Idea

1. Store the original number.
2. Reverse the complete number.
3. Compare the reversed number with the original number.
4. If both are equal, return `true`; otherwise return `false`.

### Dry Run

For:

```text
121
```

| Number | Last Digit | Reverse |
| ------- | ---------- | ------- |
| 121 | 1 | 1 |
| 12 | 2 | 12 |
| 1 | 1 | 121 |

Now,

```text
Original = 121
Reverse = 121
```

Hence,

```text
true
```

---

## Time Complexity

```text
O(log₁₀ n)
```

---

## Space Complexity

```text
O(1)
```

---

## Limitation

Reversing the entire number may cause **integer overflow** for very large integers.

---

# Approach 2 – Reverse Only Half of the Number (Optimized)

## Idea

Instead of reversing the entire number, reverse only the **last half** of its digits.

Once the reversed half becomes greater than or equal to the remaining half, compare both halves.

This avoids integer overflow and performs fewer operations.

---

## Algorithm

1. If the number is negative, return `false`.
2. If the number ends with `0` but is not `0`, return `false`.
3. Reverse digits until:

```text
reversedHalf >= remainingHalf
```

4. Compare:

For even number of digits:

```text
remainingHalf == reversedHalf
```

For odd number of digits:

```text
remainingHalf == reversedHalf / 10
```

(The middle digit is ignored.)

---

## Optimized C++ Solution

```cpp
#include<iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int n) {

        int rev_num = 0;

        if (n < 0 || (n % 10 == 0 && n != 0))
            return false;

        while (n > rev_num) {
            rev_num = rev_num * 10 + n % 10;
            n /= 10;
        }

        return (n == rev_num) || (n == rev_num / 10);
    }
};

int main() {
    int n;
    cin >> n;

    Solution obj;

    cout << boolalpha << obj.isPalindrome(n);

    return 0;
}
```

---

## Time Complexity

```text
O(log₁₀ n)
```

Only half of the digits are processed, making this approach faster in practice than reversing the entire number.

---

## Space Complexity

```text
O(1)
```

No extra data structure is used.

---

# Key Interview Points

- Negative numbers are never palindrome numbers.
- Numbers ending with `0` (except `0`) cannot be palindrome numbers.
- Reversing the entire number can lead to integer overflow.
- Reversing only half of the number avoids overflow.
- The optimized solution uses constant extra space and fewer operations.

---

# What I Learned

- How to extract the last digit using `%`.
- How to remove the last digit using `/`.
- How to reverse a number mathematically.
- Why reversing only half of the number is a better approach.
- How to handle important edge cases.
- How to optimize a brute-force solution while keeping the space complexity constant.

---

## 🏷️ Tags

`Math` • `Palindrome` • `Number Theory` • `Two Pointer Thinking` • `Interview Problem` • `Easy`