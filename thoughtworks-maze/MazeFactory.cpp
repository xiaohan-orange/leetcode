#include<sstream>
#include"MazeFactory.h"

namespace maze{

MazeFactory::MazeFactory(const string& _command):
    command(_command),
    roadRow(0),
    roadCol(0),
    renderRow(0),
    renderCol(0){}

MazeFactory::~MazeFactory(){
    for(uint32_t i = 0;i < renderRow;i++){
        delete renderGrid[i];
    }
    renderGrid.clear();
}

void MazeFactory::Reset(const string& _command){
    command = _command;
    for(uint32_t i = 0;i < renderRow;i++){
        delete renderGrid[i];
    }
    renderGrid.clear();
    roadRow = 0;
    roadCol = 0;
    renderRow = 0;
    renderCol = 0;
}

Status MazeFactory::Create(){
    vector<string> lines;
    Reader::SplitString(command,'\n',lines);
    if(lines.size() != 2){
        return kIncorrectCommandFormat;
    }
    Status status = pasreGridSize(lines[0]);
    if(status != kOk){
        return status;
    }
    initRenderGrid();
    status = pasreConnectMap(lines[1]);
    if(status != kOk){
        return status;
    }
    return kOk;
}

string MazeFactory::Render(){
    string mazeText;
    for(uint32_t i = 0;i < renderRow;i++){
        for(uint32_t j = 0;j < renderCol;j++){
            if((*renderGrid[i])[j] == 'R'){
                mazeText += ROAD;
                if(j != renderCol - 1){
                    mazeText += " ";
                }
            }
            else{
                mazeText += WALL;
                if(j != renderCol - 1){
                    mazeText += " ";
                }
            }
        }
        if(i != renderRow - 1){
            mazeText += '\n';
        }
    }
    return mazeText;
}

void MazeFactory::initRenderGrid(){
    renderGrid.reserve(renderRow);
    for(uint32_t i = 0;i < renderRow;i++){
        vector<char>* line = new vector<char>(renderCol,'W');
        renderGrid.push_back(line);
    }

    for(uint32_t i = 0;i < roadRow;i++){
        for(uint32_t j = 0;j < roadCol;j++){
            (*renderGrid[2*i+1])[2*j+1] = 'R';
        }
    }
}

Status MazeFactory::pasreGridSize(const string& str){
    vector<string> tmpStrs;
    Reader::SplitString(str,' ',tmpStrs);
    if(tmpStrs.size() != 2){
        return kIncorrectCommandFormat;
    }
    if(Reader::StringToUint32(tmpStrs[0],&roadRow) != kOk){
        return kInvalidNumberFormat;
    }
    if(Reader::StringToUint32(tmpStrs[1],&roadCol) != kOk){
        return kInvalidNumberFormat;
    }
    renderRow = roadRow * 2 + 1;
    renderCol = roadCol * 2 + 1;
    return kOk;
}

Status MazeFactory::pasreConnectMap(const string& str){
    vector<string> strsArr;
    Reader::SplitString(str,';',strsArr);
    Status status;
    for(uint32_t i = 0;i < strsArr.size();i++){
        vector<string> twoPoints;
        Reader::SplitString(strsArr[i],' ',twoPoints);
        if(twoPoints.size() != 2){
            return kIncorrectCommandFormat;
        }
        Point p1,p2;
        status = stringToPoint(twoPoints[0],&p1);
        if(status != kOk){
            return status;
        }
        status = stringToPoint(twoPoints[1],&p2);
        if(status != kOk){
            return status;
        }
        status = verifyConnect(p1,p2);
        if(status != kOk){
            return status;
        }
        renderConnect(p1,p2);
    }
    return kOk;
}

void MazeFactory::renderConnect(const Point& p1,const Point& p2){
    Point newPoint;
    newPoint.x = p1.x == p2.x ? (2*p1.x+1) : max(2*p1.x,2*p2.x);
    newPoint.y = p1.y == p2.y ? (2*p1.y+1) : max(2*p1.y,2*p2.y);
    (*renderGrid[newPoint.x])[newPoint.y] = 'R';
}

Status MazeFactory::stringToPoint(const string& str,Point* point){
    vector<string> tmpStr;
    Reader::SplitString(str,',',tmpStr);
    if(tmpStr.size() != 2){
        return kIncorrectCommandFormat;
    }
    Status status = Reader::StringToUint32(tmpStr[0],&point->x);
    if(status != kOk){
        return status;
    }
    status = Reader::StringToUint32(tmpStr[1],&point->y);
    if(status != kOk){
        return status;
    }
    return kOk;
}

Status MazeFactory::verifyConnect(const maze::Point& p1,
        const maze::Point& p2){
    if(p1.x >= roadRow || p1.y >= roadCol 
            || p2.x >= roadRow || p2.y >= roadCol){
        return kNumberOutOfRange;
    }
    if((max(p1.x,p2.x) - min(p1.x,p2.x)) + (max(p1.y,p2.y) - min(p1.y,p2.y)) != 1){
            return kMazeFormatError;
        }
    return kOk;
}

void Reader::SplitString(const string& str,char delim,vector<string>& elems){
    std::stringstream ss(str);
    string item;
    while(std::getline(ss,item,delim)){
        elems.push_back(item);
    }
}

Status Reader::StringToUint32(const string &str,uint32_t* num){
    int tmp = atoi(str.c_str());
    if(errno != 0 || tmp < 0){
        return kInvalidNumberFormat;
    }
    *num = static_cast<uint32_t>(tmp);
    return kOk;
}
}//namespace maze
