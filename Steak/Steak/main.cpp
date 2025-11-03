#include "Base.h"
int main() 
{
    std::string line;
    std::cout << "input string: ";
    std::cin >> line;

    try {
        if (isBracketRight(line)) {
            std::cout << " good job. Everything good.\n";
        }
        else {
            std::cout << "no no no. Bad line.\n";
        }
        std::cout << "input string: \n";
        std::cin >> line;
        sortTrain(line);
    }
    catch (std::out_of_range& e) {
        std::cout<< e.what();
    }
    catch (std::range_error& e) {
        std::cout << e.what();
    }
    catch (std::invalid_argument& e) 
    {
        std::cout << e.what();
    }

    return 0;
}