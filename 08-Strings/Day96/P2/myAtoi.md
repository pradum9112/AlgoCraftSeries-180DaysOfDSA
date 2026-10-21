# Day 96 — Problem 2: String to Integer (`atoi`)

## Problem Statement

Implement the `myAtoi(string s)` function that converts a string into a 32-bit signed integer.

Follow these rules:

1. Ignore leading whitespace characters (`' '`).
2. Read an optional sign: `+` or `-`. If no sign is present, assume positive.
3. Read consecutive digits and stop at the first non-digit character.
4. If no digits are found, return `0`.
5. If the number exceeds the 32-bit signed integer range, clamp it to the nearest boundary.

The valid integer range is:

- Minimum: `-2147483648` (`INT_MIN`)
- Maximum: `2147483647` (`INT_MAX`)

### Examples

**Input**
```text
"42"
```

**Output**
```text
42
```

**Input**
```text
"   -42"
```

**Output**
```text
-42
```

**Input**
```text
"4193 with words"
```

**Output**
```text
4193
```

**Input**
```text
"words and 987"
```

**Output**
```text
0
```

**Input**
```text
"2147483648"
```

**Output**
```text
2147483647
```

## Approach 1 — String Traversal with Sign Handling and Overflow Detection

### Idea

Use an index to traverse the string and a variable to accumulate the number.

**Step 1: Skip leading spaces**

Move the index forward while the current character is a space.

**Step 2: Determine the sign**

If the current character is `-`, set `sign = -1`. If it is `+`, keep `sign = 1`. Then advance the index.

**Step 3: Process digits**

While the current character is a digit:

- Convert it into an integer using `s[i] - '0'`.
- Check whether adding this digit would exceed the allowed integer limit.
- If overflow would occur, return `INT_MAX` for a positive number or `INT_MIN` for a negative number.
- Otherwise, append the digit using `ans = ans * 10 + digit`.

**Step 4: Apply the sign**

Return `ans * sign`.

### Pattern Recognition

This problem uses **parsing with state and overflow detection**.

Recognize this pattern when:

- Input is a string representing a number.
- Whitespace and an optional sign must be handled before reading digits.
- Parsing must stop at the first invalid character.
- The result must remain within a fixed numeric range.

The key idea is to process the input once while maintaining the sign and accumulated value.

### Overflow Detection

For a positive number, the limit is `INT_MAX`.

For a negative number, the magnitude limit is `2147483648`, because `INT_MIN` has an absolute magnitude one greater than `INT_MAX`.

Before appending a digit, check:

```text
ans > (limit - digit) / 10
```

If this condition is true, the next operation would exceed the permitted limit. Clamp the result immediately.

This check is important because performing the multiplication first could overflow before the program gets a chance to detect it.

### Dry Run

Input:

```text
"   -423abc"
```

| Step | Action | Result |
|---|---|---|
| 1 | Skip leading spaces | Index reaches `-` |
| 2 | Read sign | `sign = -1` |
| 3 | Read digit `4` | `ans = 4` |
| 4 | Read digit `2` | `ans = 42` |
| 5 | Read digit `3` | `ans = 423` |
| 6 | Encounter `a` | Stop parsing |
| 7 | Apply sign | `-423` |

**Final answer: `-423`**

### Time Complexity

**O(n)** — In the worst case, each character is visited once, where `n` is the length of the string.

### Space Complexity

**O(1)** — Only a fixed number of variables are used.

## Edge Cases

| Input | Expected output | Reason |
|---|---:|---|
| `"42"` | `42` | Ordinary positive number |
| `"   -42"` | `-42` | Leading spaces and negative sign |
| `"+17"` | `17` | Explicit positive sign |
| `"0"` | `0` | Zero |
| `"words"` | `0` | No initial digits |
| `"12abc34"` | `12` | Stop at first non-digit |
| `"2147483648"` | `2147483647` | Positive overflow |
| `"-2147483649"` | `-2147483648` | Negative overflow |
| `"-2147483648"` | `-2147483648` | Exact minimum integer |
| `"   "` | `0` | No digits after spaces |
| `"+-12"` | `0` | Sign is followed by another sign, not a digit |

## What I Learned

- String-to-integer conversion requires careful handling of spaces, signs, and digits.
- Parsing stops at the first non-digit after the optional sign.
- Positive and negative integer limits are not symmetric.
- Overflow must be checked before multiplying by 10 and adding the next digit.
- A single traversal solves the problem efficiently.

## Revision Shortcut

**Spaces → Sign → Digits → Overflow Check → Apply Sign**

Remember the overflow condition:

`ans > (limit - digit) / 10`

Use `INT_MAX` as the positive limit and `2147483648` as the negative magnitude limit.

## Final Takeaway

The main challenge is not converting characters into digits; it is handling the parsing rules and integer boundaries correctly. A single-pass parser with a sign variable and a preemptive overflow check gives an efficient solution.
