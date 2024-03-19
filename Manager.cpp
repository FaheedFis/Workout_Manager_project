//Name: Manager.cpp
//Project: CMSC 202 Project 3, Fall 2023
//Author:  Faheed Sadique
//Date:    10/14/23
//Desc: This file contains code details for the Manager.cpp

#include "Workout.h"
#include "Exercise.h"
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>


using namespace std;

//Overloaded constructor
Manager::Manager(std::string& fileName) : m_fileName(fileName){
  ReadFile();
}

//Destructor
~Manager(){
}

void DisplayWorkouts(){
  for (const& workout : m_workouts) {
    std::cout << "Workout: " << workout.name << std::endl;
    for (const& exercise : workout.exercises) {
      // Display exercise details
      std::cout << "  Category: " << exercise.category
		<< ", Name: " << exercise.name
		<< ", Reps: " << exercise.reps
		<< ", Weight: " << exercise.weight << std::endl;
    }
  }
}
  
void ReadFile(){
  std::ifstream inputFile(m_fileName);
  if (inputFile.is_open()) {
  }
  inputFile.close();
}

void MainMenu(){
  int choice = 0;
  while (choice != 4) {
    std::cout << "1. Display Workouts\n2. Reverse Workout\n3. Insert New Exercise\n4. Exit\n";
    std::cin >> choice;

    switch (choice) {
    case 1:
      DisplayWorkouts();
      break;
    case 2:
      ReverseWorkout();
      break;
    case 3:
      InsertNewExercise();
      break;
    case 4:
      std::cout << "Exiting...\n";
      break;
    default:
      std::cout << "Invalid choice. Please try again.\n";
    }
  }
}

int FindWorkout(const std::string& workoutName) {
  auto it = std::find_if(m_workouts.begin(), m_workouts.end(),
			 [&workoutName](const Workout& w) { return w.name == workoutName; });
  if (it != m_workouts.end()) {
    return std::distance(m_workouts.begin(), it); // Return index of workout
  }
  return -1; // Workout not found
}
void ReverseWorkout(){
  if (m_size <= 1) {
    return;
  }
}
void InsertNewExercise(){
  std::string workoutName, category, exerciseName;
  int reps;
  double weight;

  std::cout << "Enter workout name: ";
  std::cin >> workoutName;

  int index = FindWorkout(workoutName);

  if (index == -1) {
    // Workout not found, create a new workout
    Workout newWorkout;
    newWorkout.name = workoutName;
    m_workouts.push_back(newWorkout);
    index = m_workouts.size() - 1;
  }

 cout << "Enter category: ";
 cin >> category;

 cout << "Enter exercise name: ";
 cin >> exerciseName;

 cout << "Enter number of reps: ";
 cin >> reps;

 cout << "Enter weight: ";
 cin >> weight;

  // Create a new exercise
  Exercise newExercise{ category, exerciseName, reps, weight };

  // Insert into the chosen workout
  m_workouts[index].exercises.push_back(newExercise);
}
