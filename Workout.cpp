//Name: Workout.cpp
//Project: CMSC 202 Project 3, Fall 2023
//Author:  Faheed Sadique
//Date:    10/14/23
//Desc: This file contains code details for the Workout.cpp
#include "Workout.h"

using namespace std;
//Default constructor
Workout(): m_name("Default"), m_head(nullptr),m_tail(nullptr),m_size(0){
  m_name = default;
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
}

// Overloaded constructor
Workout(string& name) : m_name(name), m_head(nullptr), m_tail(nullptr), m_size(0) {
  m_name = name;
  m_head = nullptr;
  m_tail = nullptr;
  m_size = 0;

}

// Destructor
~Workout() {
}
//Inserts a new exercise into a specific workout
void InsertEnd(Exercise*){
  if (m_tail == nullptr) {
    m_head = newExercise;
    m_tail = newExercise;
  } else {
    m_tail->next = newExercise;
    m_tail = newExercise;
  }
  m_size++;
}

//implementing Getters
string GetName(){
  returns m_name;   //Returns m_name
}
int GetSize(){
  returns m_size;   //Returns m_size
}

// Reversing the workout base
void ReverseWorkout(){
  if (m_size <= 1) {
    return; 
  }

  Exercise* prev = nullptr;
  Exercise* current = m_head;
  Exercise* next = nullptr;

  m_tail = m_head; // Update tail to the previous head
  
  while (current != nullptr) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

  m_head = prev;
}

Exercise* GetData(int nodeNum){
  if (nodeNum < 0 || nodeNum >= m_size) {
    return nullptr;
  }

  Exercise* current = m_head;
  for (int i = 0; i < index; i++) {
    current = current->next;
  }

  return current;
}
friend ostream &operator<< (ostream &output, Workout &myWorkout){
  output << myWorkout.m_category << ":" << myWorkout.m_name
	 << "(" << myWorkout.m_reps << "@"
	 << myWorkout.m_weight << "Ibs)";
  return output;
}
