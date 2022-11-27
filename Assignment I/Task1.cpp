// name : Kevin Marco Marcory                 ID : 20200401
// name : Mariam Tarek Galal                  ID : 20200522

#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
double temperature , windSpeed , T_Windchill ;

cout<< "please enter the temperature in degrees celsius : " ;
cin >> temperature ;
cout<< "please enter the wind speed in kilometers per hour : ";
cin >> windSpeed ;

if ( -50<temperature<5)
    {
        if(windSpeed>=4)
            T_Windchill = 13.12 +(0.6215*temperature)- (11.37*pow(windSpeed,0.16)) + (0.3965*temperature*pow(windSpeed,0.16));
        else
            cout<<"please enter value of wind speed greater than or equal to 4 . /n";
    }
    else
    {
	    cout<<"please enter value of temperature between -50 and 5 . /n" ;
    }
    cout<< "the wind chill temperature is : "<< setprecision(2)<<fixed<<T_Windchill ;
    return 0;
}

