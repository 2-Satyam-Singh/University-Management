#include <bits/stdc++.h>
#include "helper.h"

using namespace std;

class Admin{
    private:
        // map<string, string> faculty_id_password;
        // map<string, string> student_id_password;
    public:
        void admin();
        void add_id();      //  add new student, add new faculty      
        void del_id();      //  delete student, delete faculty
        void god_mode();    //  add new functionality - do wahtever he wants - even has access to the matrix' code - omnipotent    

};
void add_id(){                                                                  //  edits : 03/03/2023
    system("clear");
    cout << "\n\n\t\t\t______1) Student______\n\n";
    cout << "\t\t\t______2) Faculty______\n\n";
    cout << "\t\t\tEnter an option : ";
    int option;    cin >> option;
    cin.ignore();               //if ( cin.ignore() ) or an empty ( getline() ) is not called, the next getline for string does not work, because it reads an extra newline from the preceding ( cin >> ).
    string name;    cout << "\n\n\t\tEnter Name : ";    getline(cin, name);
    long long int mob_no;    cout << "\n\t\tEnter Mobile Number : ";    cin >> mob_no;

    fstream data;
    bool is_duplicate = 0;
    int opt;
    string n;
    long long int m;
    data.open("database.txt", ios :: in);

    if(data){                                       //if file is not empty
        data >> opt >> n >> m;
        while(!data.eof()){
            if(opt == option && n == name)                          //  Once roll no is created, check using it. refer line 49---┐
                is_duplicate = 1;                                   //                                                           |
            data >> opt >> n >> m;                                  //                                                           |
        }                                                           //                                                           |
        data.close();                                               //                                                           |
        if(is_duplicate){                           //does data already exist?                                                   |
            cout << "\t\tThe Person already has an account";                //data exists : don't do anything                    |
            return;                                                 //                                                           |
        }                                                           //                                                           |
    }                                                               //                                                           |
    //either file is empty or data doesn't exist    :   insert the data in both cases                                            |
    data.open("database.txt", ios::app | ios::out);     //data didn't previously existed, append all data                        V
    data << opt << " " << name << " " << mob_no << "\n";            //  Create a system generated roll number and save alongside it.
    data.close();
    cout << "\t\tWelcome the newest member of the University Family\n\n";

    // if(opt == 1){
    //     Faculty f = new Faculty(name, mob_no);
    // }
    // else if(opt == 2){
    //     Student s = new Student(name, mob_no);
    // }
}
void del_id(){                                                                  //  edits : 04/03/2023
    /*Input students' / faculty's id, delete it and move it to past_faculties / passouts*/
    system("clear");
    //  int id; cout << "\n\n\t\t\tEnter ID : ";    cin >> id;          //  Once system generated roll no is created use that
    //  Ask for confirmation before deleting

    system("clear");
    cout << "\n\n\t\t\t______1) Student______\n\n";
    cout << "\t\t\t______2) Faculty______\n\n";
    cout << "\t\t\tEnter an option : ";
    int option;    cin >> option;
    cin.ignore();               //if ( cin.ignore() ) or an empty ( getline() ) is not called, the next getline for string does not work, because it reads an extra newline from the preceding ( cin >> ).
    string name;    cout << "\n\n\t\tEnter Name : ";    getline(cin, name);
    long long int mob_no;    cout << "\n\t\tEnter Mobile Number : ";    cin >> mob_no;


    /*  Algorithm  */
    //  Read the file line by line and rewrite it into new file
    //  Don't rewrite the data that needs to be deleted
    //  Rename the old file as backup, and new file as original.

    int opt;
    string n;
    long long int m;

    fstream data;
    data.open("database.txt", ios::in);

    fstream update;
    // update.open("updated_database.txt", ios::out);
    // update.close();
    update.open("updated_database.txt", ios::app | ios::out);

    if(data){                                       //  if file is not empty
        data >> opt >> n >> m;
        while(!data.eof()){
            if(opt == option && n == name && m == mob_no)
                continue;
            update << opt << " " << n << " " << m << "\n";
            data >> opt >> n >> m;
        }
    }
                                                   //     1 Lakki 123472136
    data.close();
    update.close();

    cout << "\n\n\t\t\tWork in progress";

    cout << "\n\n\t\t\tImplementation Pending";

    // cout << "\n\n\t\t\tID deleted\n\n\n";s

}
void god_mode(){                                                                //  edits : 06/03/2023, 04/03/2023, 07/07/2024
    system("clear");
    /*Give read access to this code file*/      //  {Update Later} Don't give access to code, Give access to the data, the teacher and student name and mobile number.
    fstream code;
    code.open("/home/satyams/Code/Project1/University-Management/UniversityManagementSystem.cpp", ios :: in);
    string line;
    while(getline(code, line))
        cout << line << endl;
    code.close();
}
void admin(){                                                                   //  edits : 02/03/2023
    int work = display("Admin menu", {"Add", "Delete", "Ultimate"});
    switch(work){
        case 0 : exit(0);
        break;
        case 1 : add_id();
        break;
        case 2 : del_id();
        break;
        case 3 : god_mode();
        break;
    }
}