#include "Iterator.h"

Iterator Iterator::operator++() {
	Tag* popped = this->tags.front().tag();
	this->tags.pop();
	popped->pushChildrenToQueue(this->tags);
	return *this;
}

Iterator Iterator::operator++(int i) {
	Iterator cur = *this;
	++(*this);
	return cur;
}

bool Iterator::operator==(Iterator const& other) {
	return this->current().tag() == other.current().tag()
		&& this->current().Parent() == other.current().Parent();
}

bool Iterator::operator!=(Iterator const& other) {
	//bool eq = (*this == other);
	return !(*this == other);
}