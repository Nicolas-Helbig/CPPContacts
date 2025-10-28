//
//  main.cpp
//  CPPContacts
//
//  Created by Nicolas Helbig on 28.10.25.
//

#include <iostream>
#include "Contact.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    Contact person("Alice", 25, true, 'A', 5.6, EyeColor::Blue);
    cout << person.getName() << endl;
    cout << person.getAge() << endl;
    
    return EXIT_SUCCESS;
}
