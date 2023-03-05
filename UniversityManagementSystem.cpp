#include <bits/stdc++.h>
using namespace std;

void hold(){for(int i = 0; i < INT_MAX/8; ++i);}

map<string, string> faculty_id_password;
map<string, string> student_id_password;

class University{
    private:
        map<string, string> faculty_id_password;
        map<string, string> student_id_password;
    public:
        bool admin();
};
class Faculty{

    public: 
        string name;
        string position;
        string subject;

    void get_salary();
    void teach();
    void spend();

    private:
        long long int mobno;
        int experience;
        float salary;
        string address;

};
class Student {

    public: 
        string name;
        int roll_no;
        int year;
        string branch;
        bool hosteller;

    void student_login();
    void submit_fees();
    void study();
    void take_exam();
    void check_result();

    private:
        long long int mobno;
        float marks;
        float fees;
        string address;

};



char display(string menu_name, vector<string> option){                          //  edits : 03/03/2023, 02/03/2023
                                                                    //  Displays a menu with various optins to cloose from
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

    char menu;
    cout << "\t\t\tEnter option : ";
    cin >> menu;
    cout << "\n\n\n";
    if(menu < '0' || menu > option.size() + '0'){
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
        menu = '0';
        // timeout of 3 seconds
        hold(); hold();
    }
    return menu;
}


//  Class Admin
void add_id(){                                                                  //  edits : 03/03/2023
    system("clear");
    cout << "\n\n\t\t\t______1) Student______\n\n";
    cout << "\t\t\t______2) Faculty______\n\n";
    cout << "\t\t\tEnter an option : ";
    int opt;    cin >> opt;
    cin.ignore();               //if ( cin.ignore() ) or an empty ( getline() ) is not called, the next getline for string does not work, because it reads an extra newline from the preceding ( cin >> ).
    string name;    cout << "\n\n\t\tEnter Name : ";    getline(cin, name);
    long long int mob_no;    cout << "\n\t\tEnter Mobile Number : ";    cin >> mob_no;

    fstream data;
    bool is_duplicate = 0;
    string n;
    long long int m;
    data.open("database.txt", ios :: in);

    if(data){                                       //if file is not empty
        data >> opt >> n >> m;
        while(!data.eof()){
            if(n == name)
                is_duplicate = 1;
            data >> opt >> n >> m;
        }
        data.close();
        if(is_duplicate){                           //does data already exist?
            cout << "\t\tThe Person already has an account";                //data exists : don't do anything
            return;
        }
    }
    //either file is empty or data doesn't exist    :   insert the data in both cases
    data.open("database.txt", ios::app | ios::out);     //data didn't previously existed, append all data
    data << opt << " " << name << " " << mob_no << "\n";
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
    int id; cout << "\n\n\t\t\tEnter ID : ";    cin >> id;

    cout << "\n\n\t\t\tWork in progress";
    cout << "\n\n\t\t\tImplementation Pending";

    cout << "\n\n\t\t\tID deleted\n\n\n";

}
void god_mode(){                                                                //  edits : 04/03/2023
    /*Give read access to this code file*/
    fstream code;
    code.open("/home/satyam/Coding/Projects/UniversityMgmt/UniversityManagementSystem.cpp", ios :: in);
    char data[1000];
    while(!code.eof()){
        code >> data;
        cout << data << " ";
    }
    // cin.getline(data, 1000);
    // cout << data << endl;
    code.close();
}
void admin() {                                                                  //  edits : 02/03/2023
    //  add_id()    add new student, add new faculty
    //  del_id()    delete student, delete faculty
    //  god_mode()  add new functionality - do wahtever he wants - even has access to the matrix' code - omnipotent    
    int work = display("Admin menu", {"Add", "Delete", "Ultimate"});
    int option;
    switch(work){
        case '0' : exit(0);
        break;
        case '1' : add_id();
        break;
        case '2' : del_id();
        break;
        case '3' : god_mode();
        break;
    }
}

void put_notice(){                                                              //  edits : 05/03/2023
}
void prepare_exam(){}
void check_exam(){}
void faculty(){                                                                 //  edits : 03/03/2023
    //  put_notice()
    //  prepare_exam()
    //  check_exam()
    //  edit_result()             //what is this function? what will it do?
    int work = display("Faculty menu", {"Edit Notice Board", "Prepare Exam", "Check Exam"});
    int option;
    switch(work){
        case '0' : exit(0);
        break;
        case '1' : put_notice();
        break;
        case '2' : prepare_exam();
        break;
        case '3' : check_exam();
        break;
    }
}


void student(){}

void menu(){                                                                    // edits : 01/03/2023, 27/02/2023, 26/02/2023
    bool logged = 0; 
    char menu;
    string id, code;    
    do{
        string menu_name = "University Main Menu";
        vector<string> options = {"Department Admin", "Faculty", "Student"};
        menu = display(menu_name, options);
        if(menu >= '1' && menu <= '3'){
            cout << "\t\t\tEnter Your ID : ";                       cin >> id;
            cout << "\t\t\tEnter Your Password : ";                 cin >> code;
        }
        /*
        if(menu == '1' && id == "s" && code == "s") 
            logged = 1;
        else if(menu == '2' && faculty_id_password[id] == code) 
            logged = 1;
        else if(menu == '3' && student_id_password[id] == code) 
            logged = 1;
        else{
            if(menu == '0') {
                cout << "\n\n\t\t\tEXIT\n\n\n";
                exit(0);
            }
        }
        if(logged){
            cout << "\n\t\t\tYou are successfully logged in.\n\n\n";
            hold();
            switch(menu){
                case '1': admin();  break;
                case '2': faculty(); break;
                case '3': student(); break;
            }
        }
        else{
            cout << "\n\t\t\tInvalid Username/Password\n";
            hold();
        }
        */
        switch(menu){
            case '1':
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
            case '2':
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
            case '3':
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
            default :
                if(menu == '0') {
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

}