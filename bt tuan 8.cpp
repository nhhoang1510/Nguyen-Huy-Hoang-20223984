#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node {
    int coefficient;  
    int exponent;     
    Node* next;

    Node(int coef, int exp) : coefficient(coef), exponent(exp), next(NULL) {}
};

class Polynomial {
private:
    Node* head;
public:
    Polynomial() : head(NULL) {}
    ~Polynomial() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void addTerm(int coefficient, int exponent) {
        if (coefficient == 0) return;

        Node* newNode = new Node(coefficient, exponent);
        
        if (!head || head->exponent < exponent) {
            newNode->next = head;
            head = newNode;
        }
        else {
            Node* current = head;
            Node* previous = NULL;
            while (current && current->exponent > exponent) {
                previous = current;
                current = current->next;
            }
            if (current && current->exponent == exponent) {
                current->coefficient += coefficient;
                if (current->coefficient == 0) { 
                    if (previous) previous->next = current->next;
                    else head = current->next;
                    delete current;
                }
                delete newNode; 
            } 
            else { 
                newNode->next = current;
                if (previous) previous->next = newNode;
            }
        }
    }

    void print() const {
        if (!head) {
            cout << "0\n";
            return;
        }
        Node* temp = head;
        while (temp) {
            if (temp->coefficient > 0 && temp != head) cout << " + ";
            else if (temp->coefficient < 0) cout << " - ";

            cout << abs(temp->coefficient);
            if (temp->exponent > 0) cout << "x^" << temp->exponent;

            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Polynomial poly;
    int coef, exp;

    cout << "Nhap cac he so va so mu cua da thuc (nhap he so 0 de ket thuc):\n";
    while (true) {
        cout << "He so: ";
        cin >> coef;
        if (coef == 0) break;
        cout << "So mu: ";
        cin >> exp;
        poly.addTerm(coef, exp);
    }

    cout << "Da thuc vua nhap: ";
    poly.print();

    return 0;
}

