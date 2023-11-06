#include "XmlResource.h"

using std::unique_ptr;
using std::make_unique;
using std::string;
using std::cout;
using std::endl;

unique_ptr<XmlResource> XmlResource::create() {
	return unique_ptr<XmlResource>(new XmlResource());
}

void XmlResource::save(string& path) {
	this->tree->save(path);
}

void XmlResource::load(string& path) {
	this->tree->load(path);
}

void XmlResource::print() {
	this->tree->print();
}

Iterator XmlResource::find(std::string const& name) {
	for (Iterator it = this->tree->begin(), end = this->tree->end(); it != end; ++it) {
		//cout << "current iterator name" << (*it).tag()->Name() << endl;
		if ((*it).tag()->matches(name)) {
			return it;
		}
	}
	return Iterator(QueueTag(nullptr, nullptr));
}

Iterator XmlResource::find(int data) {
	for (Iterator it = this->tree->begin(), end = this->tree->end(); it != end; ++it) {
		if ((*it).tag()->matches(data)) {
			return it;
		}
	}
	return Iterator(QueueTag(nullptr, nullptr));
}