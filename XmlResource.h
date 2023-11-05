#pragma once

#include "XmlTree.h"

class XmlResource {
private:
	template<class T>
	using up = std::unique_ptr<T>;
	up<XmlTree> tree;
	XmlResource() : tree(std::make_unique<XmlTree>()) {};
public:
	static std::unique_ptr<XmlResource> create();
	void save(std::string& path);
	void load(std::string& path);
	void print();
};