# Todo List

A terminal-based todo list application written in C++

## Building
```bash
g++ main.cpp Interface.cpp TodoList.cpp TodoItem.cpp TodoFile.cpp -o todo
```

## Usage
Run with ./todo
Available commands:
-  list - List all items in todo list. 
- add - Add item to todo list. Usage: add [item text] -p [priority] 
- update - Update item priority. Usage: update [item number] [priority] (note: this will uncheck checked items) 
- check - Check off item. Usage: check [item number]
- clear - Clear all checked items
- quit - End session
- help - List all commands

## Features
- Priority-based sorting (lower number = higher priority)
- Multi-word item text support
- Check off completed items (moved to bottom of list)
- Persistent storage via CSV file
- Multi-item checking (e.g., `check 1 2 3`)

## Requirements
- C++11 or higher
- g++ compiler
