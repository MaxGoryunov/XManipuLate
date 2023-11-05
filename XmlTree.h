#pragma once

#include <string>
#include <memory>
#include <fstream>
#include "Tag.h"

class XmlTree {
private:
	template<class T>
	using up = std::unique_ptr<T>;
	up<Tag> head;
public:
	void print();
	void load(std::string& file);
	void load(std::ifstream& file);
	void save(std::string& file);
	void save(std::ofstream& file);
};