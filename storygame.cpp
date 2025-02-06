#include "storygame.h"
#include <iostream>
#include <cctype>
#include <stdexcept>
#include <algorithm>

using namespace std;

storygame::storygame() : top(nullptr), size(0) {}

storygame::~storygame() {
    while (!isEmpty()) {
        pop();
    }
}

bool storygame::isEmpty() const {
    return top == nullptr;
}

// To make sure only alphabetic characters are entered by user. 

bool storygame::isAlphabetic(const string& word) const {
    for (char c : word) {
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}

// To trim spaces from both ends of the string. 

string storygame::trim(const string& str) const {
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return (first == string::npos || last == string::npos) ? "" : str.substr(first, last - first + 1);
}

// The push and validation for alphabetic user input and word lenghh.

void storygame::push(const string& input) {
    string word = trim(input); // Trim the extra spaces. 

    if (word.empty() || word.length() > 10 || !isAlphabetic(word)) {
        throw invalid_argument("Words must be alphabetic ya silly goose!, and 10 characters or less. understood? good. :) ");
    }
    
    Node* newNode = new Node(word);
    newNode->next = top;
    top = newNode;
    size++;
}

string storygame::pop() {
    if (isEmpty()) {
        throw underflow_error("Stack is unbelievably empty partner.");
    }
    Node* temp = top;
    string word = top->word;
    top = top->next;
    delete temp;
    size--;
    return word;
}

void storygame::capitalize() {
    if (isEmpty()) {
        throw underflow_error("no sir ree the stack is super empty.");
    }
    Node* current = top;
    while (current != nullptr) {
        for (char& c : current->word) {
            c = toupper(c);
        }
        current = current->next;
    }
}

void storygame::display() const {
    if (isEmpty()) {
        cout << "Stack is empty fellow human!...Please enter words onto the stack. or push them on me...and I shall do things with them. " << endl;
        return;
    }
    Node* current = top;
    while (current != nullptr) {
        cout << current->word << endl;
        current = current->next;
    }
}

int storygame::getSize() const {
    return size;
}

void storygame::makeStory() {
    if (size < 5) {
        cout << "Sorry pal! not enough words on the stack to make a story. Try adding some more!" << endl;
        return;
    }

    string word1 = pop();
    string word2 = pop();
    string word3 = pop();
    string word4 = pop();
    string word5 = pop();

    cout << "Story:" << endl;
    cout << " There was a " << word1 << " in the tree. It smelt like onions and coffee. There was a " << word2 << " across the street that had funny looking feet." << endl;
    cout << " On the way, they met a " << word3 << " whos companion was a " << word4 << " and then a whale jumped out of the pacific ocean and swallowed them up... gulp, gulp, gulp the whale said. " << endl;
    cout << " They lived on inside of this whale until the " << word5 << " said im done living in this whale and tried crawling out of his blow hole but on the way out the whale sneezed and blew the "<< word4 << " back to Antartica. Crazy huh." << endl;
}
