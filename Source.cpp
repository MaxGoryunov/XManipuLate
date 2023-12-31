#include <iostream>
#include <stdexcept>
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
	Iterator third = xml->find("childthree");
	if (xml->erase(third)) {
		std::cout << "Erased <childthree> " << std::endl;
		xml->print();
	}
	try {
		std::string bad("badinput.txt");
		xml->load(bad);
	}
	catch (std::runtime_error const& error) {
		std::cerr << error.what() << std::endl;
		std::cout << "Tree after incorrect parsing of bad input: " << std::endl;
		xml->print();
	}
	try {
		std::cout << "Trying to erase <chtwochtwo> and pass its children to <head>" << std::endl;
		Iterator misplaced(
			QueueTag(
				(*(xml->find("chtwochtwo"))).tag(),
				(*(xml->find("head"))).tag()
			),
			(*empty).tag()
		);
		xml->erase(misplaced);
	}
	catch (std::runtime_error const& error) {
		std::cerr << error.what() << std::endl;
		std::cout << "Tree after trying to pass children to a non-parent: " << std::endl;
		xml->print();
	}
	return 0;
}