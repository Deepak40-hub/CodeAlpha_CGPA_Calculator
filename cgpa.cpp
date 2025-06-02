#include <iostream>      // For input and output
#include <iomanip>       // For controlling output format (like setprecision)
using namespace std;

// Function to convert letter grade to corresponding grade point
double gradeToPoint(string grade) {
    if (grade == "O" || grade == "o") return 10.0;   // Outstanding
    if (grade == "A+" ) return 9.0;                  // Excellent
    if (grade == "A" ) return 8.0;                   // Very Good
    if (grade == "B+") return 7.0;                   // Good
    if (grade == "B") return 6.0;                    // Average
    if (grade == "C" ) return 5.0;                   // Pass
    if (grade == "U" ) return 0.0;                   // Fail / Reappear

    return -1; // Invalid grade entered
}

int main() {
    const int MAX_COURSES = 100;                    // Maximum number of courses supported
    int numCourses;                                 // Number of courses input by the user
    string grades[MAX_COURSES];                     // Array to store grades
    double credits[MAX_COURSES];                    // Array to store credit hours
    double gradePoints[MAX_COURSES];                // Array to store grade points

    cout << "Enter number of courses: ";
    cin >> numCourses;                              // User input for number of courses

    if (numCourses > MAX_COURSES || numCourses <= 0) {
        cout << "Invalid number of courses.\n";     // Validate course count
        return 1;
    }

    // Input section for each course
    for (int i = 0; i < numCourses; i++) {
        cout << "\nCourse " << i + 1 << ":\n";
        cout << "Enter grade (O,A+,A ,B+ B, C ,U): ";
        cin >> grades[i];                           // Take grade input

        cout << "Enter credit hours: ";
        cin >> credits[i];                          // Take credit input

        gradePoints[i] = gradeToPoint(grades[i]);   // Convert grade to grade point

        if (gradePoints[i] == -1) {
            cout << "Invalid grade entered. Exiting.\n";  // Handle invalid grades
            return 1;
        }
    }

    double totalCredits = 0, totalGradePoints = 0;

    // Calculate total credits and total grade points
    for (int i = 0; i < numCourses; i++) {
        totalCredits += credits[i];                        // Sum of credit hours
        totalGradePoints += gradePoints[i] * credits[i];   // Grade points × credits
    }

    double cgpa = totalGradePoints / totalCredits;         // Final CGPA calculation

    cout << fixed << setprecision(2);                      // Format output to 2 decimal places
    cout << "\nCourse Summary:\n";

    // Display course details
    for (int i = 0; i < numCourses; i++) {
        cout << "Course1 " << i + 1 << ": Grade = " << grades[i]
             << ", Credit Hours = " << credits[i] << "\n";
    }

    // Display final summary
    cout << "\nTotal Credit Hours: " << totalCredits << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;
    cout << "Final CGPA: " << cgpa << endl;

    return 0;
}
