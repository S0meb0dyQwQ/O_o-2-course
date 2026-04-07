#ifndef TRAIN_H
#define TRAIN_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
enum class Type
{
	passenger,
	fast,

};
struct Time
{
	int hours;
	int minutes;

	Time() : hours(0), minutes(0) {}
	Time(int h, int m) : hours(h), minutes(m)
	{
		Normalize();
	}
	Time(const Time& other)
	{
		Clone(other);
	}
	Time(std::string& other)
	{
		Divide(other);
		Normalize();
	}
	void Divide(std::string& line) 
	{
		std::string subline;
		size_t begin = line.find_first_of(':');
		subline = line.substr(0, begin);
		hours = stoi(subline);
		begin = line.find_first_not_of(':', begin);
		size_t end = line.find_first_of(':',begin);
		subline = line.substr(begin, end - begin);
		minutes = stoi(subline);
	}
	void Normalize() 
	{
		if (minutes >= 60)
		{
			hours += minutes / 60;
			minutes %= 60;
		}
		if (minutes < 0) {
			int extraHours = (minutes - 59) / 60;
			hours += extraHours;
			minutes -= extraHours * 60;
		}
	}
	void Clone(const Time& other)
	{
		hours = other.hours;
		minutes = other.minutes;
		Normalize();
	}
	bool operator<(const Time& other) const 
	{
		if (hours == other.hours) 
		{
			return minutes < other.minutes;
		}
		return hours < other.hours;
	}
	bool operator >(const Time& other)const 
	{
		return other < *this;
	}
	bool operator >= (const Time& other)const
	{
		return *this > other || *this == other;
	}
	bool operator <= (const Time& other)const
	{
		return other >= *this;
	}
	bool operator==(const Time& other) const
	{
		return hours == other.hours && minutes == other.minutes;
	}
	Time& operator = (const Time& other)
	{
		if (this != &other)
		{
		Clone(other);
		}
		return *this;
	}
	Time operator = (std::string& line)
	{
		Divide(line);
		Normalize();
		return *this;
	}
	void Print(std::ostream& out) const
	{
		//std::cout << std::setw(2) << std::setfill('0') << hours << ":"<< std::setw(2) << std::setfill('0') << minutes;
		if (hours < 10)
		{
			out << '0';
		}
		out << hours << ':';
		if (minutes < 10)
		{
			std::cout << '0';
		}
		out << minutes;
	}
}; class Train
{
private:
	std::string id;
	std::string name_station;
	Type type;
	Time time;
	Time travel_time;//в часах
	void Clone(const Train& other)
	{
		id = other.id;
		name_station = other.name_station;
		type = other.type;
		time = other.time;
		travel_time = other.travel_time;
	}
public:
	Train(){}
	Train(std::string& a, std::string& b, Type c, Time d, Time e)
	{
		id = a;
		name_station = b;
		type = c;
		time = d;
		travel_time = e;
	}
	Train(const Train& other) 
	{
		Clone(other);
	}
	~Train() = default;
	Train& operator = (const Train& other) 
	{
		if (this != &other) 
		{
			Clone(other);
		}
		return *this;
	}
	friend std::ostream& operator<<(std::ostream& out, const Train& a) 
	{
		out << "Номер: " << a.id << "\nПункт отправления: " << a.name_station << "\n Тип : ";
		if (a.type == Type::passenger) 
		{
			out << "passenger\n";
		}
		else 
		{
			out << "fast\n";
		}
		out << "Время отправления: ";
		a.time.Print(out);
		out << "\nВремя поездки: ";
		a.travel_time.Print(out);
		return out<<'\n';
	}
	void setid(std::string& a)
	{
		id = a;
	}
	void setname(std::string& a) 
	{
		name_station = a;
	}
	void settype(std::string& a)
	{
		if (a == "p")
		{
			type = Type::passenger;
		}
		else if (a == "s")
		{
			type = Type::fast;
		}
		else 
		{
			throw std::invalid_argument("wrong time");
		}
	}
	void settime(const Time& a) 
	{
		time = a;
	}
	void setTraveltime(const Time& a)
	{
		travel_time = a;
	}
	std::string getid()
	{
		return id;
	}
	std::string getstation() 
	{
		return name_station;
	}
	Type gettype()
	{
		return type;
	}
	Time& gettime() 
	{
		return time;
	}
	Time& gettraveltime() 
	{
		return travel_time;
	}
};

void CheckFile(std::ifstream& fin)
{
	if (!fin)
	{
		throw std::ios_base::failure("not exist");
	}
	if (fin.peek() == EOF)
	{
		throw std::ios_base::failure("is empty");
	}
}
void FulFillVector(std::ifstream& fin, std::vector<Train>& trains) 
{
	fin.clear();
	fin.seekg(0, std::ios::beg);
	std::string line;
	Train a;
	while(getline(fin, line, ';'))
	{
		a.setid(line);
		getline(fin, line, ';');
		a.setname(line);
		getline(fin, line, ';');
		a.settype(line);
		getline(fin, line, ';');
		a.settime(line);
		getline(fin, line);
		a.setTraveltime(line);
		trains.push_back(a);
	}
}
void SortByTime(std::vector<Train>& trains)
{
	size_t size{ trains.size() };
	for (size_t i{}; i < size - 1; ++i)
	{
		size_t min_id = i;
		for (size_t j = i + 1; j < size; ++j)
		{
			if (trains[j].gettime()< trains[min_id].gettime())
			{
				min_id = j;
			}
		}

		if (min_id != i)
		{
			std::swap(trains[i], trains[min_id]);
		}
	}
}
void PrintByTime(std::vector<Train>& trains,size_t size, std::string a, std::string b)
{
	Time first(a);
	Time second(b);
	if (first > second) 
	{
		std::swap(first, second);
	}
	bool here{};
	for (size_t i{}; i < size; ++i) 
	{
		Time time = trains[i].gettime();
		if (time <= second && time >= first)
		{
			std::cout << trains[i]<<'\n';
			here = 1;
		}
	}
	if (here == 0) 
	{
		std::cout << "Ничего не найдено\n";
	}
}
void PrintByStation(std::vector<Train>& trains, size_t size, std::string a) 
{
	bool here{};
	for (size_t i{}; i < size; ++i)
	{
		if (trains[i].getstation() == a) 
		{
			std::cout << trains[i] << '\n';
			here = 1;
		}
	}
	if (here == 0)
	{
		std::cout << "Ничего не найдено\n";
	}
}
void PrintFastByStation(std::vector<Train>& trains, size_t size, std::string a)
{
	bool here{};
	for (size_t i{}; i < size; ++i)
	{
		if (trains[i].getstation() == a && trains[i].gettype() == Type::fast)
		{
			std::cout << trains[i] << '\n';
			here = 1;
		}
	}
	if (here == 0)
	{
		std::cout << "Ничего не найдено\n";
	}
}
std::vector<Train> MakeStationVector(std::vector<Train>& trains, int size, std::string a)
{
	std::vector<Train> other;
	for (int i{}; i < size; ++i)
	{
		if (trains[i].getstation() == a)
		{
			other.push_back(trains[i]);
		}
	}
	return other;
}
void PrintTheFastestByStation(std::vector<Train>& trains, int size, std::string a)
{
	std::vector<Train> other = MakeStationVector(trains,size,a);
	if (other.empty()) 
	{
		throw std::invalid_argument("Нет такой станции\n");
	}
	size_t size_other{ other.size() };
	Train fastest{ other[0] };
	for (size_t i{}; i < size_other; ++i)
	{
		Time time = other[i].gettraveltime();
		if (time < fastest.gettraveltime())
		{
			fastest = other[i];
		}
	}
	std::cout<< fastest;
}
#endif