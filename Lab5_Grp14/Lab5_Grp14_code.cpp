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
    vector<vector<Point3D>> point_sets = {};

    cout << "Enter the number of test_cases\n";
    cin >> test_cases;

    //iterate through test cases
    for(int i = 0; i < test_cases; i++){
        cin >> num_points;
        vector<Point3D> points = {};

        //retrieve points and store into vector
        for(int j = 0; j < num_points; j++){
            Point3D p;
            //add each point into list
            cin >> p.x >> p.y >> p.z;
            points.push_back(p);
        }
        point_sets.push_back(points);
    }

    //compute manhattan distance
    for(int i = 0; i < test_cases; i++){
        for(int j = 0; j < size(point_sets.at(i)) - 1; j++){
            Point3D p1 = point_sets.at(i).at(j);
            Point3D p2 = point_sets.at(i).at(j+1);
            cout << manhattanDist(p1, p2) << "\n";
        }
        cout << "\n";
    }

    return 0;
}

int manhattanDist(Point3D p1, Point3D p2){
    int manhattan_distance = abs(p1.x - p2.x) + abs(p1.y - p2.y) + abs(p1.z - p2.z);
    return manhattan_distance;
}