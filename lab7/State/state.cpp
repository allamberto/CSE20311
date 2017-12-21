//Ana Lamberto
//Purpose: implementation of State class
#include "state.h"
#include <vector>
#include <iostream>
using namespace std;

State::State(){
        abrev = "IN";
        state = "Indiana";
        cap = "Indianapolis";
        population = 6330000;
        year = 1816;
        numRep = 9;
}

State::State(string ab, string sn, string cp, int p, int yr, int nr){
        state = sn;
        abrev = ab;
        cap = cp;
        population = p;
        year = yr;
        numRep = nr;
}

State::~State()
{ }

void State::setAbrev(string ab){
        abrev = ab;
}

void State::setName(string sn){
        state = sn;
}

void State::setCap(string cp){
        cap = cp;
}

void State::setPopulation(int p){
        population = p;
}

void State::setYear(int yr){
        year = yr;
}

void State::setNumRep(int nr){
        numRep = nr;
}

string State::getAbrev(){
        return abrev;
}

string State::getName(){
        return state;
}

string State::getCap(){
        return cap;
}

int State::getPopulation(){
        return population;
}

int State::getYear(){
        return year;
}

int State::getNumRep(){
        return numRep;
}
