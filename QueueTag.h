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
	Tag* node;
	Tag* parent;
public:
	QueueTag(Tag* tag, Tag* parent) : node(tag), parent(parent) {}
	Tag* tag() { return this->node; };
	Tag* Parent() { return this->parent; }
};