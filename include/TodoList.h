#ifndef TODOLIST_H
#define TODOLIST_H

#include <iostream>
#include <vector>
#include "TodoItem.h"
using namespace std;

class TodoList {
  public:
    int addItem(string text, int priority = 5, bool CheckedOff = false);
    void removeItem(int iD);
    vector<TodoItem> list();
    void checkOff(int ID);
    void clearCheckedItems();
    string toString();
    TodoItem getItem(int index);


  private:
    vector<TodoItem> todoList;
};

#endif 
