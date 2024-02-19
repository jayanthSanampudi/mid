//small changes

#include <iostream> // Include the input-output stream library
#include <string> // Include the string library
#include <vector> // Include the vector library (for dynamic arrays)
using namespace std;

class Person { // Define a class named Person
private:
    string name; // Private member variable for storing the person's name
    int age; // Private member variable for storing the person's age
    vector<Person*> children; // Private member variable for storing the person's children

public:
    Person(const std::string& n, int a) : name(n), age(a) {} // Constructor for initializing name and age

    void addChild(Person* child) { // Public member function for adding a child to the person
        children.push_back(child); // Add the child pointer to the vector of children
    }

    string getName() const { // Public member function to get the person's name
        return name; // Return the person's name
    }

    void print(int depth = 0) const { // Public member function for printing the family tree
        for (int i = 0; i < depth; ++i) // Loop to add indentation based on the depth of the tree
            std::cout << "   |"; // Print indentation for each level of the tree

        cout << "---" << name << " (" << age << ")\n"; // Print the person's name and age with indentation

        for (const auto& child : children) // Loop through the children of the person
            child->print(depth + 1); // Recursively print the family tree for each child
    }

    ~Person() { // Destructor to clean up memory for dynamically allocated children
        for (auto child : children) // Loop through the children vector
            delete child; // Delete each child object
    }
};

// Function to recursively build the family tree
void buildFamilyTree(Person* parent) { // Function to build the family tree starting from a parent
    int numChildren; // Variable to store the number of children
    cout << "Enter the number of children for " << parent->getName() << ": "; // Prompt for the number of children
    cin >> numChildren; // Read the number of children from the user

    for (int i = 0; i < numChildren; ++i) { // Loop to input information for each child
        string childName; // Variable to store the child's name
        int childAge; // Variable to store the child's age

        cout << "Enter the name for child " << i + 1 << ": "; // Prompt for the child's name
        cin >> childName; // Read the child's name from the user

        cout << "Enter the age for child " << i + 1 << ": "; // Prompt for the child's age
        cin >> childAge; // Read the child's age from the user

        Person* child = new Person(childName, childAge); // Create a new Person object for the child
        parent->addChild(child); // Add the child to the parent's list of children

        // Recursively build the family tree for the child
        buildFamilyTree(child); // Call buildFamilyTree recursively to build the subtree for the child
    }
}

int main() { // Main function where the program execution starts
    string rootName; // Variable to store the root person's name
    int rootAge; // Variable to store the root person's age

    // Getting information for the root of the family tree
    cout << "Enter the name for the root of the family tree: "; // Prompt for the root person's name
    cin >> rootName; // Read the root person's name from the user

    cout << "Enter the age for the root of the family tree: "; // Prompt for the root person's age
    cin >> rootAge; // Read the root person's age from the user

    // Creating the root of the family tree
    Person* root = new Person(rootName, rootAge); // Create a new Person object for the root

    // Building the family tree
    buildFamilyTree(root); // Call the buildFamilyTree function to construct the family tree starting from the root

    // Printing the family tree
    cout << "\nFamily Tree:\n"; // Print a label for the family tree
    root->print(); // Call the print function to print the family tree starting from the root

    // Clean up allocated memory
    delete root; // Delete the root object to release memory

    return 0; // Return 0 to indicate successful execution of the program
}
