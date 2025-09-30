#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <limits>

// Forward declaration
class TaskObserver;

// Subject interface
class ISubject {
public:
    virtual ~ISubject() = default;
    virtual void attach(std::shared_ptr<TaskObserver> observer) = 0;
    virtual void detach(std::shared_ptr<TaskObserver> observer) = 0;
    virtual void notify() = 0;
};

// Observer interface
class TaskObserver {
public:
    virtual ~TaskObserver() = default;
    virtual void update(const std::vector<std::string>& tasks, float temperature) = 0;
    virtual std::string getName() const = 0;
};

// Subject (To-Do List) implementation
class TodoList : public ISubject {
private:
    std::vector<std::shared_ptr<TaskObserver>> observers;
    std::vector<std::string> tasks;
    float currentTemperature = 20.0f; // Default temperature

public:
    void attach(std::shared_ptr<TaskObserver> observer) override {
        observers.push_back(observer);
        std::cout << "Attached observer: " << observer->getName() << std::endl;
    }
    
    void detach(std::shared_ptr<TaskObserver> observer) override {
        auto it = std::find(observers.begin(), observers.end(), observer);
        if (it != observers.end()) {
            std::cout << "Detached observer: " << (*it)->getName() << std::endl;
            observers.erase(it);
        }
    }
    
    void notify() override {
        for (const auto& observer : observers) {
            observer->update(tasks, currentTemperature);
        }
    }
    // Add task and notify observers
    void addTask(const std::string& task) {
        if (!task.empty()) {
            tasks.push_back(task);
            std::cout << "Task added: " << task << std::endl;
            notify();
        } else {
            std::cout << "Cannot add an empty task!" << std::endl;
        }
    }
    
    // Remove task and notify observers
    void removeTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            std::string removedTask = tasks[index];
            tasks.erase(tasks.begin() + index);
            std::cout << "Task removed: " << removedTask << std::endl;
            notify();
        } else {
            std::cout << "Invalid task index!" << std::endl;
        }
    }
    
    // Update temperature and notify observers
    void updateTemperature(float temp) {
        if (temp >= -50.0f && temp <= 60.0f) { // Reasonable temperature range
            currentTemperature = temp;
            std::cout << "Temperature updated to: " << temp << "°C" << std::endl;
            notify();
        } else {
            std::cout << "Temperature out of reasonable range (-50°C to 60°C)!" << std::endl;
        }
    }
    
    // Get current tasks
    std::vector<std::string> getTasks() const {
        return tasks;
    }
    
    // Get current temperature
    float getTemperature() const {
        return currentTemperature;
    }
    
    // Display current state
    void displayState() const {
        std::cout << "\n--- Current To-Do List State ---" << std::endl;
        std::cout << "Temperature: " << currentTemperature << "°C" << std::endl;
        std::cout << "Tasks:" << std::endl;
        if (tasks.empty()) {
            std::cout << "  No tasks" << std::endl;
        } else {
            for (size_t i = 0; i < tasks.size(); i++) {
                std::cout << "  " << i + 1 << ". " << tasks[i] << std::endl;
            }
        }
        std::cout << "Observers: " << observers.size() << std::endl;
        std::cout << "--------------------------------" << std::endl;
    }
};

// Concrete Observers
class ConsoleDisplay : public TaskObserver {
public:
    void update(const std::vector<std::string>& tasks, float temperature) override {
        std::cout << "\n--- Console Display Update ---" << std::endl;
        std::cout << "Temperature: " << temperature << "°C" << std::endl;
        std::cout << "Tasks:" << std::endl;
        if (tasks.empty()) {
            std::cout << "  No tasks" << std::endl;
        } else {
            for (size_t i = 0; i < tasks.size(); i++) {
                std::cout << "  " << i + 1 << ". " << tasks[i] << std::endl;
            }
        }
        std::cout << "-------------------------------" << std::endl;
    }
    
    std::string getName() const override {
        return "ConsoleDisplay";
    }
};

class TemperatureAlert : public TaskObserver {
public:
    void update(const std::vector<std::string>& tasks, float temperature) override {
        if (temperature > 30.0f) {
            std::cout << "🔥 HOT WEATHER ALERT! (" << temperature << "°C) Consider moving indoor tasks to top." << std::endl;
        } else if (temperature < 5.0f) {
            std::cout << "❄️  COLD WEATHER ALERT! (" << temperature << "°C) Dress warmly for outdoor tasks." << std::endl;
        }
    }
    
    std::string getName() const override {
        return "TemperatureAlert";
    }
};

class TaskCounter : public TaskObserver {
public:
    void update(const std::vector<std::string>& tasks, float temperature) override {
        std::cout << "📊 Task count: " << tasks.size() << " tasks in your list." << std::endl;
    }
    
    std::string getName() const override {
        return "TaskCounter";
    }
};

// Input validation functions
int getValidatedIntInput(const std::string& prompt, int min, int max) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value && value >= min && value <= max) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        } else {
            std::cout << "Invalid input. Please enter a number between " << min << " and " << max << "." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

float getValidatedFloatInput(const std::string& prompt, float min, float max) {
    float value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value && value >= min && value <= max) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        } else {
            std::cout << "Invalid input. Please enter a number between " << min << " and " << max << "." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

// Main function with enhanced terminal interaction
int main() {
    TodoList myTodoList;
    
    // Create observers with shared pointers
    auto console = std::make_shared<ConsoleDisplay>();
    auto alert = std::make_shared<TemperatureAlert>();
    auto counter = std::make_shared<TaskCounter>();
    
    // Attach observers
    myTodoList.attach(console);
    myTodoList.attach(alert);
    myTodoList.attach(counter);
    
    std::cout << "======================================" << std::endl;
    std::cout << "   Smart To-Do List Management System" << std::endl;
    std::cout << "   Using Observer Pattern (Industry Standard)" << std::endl;
    std::cout << "======================================" << std::endl;
    
    while (true) {
        std::cout << "\nMain Menu:" << std::endl;
        std::cout << "1. Add task" << std::endl;
        std::cout << "2. Remove task" << std::endl;
        std::cout << "3. Update temperature" << std::endl;
        std::cout << "4. Display current state" << std::endl;
        std::cout << "5. Manage observers" << std::endl;
        std::cout << "6. Exit" << std::endl;
        
        int choice = getValidatedIntInput("Enter choice (1-6): ", 1, 6);
        
        if (choice == 1) {
            std::string task;
            std::cout << "Enter task: ";
            std::getline(std::cin, task);
            myTodoList.addTask(task);
        } else if (choice == 2) {
            auto tasks = myTodoList.getTasks();
            if (tasks.empty()) {
                std::cout << "No tasks to remove!" << std::endl;
            } else {
                std::cout << "Current tasks:" << std::endl;
                for (size_t i = 0; i < tasks.size(); i++) {
                    std::cout << "  " << i + 1 << ". " << tasks[i] << std::endl;
                }
                int taskIndex = getValidatedIntInput("Enter task number to remove: ", 1, tasks.size()) - 1;
                myTodoList.removeTask(taskIndex);
            }
        } else if (choice == 3) {
            float temp = getValidatedFloatInput("Enter temperature (-50 to 60): ", -50.0f, 60.0f);
            myTodoList.updateTemperature(temp);
        } else if (choice == 4) {
            myTodoList.displayState();
        } else if (choice == 5) {
            std::cout << "\nObserver Management:" << std::endl;
            std::cout << "1. Attach ConsoleDisplay" << std::endl;
            std::cout << "2. Detach ConsoleDisplay" << std::endl;
            std::cout << "3. Attach TemperatureAlert" << std::endl;
            std::cout << "4. Detach TemperatureAlert" << std::endl;
            std::cout << "5. Attach TaskCounter" << std::endl;
            std::cout << "6. Detach TaskCounter" << std::endl;
            std::cout << "7. Back to main menu" << std::endl;
            
            int observerChoice = getValidatedIntInput("Enter choice (1-7): ", 1, 7);
            
            if (observerChoice == 1) myTodoList.attach(console);
            else if (observerChoice == 2) myTodoList.detach(console);
            else if (observerChoice == 3) myTodoList.attach(alert);
            else if (observerChoice == 4) myTodoList.detach(alert);
            else if (observerChoice == 5) myTodoList.attach(counter);
            else if (observerChoice == 6) myTodoList.detach(counter);
        } else if (choice == 6) {
            std::cout << "Exiting application. Goodbye!" << std::endl;
            break;
        }
    }
    
    return 0;
}
