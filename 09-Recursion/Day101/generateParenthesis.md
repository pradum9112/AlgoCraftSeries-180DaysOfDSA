# Day101: Generate Parentheses

## Problem Statement

Given an integer `n`, generate all combinations of `n` pairs of parentheses that are valid.

A parentheses combination is valid when every opening bracket `(` has a corresponding closing bracket `)` and no closing bracket appears before its matching opening bracket.

### Example

**Input**
```text
3
```

**Output**
```text
((()))
(()())
(())()
()(())
()()()
```

## Approach: Recursion + Backtracking

### Idea / Approach

We maintain four things:

- `curr_str`: the combination being built.
- `open`: number of opening brackets used.
- `close`: number of closing brackets used.
- `result`: stores all valid combinations.

At each recursive call:

1. If `curr_str.length() == 2 * n`, the combination is complete. Add it to `result`.
2. If `open < n`, add `(` and recursively explore that choice.
3. If `close < open`, add `)` and recursively explore that choice.
4. After each recursive call, use `pop_back()` to undo the latest choice and explore another possibility.

### Pattern Recognition

This is a **backtracking problem** because we build a solution one character at a time, explore possible choices, and undo each choice when returning from recursion.

The two essential conditions are:

- `open < n`: never use more than `n` opening brackets.
- `close < open`: never close more brackets than have been opened.

### Dry Run

For `n = 2`, the valid combinations are `"(())"` and `"()()"`.

| Current string | Open | Close | Action |
|---|---:|---:|---|
| `""` | 0 | 0 | Add `(` |
| `"("` | 1 | 0 | Add `(` |
| `"(("` | 2 | 0 | Add `)` |
| `"(()"` | 2 | 1 | Add `)` |
| `"(())"` | 2 | 2 | Store result |
| `"("` | 1 | 0 | Backtrack and try `)` |
| `"()"` | 1 | 1 | Add `(` |
| `"()("` | 2 | 1 | Add `)` |
| `"()()"` | 2 | 2 | Store result |

The algorithm explores the opening-bracket branch first, then backtracks to explore the closing-bracket branch.

### Time Complexity

Let \(C_n\) be the nth Catalan number, representing the number of valid combinations.

- **Time:** \(O(n \cdot C_n)\), because there are \(C_n\) output strings, each of length \(2n\).
- **Auxiliary space:** \(O(n)\) for the current string and recursion stack, excluding the output.
- **Output space:** \(O(n \cdot C_n)\) to store all generated combinations.

### Optimization

The algorithm avoids generating invalid combinations in the first place. In particular, `close < open` prevents an invalid prefix such as `")("` from ever being created.

This is more efficient than generating every possible sequence of `2n` brackets and checking validity afterward.

### Approach Comparison

| Method | Main idea | Efficiency |
|---|---|---|
| Generate and validate | Generate every possible sequence and check validity | Explores many invalid sequences |
| Backtracking | Add only brackets that preserve validity | Avoids invalid branches |

### Edge Cases

- `n = 1`: output is `()`.
- `n = 2`: output contains two combinations.
- `n = 3`: output contains five combinations.
- `n = 0`: the recursive base case stores the empty string. Many interview constraints specify `n >= 1`.

### What I Learned

1. Backtracking explores one choice, recursively processes it, and undoes it with `pop_back()`.
2. Constraints can prevent invalid states from being generated.
3. A recursive base case determines when a complete solution is ready to store.
4. Catalan numbers count valid parentheses combinations.

### Revision Shortcut

Remember:

- **Open condition:** `open < n`
- **Close condition:** `close < open`
- **Base case:** `curr_str.length() == 2 * n`
- **Backtrack:** `pop_back()`

### Final Takeaway

Build valid combinations instead of generating invalid ones and filtering them afterward. The two conditions—`open < n` and `close < open`—are the core of this solution.

## CPH Judge Test Cases

### Test Case 1

**Input**
```text
1
```

**Expected Output**
```text
()
```

### Test Case 2

**Input**
```text
2
```

**Expected Output**
```text
(())
()()
```

### Test Case 3

**Input**
```text
3
```

**Expected Output**
```text
((()))
(()())
(())()
()(())
()()()
```

*Note: The order of valid combinations may differ between correct implementations. The set of combinations should match.*
