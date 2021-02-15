#include <iostream>
#include <string.h>

class Test {
public:
    Test(std::string && str) {
        m_str = &str;
    }
    std::string* m_str;
};

int main(int, char* [])
{
    Test test(std::string("HelloWorld"));

    std::cout << *test.m_str << std::endl;

    return 0;
}