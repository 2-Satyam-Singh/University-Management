#include <bits/stdc++.h>
#include "helper.h"

using namespace std;

class Faculty{

    public: 
        string name;
        string position;
        string subject;

    void faculty();
    void put_notice();
    void prepare_exam();
    void check_exam();
    void edit_result();

    private:
        long long int mobno;
        int experience;
        float salary;
        string address;

};
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
void edit_result(){}
void faculty(){                                                                 //  edits : 05/03/2023
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
        case '4' : edit_result();
        break;
    }
}