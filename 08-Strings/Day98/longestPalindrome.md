# Day 98 — Longest Palindromic Substring

## Problem Statement

Given a string `s`, find and return its longest palindromic substring.

A palindrome is a string that reads the same forward and backward.

### Examples

**Example 1**

Input:
```text
s = "babad"
```

Output:
```text
"bab"
```

`"aba"` is also a valid answer because it has the same maximum length.

**Example 2**

Input:
```text
s = "cbbd"
```

Output:
```text
"bb"
```

## Approach 1 — Brute Force

### Idea / Approach

Generate every possible substring and check whether it is a palindrome.

1. Choose a starting index `i`.
2. Choose an ending index `j`, where `j >= i`.
3. Check whether the substring from `i` to `j` reads the same in both directions.
4. If it is a palindrome and longer than the current answer, update the answer.
5. Return the longest palindrome found.

The helper function `isPalindrome()` compares characters from both ends and moves inward.

### Pattern Recognition

**Pattern: Generate all substrings + validate each candidate.**

Use this approach when:
- Every possible substring is a candidate.
- A helper function can validate each candidate.
- You want a straightforward solution before optimizing.

### Dry Run

Input: `"babad"`

| Substring checked | Palindrome? | Longest so far |
|---|---|---|
| `"b"` | Yes | `"b"` |
| `"ba"` | No | `"b"` |
| `"bab"` | Yes | `"bab"` |
| `"baba"` | No | `"bab"` |
| `"babad"` | No | `"bab"` |
| `"a"` | Yes | `"bab"` |
| `"aba"` | Yes | `"bab"` |

The algorithm keeps `"bab"` because `"aba"` has the same length and the update only happens when a strictly longer palindrome is found.

Final answer: `"bab"`.

### Time Complexity

**O(n³)** — There are O(n²) possible substrings, and checking each substring for palindromicity can take O(n) time.

### Space Complexity

**O(1) auxiliary space**, excluding the returned substring and implementation-dependent string allocation costs.

## Approach 2 — Expand Around Center

### Idea / Approach

A palindrome mirrors around its center. Instead of generating every substring, choose a center and expand outward while the characters match.

There are two types of centers:

1. **Odd-length palindrome:** A single character is the center, such as `"racecar"`.
2. **Even-length palindrome:** The center lies between two characters, such as `"abba"`.

For every index `i`:

1. Expand from `(i, i)` to find the longest odd-length palindrome.
2. Expand from `(i, i + 1)` to find the longest even-length palindrome.
3. Select the larger length.
4. Update the start and end indices if the new palindrome is longer.
5. Return the corresponding substring.

### Pattern Recognition

**Pattern: Expand Around Center.**

Look for these clues:
- The problem asks for a palindrome.
- Characters on both sides of a center must match.
- Every palindrome has either one central character or a central pair.
- Expanding from each possible center avoids repeatedly checking every substring from scratch.

### Dry Run

Input: `"babad"`

| Center | Expansion | Palindrome length |
|---|---|---:|
| Index 0 (`b`) | `"b"` | 1 |
| Index 1 (`a`) | `"bab"` | 3 |
| Index 2 (`b`) | `"aba"` | 3 |
| Index 3 (`a`) | `"a"` | 1 |
| Index 4 (`d`) | `"d"` | 1 |

The longest palindrome length is `3`. Because the code updates only for a strictly longer result, the first maximum remains selected.

Final answer: `"bab"`.

### Time Complexity

**O(n²)** — There are O(n) possible centers, and each expansion can take O(n) time in the worst case.

### Space Complexity

**O(1) auxiliary space**, excluding the returned substring. The helper uses a constant number of variables and takes the input string by reference.

## Approach Comparison

| Property | Brute Force | Expand Around Center |
|---|---|---|
| Main technique | Generate and validate substrings | Expand from each center |
| Time complexity | O(n³) | O(n²) |
| Auxiliary space | O(1) | O(1) |
| Difficulty | Easier to understand | More efficient |
| Recommended | For learning the basic idea | For the final solution |

## Edge Cases

| Input | Expected output | Reason |
|---|---|---|
| `"a"` | `"a"` | Single character |
| `"cbbd"` | `"bb"` | Even-length palindrome |
| `"babad"` | `"bab"` or `"aba"` | Two maximum-length answers |
| `"racecar"` | `"racecar"` | Entire string is a palindrome |
| `"abcdef"` | Any one character | No longer palindrome exists |
| `""` | `""` | Empty string |

## What I Learned

- A palindrome reads the same in both directions.
- Brute force generates all substrings and checks each one.
- Expanding around centers reduces the time complexity from O(n³) to O(n²).
- Both odd-length and even-length palindromes must be checked.
- Passing the string as `const string&` avoids copying it for every expansion.
- Strictly greater length comparison preserves the first maximum when multiple answers have the same length.

## Revision Shortcut

**Brute force:** Generate → Check palindrome → Update longest.

**Optimized:** Odd center `(i, i)` → Even center `(i, i + 1)` → Expand while equal → Update longest.

## Final Takeaway

Expand Around Center is the recommended approach for this problem. It achieves **O(n²) time and O(1) auxiliary space**, making it significantly more efficient than checking every substring individually.
