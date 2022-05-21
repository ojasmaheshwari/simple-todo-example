#ifndef __TODO__
#define __TODO__

#include <iostream>
#include <string>
#include <vector>

class Todo{
	private:
		std::vector<std::string> list;
		unsigned int tasks_completed_num;
		unsigned int tasks_remaining_num;
		unsigned int total_todos = list.size();
	public:
		void init(std::vector<std::string>, unsigned int, unsigned int);
		void display();
		void addTodo(std::string&);
		void updateTodo(int, std::string&);
		void deleteTodo(int);
};

#endif
