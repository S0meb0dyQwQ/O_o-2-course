#include <iostream>
#include <chrono>
int main()
{
	auto start = std::chrono::high_resolution_clock::now();
    double a{ pow(2,32) };
	for (double i{}; i < a; ++i)
	{
	}
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> time = end - start;
	std::cout << time.count();
    std::cout << a;
   /* using namespace std::chrono;

    uint64_t limit = static_cast<uint64_t>(1) << 32;


    volatile uint64_t dummy = 0;
    
    auto start = high_resolution_clock::now();

    for (uint64_t i = 0; i < limit; ++i) {

    }

    auto end = high_resolution_clock::now();
    duration<double> elapsed = end - start;

    std::cout << "Elapsed time: " << elapsed.count() << " seconds\n";
    return 0;*/
}