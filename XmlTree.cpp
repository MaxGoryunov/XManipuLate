#include "XmlTree.h"
#include <iostream>
#include <stack>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::stack;
using std::move;
using std::make_unique;

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
	string line;
	stack<up<Tag>> st;
	while (getline(file, line)) {
		if (line[1] != '/') {
			st.push(
				make_unique<Tag>(
					line.substr(1, line.find('>') - 1),
					stoi(line.substr(line.find('=') + 1))
				)
			);
		}
		else {
			if (st.size() == 1) {
				break;
			}
			up<Tag> child = move(st.top());
			st.pop();
			st.top()->push(move(child));
		}
	}
	this->head = move(st.top());
}

void XmlTree::load(string& file) {
	ifstream in(file);
	this->load(in);
}