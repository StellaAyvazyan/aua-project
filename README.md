# Sorting Visualizer

A console-based Java tool that visualizes sorting algorithms step by step using ASCII bar charts, with real-time comparison and swap counters.

## Overview

This program lets you watch how Bubble Sort, Insertion Sort, Merge Sort, and Quick Sort work on a custom array of integers. At each comparison and swap, the current state of the array is printed as a bar chart so you can follow exactly how elements move.

## How to Run

**Requirements:** Java JDK 8 or later

**1. Compile**
```bash
javac SortingVisualizer.java
```

**2. Run**
```bash
java SortingVisualizer
```

**3. Follow the prompts**
```
Enter size: 5
Enter numbers:
4 2 7 1 5
1. Bubble
2. Insertion
3. Merge
4. Quick
Choose: 1
```

The visualization will print to the console automatically.

## Algorithms Supported

| # | Algorithm | Time Complexity |
|---|-----------|----------------|
| 1 | Bubble Sort | O(n²) |
| 2 | Insertion Sort | O(n²) |
| 3 | Merge Sort | O(n log n) |
| 4 | Quick Sort | O(n log n) avg |

## Example Output

```
Comparing: 4 and 2
Comparisons: 1  Swaps/Moves: 0
 4: ####
 2: ##
 7: #######
 1: #
 5: #####
----------------------
```

---

*Author: Stella Ayvazyan — May 8, 2026*
