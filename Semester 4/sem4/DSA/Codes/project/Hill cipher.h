#pragma once

#include <string>
#include "matrix.h"


class node
{
public:
	char alphabet;
	int value;
	node* next;
	node(char character, int number): alphabet(character), value(number), next(nullptr) {}
};

class LinkedList {
private:
	node* head;
	int count = 0;
public:
	LinkedList() {
		head = nullptr;
		count = 0;
	}
	
	void insert(char character,int number) {
		node* newNode = new node(character, number);
		if (head == nullptr) {
			head = newNode;
		}
		else {
			node* temp = head;
			while (temp->next != nullptr) {
				temp = temp->next;
			}
			temp->next = newNode;
		}
		count++;
	}
	int getValue(char character) const {
		node* temp = head;
		while (temp != nullptr) {
			if (temp->alphabet == character) {
				return temp->value;
			}
			temp = temp->next;
		}
		return -1; 
	}

	char getCharacter(int value) const {
		node* temp = head;
		while (temp != nullptr) {
			if (temp->value == value) {
				return temp->alphabet;
			}
			temp = temp->next;
		}
		return ' '; 
	}

	void display() const {
		node* temp = head;
		while (temp != nullptr) {
			
			cout << "alphabet: " << temp->alphabet << endl;
			cout << "Value: " << temp->value << endl;
			temp = temp->next;
		}
		cout << endl;
	}
	int size() {
		return count;
	}
};

class HillCipher {
protected:
	Matrix keyMatrix = Matrix(2,2);
	LinkedList dictionary;

public:
	HillCipher(int key[], const LinkedList& dict) : dictionary(dict) {
		/*keyMatrix = Matrix(2, 2);*/
		keyMatrix.data[0][0] = key[0];
		keyMatrix.data[0][1] = key[1];
		keyMatrix.data[1][0] = key[2];
		keyMatrix.data[1][1] = key[3];
	}

	Matrix getKeyMatrix() const {
		return keyMatrix;
	}

	int getValue(char character) const {
		return dictionary.getValue(character);
	}
};