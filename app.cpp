//============================================================================
// Name        : app.cpp
// Author      : Rostyslav Melnik
// Version     : 1.0
// Description : Project Two
//============================================================================



#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <limits> //

using namespace std;

// Helper Functions

// Trim whitespace from a string
string trim(const string& str) {
    size_t first = str.find_first_not_of(" \t");
    size_t last = str.find_last_not_of(" \t");
    return (first == string::npos) ? "" : str.substr(first, last - first + 1);
}


// Structure Definitions

struct Course {
    string courseNumber;
    string title;
    vector<string> prerequisites;

    Course() {}
};

// Internal structure for the Binary Search Tree nodes
struct Node {
    Course course;
    Node* left;
    Node* right;

    Node() {
        left = nullptr;
        right = nullptr;
    }

    Node(Course aCourse) : Node() {
        course = aCourse;
    }
};

// Binary Search Tree Class

class BinarySearchTree {
private:
    Node* root;

    void addNode(Node* node, Course course);
    void inOrder(Node* node);
    void destroyRecursive(Node* node);

public:
    BinarySearchTree();
    virtual ~BinarySearchTree();

    void Insert(Course course);
    void PrintInOrder();
    Course Search(string courseNumber);
};

// Constructor
BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

// Destructor (frees memory)
BinarySearchTree::~BinarySearchTree() {
    destroyRecursive(root);
}

// Recursive delete
void BinarySearchTree::destroyRecursive(Node* node) {
    if (node != nullptr) {
        destroyRecursive(node->left);
        destroyRecursive(node->right);
        delete node;
    }
}

// Insert course into BST
void BinarySearchTree::Insert(Course course) {
    if (root == nullptr) {
        root = new Node(course);
    } else {
        addNode(root, course);
    }
}

// Recursive insert helper
void BinarySearchTree::addNode(Node* node, Course course) {
    if (course.courseNumber < node->course.courseNumber) {
        if (node->left == nullptr) {
            node->left = new Node(course);
        } else {
            addNode(node->left, course);
        }
    } else {
        if (node->right == nullptr) {
            node->right = new Node(course);
        } else {
            addNode(node->right, course);
        }
    }
}

// In-order traversal to display courses in alphanumeric order
void BinarySearchTree::inOrder(Node* node) {
    if (node != nullptr) {
        inOrder(node->left);
        cout << node->course.courseNumber << ", " << node->course.title << endl;
        inOrder(node->right);
    }
}

// Public print method
void BinarySearchTree::PrintInOrder() {
    inOrder(root);
}

// Search for a course
Course BinarySearchTree::Search(string courseNumber) {
    Node* current = root;

    while (current != nullptr) {
        if (current->course.courseNumber == courseNumber) {
            return current->course;
        }
        else if (courseNumber < current->course.courseNumber) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }
    return Course(); // not found
}

// File Loading Function

// Open the file and validate its existence before attempting to parse
void loadCourses(string filename, BinarySearchTree*& bst) {
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Error: File not found. Please check the filename." << endl;
        return;
    }

    // Prevent duplicate data by resetting tree
    delete bst;
    bst = new BinarySearchTree();

    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        vector<string> tokens;

        while (getline(ss, token, ',')) {
            tokens.push_back(trim(token));
        }
        // Requirement validation: skip lines that do not have at least a Course ID and Title.
        if (tokens.size() < 2) {
            cout << "Error: Invalid line skipped." << endl;
            continue;
        }

        Course course;

        // Course number
        course.courseNumber = tokens[0];
        transform(course.courseNumber.begin(), course.courseNumber.end(),
                  course.courseNumber.begin(), ::toupper);

        // Title
        course.title = tokens[1];

        // Prerequisites
        for (size_t i = 2; i < tokens.size(); i++) {
            string prereq = tokens[i];
            transform(prereq.begin(), prereq.end(), prereq.begin(), ::toupper);
            course.prerequisites.push_back(prereq);
        }

        bst->Insert(course);
    }

    file.close();
    cout << "Data loaded successfully." << endl;
}

// Display Course Info

void displayCourse(Course course, BinarySearchTree* bst) {
    cout << course.courseNumber << ", " << course.title << endl;

    if (course.prerequisites.empty()) {
        cout << "Prerequisites: None" << endl;
    } else {
        cout << "Prerequisites: ";

        for (size_t i = 0; i < course.prerequisites.size(); i++) {
            Course prereq = bst->Search(course.prerequisites[i]);

            if (!prereq.courseNumber.empty()) {
                cout << prereq.courseNumber << ", " << prereq.title;
            } else {
                cout << course.prerequisites[i];
            }

            if (i < course.prerequisites.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
}

// Main Program
int main() {
    BinarySearchTree* bst = new BinarySearchTree();

    string filename;
    string searchId;
    int choice = 0;

    cout << "Welcome to the ABCU Course Planner." << endl << endl;

    while (choice != 9) {
        cout << "  1. Load Data Structure." << endl;
        cout << "  2. Print Course List." << endl;
        cout << "  3. Print Course." << endl;
        cout << "  9. Exit" << endl << endl;

        cout << "What would you like to do? ";

        // Input validation
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter 1, 2, 3, or 9." << endl;
            cin.clear();
            cin.ignore(100, '\n');
            continue;
        }

        switch (choice) {

        case 1:
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); /////
            cout << "Enter file name: ";
            //cin.ignore();
            getline(cin, filename);
            loadCourses(filename, bst);
            break;

        case 2:
            cout << "Here is a sample schedule:" << endl;
            bst->PrintInOrder();
            break;

        case 3:
            cout << "What course do you want to know about? ";
            cin >> searchId;

            // Convert input to uppercase
            transform(searchId.begin(), searchId.end(), searchId.begin(), ::toupper);

            {
                Course course = bst->Search(searchId);

                if (!course.courseNumber.empty()) {
                    displayCourse(course, bst);
                } else {
                    cout << "Course " << searchId << " not found." << endl;
                }
            }
            break;

        case 9:
            cout << "Thank you for using the course planner!" << endl;
            break;

        default:
            cout << choice << " is not a valid option." << endl;
            break;
        }

        cout << endl;
    }

    delete bst;
    return 0;
}