/// LOWER BOUND = SMALLEST INDEX OF ARRAY SUCH THAT
/// ----> ARR[INDEX] >= x      ... WHERE X IS THE GIVEN NUMBER
/// ARR[] = [3, 5, 8, 15, 19, 19]
/// INDEX    0  1  2  3   4   5

///  X = 6 , LB = 2
///  X = 19 , LB = 4
///  X = 30 , LB = 6      .... 6 IS THE IMAGINARY INDEX

///  LINEAR SEARCH IS NOT AN OPTIMAL APPROACH 
///  WHEN WE KNOW THE ARRAY IS SORTED ... WE WILL USE BINARY SEARCH TO FIND LOWER BOUND

// .........................................................................................

/// IN UPPER BOUND THE ONLY DIFFERENCE IS 
/// ----> ARR[INDEX] > x      ... WHERE X IS THE GIVEN NUMBER  .... NO = 
/// ARR[] = [3, 5, 8, 15, 19, 19]
/// INDEX    0  1  2  3   4   5

///  X = 1 , UB = 0
///  X = 6 , UB = 2
///  X = 19 , LB = 6
///  X = 30 , LB = 6      .... 6 IS THE IMAGINARY INDEX
