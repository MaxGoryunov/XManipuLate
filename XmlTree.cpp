#include "XmlTree.h"
#include <iostream>
#include <stack>
#include <stdexcept>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::stack;
using std::move;
using std::runtime_error;
using std::make_unique;

void XmlTree::save(string& file) {
	ofstream out(file);
	this->save(out);
}

void XmlTree::load(ifstream& file) {
	string line;
	stack<up<Tag>> st;
	while (getline(file, line)) {
		int start = line.find('<');
		if (line[start + 1] != '/') {
			st.push(
				make_unique<Tag>(
					line.substr(start + 1, line.find('>') - 1 - start),
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
			if (!child->matches(line.substr(start + 2, line.find('>') - 2 - start))) {
				throw runtime_error("Invalid file contents, check file for unpaired tags");
			}
			st.top()->push(move(child));
		}
	}
	this->head = move(st.top());
}

void XmlTree::load(string& file) {
	ifstream in(file);
	this->load(in);
}