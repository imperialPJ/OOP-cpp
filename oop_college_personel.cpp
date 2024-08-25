#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Abstract base class Person (demonstrates abstraction)
class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}

    virtual void displayInfo() const = 0; // Pure virtual function (demonstrates polymorphism)
};

// Derived class Student from Person (demonstrates inheritance)
class Student : public Person {
private:
    int studentID;
    string course;

public:
    Student(string n, int a, int id, string c) : Person(n, a), studentID(id), course(c) {}

    void displayInfo() const override { // Overrides base class method (demonstrates polymorphism)
        cout << "Student Name: " << name << "\n";
        cout << "Age: " << age << "\n";
        cout << "Student ID: " << studentID << "\n";
        cout << "Course: " << course << "\n";
    }

    // Encapsulated method to update the course
    void updateCourse(string newCourse) {
        course = newCourse;
    }
};

// Derived class Professor from Person (demonstrates inheritance)
class Professor : public Person {
private:
    int professorID;
    string subject;

public:
    Professor(string n, int a, int id, string s) : Person(n, a), professorID(id), subject(s) {}

    void displayInfo() const override { // Overrides base class method (demonstrates polymorphism)
        cout << "Professor Name: " << name << "\n";
        cout << "Age: " << age << "\n";
        cout << "Professor ID: " << professorID << "\n";
        cout << "Subject: " << subject << "\n";
    }

    // Encapsulated method to update the subject
    void updateSubject(string newSubject) {
        subject = newSubject;
    }
};

// College class to manage students and professors
class College {
private:
    vector<Person*> members; // Encapsulated list of college members

public:
    // Method to add a person (student or professor) to the college
    void addMember(Person* p) {
        members.push_back(p);
    }

    // Method to display information of all members
    void displayAllMembers() const {
        for (const auto& member : members) {
            member->displayInfo();
            cout << "-------------------------\n";
        }
    }

    ~College() { // Destructor to release allocated memory
        for (auto& member : members) {
            delete member;
        }
    }
};

// Main function
int main() {
    College myCollege;

    // Adding students and professors to the college
    myCollege.addMember(new Student("Alice", 20, 101, "Computer Science"));
    myCollege.addMember(new Student("Bob", 22, 102, "Mechanical Engineering"));
    myCollege.addMember(new Professor("Dr. Smith", 45, 201, "Physics"));
    myCollege.addMember(new Professor("Dr. Johnson", 50, 202, "Mathematics"));

    // Displaying information of all members
    cout << "College Members:\n";
    cout << "-------------------------\n";
    myCollege.displayAllMembers();

    return 0;
}
