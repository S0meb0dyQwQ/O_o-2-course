#include "Base.h"
void CheckOutputFile(std::ofstream& fout) 
{

    if (!fout.good()) 
    {
        throw  std::ios_base::failure("file doesn't exist\n");
    }
    if (!fout)
    {
        throw  std::ios_base::failure("output file error\n");
    }

}
void CheckInputFile(std::ifstream& fin) 
{

    if (!fin.good())
    {
        throw std::ios_base::failure("file doesn't exist\n");
    }
    if (!fin)
    {
        throw  std::ios_base::failure("input file error\n");
    }
    if (fin.peek() == EOF)
    {
        throw  std::ios_base::failure("file is empty!\n");
    }
}
void WriteArray(std::ofstream& fout, double* array, int32_t size)
{
    for (int32_t i{}; i < size; ++i)
    {
        fout << std::setprecision(10)<< array[i] << '\t';
    }
    fout << '\n';
}
int32_t CountNum(std::ifstream& fin)
{
    int32_t counter{};
    double number{};
    while (fin >> number) {
        ++counter;
    }
    return counter;
}
void FillArrayFromFile(std::ifstream& fin, double*& numbers, int32_t size) {
    fin.clear();
    fin.seekg(0);
    for (int32_t i{}; i < size; ++i) {
        fin >> numbers[i];
    }
}