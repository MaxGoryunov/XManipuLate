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
	Tag* operator *() { return this->tags.front().tag(); }
	Tag* operator ->() { return this->tags.front().tag(); }
	Iterator operator ++();
	Iterator operator ++(int i);
};