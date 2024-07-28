#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Task {
    int id;
    string description;
    bool isComplete;
};

vector<Task> tasks;
int idCounter = 1;

void addTask();
void markTask();
void showTasks();
void delTasks();

int main() {
    int choice;

    do {
        cout << "Todo App version 1.0.0\n";
        showTasks();
        cout << "1. Add task\n";
        cout << "2. Mark task\n";
        cout << "3. Close app\n";
        cout << "Your choice is: ";
        cin >> choice;
        
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case 1:
            addTask();
            break;
        case 2:
            markTask();
            break;
        case 3:
            cout << "Program Ending...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}

void addTask() {
    Task newTask;
    string description;

    cout << "Enter your new task: ";
    getline(cin >> ws, description);

    if (!description.empty()) {
        newTask.id = idCounter++;
        newTask.description = description;
        newTask.isComplete = false;

        tasks.push_back(newTask);

        cout << "Task added successfully!\n";
        cout << "Task id is " << newTask.id << endl;
        cout << "\n";
    }
    else {
        cout << "Task description cannot be empty.\n";
    }
}

void markTask() {
    int checkedId;
    cout << "Enter the task ID that you want to mark as completed: ";
    cin >> checkedId;

    
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    bool found = false;

    for (auto& task : tasks) {
        if (task.id == checkedId) {
            task.isComplete = true;
            cout << "Task with ID " << checkedId << " has been marked as completed.\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "The ID number is not found in the task list.\n";
    }
}


void showTasks() {
    cout << "\nTask List: \n";
    cout << "******************\n\n";
    for (const auto& task : tasks) {
        cout << task.id << ". Task : " << task.description << ",->  Satus : " << (task.isComplete ? "Done" : "In process") << endl;
        cout << "--\n";
    }
    cout << "\n\n";
}

