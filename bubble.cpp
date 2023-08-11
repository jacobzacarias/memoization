#include <iostream>
#include <algorithm>

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    std::sort(arr, arr + sizeof(arr) / sizeof(arr[0]));
    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    return 0;
}
