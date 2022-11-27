// name : Kevin Marco Marcory                 ID : 20200401
// name : Mariam Tarek Galal                  ID : 20200522

#include<iostream>
#include<iomanip>
#include<string>
using namespace std ;

int main()
{
	char choice ;     // select plan a or b
	short hours_start,minutes_start,seconds_start;     // to calculate start time
	short hours_end,minutes_end,seconds_end ;         //to  calculate  end time
	string day_name;                    // take the date from user
	short day_number , month ;         // take the date from user
	double duration_call;
	double cost;

//show plan to user        //Plan A
cout<<"we will show you 2 plans of call & choose between them which plan you prefered ."<<endl;
cout<<" ************************************* Plan [A] ************************************* "<<endl;
cout<<"day" << setw(30) << "call time" << setw(37) << "time of the call" << setw(27) << "rate of the call"<<endl;
cout<<"Sunday to Thursday " << setw(30) <<"Between 7:00am and 5:00pm "<< setw(25) <<"less than 15 minutes "<< setw(25) <<"0.60 LE per minute "<<endl;
cout<<"Sunday to Thursday " << setw(29) <<"Between 7:00am and 5:00pm" << setw(26) <<"more than 15 minutes "<< setw(25) <<"0.80 LE per minute "<<endl;
cout<<"Sunday to Thursday " << setw(32) <<"Before 7:00am , After 5:00pm"<< setw(13) <<" any time "<< setw(35) <<"0.45 LE per minute "<<endl;
cout<<"Friday or Saturday " << setw(13) <<"any time"<< setw(32) <<" any time "<< setw(35) <<"0.25 LE per minute "<<endl;

//Plan B
cout<<" ************************************* Plan [B]************************************* "<<endl;
cout<<"day" << setw(37) << "call time" << setw(39) << "time of the call" << setw(27) << "rate of the call"<<endl;
cout<<"Sunday to Wednesday " << setw(37) <<"Between 7:00am and 5:00pm "<< setw(27) <<"less than 30 minutes "<< setw(25) <<"0.60 LE per minute "<<endl;
cout<<"Sunday to Wednesday " << setw(36) <<"Between 7:00am and 5:00pm" << setw(28) <<"more than 30 minutes "<< setw(25) <<"0.80 LE per minute "<<endl;
cout<<"Sunday to Wednesday " << setw(39) <<"Before 7:00am , After 5:00pm"<< setw(15) <<" any time "<< setw(35) <<"0.45 LE per minute "<<endl;
cout<<"Thursday, Friday or Saturday " << setw(13) <<"any time"<< setw(32) <<" any time "<< setw(35) <<"0.25 LE per minute "<<endl;

// prompts user to choice plan a or b
cout<<"Do you want plan a or b ? ";
cin>>choice;

// prompts user to input start & end time
cout<<" Please enter start time of the call & end time in hours minutes seconds in a 24-hour format ."<<endl;
cout<<"For example, entering 14:23:11 means 2 pm at minute 23, at 11 seconds ."<<endl;
cout<<"Enter the start time : ";
cin>>hours_start>>minutes_start>>seconds_start;
cout<<"Enter the end time : ";
cin>>hours_end>>minutes_end>>seconds_end;

//prompts user to enter date of call
cout<<"Date of the call entered in Name-of-the-day day-of-the-month month."<<endl;
cout<<"For example,entering Thurs 22 4 means Thursday 22nd April. Days of the week should be {Sat, Sun, Mon, Tues, Wed, Thurs, Fri}"<<endl;
cout<<"Enter date of call : ";
cin>>day_name>>day_number>>month;

// evaluate duration call
if (seconds_end >0 && minutes_end>=minutes_start && hours_end >hours_start)
	duration_call=(hours_end-hours_start)*60 +(minutes_end -minutes_start ) + 1;
else if(seconds_end >0 && minutes_start>minutes_end && hours_end >hours_start)
	duration_call=(hours_end-hours_start)*60 + ((minutes_end-minutes_start )+ 60) + 1;
else if(seconds_end == 0 && minutes_end>=minutes_start && hours_end >hours_start)
	duration_call=(hours_end-hours_start)*60 +(minutes_end-minutes_start) ;
else if(seconds_end ==0 && minutes_start>minutes_end && hours_end >hours_start)
	duration_call=(hours_end-hours_start)*60 +((minutes_end-minutes_start)+ 60) ;

// this 4 conditions if the call start before 12 pm & end after 12pm
else if(11<hours_start<=23 && 0<hours_end<=10 && seconds_end>0 && minutes_start>minutes_end)
	duration_call=((hours_end-hours_start) +24)*60 +((minutes_end-minutes_start)+ 60)+1 ;
else if(11<hours_start<=23 && 0<hours_end<=10 && seconds_end==0 && minutes_end>=minutes_start )
	duration_call=((hours_end-hours_start)+24)*60 +(minutes_end-minutes_start) ;
else if(11<hours_start<=23 && 0<hours_end<=10 && seconds_end>0 && minutes_end>=minutes_start)
	duration_call=((hours_end-hours_start) +24)*60 +(minutes_end-minutes_start)+1 ;
else if(11<hours_start<=23 && 0<hours_end<=10 && seconds_end==0 && minutes_end>minutes_start)
	duration_call=((hours_end-hours_start) +24)*60 +((minutes_end-minutes_start)+ 60) ;

// evaluate cost
if( (hours_start,minutes_start,seconds_start >=0)  &&hours_start<=23 && minutes_start<=59 &&seconds_start<=59)
	{
		if( (hours_end,minutes_end,seconds_end >=0) &&hours_end<=23 && minutes_end<=59 &&seconds_end<=59)
			{
				if (choice=='a' || choice=='A')
					{
					// less than 15 minutes
					if((7<=hours_start<17 && duration_call<15 )&& (day_name=="Sun" || day_name=="Mon" || day_name=="Tues" || day_name=="Wed" || day_name=="Thurs")&& hours_end >hours_start)
						cost=duration_call * 0.60;
					// More than 15 minutes
					else if((7<=hours_start<17 && duration_call>15) && (day_name=="Sun" || day_name=="Mon" || day_name=="Tues" || day_name=="Wed" || day_name=="Thurs")&& hours_end >hours_start)
						cost=duration_call * 0.80;
					// before 7am and after 5pm
					else if((0<hours_start<7 || 17<hours_start<24 ) && (day_name=="Sun" || day_name=="Mon" || day_name=="Tues" || day_name=="Wed" || day_name=="Thurs") && hours_end >hours_start)
						cost=duration_call * 0.45;
					// if the day is friday or saturday
					else if(day_name=="Fri" || day_name=="Sat" && hours_end >hours_start)
						cost=duration_call * 0.25;
					// this condition if  if the call start before 12 pm & end after 12pm from  Sunday to Thursday
					else if((17<hours_start<=23 && 0<hours_end<7)&& (day_name=="Sun" || day_name=="Mon" || day_name=="Tues" || day_name=="Wed" || day_name=="Thurs"))
						cost = duration_call * 0.45;
					// this condition if  if the call start before 12 pm & end after 12pm from  friday to saturday
					else if((11<=hours_start<=23 && 0<hours_end<11)&& (day_name=="Fri" || day_name=="Sat"))
						cost = duration_call * 0.25;
					cout << "call rate = " << cost <<" LE ";
					}
				else if (choice=='b'||choice=='B')
						{
				 		// More less 30 minutes
						if((7<=hours_start<17 && duration_call<30) && (day_name=="Sun" || day_name=="Mon" || day_name=="Tues" || day_name=="Wed" )&& hours_end >hours_start)
							cost=duration_call * 0.60;
						// More than 30 minutes
						else if((7<=hours_start<17 && duration_call>30 )&& (day_name=="Sun" || day_name=="Mon" || day_name=="Tues" || day_name=="Wed" )&& hours_end >hours_start)
							cost=duration_call * 0.80;
						// before 7am and after 5pm
						else if((0<hours_start<7 || 17<hours_start<24) && (day_name=="Sun" || day_name=="Mon" || day_name=="Tues" || day_name=="Wed" )&& hours_end >hours_start)
							cost=duration_call * 0.45;
						// if the day is Thursday , friday or saturday
						else if(day_name=="Thurs"  ||day_name=="Fri" || day_name=="Sat" && hours_end<24)
							cost=duration_call * 0.25;
						// this condition if  if the call start before 12 pm & end after 12pm from  Sunday to Wednesday
						else if((17<hours_start<=23 && 0<hours_end<7)&& (day_name=="Sun" || day_name=="Mon" || day_name=="Tues" || day_name=="Wed" ))
							cost=duration_call * 0.45;
						// this condition if  if the call start before 12 pm & end after 12pm from  Thursday to saturday
						else if ((11<=hours_start<=23 && 0<hours_end<11)&& (day_name=="Thurs" || day_name=="Fri" || day_name=="Sat" ))
							cost=duration_call *  0.25;
						cout << "call rate = " << cost <<" LE ";
						}
				else
					cout<<"enter a valid number ."<<endl;
			}
		else
			cout<<"enter a valid number ."<<endl;
	}
else
	cout<<"enter a valid number ."<<endl;
return 0;
}



































