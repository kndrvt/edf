#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
#include <string>

#include "tinyxml.h"
#include "tinystr.h"
#include "task.h"

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