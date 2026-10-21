# Day 96 — Roman to Integer

## Problem Statement

Given a string representing a Roman numeral, convert it into its corresponding integer.

Roman numerals use the following symbols:

| Symbol | Value |
|---|---:|
| I | 1 |
| V | 5 |
| X | 10 |
| L | 50 |
| C | 100 |
| D | 500 |
| M | 1000 |

Normally, values are added. However, when a smaller value appears immediately before a larger value, the smaller value is subtracted.

Examples:

- `III = 1 + 1 + 1 = 3`
- `VI = 5 + 1 = 6`
- `IV = 5 - 1 = 4`
- `IX = 10 - 1 = 9`
- `MCMXCIV = 1994`

## Approach 1 — Single Pass Using Current and Next Values

### Idea

Traverse the Roman numeral string from left to right.

For each character:

1. Convert the current Roman symbol into its integer value using `getVal()`.
2. Check whether a next character exists.
3. If the current value is smaller than the next value, subtract the current value from `total`.
4. Otherwise, add the current value to `total`.
5. Return `total` after processing all characters.

The `getVal()` helper function uses a switch statement to map each Roman symbol to its corresponding integer.

### Pattern Recognition

This problem uses **lookahead with conditional accumulation**.

Recognize this pattern when:

- The meaning of the current element depends on the next element.
- Most values are accumulated normally, but a special relationship changes the operation.
- You can solve the problem by comparing adjacent elements without storing the entire sequence in another data structure.

The key condition is:

- `currentVal < nextVal` → subtract the current value.
- Otherwise → add the current value.

### Dry Run

Input:

```text
MCMXCIV
```

| Current symbol | Current value | Next value | Operation | Total |
|---|---:|---:|---|---:|
| M | 1000 | 100 | Add | 1000 |
| C | 100 | 1000 | Subtract | 900 |
| M | 1000 | 10 | Add | 1900 |
| X | 10 | 100 | Subtract | 1890 |
| C | 100 | 1 | Add | 1990 |
| I | 1 | 5 | Subtract | 1989 |
| V | 5 | None | Add | 1994 |

**Final answer: 1994**

Notice that the smaller symbols in `CM`, `XC`, and `IV` are subtracted rather than added.

### Time Complexity

**O(n)** — Every character is visited once. The `getVal()` switch performs a constant amount of work for each character.

### Space Complexity

**O(1)** — Only a fixed number of variables are used. The auxiliary space is constant, excluding the input string.

## Edge Cases

| Input | Output | Explanation |
|---|---:|---|
| `"I"` | 1 | Single symbol |
| `"III"` | 3 | All values are added |
| `"IV"` | 4 | Subtractive pair |
| `"LVIII"` | 58 | Additive sequence |
| `"MCMXCIV"` | 1994 | Multiple subtractive pairs |
| `"MMM"` | 3000 | Repeated symbols |

The solution assumes the input is a valid Roman numeral. The helper's default return value of `0` does not validate the complete Roman numeral format.

## What I Learned

- Roman symbols can be converted into integer values using a helper function.
- Comparing the current value with the next value determines whether to add or subtract.
- A single traversal is enough; a stack or hash map is unnecessary.
- Lookahead helps solve problems where the current element's treatment depends on its successor.

## Revision Shortcut

**Current value < next value → subtract current. Otherwise → add current.**

Remember the three essential steps:

1. Map the symbol to its value.
2. Compare it with the next symbol, if one exists.
3. Update the running total.

## Final Takeaway

The main insight is that Roman numeral conversion does not require treating every symbol independently. The relationship between adjacent symbols determines whether the current value contributes positively or negatively to the total.
