#include <iostream>
#include <string>

#include "process.h"

int main()
{
    int select = 0;
    load_stu_from_file();
    do
    {
        std::cout << "select 1.add stu 2.delete stu 3.update stu 4.query stu 5.show all stu 6.exit " << std::endl;
        std::cout << "select:";
        std::cin >> select;
        switch (select)
        {
        case 1:
            /* code */
            add_stu();
            break;

        case 2:
            /* code */
            del_stu();
            break;

        case 3:
            /* code */
            modify_stu();
            break;

        case 4:
            /* code */
            search_stu();
            break;

        case 5:
            /* code */
            show_stu();
            break;

        default:
            select = 6;
            break;
        }
    } while (select != 6);

    std::cout << "exit" << std::endl;
    return 0;
}