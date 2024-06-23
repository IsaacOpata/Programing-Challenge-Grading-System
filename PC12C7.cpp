#include <iostream>
#include <string>
using namespace std;

// Function prototypes
void getScores(double [], int);
char getLetterGrade(double);

int main() 
{
    const int NUM_STUDENTS = 5;
    const int NUM_TESTS = 4;

    string studentNames[NUM_STUDENTS];
    char letterGrades[NUM_STUDENTS];
    double testScores[NUM_STUDENTS][NUM_TESTS];

    // Get the student names and their test scores
    for (int i = 0; i < NUM_STUDENTS; i++) 
    {
        cout << "Enter the name of student " << (i + 1) << ": ";
        cin >> studentNames[i];

        cout << "Enter the four test scores for " << studentNames[i] << ": ";
        getScores(testScores[i], NUM_TESTS);
    }

    // Calculate average scores and assign letter grades
    for (int i = 0; i < NUM_STUDENTS; i++) 
    {
        double sum = 0.0;
        for (int j = 0; j < NUM_TESTS; j++) 
        {
            sum += testScores[i][j];
        }
        double average = sum / NUM_TESTS;
        letterGrades[i] = getLetterGrade(average);
    }

    // Display the results
    cout << "\nStudent Grades:\n";
    for (int i = 0; i < NUM_STUDENTS; i++) 
    {
        cout << "Name: " << studentNames[i] << ", Average Score: "
            << (testScores[i][0] + testScores[i][1] + testScores[i][2] + testScores[i][3]) / NUM_TESTS
            << ", Letter Grade: " << letterGrades[i] << endl;
    }

    return 0;
}

// Function to get valid test scores
void getScores(double scores[], int size) {
    for (int i = 0; i < size; i++) {
        do 
        {
            cout << "Score " << (i + 1) << ": ";
            cin >> scores[i];
            if (scores[i] < 0 || scores[i] > 100) 
            {
                cout << "Invalid score. Please enter a score between 0 and 100." << endl;
            }
        } 
        while (scores[i] < 0 || scores[i] > 100);
    }
}

// Function to determine the letter grade based on average score
char getLetterGrade(double average) 
{
    if (average >= 90)
        return 'A';
    else if (average >= 80)
        return 'B';
    else if (average >= 70)
        return 'C';
    else if (average >= 60)
        return 'D';
    else
        return 'F';
}
