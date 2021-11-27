#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
#include <string>

#include "tinyxml.h"
#include "tinystr.h"
#include "task.h"

using namespace std;

auto comp = [](const Task &a, const Task &b) {
	return (a.get_priority() > b.get_priority());
};

int main() {
	TiXmlDocument doc("input_dynamic_pri.xml");
	if (!doc.LoadFile())
		return 1;

	TiXmlElement *root = doc.FirstChildElement("system");
	if (!root)
		return 1;

	int runtime;
	root->Attribute("runtime", &runtime);

	//создание массива всех задач и добавление элементов в массив
	vector <Task> Task_array;
	for (TiXmlElement *elem = root->FirstChildElement(
			"task"); elem; elem = elem->NextSiblingElement("task")) {
		int per, pri, dur;
		string nam = elem->Attribute("name");
		nam = nam.erase(nam.length() - 1, 1);
		nam = nam.erase(0, 1);
		elem->Attribute("period", &per);
		elem->Attribute("priority", &pri);
		elem->Attribute("duration", &dur);
		Task tsk(nam, per, pri, dur);
		Task_array.insert(Task_array.end(), tsk);
	}

	//создание очереди выполнения
	priority_queue<Task, vector<Task>, decltype(comp)> Task_queue(comp);

	//создание выходного файла
	TiXmlDocument doc_out;
	TiXmlElement trace("trace");
	trace.SetAttribute("runtime", runtime);
	TiXmlElement start("start");

	//моделирование выполнения задач
	Task cur_task;
	for (int i = 0; i < runtime; ++i) {
		//проверка на начало нового периода для каждой задачи
		for (vector<Task>::iterator T = Task_array.begin();
			 T != Task_array.end(); ++T) {
			if ((i % T->get_period()) == 0) Task_queue.push(*T);
		}
		//выполнилась ли текущая задача
		if (cur_task.get_duration() == 0) {
			//задача выполнилась
			if (!Task_queue.empty()) {
				//постановка новой задачи на выполнение
				cur_task = Task_queue.top();
				Task_queue.pop();
				//добавление атрибутов элементу и элемента в корневой
				start.SetAttribute("name", (cur_task.get_name()).c_str());
				start.SetAttribute("time", i);
				trace.InsertEndChild(start);
			} else {
				//готовых к выполнению задач нет
				continue;
			}
		}
		-cur_task;
	}

	//добавление данных в файл и его сохранение
	doc_out.InsertEndChild(trace);
	doc_out.SaveFile("output_dynamic_pri.xml");
	return 0;
}