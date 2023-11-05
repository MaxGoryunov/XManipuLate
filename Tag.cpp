#include "Tag.h"
#include <string>

using std::cout;
using std::endl;
using std::to_string;
using std::string;
using std::ofstream;

void Tag::multipush(vup<Tag> arrived) {
	this->children.insert(
		this->children.end(),
		std::make_move_iterator(arrived.begin()),
		std::make_move_iterator(arrived.end())
	);
}

string Tag::asText(int depth) {
	string offset = string(depth, ' ');
	string text = offset + "<" + this->name + "> " + to_string(this->data) + "\n";
	for (auto const& child : this->children) {
		text += child->asText(depth + Tag::DEPTH_SHIFT);
	}
	return text + offset + "</" + this->name + ">\n";
}