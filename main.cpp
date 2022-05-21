#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "todo.h"

// Globals
Todo todo_obj;
std::string header("C++ TODO LIST APPLICATION"), dash(50, '-');
std::string username;
bool loop = true;


// Class definitions
void Todo::init(std::vector<std::string> i_list, unsigned int i_tasks_completed, unsigned int i_tasks_remaining)
{
	list = i_list;
	tasks_completed_num = i_tasks_completed;
	tasks_remaining_num = i_tasks_remaining;
}

void Todo::display()
{
	for (unsigned int i = 0; i < list.size(); i++)
	{
		std::cout << i+1 << ") " << list[i] << '\n';
	}
}

void Todo::addTodo(std::string &i_todo)
{
	list.push_back(i_todo);
}

void Todo::updateTodo(int i_todo_num, std::string &i_todo_desc)
{
	list[i_todo_num-1] = i_todo_desc;
}

void Todo::deleteTodo(int i_todo_num)
{
	list.erase(list.begin()+(i_todo_num-1));
}

// Prototypes
void handleInput();
void displayHelp();

int main()
{

	std::cout << dash << '\n' << std::setw(header.length()+5) << header << '\n' << dash << '\n';
	std::cout << "Enter your username: ";
	std::getline(std::cin, username);
	std::cout << "Hey " << username << '!' << "\nStart by typing commands called <actions> or type help for list of available commands.\n";
	while (loop)
	{
		handleInput();
	}
	std::cin.get();
}

void handleInput(){
	std::string cmd = "", arg1;
	int arg2;
	std::cout << "Action> ";
	if (std::cin >> cmd && cmd.length() != 0){
		if (cmd == "help")
		{
			displayHelp();
		}
		else if (cmd == "add")
		{
			std::getline(std::cin, arg1);
			todo_obj.addTodo(arg1);
			std::cout << "Todo was added successfully!\n";
		}
		else if (cmd == "display")
		{
			todo_obj.display();
		}
		else if (cmd == "update")
		{
			std::cin >> arg2; // Todo number argument
			std::getline(std::cin, arg1);
			todo_obj.updateTodo(arg2, arg1);
			std::cout << "Todo no. " << arg2 << " was updated successfully!\n";
		}
		else if (cmd == "delete")
		{
			std::cin >> arg2; // Todo number argument
			todo_obj.deleteTodo(arg2);
			std::cout << "Todo no. " << arg2 << " was deleted successfully!\n";
		}
		else {
		std::cout << "Invalid command or argument error\n";
		}

	}
	else {
		std::cout << "Invalid command or argument error\n";
	}
}

void displayHelp(){
	std::vector<std::string> list_cmds = {
		"add {todo_desp} -> Adds a todo to your list.",
		"display -> displays lists of available todos.",
		"update {todo_no} {new_desc} -> Updates todo description.",
		"delete {todo_no} -> Deletes a todo off the list.",
		"mark_done {todo_no} -> Marks a todo as done.",
		"unmark_done {todo_no} -> Unmark a todo as remaining.",
		"display done -> Displays only todos which are done.",
		"display rem -> Displays only todos which are remaining"
	};
	for (unsigned int i = 0; i < list_cmds.size(); i++)
	{
		std::cout << i+1 << ") " << list_cmds[i] << '\n';
	}
}
