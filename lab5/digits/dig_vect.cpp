#include <iostream>
#include <vector>
using namespace std;

//pass freq by reference so it changes without having to return a value
void findfreq(vector<int> digits, vector<int>& freq);
void results(vector<int> digits, vector<int> freq);

int main()
{
        //array with random digits
        vector<int> digits = {4,3,6,5,7,8,9,4,6,3,1,3,5,7,6,3,6,
                  5,6,7,0,2,9,7,1,3,2,1,6,7,4,6,2,8,
                  1,4,5,6,0,2,7,6,4,5,6,8,3,5,7,1,5};
        vector<int> freq = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};    // array to tally the frequency of digits

        findfreq(digits, freq); // compute digits' frequencies
        results(digits, freq);  // display frequencies for each digit

        return 0;
}

void findfreq(vector<int> a, vector<int>& freq)
{
         for(int i = 0; i < a.size(); i++){ //loop through entire vector checking for digit at each iteration
               (freq[a[i]])++; // add one to each position of freq that the position of a falls under
        }

}

void results(vector<int> a, vector<int> freq)
{
        for (int n = 0; n <= 9; n++)
                cout <<  "digit " << n << " occurs " << freq[n] << " times" << endl;
}
