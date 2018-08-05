#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<sqlite3.h>

using namespace std;

static int callback(void* NotUsed,int argc,char** argv,char** azColName){
    int i;
    for(int i = 0;i < argc;i++){
        printf("%s = %s\n",azColName[i],argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(int argc,char* argv[]){
    sqlite3 *db;
    char* zErrMsg = 0;
    int rc;
    char* sql;

    rc = sqlite3_open("test.db",&db);
    if(rc){
        cout << "Can't open database:" << sqlite3_errmsg(db) << endl;
        return 0;
    }
    else{
        cout << "Opened database successfully" << endl;
    }

    sql = "CREATE TABLE USER("\
           "USERNAME CHAR(20) PRIMARY KEY NOT NULL,"\
           "PASSWORD CHAR(25));";
    
    rc = sqlite3_exec(db,sql,callback,0,&zErrMsg);
    if(rc != SQLITE_OK){
        cout << "SQL error:" << zErrMsg <<endl;
        return 0;
    }
    else{
        cout << "Table create successfully" << endl;
    }
    sqlite3_close(db);
    return 0;
}
