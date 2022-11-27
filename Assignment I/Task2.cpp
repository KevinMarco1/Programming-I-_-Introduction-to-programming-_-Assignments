// name : Kevin Marco Marcory                 ID : 20200401
// name : Mariam Tarek Galal                  ID : 20200522

#include<iostream>
#include<cmath>
using namespace std;

int main()
{

double x_center ;    // x-coordinate of the center of the circle
double y_center;    // y-coordinate of the center  of the circle
double x_point;    // x-coordinate point of the circle
double y_point;    // y-coordinate point of the circle
double radius , distance;

cout<<"Enter the coordinates of the center of the circle :";
cin>>x_center>>y_center;
cout<< "Enter the radius of the circle : " ;
cin>> radius;
cout<<"Enter coordinate of the point : ";
cin>>x_point>>y_point;

distance = sqrt(pow((x_center-x_point),2) +pow((y_center-y_point),2));

if (radius == distance ||distance == radius-0.01 || radius == distance + 0.01 )
cout<< "on the circle";
else if (radius > distance)
cout<<"inside the circle";
else
cout<<"outside the circle";

return 0;
}

