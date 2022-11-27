// name : Kevin Marco         	ID:20200401
// name :Mariam Tarek Galal		ID :20200522
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
//prototype of functions
void info ();
double plane(double&);
double taxi(double&);
double vechile (double& ,double&);
double accommodation(double&);
double conference(double&);
double meals_departure(double&);
double meals_back(double&);
double check(double);  // check number is positive or negative

int days;
int hours_depart,minutes_depart,seconds_deaprt; //these variables used to evaluate the time of departure (used in info_transportation function)
int hours_back,minutes_back,seconds_back;  // these variables used to evaluate the time back (used in info_transportation function)

int main()
{
	// variables of refunded things
	double vechile_refunded ,plane_refunded ,taxi_refunded ,refunded_accommodation ,refunded_conference, parking_refunded,refunded_departure ,refunded_back =0;
	// variables of expenses things
	double accommodation_expenses , meals_departure_expenses , meals_back_expenses ,transport_expenses ;
	double confernce_expenses =0;
	// variables of total
	double total_refunded,total_expenses,rejected_refunded;
	string ques1 ,ques2;
	
	info();
	cout<<"Did you travel by plane or taxi or your own vechile ?"<<endl;
	cin>>ques1;
	if(ques1=="plane" || ques1== "Plane")
		transport_expenses =plane(plane_refunded);
	else if(ques1== "taxi"||ques1=="Taxi")
		transport_expenses =taxi(taxi_refunded); 
	else if(ques1== "vechile"||ques1== "vechile")
		transport_expenses =vechile(parking_refunded ,vechile_refunded );
		
	accommodation_expenses=accommodation(refunded_accommodation);
	cout<<"There is any fees to any conference or seminar ?"<<endl;
	cin>>ques2;
	if (ques2== "yes"|| ques2=="Yes")
		confernce_expenses=conference(refunded_conference);
	
	meals_departure_expenses=meals_departure(refunded_departure);
	meals_back_expenses=meals_back(refunded_back);
	// evaluate total of expenses , refunded & rejected refunded
	total_expenses= accommodation_expenses +transport_expenses + vechile_refunded+ meals_departure_expenses + meals_back_expenses +confernce_expenses ;
	cout<<"total expenses is : " <<total_expenses<<endl;
	
	total_refunded= vechile_refunded +plane_refunded +taxi_refunded +refunded_accommodation +refunded_departure+refunded_back + refunded_conference+parking_refunded;
	cout<<"total refunded is : " <<total_refunded<<endl;
	
	rejected_refunded= total_expenses - total_refunded;
	cout<<"rejected refunded is : " <<rejected_refunded<<endl;
	
return 0;
}
// Function that takes days that the employee spent & time arrival & time back
void info()
{
	cout<<"How many days you spent on this trip ? "<<endl;
	cin>>days;
	cout<<"At what time did the employee depart on the first day of the trip ? (please enter the time in a 24-hour format) "<<endl;
	cin>>hours_depart>>minutes_depart>>seconds_deaprt;
	cout<<"At what time did the employee arrive back home on the last day of the trip ? (please enter the time in a 24-hour format)";
	cin>>hours_back>>minutes_back>>seconds_back;
	
	while ((0>hours_depart && hours_depart>=24 )||( 0>minutes_depart && minutes_depart>=60) ||(0>seconds_deaprt && seconds_deaprt>=60)
	||(0>hours_back && hours_back>=24)  || (0>minutes_back && minutes_back>=60)|| (0>seconds_back && seconds_back>=60) || days <0)
		{
			cout<<"please enter a valid numbers for the time or days ."<<endl;
			info();
		}
}
// function that used if user goes in plan
double plane(double &x)
{
	double plane_cost;
	cout<<"What the cost of plane ticket ?"<<endl;
	cin>>plane_cost;
	x=plane_cost;
	return plane_cost; 
}
// function that used if user goes in taxi
double taxi(double &y)
{
	cout<<"How much did you pay for taxi per day? "<<endl;
	double f ,taxi_fees;
	cin>>f;
	taxi_fees= f * days;
	y = 100 * days;
	return taxi_fees;
}
// function that used if user goes in his own vechile
double vechile (double &z ,double&vechile_cost)
{
	cout<<"How many kilometers is this trip ?"<<endl;
	double number_kilometers;
	cin>>number_kilometers;
	vechile_cost = 0.775 * number_kilometers; 
	vechile_cost=check(vechile_cost);
	cout<<"How much did you pay for the parking per day ?"<<endl;
	double parking_cost ,parking_fees;
	cin>>parking_cost;
	parking_fees = parking_cost*days;
	z = 25*days;
	return parking_fees;
}
// function that evaluate the epenses  & refunded of accommodation
double accommodation(double &a)
{
	double accommodation , accommodation_cost;
	cout<<"What is the cost of Accommodation per day ?"<<endl;
	cin>>accommodation;	
	accommodation_cost = accommodation * days;
	a  = 500 * days;
	return accommodation_cost;
}
// function that evaluate the epenses  & refunded of conference
double conference(double&p)
{
	double num_conferences ,conferencne_fees  ;
	double result =0;
	cout<<"What the number of confernces did you attend ?"<<endl;
	cin>>num_conferences;
	for (int count=1 ; count<=num_conferences ; count++) {
		cout<<"Enter the fees of conference "<<cout<<": ";
		cin>>conferencne_fees;
		result = result + conferencne_fees; }
	p = result;
	return result;
}
// function that evaluate the epenses  & refunded of meals departure
double meals_departure(double&b)
{
	double total_eating;
	if (hours_depart < 8) {
		cout<<"enter the cost of breakfast of departure : ";
		double breakfast_arrival;
		cin>>breakfast_arrival;
		breakfast_arrival=check(breakfast_arrival);
		b = 40;
		return breakfast_arrival;  
	}
	else if (hours_depart < 12 && hours_depart > 8) {
		cout<<"enter the cost of lunch of departure : ";
		double lunch_arrival;		
		cin>>lunch_arrival;
		lunch_arrival=check(lunch_arrival);
		b = 60;
		return  lunch_arrival;
	}
	else if ( hours_depart > 12 && hours_depart<18){
		cout<<"enter the cost of the dinner of departure : ";
		double dinner_arrival;
		cin>>dinner_arrival;
		dinner_arrival=check(dinner_arrival);
		b=80; 
		return dinner_arrival;
	}
}
// function that evaluate the epenses  & refunded of meals back
double meals_back(double &c)
{
	if(hours_back < 9){
		cout<<"enter the cost of breakfast of back : ";
		double breakfast_back;
		cin>>breakfast_back;
		breakfast_back =check(breakfast_back);
		c = 40;
		return breakfast_back;
	 }
	else if(hours_depart < 13 && hours_depart > 9){
		cout<<"enter the cost of lunch of back : ";
		double lunch_back;
		cin>>lunch_back;
		lunch_back=check(lunch_back);
		c = 60;
		return lunch_back;
	}
	else if( hours_depart > 13 && hours_depart<19){
		cout<<"enter the cost of the dinner of back : ";
		double dinner_back;
		cin>>dinner_back; 
		dinner_back=check(dinner_back);
		c = 80;
		return dinner_back;
	}
}
// chech number they are valid or not
double check(double m)
{
	double s;
	if (m > 0)
		return m;
	else
	{
		cout<<"please enter number greater than zero :";
		cin>>m;
		return m;
	}
}
