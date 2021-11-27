#pragma once
#include <iostream>
#include <string>

class Task {
	std::string name;
	int period;
	int priority;
	int duration;
public:
	Task (); //конструктор по умолчанию
	Task (const std::string nam, int per, int pri, int dur); //конструктор
	Task (const Task & tsk); //конструктор копирования
	Task & operator- (); //уменьшение времени выполнения для текущей задачи
	//геттеры
	const std::string get_name() const;
	int get_period() const;
	int get_priority() const;
	int get_duration() const;
	friend std::ostream & operator<< (std::ostream & os, const Task & t);
};