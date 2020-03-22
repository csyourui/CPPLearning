//
//  送货ABCD.cpp
//  Main
//
//  Created by yourui on 2020/3/19.
//  Copyright © 2020 yourui. All rights reserved.
//
#include <iostream>
#include <vector>
using namespace std;
//定义一个坐标类
struct Point{
    int x,y;
    bool isVisited;
    Point(int x, int y, bool f):x(x),y(y),isVisited(f) {};
};
    
int getLength(Point &a, Point &b){
    return abs(a.x-b.x) + abs(a.y-b.y);
}

int minPath = INT_MAX;
void caculate(vector<Point>& points, Point p, int totalLen, int count) {
    if(count == points.size()) {
        minPath = min(minPath, totalLen + p.x + p.y);
    }
    for(int i = 0; i < points.size(); i++) {
        if(!points[i].isVisited) {
            points[i].isVisited = true;
            totalLen += getLength(points[i], p);
            if(totalLen < minPath)
                caculate(points, points[i], totalLen, count + 1);

            totalLen -= getLength(points[i], p);
            points[i].isVisited = false;
        }
    }
}

int main() {
    int numofPoints, x, y;
    char c;
    cin >> numofPoints;
    vector<Point> points;
    for (int i = 0; i < numofPoints; i++) {
        cin >> x >> c >> y;
        Point tPoint(x,y,false);
        points.push_back(tPoint);
    }
    Point StartPoint(0,0,false);

    caculate(points, StartPoint, 0, 0);
    cout<<minPath<<endl;
}
/*
 4
 2,2
 2,8
 4,4
 7,2
 */
