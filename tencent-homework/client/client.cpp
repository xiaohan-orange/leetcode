#include<iostream>
#include<string>

#include<grpc/grpc.h>
#include<grpccpp/channel.h>
#include<grpcpp/client_context.h>
#include<grpcpp/create_channel.h>
#include<grpcpp/security/credentials.h>
#include"UserInformation.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::ClientReader;
using grpc::ClientReaderWriter;
using grpc::Status;
using userinformation::UserLog;
using userinformation::Responce;

using namespace std;

int main(){
    cout << "Please enter "LOG-IN" for log in or enter "REGISTER" for registration";
    cout << endl;
    string str;
    getline(cin,str);
    if(str == "LOG-IN"){
        userinformation::UserInfo user;
        Responce responce;
        string usernameStr = "";
        string passwordStr = "";
        cout << "Please enter username:" << endl;
        getline(cin,usernameStr);
        cout << "Please enter password:" << endl;
        getline(cin,passwardStr);
        user.userName = usernameStr;
        user.password = passwordStr;
        responce = LogIn(user);
        cout << responce.status << endl;
    }
    else if(str == "REGISTER"){
        userinformation::UserInfo user;
        Responce responce;
        string usernameStr = "";
        string passwordStr1 = "";
        string passwordStr2 = "";
        cout << "Welcome to register an account,please enter your username:";
        cout << endl;
        getline(cin,username);
        cout << "Please enter password:" << endl;
        getline(cin,passwordStr1);
        cout << "Please enter password again:" << endl;
        getline(cin,passwordStr2);
        if(passwordStr1 != passwordStr2){
            cout << "The password entered twice is different." << endl;
            return 0;
        }
        user.username = usernameStr;
        user.password = passwordStr1;
        responce = Register(user);
        cout << responce.status << endl;
    }
    else{
        cout << "Invalid input!" << endl;
        return 0;
    }
}
