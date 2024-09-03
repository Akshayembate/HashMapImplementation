Custom Hash Table Implementation in C++
Overview
This project provides a custom hash table implementation in C++ using open addressing for collision resolution. The hash table supports basic operations such as adding, deleting, and searching for string entries. The size of the hash table is fixed at 26 slots, and each entry is associated with a status indicating whether it is "occupied," "never used," or a "tombstone" (marked for deletion).

Features
Fixed-Size Hash Table: The hash table has a fixed size of 26, corresponding to the 26 letters of the English alphabet.
Open Addressing: Collision resolution is handled using open addressing with linear probing.
String-Based Keys: Each entry in the hash table is a string, and the hash function is based on the last character of the string.
Basic Operations:
Add: Adds a new entry to the hash table if it does not already exist.
Delete: Marks an entry as deleted ("tombstone") in the hash table.
Search: Searches for an entry in the hash table.
Code Structure
HashTable Class: The main class that defines the hash table structure and its operations.
Public Methods:
void print(): Prints the current state of the hash table, including the data and status of each slot.
void Add(const std::string& entryString): Adds a new entry to the hash table.
void Delete(const std::string& entryString): Deletes an entry from the hash table by marking it as a tombstone.
Private Methods:
int GetIndex(const std::string& entryString): Computes the index for an entry based on its last character.
bool Find(const std::string entryString): Checks if an entry exists in the hash table.
int GetInsertIndex(const std::string& entryString): Finds the appropriate index to insert a new entry.
int GetDeleteIndex(const std::string& entryString): Finds the index of an entry to be deleted.
Usage
To use the hash table implementation, you can compile and run the provided main.cpp file. The program reads input from the command line, where each word is prefixed by either 'A' (for adding) or 'D' (for deleting). The program then processes these commands and prints the final state of the hash table.