#include "Base.h"
#include "Sorts.h"
int main() 
{
    int32_t choose{};
    std::cout << "input choose:\n 1) from console 2) random 3) from file\n";
    std::cin >> choose;
    switch (choose) 
    {
    case 1:
        WorkFromConsole();
        break;
    case 2:
        WorkByRandom();
        break;
    case 3:
        WorkFromFile();
        break;
    default:
        std::cout << "wrong number try again later\n";
    }
 	return 0;
}