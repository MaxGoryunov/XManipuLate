#include "Tag.h"
#include <string>
#include <stdexcept>

using std::cout;
using std::endl;
using std::to_string;
using std::string;
using std::ofstream;
using std::vector;
using std::unique_ptr;
using std::make_unique;
using std::runtime_error;
using std::make_move_iterator;

void Tag::multipush(vector<unique_ptr<Tag>> arrived) {
	this->children.insert(
		this->children.end(),
		make_move_iterator(arrived.begin()),
		make_move_iterator(arrived.end())
	);
}

string Tag::asText(int depth) {
	string offset = string(depth, ' ');
	string text = offset + "<" + this->name + "> value=" + to_string(this->data) + "\n";
	for (auto const& child : this->children) {
		text += child->asText(depth + Tag::DEPTH_SHIFT);
	}
	return text + offset + "</" + this->name + ">\n";
}

void Tag::pushChildrenToQueue(std::queue<QueueTag>& tags) {
	for (int i = 0; i < this->children.size(); ++i) {
		tags.push(QueueTag(this->children[i].get(), this));
	}
}

void Tag::passChildrenToParent(Tag* parent) {
	parent->multipush(std::move(this->children));
}

void Tag::eraseAndPassChildren(Tag* parent) {
	for (int i = 0; i < parent->children.size(); ++i) {
		if (parent->children[i].get() == this) {
			this->passChildrenToParent(parent);
			parent->children[i].reset();
			parent->children.erase(parent->children.begin() + i);
		}
	}
	throw runtime_error("Given parent is not an actual parent");
}