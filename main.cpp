#include "ov_string.h"
#include <vector>
using ov::string;

void func1(string s){
    std::cout << "In func1: " << s << std::endl;
}
void func2(const string& s){
    std::cout << "In func2: " << s << std::endl;
}

int main(int argc, char *argv[])
{
    string s1 = ov::string();
    string s2 = ov::string("hello");
    string s3 = ov::string(s2);
    string s4 = s2;

    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    std::cout << s3 << std::endl;
    std::cout << s4 << std::endl;

    func1(s1);
    func2(s2);
    func1("temporary");
    func2("temporary");

    std::vector<string> sv;
    sv.push_back(s1);
    sv.push_back(s2);
    sv.push_back("google");

    for(int i = 0; i < sv.size(); ++i){
        std::cout << sv[i] << std::endl;
    }
    return 0;
}
