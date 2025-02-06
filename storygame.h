#ifndef STORYGAME_H
#define STORYGAME_H

#include <iostream>
#include <stdexcept>
#include <string>
#include <cctype>

class storygame {
private:
    struct Node {
        std::string word;
        Node* next;
        Node(const std::string& w) : word(w), next(nullptr) {}
    };
    Node* top;
    int size;   

    bool isAlphabetic(const std::string& word) const;
    std::string trim(const std::string& str) const;

public:
    storygame();
    ~storygame();

    void push(const std::string& word);
    std::string pop();
    bool isEmpty() const;
    void capitalize();
    void display() const;
    int getSize() const;
    void makeStory();
};

#endif
