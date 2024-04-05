#include "HashTable.h"

int hash1(int key, int M) {
	return key % M; // first hash to find its *natural* spot in the table
}

int hash2(int key, int R) {
	return R - (key % R); // second hash to find a values offset if their *natural* spot is taken
}

void hashInit(int* hashTable, int* input, int M, int R) { //{764, 35954, 8683, 41, 11004, 1362, 77, 1, 448, 118, 5507} keys

	for (int i = 0; i < M; i++) // set all the values to a value we dont have in the keys and can be used to check empty places 
		hashTable[i] = -1;

	for (int i = 0; i < M; i++) { // fill the hash table with each key/input 

		int key = input[i];        // create current key 
		int index = hash1(key, M); // get the *natural* index of where the key would be in no colision 
		int offset = hash2(key, R);// in case of colisions, get the offset value to use later 

		int j = 0; // set offeset multiplier to zero for fisrt interation 
		while (hashTable[(index + j * offset) % M] != -1) // while this spot in the hash is not equal to -1 (our empty value)
			j++; // increase the offest multiplier to find new spot 

		hashTable[(index + j * offset) % M] = key; // once you find an empty spot, set the value in the table
	}											   // at [*natural* index plus the offset * its multiplier] 
}												   // equal to the key we want to insert	

void printHashTable(int* hashTable, int M) {
	printf("____________\n");
	for (int i = 0; i < M; i++) {         // goes through the hash table array and at each spot, up to M - 1,
		printf("|   %i \n", hashTable[i]);// we print off the value in that place 
		printf("|___________\n");       
	}
}

//    0   1   2   3   4   5   6   7   8   9  10
//  _____________________________________________
//	|	|	|	|	|	|	|	|	|	|	|	|
//  |	|	|	|	|	|	|	|	|	|	|	| 
//  ---------------------------------------------
//