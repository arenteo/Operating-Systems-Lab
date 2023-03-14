#include <iostream>
#include <cmath>
using namespace std;

struct Point3D {
    int x;
    int y;
    int z;
};

int manhattanDist(int x, int y, int z);

int main(){
    int test_cases, num_points;

    cout << "Enter the number of test_cases\n";
    cin >> test_cases;

    for(int i = 0; i < test_cases; i++){
        cin >> num_points;
        for(int i = 0; i < num_points; i++){
            Point3D p;
            //add each point into list
            cin >> p.x >> p.y >> p.z;
        }
    }
    return 0;
}

int manhattanDist(Point3D  p1, Point3D p2){
    int manhattan_distance = abs(p1.x - p2.x) + abs(p1.y - p2.y) + abs(p1.z - p2.z);
    return manhattan_distance;
}