#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    struct {
    string task;
    string dueDate;
    }toDoList[100];

    char choice;
    int count = 0;
    string menu = "Please choose from the following options:\n"
        "1. Add a task to the list\n"
        "2. Get a task from the list\n"
        "3. See all tasks in the list\n"
        "4. Exit the program\n"
        "Enter your choice: \n";
    do
    {
        cout << menu;
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
            case '1': cout << "Enter the task: " << endl;
                      cin >> toDoList[count].task;
                      cout << "Enter the due date: " << endl;
                      cin >> toDoList[count].dueDate;
                      count++;
                      break;
            case '2': cout << "The next task is: " << toDoList[count - 1].task << toDoList[count - 1].dueDate << endl;
                      break;
            case '3': cout << "All tasks: " << endl;
                      for (int i = 0; i < count; i++)
                      {
                            cout << toDoList[i].task << toDoList[i].dueDate << endl;
                      }
                      break;
            case '4': cout << "Exiting the program...\n";
                      break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != '4');
    return 0;
}



