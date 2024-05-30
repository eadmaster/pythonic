#include <unordered_map>
#include <any>
#include <string>
#include <stdexcept>
#include <vector>
#include <initializer_list>
#include <iostream>

class dict {
public:
    // Default constructor
    dict() = default;

    // Constructor with initializer list
    dict(std::initializer_list<std::pair<const std::string, std::any>> init) : data(init) {}

    // Set item
    template<typename T>
    void setitem(const std::string& key, const T& value) {
        data[key] = value;
    }

    // Check if a key exists
    bool contains(const std::string& key) const {
        return data.find(key) != data.end();
    }

    // Get all keys
    std::vector<std::string> keys() const {
        std::vector<std::string> result;
        for (const auto& pair : data) {
            result.push_back(pair.first);
        }
        return result;
    }

    // Get all values
    std::vector<std::any> values() const {
        std::vector<std::any> result;
        for (const auto& pair : data) {
            result.push_back(pair.second);
        }
        return result;
    }

    // Get all items
    std::vector<std::pair<std::string, std::any>> items() const {
        std::vector<std::pair<std::string, std::any>> result;
        for (const auto& pair : data) {
            result.push_back(pair);
        }
        return result;
    }

    // Size of the dictionary
    size_t size() const {
        return data.size();
    }

    // Clear the dictionary
    void clear() {
        data.clear();
    }

    // Type-safe accessor for dictionary values
    template<typename T>
    T get_as(const std::string& key) const {
        auto it = data.find(key);
        if (it == data.end()) {
            throw std::out_of_range("Key not found: " + key);
        }
        return std::any_cast<T>(it->second);
    }

    // Type-safe accessor with default value
    template<typename T>
    T get_as(const std::string& key, const T& default_value) const {
        auto it = data.find(key);
        if (it == data.end()) {
            return default_value;
        }
        return std::any_cast<T>(it->second);
    }

    // Update dictionary with another dictionary or initializer list
    void update(const dict& other) {
        for (const auto& pair : other.data) {
            data[pair.first] = pair.second;
        }
    }

    void update(std::initializer_list<std::pair<const std::string, std::any>> init) {
        for (const auto& pair : init) {
            data[pair.first] = pair.second;
        }
    }

    // Pop item with key, return value, throw exception if key not found
    template<typename T>
    T pop(const std::string& key) {
        auto it = data.find(key);
        if (it != data.end()) {
            T value = std::any_cast<T>(it->second);
            data.erase(it);
            return value;
        } else {
            throw std::out_of_range("Key not found: " + key);
        }
    }

    // Pop item with key, return value or default if key not found
    template<typename T>
    T pop(const std::string& key, const T& default_value) {
        auto it = data.find(key);
        if (it != data.end()) {
            T value = std::any_cast<T>(it->second);
            data.erase(it);
            return value;
        } else {
            return default_value;
        }
    }

    // Helper class to enable type-safe access via operator[]
    class ValueProxy {
    public:
        ValueProxy(std::any& value) : value(value) {}

        template<typename T>
        operator T() const {
            return std::any_cast<T>(value);
        }

        template<typename T>
        void operator=(const T& new_value) {
            value = new_value;
        }

        friend std::ostream& operator<<(std::ostream& os, const ValueProxy& vp) {
            if (vp.value.type() == typeid(int)) {
                os << std::any_cast<int>(vp.value);
            } else if (vp.value.type() == typeid(std::string)) {
                os << std::any_cast<std::string>(vp.value);
            } else {
                os << "[unsupported type]";
            }
            return os;
        }

    private:
        std::any& value;
    };

    class ConstValueProxy {
    public:
        ConstValueProxy(const std::any& value) : value(value) {}

        template<typename T>
        operator T() const {
            return std::any_cast<T>(value);
        }

        friend std::ostream& operator<<(std::ostream& os, const ConstValueProxy& cvp) {
            if (cvp.value.type() == typeid(int)) {
                os << std::any_cast<int>(cvp.value);
            } else if (cvp.value.type() == typeid(std::string)) {
                os << std::any_cast<std::string>(cvp.value);
            } else {
                os << "[unsupported type]";
            }
            return os;
        }

    private:
        const std::any& value;
    };

    ValueProxy operator[](const std::string& key) {
        return ValueProxy(data[key]);
    }

    ConstValueProxy operator[](const std::string& key) const {
        auto it = data.find(key);
        if (it == data.end()) {
            throw std::out_of_range("Key not found: " + key);
        }
        return ConstValueProxy(it->second);
    }

private:
    std::unordered_map<std::string, std::any> data;
};


// Example usage
int main() {
    // Using default constructor
    dict d;
    d["key1"] = 123;
    d["key2"] = std::string("value");

    // Using initializer list constructor
    dict d2 = {{"key3", 456}, {"key4", std::string("another value")}};

    // Using update method
    d.update(d2);
    d.update({{"key5", 789}, {"key6", std::string("yet another value")}});

    // Using auto for type inference with operator[]
    try {
        auto value1 = d["key1"];
        auto value2 = d["key2"];
        auto value3 = d["key3"];
       std::cout << "key1: " << value1 << "\n";
        std::cout << "key2: " << value2 << "\n";
        std::cout << "key3: " << value3 << "\n";
    } catch (const std::bad_any_cast& e) {
        std::cerr << "Bad any cast: " << e.what() << "\n";
    }

    if (d.contains("key1")) {
        std::cout << "Contains key1\n";
    }

    // Using pop method
    try {
        d.pop<int>("key1");
    } catch (const std::out_of_range& e) {
        std::cerr << "Key not found: " << e.what() << "\n";
    }

/*
    // Iterating over dictionary
    std::cout << "Dictionary contents:\n";
    for (const auto& item : d.items()) {
        std::cout << "Key: " << item.first << ", Value: " << item.second << "\n";
    }*/


}