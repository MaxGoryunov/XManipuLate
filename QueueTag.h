#pragma once

#include "Tag.h"

/*
* Usage of raw pointers instead of unique or shared pointers is justified by
* the fact that this class's fields(tag and parent) do not represent possession
* of resources, neither unique nor shared. They are just pointers to specific
* places in memory.
*/
class QueueTag {
private:
	Tag* tag;
	Tag* parent;
public:
	QueueTag(Tag* tag, Tag* parent) : tag(tag), parent(parent) {}
	Tag* Tag() { return this->tag; }
	Tag* Parent() { return this->parent; }
};