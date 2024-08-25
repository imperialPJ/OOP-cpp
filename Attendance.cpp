#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Class to store student information
class Student {
private:
    int studentID;
    string name;
    int totalClasses;

public:
    // Constructor
    Student(int id, string n, int total) : studentID(id), name(n), totalClasses(total) {}

    // Getters
    int getID() const { return studentID; }
    string getName() const { return name; }
    int getTotalClasses() const { return totalClasses; }
};

// Class to store attendance information
class Attendance {
private:
    int studentID;
    int attendedClasses;

public:
    // Constructor
    Attendance(int id, int attended) : studentID(id), attendedClasses(attended) {}

    // Getters
    int getID() const { return studentID; }
    int getAttendedClasses() const { return attendedClasses; }

    // Method to calculate attendance percentage
    double calculatePercentage(int totalClasses) const {
        return (static_cast<double>(attendedClasses) / totalClasses) * 100;
    }
};

// Main function
int main() {
    vector<Student> students;
    vector<Attendance> attendanceRecords;

    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;

    // Input student data
    for (int i = 0; i < numStudents; ++i) {
        int id, totalClasses;
        string name;

        cout << "\nEnter details for Student " << i + 1 << ":\n";
        cout << "Student ID: ";
        cin >> id;
        cout << "Name: ";
        cin.ignore(); // Ignore newline character left in the buffer
        getline(cin, name);
        cout << "Total Classes: ";
        cin >> totalClasses;

        students.push_back(Student(id, name, totalClasses));
    }

    // Input attendance data
    for (int i = 0; i < numStudents; ++i) {
        int id, attendedClasses;

        cout << "\nEnter attendance for Student ID " << students[i].getID() << " (" << students[i].getName() << "):\n";
        cout << "Classes Attended: ";
        cin >> attendedClasses;

        attendanceRecords.push_back(Attendance(students[i].getID(), attendedClasses));
    }

    // Display student information and attendance percentage
    cout << "\nAttendance Summary:\n";
    for (const auto& student : students) {
        cout << "\nStudent ID: " << student.getID() << "\n";
        cout << "Name: " << student.getName() << "\n";
        int totalClasses = student.getTotalClasses();

        // Find the corresponding attendance record
        for (const auto& attendance : attendanceRecords) {
            if (attendance.getID() == student.getID()) {
                double percentage = attendance.calculatePercentage(totalClasses);
                cout << "Attendance Percentage: " << percentage << "%" << "\n";
            }
        }
    }

    return 0;
}
