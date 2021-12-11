/*Написать программу, которая в диалоговом режиме позволяет осуществлять следующие операции:
0 - exit;
1 - add a value to sorted list;
2 - remove a value from sorted list;
3 - print list.
Все операции должны сохранять сортированность. Начинаем с пустого списка. Список должен быть оформлен отдельным модулем.*/

#include "intList.h"

int main()
{
    ListNode *list = nullptr;
    int value = 0;
    int flag = 0;
    std::cout << "Enter action: 0 - exit;" << std::endl
            << "1 - add a value to sorted list;" << std::endl
            << "2 - remove a value from sorted list;" << std::endl
            << "3 - print list." << std::endl;
    std::cin >> flag;
    while (flag != 0)
    {
        switch (flag)
        {
            case 1:
                std::cout << "Enter value: ";
                std::cin >> value;
                addValue(list, value);
                break;
            case 2:
                removeValue(list);
                break;
            case 3:
                std::cout << "Your list: ";
                printList(list);
                break;
            default:
                std::cout << "Enter action: 0 - exit;" << std::endl
                << "1 - add a value to sorted list;" << std::endl
                << "2 - remove a value from sorted list;" << std::endl
                << "3 - print list." << std::endl << std::endl;
                break;
        }
        std::cout << "Enter next action: ";
        std::cin >> flag;
    }
    if (list != nullptr)
    {
        deleteList(list);
    }
    return 0;
}
