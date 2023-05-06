#include <iostream>
#include <string>

using namespace std;

struct student {        // node struct

    // attributes

    int id;
    string name;
    int age;
    int grade;

    // node attributes

    student *next;
    student *prev;

    // Constructors and deconstructor

    student(int id_in, string name_in, int age_in, int grade_in) {
        id = id_in;
        name = name_in;
        age = age_in;
        grade = grade_in;
        
        next = nullptr;
        prev = nullptr;
    };

    student(int id_in, string name_in, int age_in, int grade_in, student *next_in, student *prev_in) {
        id = id_in;
        name = name_in;
        age = age_in;
        grade = grade_in;

        next = next_in;
        prev = prev_in;
    };
    ~student() {};
};

class CircularDoublyLinkedList {
    private:
        int id_num = 30000;
        student *head;
        student *tail;

    public:

        // HW Functions
        CircularDoublyLinkedList();                     // Constructor
        ~CircularDoublyLinkedList();                    // Deconstructor
        void add_record();                              // add NEW STUDENT to record list
        void remove_record();
        void update_record();
        void display_record();

        // Misc Functions
        int generate_id();                              // creates unique ID
        student* search();                              // search based on NAME or ID
        void del_node(student* point);                  // deletes a node within list
        void print(student* point, bool circle);        // display node
};

CircularDoublyLinkedList::CircularDoublyLinkedList() {  // constructor
    head = nullptr;
    tail = nullptr;
}

CircularDoublyLinkedList::~CircularDoublyLinkedList() { // deletes all items in list

    student *current;
    while(current != nullptr)
    {
        current = head;
        head = head->next;
        delete current;
    }

}

/*

    ASSIGNMENT FUNCTIONS

*/

void CircularDoublyLinkedList::add_record()
{
    while (true) {

        int id_in; string name_in; int age_in; int grade_in; student *next_in; student *prev_in;         // attribute initialize

        id_in = generate_id();
        cout << "\nPlease Enter Name: ";
        cin >> name_in;
        cout << "\nPlease Enter Age: ";
        cin >> age_in;

        // Check Valid Age

        if (age_in < 0)                                 // cannot be negative age... but a 200 year old man is technically possible
        {
            cout << "Invalid Age!!! (Cannot Be Negative)" << endl;

            cout << "Input 'M' to continue: ";    // system pause
            char in;
            cin >> in;
            break;
        }

        cout << "\nPlease Enter Grade: ";
        cin >> grade_in;

        // Check Valid Grade

        if (grade_in < 1 || grade_in > 6)               // grades 1-6 are possible... we're an elementary school now
        {
            cout << "Invalid Grade!!! (1-6)" << endl;

            cout << "Input 'M' to continue: ";
            char in;
            cin >> in;
            break;
        }

        student *new_student = new student(id_in, name_in, age_in, grade_in);

        if (head == nullptr)                            // List is empty... set head and tail to each other
        {
            head = new_student;
            tail = new_student;
            new_student->next = head;
            new_student->prev = head;
        } else                                          // List is not empty, set pointers to not break
        {
            tail-> next = new_student;
            new_student->prev = tail;
            head->prev = new_student;
            new_student->next = head;
            tail = new_student;
        }
        cout << "Added Successfully!" << endl;

        cout << "Input 'M' to return to main menu. Otherwise, continue adding new records: ";
        char in;
        cin >> in;
        if (in == 'M') { break;}

    }
}

void CircularDoublyLinkedList::remove_record()
{
    while (true) {
        system("cls");                                     // clear menu from screen

        student* point = search();                         // find record to be deleted

        if (head == nullptr)
        {
            cout << "List is empty!" << endl;
            
            cout << "Input 'M' to continue: ";    // system pause
            char in;
            cin >> in;
            return;
        }

        if (point == nullptr)                              // invalid input OR record not found
        {
            cout << "Record not found!" << endl;
            cout << "Input 'M' to continue: ";             // system pause
            char in;
            cin >> in;
            return;
        } else
        {
            del_node(point);                                // delete node in list

            cout << "Successfully Deleted!" << endl;
            cout << "Input 'M' to return to main menu. Otherwise, continue removing new records: ";
            char in;
            cin >> in;
            if (in == 'M') { break;}
        }

        
    }
}

void CircularDoublyLinkedList::update_record() {
    while (true) {

        system("cls");

        student* point = search();

        if (head == nullptr)
        {
            cout << "List is empty!" << endl;
        
            cout << "Input 'M' to continue: ";    // system pause
            char in;
            cin >> in;
            return;
        }

        if (point == nullptr)                              // invalid input OR record not found
        {
            cout << "Record not found!" << endl;
            cout << "Input 'M' to continue: ";             // system pause
            char in;
            cin >> in;
            return;
        }else
        {   // NO NEW UPDATE ID

            // New name
            cout << "Original Name: " << point->name << endl;
            cout << "Input new Name: ";
            string name_in; 
            cin >> name_in;
            cout << endl;

            // new age
            cout << "Original Age: " << point->age << endl;
            cout << "Input new Age: ";
            int age_in; 
            cin >> age_in;
            if (age_in < 0)                                 // cannot be negative age... but a 200 year old man is technically possible
            {
                cout << "Invalid Age!!! (Cannot Be Negative)" << endl;

                cout << "Input 'M' to continue: ";    // system pause
                char in;
                cin >> in;
                break;
            }
            cout << endl;

            // new grade
            cout << "Original Grade: " << point->grade << endl;
            cout << "Input new Grade: ";
            int grade_in;
            cin >> grade_in;
            if (grade_in < 1 || grade_in > 6)               // grades 1-6 are possible... we're an elementary school now
            {
                cout << "Invalid Grade!!! (1-6)" << endl;

                cout << "Input 'M' to continue: ";
                char in;
                cin >> in;
                break;
            }
            cout << endl;

            // update characteristics
            point->age = age_in;
            point->name = name_in;
            point->grade = grade_in;

            cout << "Successfully Updated!" << endl;
            cout << "Input 'M' to return to main menu. Otherwise, continue adding new records: ";
            char in;
            cin >> in;
            if (in == 'M') { break;}
        }
    
    }
    
}

void CircularDoublyLinkedList::display_record() {
    system("cls");

    if (head == nullptr)                      // list is empty
    {
        cout << "List is empty!" << endl;
    
        cout << "Input 'M' to continue: ";    // system pause
        char in;
        cin >> in;
        return;
    } else
    {
        student *current = head;
        char input;
        bool circular = false;

        do
        {

            print(current, circular);

            cout << "Input 'N' to view next record, 'P' to go to previous record, or 'M' to go back to main menu: ";
            cin >> input;
            cout << endl;

            if (input == 'N')                 // next node
            {
                if (current == tail)          // IF NEXT IS DONE ON TAIL... THEN IT CIRCLES BACK
                {
                    circular = true;
                }
                current = current->next;
            } else if (input == 'P')          // prev node
            {
                current = current->prev;
            } else if (input == 'M')
            {
                return;
            }else
            {
                cout << "Invalid Input!" << endl;
            }

            system("cls");                    // clear cmd

        } while (input != 'M');
        
    }
    
}

/*

    MISC FUNCTIONS

*/

int CircularDoublyLinkedList::generate_id() {           // generate new id based on list size;
    int temp = id_num;
    id_num++;
    return temp;
}

student* CircularDoublyLinkedList::search()
{

    string input;

    cout << "Search by ID or NAME: ";
    cin >> input;
    if (input == "ID")
    {
        int id_in;
        cout << "Input ID: ";
        cin >> id_in;

        student* current = head;

        if (current == nullptr)                 // list is empty
        {
            return nullptr;
        }

        do                                      // keep searching until search ID is found
        {
            if (current->id == id_in)           // id found
            {
                return current;
            }
        } while (current != head);

        return nullptr;                         // ID not found         

    }else if (input == "NAME")
    {
        string name_in;
        cout << "Input Name: ";
        cin >> name_in;

        student* current = head;

        if (current == nullptr)                 // list is empty
        {
            return nullptr;
        }

        do                                      // keep searching until search ID is found
        {
            if (current->name == name_in)           // id found
            {
                return current;
            }
        } while (current != head);

        return nullptr;                         // ID not found         
            
    }
    else                                        // invalid input!
    {
        cout << "Invalid input" << endl;
        return nullptr;
    }

}

void CircularDoublyLinkedList::del_node(student* point) {


    if (point == head && point == tail)                 // point is THE ONLY ONE in list (Prevents Display Bug)
    {
        head = nullptr;
        tail = nullptr;
    } else if (point == head)                           // point IS the head
    {
        head = point->next;
        tail->next = head;
        head->prev = tail;
    } else if (point == tail)                           // point IS the tail
    {
        tail = point->prev;
        tail->next = head;
        head->prev = tail;
    } else                                              // point is normal
    {
        point->prev->next = point->next;
        point->next->prev = point->prev;
    }
    
    delete point;                                       // deletes pointer
    
}

void CircularDoublyLinkedList::print(student* point, bool circle) {
    if (circle) { cout << "\033[1;31m";}                            // make text red

    cout << "ID: " << point->id << endl;
    cout << "Name: " << point->name << endl;
    cout << "Age: " << point->age << endl;
    cout << "Grade: " << point->grade << endl;

    if (circle) { cout << "\033[0m";}
}

/*

    MAIN FUNCTION

*/

int main() {

    char input;
    CircularDoublyLinkedList my_list;

    do
    {
        // MAIN MENU    
        cout << "A: Add new record" << endl;
        cout << "R: Remove record" << endl;
        cout << "U: Update record" << endl;
        cout << "D: Display records" << endl;
        cout << "E: Exit" << endl;
        cout << "Input: "; 
        
        cin >> input;

        switch(input) {
        case 'A':
            my_list.add_record();
            break;
        case 'R':
            my_list.remove_record();
            break;
        case 'U':
            my_list.update_record();
            break;
        case 'D':
            my_list.display_record();
            break;
        case 'E':
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }

    system("cls");                                // clears system on windows :D
    
    } while (input != 'E');
    
    cout << "Bye Bye!" << endl;

    return 0;
}