#include "Container.h"
void CheckInputFile(std::ifstream& fin) {

    if (!fin.good()) {
        throw std::ios_base::failure("file doesn't exist\n");
    }
    if (!fin) {
        throw std::ios_base::failure("input file error\n");
    }
    if (fin.peek() == EOF) {
        throw std::ios_base::failure("file is empty!\n");
    }
}
int CompareTrees(const void* a, const void* b) 
{
    Tree* ptr_a = *static_cast<Tree* const*>(a);
    Tree* ptr_b = *static_cast<Tree* const*>(b);
    if (ptr_a->GetName() == ptr_b->GetName())
    {
        return ptr_b->GetAge() - ptr_a->GetAge();
    }
    return ptr_a->GetName() > ptr_b->GetName();
}
int CountSize(std::ifstream& fin)
{
    fin.clear();
    fin.seekg(0);
    std::string line;
    int counter{};
    while (fin >> line)
    {
        ++counter;
    }
    return counter;
}
void MakeArrayFromFile(std::ifstream& fin, Container& array)
{
    fin.clear();
    fin.seekg(0);
    std::string line;
    FruitTree fruit;
    ForestTree forest;
    int size = array.GetCapacity();
    for (int i{}; i < size; ++i)
    {
        getline(fin, line, ';');
        if (line == "Fruit")
        {
            getline(fin, line, ';');
            fruit.SetName(line);
            getline(fin, line, ';');
            fruit.SetAge(stoi(line));
            getline(fin, line, ';');
            if (line == "deciduous") 
            {
                fruit.SetType(Type::deciduous);
            }
            else 
            {
                fruit.SetType(Type::coniferous);
            }
            getline(fin, line, ';');
            fruit.SetCrop(stoi(line));
            getline(fin, line);
            fruit.SetAvKep(stoi(line));
            array.Push_back(new FruitTree(fruit));
        }
        else if (line == "Forest")
        {
            getline(fin, line, ';');
            forest.SetName(line);
            getline(fin, line, ';');
            forest.SetAge(stoi(line));
            getline(fin, line, ';');
            if (line == "deciduous")
            {
                forest.SetType(Type::deciduous);
            }
            else
            {
                forest.SetType(Type::coniferous);
            }
            getline(fin, line);
            forest.SetWood(stoi(line));
            array.Push_back(new ForestTree(forest));
        }

    }

}

void Container::Resize(int new_capacity)
    {
        capacity = new_capacity;
        Tree** new_array = new Tree * [new_capacity];
        for (int i{}; i < size; ++i)
        {
            new_array[i] = trees[i];
        }
        trees = nullptr;
        trees = new_array;
    }
Container::Container( int cap) 
{
    capacity = cap;
    trees = new Tree*[cap];
    for (int i = 0; i < cap; ++i)
    {
        trees[i] = new Tree();
    }
}
Container::Container(const Container& other)
{
    size = other.size;
    capacity = other.capacity;
    this->Resize(other.capacity);
    for (int i = 0; i < other.size; ++i)
    {
        trees[i] = other.trees[i];
    }
}
Container::~Container()
{
    delete[]trees;
}
void Container::Push_back(Tree* dyb)
{
    if (size == capacity) 
    {
        this->Resize(capacity * 2);
    }
    trees[size++] = dyb;
}
void Container:: Pop_back()
{
    if (size > 0)
    {
        --size;
    }
    else 
    {
        throw std::out_of_range("there ara no elements");
    }
}
Tree Container:: at(int i) const
{
    if (i >= size) {
        throw std::out_of_range("Index out of range");
    }
    return *trees[i];
}
void Container:: Print() const
{
    for (int i{}; i < size; ++i)
    {
        trees[i]->Print();
    }
}
int Container:: CountDeciduous() 
{
    int counter{};
    for (int i{}; i < size; ++i)
    {
        if (trees[i]->GetType() == Type::deciduous)
        {
            ++counter;
        }
    }
    return counter;
}
int Container::CountConiferous()
{
    int counter{ this->CountDeciduous() };
    return size - counter;
}
int Container::CountForest()
{
    int counter{};
    for (int i{}; i < size; ++i)
    {
        if (typeid(*trees[i]) == typeid(ForestTree))
        {
            ++counter;
        }
    }
    return counter;
}
int Container::CountFruit()
{
    int counter{};
    for (int i{}; i < size; ++i)
    {
        if (typeid(*trees[i]) == typeid(FruitTree))
        {
            ++counter;
        }
    }
    return counter;
}
void Container:: PrintSorted()
{
    qsort(trees, size, sizeof(Tree*), CompareTrees);
    this->Print();
}
int Container:: GetSize()
{
    return size;
}
int Container::GetCapacity()
{
    return capacity;
}