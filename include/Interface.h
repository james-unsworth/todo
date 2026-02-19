#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include "TodoFile.h"
#include "TodoList.h"
using namespace std;

class Interface {
  public:
    explicit Interface();
    int run();
    int quit();
    int printTodoList();
    vector<string> split(string input); 

  private:
    TodoFile file;
    TodoList todoList;
};

#endif


