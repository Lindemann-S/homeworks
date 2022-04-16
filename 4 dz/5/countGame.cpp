#include "countGame.h"
struct ListNode;
void game(int numberOfWarriors, int step)
{
    ListNode *list = nullptr;
    for (int i = 1; i <= numberOfWarriors; i++)
    {
        addValue(list, i);
    }
    printList(list);
    for (int i = numberOfWarriors; i > 2; i--)
    {
        removeStepValue(list, step % i);
    }
    std::cout << "Positions of the surviving warriors: ";
    printList(list);
    deleteList(list);
}
