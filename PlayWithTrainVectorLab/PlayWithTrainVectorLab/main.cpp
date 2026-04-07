#include "Train.h"
int main()
{
	try {
		setlocale(LC_ALL, "Russian");
		std::vector<Train>trains;
		std::ifstream fin("Schedule.txt");
		CheckFile(fin);

		FulFillVector(fin, trains);
		size_t size{ trains.size() };
		SortByTime(trains);

		std::string first;
		std::string second;
		std::cout << "ѕоезда из заданного промежутка времени.\n";
		std::cin >> first >> second;
		PrintByTime(trains, size, first, second);

		std::cout << "ѕоезда из заданной станции.\n";
		std::cin >> first;
		PrintByStation(trains, size, first);

		std::cout << "—корые поезда из заданной станции.\n";
		std::cin >> first;
		PrintFastByStation(trains, size, first);

		std::cout << "—амые быстрые поезда из заданной станции.\n";
		std::cin >> first;
		try 
		{
			PrintTheFastestByStation(trains, size, first);
		}
		catch (std::invalid_argument& e)
		{
			std::cout << e.what();
		}
	}
	catch (std::invalid_argument& e)
	{
		std::cout << e.what();
	}
	catch (std::ios_base::failure& e)
	{
		std::cout << e.what();
	}
	return 0;
}
