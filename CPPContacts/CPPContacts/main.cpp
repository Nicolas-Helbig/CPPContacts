//
//  main.cpp
//  CPPContacts
//
//  Created by Nicolas Helbig on 28.10.25.
//

#include <iostream>
#include <vector> // it seems to work without this but whatever
#include "Contact.hpp"
#include "UIHelper.hpp"
using namespace std;

// data storage (would use a model / view model in a professional app but this is simple
vector<Contact> Contacts;

// forward declaration (lets the compiler know the function(s) will be declared later
void AddNewContact();
void DisplayContactsList();

// actual main method
int main(int argc, const char * argv[]) {
    cout << "Welcome to CPPContacts, CPP standing for C++, not Chinese Pommunist Party." << endl;
    
    if (Contacts.empty()){
        cout << "It seems like you do not have any contacts yet. Do you wish to create one?" << endl;
        vector<NavOption> options = {
            NavOption('N', "New Contact"),
            NavOption('D', "Add Dummy Contact"),
            NavOption('E', "Exit App")
        };
        char response = GetOptionsStripInput(options);
        switch (response){
            case 'N': // use fall-through to accept both
            case 'n':
                AddNewContact();
                break;
            case 'D':
            case 'd':{
                Contact dummyPerson("Alice", 25, true, 'A', 1.6, EyeColor::Blue);
                // push_back appends to the end
                Contacts.push_back(dummyPerson);
                cout << "Alice added, here is your current contacts list:\n" << endl;
                DisplayContactsList();
                break;
            } // curly braces necessary because of the variable declaration, compiler will otherwise get confused about its scope
            case 'E':
            case 'e':
                cout << "Thank you for considering CPPContacts!" << endl;
                return 0;
        }
    }
    else{
        return 1;
    }
    
    return EXIT_SUCCESS;
    /// List of exit codes:
    /// 0   Exited successfully
    /// 1   Failed from unexpected result: Contacts list contained at least one contact on startup
}

void AddNewContact(){
    cout << "Contact Creation Wizzard launched!" << endl;
    
    cout << "What's the contact's name?" << endl;
    string name;
    cin >> name;
    
    cout << "How old are they?" << endl;
    int age;
    cin >> age;
    
    cout << "Are they female? (y/n)" << endl;
    string isFemaleString;
    cin >> isFemaleString;
    bool isFemale = false;
    if (isFemaleString == "y") isFemale = true;
    
    cout << "What is their initial letter?" << endl;
    char initial;
    cin >> initial;
    
    cout << "How tall are they?" << endl;
    double height;
    cin >> height;
    
    cout << "What is their eye color?" << endl;
    string eyeColorString;
    cin >> eyeColorString;
    EyeColor eyeColor = EyeColor::Other;
    if (eyeColorString == "brown" || eyeColorString == "Brown") eyeColor = EyeColor::Brown;
    if (eyeColorString == "blue" || eyeColorString == "Blue") eyeColor = EyeColor::Blue;
    
    Contact newContact(name, age, isFemale, initial, height, eyeColor);
    Contacts.push_back(newContact);
    
    cout << "Congratulations, your contact has been added.\nYour contact list currently contains:\n" << endl;
    DisplayContactsList();
}

void DisplayContactsList(){
    cout << "Name\tAge\t\tGender\t\tInitial\t\tHeight\t\tEye Color" << endl;
    for (int i = 0; i < Contacts.size(); i++){
        Contact ct = Contacts[i];
        
        string eyeColor;
        EyeColor c = ct.getEyeColor();
        switch (c){
            case EyeColor::Brown:
                eyeColor = "Brown";
                break;
            case EyeColor::Blue:
                eyeColor = "Blue";
                break;
            default:
                eyeColor = "Special";
                break;
        }
        
        cout << ct.getName() << "\t" << ct.getAge() << "\t\t"  << (ct.getIsFemale() ? "Female" : "Male") << "\t\t"  << ct.getInitial() << "\t\t\t"  << ct.getHeight() << "\t\t\t" << eyeColor << endl;
    }
    cout << endl;
    
    vector<NavOption> options = {
        NavOption('N', "New Contact"),
        NavOption('E', "Exit App")
    };
    char response = GetOptionsStripInput(options);
    switch (response){
        case 'N': // use fall-through to accept both
        case 'n':
            AddNewContact();
            break;
        case 'E':
        case 'e':
            cout << "Thank you for considering CPPContacts!" << endl;
            break;
    }
}
