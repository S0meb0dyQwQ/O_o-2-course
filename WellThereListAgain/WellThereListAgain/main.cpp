#include "Base.h"
int main()
{
	DLList<int> L;
	L.insert(0, 3);
	std::cout << L.front();
	return 0;
}