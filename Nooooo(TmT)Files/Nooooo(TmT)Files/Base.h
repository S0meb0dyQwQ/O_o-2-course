#ifndef BASE_H
#define BASE_H
#include <iostream>
#include <cstdint>
#include <string>
#include <fstream>
#include <iomanip>
void ChooseType(char&);
void InputSize(int32_t&);
void FillArray(double*&, int32_t);
void InputSortType(bool&);
void RewriteCopy(double*,double*&, int32_t);

void CheckOutputFile(std::ofstream&);
void CheckInputFile(std::ifstream&);
void WriteArray(std::ofstream&, double*, int32_t);
int32_t CountNum(std::ifstream&);
void FillArrayFromFile(std::ifstream&, double*& , int32_t);

void BubbleSort(double*&, int32_t, bool);

int32_t FindSmallestPositionFromBeginning(double*, int32_t, int32_t);
int32_t FindSmallestPositionFromEnd(double*, int32_t, int32_t);
void SelectionSort(double*&, int32_t, bool);

void InsertionSort(double*&, int32_t, bool);

void QuickSort(double*&, int32_t, int32_t, bool);
int32_t Separate(double*, int32_t, int32_t, bool);

void MergeSort(double*&, int32_t, int32_t, bool);
void Merge(double*&, int32_t, int32_t, int32_t, bool);

int Compare(const void*, const void*);
size_t CountDigitAfterDot(double);

void ShowArray(double*, int32_t);
#endif
