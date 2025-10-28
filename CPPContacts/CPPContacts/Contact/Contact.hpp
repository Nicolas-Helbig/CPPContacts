//
//  Contact.hpp
//  CPPContacts
//
//  Created by Nicolas Helbig on 28.10.25.
//

#ifndef Contact_hpp // if Contacts_hpp isn't yet defined...
#define Contact_hpp // define it because otherwise the compiler might see things twice if we reference something here that already defines Contact_hpp, this needs to be prevented

#include <string> // we will need strings!
using namespace std; // this is to we don't need to write std::string every time, just string is enough, it will get it

enum class EyeColor : int {
    Brown = 1,
    Blue = 2,
    Other = 3
};

class Contact{
private:
    string name;
    int age;
    bool isFemale;
    char initial;
    double height;
    EyeColor eyeColor;
    
public:
    // constructor
    Contact(string n, int a, bool f, char i, double h, EyeColor e);
    
    // getters
    string getName();
    int getAge();
    bool getIsFemale();
    char getInitial();
    double getHeight();
    EyeColor getEyeColor();
    
    // setters
    void setName(string n);
    void setAge(int a);
    void setIsFemale(bool f);
    void setInitial(char i);
    void setHeight(double h);
    void setEyeColor(EyeColor e);
};

#endif // !Contact_hpp; this just ends the if statement
