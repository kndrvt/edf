#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>

#include "tinyxml.h"
#include "tinystr.h"
#include "task.h"

unsigned int lcm(unsigned int a, unsigned int b) {
	return a * b / std::gcd(a, b);
}

unsigned int find_lcm(std::vector<unsigned int> &&arr) {
	unsigned int res_lcm = 1;

	for (int a : arr)
		res_lcm = lcm(res_lcm, a);
	return res_lcm;
}

unsigned int find_L(std::vector <Task> &tasks, unsigned int period_lcm) {
	double U = 0;
	unsigned int L = 0;

	for (Task &tsk : tasks)
		U += period_lcm / tsk.get_period() * tsk.get_duration();
	U /= period_lcm;
	if (U >= 1)
		return 0;

	for (Task &tsk : tasks) {
		L += (tsk.get_period() - tsk.get_deadline()) * tsk.get_duration();
	}
	return static_cast<unsigned int>(L / (1 - U));
}

unsigned int check_criterion(std::vector <Task> &tasks) {
	unsigned int sum;
	unsigned int period_lcm = find_lcm(Task::get_periods(tasks));
	unsigned int L = find_L(tasks, period_lcm);
	std::vector<unsigned int> deadlines = Task::get_deadlines(tasks);

	if (L == 0)
		return period_lcm;

	std::sort(deadlines.begin(), deadlines.end());
	for (unsigned int dl : deadlines) {
		if (dl > L)
			break;
		sum = 0;
		for (Task &tsk : tasks) {
			sum += (static_cast<double>(dl - tsk.get_deadline() +
										tsk.get_period()) / tsk.get_period()) *
				   tsk.get_duration();
		}
		if (sum <= dl)
			return 0;
	}
	sum = 0;
	for (Task &tsk : tasks) {
		sum += (static_cast<double>(L - tsk.get_deadline() +
									tsk.get_period()) /
				tsk.get_period()) * tsk.get_duration();
	}
	if (sum <= L)
		return 0;
	return L;
}


int parse_document(const char *filename) {
	TiXmlDocument doc(filename);
	if (!doc.LoadFile())
		return 1;

	TiXmlElement *root = doc.FirstChildElement("system");
	if (!root)
		return 1;

	std::vector <Task> tasks;
	for (TiXmlElement *elem = root->FirstChildElement("task");
		 elem;
		 elem = elem->NextSiblingElement("task")) {
		int pr, dl, dr;
		elem->Attribute("period", &pr);
		elem->Attribute("deadline", &dl);
		elem->Attribute("duration", &dr);
		tasks.emplace_back(elem->Attribute("name"), pr, dl, dr);
	}

	unsigned int res = check_criterion(tasks);
	if (!res) {
		std::cout << "YES" << std::endl;
	} else {
		std::cout << "NO" << std::endl;
		std::cout << 0 << " " << res << std::endl;
	}
	return 0;
}

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cout << "Usage: edf <XML filename>" << std::endl;
		return 0;
	}
	for (int i = 1; i < argc; ++i) {
		if (parse_document(argv[i]))
			return 1;
	}
	return 0;
}