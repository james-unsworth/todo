#ifndef TODOFILE_H
#define TODOFILE_H

#include <iostream>
#include <fstream>
#include "TodoList.h"
#include "TodoItem.h"
using namespace std;

class TodoFile {
  public:
    explicit TodoFile();
    explicit TodoFile(string filename);
    int save(TodoList todoList);
    int load(TodoList& todoList);
      
  private:
    string filename;
    ofstream file;
};

#endif

