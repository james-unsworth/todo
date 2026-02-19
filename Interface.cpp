#include "include/Interface.h"
#include "include/TodoList.h"
#include "include/TodoFile.h"
#include <sstream>
#include <algorithm>

Interface::Interface() {
  file.load(todoList);
}

int Interface::run() {
  string line;
  cout << "TODO LIST - Type 'help' for commands\n\n";
  
  while (true) {
    cout << ">";
    getline(cin, line);

    if (line.empty()) continue;

    vector<string> tokens = split(line);
    string command = tokens[0];
    
   if (command == "list") { 
     printTodoList();
   }

   // ADD
   else if (command == "add") {
     int priority;
     int priorityIdx = -1;
     bool incompleteCommand = false;

     if (tokens.size() < 2 || tokens[1] == "-p") {
      cout << "\nUsage: add [item text] -p [priority]\n\n";
      incompleteCommand = true;
      continue;
     }

     for (int i = 0; i < tokens.size(); i++) {
       if (tokens[i] == "-p" && i < (tokens.size() - 1)) {
          priorityIdx = i + 1;
          continue;
       } else if (tokens[i] == "-p") {
         cout << "\nUsage: add [item text] -p [priority]\n\n";
         incompleteCommand = true;
         break;
      } 
     }
     if (priorityIdx == -1 && !incompleteCommand) {
       string text;
       for (int i = 1; i < tokens.size(); i++) {
         text += tokens[i];
         if (i < tokens.size() - 1) {
           text += " ";
         }
       }
       todoList.addItem(text);
       file.save(todoList);
       cout << "\nAdded: " << text << "\n\n";
     }

     else if (!incompleteCommand) {
       try {
         priority = stoi(tokens[priorityIdx]);
       }
       catch (invalid_argument& e) {
         priority = 5;
      }

       string text;
       for (int i = 1; i < priorityIdx - 1; i++) {
         text += tokens[i];
         if (i < priorityIdx - 2) {
           text += " ";
         }
       }
       todoList.addItem(text, priority);
       file.save(todoList);
       cout << "\nAdded: " << text << " [" << priority << "]\n\n";
     }
   }

   // UPADATE
   else if (command == "update") {
      if (tokens.size() < 3) {
        cout << "\nUsage: update [item number] [priority]\n\n";
        continue;
      }
      int item;
      try {
        item = stoi(tokens[1]);
      } catch (invalid_argument& e) {
         cout << "\nInvalid item number. Usage: update [item number] [priority]\n\n";
         continue;
      }
      if (item < 1 || item > todoList.list().size()) {
         cout << "\nItem number out of range. Use 'list' to see items.\n\n";
         continue;
      }

      int priority;
      try {
        priority = stoi(tokens[2]);
      }
      catch(invalid_argument& e) {
        cout << "\nPriority must be a number\n";
        continue;
      }

      string text = todoList.getItem(item - 1).text();
      todoList.removeItem(item - 1);
      todoList.addItem(text, priority);

      cout << "\nUpdated priority for item " << item << " to [" << priority << "]\n\n";
      file.save(todoList);
      printTodoList();

  }

   // CHECK
   else if (command == "check") {
     if (tokens.size() < 2) {
       cout << "\nUsage: check [item number]\n\n";
       continue;
     }
    
     tokens.erase(tokens.begin());
     vector<int> items;
     for (string token : tokens) {
      try{
        int item = stoi(token);
        items.push_back(item);
      } catch (invalid_argument& e) {
         cout << "\nInvalid number. Usage: check [item number]\n\n";
         continue;
      }
     }

     sort(items.begin(), items.end());
     reverse(items.begin(), items.end());
    
     for (int item : items) {
       int index = item - 1;
       if (index < 0 || index >= todoList.list().size()) {
         cout << "\nItem number out of range. Use 'list' to see items.\n\n";
         continue;
       }
       
       todoList.checkOff(index);
       cout << "\nChecked off item " << item << "\n\n";
     }
     file.save(todoList);

   }
   
   // CLEAR
   else if (command == "clear") {
      todoList.clearCheckedItems();
      file.save(todoList);
      cout << "\nCleared checked items\n\n";
   }

  // QUIT
   else if (command == "quit") {
      quit();
      break;
   }

   // HELP
   else if (command == "help") {
      cout << "Commands:\n";
      cout << "\tlist - list all items in todo list.\n";
      cout << "\tadd - add item to todo list. usage: add [item text] -p [priority]\n";
      cout << "\tupdate - update item priority. usage: update [item number] [priority] (note: this will uncheck checked items).\n";
      cout << "\tcheck - check off item. usage: check [item number]\n";
      cout << "\tclear - clear all checked items.\n";
      cout << "\ttquit - end session.\n";
      cout << "\thelp - list all commands.\n\n";
   }

   else {
    cout << "\nUnknown command: " + command + ". Type 'help' for commands.\n\n";
   }

  }
  return 0;
}

vector<string> Interface::split(string input) {
  vector<string> tokens;
  stringstream ss(input);
  string word;

  while (ss >> word) {
    tokens.push_back(word);
  }

  return tokens;
}

int Interface::quit() {
  return 0;
}

int Interface::printTodoList() {
  cout << "\n\n" << todoList.toString()<< "\n"; 
  return 0;
}

