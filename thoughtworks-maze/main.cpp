#include<iostream>
#include"MazeFactory.h"

using namespace std;
using namespace maze;

int main(int argc,const char* argv[]){
    string testCommand = "3 3\n0,1 0,2;0,0 1,0;0,1 1,1;0,2 1,2;1,0 1,1;1,1 1,2;1,1 2,1;1,2 2,2;2,0 2,1";
    //cout << "TEXT CASE: " << endl <<testCommand << endl;
    MazeFactory mazeFactory(testCommand);
    Status status = mazeFactory.Create();
    if(status != kOk){
        cout << maze::convertStatusToString(status) << endl;
    }
    cout << mazeFactory.Render() << endl;
    return 0;
}
