#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct Point3D {
    int x;
    int y;
    int z;
};

int manhattanDist(Point3D p1, Point3D p2);

int main(){
    int test_cases, num_points;

    cout << "Enter the number of test_cases\n";
    cin >> test_cases;

    //iterate through test cases
    for(int i = 0; i < test_cases; i++){
        cin >> num_points;
        vector<Point3D> points = {};

        //retrieve points and store into vector
        for(int i = 0; i < num_points; i++){
            Point3D p;
            //add each point into list
            cin >> p.x >> p.y >> p.z;
            points.push_back(p);
        }

        //compute manhattan distance
        for(int i = 0; i < num_points - 1; i++){
            Point3D p1 = points.at(i);
            Point3D p2 = points.at(i+1);
            cout << manhattanDist(p1, p2) << "\n";
        }
    }
    return 0;
}

int manhattanDist(Point3D p1, Point3D p2){
    int manhattan_distance = abs(p1.x - p2.x) + abs(p1.y - p2.y) + abs(p1.z - p2.z);
    return manhattan_distance;
}