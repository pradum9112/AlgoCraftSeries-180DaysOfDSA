# Day 100 — Pow(x, n)

## Problem Statement

Implement `myPow(x, n)`, which calculates \(x^n\), where `x` is a floating-point number and `n` is a signed integer.

Requirements:
- Handle positive exponents.
- Handle negative exponents using the reciprocal.
- Return `1.0` when the exponent is zero.
- Handle the minimum 32-bit integer exponent safely.

### Example 1

**Input**
```text
x = 2.0, n = 10
```

**Output**
```text
1024.0
```

### Example 2

**Input**
```text
x = 2.0, n = -2
```

**Output**
```text
0.25
```

**Explanation**

A negative exponent means taking the reciprocal:

\[
x^{-n}=\frac{1}{x^n}
\]

Therefore, \(2^{-2}=\frac{1}{2^2}=\frac14=0.25\).

## Approach 1 — Recursive Binary Exponentiation

### Idea / Approach

Instead of multiplying `x` by itself `n` times, calculate half of the power recursively.

For an exponent `n`:

- If `n == 0`, return `1.0`.
- Recursively calculate `half = solve(x, n / 2)`.
- If `n` is even, return `half * half`.
- If `n` is odd, return `half * half * x`.

For negative exponents, convert the exponent to a positive `long long` and replace `x` with `1.0 / x`.

Using `long long` is important because the magnitude of `INT_MIN` cannot be represented as a positive `int`.

### Pattern Recognition

**Pattern: Recursion + Divide and Conquer + Binary Exponentiation.**

Look for these clues:
- The same power can be reduced to half the exponent.
- Even powers can be calculated by squaring the half result.
- Odd powers require one additional multiplication by `x`.
- The exponent shrinks by approximately half on every recursive call.

### Dry Run

Input: `x = 2.0`, `n = 10`

The recursive calls reduce the exponent:

| Call | Exponent | Action |
|---|---:|---|
| `solve(2, 10)` | 10 | Calculate half |
| `solve(2, 5)` | 5 | Calculate half |
| `solve(2, 2)` | 2 | Calculate half |
| `solve(2, 1)` | 1 | Calculate half |
| `solve(2, 0)` | 0 | Return `1.0` |

Now return through the recursive calls:

| Exponent | Calculation | Result |
|---|---|---:|
| 1 | \(1 \times 1 \times 2\) | 2 |
| 2 | \(2 \times 2\) | 4 |
| 5 | \(4 \times 4 \times 2\) | 32 |
| 10 | \(32 \times 32\) | 1024 |

Final answer: `1024.0`.

### Time Complexity

**O(log |n|)** — The exponent is divided by two on each recursive call.

### Space Complexity

**O(log |n|)** — The recursive call stack grows with the number of times the exponent can be halved.

## Approach 2 — Iterative Binary Exponentiation

### Idea / Approach

Use a loop instead of recursion. Maintain:
- `ans`, initially `1.0`.
- `x`, the current power contribution.
- `nn`, the remaining exponent magnitude.

For each iteration:

1. If `nn` is odd, multiply `ans` by `x` and decrement `nn`.
2. If `nn` is even, square `x` and divide `nn` by two.
3. Continue until `nn` becomes zero.

As in the recursive approach, negative exponents are handled by taking the reciprocal of `x` and using a positive `long long` exponent.

### Pattern Recognition

**Pattern: Iterative Binary Exponentiation.**

Use this when:
- You need fast exponentiation.
- The exponent can be reduced through repeated halving.
- You want to avoid recursive call-stack space.

### Dry Run

Input: `x = 2.0`, `n = 10`

Initially: `ans = 1`, `x = 2`, `nn = 10`.

| Iteration | Condition | Operation | `ans` | `x` | `nn` |
|---|---|---|---:|---:|---:|
| 1 | Even | Square `x`, halve `nn` | 1 | 4 | 5 |
| 2 | Odd | Multiply `ans` by `x` | 4 | 4 | 4 |
| 3 | Even | Square `x`, halve `nn` | 4 | 16 | 2 |
| 4 | Even | Square `x`, halve `nn` | 4 | 256 | 1 |
| 5 | Odd | Multiply `ans` by `x` | 1024 | 256 | 0 |

Final answer: `1024.0`.

### Time Complexity

**O(log |n|)** — The loop reduces the exponent by halving it or removing an odd bit.

### Space Complexity

**O(1)** — Only a fixed number of variables are used.

## Approach Comparison

| Property | Recursive | Iterative |
|---|---|---|
| Main technique | Divide and conquer | Binary exponentiation loop |
| Time complexity | O(log |n|) | O(log |n|) |
| Auxiliary space | O(log |n|) | O(1) |
| Recursion used | Yes | No |
| Main advantage | Expresses the recursive relationship clearly | Avoids recursive stack usage |

## Edge Cases

| Input | Expected output | Reason |
|---|---:|---|
| `x = 2.0, n = 10` | `1024.0` | Positive exponent |
| `x = 2.0, n = -2` | `0.25` | Negative exponent |
| `x = 5.0, n = 0` | `1.0` | Zero exponent |
| `x = 2.0, n = 1` | `2.0` | Exponent one |
| `x = 2.0, n = -1` | `0.5` | Reciprocal |
| `x = 2.0, n = INT_MIN` | A very small positive value | Tests safe exponent conversion |

For `x = 0` and a negative exponent, the mathematical result is undefined; typical problem constraints exclude that input.

## What I Learned

- Binary exponentiation reduces the number of multiplications dramatically.
- Even powers can be calculated by squaring the half-power.
- Odd powers need one extra multiplication by the base.
- Negative exponents require taking the reciprocal.
- Converting `n` to `long long` before negating it avoids overflow for `INT_MIN`.
- Iteration and recursion can implement the same algorithm with different auxiliary-space costs.

## Revision Shortcut

**Recursive:** Base case → solve half → square → multiply by `x` if odd.

**Iterative:** If odd, multiply the answer; otherwise, square the base and halve the exponent.

**Negative exponent:** Take the reciprocal and safely convert the exponent magnitude to `long long`.

## Final Takeaway

Binary exponentiation calculates powers in **O(log |n|) time** rather than O(|n|). The recursive version is ideal for practicing recursion, while the iterative version achieves O(1) auxiliary space.
