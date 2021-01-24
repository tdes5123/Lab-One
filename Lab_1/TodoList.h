#ifndef TODO_LIST_H
#define TODO_LIST_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "TodoListInterface.h"
using namespace std;

class TodoList: public TodoListInterface {
  public:
     vector <string> tasks; 

    TodoList() {
      cout << "In Constructor" << endl;

      ifstream infile ("TODOList.txt");
      string line;
      
      if (infile.is_open()) {
        while (getline(infile, line)){
          cout << line << '\n';
          tasks.push_back(line);
        }
      }

      infile.close();
    }
    virtual ~TodoList() { 
      cout << "In Destructor" << endl;

      ofstream outfile;
      outfile.open ("TODOList.txt", ofstream::out | ofstream::trunc);
      
      for (int i = 0; i < tasks.size(); i++)  {
        cout << tasks.at(i) << '\n'; 
        outfile << tasks.at(i) << endl;
       }

      outfile.close();
    }

    // Adds an item to the todo list with the data specified by the string.
    virtual void add(string _duedate, string _task) {
      cout << "In add" << endl;

      tasks.push_back(_duedate + " "+ _task);
    }

    //Removes an item from the todo list with the specified task name
    //Returns 1 if it removes an iitem, 0 otherwise
    virtual int remove (string _task) {
      cout << "In remove" << endl;

      for (int i = 0; i < tasks.size(); i++) {
        if (tasks.at(i).find(_task) != string::npos) {
          tasks.erase(tasks.begin() + i);
        }
      }
    }

    //Prints out the full todo list to the console 
    virtual void printTodoList() {
      cout << "In printToDoList" << endl;
      for (int i = 0; i < tasks.size(); i++) {
        cout << tasks.at(i) << endl;
      }
    }

    // Prints out all items of a todo list with a particul due date
    virtual void printDaysTasks(string _date) {
      cout << "In daystasks" << endl;

      for (int i = 0; i < tasks.size(); i++) {
        if(tasks.at(i).find(_date) != string::npos) {
          cout << tasks.at(i) << endl;
        } else {
          cout << "wtf" << endl; 
        }
    
      }
    }
};

#endif