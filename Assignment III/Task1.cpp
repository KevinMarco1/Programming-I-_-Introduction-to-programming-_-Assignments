//Name:Kevin Marco Marcory        ID:20200401
//Name: Mariam Tarek Galal        ID:20200522
#include <iostream>
using namespace std;

//Prototype of functions
void Print(string[], string[],int );  
bool IterationChecker(int , int );
void IterationPrepare(string [], bool, int, int);
int CloseMicro(string [],int ,int ,int );


int main(){

    int size, iterations;
    cout<<"please enter the size : ";
    cin >> size;
    while(size < 1){
        cout << "Please enter a valid Size : " ;
        cin >> size;
    }
    cout<<"Please enter number of iterations : ";
	cin>>iterations;
	
    bool checker;
    string surface[size];
    string saver[size];
    cout<<"Please enter the Surface "<<endl;

	// take string from user
    for(int i = 0; i < size; i++){
        cin >> surface[i];
        saver[i] = surface[i];
    }
    cout << endl << endl;
	// print  string  before iterations
    for(int i = 0; i < size; i++){
        cout << surface[i] << endl;
    }
	cout << endl << endl;
	
    for(int q = 0; q < iterations; q++){
        for(int j = 0; j < size; j++){
            for(int k = 1; k < size + 1; k++){
                if(surface[j][k] == 'M'||surface[j][k] == 'm'){
                    checker = 1;
                }
                else{
                    checker = 0;
                }
                IterationPrepare(saver,IterationChecker(checker,CloseMicro(surface,j,k,size)), j ,k);
            }
        }
        Print(saver,surface,size);
    }
    
    return 0;
}

// A function which will take the current surface states and print them 
void Print(string saver[], string arr[],int size){
    for(int i = 0; i < size; i++){
        cout << saver[i] << endl;
        arr[i] = saver[i];
    }
    cout << endl << endl;
}

//  function which should prepare the next state of the surface .
void IterationPrepare(string arr[], bool check, int index1, int index2){

    if(check){
        arr[index1][index2] = 'M';
    }else{
        arr[index1][index2] = '-';
    }
}

// function which should return whether in the next iteration, this block will be empty or have a micro-organism.
bool IterationChecker(int checker, int nums){
    if(checker == 0){
        if(nums == 3){
            return true;
        }
    }else if (checker == 1){
        if(nums >= 4 || nums <= 1){
            return false;
        }else if (nums == 2 || nums == 3){
            return true;
        }
    }
}

// function which should return the number of close micro-organisms in a given block.
int CloseMicro(string arr[],int index1,int index2,int size){
    int c = 0;
    if(index1 == 0){
        for(int i = index1; i <= index1 + 1; i++){
            for(int j = index2-1; j <= index2 + 1; j++){    
                if(arr[i][j] == 'M' ||arr[i][j] == 'm' ){
                    c++;
                }
            }
        }
    }
    else if(index1==size-1){
        for(int i=index1-1;i<=index1;i++){
            for(int j = index2-1; j <= index2 + 1; j++){
                if(arr[i][j] == 'M'|| arr[i][j] =='m'){	
                    c++;
                }
            }
        }
    }
    else{
        for(int i = index1 - 1; i <= index1 + 1; i++){
            for(int j = index2-1; j <= index2 + 1; j++){    
                if(arr[i][j] == 'M'||arr[i][j] =='m'){
                    c++;
                }
            }
        }
    }
    if(arr[index1][index2] == 'M'|| arr[index1][index2] =='m'){
        c--;
        return c;
    }else{
        return c;
    }
}


