

/* TODO:  see also  https://theboostcpplibraries.com/boost.stringalgorithms*/


#include <iostream>
#include <string>
#include <cctype>
#include <cassert>
#include <sstream>
#include <cmath>
#include <algorithm>

using namespace std;
using std::string;
#include <list>

//#include <boost/any.hpp>
//using boost::any_cast;

#include <typeinfo>       // operator typeid

// TODO: python-like comments with "#"

/** global functions **/
#define print(o) std::cout << static_cast<std::string>(o) << std::endl
#define len(o)  o.size()
#define type(o) typeid(o).name()  // 2FIX: returned value is implementation-defined  http://www.cplusplus.com/reference/typeinfo/type_info/name/
//TODO: #define cmp(o1, o2)   # Compare the two objects x and y and return an integer according to the outcome. The return value is negative if x < y, zero if x == y and strictly positive if x > y.

/*
#define int(o) static_cast<int>(o)
#define long(o) static_cast<long>(o)
#define float(o) static_cast<float>(o)
#define double(o) static_cast<double>(o)
#define bool(o) static_cast<bool>(o)
//TODO: #define hex(int)          # int->str (hex)
//TODO: #define oct(int)          # int->str (oct)
//TODO: #define bin(int)          # int->str (bin) (new in py2.6)
//TODO: #define chr(int)          # int->char
//TODO: #define ord('c')          # char->int
//TODO: #define repr(any)
*/

// TODO: top level function aliases  http://stackoverflow.com/questions/9864125/c11-how-to-alias-a-function
//int (*holler)(const char*, ...) = std::printf;


// str class
// source https://www.daniweb.com/programming/software-development/code/252294/string-class-inherited-from-basic-string
// see also https://github.com/imageworks/pystring
#include <cassert>
#include <sstream>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <iostream>

class str : public std::basic_string<char>  // Extends std::basic_string and adds more functionality
{
public:
	typedef std::basic_string<char> string_type;

	str() : string_type() {}
	str(const char * str) : string_type(str){}
	str(const char * str, size_t n) : string_type(str,n) {}
	str(size_t n , char c ) : string_type(n,c) {}
        // TODO: constructor from any iterator

	str  upper()const      { return _apply(std::toupper);  }
	str  lower()const      { return _apply(std::tolower);  }
    
    // TODO: replace -> boost::replace_first_copy(this, old, rep);
    
    //str  ltrim()const      { return( return erase(0, find_first_not_of("\t\n\v\f\r "))); }
    //str  rtrim()const      { return( return erase(find_last_not_of("\t\n\v\f\r ") + 1) ); }
    //str  trim()const       { return ( ltrim(rtrim(s))); }
	
	bool    isdigit()const      { return _isAllDigits();	}
	bool    islower()const      { return _checkIf(std::islower); }
	bool    isupper()const      { return _checkIf(std::isupper); }
	bool    isalpha()const      { return _checkIf(std::isalpha); }

    // size_t  toSizeT()const      { return _convertTo<size_t>(*this);}

	bool    startswith(const str& preFix)const { return substr(0,preFix.size()) == preFix;  }
	bool    endswith(const str& suffix)const	{ return substr(size()-suffix.size()) == suffix; }

    // TODO: find, index, count
            
	//conversion function
	operator const char*(){
		return c_str();
	}
    
private:
	//helpers
	typedef int(*ApplyFunc)(int); 	
    
	//converts a string to a valid data type
	template<typename ReturnType>
	ReturnType _convertTo(const string& str)const{			
		_assertValidSize();
		std::stringstream convert;
		convert << str ;
		ReturnType data;
		assert(!(convert >> data).fail() ); //make sure conversion was succesful
		return data;
	}

	//takes in a function and returns a string with that function applied to the whole string
	str _apply(const ApplyFunc& Applier )const{
		_assertValidSize();
		str s;
		std::transform( begin(),end(), //from start to end
						std::back_insert_iterator<string_type>(s), //adjust str size
						Applier); //while applying a function to it
		return s;
	}	

	//takes in a function and checks if it passes the function checking
	bool _checkIf(const ApplyFunc& Applier)const{
		for(size_t indx = 0; indx != size(); ++indx){			
			if(!Applier((*this)[indx]) )return false;
		}
		return true;
	}
	//A valid digit is 0-9, with the expection of '.' for floating point, and '-' for negative digits
	//A valid here cannot end with any post-fix, ex : 3.14f or 124L is invalid!
	bool _isAllDigits()const{
		size_t start = 0;
		if((*this)[0] == '-' ) 
			start = 1;
		for(; start < size(); ++start){
			char value = (*this)[start];
			if(! ::isdigit( value ) && value != '.' )
				return false;
		}
		return true;
	}
	void _assertValidSize()const{
		assert(size());
	}	
};


/* TODO: standard container classes -> extend standard containers and add more methods
// tuple

// list -> std::vector  https://stackoverflow.com/questions/17528657/python-list-equivalent-in-c   https://www.boost.org/doc/libs/1_42_0/doc/html/any/s02.html
       NO? std::list  https://en.wikipedia.org/wiki/List_(STL)

// dict -> std::unordered_map 
*/
    
// TODO: random class
/*
class random
{
    shuffle
    
}*/
