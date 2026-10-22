# Day 97 — Count Substrings with Exactly One Odd-Frequency Character

## Problem Statement

Given a string `s`, count all substrings in which **exactly one distinct character appears an odd number of times**.

For this implementation, the alphabet is assumed to contain only characters from `'a'` to `'j'`.

### Example

**Input**
```text
s = "abac"
```

**Output**
```text
4
```

**Explanation**

The valid substrings are:

- `"a"` — `a` occurs once.
- `"aba"` — `a` occurs twice and `b` occurs once.
- `"b"` — `b` occurs once.
- `"a"` — `a` occurs once.
- `"c"` — `c` occurs once.

Therefore, the correct total is **5**.

## Approach 1 — Brute Force with Frequency Counting

### Idea / Approach

Generate every possible substring by fixing a starting index `i` and extending the ending index `j`.

Maintain a frequency array and an `oddCount` variable:

1. Start a new substring with an empty frequency array.
2. Add each new character to the current substring.
3. Increment that character's frequency.
4. If its frequency becomes odd, increment `oddCount`.
5. If its frequency becomes even, decrement `oddCount`.
6. If `oddCount == 1`, increment the answer.

This avoids recounting every character in each substring from scratch.

### Pattern Recognition

**Pattern: Generate all substrings + maintain incremental state.**

Use this approach when:
- Every possible substring must be considered.
- A substring property can be updated when one new character is added.
- The input is small enough for quadratic time.

### Dry Run

Input: `"abac"`

| Substring | Odd-frequency characters | Valid? |
|---|---|---|
| `"a"` | `a` | Yes |
| `"ab"` | `a, b` | No |
| `"aba"` | `b` | Yes |
| `"abac"` | `b, c` | No |
| `"b"` | `b` | Yes |
| `"ba"` | `b, a` | No |
| `"bac"` | `b, a, c` | No |
| `"a"` | `a` | Yes |
| `"ac"` | `a, c` | No |
| `"c"` | `c` | Yes |

The valid substrings are `"a"`, `"aba"`, `"b"`, `"a"`, and `"c"`.

Final output: `5`.

### Time Complexity

**O(n²)** — There are O(n²) substrings, and each extension updates the frequency of one character in O(1) time.

### Space Complexity

**O(1)** — The frequency array has a fixed size of 10.

## Approach 2 — Prefix Parity Bitmask

### Idea / Approach

Represent character-frequency parity using bits:

- `0` means the character has appeared an even number of times.
- `1` means the character has appeared an odd number of times.

When a character appears, toggle its corresponding bit using XOR.

Maintain a prefix-mask frequency map. For each current mask, check the masks obtained by toggling exactly one bit. Each matching earlier prefix represents a substring with exactly one odd-frequency character.

Initialize the map with mask `0` occurring once to represent the empty prefix.

### Pattern Recognition

**Pattern: Prefix XOR / parity bitmask + frequency map.**

Look for these clues:

- The condition depends on whether frequencies are odd or even.
- A character's parity changes whenever it appears.
- A substring's parity can be found by XORing two prefix masks.
- Exactly one odd-frequency character means the two masks differ in exactly one bit.

### Dry Run

Input: `"abac"`

| Character | Prefix mask | New valid substrings | Running total |
|---|---|---:|---:|
| `a` | `a` | 1 | 1 |
| `b` | `a ⊕ b` | 1 | 2 |
| `a` | `b` | 2 | 4 |
| `c` | `b ⊕ c` | 1 | 5 |

Final output: `5`.

### Time Complexity

**O(10n)** expected time for an alphabet of 10 characters, because each character checks 10 possible one-bit differences.

### Space Complexity

**O(n)** for storing frequencies of previously seen prefix masks.

## Approach Comparison

| Property | Brute Force | Prefix Bitmask |
|---|---|---|
| Main technique | Nested loops and frequencies | Prefix parity and hash map |
| Time | O(n²) | Expected O(10n) |
| Extra space | O(1) | O(n) |
| Best use | Small inputs; easy to understand | Larger inputs; efficient counting |

## Important Correction: Sliding Window

The `atMostK(1) - atMostK(0)` sliding-window technique in the original submission is not generally valid for counting odd-frequency characters.

The number of odd-frequency characters does not increase monotonically as the window expands. For example, adding another `a` can change the number of odd-frequency characters from two to one.

Therefore, the usual sliding-window shrinking rule cannot guarantee correct counting for this property.

## Edge Cases

| Input | Output | Reason |
|---|---:|---|
| `"a"` | 1 | One odd-frequency character |
| `"aa"` | 2 | Both single-character substrings qualify |
| `"ab"` | 2 | Each single-character substring qualifies |
| `"abac"` | 5 | Five valid substrings |
| `""` | 0 | No substrings |

## What I Learned

- Frequency parity can be tracked by incrementing or decrementing an odd counter.
- XOR bitmasks encode the parity of multiple characters.
- Prefix masks can help count substrings by comparing earlier prefixes.
- A standard sliding window requires a suitable monotonic property; not every substring condition supports it.
- Always make the brute-force and optimized solutions count the same condition.

## Revision Shortcut

**Brute force:** Extend each substring and maintain its odd-frequency count.

**Optimized:** Toggle one bit per character, then count previous prefix masks differing in exactly one bit.

## Final Takeaway

The brute-force solution is straightforward and takes O(n²) time. The prefix-bitmask approach improves the expected running time to O(10n) for an alphabet of 10 characters, using O(n) additional space.
