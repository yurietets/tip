// 13 практическое занятие задание 3
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Task {
    string description;
    int priority;
    bool completed;
};
void printTasks(const vector<Task>& tasks, bool showAll = true) {
    if (tasks.empty()) {
        cout << "список задач пуст" << endl;
        return;
    }
    for (size_t i = 0; i < tasks.size(); ++i) {
        if (showAll || !tasks[i].completed) {
            cout << i + 1 << ". ";
            cout << (tasks[i].completed ? "[ВЫПОЛНЕНО] " : "[НЕ ВЫПОЛНЕНО] ");
            cout << tasks[i].description;
            cout << " (приоритет: " << tasks[i].priority << ")" << endl;
        }
    }
}
bool compareByPriority(const Task& a, const Task& b) {
    return a.priority < b.priority;
}
int main() {
    setlocale(LC_ALL, "Russian");
    vector<Task> taskList;
    int choice;
    do {
        cout << "меню" << endl;
        cout << "1 — Добавить задачу" << endl;
        cout << "2 — Отметить задачу как выполненную" << endl;
        cout << "3 — Удалить задачу" << endl;
        cout << "4 — Вывести все задачи" << endl;
        cout << "5 — Вывести только невыполненные задачи" << endl;
        cout << "6 — Вывести задачи по приоритету" << endl;
        cout << "0 — Выход" << endl;
        cout << "выберите пункт меню ";
        cin >> choice;
        vector<Task> sortedTasks;
        switch (choice) {
        case 1: {
            Task newTask;
            cin.ignore();
            cout << "введите описание задачи ";
            getline(cin, newTask.description);
            cout << "введите приоритет (1 - выс, 2 - ср, 3 - низ) ";
            cin >> newTask.priority;
            newTask.completed = false;
            taskList.push_back(newTask);
            cout << "задача добавлена" << endl;
            break;
        }
        case 2: {
            int num;
            cout << "введите номер задачи для выполнения ";
            cin >> num;
            if (num > 0 && num <= taskList.size()) {
                taskList[num - 1].completed = true;
                cout << "задача " << num << " выполнена" << endl;
            }
            else {
                cout << "неверный номер задачи" << endl;
            }
            break;
        }
        case 3: {
            int num;
            cout << "введите номер задачи для удаления ";
            cin >> num;
            if (num > 0 && num <= taskList.size()) {
                auto it = taskList.begin() + (num - 1);
                taskList.erase(it);
                cout << "задача " << num << " удалена" << endl;
            }
            else {
                cout << "неверный номер задачи" << endl;
            }
            break;
        }
        case 4:
            cout << "все задачи" << endl;
            printTasks(taskList, true);
            break;
        case 5:
            cout << "невыполненные задачи" << endl;
            printTasks(taskList, false);
            break;
        case 6:
            cout << "задачи по приоритету" << endl;
            sortedTasks = taskList;
            sort(sortedTasks.begin(), sortedTasks.end(), compareByPriority);
            printTasks(sortedTasks, true);
            break;
        case 0:
            cout << "выход из программы" << endl;
            break;
        default:
            cout << "неверный пункт меню" << endl;
            break;
        }
    } while (choice != 0);
    return 0;
}
