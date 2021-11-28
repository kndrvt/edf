#include <iostream>
#include <string>

#include "task.h"

Task::Task() : name("Task0"), period(0), deadline(0), duration(0) {}

Task::Task(const std::string &nm, unsigned int pr, unsigned int dl,
		   unsigned int dr) : name(nm),
							  period(pr),
							  deadline(dl),
							  duration(dr) {}

Task::Task(std::string &&nm, unsigned int pr, unsigned int dl, unsigned int dr)
		: name(nm),
		  period(pr),
		  deadline(dl),
		  duration(dr) {}

Task::Task(const Task &tsk) : name(tsk.name), period(tsk.period),
							  deadline(tsk.deadline), duration(tsk.duration) {}

std::string Task::get_name() const {
	return name;
}

unsigned int Task::get_period() const {
	return period;
}

unsigned int Task::get_deadline() const {
	return deadline;
}

unsigned int Task::get_duration() const {
	return duration;
}

std::ostream &operator<<(std::ostream &os, const Task &tsk) {
	std::cout << tsk.get_name() << "("
			  << tsk.get_period() << ", "
			  << tsk.get_deadline() << ", "
			  << tsk.get_duration() << ")"
			  << std::endl;
	return os;
}

std::vector<unsigned int> Task::get_periods(std::vector <Task> &tasks) {
	std::vector<unsigned int> res;

	for (Task &tsk : tasks)
		res.push_back(tsk.get_period());
	return res;
}

std::vector<unsigned int> Task::get_deadlines(std::vector <Task> &tasks) {
	std::vector<unsigned int> res;

	for (Task &tsk : tasks)
		res.push_back(tsk.get_deadline());
	return res;
}