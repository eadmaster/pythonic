#include <bits/stdc++.h>
using namespace std;
#include "pythonic.hpp"


int main()
{
	auto x = 4; 
	auto y = 3.37; 

	auto s = str("Text");
	
	//cout << str.toUpper().shuffled() << endl;
	//s = new str("text");
	//print( len(s) ) ;
	print( s.upper() ); 
	print( s.lower() ); 
	print( "literal str" ); 
	
/*
	List l = {1, 2, 3, "four"};

    // Access elements using operator[]
    std::cout << "Element at index 0: ";
    try {
        std::cout << boost::any_cast<int>(l[0]) << std::endl;
    } catch (const boost::bad_any_cast&) {
        std::cout << "[unknown type]" << std::endl;
    }

    std::cout << "Element at index 1: ";
    try {
        std::cout << boost::any_cast<int>(l[1]) << std::endl;
    } catch (const boost::bad_any_cast&) {
        std::cout << "[unknown type]" << std::endl;
    }

    std::cout << "Element at index 3: ";
    try {
        std::cout << boost::any_cast<const char*>(l[3]) << std::endl;
    } catch (const boost::bad_any_cast&) {
        std::cout << "[unknown type]" << std::endl;
    }

    // Modify an element using operator[]
    l[2] = 10;
    std::cout << "Modified element at index 2: ";
    try {
        std::cout << boost::any_cast<int>(l[2]) << std::endl;
    } catch (const boost::bad_any_cast&) {
        std::cout << "[unknown type]" << std::endl;
    }*/

	// dict tests
	dict d;
    d["key1"] = 123;
    d["key2"] = "str value";
    print(d["key2"]);
    
    // Using initializer list constructor
    dict d2 = {{"key3", 456}, {"key4", std::string("another value")}};

    // Using update method
    d.update(d2);
    d.update({{"key5", 789}, {"key6", std::string("yet another value")}});

	auto value1 = d["key1"];
	print(value1);
	printf("%d", value1);
	//value1 = d.get("key1");
	//printf("%d", value1);
	auto value2 = d["key2"];
	auto value3 = d["key3"];
	print(value2);
	print(value3);
	//std::cout << "key1: " << value1 << "\n";  // using cout req. explicit casting

    if (d.has_key("key1")) {
        std::cout << "Contains key1\n";
        //d.pop("key1", "da");
    }

    for (auto k : d.keys()) {
        print(k);
    }

    for (auto v : d.values()) {
        print(v);
    }

    for (auto i : d.items()) {
        print(i.first);
        print(i.second);
    }

    // Using pop method
    auto popped_value = d.pop("key3", -1);
    print("popped_value:");
    print(popped_value);
    //popped_value = d.pop("key7"); // key7 does not exist -> check exception

    print("Size: ");
    print(d.size());
    d.clear();
    print(d.size());



}