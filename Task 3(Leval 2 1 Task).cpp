#include <iostream>
#include <vector>
#include <string>

// Task class definition
class Task {
public:
    int id;
    std::string title;
    std::string description;

    Task(int id, const std::string& title, const std::string& description)
        : id(id), title(title), description(description) {}
};

// Function declarations
void createTask(std::vector<Task>& tasks, int& currentId);
void readTasks(const std::vector<Task>& tasks);
void updateTask(std::vector<Task>& tasks);
void deleteTask(std::vector<Task>& tasks);

int main() {
    std::vector<Task> tasks;
    int currentId = 1; // To assign unique IDs to tasks
    int choice;

    while (true) {
        std::cout << "\nTask Manager\n";
        std::cout << "1. Create Task\n";
        std::cout << "2. Read Tasks\n";
        std::cout << "3. Update Task\n";
        std::cout << "4. Delete Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                createTask(tasks, currentId);
                break;
            case 2:
                readTasks(tasks);
                break;
            case 3:
                updateTask(tasks);
                break;
            case 4:
                deleteTask(tasks);
                break;
            case 5:
                return 0;
            default:
                std::cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}

void createTask(std::vector<Task>& tasks, int& currentId) {
    std::string title, description;
    std::cin.ignore(); // Clear the input buffer
    std::cout << "Enter task title: ";
    std::getline(std::cin, title);
    std::cout << "Enter task description: ";
    std::getline(std::cin, description);
    
    tasks.emplace_back(currentId++, title, description);
    std::cout << "Task created successfully!\n";
}

void readTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks available.\n";
        return;
    }
    for (const auto& task : tasks) {
        std::cout << "ID: " << task.id << "\nTitle: " << task.title << "\nDescription: " << task.description << "\n\n";
    }
}

void updateTask(std::vector<Task>& tasks) {
    int id;
    std::cout << "Enter task ID to update: ";
    std::cin >> id;
    std::cin.ignore(); // Clear the input buffer
    
    for (auto& task : tasks) {
        if (task.id == id) {
            std::string title, description;
            std::cout << "Enter new task title: ";
            std::getline(std::cin, title);
            std::cout << "Enter new task description: ";
            std::getline(std::cin, description);
            task.title = title;
            task.description = description;
            std::cout << "Task updated successfully!\n";
            return;
        }
    }
    std::cout << "Task with ID " << id << " not found.\n";
}

void deleteTask(std::vector<Task>& tasks) {
    int id;
    std::cout << "Enter task ID to delete: ";
    std::cin >> id;
    std::cin.ignore(); // Clear the input buffer

    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->id == id) {
            tasks.erase(it);
            std::cout << "Task deleted successfully!\n";
            return;
        }
    }
    std::cout << "Task with ID " << id << " not found.\n";
}
