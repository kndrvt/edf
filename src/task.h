#pragma once

#include <iostream>
#include <vector>
#include <string>

class Task {
	std::string name;
	unsigned int period;
	unsigned int deadline;
	unsigned int duration;

public:
	Task();
	Task(const std::string &nm, unsigned int pr, unsigned int dl,
		 unsigned int dr);
	Task(std::string &&nm, unsigned int pr, unsigned int dl, unsigned int dr);
	Task(const Task &tsk);

	std::string get_name() const;
	unsigned int get_period() const;
	unsigned int get_deadline() const;
	unsigned int get_duration() const;

	friend std::ostream &operator<<(std::ostream &os, const Task &tsk);

	static std::vector<unsigned int>
	get_periods(std::vector <Task> &tasks);
	static std::vector<unsigned int>
	get_deadlines(std::vector <Task> &tasks);
};