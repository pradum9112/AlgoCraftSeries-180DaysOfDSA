# Day 60 — Maximum Product Subarray

## 📌 Problem Statement

Given an integer array `nums`, find the contiguous subarray that has the largest product.

Return the maximum product.

---

## 🧪 Example

### Input

```text
5
2 3 -2 4 -1
```

### Your Output

```text
48
```

### Explanation

The maximum-product subarray is:

```text
[2, 3, -2, 4, -1]
```

Its product is:

```text
2 × 3 × (-2) × 4 × (-1) = 48
```

Therefore:

```text
Answer = 48
```

---

# 🔍 Pattern Recognition Clue

Is problem ko dekhte hi notice karo:

```text
CONTIGUOUS SUBARRAY
        +
PRODUCT
        +
NEGATIVE NUMBERS
        ↓
Negative × Negative = Positive
```

### Strong clue

Maximum **sum** mein hum Kadane's Algorithm use karte hain.

Lekin maximum **product** mein ek important problem hai:

```text
Negative number
```

kyunki:

```text
Positive × Negative = Negative

Negative × Negative = Positive
```

Isliye sirf `maximum product` track karna enough nahi hai.

Humein:

```text
MAXIMUM PRODUCT
+
MINIMUM PRODUCT
```

dono track karne padte hain.

---

# Approach 1 — Brute Force

Har possible subarray generate karo.

For example:

```text
[2, 3, -2]
```

Possible subarrays:

```text
[2]
[2, 3]
[2, 3, -2]

[3]
[3, -2]

[-2]
```

Har subarray ka product calculate karo aur maximum store karo.

### Complexity

```text
Time  = O(N³)
Space = O(1)
```

---

# Approach 2 — Prefix + Suffix

Product mein `0` problem create karta hai.

Example:

```text
[2, 3, 0, -2, 4]
```

Zero ke baad product continue karna useful nahi hota.

Isliye hum:

```text
prefix product
```

aur

```text
suffix product
```

calculate karte hain.

Example:

```text
[2, 3, -2, 4]
```

Prefix:

```text
2
2 × 3 = 6
6 × -2 = -12
-12 × 4 = -48
```

Suffix:

```text
4
4 × -2 = -8
-8 × 3 = -24
-24 × 2 = -48
```

Dono directions check karne se negative numbers ke effect ko handle kar sakte hain.

### Complexity

```text
Time  = O(N)
Space = O(1)
```

---

# Approach 3 — Optimal: Maximum + Minimum Product

Yahi sabse important approach hai.

Hum har position par do cheezein maintain karte hain:

```text
maxProd
minProd
```

### Why both?

Suppose:

```text
maxProd = 6
minProd = -12
```

Next number:

```text
-2
```

Then:

```text
6 × -2 = -12
```

but:

```text
-12 × -2 = 24
```

Dekho!

Jo `minimum` tha:

```text
-12
```

negative number ke saath multiply hokar:

```text
24
```

maximum ban gaya.

Therefore:

```text
MINIMUM × NEGATIVE
          ↓
      MAXIMUM
```

Isi wajah se maximum aur minimum dono store karne padte hain.

---

# 🔥 Negative Number Par Swap

Code:

```cpp
if (nums[i] < 0) {
    swap(maxProd, minProd);
}
```

Suppose:

```text
maxProd = 6
minProd = -12
```

Aur current number:

```text
-2
```

Negative multiply karne par:

```text
6 × -2  = -12
-12 × -2 = 24
```

Toh old:

```text
max → negative
min → positive
```

effectively reverse ho jata hai.

Isliye pehle:

```text
swap(maxProd, minProd)
```

karte hain.

---

# 🔄 Dry Run

Array:

```text
[2, 3, -2, 4]
```

Initial:

```text
maxProd = 2
minProd = 2
result  = 2
```

### i = 1

Current:

```text
3
```

No negative.

Calculate:

```text
max(3, 2 × 3)
= 6
```

and:

```text
min(3, 2 × 3)
= 3
```

Now:

```text
maxProd = 6
minProd = 3
result = 6
```

---

### i = 2

Current:

```text
-2
```

Negative hai.

Swap:

```text
maxProd = 3
minProd = 6
```

Then:

```text
maxProd = max(-2, 3 × -2)
        = -2
```

```text
minProd = min(-2, 6 × -2)
        = -12
```

Result:

```text
result = 6
```

---

### i = 3

Current:

```text
4
```

Positive hai.

```text
maxProd = max(4, -2 × 4)
        = 4
```

```text
minProd = min(4, -12 × 4)
        = -48
```

Result:

```text
max(6, 4) = 6
```

Answer:

```text
6
```

---

# ⚠️ Zero ka Role

Example:

```text
[2, 3, 0, 4, 5]
```

Zero product ko tod deta hai:

```text
2 × 3 = 6
6 × 0 = 0
```

Zero ke baad ek naya subarray start ho sakta hai.

Isi concept ko Prefix + Suffix approach mein reset karke handle kiya jata hai.

---

# 📊 Complexity

| Approach         |  Time | Space |
| ---------------- | ----: | ----: |
| Brute Force      | O(N³) |  O(1) |
| Prefix + Suffix  |  O(N) |  O(1) |
| Max/Min Tracking |  O(N) |  O(1) |

---

# 🧠 Core Learning

Maximum subarray sum:

```text
Kadane's Algorithm
→ current sum
→ reset when negative
```

Maximum subarray product:

```text
Negative changes the game
        ↓
Track MAX + MIN
        ↓
Negative can turn MIN into MAX
```

### One-line memory trick

```text
MAXIMUM PRODUCT
      ↓
Negative number?
      ↓
MINIMUM bhi yaad rakho!
```

---

# 🎯 Final Pattern

```text
Contiguous Subarray
        ↓
Product
        ↓
Negative numbers present
        ↓
Negative × Negative = Positive
        ↓
Track Maximum + Minimum
```

**Day 60 takeaway:**

> Product problems mein negative number ko kabhi ignore mat karo. Jo minimum product hai, wahi next negative ke baad maximum ban sakta hai.
