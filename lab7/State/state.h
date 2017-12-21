//Ana Lamberto
//Purpose: interface for State school

#include <string>
#include <vector>
using namespace std;

class State {
public:
        State();
        State(string, string, string, int, int, int);
        ~State();
        void setAbrev(string);
        void setName(string);
        void setCap(string);
        void setPopulation(int);
        void setYear(int);
        void setNumRep(int);
        string getAbrev();
        string getName();
        string getCap();
        int getPopulation();
        int getYear();
        int getNumRep();
//      void displayAll(vector<State> &);
private:
        int population;
        int year;
        int numRep;
        string abrev;
        string state;
        string cap;
};
