# Day 99 — Sum of Beauty of All Substrings

## Problem Statement

Given a string `s`, return the sum of the beauty of all its substrings.

The **beauty of a substring** is defined as:

**Beauty = Maximum character frequency − Minimum character frequency**

Only characters that appear in the substring are considered when finding the minimum frequency. Characters with frequency zero must be ignored.

### Example 1

**Input**
```text
s = "aabcb"
```

**Output**
```text
5
```

**Explanation**

Consider the substrings whose beauty is greater than zero:

| Substring | Character frequencies | Beauty |
|---|---|---:|
| `"aab"` | a: 2, b: 1 | 1 |
| `"aabc"` | a: 2, b: 1, c: 1 | 1 |
| `"aabcb"` | a: 2, b: 2, c: 1 | 1 |
| `"abcb"` | a: 1, b: 2, c: 1 | 1 |
| `"bcb"` | b: 2, c: 1 | 1 |

The beauty of all other substrings is zero.

Total beauty = 1 + 1 + 1 + 1 + 1 = **5**.

## Approach 1 — Brute Force with Frequency Counting

### Idea / Approach

Generate every possible substring and calculate its beauty using a frequency array.

1. Fix a starting index `i`.
2. Initialize a frequency array of size 26 with zeros.
3. Extend the ending index `j` one character at a time.
4. Update the frequency of the newly included character.
5. Scan the frequency array to find the maximum and minimum non-zero frequencies.
6. Add `maxFreq - minFreq` to `totalBeauty`.
7. Repeat for every starting index and return the accumulated total.

The frequency array is reset for every new starting position, but within each starting position, the frequencies are updated incrementally.

### Pattern Recognition

**Pattern: Enumerate all substrings + maintain frequencies.**

Look for these clues:

- The problem asks for a result over every possible substring.
- Each substring has a property based on character frequencies.
- Adding a character can update the frequency array without rebuilding the substring.
- The alphabet is limited to lowercase English letters, so a fixed-size array is sufficient.

### Dry Run

Input: `"aabcb"`

| Starting index | Substring | Max frequency | Min frequency | Beauty |
|---:|---|---:|---:|---:|
| 0 | `"a"` | 1 | 1 | 0 |
| 0 | `"aa"` | 2 | 2 | 0 |
| 0 | `"aab"` | 2 | 1 | 1 |
| 0 | `"aabc"` | 2 | 1 | 1 |
| 0 | `"aabcb"` | 2 | 1 | 1 |
| 1 | `"a"` | 1 | 1 | 0 |
| 1 | `"ab"` | 1 | 1 | 0 |
| 1 | `"abc"` | 1 | 1 | 0 |
| 1 | `"abcb"` | 2 | 1 | 1 |
| 2 | `"b"` | 1 | 1 | 0 |
| 2 | `"bc"` | 1 | 1 | 0 |
| 2 | `"bcb"` | 2 | 1 | 1 |

The remaining substrings also contribute zero beauty.

Final answer: **5**.

### Time Complexity

**O(n² × 26)** — There are O(n²) substrings. For every substring extension, the algorithm scans all 26 frequency entries.

Since 26 is constant, the time complexity simplifies to **O(n²)**.

### Space Complexity

**O(1)** auxiliary space — The frequency array always contains 26 entries, independent of the string length.

## Edge Cases

| Input | Expected output | Reason |
|---|---:|---|
| `"a"` | 0 | Only one character frequency |
| `"aa"` | 0 | All present characters have equal frequencies |
| `"ab"` | 0 | Both characters occur once |
| `"aabcb"` | 5 | Five substrings have beauty 1 |
| `"aaaa"` | 0 | Every substring has only one distinct character |

## What I Learned

- Beauty is the difference between the maximum and minimum frequencies of present characters.
- Characters with zero frequency must not be considered for the minimum.
- A frequency array can be updated incrementally as a substring grows.
- Nested loops can enumerate all substrings.
- A fixed alphabet allows O(1) auxiliary space for frequency tracking.

## Revision Shortcut

**Fix start → reset frequencies → extend end → update frequency → find max/min → add beauty.**

Formula:

`totalBeauty += maxFreq - minFreq`

## Final Takeaway

The brute-force solution efficiently maintains character frequencies while enumerating every substring. Its time complexity is **O(n²)** for a fixed alphabet of 26 lowercase English letters, with **O(1) auxiliary space**.
