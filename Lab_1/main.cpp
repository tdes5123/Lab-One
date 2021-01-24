#include <iostream>
#include <fstream>
#include <string>
#include "TodoList.h"
using namespace std;

int main(int argc, char *argv[]) {
  TodoList mylist;

  for (int i = 0; i < argc; i++) {
    cout << "argv[" << i << "]=" << argv[i] << endl;
  }

  string firstarg = argv[1];
  if (firstarg.compare("add") == 0) {
    cout << "Doing an add" << endl;

    string date = argv[2];
    string task = argv[3];
    cout << "date " << date << " task " << task << endl;

    mylist.add(date, task);
  } else if (firstarg.compare("remove") == 0) {
      cout << "Removing" << endl;

      string task = argv[2];
      
      mylist.remove(task);
  } else if (firstarg.compare("printList") == 0) {
      cout << "Printing List" << endl;

      mylist.printTodoList();
  } else if (firstarg.compare("printDay") == 0) {
      cout << "Printing Days Tasks" << endl;

      string day = argv[2];

      mylist.printDaysTasks(day);
  }
}