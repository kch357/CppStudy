#include <iostream>

int arr[3] = {0, 1, 2};
int(&ref)[sizeof(arr)/4] = arr;

int main() {
    std::cout << ref[2] << std::endl;
}