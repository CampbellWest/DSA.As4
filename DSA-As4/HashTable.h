#pragma once

#include "stdio.h"

#define TABLE_SIZE 11

int hash1(int key, int M);

int hash2(int key, int R);

void hashInit(int* hashTable, int* input, int M, int R);

void printHashTable(int* hashTable, int M);