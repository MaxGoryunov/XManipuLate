#pragma once

#include <queue>
#include <memory>
#include "QueueTag.h"

class Iterator {
private:
	std::queue<QueueTag> tags;
	QueueTag end;
	QueueTag current() const { return (!this->tags.empty()) ? this->tags.front() : this->end; }
public:
	Iterator(QueueTag const& tag, Tag* end) : end(end, nullptr) {
		this->tags.push(tag);
	}
	QueueTag operator *() { return this->current(); }
	Iterator operator ++();
	Iterator operator ++(int i);
	bool operator == (Iterator const& other);
	bool operator != (Iterator const& other) { return !(*this == other); }
};