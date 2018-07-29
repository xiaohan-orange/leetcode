#ifndef MazeFactory_h
#define MazeFactory_h

#include<string>
#include<vector>
#include<stdint.h>
#include<stdlib.h>
#include<errno.h>

namespace maze{
using namespace std;

enum Status{
    kOk,
    kInvalidNumberFormat,
    kNumberOutOfRange,
    kIncorrectCommandFormat,
    kMazeFormatError
};

struct Point{
    uint32_t x;
    uint32_t y;
};

static const string WALL = "[W]";
static const string ROAD = "[R]";
static string converstStatusToString(const Status& status);

class MazeFactory{
public:
    MazeFactory(const string& _command);
    ~MazeFactory();

    void Reset(const string& _command);
    Status Create();
    string Render();

private:
    void initRenderGrid();
    Status pasreGridSize(const string& str);
    Status pasreConnectMap(const string& str);
    Status verifyConnect(const Point& p1,const Point& p2);
    Status stringToPoint(const string& str,Point* point);
    void renderConnect(const Point& p1,const Point& p2);
private:
    string command;
    uint32_t roadRow;
    uint32_t roadCol;
    uint32_t renderRow;
    uint32_t renderCol;
    vector<vector<char>*> renderGrid;
};

class Reader{
public:
    static void SplitString(const string& str,char delim,
                        vector<string>& elems);
    static Status StringToUint32(const string& str,uint32_t* num);
};

static string convertStatusToString(const Status& status){
    string errorMsg;
    switch(status){
        case kOk:
            errorMsg = "ok.";
            break;
        case kNumberOutOfRange:
            errorMsg = "Number out of range.";
            break;
        case kInvalidNumberFormat:
            errorMsg = "Invalid number format.";
            break;
        case kIncorrectCommandFormat:
            errorMsg = "Incorrect command format.";
            break;
        case kMazeFormatError:
            errorMsg = "Maze format error.";
            break;
        default:
            errorMsg = "Invalid status.";
            break;
    }
    return errorMsg;
}

}//namespace maze
#endif
