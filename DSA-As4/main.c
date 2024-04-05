#include "HashTable.h"

int main() {

	int M = TABLE_SIZE; // size of the hashtable 
	int R = 7;          // our hash value for the double hash 

	int input[] = {764, 35954, 8683, 41, 11004, 1362, 77, 1, 448, 118, 5507}; // keys we want to inset 
	int hashTable[TABLE_SIZE];

	hashInit(hashTable, input, M, R);

	printHashTable(hashTable, M);

	return 0;
}