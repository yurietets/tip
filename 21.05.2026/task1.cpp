// 14 практическое занятие задача 1
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    vector<int> numbers(30);
    srand(67);
    for (int i = 0; i < 30; ++i) { numbers[i] = rand() % 201 - 100; }
    int sum = accumulate(numbers.begin(), numbers.end(), 0);
    double average = static_cast<double>(sum) / 30;
    auto minMax = minmax_element(numbers.begin(), numbers.end());
    int minElement = *minMax.first;
    int maxElement = *minMax.second;
    int positiveCount = count_if(numbers.begin(), numbers.end(), [](int x) { return x > 0; });
    int negativeCount = count_if(numbers.begin(), numbers.end(), [](int x) { return x < 0; });
    int zeroCount = count_if(numbers.begin(), numbers.end(), [](int x) { return x == 0; });
    int a, b;
    cout << "введите диапазон a - b: ";
    cin >> a >> b;
    int abCount = count_if(numbers.begin(), numbers.end(), [a, b](int x) { return x >= a && x <= b; });
    bool multiSeven = any_of(numbers.begin(), numbers.end(), [](int x) { return x % 7 == 0; });
    bool allUnder200 = all_of(numbers.begin(), numbers.end(), [](int x) { return abs(x) <= 200; });
    cout << "результаты анализа \n";
    cout << "сумма всех элементов: " << sum << "\n";
    cout << "среднее арифметическое: " << average << "\n";
    cout << "минимальный элемент: " << minElement << "\n";
    cout << "максимальный элемент: " << maxElement << "\n";
    cout << "количество положительных: " << positiveCount << "\n";
    cout << "количество отрицательных: " << negativeCount << "\n";
    cout << "количество нулевых: " << zeroCount << "\n";
    cout << "в диапазоне [" << a << ", " << b << "]: " << abCount << " элементов\n";
    cout << "есть число, кратное 7: " << (multiSeven ? "да" : "нет") << "\n";
    cout << "все числа <= 200 по модулю: " << (allUnder200 ? "да" : "нет") << "\n";
    return 0;
}
