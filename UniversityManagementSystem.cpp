#include <bits/stdc++.h>
using namespace std;

void hold(){for(int i = 0; i < INT_MAX/8; ++i);}

map<string, string> faculty_id_password = {{"faculty", "faculty"}};
map<string, string> student_id_password = {{"student", "student"}};

class Admin{
    private:
        map<string, string> faculty_id_password;
        map<string, string> student_id_password;
    public:
        void admin();
        void add_id();
        void del_id();
        void god_mode();

};
class Faculty{

    public: 
        string name;
        string position;
        string subject;

    void faculty();
    void put_notice();
    void prepare_exam();
    void check_exam();

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
        char gender;

    void student();
    bool get_fee(float);
    void submit_fees();
    void give_exam();
    void check_result();

    private:
        long long int mobno;
        float marks;
        float fee;
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
void god_mode(){                                                                //  edits : 06/03/2023, 04/03/2023
    system("clear");
    /*Give read access to this code file*/
    fstream code;
    code.open("/home/satyam/Coding/UniversityMgmt/UniversityManagementSystem.cpp", ios :: in);
    string line;
    while(getline(code, line))
        cout << line << endl;
    code.close();
    
    // fstream code;
    // code.open("/home/satyam/Coding/UniversityMgmt/UniversityManagementSystem.cpp", ios :: in);
    // char data[1000];
    // while(!code.eof()){
    // code.close();

}
void admin(){                                                                   //  edits : 02/03/2023
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

// class Faculty
void put_notice(){                                                              //  edits : 13/03/2023, 05/03/2023
    cout << "\n\n\t\t\tEnter a notice to be displayed : \n\n\t\t\t";
    string notice;
    cin.ignore();                                   // to ignore an extra enter key from previous keypress
    getline(cin, notice);
    // noticeBoard.push(notice);                                                // NoticeBoard class handles all notices 
    // cout << "\n\n\t\t\t" << noticeBoard.top();
    cout << "\n\n\t\t\t" << "Notice Published to Notice Board";
    cout << "\n\n\n\n";
}
void prepare_exam(){                                                            //  edits : 06/03/2023
    system("clear");
    int n;    cout << "\n\n\t\t\t" << "How Many Questions to create?\t";      cin >> n; 
    int q;    cout << "\t\t\tNumber of Options in every Question?\t";       cin >> q;
    fstream data;
    data.open("questions.txt", ios :: in);
    if(data){
        //  what to do if file is not empty?
        //  maybe upload it to PYQ's
        //  delete file
        data.open("questions.txt", ios::out);
        data << "";
    }
    data.open("questions.txt", ios::app | ios::out);
    //  previous data is deleted
    for(int i = 1; i <= n; ++i){
        cout << "\n\n\n\t\t\tQuestion " << i << " : ";
        cin.ignore();
        string question;      getline(cin, question);
        cout << endl;
        data << "Question " << i << " : " << question << "\n";     // first letter not showing maybe input bug, maybe output
        for(int j = 1; j <= q; ++j){
            cout << "\t\t\tOption " << j << " : ";
            string option;        getline(cin, option);
            data << "Option " << j << " : " << option << "\n";     // first letter not showing maybe input bug, maybe output
        }
        data.close();
        cout << "\n\t\t\tQuestion " << i << " entered.\n";
        if(i != n)
            cout << "\t\t\tEnter next Question.";
        else{
            cout << "\n\n\t\t\tQuestion paper created.";                        // not printing properly
            cin.ignore();                                                       // bug occuring
            hold();hold();
            system("clear");                                                    // clear executing first, the previous line, later
            cout << "\n\n\n\t\t\t\t___Press 1 to View___";
            cout << "\n\n\t\t\t\t___Press 0 to Exit___";
            cout << "\n\n\t\t\t\t\t";
            bool view;  cin >> view;
            if(view){
                system("clear");
                //  View question paper
                fstream paper;
                paper.open("questions.txt", ios::in);
                string line;
                while(getline(paper, line))                     // first letter not showing maybe input bug, maybe output
                    cout << line << endl;
                paper.close();
            }
        }
    }
}
void check_exam(){}
void faculty(){                                                                 //  edits : 05/03/2023
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

// class Student
bool get_fee(float fee){                                                        //  edits : 05/03/2023
    //  Fee contains the amount of fees to be submitted
    //  Return the confirmation of whether fees is submitted or not

    cout << "\n\n\n\t\t\t\tImplementation Pending\n\n\n";
    return 0;
}
void submit_fees(){                                                             //  edits : 05/03/2023
    // Display fees
    string name = "Get this name";          //  get name of student
    string branch = "Get Department";           //  get department of study
    int year = 1;                           //  get year of study
    char gender = 'M';                      //  get gender
    float fee = 3;                          //  get fees - if 0, print fees is submitted
    system("clear");
    cout << "\n\n\n\t\t\t\tName : " << name;
    cout << "\t\t\t\tGender: " << gender;
    cout << "\n\n\t\t\t\tInfo : \t" << branch << " " << year << " year";
    if(fee == 0){
        cout << "\n\n\n\t\t\t\tYour fee is already submitted";
        cout << "\n\n\n\t\t\t\tAap hamari University ki shaan ho...!!!";
        cout << "\n\n\t\t\t\tThank You for Visiting.\n\n\n\n";
        exit(0);
    }
    cout << "\n\n\n\t\t\t\tFee to be submitted : " << fee;
    cout << "\n\n\n\n\n\t\t\t\tPress 1 to submit now.";
    cout << "\n\n\n\t\t\t\tPress 0 to exit.\n\n\n\n";
    char option;    cout << "\t\t\t\t";     cin >> option;
    if(option != '1' && option != '0'){
        cout << "\n\n\n\t\t\t\tYou are Naughty";
        cout << "\n\n\t\t\t\tEXITING...\n\n\n\n";
        exit(0);
    }
    if(option == '0'){
        char notation = 'e';
        if(gender == 'M')
            notation = 'a';
        else if(gender == 'F')
            notation = 'i';
        cout << "\n\n\n\t\t\t\tAre yarr... Fees to bhart" << notation << " jat" << notation << "\n\n\n\n";
        exit(0);
    }
    bool submitted = get_fee(fee);                  // submited contains confirmation
    if(submitted){
        cout << "\n\n\n\t\t\t\tCongratualations!!!";
        cout << "\n\n\t\t\t\tYour fees has been submitted";
    }
    else{
        cout << "\n\n\n\t\t\t\tSorry!!!";
        cout << "\n\n\t\t\t\tFees submittion failed";
    }
    cout << "\n\n\n\n";
}
void give_exam(){}
void check_result(){}
void student(){                                                                 //  edits : 13/03/2023
    // submit_fees()
    // give_exam()
    // check_result()
    int work = display("Student menu", {"Submit Fees", "Give Exam", "Check Result"});
    int option;
    switch(work){
        case '0' : exit(0);
        break;
        case '1' : submit_fees();
        break;
        case '2' : give_exam();
        break;
        case '3' : check_result();
        break;
    }
}

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
    // prepare_exam();
}