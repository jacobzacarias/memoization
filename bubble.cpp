#include <iostream>
#include <algorithm>  // Include the algorithm library for sorting

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};

    // Calculate the size of the array
    int size = sizeof(arr) / sizeof(arr[0]);

    // Check if the array is empty
    if (size == 0) {
        std::cerr << "Array is empty!" << std::endl;
        return 1; // Indicate error with a non-zero exit code
    }

    // Sort the array in ascending order using the std::sort function
    std::sort(arr, arr + size);

    // Print the sorted array in ascending order
    std::cout << "Sorted array in ascending order: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Sort the array in descending order
    std::sort(arr, arr + size, std::greater<int>());

    // Print the sorted array in descending order
    std::cout << "Sorted array in descending order: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
