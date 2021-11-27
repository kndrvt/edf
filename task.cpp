#include <iostream>
#include <string>

#include "task.h"

Task::Task (): name("task0"), period(0), priority(0), duration(0) {}

Task::Task (const std::string nam, int per, int pri, int dur): name(nam), period(per), priority(pri), duration(dur) {}

Task::Task (const Task & tsk) {
	name = tsk.name;
	period = tsk.period;
	priority = tsk.priority;
	duration = tsk.duration;
}

Task & Task::operator- () {
	--duration;
	return *this;
}

const std::string Task::get_name() const {
	return name;
}
int Task::get_period() const {
	return period;
}

int Task::get_priority() const {
	return priority;
}

int Task::get_duration() const {
	return duration;
}

std::ostream & operator<< (std::ostream & os, const Task & t) {
	std::cout << t.get_name() << std::endl;
	std::cout << t.get_period() << std::endl;
	std::cout << t.get_priority() << std::endl;
	std::cout << t.get_duration() << std::endl;
	return os;
}