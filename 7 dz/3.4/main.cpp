#include "hashTable.h"

int main()
{
    std::ifstream file;
    file.open("book.txt");
    if (!file.is_open())
    {
        std::cout << "file didnt open" << std::endl;
        return -1;
    }
    Table *hashTable = createTable();
    char *buffer = new char[1000];
    while (1)
    {
        if (file.eof())
        {
            break;
        }
        file >> buffer;
        int length = strlen(buffer);
        for (int i = 0; i < length; i++)
        {
            if (isAlpha(buffer[i]))
            {
                buffer[i] = toLower(buffer[i]);
            }
            else
            {
                continue;
            }
        }
        for (int i = 0; i < length; i++)
        {
            if (!isLetter(buffer[i]))
            {
                buffer = wordRepair(buffer, i, length);
                break;
            }
            else
            {
                continue;
            }
        }
        if (buffer[0] == '\0')
        {
            continue;
        }
        addToTable(hashTable, buffer);
    }
    file.close();
    delete []buffer;
    statistic(hashTable);
    deleteTable(hashTable);
    return 0;
}
