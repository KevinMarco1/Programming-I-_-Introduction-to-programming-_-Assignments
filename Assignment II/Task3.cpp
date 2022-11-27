// name : Kevin Marco         	ID:20200401
// name :Mariam Tarek Galal		ID :20200522
#include<iostream>
#include<iomanip>
using namespace std;
//prototype of the function
bool validation(int);
int count_digit(long long  );
int secondary(int[],int );
int primary(int[] ,int);
int sum_all(int , int );

int main()
{
int size;
long long card_number;
cout<<"Enter the serial number of credit card : ";
cin>>card_number;
size=count_digit(card_number);

int array_creditCard[size];
if(validation(size))
{
	int carry;
	for(int counter=size-1;counter>=0;counter--)
		{
			carry= card_number % 10;
			array_creditCard[counter]= carry;
			card_number =card_number / 10;
		}
	int f ;
	f = secondary(array_creditCard,size);
	cout<<f<<endl;
	int g ;
	g =primary(array_creditCard,size);
	cout<<g<<endl;
	sum_all(f,g);
}
else
	cout<<"enter a valid number betweem 14 & 16 .";
return 0;
}

//that's the function which evaluate length of credit card
int count_digit(long long number)
{
	int digit=0;
	while (number != 0)
		{
			number = number / 10;
			digit = digit + 1 ;
		}
	return digit;
}
//that's the function which determine the validation of cridit card
bool validation(int test_digits)
{
	bool status;
	if (14 <=  test_digits && test_digits <= 16)
		status = true;
	else
		status = false;
	return status;
}

//that's the function which multiple array*2 and sum digit
int secondary(int array_list[],int subcript)
{
	int x;
	int sum=0;
	for(int count = subcript-1 ; count>=0 ; count-2)
	{
			x=array_list[count]*2;
			if(x>9)
			{
				while (x!=0)
				{
				x = x % 10;
				sum = sum + x;
				x = x / 10;
				}
			}
			else
				sum = sum + x ;
	}
	return sum;
}
// this function used to get the numbers which doesn't muliple by 2 & sum these numbers
int primary(int z[] , int b)
{
	int sum=0;
	for(int count = b-2 ; count>=0 ; count-2)
		sum = sum + z[count];
	return sum;
}

int sum_all(int sum1 , int sum2)
{
	int total = sum1 + sum2;
	if (total % 10 == 0 )
		cout<<"the credit card is valid";
	else
		cout<<"the credit card is not valid";
}




