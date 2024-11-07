#include <iostream>
#include <ctime>

using namespace std;

struct Ticket {
    int ticketId, priority;
    string customerName, serviceRequestDescription;
    time_t creationTime, closeTime;
    bool status;

    Ticket(int ticketId, string customerName, int priority, string serviceRequestDescription) : ticketId(ticketId), customerName(customerName), priority(priority), serviceRequestDescription(serviceRequestDescription), status(false), creationTime(time(0)) {}

    void printDetails() {
        cout << "Ticket Id : " << ticketId << endl << "Customer Name : " << customerName << endl << "Priority : " << priority << endl << "Service Request Description : " << serviceRequestDescription << endl << "Creation time : " << creationTime << endl << "Status : " << (status ? "Open" : "Closed") << endl << "Close time : " << closeTime << endl;
    }
};

class ServiceRequestManagement {
    struct Node {
        Ticket ticket;
        Node* next;

        Node(Ticket ticket, Node* next = nullptr) : ticket(ticket), next(next) {}
    };

    Node* head;

    int getLength(Node* node) {
        if(!node) return 0;

        return 1 + getLength(node->next);
    }

    public:
        ServiceRequestManagement() : head(nullptr) {}

        void addTicket(Ticket ticket) {
            head = new Node(ticket, head);
        }

        void removeTicket(int id) {
            if(head && head->ticket.ticketId == id) {
                Node* temp = head;
                head = head->next;
                delete temp;
                return;
            }

            for(Node* curr = head; curr->next; curr = curr->next) {
                if(curr->next->ticket.ticketId == id) {
                    Node* temp = curr->next;
                    curr->next = curr->next->next;
                    delete temp;
                    return;
                }
            }

            cout << "Ticket with id " << id << " does not exist in the system" << endl;
        }

        void searchTicketById(int id) {
            for(Node* curr = head; curr; curr = curr->next) {
                if(curr->ticket.ticketId == id) {
                    curr->ticket.printDetails();
                    return;
                }
            }
            cout << "Ticket with id " << id << " does not exist in the system" << endl;
        }

        void searchTicketByName(string name) {
            for(Node* curr = head; curr; curr = curr->next) {
                if(curr->ticket.customerName == name) {
                    curr->ticket.printDetails();
                    return;
                }
            }
            cout << "Ticket with customer name " << name << " does not exist in the system" << endl;
        }


};

int main() {
    ServiceRequestManagement s;
    
    return 0;
}
