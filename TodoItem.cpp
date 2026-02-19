#include "include/TodoItem.h"

TodoItem::TodoItem() {
  itemText = "";
  itemPriority = 0;
  itemCheckedOff = false;
}

TodoItem::TodoItem(string text, int priority, bool checkedOff) {
  itemText = text;
  itemPriority = priority;
  itemCheckedOff = checkedOff;
}

string TodoItem::text() {
  return itemText;
}

void TodoItem::setText(string text) {
  itemText = text;
}

int TodoItem::priority() {
  return itemPriority;
}

void TodoItem::setPriority(int priority) {
  itemPriority = priority;
}

bool TodoItem::isCheckedOff() {
  return itemCheckedOff;
}

void TodoItem::setCheckedOff(bool checkedOff) {
  itemCheckedOff = checkedOff;
}


  
