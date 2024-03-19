//Name: Exercise.cpp
//Project: CMSC 202 Project 3, Fall 2023
//Author:  Faheed Sadique
//Date:    10/14/23
//Desc: This file contains code details for an Exercise.cpp

#include "Exercise.h"
#include <iostream>
using namespace std;

//Default constructor
Exercise::Exercise(): m_category(newExercise),m_next(nullptr){
  int time (0);
}

std::string category;
std::string name;
int reps;
int weight;


//Overloaded constructor
Exercise::Exercise(std::string& category, std::string& name, int reps, int weight): m_category(category), m_name(name), m_reps(reps), m_weight(weight){
    m_category = category;
     m_name = name;
     m_reps = reps;
     m_weight = weight;
}

std::string GetCategory(){   //Returns m_category
return m_category;
}

std::string GetName() {   //Returns m_name
return m_name;
}

int GetReps() {   //Returns m_reps
return m_reps;
}

int GetWeight(){   //Returns m_weight
return m_weight;
}

Exercise* GetNext(){  //Returns m_next
return m_next;
}
void SetCategory(std::string category){  //Sets m_category
  cout << category << endl;
  // m_category = category;
}
void SetName(std::string name){  //Sets m_name
  cout << name << endl;
  //m_name = name;
}
void SetReps(int reps){    //Sets m_reps
  cout << reps << endl;
  //m_reps = reps;
}

void SetWeight(int weight){  //Sets m_weight
  cout << weight << endl;
  //m_weight = weight;
}
void SetNext(Exercise* next){    //Sets m_next
  cout << next << endl;
  //m_next = next;
}
