#include <bits/stdc++.h>
#include "helper.h"

using namespace std;

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
    int work = display("Student menu", {"Submit Fees", "Give Exam", "Check Result"});
    int option;
    switch(work){
        case '0' : exit(0);
        break;
        case '1' : 
        break;
        case '2' : submit_fees();
        break;
        case '3' : give_exam();
        break;
        case '4' : check_result();
        break;
    }
}