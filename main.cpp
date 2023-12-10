#include <iostream>
#include "homeworkFourDriver.hpp"
using namespace std;

int main(){
        //Create a ChildrenBook object
        ChildrenBook childrenBook("Winnie the Pooh", "A. A. Milne", 10, 5);
        

        // Create a SeriousBook object
        SeriousBook seriousBook("Harry Potter and the Philosopher's Stone", "J.K. Rowling", 300, "Fiction");

        cout << "Children Book type: ";
        childrenBook.type();

        cout << "Serious Book type: ";
        seriousBook.type();

        // Demonstrate the overloaded equality operator
        if (childrenBook == seriousBook) {
            cout << "The two books are the same." << endl;
        } else {
            cout << "The two books are different." << endl;
        }

        return 0;

}

