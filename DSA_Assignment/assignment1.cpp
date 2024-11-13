#include <iostream>
#include <ctime> // had to use for creation time and close time
#include <string>
#include <unordered_map> //had to use it for a single function. Used only once
#include <algorithm>     // only used for swapping and thats it
#include "config.cpp" //including the config file

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

// Res stack class
class ResolutionStack
{
private:
    Node *top;

public:
    ResolutionStack()
    {
        top = nullptr;
    }
    // Each of these operations will take o(1) t.c

    void push(int ticketId)
    {
        Node *newNode = new Node(ticketId);
        newNode->next = top;
        top = newNode;
        cout << "Ticket with id no: " << ticketId << "successsfully resolved and added to resolutuon stack" << endl;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow. No element to pop." << endl;
            return -1;
        }
        int poppedValue = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
        cout << poppedValue << " popped from stack." << endl;
        return poppedValue;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty. No element to peek." << endl;
            return -1;
        }
        return top->data;
    }
    
    // will take o(n)t.c where n is the size of stack
    void display()
    {
        Node *current = top;
        cout << "Stack contents: ";

        ResolutionStack tempStack;

        while (current != nullptr)
        {
            cout << current->data << " ";
            tempStack.push(current->data);
            current = current->next;
        }

        cout << endl;

        while (!tempStack.isEmpty())
        {
            push(tempStack.peek());
            tempStack.pop();
        }
    }
};

// Classes for tickets

class Ticket
{
public:
    string customerName;
    int priority;
    string serviceRequestDescription;
    time_t creationTime;
    time_t closeTime;
    Ticket *next;
    int ticketId;
    bool status;
    bool assigned;

    Ticket(string customerName, int priority, string serviceRequestDescription, int ticketId, time_t creationTime = time(nullptr), bool assigned = false)
    {
        this->customerName = customerName;
        this->priority = priority;
        this->serviceRequestDescription = serviceRequestDescription;
        this->creationTime = creationTime;
        this->next = nullptr;
        this->ticketId = ticketId;
        this->status = true;
        this->assigned = assigned;
    }
    Ticket()
    {
    }
};

class Tickets
{
public:
    Ticket *head;
    int size;

    Tickets()
    {
        head = nullptr;
    }

    void insertAtTail(string customerName, int priority, string serviceRequestDescription, int ticketId, time_t creationTime = time(nullptr), bool assigned = false)
    {
        size++;
        Ticket *newTicket = new Ticket(customerName, priority, serviceRequestDescription, ticketId, creationTime, assigned);

        if (head == nullptr)
        {
            head = newTicket;
        }
        else
        {
            Ticket *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newTicket;
        }
        cout << "Ticket with id no " << ticketId << " added at tail. Creation Time: " << ctime(&newTicket->creationTime);
    }

    void insertAtHead(string customerName, int priority, string serviceRequestDescription, int ticketId)
    {
        size++;
        Ticket *newTicket = new Ticket(customerName, priority, serviceRequestDescription, ticketId);

        if (head == nullptr)
        {
            head = newTicket;
        }
        else
        {
            newTicket->next = head;
            head = newTicket;
        }
        cout << "Ticket added at head. Creation Time: " << ctime(&newTicket->creationTime);
    }

    void insertAtAnyPosition(int pos, string customerName, int priority, string serviceRequestDescription, int ticketId)
    {
        Ticket *newTicket = new Ticket(customerName, priority, serviceRequestDescription, ticketId);
        if (pos == 0)
        {
            insertAtHead(customerName, priority, serviceRequestDescription, ticketId);
            return;
        }

        Ticket *temp = head;
        for (int i = 0; i < pos - 1 && temp != nullptr; i++)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Position out of range\n";
            return;
        }

        newTicket->next = temp->next;
        temp->next = newTicket;

        cout << "Ticket added at position " << pos << ". Creation Time: " << ctime(&newTicket->creationTime);
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "No tickets to display.\n";
            return;
        }

        Ticket *temp = head;
        while (temp != nullptr)
        {
            cout << "Customer Name: " << temp->customerName << "\n";
            cout << "Priority: " << temp->priority << "\n";
            cout << "Service Request: " << temp->serviceRequestDescription << "\n";
            cout << "Creation Time: " << ctime(&temp->creationTime);
            cout << "Ticket Id: " << temp->ticketId << endl;
            if (temp->status == true)
            {
                cout << "Ticket is open" << endl;
            }
            else
            {
                cout << "Ticket is closed" << endl;
            }
            if (temp->assigned == true)
            {
                cout << "Ticket is assgined to some agent" << endl;
            }
            else
            {
                cout << "Ticket is not assigned" << endl;
            }
            cout << "-------------------------\n";

            temp = temp->next;
        }
    }

    void deleteAtHead()
    {
        if (head == nullptr)
        {
            cout << "No tickets to delete.\n";
            return;
        }

        Ticket *temp = head;
        head = head->next;
        cout << "Ticket deleted at head. Customer Name: " << temp->customerName << "\n";
        delete temp;
    }

    void deleteById(int ticketId)
    {
        if (head == nullptr)
        {
            cout << "No tickets to delete.\n";
            return;
        }

        if (head->ticketId == ticketId)
        {
            deleteAtHead();
            return;
        }

        Ticket *temp = head;
        Ticket *prev = nullptr;

        while (temp != nullptr && temp->ticketId != ticketId)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Ticket with ID " << ticketId << " not found.\n";
            return;
        }

        prev->next = temp->next;
        cout << "Ticket with ID " << ticketId << " deleted. Customer Name: " << temp->customerName << "\n";
        delete temp;
    }

    void deleteAtTail()
    {
        if (head == nullptr)
        {
            cout << "No tickets to delete.\n";
            return;
        }
        size--;

        if (head->next == nullptr)
        {
            deleteAtHead();
            return;
        }

        Ticket *temp = head;
        Ticket *prev = nullptr;
        while (temp->next != nullptr)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = nullptr;
        cout << "Ticket deleted at tail. Customer Name: " << temp->customerName << "\n";
        delete temp;
    }

    Ticket *getNotAssignedTickets()
    {
        Ticket *dummyNode = new Ticket();
        Ticket *curr = dummyNode;
        Ticket *temp = head;
        while (temp != NULL)
        {
            if (temp->assigned == false)
            {
                curr->next = temp;
                curr = curr->next;
            }
            temp = temp->next;
        }
        return dummyNode->next;
    }
};

// Helper functions for tickets including searching and sorting

// max t.c will be size of ll so o(n)
Ticket *getNthNode(Ticket *head, int pos)
{
    int cnt = 0;
    Ticket *temp = head;
    while (temp != NULL && cnt < pos)
    {
        cnt++;
        temp = temp->next;
    }
    return temp;
}

// t.c o(nlogn) for both the searches since its binary search
Ticket *binarySearchByID(Ticket *head, int ticketID)
{
    int size = 0;
    Ticket *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        size++;
    }
    int left = 0, right = size - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (getNthNode(head, mid)->ticketId == ticketID)
        {
            return getNthNode(head, mid);
        }
        if (getNthNode(head, mid)->ticketId > ticketID)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return NULL;
}

Ticket *binarySearchByName(Ticket *head, const string &customerName)
{
    int size = 0;
    Ticket *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        size++;
    }
    int left = 0, right = size - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (getNthNode(head, mid)->customerName == customerName)
        {
            return getNthNode(head, mid);
        }
        if (getNthNode(head, mid)->customerName > customerName)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return NULL;
}

Ticket *getTail(Ticket *head)
{
    Ticket *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        temp = temp->next;
    }
    return temp;
}

Ticket *partition(Ticket *head, Ticket *tail, int criteria)
{
    Ticket *pivot = head;      // The pivot is the head
    Ticket *curr = head->next; // Start checking from the second element
    Ticket *prev = head;       // Last element smaller than pivot

    while (curr != tail->next)
    {
        if ((criteria == 1 && curr->priority < pivot->priority) ||
            (criteria == 2 && curr->creationTime < pivot->creationTime) ||
            (criteria == 3 && curr->customerName < pivot->customerName) ||
            (criteria == 4 && curr->ticketId < pivot->ticketId))
        {
            // Move prev forward and swap fields with curr
            prev = prev->next;
            swap(prev->ticketId, curr->ticketId);
            swap(prev->customerName, curr->customerName);
            swap(prev->priority, curr->priority);
            swap(prev->creationTime, curr->creationTime);
            swap(prev->status, curr->status);
            swap(prev->assigned, curr->assigned);
            swap(prev->serviceRequestDescription, curr->serviceRequestDescription);
            swap(prev->closeTime, curr->closeTime);
        }
        curr = curr->next;
    }

    // Finally, swap the pivot with the last smaller element
    swap(head->ticketId, prev->ticketId);
    swap(head->customerName, prev->customerName);
    swap(head->priority, prev->priority);
    swap(head->creationTime, prev->creationTime);
    swap(head->status, prev->status);
    swap(head->assigned, prev->assigned);
    swap(head->serviceRequestDescription, prev->serviceRequestDescription);
    swap(head->closeTime, prev->closeTime);

    return prev; // Return the pivot's final position
}

void solveSort(Ticket *head, Ticket *tail, int criteria)
{
    // single element or null
    if (head == NULL || head == tail)
        return;

    Ticket *pivot = partition(head, tail, criteria);
    solveSort(head, pivot, criteria);
    solveSort(pivot->next, tail, criteria);
}

Ticket *quickSort(Ticket *head, int criteria)
{
    // code here
    Ticket *temp = head;
    // single element or null
    if (temp == NULL || temp->next == NULL)
        return head;
    Ticket *tail = getTail(head);
    solveSort(head, tail, criteria);
    return head;
}

// mergesort will take o(nlogn )t.c

Ticket *mergeTicket(Ticket *left, Ticket *right, int criteria)
{
    Ticket *ans = NULL;
    Ticket *temp = NULL;

    while (left != NULL && right != NULL)
    {
        if ((left->priority < right->priority && criteria == 1) ||
            (left->creationTime < right->creationTime && criteria == 2) ||
            (left->customerName < right->customerName && criteria == 3) ||
            (left->ticketId < right->ticketId && criteria == 4))
        {
            if (ans == NULL)
            {
                ans = left;
                temp = left;
            }
            else
            {
                temp->next = left;
                temp = left;
            }
            left = left->next;
        }
        else
        {
            if (ans == NULL)
            {
                ans = right;
                temp = right;
            }
            else
            {
                temp->next = right;
                temp = right;
            }
            right = right->next;
        }
    }

    while (left != NULL)
    {
        if (ans == NULL)
        {
            ans = left;
            temp = left;
        }
        else
        {
            temp->next = left;
            temp = left;
        }
        left = left->next;
    }

    while (right != NULL)
    {
        if (ans == NULL)
        {
            ans = right;
            temp = right;
        }
        else
        {
            temp->next = right;
            temp = right;
        }
        right = right->next;
    }

    return ans;
}

// Helper function to find the middle of the linked list
Ticket *getMid(Ticket *head)
{
    Ticket *fast = head->next;
    Ticket *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

// Merge sort function for linked list based on the given criteria
Ticket *sortList(Ticket *head, int criteria)
{
    if (head == NULL || head->next == NULL)
        return head;

    Ticket *mid = getMid(head);
    Ticket *left = head;
    Ticket *right = mid->next;
    mid->next = NULL;

    left = sortList(left, criteria);
    right = sortList(right, criteria);

    Ticket *result = mergeTicket(left, right, criteria);
    return result;
}

// each of three sorting algos will take o(n^2) t.c
void bubbleSort(int criteria, Ticket *head)
{
    if (!head)
        return;

    bool swapped;
    do
    {
        swapped = false;
        Ticket *current = head;

        while (current && current->next)
        {
            bool condition = false;
            if (criteria == 1)
            {
                condition = (current->priority > current->next->priority);
            }
            else if (criteria == 2)
            {
                condition = (current->creationTime > current->next->creationTime);
            }
            else if (criteria == 3)
            {
                condition = (current->customerName > current->next->customerName);
            }
            else if (criteria == 4)
            {
                condition == (current->ticketId > current->next->ticketId);
            }

            if (condition == true)
            {

                swap(current->ticketId, current->next->ticketId);
                swap(current->customerName, current->next->customerName);
                swap(current->priority, current->next->priority);
                swap(current->serviceRequestDescription, current->next->serviceRequestDescription);
                swap(current->creationTime, current->next->creationTime);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

void selectionSort(int criteria, Ticket *head)
{
    if (head == NULL || head->next == NULL)
        return;

    Ticket *current = head;
    while (current)
    {
        Ticket *minNode = current;
        Ticket *temp = current->next;
        while (temp)
        {
            bool condition = false;
            if (criteria == 1)
            {
                condition = (temp->priority < minNode->priority);
            }
            else if (criteria == 2)
            {
                condition = (temp->creationTime < minNode->creationTime);
            }
            else if (criteria == 3)
            {
                condition = (temp->customerName < minNode->customerName);
            }
            else if (criteria == 4)
            {
                condition = (temp->ticketId < minNode->ticketId);
            }

            if (condition)
            {
                minNode = temp;
            }
            temp = temp->next;
        }
        if (minNode != current)
        {
            swap(current->ticketId, minNode->ticketId);
            swap(current->customerName, minNode->customerName);
            swap(current->priority, minNode->priority);
            swap(current->serviceRequestDescription, minNode->serviceRequestDescription);
            swap(current->creationTime, minNode->creationTime);
        }
        current = current->next;
    }
}

void insertionSort(int criteria, Ticket *head)
{
    if (head == NULL || head->next == NULL)
        return;

    Ticket *sorted = NULL;
    Ticket *current = head;

    while (current)
    {
        Ticket *nextNode = current->next;

        if (sorted == NULL || (criteria == 1 && current->priority <= sorted->priority) ||
            (criteria == 2 && current->creationTime <= sorted->creationTime) ||
            (criteria == 3 && current->customerName <= sorted->customerName) ||
            (criteria == 4 && current->ticketId <= sorted->ticketId))
        {
            current->next = sorted;
            sorted = current;
        }
        else
        {
            Ticket *temp = sorted;
            while (temp->next && ((criteria == 1 && temp->next->priority > current->priority) ||
                                  (criteria == 2 && temp->next->creationTime < current->creationTime) ||
                                  (criteria == 3 && temp->next->customerName < current->customerName) || (criteria == 4 && temp->next->ticketId < current->ticketId)))
            {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = nextNode;
    }
    head = sorted;
}

// Relevant functions and classes related to agents

class Agent
{
private:
    int agentID;
    string name;

    bool availability;
    int assignedTicketsCount;

public:
    Tickets *assignedTickets;
    
    Agent(int agentID, string name)
    {
        this->agentID = agentID;
        this->name = name;
        this->availability = true;
        assignedTickets = new Tickets();
        assignedTicketsCount = 0;
    }

    Agent(){}

    void addAssignedTicket(string customerName, int priority, string serviceRequestDescription, int ticketId, time_t creationTime)
    {
        assignedTicketsCount++;
        if (assignedTicketsCount >= 5)
        {
            this->availability = false;
        }
        assignedTickets->insertAtTail(customerName, priority, serviceRequestDescription, ticketId, creationTime, false);
    }

    // This function will close all tickets the agent has been assigned
    void closeTicket(ResolutionStack &st)
    {
        for (int i = 0; i < assignedTicketsCount; i++)
        {

            Ticket *ticket = getNthNode(assignedTickets->head, i + 1);
            if (ticket == NULL)
            {
                continue;
            }
            if (ticket->status == false)
            {
                cout << "Ticket with id no " << ticket->ticketId << " already closed " << endl;
            }
            else
            {
                ticket->status = false; // clsoed
                ticket->closeTime = time(nullptr);
                cout << "Ticket with id no " << ticket->ticketId << " closed at " << ctime(&ticket->closeTime);
                st.push(ticket->ticketId);
            }
        }
    }

    int getAgentID() const { return agentID; }
    void setAgentID(int agentID) { this->agentID = agentID; }

    string getName() const { return name; }
    void setName(const string &name) { this->name = name; }

    Tickets *getTickets() const { return assignedTickets; }
    void setTickets(Tickets *tickets) { this->assignedTickets = tickets; }

    bool isAvailable() const { return availability; }
    void setAvailability(bool availability) { this->availability = availability; }

    int getAssignedTicketsCount() const { return assignedTicketsCount; }
};

class Agents
{
public:
    Agent *agents;
    int size;
    
    Agents()
    {
        size = 0;
        agents = new Agent[size];
    }
    
    void addAgent(Agent *agentToAdd)
    {
        size++;
        Agent *temp = new Agent[size];
        for (int i = 0; i < size - 1; i++)
        {
            temp[i] = agents[i];
        }
        temp[size - 1] = *agentToAdd;
        agents = temp;
    }
    
    bool agentExists(int id)
    {
        for (int i = 0; i < size; i++)
        {
            if (agents[i].getAgentID() == id)
            {
                return true;
            }
        }
        return false;
    }
    
    void printAgents() const
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Agent ID: " << agents[i].getAgentID() << endl;
            cout << "Name: " << agents[i].getName() << endl;
            cout << "Availability: " << (agents[i].isAvailable() ? "Available" : "Not Available") << endl;

            cout << "--------------------------" << endl;
        }
    }
    
    void printAssignedTickets()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Displaying info of assgined tickets for " << agents[i].getName() << endl;
            Tickets *temp = agents[i].assignedTickets;
            Ticket *tempHead = temp->head;
            while (tempHead != NULL)
            {
                cout << "Ticket Id: " << tempHead->ticketId << endl;
                tempHead = tempHead->next;
            }
        }
    }
    
    void assignTicketToAgent(Tickets &tickets)
    {
        Agent *bestAgent = nullptr;
        if (threshold < 100)
        {
            int algo = elementarySortingAlgorithm;
            switch (algo)
            {
            case 0:
                bubbleSort(1, tickets.head);
                break;
            case 1:
                insertionSort(1, tickets.head);
                break;
            case 2:
                selectionSort(1, tickets.head);
                break;
            default:
                cout << "Invalud" << endl;
                break;
            }
        }
        else
        {
            sortList(tickets.head, 1);
        }

        unordered_map<Ticket *, int> mp;
        Ticket *temp = tickets.head;

        // Populate the map with tickets
        while (temp != NULL)
        {
            mp[temp] = 1;      // Mark ticket as available
            temp = temp->next; // Move to the next ticket
        }

        for (int i = 0; i < size; i++)
        {
            Ticket *temp = tickets.head; // Reset temp for each agent
            while (temp != NULL)
            {
                if (agents[i].isAvailable() && agents[i].getAssignedTicketsCount() < 5)
                {
                    if (mp[temp] == 1) // Check if ticket is available
                    {
                        temp->assigned = true;
                        // Extract ticket details

                        string customerName = temp->customerName;
                        int priority = temp->priority;
                        string serviceRequestDescription = temp->serviceRequestDescription;
                        time_t creationTime = temp->creationTime;
                        time_t closeTime = temp->closeTime;
                        int ticketId = temp->ticketId;

                        // Assign the ticket to the agent
                        agents[i].addAssignedTicket(customerName, priority, serviceRequestDescription, ticketId, creationTime);
                        mp[temp] = 0; // Mark ticket as assigned
                    }
                }
                temp = temp->next; // Move to the next ticket
            }
        }
    }

    void displayTotalAssignedTickets()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Total assigned tickets for agent with id " << agents[i].getAgentID() << "is " << agents[i].getAssignedTicketsCount() << endl;
        }
    }
};

// Each of the three sorting algos will take o(n^2) t.c
void bubbleSortByAssignedTickets(Agent *arr, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (arr[j].getAssignedTicketsCount() > arr[j + 1].getAssignedTicketsCount())
            {
                // Swap
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertionSortByAssignedTickets(Agent *arr, int size)
{
    for (int i = 1; i < size; ++i)
    {
        Agent key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key
        while (j >= 0 && arr[j].getAssignedTicketsCount() > key.getAssignedTicketsCount())
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSortByAssignedTickets(Agent *arr, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (arr[j].getAssignedTicketsCount() < arr[minIndex].getAssignedTicketsCount())
            {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element
        swap(arr[minIndex], arr[i]);
    }
}

void merge(Agent *arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Agent *leftArr = new Agent[n1];
    Agent *rightArr = new Agent[n2];

    for (int i = 0; i < n1; ++i)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        rightArr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (leftArr[i].getAssignedTicketsCount() <= rightArr[j].getAssignedTicketsCount())
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    delete[] leftArr;
    delete[] rightArr;
}

void mergeSortByAssignedTickets(Agent *arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSortByAssignedTickets(arr, left, mid);
        mergeSortByAssignedTickets(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int partition(Agent *arr, int low, int high)
{
    int pivot = arr[high].getAssignedTicketsCount();
    int i = low - 1;

    for (int j = low; j < high; ++j)
    {
        if (arr[j].getAssignedTicketsCount() < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortByAssignedTickets(Agent *arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSortByAssignedTickets(arr, low, pi - 1);
        quickSortByAssignedTickets(arr, pi + 1, high);
    }
}

// queue classes and functions

class Queue
{
private:
    Ticket *front;
    Ticket *rear;

public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }
    // Each of enque deque isEmpty operation will take o(1) t.c

    void enqueue(Ticket *ticket)
    {
        string customerName = ticket->customerName;
        int priority = ticket->priority;
        string serviceRequestDescription = ticket->serviceRequestDescription;
        time_t creationTime = ticket->creationTime;
        int ticketId = ticket->ticketId;
        Ticket *newTicket = new Ticket(customerName, priority, serviceRequestDescription, ticketId, creationTime);
        if (rear == nullptr)
        {
            front = rear = newTicket;
            return;
        }
        rear->next = newTicket;
        rear = newTicket;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        Ticket *temp = front;
        front = front->next;
        if (front == nullptr)
        {
            rear = nullptr;
        }
        delete temp;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->ticketId;
    }

    // will take o(n) t.c
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        Ticket *temp = front;
        while (temp != nullptr)
        {
            cout << "TicketId: " << temp->ticketId << endl;
            temp = temp->next;
        }
        cout << endl;
    }
};

// Helper function for close tickets
void modifyOpenTickets(Agent agent, Tickets &tickets)
{
    Ticket *tempAssignedAgent = agent.assignedTickets->head;
    Ticket *tempTicket = tickets.head;
    while (tempTicket != NULL)
    {
        tempAssignedAgent = agent.assignedTickets->head;

        while (tempAssignedAgent != NULL)
        {
            if (tempTicket->ticketId == tempAssignedAgent->ticketId)
            {
                tempTicket->status = false;
            }
            tempAssignedAgent = tempAssignedAgent->next;
        }
        tempTicket = tempTicket->next;
    }
}

Ticket *getOpenTickets(Ticket *head)
{
    Ticket *dummyNode = new Ticket();
    Ticket *curr = dummyNode;
    Ticket *temp = head;
    while (temp != NULL)
    {
        if (temp->status == true)
        {
            curr->next = temp;
            curr = temp;
        }
        temp = temp->next;
    }
    return dummyNode->next;
}

int main()
{
    ResolutionStack res;
    Queue pendingQueue;
    Tickets ticketList;
    Agent *agentIt = new Agent(1, "Micheal");
    Agent *agentAdmin = new Agent(2, "Ahmed");
    Agent *accountsAgent = new Agent(3, "Aslam");
    Agent *academicAgent1 = new Agent(4, "Saleh");
    Agent *academicAgent2 = new Agent(5, "Mufeez");
    Agent *academicAgent3 = new Agent(6, "AbdurRehman");
    Agents agentList;
    agentList.addAgent(agentIt);
    agentList.addAgent(agentAdmin);
    agentList.addAgent(accountsAgent);
    agentList.addAgent(academicAgent1);
    agentList.addAgent(academicAgent2);
    agentList.addAgent(academicAgent3);

    // Add initial tickets
    ticketList.insertAtTail("Alice", 1, "Login issue", 1);
    ticketList.insertAtTail("Bob", 2, "Password reset", 2);
    ticketList.insertAtTail("Charlie", 3, "Hardware issue", 3);
    ticketList.insertAtTail("David", 1, "Email not working", 4);
    ticketList.insertAtTail("Eva", 2, "Network issue", 5);
    ticketList.insertAtTail("Frank", 3, "Slow system performance", 6);
    ticketList.insertAtTail("Grace", 1, "Software installation", 7);
    ticketList.insertAtTail("Helen", 2, "Monitor not working", 8);
    ticketList.insertAtTail("Ivy", 3, "Keyboard issue", 9);
    ticketList.insertAtTail("Jack", 1, "Printer not connecting", 10);
    ticketList.insertAtTail("Karen", 2, "Application crash", 11);
    ticketList.insertAtTail("Leo", 3, "Touchpad not working", 12);
    ticketList.insertAtTail("Mia", 1, "Projector issue", 13);
    int choice = -1;
    int ticketDeletionId;

    while (choice != 0)
    {

        int ticketChoice = -1;
        int agentChoice = -1;
        int ticketResChoice = -1;
        int reportChoice = -1;
        Ticket *tempQueue = NULL;
        Ticket *openTicketsHead = NULL;
        string name;
        cout << "Welcome to the one stop management system" << endl;
        cout << "Press 1 for tickets menu, 2 for agents menu, 3 for ticket resolution log, 4 for report menu, or 0 to exit." << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            ticketChoice = -1; // Reset ticketChoice for every menu access
            while (ticketChoice != 0)
            {
                cout << "Tickets Menu: 1. Add ticket, 2. Remove ticket, 3. Search by ID, 4. Search by customer name, 5. Sort by priority, 6. Sort by creation time, 7. Sort by customer name, 8. Display all tickets, 0. Exit to main menu." << endl;
                cin >> ticketChoice;

                Ticket *foundTicket = nullptr;
                switch (ticketChoice)
                {
                case 1:
                {
                    string customerName, description;
                    int priority, ticketId;
                    cout << "Enter customer name: ";
                    cin >> customerName;
                    cout << "Enter ticket ID (unique): ";
                    cin >> ticketId;
                    cout << "Enter service request description: ";
                    cin >> description;
                    cout << "Enter ticket priority: ";
                    cin >> priority;
                    ticketList.insertAtTail(customerName, priority, description, ticketId);
                }
                break;
                case 2:
                    cout << "Enter ticket id you want to delete " << endl;
                    cin >> ticketDeletionId;
                    ticketList.deleteById(ticketDeletionId);
                    break;
                case 3:
                {
                    int id;
                    cout << "Enter the ID of the ticket to search: ";
                    cin >> id;
                    if (threshold < 100)
                    {
                        int algo = elementarySortingAlgorithm;
                        switch (algo)
                        {
                        case 0:
                            bubbleSort(4, ticketList.head);
                            cout << "Bubble sort performed." << endl;
                            break;
                        case 1:
                            insertionSort(4, ticketList.head);
                            cout << "Insertion sort performed." << endl;
                            break;
                        case 2:
                            selectionSort(4, ticketList.head);
                            cout << "Selection sort performed." << endl;
                            break;
                        default:
                            cout << "Invalid sorting algorithm." << endl;
                            break;
                        }
                    }
                    else
                    {
                        int algo = advancedSortingAlgorithm;
                        switch (algo)
                        {
                        case 3:
                            sortList(ticketList.head, 4);
                            cout << "Merge sort performed." << endl;
                            break;
                        case 4:
                            quickSort(ticketList.head, 4);
                            cout << "Quick Sort perfomed" << endl;
                            break;
                        default:
                            cout << "Invalid" << endl;
                            break;
                        }
                    }
                    foundTicket = binarySearchByID(ticketList.head, id);
                    if (foundTicket == nullptr)
                    {
                        cout << "Ticket with ID " << id << " not found." << endl;
                    }
                    else
                    {
                        cout << "Ticket found. Customer Name: " << foundTicket->customerName << endl;
                    }
                }
                break;
                case 4:
                    // Search by customer name logic

                    cout << "Enter the customer name of the ticket to search: ";
                    cin >> name;
                    if (threshold < 100)
                    {
                        int algo = elementarySortingAlgorithm;
                        switch (algo)
                        {
                        case 0:
                            bubbleSort(3, ticketList.head);
                            cout << "Bubble sort performed." << endl;
                            break;
                        case 1:
                            insertionSort(3, ticketList.head);
                            cout << "Insertion sort performed." << endl;
                            break;
                        case 2:
                            selectionSort(3, ticketList.head);
                            cout << "Selection sort performed." << endl;
                            break;
                        default:
                            cout << "Invalid sorting algorithm." << endl;
                            break;
                        }
                    }
                    else
                    {
                        int algo = advancedSortingAlgorithm;
                        switch (algo)
                        {
                        case 3:
                            sortList(ticketList.head, 3);
                            cout << "Merge sort performed." << endl;
                            break;
                        case 4:
                            quickSort(ticketList.head, 3);
                            cout << "Quick Sort perfomed" << endl;
                            break;
                        default:
                            cout << "Invalid" << endl;
                            break;
                        }
                    }
                    foundTicket = binarySearchByName(ticketList.head, name);
                    if (foundTicket == nullptr)
                    {
                        cout << "Ticket with customer name " << name << " not found." << endl;
                    }
                    else
                    {
                        cout << "Ticket found. Customer Name: " << foundTicket->customerName << " and id: " << foundTicket->ticketId << endl;
                    }
                    break;
                case 5:
                {

                    if (threshold < 100)
                    {
                        int algo = elementarySortingAlgorithm;
                        switch (algo)
                        {
                        case 0:
                            bubbleSort(1, ticketList.head);
                            cout << "Bubble sort performed." << endl;
                            break;
                        case 1:
                            insertionSort(1, ticketList.head);
                            cout << "Insertion sort performed." << endl;
                            break;
                        case 2:
                            selectionSort(1, ticketList.head);
                            cout << "Selection sort performed." << endl;
                            break;
                        default:
                            cout << "Invalid sorting algorithm." << endl;
                            break;
                        }
                    }
                    else
                    {
                        int algo = advancedSortingAlgorithm;
                        switch (algo)
                        {
                        case 3:
                            sortList(ticketList.head, 1);
                            cout << "Merge sort performed." << endl;
                            break;
                        case 4:
                            quickSort(ticketList.head, 1);
                            cout << "Quick Sort perfomed" << endl;
                            break;
                        default:
                            cout << "Invalid" << endl;
                            break;
                        }
                    }
                }
                break;

                case 6:
                    if (threshold < 100)
                    {
                        int algo = elementarySortingAlgorithm;
                        switch (algo)
                        {
                        case 0:
                            bubbleSort(2, ticketList.head);
                            cout << "Bubble sort performed." << endl;
                            break;
                        case 1:
                            insertionSort(2, ticketList.head);
                            cout << "Insertion sort performed." << endl;
                            break;
                        case 2:
                            selectionSort(2, ticketList.head);
                            cout << "Selection sort performed." << endl;
                            break;
                        default:
                            cout << "Invalid sorting algorithm." << endl;
                            break;
                        }
                    }
                    else
                    {
                        int algo = advancedSortingAlgorithm;
                        switch (algo)
                        {
                        case 3:
                            sortList(ticketList.head, 1);
                            cout << "Merge sort performed." << endl;
                            break;
                        case 4:
                            quickSort(ticketList.head, 1);
                            cout << "Quick Sort perfomed" << endl;
                            break;
                        default:
                            cout << "Invalid" << endl;
                            break;
                        }
                    }

                    break;
                case 7:
                    if (threshold < 100)
                    {
                        int algo = elementarySortingAlgorithm;
                        switch (algo)
                        {
                        case 0:
                            bubbleSort(3, ticketList.head);
                            cout << "Bubble sort performed." << endl;
                            break;
                        case 1:
                            insertionSort(3, ticketList.head);
                            cout << "Insertion sort performed." << endl;
                            break;
                        case 2:
                            selectionSort(3, ticketList.head);
                            cout << "Selection sort performed." << endl;
                            break;
                        default:
                            cout << "Invalid sorting algorithm." << endl;
                            break;
                        }
                    }
                    else
                    {
                        int algo = advancedSortingAlgorithm;
                        switch (algo)
                        {
                        case 3:
                            sortList(ticketList.head, 1);
                            cout << "Merge sort performed." << endl;
                            break;
                        case 4:
                            quickSort(ticketList.head, 1);
                            cout << "Quick Sort perfomed" << endl;
                            break;
                        default:
                            cout << "Invalid" << endl;
                            break;
                        }
                    }
                case 8:
                    ticketList.display();
                    break;
                default:
                    ticketChoice = 0; // Exit menu on invalid choice
                    break;
                }
            }
            break;

        case 2:
            agentChoice = -1; // Reseting agentChoice for every menu access
            while (agentChoice != 0)
            {
                cout << "Agents Menu: 1. Add agent, 2. Assign open tickets, 3. Display agents, 4. Close agent tickets, 0. Exit to main menu." << endl;
                cin >> agentChoice;

                switch (agentChoice)
                {
                case 1:
                {
                    string name;
                    int id;
                    cout << "Enter agent name: ";
                    cin >> name;
                    cout << "Enter agent ID: ";
                    cin >> id;
                    if (agentList.agentExists(id))
                    {
                        cout << "Agent with ID " << id << " already exists. Try again." << endl;
                    }
                    else
                    {
                        Agent *temp = new Agent(id, name);
                        agentList.addAgent(temp);
                        cout << "Agent added." << endl;
                    }
                }
                break;
                case 2:
                    agentList.assignTicketToAgent(ticketList);
                    cout << "Tickets successfully assigned." << endl;
                    break;
                case 3:
                    agentList.printAgents();
                    agentList.displayTotalAssignedTickets();
                    break;
                case 4:
                    // Implementing logic to close all tickets for a particular agent
                    int id;
                    cout << "Enter id of agent of which you want to close all assigned tickets of " << endl;
                    cin >> id;
                    if (agentList.agentExists(id) == false)
                    {
                        cout << "Agent with id no does not exist" << endl;
                    }
                    else
                    {
                        for (int i = 0; i < agentList.size; i++)
                        {
                            if (agentList.agents[i].getAgentID() == id)
                            {
                                agentList.agents[i].closeTicket(res);
                                modifyOpenTickets(agentList.agents[i], ticketList);
                            }
                        }
                    }

                    break;
                default:
                    agentChoice = 0; // Exiting menu on invalid choice
                    break;
                }
            }
            break;

        case 3:
            while (ticketResChoice != 0)
            {
                cout << "Welcome to ticket resolution log menu." << endl;
                cout << "Press 1 to see the ticket resolution log(History of ticket closed)" << endl;
                cout << "Presss 2 to initialize and show pending Queue" << endl;
                cout << "Press any other number to exit to main menu " << endl;
                cin >> ticketResChoice;
                switch (ticketResChoice)
                {
                case 1:
                    cout << "Displaying resolution log" << endl;
                    res.display();
                    break;
                case 2:
                    cout << "Initialzing Pending Queue" << endl;
                    if (threshold < 100)
                    {
                        int algo = elementarySortingAlgorithm;
                        switch (algo)
                        {
                        case 0:
                            bubbleSort(1, ticketList.head);
                            cout << "Bubble sort performed." << endl;
                            break;
                        case 1:
                            insertionSort(1, ticketList.head);
                            cout << "Insertion sort performed." << endl;
                            break;
                        case 2:
                            selectionSort(1, ticketList.head);
                            cout << "Selection sort performed." << endl;
                            break;
                        default:
                            cout << "Invalid sorting algorithm." << endl;
                            break;
                        }
                    }
                    else
                    {
                        int algo = advancedSortingAlgorithm;
                        switch (algo)
                        {
                        case 3:
                            sortList(ticketList.head, 1);
                            cout << "Merge sort performed." << endl;
                            break;
                        case 4:
                            quickSort(ticketList.head, 1);
                            cout << "Quick Sort perfomed" << endl;
                            break;
                        default:
                            cout << "Invalid" << endl;
                            break;
                        }
                    }
                    tempQueue = ticketList.getNotAssignedTickets();
                    if (tempQueue == NULL)
                    {
                        cout << "No free tickets available " << endl;
                    }
                    else
                    {
                        cout << "Free tickets available" << endl;
                    }
                    while (tempQueue != NULL)
                    {
                        pendingQueue.enqueue(tempQueue);
                        tempQueue = tempQueue->next;
                    }
                    pendingQueue.display();

                    break;
                default:
                    ticketResChoice = 0;
                    break;
                }
            }

            break;
        case 4:
            // Implementing report menu
            while (reportChoice != 0)
            {
                cout << "Welcome to report menu" << endl;
                cout << "Press 1 to display all open tickets sorted by priority" << endl;
                cout << "Press 2 to display list of agents and theor currently assigned Tickets. Also sorts the agent based on number of assgined tickets" << endl;
                cout << "Press 3 to display most recent res log" << endl;
                cout << "Press any other number to exit to main Menu" << endl;
                cin >> reportChoice;
                switch (reportChoice)
                {
                case 1:
                    openTicketsHead = getOpenTickets(ticketList.head);
                    if (threshold < 100)
                    {
                        int algo = elementarySortingAlgorithm;
                        switch (algo)
                        {
                        case 0:
                            bubbleSort(1, openTicketsHead);
                            cout << "Bubble sort performed." << endl;
                            break;
                        case 1:
                            insertionSort(1, openTicketsHead);
                            cout << "Insertion sort performed." << endl;
                            break;
                        case 2:
                            selectionSort(1, openTicketsHead);
                            cout << "Selection sort performed." << endl;
                            break;
                        default:
                            cout << "Invalid sorting algorithm." << endl;
                            break;
                        }
                    }
                    else
                    {
                        int algo = advancedSortingAlgorithm;
                        switch (algo)
                        {
                        case 3:
                            sortList(openTicketsHead, 1);
                            cout << "Merge sort performed." << endl;
                            break;
                        case 4:
                            quickSort(openTicketsHead, 1);
                            cout << "Quick Sort perfomed" << endl;
                            break;
                        default:
                            cout << "Invalid" << endl;
                            break;
                        }
                    }
                    while (openTicketsHead != NULL)
                    {
                        cout << "Priority of ticket with id " << openTicketsHead->ticketId << " is " << openTicketsHead->priority << endl;
                        openTicketsHead = openTicketsHead->next;
                    }
                    break;
                case 2:
                    if (threshold < 100)
                    {
                        int algo = elementarySortingAlgorithm;
                        switch (algo)
                        {
                        case 0:
                            bubbleSortByAssignedTickets(agentList.agents, agentList.size);
                            cout << "Bubble sort performed." << endl;
                            break;
                        case 1:
                            insertionSortByAssignedTickets(agentList.agents, agentList.size);
                            cout << "Insertion sort performed." << endl;
                            break;
                        case 2:
                            selectionSortByAssignedTickets(agentList.agents, agentList.size);
                            cout << "Selection sort performed." << endl;
                            break;
                        default:
                            cout << "Invalid sorting algorithm." << endl;
                            break;
                        }
                    }
                    else
                    {
                        int algo = advancedSortingAlgorithm;
                        switch (algo)
                        {
                        case 3:
                            mergeSortByAssignedTickets(agentList.agents, 0, agentList.size - 1);
                            cout << "Merge sort performed." << endl;
                            break;
                        case 4:
                            quickSortByAssignedTickets(agentList.agents, 0, agentList.size - 1);
                            cout << "Quick Sort perfomed" << endl;
                            break;
                        default:
                            cout << "Invalid" << endl;
                            break;
                        }
                    }
                    agentList.printAgents();
                    agentList.printAssignedTickets();
                    break;
                case 3:
                    cout << "Printing id of most recent ticket res log" << endl;
                    cout << "Id no : " << res.peek() << endl;
                    break;
                default:
                    reportChoice = 0;
                    break;
                }
            }
            break;

        case 0:
            cout << "Exiting the system. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid option. Try again." << endl;
            break;
        }
    }

    return 0;
}
