#pragma once

#include <queue>
#include <memory>
#include "QueueTag.h"

class Iterator {
private:
	std::queue<QueueTag> tags;
public:
	Iterator(QueueTag const& tag) {
		this->tags.push(tag);
	}
	QueueTag operator *() { return this->tags.front(); }
	QueueTag operator ->() { return this->tags.front(); }
	Iterator operator ++();
	Iterator operator ++(int i);
	bool operator == (Iterator const& other);
	bool operator != (Iterator const& other);
};