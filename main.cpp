#include <iostream>
#include <windows.h>
#include <mysql.h>
#include <sstream>

using namespace std;

void addRec();
void delRec();
void viewRec();
MYSQL* connect();
int main()
{
    /*MYSQL* conn;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "10.214.3.15", "admin", "admin", "test1", 0, NULL, 0);
    if(conn)
        cout<<"CONNECTED\n";
    else
        cout<<"ERROR";


    int qstate = 0;
    stringstream ss;

    string name = "rhuel gwapo";

    ss<<"INSERT INTO testt1(name) VALUES('"<< name <<"')";

    string query = ss.str();
    const char* q = query.c_str();
    qstate = mysql_query(conn, q);

    if(qstate == 0)
    {
        cout<<"RECORD INSERTED...";
    }
    else
        cout<<"FAILED to insert";
    */

    int checkRun = 0;
    while(checkRun == 0)
    {
        int choice;

        cout<<"DATABASE MANAGEMENT SYSTEM"<<endl<<"[1]ADD"<<endl<<"[2]DELETE"<<endl<<"[3]EDIT"<<endl<<"[4]SORT"<<endl<<"[5]VIEW"<<endl<<"[6]EXIT"<<endl;

        cin>>choice;

        switch(choice)
        {
        case 1:
            addRec();
            break;
        case 2:
            delRec();
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            viewRec();
            break;
        case 6:
            checkRun = 1;
            break;
        }
        cin.ignore();
    }
}
MYSQL* connect()
{
    MYSQL* conn;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "10.214.2.54", "admin", "admin", "dbms", 0, NULL, 0);

    return conn;
}
void addRec()
{
    MYSQL* checkCon = connect();
    if(checkCon)
    {
        string studentID, surname, firstname, birthdate, address;
        char gender;
        int qstate = 0;

        cout << "ENTER STUDENT ID: ";
        cin >> studentID;

        cout << "ENTER SURNAME: ";
        getline(cin, surname);

        cout << "ENTER FIRSTNAME: ";
        getline(cin, firstname);

        cout << "ENTER BIRTHDATE: ";
        getline(cin, birthdate);

        cout << "ENTER ADDRESS: ";
        getline(cin, address);

        cout << "ENTER GENDER: ";
        cin >> gender;

        stringstream ss;

        ss<<"INSERT INTO student(studentID, surname, firstname, birthdate, address, gender) VALUES('"<<studentID<<"','"
        <<surname<<"','"<<firstname<<"','"<<birthdate<<"','"<<address<<"','"<<gender<<"')";

        string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(checkCon, q);

        cout<<endl;

        if(qstate == 0)
            cout<<"RECORD INSERTED..."<<endl;
        else
            cout<<"FAILED TO INSERT..."<<endl;
    }
    else
        cout<<"FAILED TO ESTABLISH CONNECTION";

    system("pause");
    system("cls");
}
void viewRec()
{
    MYSQL* checkCon = connect();
    MYSQL_ROW row;
    MYSQL_RES* res;
    if(checkCon)
    {
        int qstate = mysql_query(checkCon, "SELECT studentID, firstname, surname, birthdate, gender, address FROM student");

        if(!qstate)
        {
            res = mysql_store_result(checkCon);

            while((row = mysql_fetch_row(res)))
                cout<<row[0]<<"\t | \t"<<row[1]<<"\t | \t"<<row[2]<<"\t | \t"<<row[3]<<"\t | \t"<<row[4]<<"\t | \t"<<row[5]<<endl;
        }
    }
    system("pause");
    system("cls");
}
void delRec()
{
    MYSQL* checkCon = connect();

    if(checkCon)
    {
        viewRec();
        string studentID;

        cout<<"\n Enter StudentId to delete: ";
        cin>>studentID;

        stringstream ss;

        ss<<"DELETE FROM student WHERE studentID = '"+ studentID +"'";
        string query = ss.str();
        const char* q = query.c_str();

        int qstate = mysql_query(checkCon,q);

        if(qstate == 0)
            cout<<"ROW DELETED...";
        else
            cout<<"ROW FAILED TO DELETE...";
    }
    else
        cout<<"FAILED TO ESTABLISH CONNECTION";

    system("pause");
    system("cls");

}
