//
//  UIHelper.hpp
//  CPPContacts
//
//  Created by Nicolas Helbig on 28.10.25.
//

#ifndef UIHelper_hpp
#define UIHelper_hpp

#include <string>
#include <vector>
using namespace std;

class NavOption{
public: // will use public here since this doesn't store actual data
    char key;
    string description;
    
    // constructor
    NavOption(char k, string d){
        key = k;
        description = d;
    }
};

char GetOptionsStripInput(vector<NavOption> navOptions){
    for (int i = 0; i < navOptions.size(); i++){
        cout << navOptions[i].key << "\t" << navOptions[i].description << "\t\t";
    }
    cout << endl;
    
    char choice;
    cin >> choice;
    cout << endl;
    return choice;
}

#endif // !UIHelper_hpp
