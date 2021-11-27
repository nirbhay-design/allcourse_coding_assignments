#include <windows.h>
#include <bits/stdc++.h>
#include <mysql.h>

using namespace std;
int qstate;
MYSQL * conn;
MYSQL_ROW row;
MYSQL_RES *res;
class dbsystem{
public:
    static void connectionfunction(){
        conn = mysql_init(0);
//192.168.1.9
        conn = mysql_real_connect(conn,"localhost","Nirbhay","nirbhay@#$234","employdata",0,NULL,0);
        if (conn ) {
            cout << "connection successful " << endl;
        } else {
            cout << "connection failed" << endl;
        }
    }

};
void function1(string query_string);
void function2(); 
void function3();
void RegisterEmployee();
void displayEmployee();
void createtable(string query_string);
int main(int argc , char * argv[]) {

    //dbsystem::connectionfunction();

    // dbsystem sys;
    // sys.connectionfunction();

    // string query_string = "CREATE TABLE employee (emp_name VARCHAR(50) , email VARCHAR(50) NOT NULL PRIMARY KEY, con_no VARCHAR(12), dept VARCHAR(20))";
    // query_string = "CREATE TABLE department (emp_name VARCHAR(50),salary VARCHAR(50),emp_designation VARCHAR(50),email VARCHAR(50) NOT NULL PRIMARY KEY)";
    // query_string = "CREATE TABLE awardee (emp_name  VARCHAR(50),email VARCHAR(50) NOT NULL PRIMARY KEY,dept VARCHAR(50),exp VARCHAR(50))";
    // createtable(query_string);

    return 0;
}


void createtable(string query_string) {
    const char * quri = query_string.c_str();
    qstate = mysql_query(conn,quri);
    if (!qstate) {
        cout << "successfully created table" << endl;
    } else {
        cout << "error occured" << endl;
    }

}
void function1(string query_string){
    // cout << "entering into the function" << endl;
    string insert_query = query_string;
    const char * queri = insert_query.c_str();
    qstate = mysql_query(conn,queri);
    if (!qstate) {
        res = mysql_store_result(conn);
        while ((row = mysql_fetch_row(res))) {
            cout << " EMP_ID: "<< row[1] <<" | EMP_NAME: " << row[2] << " | DEPT: " << row[3] << " | SALARY: " << row[4] << endl;
        }

        // cout << "hello " << endl;
    } else {
        cout << "error occured" << endl;
    }
}

void function2(){
    string quere = "CREATE TABLE my_emp (s_no INT NOT NULL PRIMARY KEY,emp_id VARCHAR(40) NOT NULL,emp_name VARCHAR(40) NOT NULL,dept VARCHAR(40) NOT NULL,Salary VARCHAR(15) NOT NULL)";
    const char * q = quere.c_str();
    qstate = mysql_query(conn,q);
    if (!qstate) {
        cout << "table created" << endl;
    } else {
        cout << "error occured while creating table" << endl;
    }
}

void function3() {
    string anotherquery = "INSERT INTO my_emp SELECT * FROM emp_info";
    const char * qer = anotherquery.c_str();
    qstate = mysql_query(conn,qer);
    if (!qstate) {
        cout << "table copied" << endl;
    } else {
        cout << "error copying table" << endl;
    }
}

void RegisterEmployee(){
    string email,emp_name,dept,con_no,salary,emp_designation,exp;

    cout << "enter employee name : ";
    getline(cin , emp_name);

    cout << "enter designation : ";
    getline(cin , emp_designation);

    cout << "enter employee email : ";
    cin >> email;

    cout << "enter dept : ";
    cin >> dept;

    cout << "enter contact number of employee : ";
    cin >> con_no;

    cout << "enter experience in years (only enter int value): ";
    cin >> exp;

    cout << "enter salary : ";
    cin >> salary;

    
    cin.ignore();
    string insert_query = "INSERT INTO employee (email, emp_name, dept, con_no) VALUES ('" + email + "', '" + emp_name +"', '"+ dept + "', '" + con_no +"')";
    string insert_query1 = "INSERT INTO department (emp_name,salary,emp_designation,email)";
    string insert_query2 = "INSERT INTO awardee (emp_name,email,dept,exp)";
    //cout << insert_query << endl;
    const char * q = insert_query.c_str();
    //cout << q << endl;
    qstate = mysql_query(conn,q);
    //cout << qstate << endl;
    if (!qstate) {
        cout << "employee successfully added " << endl;
    } else {
        cout << "failed" << endl;
    }

    //cout << insert_query << endl;
}

void displayEmployee(){
    char choose;

    // qstate = mysql_query(conn,"SELECT * FROM employee_info ORDER BY salary DESC");
    qstate = mysql_query(conn,"SELECT * FROM emp_info");
    
    if (!qstate) {
        res = mysql_store_result(conn);
        
        printf("-------------------------------------------------------------\n");
        printf("|                  employee information                      |\n");
        printf("-------------------------------------------------------------\n");
        //printf("| %-5s | %-10s | %-25s  | %-30s  |\n","emp_id","emp_name","dept","salary");
        
        while ((row = mysql_fetch_row(res))){
            
            printf("| %-5s | %-15s | %-5s | %-5s    | %-10s |\n",row[0],row[1],row[2],row[3],row[4]);
            //cout << "emp_id: " << row[0] << " emp_name: " << row[1] << " dept: " << row[2] << " salary: " << row[3] << endl;
        }
        printf("|-------------------------------------------------------------|\n");
        

    } else {
        cout << "error displaying tables " << endl;
    }
}

