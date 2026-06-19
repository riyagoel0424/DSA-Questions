#include <iostream>
#include <vector>

void add_element(std::vector<int>& array, int element) {
    array.push_back(element);
}

int main() {
    std::vector<int> arr = {1, 2, 3};
    add_element(arr, 4);
    
    for (int i : arr) {
        std::cout << i << " ";  // Output: 1 2 3 4
    }
    return 0;
}


#include <iostream>
#include <vector>

void insert_element(std::vector<int>& array, int element, int position) {
    if (position >= 0 && position <= array.size()) {
        array.insert(array.begin() + position, element);
    }
}

int main() {
    std::vector<int> arr = {1, 2, 3};
    insert_element(arr, 4, 1);
    
    for (int i : arr) {
        std::cout << i << " ";  // Output: 1 4 2 3
    }
    return 0;
}
