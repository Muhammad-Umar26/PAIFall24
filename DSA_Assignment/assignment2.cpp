#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Record {
    int id, age;
    string name;

    Record(int id, string name, int age) : id(id), name(name), age(age) {}

    void printDetails() {
        cout << "Id : " << id << endl << "Name : " << name << endl << "Age : " << age << endl;
    }
};

class BinarySearchTree {
    struct Node {
        Record record;
        Node* left;
        Node* right;

        Node(Record record, Node* left = nullptr, Node* right = nullptr) : record(record), left(left), right(right) {}
    };

    Node* table;

    Node* insert(Node* node, Record& record) {
        if(!node) {
            return new Node(record);
        }

        if(record.id == node->record.id) return node;

        if(record.id < node->record.id) {
            node->left = insert(node->left, record);
        } else {
            node->right = insert(node->right, record);
        }

        return node;
    }

    Node* search(Node* node, int id) {
        if(!node || id == node->record.id) {
            return node;
        }

        if(id < node->record.id) {
            return search(node->left, id);
        }

        return search(node->right, id);
    }

    Node* findMinNode(Node* node) {
        Node* curr = node;
        while(curr->left) {
            curr = curr->left;
        }
        return curr;
    }

    Node* deleteNode(Node* node, int id) {
        if(!node) return node;

        if(id < node->record.id) {
            node->left = deleteNode(node, id);
        } else if(id > node->record.id) {
            node->right = deleteNode(node->right, id);
        } else {
            if(!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            } else if(!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            }

            Node* temp = findMinNode(node->right);
            node->record = temp->record;
            node->right = deleteNode(node->right, temp->record.id);
        }
        return node;
    }

    void inorder(Node* node) {
        if(!node) return;

        inorder(node->left);
        node->record.printDetails();
        inorder(node->right);
    }

    void destroyTree(Node* node) {
        if (!node) return;

        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

    public:
        BinarySearchTree() : table(nullptr) {}

        void insert(Record& record) {
            table = insert(table, record);
        }

        Node* search(int id) {
            return search(table, id);
        }

        void traverse() {
            inorder(table);
        }

        void deleteNode(int id) {
            table = deleteNode(table, id);
        }

        ~BinarySearchTree() {
            destroyTree(table);
        }
};

class AVLTree {
    struct Node {
        Record record;
        int height;
        Node* left;
        Node* right;

        Node(Record record, Node* left = nullptr, Node* right = nullptr, int height = 1) : record(record), left(left), right(right), height(height) {}
    };

    Node* table;

    int getHeight(Node* node) {
        return node ? node->height : 0;
    }

    int getBalance(Node* node) {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    Node* LL_Rotation(Node* node) {
        Node* child = node->left;
        node->left = child->right;
        child->right = node;

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        child->height = max(getHeight(child->left), getHeight(child->right)) + 1;

        return child;
    }

    Node* RR_Rotation(Node* node) {
        Node* child = node->right;
        node->right = child->left;
        child->left = node;

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        child->height = max(getHeight(child->left), getHeight(child->right)) + 1;

        return child;
    }

    Node* insert(Node* node, Record& record) {
        if(!node) {
            return new Node(record);
        }

        if(record.id < node->record.id) {
            node->left = insert(node->left, record);
        } else if(record.id > node->record.id) {
            node->right = insert(node->right, record);
        } else {
            return node;
        }

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

        int balance = getBalance(node);

        if(balance > 1) {
            if(record.id > node->left->record.id) {
                node->left = RR_Rotation(node->left);
            }
            return LL_Rotation(node);
        }

        if(balance < -1) {
            if(record.id < node->right->record.id) {
                node->right = LL_Rotation(node->right);
            }
            return RR_Rotation(node);
        }

        return node;
    }

    Node* search(Node* node, int id) {
        if(!node || id == node->record.id) {
            return node;
        }

        if(id < node->record.id) {
            return search(node->left, id);
        }

        return search(node->right, id);
    }

    Node* findMinNode(Node* node) {
        Node* curr = node;
        while(curr && curr->left) {
            curr = curr->left;
        }
        return curr;
    }

    Node* deleteNode(Node* node, int id) {
        if(!node) return nullptr;

        if(id < node->record.id) {
            node->left = deleteNode(node->left, id);
        } else if(id > node->record.id) {
            node->right = deleteNode(node->right, id); 
        } else {
            if(!node->left) {
                Node* temp = node->right;
                delete node;
                return node->right;
            }

            if(!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = findMinNode(node->right);
            node->record = temp->record;
            node->right = deleteNode(node->right, temp->record.id);
        }

        if(!node) return nullptr;

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

        int balance = getBalance(node);

        if(balance > 1) {
            if(getBalance(node->left) < 0) {
                node->left = RR_Rotation(node->left);
            }
            return LL_Rotation(node);
        }

        if(balance < -1) {
            if(getBalance(node->right) > 0) {
                node->right = LL_Rotation(node->right);
            }
            return RR_Rotation(node);
        }

        return node;
    }

    void inorder(Node* node) {
        if(!node) return;

        inorder(node->left);
        node->record.printDetails();
        inorder(node->right);
    }

    void destroyTree(Node* node) {
        if (!node) return;

        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

    public:
        AVLTree() : table(nullptr) {}

        void insert(Record& record) {
            table = insert(table, record);
        }

        Node* search(int id) {
            return search(table, id);
        }

        void deleteNode(int val) {
            table = deleteNode(table, val);
        }

        void traverse() {
            inorder(table);
            cout << endl;
        }

        ~AVLTree() {
            destroyTree(table);
        }
};

int main() {
    return 0;
}
