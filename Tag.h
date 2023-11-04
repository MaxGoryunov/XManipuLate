#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Tag {
private:
	static int const DEPTH_SHIFT = 5;
	template<class T>
	using up = std::unique_ptr<T>;
	template<class T>
	using vup = std::vector<up<T>>;
	std::string name;
	int data;
	vup<Tag> children;
public:
	Tag(std::string const& name, int data) : name(name), data(data) {};
	void push(up<Tag> child) { this->children.push_back(std::move(child)); }
	void multipush(vup<Tag> arrived);
	std::string asText(int depth = 0);
	void print(int depth = 0);
};