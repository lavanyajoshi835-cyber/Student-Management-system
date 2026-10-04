#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    string name;
    string enrollmentNo;
    string branch;
    int semester;
    float marks;
};

// Add a student
void addStudent(vector<Student>& students) {
    Student s;

    cout << "\nEnter Student Name: ";
    cin.ignore();
    getline(cin, s.name);

    cout << "Enter Enrollment Number: ";
    getline(cin, s.enrollmentNo);

    cout << "Enter Branch: ";
    getline(cin, s.branch);

    cout << "Enter Semester: ";
    cin >> s.semester;

    cout << "Enter Marks: ";
    cin >> s.marks;

    students.push_back(s);

    cout << "\nStudent added successfully!\n";
}

// Display all students
void displayStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "\nNo student records found.\n";
        return;
    }

    cout << "\n===== Student Records =====\n";

    for (int i = 0; i < students.size(); i++) {
        cout << "\nStudent " << i + 1 << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Enrollment No: " << students[i].enrollmentNo << endl;
        cout << "Branch: " << students[i].branch << endl;
        cout << "Semester: " << students[i].semester << endl;
        cout << "Marks: " << students[i].marks << endl;
    }
}

// Search for a student
void searchStudent(const vector<Student>& students) {
    string enrollment;
    cout << "\nEnter Enrollment Number to search: ";
    cin >> enrollment;

    for (const Student& s : students) {
        if (s.enrollmentNo == enrollment) {
            cout << "\nStudent Found!\n";
            cout << "Name: " << s.name << endl;
            cout << "Enrollment No: " << s.enrollmentNo << endl;
            cout << "Branch: " << s.branch << endl;
            cout << "Semester: " << s.semester << endl;
            cout << "Marks: " << s.marks << endl;
            return;
        }
    }

    cout << "\nStudent not found.\n";
}

// Update student details
void updateStudent(vector<Student>& students) {
    string enrollment;
    cout << "\nEnter Enrollment Number to update: ";
    cin >> enrollment;

    for (Student& s : students) {
        if (s.enrollmentNo == enrollment) {

            cin.ignore();

            cout << "Enter New Name: ";
            getline(cin, s.name);

            cout << "Enter New Branch: ";
            getline(cin, s.branch);

            cout << "Enter New Semester: ";
            cin >> s.semester;

            cout << "Enter New Marks: ";
            cin >> s.marks;

            cout << "\nStudent details updated successfully!\n";
            return;
        }
    }

    cout << "\nStudent not found.\n";
}

// Delete a student
void deleteStudent(vector<Student>& students) {
    string enrollment;
    cout << "\nEnter Enrollment Number to delete: ";
    cin >> enrollment;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].enrollmentNo == enrollment) {
            students.erase(students.begin() + i);

            cout << "\nStudent deleted successfully!\n";
            return;
        }
    }

    cout << "\nStudent not found.\n";
}

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\n\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;

            case 2:
                displayStudents(students);
                break;

            case 3:
                searchStudent(students);
                break;

            case 4:
                updateStudent(students);
                break;

            case 5:
                deleteStudent(students);
                break;

            case 6:
                cout << "\nExiting program...\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}