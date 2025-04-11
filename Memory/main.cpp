#include <iostream>
using namespace std;
struct Person
{
char name[32];
int id;
};


// create a function above main() called Double that takes in an int pointerparameter
// in the function, multiply the int pointer parameter by 2 and assign itback to the parameter (i = i * 2)
// !! make sure to dereference the pointer to set the value and not set theaddress !!
// call the Double function with the pointer created in the POINTER VARIABLEsection
// output the dereference pointer
// output the int variable created in the REFERENCE section
// did the int variable's value change when using the pointer?

void Double(int *amount) {
    *amount = *amount * 2;
}



// create a function above main() called Square that takes in an int
// in the function, multiply the int parameter by itself and assign it back
// call the Square function with the int variable created in the REFERENCE

void square(int &amount) {
    amount = amount * amount;
}


int main()
{
// ** REFERENCE **
//
// declare an int variable and set the value to some number (less than 10)
    int myNumber = 5;
// declare a int reference and set it to the int variable above
    int &myRef = myNumber;
// output the int variable
    std::cout << "myNumber: " << myNumber << std::endl;
// set the int reference to some number
    myRef = 24;
// output the int variable
    std::cout << "myNumber: " << myNumber << std::endl;
// what happened to the int variable when the reference was changed? (insert answer)
    //The int variable changed with the reference.

// output the address of the int variable
   std::cout << "myNumber address: " <<  std::addressof(myNumber) << std::endl;
// output the address of the int reference
    std::cout << "myRef address: " <<  std::addressof(myRef) << std::endl;
// are the addresses the same or different? (insert answer)
    //Identical, because the reference is just an alias for the variable.

// ** REFERENCE PARAMETER **
//
// create a function above main() called Square that takes in an int
// in the function, multiply the int parameter by itself and assign it back
// call the Square function with the int variable created in the REFERENCE

    square(myNumber);
    std::cout << "myNumber: " << myNumber << std::endl;


// output the int variable to the console
// !! notice how the variable has not changed, this is because we only passedthe value to the function !!
// change the Square function to take a int reference
// !! notice how the calling variable has now changed, this is because we'passed by reference' !!
// !! when a function takes a reference parameter, any changes to the parameter changes the calling variable ""

// ** POINTER VARIABLE **
    int* pointer = nullptr;
    pointer = &myNumber;

    std::cout << "myPointer: " << pointer << std::endl;
//
// declare an int pointer, set it to nullptr (it points to nothing)
// set the int pointer to the address of the int variable created in the REFERENCE section
// output the value of the pointer
// what is this address that the pointer is pointing to?
    //The address of the variable myNumber.
// output the value of the object the pointer is pointing to (dereference thepointer)
    std::cout << "myPointer: " << *pointer << std::endl;
// ** POINTER PARAMETER **
//
// create a function above main() called Double that takes in an int pointerparameter
// in the function, multiply the int pointer parameter by 2 and assign itback to the parameter (i = i * 2)
// !! make sure to dereference the pointer to set the value and not set theaddress !!
// call the Double function with the pointer created in the POINTER VARIABLEsection
    Double(pointer);
    std::cout << "myPointer: " << pointer << std::endl;
    std::cout << "myPointer: " << *pointer << std::endl;
    // Yes, the variables value changed when using the pointer.
// output the dereference pointer
// output the int variable created in the REFERENCE section
// did the int variable's value change when using the pointer?
}