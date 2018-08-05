#include<iostream>
#include<string>
#include<sqlite3.h>

#include<grpc/grpc.h>
#include<grpcpp/server.h>
#include<grpcpp/server_builder.h>
#include<grpcpp/server_context.h>
#include<grpcpp/security/server_credentials.h>
#include"UserInformation.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContect;
using grpc::ServerReader;
using grpc::ServerWrite;
using grpc::Status;
using userinformation::UserInfo;
using userinformation::Responce;

class UserInformationImpl final : public UserLog::service{
public:
    Responce Register(const UserInfo* userinfo) override {}
    Responce LogIn(const UserInfo* userinfo) override {}
private:
}

void RunServer(){

}

int main(int argc,char** argv){
    RunServer();
    return 0;
}
