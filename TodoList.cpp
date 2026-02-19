#include "include/TodoList.h"
#include "include/TodoFile.h"

int TodoList::addItem(string text, int priority, bool checkedOff) {
  TodoItem newItem = TodoItem(text, priority, checkedOff);

  if (checkedOff) {
    todoList.push_back(newItem);
    return 0;
  }

  if (todoList.empty()) { 
    todoList.push_back(newItem);
    return 0;
  }

  auto item = todoList.begin();
  bool inserted = false;
  for (item; item < todoList.end(); item++) {
    if (item->isCheckedOff()) {
      todoList.insert(item, newItem);
      inserted = true;
      break;
    }
    if (newItem.priority() < item->priority()) {
      todoList.insert(item, newItem);
      inserted = true;
      break;
    }
  }
  if (!inserted) {
    todoList.push_back(newItem);
  }

  return 0;
}

void TodoList::removeItem(int ID) {
  todoList.erase(todoList.begin() + ID);
}

vector<TodoItem> TodoList::list() {
  return todoList;
}

void TodoList::checkOff(int index) {
  TodoItem checkedItem = todoList.at(index);
  checkedItem.setCheckedOff(true);
  todoList.push_back(checkedItem);
  auto i = next(todoList.begin(), index);
  todoList.erase(i);
}

void TodoList::clearCheckedItems() {
  auto i = todoList.begin();
  while (i != todoList.end()) {
    if (i->isCheckedOff()) {
      i = todoList.erase(i);
    } else {
      i++;
    }
  }
}

string TodoList::toString() {
  string todoString;
  for (int i = 0; i < todoList.size(); i++) {
    string checkbox = todoList[i].isCheckedOff() ? "[X] " : "[ ] ";
    todoString += checkbox + to_string(i + 1) + ".  " + todoList[i].text() + "\t[" + to_string(todoList[i].priority()) + "]\n";
  }

  return todoString;
}

TodoItem TodoList::getItem(int index) {
  return todoList.at(index);
} 
