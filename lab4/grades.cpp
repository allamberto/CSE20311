//Ana Luisa Lamberto
//Lab 4
//Purpose: reads integer grade values from a data file into an array, and that then computes their average and their standard deviation.

#include <iostream>
#include <cmath>
using namespace std;

int main(){

int numVal = 50, grades[numVal], sum = 0, i = 0;

cin >> grades[0]; //input first value for comparison

//set up input for at most 50 values from data file
while (grades[i] > 0) {
        sum += grades[i];
        i++;
        cin >> grades[i]; //comes last to make sure -1 isn't added to the sum
}
for (int j = 0; j <=(i - 1); j++)
cout << grades[j] << endl;

cout << "i: " << i << endl;
cout << "sum: " << sum << endl;

float avg = (sum * 1.0)/i; //multiply by 1.0 to make sure avg is a decimal
cout << "The mean of all the grades is " << avg << ".\n";

float sumDev = 0; //sum of differences in standard deviation formula

//loop to calculate standard deviation
for (int j = 0; j < i; j++) {
        sumDev += pow((grades[j] - avg), 2); //take the sum of every square of the grade minus the mean
}

float standDev = sqrt(sumDev/i); //mean of the sum calcualted above
cout << "The standard deviation is " << standDev << ".\n";

return 0;
}
