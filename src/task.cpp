#include <iostream>
#include <string>

#include "task.h"

Task::Task() : name("Task0"), period(0), deadline(0), duration(0) {}

Task::Task(const std::string &nm, int dl, int pr, int dr) : name(nm),
															period(pr),
															deadline(dl),
															duration(dr) {}

Task::Task(std::string &&nm, int dl, int pr, int dr) : name(nm),
													   period(pr),
													   deadline(dl),
													   duration(dr) {}

Task::Task(const Task &tsk) : name(tsk.name), period(tsk.period),
							  deadline(tsk.deadline), duration(tsk.duration) {}

Task &Task::operator-() {
	--duration;
	return *this;
}

const std::string Task::get_name() const {
	return name;
}

int Task::get_period() const {
	return period;
}

int Task::get_deadline() const {
	return deadline;
}

int Task::get_duration() const {
	return duration;
}

bool Task::operator<(const Task &tsk) const {
	return deadline < tsk.get_deadline();
}

std::ostream &operator<<(std::ostream &os, const Task &tsk) {
	std::cout << tsk.get_name() << std::endl;
	std::cout << tsk.get_period() << std::endl;
	std::cout << tsk.get_deadline() << std::endl;
	std::cout << tsk.get_duration() << std::endl;
	return os;
}