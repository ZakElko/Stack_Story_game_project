/******************************************************************************
Zakaria Elkhodary 
CISC187_Chapter 19 Programming Assignment- Stack
11/12/24
*******************************************************************************/
#include "storygame.h"
#include <iostream>
#include <limits>
#include <cctype>
#include <algorithm>

using namespace std;

void showMenu() {
    cout << "---------------------------------------------------" << endl;
    cout << " Howdy, please Enter a number from the menu below: " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "1. Enter a word to Push onto the stack (The use of animal terminology may enhance the quality of your story. :) ) " << endl;
    cout << "2. Enter a word to Pop from the stack" << endl;
    cout << "3. Capitalize all of the words on the stack" << endl;
    cout << "4. Display the Stack of words you entered" << endl;
    cout << "5. Enter 5 words and i will create a story for you. " << endl;
    cout << "6. Exit the program, Adios...butter toast. " << endl;
}

int getValidMenuChoice() {
    int selection;
    while (true) {
        cin >> selection;
        if (cin.fail() || selection < 1 || selection > 6) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid Entry Human..... Please enter a number between 1 and 6: ";
        } else {
            break;
        }
    }
    return selection;
}

int main() {
    storygame stack;
    int selection;

    do {
        showMenu();
        selection = getValidMenuChoice();

        switch (selection) {
        case 1: { // Push a word onto the stack
            string word;
            cout << "Enter a word to push (Add) onto the stack (10 characters or less): ";
            cin >> word;
            try {
                stack.push(word);
            } catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
            }
            break;
        }

        case 2: { // Pop a word from the stack
            try {
                string word = stack.pop();
                cout << "Popped: " << word << endl;
            } catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
            }
            break;
        }

        case 3: { // To capitalize all of the words. 
            try {
                stack.capitalize();
                cout << "All words have offically been capitalized." << endl;
            } catch (const exception& e) {
                cout << "Error: " << e.what() << endl;
            }
            break;
        }

        case 4: { // Display stack
            stack.display();
            break;
        }

        case 5: { // Make a story
            if (stack.getSize() < 5) {
                cout << "Not enough words on the stack to make a story silly! Please Add at least 5 words.\n";
            } else {
                stack.makeStory();
            }
            break;
        }

        case 6: { // Exit
            cout << "Adios Mi Amigo! \n";
            break;
        }

        default: {
            cout << "Invalid entry friend. Try again.\n";
            break;
        }
        }
    } while (selection != 6);

    return 0;
}
