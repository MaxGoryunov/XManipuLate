#pragma once

#include <string>
#include <memory>
#include <fstream>
#include "Tag.h"
#include "Iterator.h"

class XmlTree {
private:
	template<class T>
	using up = std::unique_ptr<T>;
	up<Tag> head;
public:
	void print(int depth = 0);
	void load(std::string& file);
	void load(std::ifstream& file);
	void save(std::string& file);
	void save(std::ofstream& file);
	Iterator begin() { return Iterator(QueueTag(head->begin(), nullptr), this->head->end()); }
	Iterator end() { return Iterator(QueueTag(head->end(), nullptr), this->head->end()); }
};