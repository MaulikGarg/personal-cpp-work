#include<iostream>

#include <vector>
#include <fstream>

using namespace std;

struct Point
{
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int xx, int yy) : x(xx), y(yy) {}
};

istream &operator>>(istream &is, Point &point)
{
    int x;
    int y;
    char c1, c2, c3;
    is >> c1 >> x >> c2 >> y >> c3;
    // if input extraction fails
    if (!is)
        return is;
    // if "wrong" input is entered where (,) are expected
    if (c1 != '(' || c2 != ',' || c3 != ')')
    {
        is.clear(ios_base::failbit);
        return is;
    }
    // ok it is successful if we reach here
    point = Point(x, y);
    return is;
}

ostream &operator<<(ostream &os, Point point)
{
    os << '(' << point.x << ',' << point.y << ')';
    return os;
}

void writeToFile(vector<Point> &original_points)
{
    ofstream inFile{"out.txt"};
    if (!inFile)
        exit(1); // if file fails to open

    // entering the points into the file;
    for (auto p : original_points)
    {
        inFile << '(' << p.x << ',' << p.y << ")\n";
    }
}

void readFromFile(vector<Point> &processed_points)
{
    // open an input file
    ifstream outFile{"out.txt"};
    if (!outFile)
        exit(1);
    // entering the points into the file, from the previous file;
    {
        Point p{};
        while (outFile >> p)
        {
            processed_points.push_back(p);
        }
    }
}


int main()
{
  // int birth_year {2005};
  // cout << "Dec\t" << "Hex\t" << "Oct\t" << '\n';
  // cout << birth_year << '\t'<< hex << birth_year << '\t' <<  oct << birth_year << '\n';


  // int a,b,c,d;
  // cin >> a >>oct >> b >> hex >> c >> d;
  // cout << a << '\t'<< b << '\t'<< c << '\t'<< d << '\n';

  // double num{1234567.89};
  // cout << num << '\t' << fixed << num << scientific << '\t' << num << '\n'; 

  vector<Point> original_points;
    cout << "Enter 7 pairs of co ordinates (x,y): ";
    for (int i{0}; i < 7; i++)
    {
        Point p;
        cin >> p;
        original_points.push_back(p);
    }

    //write to out.txt
    writeToFile(original_points);
    vector<Point> processed_points;
    //fill from out.txt
    readFromFile(processed_points);

    for(int i = 0; i < 7; i++){
        if((original_points[i].x!=processed_points[i].x) || (original_points[i].y!=processed_points[i].y)){
            cerr << "Something's wrong!";
            exit(1);
        }
    }

    cout << "Original points: ";
    for(auto& i: original_points){
        cout << i;
    }
    cout << "\nProcessed points: ";
    for(auto& i: processed_points){
        cout << i;
    }

  return 0;
}
