#include "Base.h"
int main() 
{
	TDeque<int> L;
	L.InsFront(3);
	L.InsFront(9);
	L.InsBack(8);
	L.GetByIndex(2);
	L.DelFront();
	L.SetByIndex(5, 1);
	TDeque<int> a(L);
	a.PrintDeque();
	return 0;
}