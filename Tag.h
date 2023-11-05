#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <fstream>
#include <memory>
#include "QueueTag.h"

class QueueTag;

class Tag {
private:
	static int const DEPTH_SHIFT = 2;
	std::string name;
	int data;
	std::vector<std::unique_ptr<Tag>> children;
public:
	Tag(std::string const& name, int data) : name(name), data(data) {};
	void push(std::unique_ptr<Tag> child) { this->children.push_back(std::move(child)); }
	void multipush(std::vector<std::unique_ptr<Tag>> arrived);
	std::string asText(int depth = 0);
	void pushChildrenToQueue(std::queue<QueueTag>& tags);
};