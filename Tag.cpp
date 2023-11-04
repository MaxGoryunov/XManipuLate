#include "Tag.h"
#include <string>

using std::cout;
using std::endl;
using std::to_string;
using std::string;

void Tag::multipush(vup<Tag> arrived) {
	this->children.insert(
		this->children.end(),
		std::make_move_iterator(arrived.begin()),
		std::make_move_iterator(arrived.end())
	);
}

string Tag::asText(int depth) {
	string text = string(depth, ' ') + "<" + this->name + "> " + to_string(this->data) + "\n";
	for (const auto& child : this->children) {
		text += child->asText(depth + Tag::DEPTH_SHIFT);
	}
	return text + "</" + this->name + ">\n";
}

void Tag::print(int depth) {
	cout << this->asText(depth) << endl;
}