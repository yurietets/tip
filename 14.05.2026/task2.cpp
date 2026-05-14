// 13 практическое занятие задание 2
#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>
using namespace std;

double calculateAverage(const array<int, 15>& grades) {
    int sum = accumulate(grades.begin(), grades.end(), 0);
    return static_cast<double>(sum) / grades.size();
}
int countExcellent(const array<int, 15>& grades) {
    return count(grades.begin(), grades.end(), 5);
}
int countUnsatisfactory(const array<int, 15>& grades) {
    return count_if(grades.begin(), grades.end(),
        [](int grade) { return grade <= 2; });
}
void printGradeDistribution(const array<int, 15>& grades) {
    cout << "гистрограмма" << endl;
    for (int mark = 5; mark >= 1; --mark) {
        int count = std::count(grades.begin(), grades.end(), mark);
        cout << mark << ": ";
        for (int i = 0; i < count; ++i) {
            cout << "*";
        }
        cout << " (" << count << ")" << endl;
    }
}
int main() {
    array<int, 15> grades;
    cout << "введите оценки для 15 студентов, от 1 до 5" << endl;
    for (int i = 0; i < grades.size(); ++i) {
        int grade;
        do {
            cin >> grade;
            if (grade < 1 || grade > 5) {
                cout << "оценка должна быть от 1 до 5" << endl;
            }
        } while (grade < 1 || grade > 5);
        grades[i] = grade;
    }
    cout << "статистика" << endl;
    cout << "средний балл: " << calculateAverage(grades) << endl;
    cout << "колво отличников: " << countExcellent(grades) << endl;
    cout << "колво неуспевающих: " << countUnsatisfactory(grades) << endl;
    printGradeDistribution(grades);
    return 0;
}
