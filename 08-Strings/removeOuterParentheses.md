# Day94 — Remove Outermost Parentheses

## Problem

A valid parentheses string is either empty, a concatenation of two valid parentheses strings, or a valid string enclosed in a matching pair of parentheses.

A **primitive parentheses string** is a non-empty valid parentheses string that cannot be split into two non-empty valid parentheses strings.

Given a valid parentheses string `s`, remove the outermost pair of parentheses from every primitive substring and return the resulting string.

### Example

```text
Input:  (()())(())(()(()))
Output: ()()()(())(())
```

Each primitive loses its first and last parentheses.

---

# Approach 1 — Primitive Substring

## Idea

Use two variables:

* `balance`: tracks the number of unmatched opening parentheses.
* `start`: marks the beginning of the current primitive substring.

Traverse the string and update `balance`:

* For `(`, increment `balance`.
* For `)`, decrement `balance`.

Whenever `balance` becomes zero, a complete primitive substring has been found.

Remove its first and last characters and append the remaining substring to `result`. If the primitive is simply `()`, nothing needs to be appended.

Then update `start` to the next character.

## Pattern Recognition

When a string contains multiple valid parentheses primitives, a balance counter can identify where each primitive ends.

**Pattern:** Balanced parentheses + substring boundaries.

```text
Track balance
     ↓
Balance returns to zero
     ↓
Primitive completed
     ↓
Remove outermost pair
     ↓
Continue from next primitive
```

## Dry Run

Input:

```text
(()())(())
```

### First primitive: `(()())`

The balance returns to zero at the final `)` of this primitive.

Remove its outermost pair:

```text
(()()) → ()()
```

Result:

```text
()()
```

### Second primitive: `(())`

Remove its outermost pair:

```text
(()) → ()
```

Final result:

```text
()()()
```

## Time Complexity

Each character is visited once. The substring operations together copy at most `n` characters.

* **Time:** `O(n)`

## Space Complexity

The output and temporary substring storage may require space proportional to the input length.

* **Auxiliary space:** `O(n)`

---

# Approach 2 — Stack

## Idea

Use a stack to track the nesting depth of parentheses.

For an opening parenthesis `(`:

1. If the stack is empty, this is the outermost opening parenthesis, so skip it.
2. Otherwise, append it to the result.
3. Push it onto the stack.

For a closing parenthesis `)`:

1. Pop the matching opening parenthesis.
2. If the stack is still non-empty, this closing parenthesis is not outermost, so append it.
3. If the stack becomes empty, skip the outermost closing parenthesis.

## Pattern Recognition

A stack naturally represents nested structures such as parentheses.

**Pattern:** Stack depth identifies outermost versus inner parentheses.

```text
Opening '('
    ↓
Stack empty? → Skip outermost
    ↓
Push '('

Closing ')'
    ↓
Pop '('
    ↓
Stack empty? → Skip outermost
Otherwise    → Append ')'
```

## Dry Run

Input:

```text
(())
```

1. First `(`: stack is empty, so skip it; push.
2. Second `(`: stack is non-empty, so append it; push.
3. First `)`: pop; stack remains non-empty, so append it.
4. Final `)`: pop; stack becomes empty, so skip it.

Output:

```text
()
```

## Time Complexity

Every character is processed once.

* **Time:** `O(n)`

## Space Complexity

The stack can hold up to `O(n)` opening parentheses, and the result can also hold `O(n)` characters.

* **Auxiliary space:** `O(n)`

---

# Approach 3 — Counter (Optimal)

## Idea

The stack is not necessary because we only need the current nesting depth, not the actual parentheses stored in the stack.

Maintain an integer `balance`.

### When the character is `(`

* If `balance > 0`, we are already inside a primitive. Append `(`.
* Increment `balance`.

### When the character is `)`

* Decrement `balance`.
* If `balance > 0`, we are still inside the primitive. Append `)`.

This automatically skips the outermost opening and closing parentheses.

## Pattern Recognition

Whenever a problem requires only the depth of nested parentheses, a counter can replace a stack.

**Pattern:** Nesting depth + conditional inclusion.

```text
'(':
    If balance > 0, append
    balance++

')':
    balance--
    If balance > 0, append
```

## Dry Run

Input:

```text
(()())
```

Initially:

```text
balance = 0
result = ""
```

| Character | Balance after processing | Action             | Result |
| --------- | -----------------------: | ------------------ | ------ |
| `(`       |                        1 | Skip outer opening | `""`   |
| `(`       |                        2 | Append             | `(`    |
| `)`       |                        1 | Append             | `()`   |
| `(`       |                        2 | Append             | `()(`  |
| `)`       |                        1 | Append             | `()()` |
| `)`       |                        0 | Skip outer closing | `()()` |

Output:

```text
()()
```

## Time Complexity

Every character is processed once.

* **Time:** `O(n)`

## Space Complexity

The counter uses `O(1)` auxiliary space, excluding the output string.

* **Auxiliary space:** `O(1)`
* **Output storage:** `O(n)`

---

# Approach Comparison

| Approach            | Time Complexity | Auxiliary Space | Key Idea                            |
| ------------------- | --------------- | --------------- | ----------------------------------- |
| Primitive Substring | `O(n)`          | `O(n)`          | Detect primitive boundaries         |
| Stack               | `O(n)`          | `O(n)`          | Track nesting using a stack         |
| Counter             | `O(n)`          | `O(1)`          | Track nesting depth with an integer |

## Edge Cases

1. **Input `()`** → output `""`
2. **Input `(())`** → output `()`
3. **Input `()()`** → output `""`
4. **Input `(()())`** → output `()()`
5. **Multiple primitives** → remove the outermost pair of each independently.

These approaches assume the input is a valid parentheses string, as specified by the problem.

## What I Learned

* A balance counter can identify the end of each primitive.
* A stack can distinguish outermost parentheses from inner parentheses.
* When only nesting depth matters, a counter is sufficient.
* The counter approach avoids the extra stack and achieves `O(1)` auxiliary space.

## Revision Shortcut

Remember:

```text
Opening '(':
    If balance > 0, append it.
    Increment balance.

Closing ')':
    Decrement balance.
    If balance > 0, append it.
```

## Final Takeaway

The counter approach is the most space-efficient of these three solutions: it processes the string in `O(n)` time with `O(1)` auxiliary space, excluding the output string.

**Core pattern:** Balanced Parentheses + Nesting Depth.
