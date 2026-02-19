#ifndef TODOITEM_H
#define TODOITEM_H

#include <iostream>
using namespace std;

class TodoItem {
  public:
    explicit TodoItem();
    explicit TodoItem(string text, int priority, bool checkedOff);

    string text();
    int priority();
    bool isCheckedOff();

    void setText(string text);
    void setPriority(int priority);
    void setCheckedOff(bool checked);

  private:
    string itemText;
    int itemPriority;
    bool itemCheckedOff;
};

#endif 
