maxDepth# Day 95 — Maximum Nesting Depth of Parentheses

## Problem Statement

Given a valid string containing parentheses and other characters, find the **maximum nesting depth** of its parentheses.

The nesting depth is the maximum number of opening parentheses that are active at the same time before their matching closing parentheses.

### Example

**Input**
```text
s = "(1+(2*3)+((8)/4))+1"
```

**Output**
```text
3
```

**Explanation**

The deepest part is `((8)/4)`. At the deepest point, three opening parentheses are active simultaneously, so the maximum nesting depth is `3`.

## Approach 1 — Single Pass Using a Counter

### Idea

Maintain two variables:

- `curr_depth`: the current nesting depth.
- `max_depth`: the maximum depth found so far.

Traverse the string once:

1. If the character is `(`, increment `curr_depth`.
2. Update `max_depth` if the current depth is greater.
3. If the character is `)`, decrement `curr_depth`.
4. Ignore all other characters.
5. Return `max_depth`.

### Pattern Recognition

This problem is a good fit for a **counter-based string traversal**.

Look for these clues:

- The question asks for maximum nesting or depth.
- Opening and closing symbols indicate entering and leaving a nested level.
- We only need the current level and the maximum level, not the actual matching positions.

A stack is not necessary because we only need the depth, not the matching parentheses themselves.

### Dry Run

Input:

```text
(1+(2*3)+((8)/4))+1
```

| Character/event | Current depth | Maximum depth |
|---|---:|---:|
| `(` | 1 | 1 |
| `(` | 2 | 2 |
| `)` | 1 | 2 |
| `(` | 2 | 2 |
| `(` | 3 | 3 |
| `)` | 2 | 3 |
| `)` | 1 | 3 |
| Final closing parentheses | 0 | 3 |

Characters other than parentheses do not change the depth. The final answer is `3`.

### Time Complexity

**O(n)** — Each character is visited once, where `n` is the length of the string.

### Space Complexity

**O(1)** — Only two integer variables are used; the extra space does not grow with the input size.

## Edge Cases

| Input | Output | Reason |
|---|---:|---|
| `"(1+(2*3)+((8)/4))+1"` | `3` | Maximum nesting is three |
| `"(1)+((2))+(((3)))"` | `3` | The deepest group has three levels |
| `"1+2*3"` | `0` | No parentheses |
| `"((()))"` | `3` | Three nested levels |
| `"()"` | `1` | One pair of parentheses |

The solution assumes the input has valid, balanced parentheses.

## What I Learned

- A counter can represent the current nesting level.
- Increment when entering a nested level and decrement when leaving it.
- Update the maximum when the depth increases.
- A stack is unnecessary when only the maximum depth is required.

## Revision Shortcut

**Opening bracket → increment → update maximum.**

**Closing bracket → decrement.**

Return the maximum recorded depth.

## Final Takeaway

The key is to distinguish **current depth** from **maximum depth**. The current depth changes as parentheses open and close, while the maximum depth only increases when a deeper level is reached.
