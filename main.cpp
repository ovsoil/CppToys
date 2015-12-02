#include "ov_String.h"
#include <vector>
using ov::String;

void func1(String s){
    std::cout << "In func1: " << s << std::endl;
}
void func2(const String& s){
    std::cout << "In func2: " << s << std::endl;
}

int main(int argc, char *argv[])
{
    String s1 = ov::String();
    String s2 = ov::String("hello");
    String s3 = ov::String(s2);
    String s4 = s2;

    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    std::cout << s3 << std::endl;
    std::cout << s4 << std::endl;

    s2[1] = 'o';
    std::cout << s2 << std::endl;
    func1(s1);
    func2(s2);
    func1("temporary");
    func2("temporary");

    std::vector<String> sv;
    sv.push_back(s1);
    sv.push_back(s2);
    sv.push_back("google");

    for(int i = 0; i < sv.size(); ++i){
        std::cout << sv[i] << std::endl;
    }
    return 0;
}
