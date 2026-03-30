#include <iostream>
#include <string>
using namespace std;

// Node for Linked List
class Node {
public:
    int id, age, priority;
    string name, disease;
    Node* next;

    Node(int i, string n, int a, string d, int p) {
        id = i;
        name = n;
        age = a;
        disease = d;
        priority = p;
        next = NULL;
    }
};

Node* head = NULL;

// 🔹 Add Patient (Linked List)
void addPatient() {
    int id, age, priority;
    string name, disease;

    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Age: ";
    cin >> age;
    cout << "Enter Disease: ";
    cin >> disease;
    cout << "Enter Priority (1-High, 2-Medium, 3-Low): ";
    cin >> priority;

    Node* newNode = new Node(id, name, age, disease, priority);

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    cout << "Patient Added!\n";
}

// 🔹 Display Patients
void displayPatients() {
    Node* temp = head;
    if (temp == NULL) {
        cout << "No patients!\n";
        return;
    }

    while (temp != NULL) {
        cout << "\nID: " << temp->id;
        cout << "\nName: " << temp->name;
        cout << "\nAge: " << temp->age;
        cout << "\nDisease: " << temp->disease;
        cout << "\nPriority: " << temp->priority << endl;
        temp = temp->next;
    }
}

// 🔹 Search Patient
void searchPatient() {
    int id;
    cout << "Enter ID to search: ";
    cin >> id;

    Node* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            cout << "Patient Found:\n";
            cout << temp->name << " | " << temp->disease << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Patient Not Found!\n";
}

// 🔹 Sort by Priority (Bubble Sort)
void sortPatients() {
    if (head == NULL) return;

    Node* i;
    Node* j;

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->priority > j->priority) {
                swap(i->id, j->id);
                swap(i->name, j->name);
                swap(i->age, j->age);
                swap(i->disease, j->disease);
                swap(i->priority, j->priority);
            }
        }
    }

    cout << "Patients sorted by priority!\n";
}

// 🔹 Queue for Waiting List
class Queue {
    int arr[100];
    int front, rear;

public:
    Queue() {
        front = rear = -1;
    }

    void enqueue(int id) {
        if (rear == 99) {
            cout << "Queue Full\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = id;
        cout << "Added to waiting list\n";
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Empty\n";
            return;
        }
        cout << "Patient ID " << arr[front++] << " served\n";
    }

    void displayQueue() {
        if (front == -1 || front > rear) {
            cout << "No waiting patients\n";
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

Queue q;

// 🔹 Main Menu
int main() {
    int choice;

    do {
        cout << "\n--- Hospital System ---\n";
        cout << "1. Add Patient\n";
        cout << "2. Display Patients\n";
        cout << "3. Search Patient\n";
        cout << "4. Sort by Priority\n";
        cout << "5. Add to Waiting Queue\n";
        cout << "6. Serve Patient\n";
        cout << "7. Display Waiting Queue\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addPatient(); break;
            case 2: displayPatients(); break;
            case 3: searchPatient(); break;
            case 4: sortPatients(); break;
            case 5: {
                int id;
                cout << "Enter Patient ID: ";
                cin >> id;
                q.enqueue(id);
                break;
            }
            case 6: q.dequeue(); break;
            case 7: q.displayQueue(); break;
        }

    } while (choice != 8);

    return 0;
}