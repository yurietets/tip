// 14 практическое занятие задача 4
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

struct student {
    string name;
    string group;
    vector<int> grades = { 0, 0, 0 };
    double getAverage() const {
        return static_cast<double>(accumulate(grades.begin(), grades.end(), 0)) / 3; }
    bool allFives() const { return all_of(grades.begin(), grades.end(), [](int grade) { return grade == 5; }); }
    bool hasTwo() const { return any_of(grades.begin(), grades.end(), [](int grade) { return grade == 2; }); }
};
int main() {
    setlocale(LC_ALL, "Russian");
    vector<student> students = {
        {"Давид", "EFBO-09-25", {4, 5, 4}},
        {"Разен", "EFBO-09-25", {5, 5, 5}},
        {"Ярик", "EFBO-09-25", {3, 4, 3}},
        {"Юра", "EFBO-10-25", {2, 4, 3}},
        {"Сеня", "EFBO-10-25", {4, 4, 5}},
        {"Вова", "EFBO-10-25", {5, 4, 5}},
        {"Дима", "EFBO-09-25", {3, 3, 4}},
        {"Хабиб", "EFBO-11-25", {4, 4, 4}},
        {"Федя", "EFBO-11-25", {5, 5, 4}},
        {"Антон", "EFBO-11-25", {2, 2, 3}},
    };
    string searchGroup;
    cout << "введите номер группы для поиска: ";
    cin >> searchGroup;
    cout << "\n студенты группы " << searchGroup << ": \n";
    bool found = false;
    for (const auto& student : students) {
        if (student.group == searchGroup) {
            cout << student.name << " - " << student.group
                << " - ср. балл: " << student.getAverage() << "\n";
            found = true;
        }
    }
    if (!found) { cout << "в группе " << searchGroup << " нет студентов \n"; }
    cout << endl;
    auto bestStudent = max_element(students.begin(), students.end(), [](const student& a, const student& b) { return a.getAverage() < b.getAverage(); });
    cout << "студент с максимальным ср баллом: " << bestStudent->name << " - ср балл: " << bestStudent->getAverage() << " \n";
    int studentsWithTwo = count_if(students.begin(), students.end(), [](const student& s) { return s.hasTwo(); });
    cout << "количество студентов с двойками: " << studentsWithTwo << "\n";
    sort(students.begin(), students.end(),
        [](const student& a, const student& b) { return a.getAverage() > b.getAverage(); });
    cout << "студенты по убыванию среднего балла: \n";
    for (const auto& student : students) {
        cout << student.name << " - " << student.group
            << " - ср балл: " << student.getAverage() << " \n";
    }
    cout << endl;
    cout << "студенты-отличники: \n";
    bool super = false;
    for (const auto& student : students) {
        if (student.getAverage() >= 4.5) {
            cout << student.name << " - " << student.group
                << " - ср балл: " << student.getAverage() << " \n";
            super = true;
        }
    }
    if (!super) {
        cout << "отличников нет \n";
    }
    cout << endl;
    bool anyAllFives = any_of(students.begin(), students.end(), [](const student& s) { return s.allFives(); });
    cout << "есть ли студенты со всеми пять: " << (anyAllFives ? "да" : "нет") << "\n";
    return 0;
}
