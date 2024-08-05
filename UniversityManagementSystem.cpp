#include <bits/stdc++.h>
// #include "helper.h"
#include "student.h"
#include "faculty.h"
#include "admin.h"
using namespace std;

//  Forward declaration from the helper file
void hold();
void wrong_password();
int display(string, vector<string>);

class Admin;
class Student;
class Faculty;

void menu(){                                                                    // edits : 01/03/2023, 27/02/2023, 26/02/2023
    bool logged = 0; 
    int menu;
    string id, code;    
    do{
        string menu_name = "University Main Menu";
        vector<string> options = {"Department Admin", "Faculty", "Student"};
        menu = display(menu_name, options);                                     // Selected option is stored in "menu"
        if(menu >= 1 && menu <= 3){
            cout << "\t\t\tEnter Your ID : ";                       cin >> id;
            cout << "\t\t\tEnter Your Password : ";                 cin >> code;
        }
        
        switch(menu){
            case 1:
                if(id == "s" && code == "s") {
                    logged = 1;
                    cout << "\n\t\t\tYou are successfully logged in.\n\n\n";
                    hold();
                    admin();
                }
                else
                    cout << "\n\t\t\tInvalid Username/Password\n";
                    hold();
                break;
            case 2:
                if(faculty_id_password[id] == code) {
                    logged = 1;
                    cout << "\n\t\t\tYou are successfully logged in.\n\n\n";
                    hold();
                    faculty();
                }
                else
                    cout << "\n\t\t\tInvalid Username/Password\n";
                    hold();
                break;
            case 3:
                if(student_id_password[id] == code) {
                    logged = 1;
                    cout << "\n\t\t\tYou are successfully logged in.\n\n\n";
                    hold();
                    student();
                }
                else
                    cout << "\n\t\t\tInvalid Username/Password\n";
                    hold();
                break;
            default:
                if(menu == 0) {
                    cout << "\n\n\t\t\tEXIT\n\n\n";
                    exit(0);
                }
        }
    }
    while(!logged);
}
int main(){
    // cin.tie(nullptr);
    // University* univ1 = new University();
    menu();
    // prepare_exam();
}