#include <cstring>
#include <algorithm>
#include "ov_string.h"

namespace ov{

    std::ostream& operator<<(std::ostream& os, const string& s){
        os << "ov::string(\"" << s.c_str() << "\")";
        return os;
    }

    std::istream& operator>>(std::istream& is, string& s){
        char str[1024];
        is >> str;
        s = string(str);
        return is;
    }

string::string() : _data(new char[1]){
    _data[0] = '\0';
}

string::string(const char *s) {
    if(NULL == s){
        throw "error";
    }
    _data = new char[strlen(s) + 1];
    strcpy(_data, s);
}

string::string(const string& s){
    _data = new char[s.size() + 1];
    std::strcpy(_data, s._data);
}

string::~string(){
    delete[] _data;
}

string &string::operator=(const string& s){
    if(this == &s)
        return *this;
    string tmp(s);
    std::swap(_data, tmp._data);
    return *this;
}

bool string::operator==(const string& s){
    return 0 == strcmp(_data, s.c_str())? true : false;
}

const string& string::operator+(const string& s){
    char *p = new char[size() + s.size() + 1];
    strcpy(p, _data);
    strcat(p, s._data);
    string tmp(p);
    std::swap(_data, tmp._data);
    return *this;
}

const char *string::c_str() const{
    return _data;
}

int string::size() const{
    return strlen(_data);
}

void string::swap(string& s){
    std::swap(_data, s._data);
}
}
