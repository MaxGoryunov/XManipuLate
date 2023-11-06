#include <iostream>
#include "XmlResource.h"

int main() {
	std::unique_ptr<XmlResource> xml = XmlResource::create();
	std::string in("input.txt");
	xml->load(in);
	xml->print();
	std::string out("out.txt");
	xml->save(out);
	Iterator it = xml->find("chtwochtwo");
	std::cout << "Found by name: " << std::endl;
	std::cout << (*it).tag()->asText() << std::endl;
	Iterator it1 = xml->find(20);
	std::cout << "Found by value: " << std::endl;
	std::cout << (*it1).tag()->asText() << std::endl;
	Iterator added = xml->add("grandchtwo", 140, it1);
	std::cout << "After add: " << std::endl;
	std::cout << (*it1).tag()->asText() << std::endl;
	Iterator empty = xml->find("notatag");
	if ((*empty).tag() == nullptr) {
		std::cout << "Found nothing in the tree" << std::endl;
	}
	return 0;
}