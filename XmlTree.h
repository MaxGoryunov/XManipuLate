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
	void print(int depth = 0) { std::cout << this->head->asText(depth) << std::endl; }
	void load(std::string& file);
	void load(std::ifstream& file);
	void save(std::string& file);
	void save(std::ofstream& file) { file << this->head->asText(); }
	Iterator begin() { return Iterator(QueueTag(head->begin(), nullptr), this->head->end()); }
	Iterator end() { return Iterator(QueueTag(head->end(), nullptr), this->head->end()); }
};