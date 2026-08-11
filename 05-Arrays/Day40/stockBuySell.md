# 📘 Day 40 - Best Time to Buy and Sell Stock

## Problem Statement

You are given an array `arr` where:

```text
arr[i] = stock price on day i
```

You need to choose:

- One day to **buy**
- A later day to **sell**

Return the **maximum profit** possible.

If no profit is possible, return:

```text
0
```

---

# Example

### Input

```text
7
7 1 5 3 6 4 8
```

### Output

```text
7
```

### Explanation

Buy at:

```text
1
```

Sell at:

```text
8
```

Profit:

```text
8 - 1 = 7
```

Therefore:

```text
Maximum Profit = 7
```

---

# Important Condition

You must:

```text
BUY first
SELL later
```

You cannot buy on a later day and sell on an earlier day.

So while traversing the array from left to right, we only consider prices seen so far as possible buying prices.

---

# Brute Force Approach

Try every possible buying day and every possible selling day.

For every pair:

```text
profit = sellingPrice - buyingPrice
```

Keep the maximum profit.

### Complexity

```text
Time  = O(n²)
Space = O(1)
```

This works but is inefficient for large arrays.

---

# Optimal Approach

We can solve the problem in one traversal.

We maintain two variables:

```cpp
int minPrice = arr[0];
int maxProfit = 0;
```

### `minPrice`

Stores the minimum stock price seen so far.

This represents the best price at which we could have bought the stock.

### `maxProfit`

Stores the maximum profit found so far.

---

# Core Idea

For every price:

### Step 1

Update the minimum price:

```cpp
minPrice = min(minPrice, arr[i]);
```

### Step 2

Calculate the profit if we sell today:

```cpp
currentProfit = arr[i] - minPrice;
```

### Step 3

Update maximum profit:

```cpp
maxProfit = max(maxProfit, currentProfit);
```

---

# Dry Run

Consider:

```text
arr = [7, 1, 5, 3, 6, 4, 8]
```

Initially:

```text
minPrice = 7
maxProfit = 0
```

---

## Day 1

Price:

```text
7
```

Minimum price:

```text
minPrice = min(7, 7)
         = 7
```

Profit:

```text
7 - 7 = 0
```

Maximum profit:

```text
maxProfit = 0
```

---

## Day 2

Price:

```text
1
```

Update minimum:

```text
minPrice = min(7, 1)
         = 1
```

Profit:

```text
1 - 1 = 0
```

State:

```text
minPrice = 1
maxProfit = 0
```

We have discovered a much better buying price:

```text
BUY at 1
```

---

## Day 3

Price:

```text
5
```

Minimum remains:

```text
minPrice = 1
```

If we sell today:

```text
profit = 5 - 1
       = 4
```

Update:

```text
maxProfit = 4
```

So far:

```text
Buy = 1
Sell = 5

Profit = 4
```

---

## Day 4

Price:

```text
3
```

Minimum:

```text
minPrice = 1
```

Profit:

```text
3 - 1 = 2
```

Maximum remains:

```text
maxProfit = 4
```

---

## Day 5

Price:

```text
6
```

Minimum:

```text
minPrice = 1
```

Profit:

```text
6 - 1 = 5
```

Update:

```text
maxProfit = 5
```

---

## Day 6

Price:

```text
4
```

Profit:

```text
4 - 1 = 3
```

Maximum remains:

```text
5
```

---

## Day 7

Price:

```text
8
```

Profit:

```text
8 - 1 = 7
```

Update:

```text
maxProfit = 7
```

Final answer:

```text
7
```

---

# Visualization

Think of the algorithm like this:

```text
Price:
7   1   5   3   6   4   8
    ↓
   MIN
```

We keep asking:

> "Aaj sell karun to ab tak ke cheapest buying price se kitna profit hoga?"

```text
minPrice = cheapest price seen so far

currentProfit = today's price - minPrice
```

Then:

```text
maxProfit = best profit seen so far
```

---

# Important Visualization

Three things are happening:

```text
             Cheapest Buy
                  ↓
7   1   5   3   6   4   8
    ↑               ↑
   BUY             SELL
```

At the end:

```text
BUY  = 1
SELL = 8

PROFIT = 8 - 1 = 7
```

---

# Why Do We Track `minPrice`?

Suppose:

```text
[7, 6, 4, 3, 1, 8]
```

When we reach `8`, we don't need to go back and check every previous price.

We already know:

```text
minimum price before 8 = 1
```

Therefore:

```text
profit = 8 - 1
       = 7
```

This eliminates the nested loop from the brute-force approach.

---

# Why Does `minPrice` Come Before Profit Calculation?

Conceptually:

```cpp
minPrice = min(minPrice, arr[i]);
```

then:

```cpp
currentProfit = arr[i] - minPrice;
```

This means the current price can become the cheapest buying price.

Since:

```text
arr[i] - arr[i] = 0
```

this does not create an invalid profit.

And for a valid positive profit, the minimum price must have occurred at an earlier day.

---

# What If Prices Always Fall?

Example:

```text
[7, 6, 5, 4, 3]
```

There is no profitable transaction.

The algorithm gives:

```text
maxProfit = 0
```

because we initialize:

```cpp
int maxProfit = 0;
```

So the answer correctly remains:

```text
0
```

---

# Complexity

## Brute Force

```text
Time  = O(n²)
Space = O(1)
```

## Optimal

```text
Time  = O(n)
Space = O(1)
```

We traverse the array only once.

---

# Comparison

| Approach | Time | Space |
|---|---:|---:|
| Brute Force | O(n²) | O(1) |
| Minimum Price Tracking | **O(n)** | **O(1)** |

---

# Key Learning

Remember these three variables/concepts:

```text
minPrice
currentProfit
maxProfit
```

For every price:

```text
1. Find cheapest buying price so far
2. Calculate today's possible profit
3. Keep the best profit
```

In short:

```text
MIN BUY → TODAY'S SELL → MAX PROFIT
```

---

# Revision Formula

```text
minPrice = min(minPrice, price)

profit = price - minPrice

maxProfit = max(maxProfit, profit)
```

---

# Pattern

This problem teaches:

- Greedy thinking
- One-pass array traversal
- Tracking minimum value
- Tracking maximum result
- Optimization from `O(n²)` to `O(n)`

The key greedy decision is:

> **Always remember the cheapest price seen so far, because that gives us the best possible buying point for the current day.**