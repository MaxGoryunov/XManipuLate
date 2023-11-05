#include "XmlResource.h"

using std::unique_ptr;
using std::make_unique;
using std::string;

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