#pragma once

#include <fstream>

#include "list.h"

struct Table;
Table *createTable();
Table *createTable(int tableSize);
void addToTable(Table *&hashTable, char *buffer);
void addToTable(Table *&newTable, List *list);
void statistic(Table *hashTable);
void deleteTable(Table *hashTable);
