#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
void CheckInputFile(std::ifstream& fin) {

    if (!fin.good()) {
        throw "file doesn't exist\n";
    }
    if (!fin) {
        throw "input file error\n";
    }
    if (fin.peek() == EOF) {
        throw "file is empty!\n";
    }
}

void CheckOutputFile(std::ofstream& fout) {

    if (!fout.good()) {
        throw "file doesn't exist\n";
    }
    if (!fout) {
        throw "output file error\n";
    }

}

int32_t CountNum(std::ifstream& fin) {
    int32_t counter{};
    int32_t number{};
    while (fin >> number) {
        ++counter;
    }
    return counter;
}

void OutputArray(std::ostream& out, int32_t* numbers, int32_t size) {
    for (int32_t i{}; i < size; ++i) {
        out << numbers[i] << '\t';
    }
}

void FillArrayFromFile(std::ifstream& fin, int32_t* numbers, int32_t size) {
    fin.clear();
    fin.seekg(0);
    for (int32_t i{}; i < size; ++i) {
        fin >> numbers[i];
    }
}
int32_t CountDigit(int32_t number) {
    int32_t i{};
    if (number == 0) return 1;
    while (number) {
        number /= 10;
        ++i;
    }
    return i;
}

int compare(const void* a, const void* b) {
    return(CountDigit(*((int32_t*)a)) - CountDigit(*((int32_t*)b)));
}


int main() {
    std::ifstream fin("in.txt");
    try {
        CheckInputFile(fin);
        std::ofstream fout("out.txt");
        CheckOutputFile(fout);
        /*int32_t firstnum{};
        int32_t secondnum{};
        fin >> firstnum >> secondnum;
        fout << '\n' << firstnum << '+' << secondnum << '=' << firstnum + secondnum << '\n';
        */
        /*std::string str;
        while(std::getline(fin,str)){
            fout << str << '\n';
        }
        fout.close();
        fin.close();
        */
        int32_t size{ CountNum(fin) };
        std::cout << size << '\n';


        int32_t* numbers = new int32_t[size];
        FillArrayFromFile(fin, numbers, size);
        qsort(numbers, size, sizeof(int32_t), compare);
        OutputArray(fout, numbers, size);


        std::cout << "success\n";
    }
    catch (const char* msg) {
        std::cerr << msg;
    }

    return 0;
}