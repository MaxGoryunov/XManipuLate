#include "Iterator.h"

Iterator Iterator::operator++() {
	Tag* popped = this->tags.front().tag();
	this->tags.pop();
	//popped->pushChildrenToQueue(this->tags);
	return *this;
}

Iterator Iterator::operator++(int i) {
	Iterator cur = *this;
	++(*this);
	return cur;
}

