//
//  Contact.cpp
//  CPPContacts
//
//  Created by Nicolas Helbig on 28.10.25.
//

#include "Contact.hpp"

// constructor
Contact::Contact(string n, int a, bool f, char i, double h, EyeColor e) {
    name = n;
    age = a;
    isFemale = f;
    initial = i;
    height = h;
    eyeColor = e;
}

// getters
string Contact::getName() {
    return name;
}
int Contact::getAge() {
    return age;
}
bool Contact::getIsFemale() {
    return isFemale;
}
char Contact::getInitial() {
    return initial;
}
double Contact::getHeight() {
    return height;
}
EyeColor Contact::getEyeColor() {
    return eyeColor;
}

// setters
void Contact::setName(string n) {
    name = n;
}
void Contact::setAge(int a) {
    age = a;
}
void Contact::setIsFemale(bool f) {
    isFemale = f;
}
void Contact::setInitial(char i) {
    initial = i;
}
void Contact::setHeight(double h) {
    height = h;
}
void Contact::setEyeColor(EyeColor e) {
    eyeColor = e;
}
