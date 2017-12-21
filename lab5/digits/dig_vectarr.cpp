#include <iostream>
#include <vector>
#include <array>
using namespace std;

//pass freq by reference so it changes without having to return a value
void findfreq(vector<int> digits, array<int, 10>& freq);
void results(vector<int> digits, array<int, 10> freq);

int main()
{
        //array with random digits
        vector<int> digits = {4,3,6,5,7,8,9,4,6,3,1,3,5,7,6,3,6,
                  5,6,7,0,2,9,7,1,3,2,1,6,7,4,6,2,8,
                  1,4,5,6,0,2,7,6,4,5,6,8,3,5,7,1,5};
        array<int, 10> freq = {0};    // array to tally the frequency of digits

        findfreq(digits, freq); // compute digits' frequencies
        results(digits, freq);  // display frequencies for each digit

        return 0;
}

void findfreq(vector<int> a, array<int, 10>& freq)
{
        for (auto it = a.begin(); it < a.end(); it++){ //loop through entire vector checking for digit at each iteration
                (freq[*it])++;
        }
}

void results(vector<int> a, array<int, 10> freq)
{
        for (int n = 0; n < freq.size(); n++)
                cout <<  "digit " << n << " occurs " << freq[n] << " times" << endl; //
}
