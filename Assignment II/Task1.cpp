// name : Kevin Marco         	ID:20200401
// name :Mariam Tarek Galal		ID :20200522
#include<iostream>
#include<iomanip>
using namespace std ;

const long double PI = 3.14159265359;
const double Bernoulli[31]={1,-0.5,0.1666666666666666666667,0,-0.03333333333333333333333,0,0.02380952380952380952381,0,-0.03333333333333333333333,0,0.07575757575757575757576,0,-0.2531135531135531135531,0,1.166666666666666666667,0,-7.092156862745098039216,0,54.97117794486215538847,0,-529.1242424242424242424,0,6192.123188405797101449,0,-86580.25311355311355311,0,1425517.166666666666667,0,-27298231.06781609195402,0,601580873.9006423683843};
int main ()
{
double angle_degree ,angle_radian ;

//prototype functions
double convertAngle(double);  //prototype of converter function
long double factorial(long double);  //prototype of factorial function
long double power(long double ,long double); //prototype of power function
double cosine(double);  //prototype of cosine function
double sine(double);    //prototype of sine function
double tangent(double); //prototype of Tangent function

// angle in degree5
cout<<"enter the angle in degrees : ";
cin>>angle_degree;

//convert angle to radian
angle_radian=convertAngle(angle_degree);

cout<<"cos ("<<angle_degree<<") ="<<cosine(angle_radian)<<endl;
cout<<"sin ("<<angle_degree<<") ="<<sine(angle_radian)<<endl;
cout<<"tan ("<<angle_degree<<") ="<<tangent(angle_radian)<<endl;


return 0;
}

//that's the function which convert angle in degrees to angle in radian
double convertAngle(double degree)
{
	double result;
	result=degree * (PI/180);
	return result;
}
//that's the function which evaluate factorial
long double factorial(long double z)
{
	long double result = 1;
	for(int counter=1;counter<=z;counter++)
		result = result*counter;
	return result;
}
//that's the function which evaluate the power
long double power(long double a, long double b) // a refer to base , b refer to power
{
	long double result=1;
	if (b>=1)
	{
		for(int counter=1;counter<=b;counter++)
			result = result *a;
		return result;
	}
	else
	{
		for(int counter=b;counter<0;counter++)
			result = result * (1/a);
		return result;
	}
}
//that's the function which evaluate the cosine angle
double cosine(double c)            // c refer to angle in radian
{
	double result = 0;
	for(int n=0 ;n<=15;n++)
		result=result + (power(-1,n)) *(power(c,2*n) / factorial(2*n));
	return result;
}
//that's the function which evaluate the sine angle
double sine(double d)              // d refer to angle in radian
{
	double result = 0;
	for(int n=0 ;n<=15;n++)
		result=result + (power(-1,n)) *(power(d,2*n+1) / factorial(2*n+1));
	return result;
}
//that's the function which evaluate tan
double tangent(double e){ 			// e refer to angle in radian
    double a,b,c,d,f;
    double result=0;
    for(int n=0;n<15;n++){
        a=power(-1,n);
        b=power(2,(2*n)+2);
        c=power(2,(2*n)+2)-1;
        d=power(e,2*n+1);
        f=factorial(2*n+2);
        result+=(a*b*c *Bernoulli[2*n+2]*d)/f;
    }
    return result;
}


