#pragma once        //  To stop conflicts due to repeated inclusion of this file.

// If #pragma once don't work, use below 4 lines.
// #ifndef FILE1_H
// #define FILE1_H

// // Your code here

// #endif // FILE1_H


#include <iostream>
using namespace std;



map<string, string> faculty_id_password = {{"faculty", "faculty"}};
map<string, string> student_id_password = {{"student", "student"}};


void hold(){for(int i = 0; i < INT_MAX/8; ++i);}
void wrong_password(){cout << "\n\t\t\tInvalid Username/Password\n";hold();}


int display(string menu_name, vector<string> option){                           //  edits : 03/03/2023, 02/03/2023, 06/07/2024
                                                                    //  Displays a menu with various options to choose from
    int menu_spacing = 28 - menu_name.size();
    string ml;
    for(int i = 0; i < menu_spacing/2; ++i)
        ml.push_back(' ');
    string mr = ml;
    if(menu_spacing % 2 == 1)
        mr.push_back(' ');

    system("clear");
    cout << "\t\t\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
    cout << "\t\t\tX                                                   X\n";
    cout << "\t\t\tX           ------------------------------          X\n";
    cout << "\t\t\tX           |"<< ml << menu_name<< mr <<"|          X\n";
    cout << "\t\t\tX           ------------------------------          X\n";
    cout << "\t\t\tX                                                   X\n";
    cout << "\t\t\tX  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  X\n";
    cout << "\t\t\tX  X                                             X  X\n";
    for(int i = 0; i < option.size(); ++i){
        cout << "\t\t\tX  X             " << i+1 << ") " << option[i];
        for(int j = option[i].size(); j < 29; ++j)  cout << " "; cout << "X  X\n";
        cout << "\t\t\tX  X                                             X  X\n";
    }
    cout << "\t\t\tX  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  X\n";
    cout << "\t\t\tX                                                   X\n";
    cout << "\t\t\tX                  PRESS 0 TO EXIT                  X\n";
    cout << "\t\t\tX                                                   X\n";
    cout << "\t\t\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n\n\n";

    int menu;                                                                   //  Option to be chosen
    cout << "\t\t\tEnter option : ";
    cin >> menu;
    cout << "\n\n\n";
    if(menu < 0 || menu > option.size()){
        system("clear");
        cout << "\t\t\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
        cout << "\t\t\tX                                                 X\n";
        cout << "\t\t\tX  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  X\n";
        cout << "\t\t\tX  X                                           X  X\n";
        cout << "\t\t\tX  X            Not a Valid Option             X  X\n";
        cout << "\t\t\tX  X                                           X  X\n";
        cout << "\t\t\tX  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  X\n";
        cout << "\t\t\tX                                                 X\n";
        cout << "\t\t\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n" << endl;
        // timeout of 3 seconds
        hold(); hold();
    }
    return menu;
}