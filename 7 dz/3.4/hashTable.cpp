#include "hashTable.h"

struct Table
{
    List **node;
    int size;
    int existingElements;
    double loadFactor;
};

Table *createTable()
{
   return createTable(1001);
}

Table *createTable(int tableSize)
{
    Table *table = new Table;
    table->size = tableSize;
    table->existingElements = 0;
    table->loadFactor = 0;
    List **list= new List *[tableSize];
    for (int i = 0; i < tableSize; i++)
    {
        list[i] = createList();
    }
    table->node = list;
    return table;
}

void deleteTable(Table *table)
{
    for (int i = 0; i < table->size; i++)
    {
        if (table->node[i] != nullptr)
        {
            deleteList(table->node[i]);
        }
    }
    delete []table;
}

int hashFunction(char *word, int module)
{
    int length = strlen(word);
    const int p = 31;
    unsigned long long hash = 0;
    unsigned long long pow = 1;
    for (int i = 0; i < length; i++)
    {
        int ch = word[i] - 'a' + 1;
        hash = (hash + ch * pow) % module;
        for (int j = 0; j < i; j++)
        {
            pow = (pow * p) % module;
        }
    }
    return hash;
}

List *searchList(Table *table, char *word)
{
    int i = hashFunction(word, table->size);
    return table->node[i];
}

void rebuildTable(Table *&table)
{
    std::cout << "Start rebuilding ..." << std::endl;
    Table *newTable = nullptr;
    newTable = createTable(table->size * 10 + 1);
    newTable->existingElements = table->existingElements;
    newTable->loadFactor = (double) newTable->existingElements / newTable->size;
    for (int i = 0; i < table->size; i++)
    {
        if (!isEmpty(table->node[i]))
        {
            char *word = returnChar(table->node[i]);
            int j = hashFunction(word, newTable->size);
            newTable->node[j] = table->node[i];
        }
    }
    delete []table;
    table = newTable;
}

void addToTable(Table *&table, char *word)
{
    String *str = createString(word);
    List *detectedList = searchList(table, word);
    if (isEmpty(detectedList))
    {
        table->existingElements++;
        table->loadFactor = (double) table->existingElements / table->size;
    }
    push(detectedList, str);
    if (table->loadFactor > 1)
    {
        rebuildTable(table);
    }
}

void statistic(Table *hashTable)
{
    std::cout << "Load factor = " << hashTable->loadFactor << std::endl;
    std::cout << "Empty elements = " << hashTable->size - hashTable->existingElements << std::endl;
    int numberOfWords = 0;
    double sumOfNodes = 0;
    int maxChainLength = 0;
    int index = 0;
    for (int i = 0; i < hashTable->size; i++)
    {
        if (hashTable->node[i] == nullptr)
        {
            continue;
        }
        numberOfWords += numOfWords(hashTable->node[i]);
        int numberOfNodes = numOfNodes(hashTable->node[i]);
        sumOfNodes += numberOfNodes;
        if (numberOfNodes > maxChainLength)
        {
            maxChainLength = numberOfNodes;
            index = i;
        }

    }
    std::cout << "Number of words = " << numberOfWords << std::endl;
    std::cout << "Average chain length = " << sumOfNodes / hashTable->existingElements << std::endl;
    std::cout << "Max chain length = " << maxChainLength << std::endl;
    std::cout << "Existing words:" << std::endl;
    print(hashTable->node[index]);
}
