#ifndef _OV_STRING_H
#define _OV_STRING_H
#include <stddef.h>
#include <iostream>

namespace ov{
class string{
friend std::ostream& operator<<(std::ostream& os, const string& s);
friend std::istream& operator>>(std::istream& is, string& s);
public:
    string();
    string(const char *s);
    string(const string& s);
    ~string();

    const char *c_str() const;
    int size() const;
    void swap(string& s);

public:
    string& operator=(const string& s);
    bool operator==(const string& s);
    const string& operator+(const string& s);
private:
    char *_data;
};
}

#endif /* _OV_STRING_H */
