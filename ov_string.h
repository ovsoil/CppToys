/**
 * @file ov_string.h
 * @brief   
 *  An implementation of string, easy for interview.
 * @author ovsoil
 * @version 1.0
 * @date 2015-12-02
 */


#ifndef _OV_STRING_H
#define _OV_STRING_H

#include <iostream>
#include <cstring>

namespace ov{

class String{
friend std::ostream& operator<<(std::ostream&, const String&);
friend std::istream& operator>>(std::istream&, String&);
public:
    String();
    String(const char*);
    String(const String&);
    ~String();
    
    size_t size() const;
    const char *c_str() const;
    void swap(String& s);

public:
    String& operator=(const String&);
    bool operator==(const String&);
    String& operator+(const String&);
    char& operator[](int);

private:
    char *_data;
};


//implement 

String::String():_data(new char[1]){
    _data[0] = '\0';
}


/**
 * @brief   构造函数：以c语言字符串构造String，使用空指针会抛出异常
 *
 * @param   pstr
 */
String::String(const char* pstr){
    if(NULL == pstr)
        throw "error";
    _data = new char[strlen(pstr) + 1];
    strcpy(_data, pstr);
}

String::String(const String& s){
    _data = new char[s.size() + 1];
    strcpy(_data, s.c_str());
}

String::~String(){
    delete[] _data;
}


size_t String::size() const{
    return strlen(_data);
}

const char *String::String::c_str() const{
    return _data;
}

void String::swap(String& s){
    std::swap(_data, s._data);
}

String& String::operator=(const String& rhs){
    if(this == &rhs)
        return *this;
    String tmp(rhs);
    swap(tmp);
    return *this;
}

bool String::operator==(const String& rhs){
    return 0 == strcmp(_data, rhs.c_str());
}

String& String::operator+(const String& rhs){
    char *p = new char[size() + rhs.size() + 1];
    strcpy(p, _data);
    strcat(p, rhs._data);
    String tmp(p);
    swap(tmp);
    return *this;
}

char& String::operator[](int rhs){
    return _data[rhs];
}

std::ostream& operator<<(std::ostream& os, const String& s){
    return os << s.c_str();
}

std::istream& operator>>(std::istream& is, String& s){
    char str[1024];
    is >> str;
    s = String(str);
    return is;
}

}

#endif /* _OV_STRING_H */
