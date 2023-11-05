#include "XmlTree.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

void XmlTree::print() {
	cout << this->head->asText() << endl;
}

void XmlTree::save(ofstream& file) {
	file << this->head->asText();
}

void XmlTree::save(string& file) {
	ofstream out(file);
	this->save(out);
}

void XmlTree::load(ifstream& file) {

}

void XmlTree::load(string& file) {
	ifstream in(file);
	this->load(in);
}