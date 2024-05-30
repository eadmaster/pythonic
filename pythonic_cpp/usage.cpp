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
Dict dict;
    dict["key1"] = 123;
    dict["key2"] = std::string("value");

    // Using initializer list constructor
    Dict dict2 = {{"key3", 456}, {"key4", std::string("another value")}};

    // Using update method
    dict.update(dict2);
    dict.update({{"key5", 789}, {"key6", std::string("yet another value")}});

    try {
        int value1 = dict.get<int>("key1");
        std::string value2 = dict.get<std::string>("key2");
        int value3 = dict.get<int>("key3");
        std::cout << "key1: " << value1 << "\n";
        std::cout << "key2: " << value2 << "\n";
        std::cout << "key3: " << value3 << "\n";
    } catch (const boost::bad_any_cast& e) {
        std::cerr << "Bad any cast: " << e.what() << "\n";
    }

    if (dict.has_key("key1")) {
        std::cout << "Contains key1\n";
        //dict.pop("key1", "da");
    }


    auto keys = dict.keys();
    auto values = dict.values();
    auto items = dict.items();

    for (const auto& key : keys) {
        std::cout << "Key: " << key << "\n";
    }

    for (const auto& value : values) {
        try {
            std::cout << "Value: " << boost::any_cast<std::string>(value) << "\n";
        } catch (const boost::bad_any_cast&) {
            std::cout << "Value: [non-string value]\n";
        }
    }

    for (const auto& item : items) {
        std::cout << "Item: " << item.first << " = ";
        try {
            std::cout << boost::any_cast<std::string>(item.second) << "\n";
        } catch (const boost::bad_any_cast&) {
            std::cout << "[non-string value]\n";
        }
    }

    std::cout << "Size: " << dict.size() << "\n";
    dict.clear();
    std::cout << "Size after clear: " << dict.size() << "\n";

    // Accessing elements in dict2
    try {
        int value3 = dict2.get<int>("key3");
        std::string value4 = dict2.get<std::string>("key4");
        std::cout << "key3: " << value3 << "\n";
        std::cout << "key4: " << value4 << "\n";
    } catch (const boost::bad_any_cast& e) {
        std::cerr << "Bad any cast: " << e.what() << "\n";
    }

    // Using pop method
    int popped_value = dict.pop<int>("key3", -1);
    std::cout << "Popped key3: " << popped_value << "\n";
    popped_value = dict.pop<int>("key7", -1); // key7 does not exist
    std::cout << "Popped key7 (default): " << popped_value << "\n";


}