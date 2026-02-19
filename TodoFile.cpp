#include "include/TodoFile.h"
#include <sstream>

TodoFile::TodoFile() {
  filename = "TodoList.csv";
}

TodoFile::TodoFile(string fname) {
  filename = fname;
    
}

int TodoFile::save(TodoList todoList) {
  file.open(this->filename, ios::out | ios::trunc);

  for (TodoItem item : todoList.list()) {
    file << item.text() << "," << item.priority() << "," << item.isCheckedOff() << "\n";
  }

  file.flush();
  file.close();

  return 0;
}

int TodoFile::load(TodoList& todoList) {
  ifstream inFile(this->filename);
  string line;

  while (getline(inFile, line)) {
    if (line.empty()) continue;

    TodoItem item;
    vector<string> row;
    stringstream ss;
    ss << line;
    string cell;

    while(getline(ss, cell, ',')) {
      row.push_back(cell);
    }

    if (row.size() < 3) continue;

    item.setText(row[0]);
    item.setPriority(stoi(row[1]));
    item.setCheckedOff(row[2] == "1");
    todoList.addItem(item.text(), item.priority(), item.isCheckedOff());
  }

  inFile.close();
  return 0;
}

