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
	return 0;
}