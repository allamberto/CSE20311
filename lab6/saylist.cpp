#include <iostream>
#include <string>
#include <list>
#include <fstream>
using namespace std;

void display(list<string>);
void findWord(list<string>, string);

int main(){

        bool doExit = false;
        int choice;
        ifstream ifs;
        ofstream ofs;
        string s; //will hold different stirng values through transitions - no specific value

        //get startup data file
        string input, output;
        cout << "Please choose a \"startup\" data file: ";
        cin >> input;

        ifs.open(input);
        while(!ifs){ //check to make sure text file is valid
                cout << endl << "Error - Try again.\n" << endl;
                cout << "Please choose a \"startup\" data file: ";
                cin >> input;
                ifs.open(input); //reload new input if not valid
        }

        list<string> sayings;
        std::list<string>::iterator it; //create iterator
        getline(ifs, s); //take first line
        while(!ifs.eof()){ //add all sayings into a list
                sayings.push_back(s);
                getline(ifs, s); //take next line
        }
        sayings.sort(); //sort sayings in alphabetical order

        do{
                //setup menu
                cout << "Please choose an option:\n\t1: Display all sayings currently in the database";
                cout << "\n\t2: Enter a new saying into the database";
                cout << "\n\t3: List sayings that contain a given substring entered by the user";
                cout << "\n\t4: Remove a saying";
                cout << "\n\t5: Save all sayings in a new text file\n\t6: Quit" << endl;
                cout << "\nEnter your choice: ";
                cin >> choice;
                switch(choice){
                        case 1:
                                display(sayings);
                        break;
                        case 2:
                                cin.ignore(); //keep from entering an infinite loop
                                cout << "\nEnter your new saying: ";
                                getline(cin, s); //gets entire line as input
                                sayings.push_back(s); //add new saying to list
                                sayings.sort(); //sort list again
                        break;

                        case 3:
                                cout << "What word would you like to search for: ";
                                cin >> s;
                                findWord(sayings, s);
                        break;

                        case 4:
                                int rvChoice;
                                cout << "Here are your sayings. Which number would you like deleted?" << endl;
                                display(sayings); //display choices
                                cout << "Delete: ";
                                cin >> rvChoice;
                                while((rvChoice > sayings.size()) || (rvChoice < 0)){ //check to make sure choice is valid
                                        cout << "Sorry that's not an option. Please try again." << endl;
                                        cout << "Which number would you like to delete: ";
                                        cin >> rvChoice;
                                }
                                it = sayings.begin(); //intialize pointer
                                advance(it, (rvChoice - 1));    //advance pointer to correct saying
                                sayings.erase(it); //erase user choice from list                        
                        break;

                        case 5:
                                cout << "What would you like to name your new file? (with extension): ";
                                cin >> output;
                                ofs.open(output); //open ofstream
                                for (auto it = sayings.begin(); it != sayings.end(); it++){
                                        ofs << *it << endl; //output each saying
                                }
                                ofs.close();
                        break;

                        case 6:
                                doExit = true; //change flag
                        break;

                        default:
                                cout << "\nInvalid Input - Please try again." << endl;
                        break;
                 }
        }while(!doExit);

        return 0;

}

//displays a group of sayings
void display(list<string> sayings){
        int i = 0;
        for(auto it = sayings.begin(); it != sayings.end(); it++){ //use pointer to loop through list
                cout << ++i << ": " <<  *it << endl;

        }
}

void findWord(list<string> sayings, string word){
        int count = 0;
        for(auto it = sayings.begin(); it != sayings.end(); it++){
                string s = *it;
                if((s.find(word) != string::npos)){ //find checks if word is in the string
                        cout << *it << endl;
                }
                else //keep count of how many times word doesn't appear
                        count++;
        }

        if(count == sayings.size()) //check to see if word ever appeared
                cout << "That word doesn't appear in any sayings" << endl;
}

                     

