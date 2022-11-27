// name : Kevin Marco         	ID:20200401
// name :Mariam Tarek Galal		ID :20200522
#include<iostream>
#include<iomanip>
#include<string>
#include<cstdlib>
using namespace std ;
// protoype of functions
void  print_message(string& ,string& ,string&);
void old_system (string&);
void new_system(string ,string ,string);
void comparison_old();
void comparison_new();

int old_belal =0;	//Global
int old_adham =0;	//Global
int old_catherine=0; //Global
int new_belal =0;   //Global
int new_adham =0;	//Global
int new_catherine=0;	//Global

int main()
{
//take number of voters of elections
int voters ;
cout<<" what is the number of voters in election : ";
cin>>voters;
cout<<"There are three candidates Adham, belal, and Catherine"<<endl;

int counter=1;
string president1 , president2 , president3;

while (voters>=counter)
{
	 print_message(president1,president2,president3);
	 old_system(president1);
	 new_system(president1,president2,president3);
	counter = counter+1;
}
cout<<"==========================Old System=========================="<<endl;
comparison_old();
cout<<"==========================New system=========================="<<endl;
comparison_new();

return 0;
}
// determine point of winner in the old system
void old_system (string& first_candidate)
{
	if (first_candidate=="Belal" || first_candidate=="belal" )
    	old_belal=old_belal+1;
 	else if (first_candidate=="Adham" || first_candidate=="adham" )
   	    old_adham=old_adham+1;
	else if (first_candidate=="Catherine" || first_candidate=="catherine" )
   	    old_catherine=old_catherine+1;

}
// take from user everything about elections
void print_message(string& candidate1 ,string& candidate2, string& candidate3)
{
	cout<<"enter the names of the candidates in order of preference  :";
	cin>>candidate1;
	cin>>candidate2;
	cin>>candidate3;
	while (candidate1==candidate2 || candidate2==candidate3 || candidate1==candidate3)
	{
		cout<<"The preferences cannot have any repetitions. please donot write any repetitions names."<<endl;
		cout<<"enter the names of the candidates in order of preference  :";
		cin>>candidate1;
		cin>>candidate2;
		cin>>candidate3;
	}
}
// determine point of electors in the new system
void new_system(string candi1,string candi2,string candi3)
{
	if (candi1=="Belal" ||candi1=="belal" )
    	new_belal=new_belal+3;
 	else if (candi1=="Adham" || candi1=="adham" )
   	    new_adham=new_adham+3;
	else if (candi1=="Catherine" || candi1=="catherine" )
   	    new_catherine=new_catherine+3;
   	    
   	if (candi2=="Belal" ||candi2=="belal" )
    	new_belal=new_belal+2;
 	else if (candi2=="Adham" || candi2=="adham" )
   	    new_adham=new_adham+2;
	else if (candi2=="Catherine" || candi2=="catherine" )
   	    new_catherine=new_catherine+2;
   	    
   	if (candi3=="Belal" ||candi3=="belal" )
    	new_belal=new_belal+1;
 	else if (candi3=="Adham" || candi3=="adham" )
   	    new_adham=new_adham+1;
	else if (candi3=="Catherine" || candi3=="catherine" )
   	    new_catherine=new_catherine+1;
}
// this function used to make a comparison to determine who is the winner in old sytem
void comparison_old()
{
		if (old_belal> old_adham && old_belal > old_catherine)
			cout<<"Belal is the winner & his point is : "<<old_belal<<endl;
		else if (old_adham > old_belal && old_adham > old_catherine)
			cout<<"Adham is the winner & his point is : "<<old_adham<<endl;
		else
			cout<<"Catherine  is the winner & her point is : "<<old_catherine<<endl;
}
// this function used to make a comparison to determine who is the winner in new sytem
void comparison_new()
{
		if (new_belal> old_adham && new_belal > new_catherine)
			cout<<"Belal is the winner & his point is : "<<new_belal<<endl;
		else if (new_adham >new_belal && new_adham > new_catherine)
			cout<<"Adham is the winner & his point is : "<<new_adham<<endl;
		else
			cout<<"Catherine  is the winner & her point is : "<<new_catherine<<endl;
}
