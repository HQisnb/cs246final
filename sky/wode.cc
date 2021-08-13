
#include <iostream>
#include <memory>
#include <fstream>
#include <sstream>
#include <string>

int main() {
    std::ifstream file1 {"sequence1.txt"};
    std::ifstream file2 {"sequence2.txt"};
    std::stringstream iss1;
    std::stringstream iss2;
    iss1 << file1.rdbuf();
    file1.close();
    iss2 << file2.rdbuf();
    file2.close();

    while (iss1) {
        char a;
        char b;
        iss1 >> a;
        iss2 >> b;
        std::cout << "char a is " << a << std::endl;
        std::cout << "char b is " << b << std::endl;
    }
}