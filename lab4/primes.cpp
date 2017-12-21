//Ana Luisa Lamberto
//Lab 4
//Purpose:  finds all the prime numbers between 1 and 1,000

#include <iostream>
#include <iomanip>
using namespace std;

int main(){

int numElements = 1000; //included so I don't have to hardcode 1000 anywhere
int primeAr[numElements];

//set all numbers but 1 equal to 1
for (int i = 2; i <= numElements; i++){
        primeAr[i] = 1;
        //cout << primeAr[i] << " ";
}


//loop through entire array for each vallue to find multiples
for (int i = 2; i <=numElements; i++){ //loop through all numbers in array
        if (primeAr[i] == 1){
                for (int j = numElements; j > i; j--){ //loop through the remainder of the function starting from max and descreasing until it reaches i
                        if ((j%i) == 0){ //if the element is divisible with no reminder with the couter from outer loop than that number isn't prime
                                primeAr[j] = 0;
                        }
                }
        }
}

int spaceCounter = 0; //keeps track of how many outputs are printed per line
cout << setw(6); //to line up first row
// print prime numbers
for (int i = 2; i < numElements; i++){
        if (primeAr[i] == 1){
                if (spaceCounter == 9){ //stops printing in that line at output 10
                        cout << i << setw(6) << endl;
                        spaceCounter = 0;
                }
                else{
                cout  << i << setw(6);
                spaceCounter++;
                }
        }
}

return 0;
}
