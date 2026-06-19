#include <iostream>
using namespace std;

// // Function to find the integer square root using binary search
int squareRoot(int n) {
    if (n == 0 || n == 1) // Base cases
        return n;

    int low = 0, high = n, ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2; // Avoid overflow
        long long square = mid * mid;

        if (square == n)
            return mid; // Exact square root found
        else if (square < n) {
            ans = mid;  // Store potential answer
            low = mid + 1; //        Search right half
        } else {
            high = mid - 1; // Search left half
        }
    }

    return ans; // Return floor value of square root
}

// // Main function
int main() {
    int n;
    cout << "Enter an integer: ";
    cin >> n;

    int result = squareRoot(n);
    cout << "Integer square root of " << n << " is: " << result << endl;

    

    return 0;
}

