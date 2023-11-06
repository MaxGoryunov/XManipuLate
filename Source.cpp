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
	std::cout << "It found: " << std::endl;
	std::cout << (*it).tag()->asText() << std::endl;
	return 0;
}