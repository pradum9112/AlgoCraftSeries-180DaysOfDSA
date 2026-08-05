# 📘 Longest Subarray with Sum K (Brute Force)

## Approach

Check every possible subarray.

For every starting index:

- Start sum = 0
- Extend subarray
- Keep adding elements
- Whenever sum becomes K, update answer.

---

## Time Complexity

Current Solution

```
O(n²)
```

---

## Best Possible

```
O(n)
```

using Prefix Sum or Sliding Window.

---

## Space Complexity

```
O(1)
```

---

## Learning

✔ Nested Loops

✔ Subarray Generation

✔ Baseline Solution