#include <iostream>

int main(){

    std::string str = "HI THIS IS BRAIN";   //original string
    std::string* strptr = &str;             //pointer to the string
    std::string& strref = str;              //reference to the string

    std::cout << "Memory address of string is               :" << &str << std::endl;
    std::cout << "Memory address held by string pointer is  :" << strptr << std::endl;
    std::cout << "Memory address held by string reference is:" << &strref << std::endl;

    std::cout << "\nValue of the string is                :" << str << std::endl;
    std::cout << "Value pointed by string pointer is    :" << *strptr << std::endl;
    std::cout << "Value pointer by string reference is  :" << strref << std::endl;

    return(0);
}
