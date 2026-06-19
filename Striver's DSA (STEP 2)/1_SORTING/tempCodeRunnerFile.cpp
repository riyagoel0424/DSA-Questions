#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Quick Sort Function
void quickSort(vector<char>& arr, int low, int high) {
    if (low >= high) return;
    char pivot = arr[low];
    int i = low + 1, j = high;
    while (i <= j) {
        while (i <= high && arr[i] <= pivot) i++;
        while (j >= low && arr[j] > pivot) j--;
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    quickSort(arr, low, j - 1);
    quickSort(arr, j + 1, high);
}

// Merge Sort Helper Functions
void merge(vector<char>& arr, int left, int mid, int right) {
    vector<char> temp;
    int i = left, j = mid + 1;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) temp.push_back(arr[i++]);
        else temp.push_back(arr[j++]);
    }
    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);
    for (int k = left; k <= right; k++) arr[k] = temp[k - left];
}

void mergeSort(vector<char>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// Main Function
int main() {
    // Quick Sort
    string str1 = "PANJABUNIVERSITY";
    vector<char> arr1(str1.begin(), str1.end());
    quickSort(arr1, 0, arr1.size() - 1);
    cout << "Quick Sort: ";
    for (char c : arr1) cout << c;
    cout << endl;

    // Merge Sort
    string str2 = "PANJABUNIVERSITY";
    vector<char> arr2(str2.begin(), str2.end());
    mergeSort(arr2, 0, arr2.size() - 1);
    cout << "Merge Sort: ";
    for (char c : arr2) cout << c;
    cout << endl;

    return 0;
}
