// 13 практическое занятие задание 1
#include <iostream>
#include <array>
using namespace std;

void printArray(const array<int, 10>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int sumArray(const array<int, 10>& arr) {
    int sum = 0;
    for (int value : arr) {
        sum += value;
    }
    return sum;
}
double averageArray(const array<int, 10>& arr) {
    return static_cast<double>(sumArray(arr)) / arr.size();
}
int findMax(const array<int, 10>& arr) {
    int max_val = arr[0];
    for (int value : arr) {
        if (value > max_val) {
            max_val = value;
        }
    }
    return max_val;
}
int findMin(const array<int, 10>& arr) {
    int min_val = arr[0];
    for (int value : arr) {
        if (value < min_val) {
            min_val = value;
        }
    }
    return min_val;
}
int main() {
    array<int, 10> myArray;
    for (int i = 0; i < myArray.size(); ++i) {
        myArray[i] = i;
    }
    cout << "исходный массив: ";
    printArray(myArray);
    cout << "сумма элементов: " << sumArray(myArray) << endl;
    cout << "среднее арифметическое: " << averageArray(myArray) << endl;
    cout << "максимальный элемент: " << findMax(myArray) << endl;
    cout << "минимальный элемент: " << findMin(myArray) << endl;
    myArray.fill(42);
    cout << "массив после fill(42): ";
    printArray(myArray);
    array<int, 10> copyArray = myArray;
    cout << "копия массива: ";
    printArray(copyArray);
    return 0;
}
