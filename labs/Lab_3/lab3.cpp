#include <iostream>
#include <cmath>


using namespace std;

//unctions for Exercise 1
double Exercise1Pt1(double a[], double b[], int n, int m) {
    double y = 0;
    for (int i = 0; i < n; i++) {
        double product = 0;
        for (int j = 0; j < m; j++) {
            product += a[i] * b[j];
        }
        y += product;
    }
    return y;
}

void Exercise1Pt2(double a[], double b[], int n, int m, double* result) {
    for (int i = 0; i < n; i++) {
        double product = 0;
        for (int j = 0; j < m; j++) {
            product += a[i] * b[j];
        }
        *result += product;
    }
}

void Exercise1Pt3(double a[], double b[], int n, int m, double& result) {
    for (int i = 0; i < n; i++) {
        double product = 0;
        for (int j = 0; j < m; j++) {
            product += a[i] * b[j];
        }
        result += product;
    }
}

//Functions for Exercise 2

double GetMax1(double* a, int n) {
    // a WILL BE an array?

    double max = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }

    return max;

}

void GetMax2(double* a, int n, double* vmax) {
    //your code here

    *vmax = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] > *vmax) {
            *vmax = a[i];
        }
    }

}

void GetMax3(double* a, int n, double& vmax) {
    //your code here

    vmax = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] > vmax) {
            vmax = a[i];
        }
    }

}

//Functions for Exercise 3

struct Point3D {
    //add your struct members

    double x;
    double y;
    double z;

    Point3D(double i, double j, double k) {
        x = i;
        y = j;
        z = k;
    }

};

double DistanceBetweenTwoPoints(Point3D a, Point3D b) {
    return sqrt(pow((b.x - a.x),2) + pow((b.y - a.y),2) + pow((b.z - a.z),2));
}

double DistanceBetweenPointandOrigin(Point3D a) {
    return sqrt(pow((a.x),2) + pow((a.y),2) + pow((a.z),2));
}

Point3D AddTwoPoints(Point3D a, Point3D b) {
    //your code here

    Point3D temp((a.x + b.x), (a.y + b.y), (a.z + b.z));

    return temp;

}

Point3D SubtractTwoPoints(Point3D a, Point3D b) {
    //your code here
    Point3D temp((a.x - b.x), (a.y - b.y), (a.z - b.z));

    return temp;
}

//Functions for Exercise 4

class ThreeDPoint {
    public:
        ThreeDPoint(); // Default constructor
        ThreeDPoint(int,int,int); // Constructor with 3 values
        ThreeDPoint(const ThreeDPoint&); // Copy constructor 
        int GetX(); // accessor functions
        int GetY();
        int GetZ();
        void SetX(int); // modifier functions
        void SetY(int);
        void SetZ(int);
        double DistanceBetweenTwoPoints(ThreeDPoint*);
        double DistanceBetweenPointandOrigin();
        ThreeDPoint operator+ (const ThreeDPoint&); // + operator overloading
        ThreeDPoint operator- (const ThreeDPoint&); // - operator overloading
    private:
        int x;
        int y;
        int z;
    protected:
};

ThreeDPoint::ThreeDPoint() {
    x = 0;
    y = 0;
    z = 0;
 }

ThreeDPoint::ThreeDPoint(int tempX, int tempY, int tempZ) {
    x = tempX;
    y = tempY;
    z = tempZ;
}

ThreeDPoint::ThreeDPoint(const ThreeDPoint& input3DPoint) {
    x = input3DPoint.x;
    y = input3DPoint.y;
    z = input3DPoint.z;
}

int ThreeDPoint::GetX() {
    return x;
}

int ThreeDPoint::GetY() {
    return y;
}

int ThreeDPoint::GetZ() {
    return z;
}

void ThreeDPoint::SetX(int tempX) {
    x = tempX;
}

void ThreeDPoint::SetY(int tempY) {
    y = tempY;
}

void ThreeDPoint::SetZ(int tempZ) {
    z = tempZ;
}

double ThreeDPoint::DistanceBetweenTwoPoints(ThreeDPoint* b) {

    ThreeDPoint temp = *b;

    return sqrt(pow((temp.GetX() - x),2) + pow((temp.GetY() - y),2) + pow((temp.GetZ() - z),2));
}

double ThreeDPoint::DistanceBetweenPointandOrigin() {
    return sqrt(pow((x),2) + pow((y),2) + pow((z),2));
};

ThreeDPoint ThreeDPoint::operator+ (const ThreeDPoint& b) {
    ThreeDPoint temp((x + b.x), (y + b.y), (z + b.z));
    return temp;
};

ThreeDPoint ThreeDPoint::operator- (const ThreeDPoint& b) {
    ThreeDPoint temp((x - b.x), (y - b.y), (z - b.z));
    return temp;
};




int main()
{
    // add your function calls 

    double a[] = {1.0, 2.0, 3.0};
    double b[] = {1.0, 2.0, 3.0};
    double result = 0;
    double* res_point = &result;
  
    cout << Exercise1Pt1(a, b, 3, 3) << endl;

    Exercise1Pt2(a, b, 3, 3, res_point);
    cout << result << endl;

    result = 0;
    Exercise1Pt3(a, b, 3, 3, result);
    cout << result << endl;

    cout << GetMax1(a, 3) << endl;

    double vmax = 0;
    double* vmax_ptr = &vmax;
    GetMax2(a, 3, vmax_ptr);
    cout << vmax << endl;

    vmax = 0;
    GetMax3(a, 3, vmax);
    cout << vmax << endl;

    // 3D POINTS

    Point3D wow(1.0, 2.0, 3.0);
    Point3D wow2(4.0, 5.0, 6.0);

    cout << DistanceBetweenTwoPoints(wow, wow2) << endl;
    cout << DistanceBetweenPointandOrigin(wow) << endl;

    Point3D yee = AddTwoPoints(wow, wow2);
    cout << yee.x << yee.y << yee.z << endl;

    yee = SubtractTwoPoints(wow, wow2);
    cout << yee.x << yee.y << yee.z << endl;

    ThreeDPoint nice(1, 2, 3);
    ThreeDPoint NICE(4, 5, 6);
    ThreeDPoint* NICE_ptr = &NICE;

    cout << nice.DistanceBetweenTwoPoints(NICE_ptr) << endl;
    cout << nice.DistanceBetweenPointandOrigin() << endl;

    cout << (nice + NICE).GetX() << (nice + NICE).GetY() << (nice + NICE).GetZ() << endl;
    cout << (nice - NICE).GetX() << (nice - NICE).GetY() << (nice - NICE).GetZ() << endl;

    cout << nice.GetX() << endl;

    nice.SetX(999999);
    cout << nice.GetX();

    return 0;
}
