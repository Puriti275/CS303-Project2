| Mode  | Size     | Elapsed Time | Memory     |
|-------|---------:|-------------:|-----------:|
| STL   |   100000 |        0.16s |   10.56 MB |
| STL   |   500000 |        0.72s |   38.10 MB |
| STL   |  1000000 |        1.42s |   73.60 MB |
| STL   | 10000000 |       14.48s |  741.84 MB |
| STL   | 25000000 |       37.25s | 1785.14 MB |
| QSORT |   100000 |        0.14s |   11.20 MB |
| QSORT |   500000 |        0.67s |   41.60 MB |
| QSORT |  1000000 |        1.37s |   79.80 MB |
| QSORT | 10000000 |       13.39s |  767.30 MB |
| QSORT | 25000000 |       33.22s | 1912.10 MB |
| MERGE |   100000 |        0.14s |    9.63 MB |
| MERGE |   500000 |        0.71s |   34.00 MB |
| MERGE |  1000000 |        1.32s |   64.50 MB |
| MERGE | 10000000 |       13.55s |  613.89 MB |
| MERGE | 25000000 |       35.07s | 1529.38 MB |
| QUICK |   100000 |        0.15s |    9.63 MB |
| QUICK |   500000 |        0.82s |   34.00 MB |
| QUICK |  1000000 |        1.56s |   64.50 MB |
| QUICK | 10000000 |       17.31s |  610.90 MB |
| QUICK | 25000000 |       43.55s | 1529.40 MB |


After you have performed your benchmark:

1) Discuss the relative performance of each sorting method and try to explain the differences.

2) What do these results reveal about the relationship between theoretical complexity discussed in class and actual performance?

3) In your opinion, which sorting mode is the best? Justify your conclusion by examining the trade-offs for the chosen mode.

   The sorting mode that's the best in my opinion is merge sort because it had the lowest amount of memory utilization as well as the second fastest time for large data (25M integers). Although QSort beat its time by 1.5 seconds, it also utilized 400MB more of memory! When this is scaled to large data for a workplace, it can cause the sorting algorithm to be useless due to hardware constraints.
   - Parker Myers

A brief summary of each group member's contributions to the project:

Andrew:

Joy:

Parker: Updated and completed the STL & QSort template using help from Maggie in lab, and the C++ references that were listed on the lab writeup. Testing the compilation, and timing the algorithms using usr/bin/time, and creating the test files with benchmark.cpp.
