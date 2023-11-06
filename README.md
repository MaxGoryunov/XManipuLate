# XManipuLate

XManipuLate is a simple library in C++ for working with XML resources.

## XmlResource

This object represents an XML structure as a whole.

To save to a file:
```c++
unique_ptr<XmlResource> xml = XmlResource::create();
/// populating an xml tree
xml->save("out.txt");
```

To load from a file:
```c++
xml->load("in.txt");
```

To print the tree to the console:
```c++
xml->print();
```

To find a tag by name:
```c++
Iterator it = xml->find("tagname");
```

To find a tag by value:
```c++
Iterator it = xml->find(30);
```

To add a subtree to the tree:
```c++
Iterator it = xml->find("parent");
xml->add("childtag", 40, it);
```

To erase a tag from the tree:
```c++
Iterator it = xml->find("erase");
xml->erase(it);
```

`XmlResource` provides strong exception guarantee. It means that if an 
exception is thrown during any of the above operations, the tree will be left 
in a valid state.

## XmlTree

`XmlTree` can be loaded, saved and printed just like `XmlResource`. On top of
that, it can also be traversed using an `Iterator`. For example, to find a tag
by its name:
```c++
unique_ptr<XmlTree> tree = make_unique<XmlTree>();
for (Iterator it = tree->begin(), end = tree->end(); it != end; ++it) {
    if ((*it).tag()->matches(name)) {
        return it;
    }
}
```

## Tag

A tag is the smallest element of `XmlResource`. It can be converted to text:
```c++
unique_ptr<Tag> tag = make_unique<Tag>("tagname", 42);
cout << tag->asText() << endl;
```