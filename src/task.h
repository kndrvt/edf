#pragma once

#include <iostream>
#include <string>

class Task {
	std::string name;
	int period;
	int deadline;
	int duration;

public:
	Task();
	Task(const std::string &nm, int pr, int dl, int dr);
	Task(std::string &&nm, int pr, int dl, int dr);
	Task(const Task &tsk);

	const std::string get_name() const;
	int get_period() const;
	int get_deadline() const;
	int get_duration() const;

	Task &operator-();
	bool operator<(const Task &tsk) const;
	friend std::ostream &operator<<(std::ostream &os, const Task &tsk);
};