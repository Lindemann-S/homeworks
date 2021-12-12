/*
 * > "Считалочка" — отряд из 41-го сикария, защищавший галилейскую крепость Массада, не пожелал сдаваться в плен блокировавшим его превосходящим силам римлян.
 * > Сикарии стали в круг и договорились, что каждые два воина будут убивать третьего, пока не погибнут все.
 * > Самоубийство — тяжкий грех, но тот, кто в конце концов останется последним, должен будет его совершить.
 * > Иосиф Флавий, командовавший этим отрядом, якобы быстро рассчитал, где нужно стать ему и его другу, чтобы остаться последними, но не для того, чтобы убить друг друга, а чтобы сдать крепость римлянам.
 * > В нашем случае участвует n воинов и убивают каждого m-го.
 * > Требуется определить номер k начальной позиции воина, который должен будет остаться последним.
 * > Считать с помощью циклического списка, который должен быть оформлен отдельным модулем.
*/

#include "countGame.h"

int main()
{
    int numberOfWarriors = 0;
    int step = 0;
    std::cout << "Enter number of warriors: ";
    std::cin >> numberOfWarriors;
    std::cout << "Enter the step: ";
    std::cin >> step;
    game(numberOfWarriors, step);
    // ListNode *list = nullptr;
    // int value = 0;
    // int flag = 0;
    // std::cout << "Enter action: 0 - exit;" << std::endl
    //         << "1 - add a value to sorted list;" << std::endl
    //         << "2 - remove a value from sorted list;" << std::endl
    //         << "3 - print list." << std::endl;
    // std::cin >> flag;
    // while (flag != 0)
    // {
    //     switch (flag)
    //     {
    //         case 1:
    //             std::cout << "Enter value: ";
    //             std::cin >> value;
    //             addValue(list, value);
    //             break;
    //         case 2:
    //             std::cout << "Enter value: ";
    //             std::cin >> value;
    //             removeValue(list, value);
    //             break;
    //         case 3:
    //             std::cout << "Your list: ";
    //             printList(list);
    //             break;
    //         default:
    //             std::cout << "Enter action: 0 - exit;" << std::endl
    //             << "1 - add a value to sorted list;" << std::endl
    //             << "2 - remove a value from sorted list;" << std::endl
    //             << "3 - print list." << std::endl << std::endl;
    //             break;
    //     }
    //     std::cout << "Enter next action: ";
    //     std::cin >> flag;
    // }
    // if (list != nullptr)
    // {
    //     deleteList(list);
    // }
    return 0;
}
