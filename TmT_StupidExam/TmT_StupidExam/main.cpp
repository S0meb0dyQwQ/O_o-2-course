#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
int Compare(const void* a, const void* b) 
{
    return *((int*)b) - *((int*)a);
}

int main()
{
    std::string str;
    std::string st{};
    std::ifstream fin("in.txt");
    std::ofstream fout("out.txt");
	try
    {
       /* 
       //1)найти макс там понятно поразделять слова и тип длина первого будет макс если следующее больше то делай большее с минимум также
        //2)найти все макс и занести их в новую строку , ок
        // я задолбаюсь все делать
        //3) палиндромы с помощью strrev и strcmp в новую строку как нехуй и по возрастанию просто отсортировать
        //4) символы в возрастании кодов? чего бл а ну это проще чем казалось
        //5) наибольшее кол-во различных символов... тетя давно таблетки принимала? для каждого слова тип считать кол-во символов различных
        // в жопу если попадется я слово сортировать буду пошла нафиг 
        //6) найти все слова начинаюшиеся с гласной бля ну лан
        //7) эт короче тупо во всех словах считать колво глассных
        //8) цифры с макс колво нулей это тож с strpbrk просто там не глассные считаем а нули
        //10) строку сделать массивом массивов и там поперемещать + проверка на all num бля ну херня задание много не точностей слава богу оно не мне было
        //11) эхехе не написала про доп строки ну тогда точно массив массивов меняем слова с full numbers и все четенько
        //12)так ну тож как нефиг в одном вайле делим током строки записываем сначала первое + пробел + второе и тд до конца одной из строк а потом дописываем конец(токен же остался на своем адресе вот его и записываем
        //14) ну как у меня находим чиселки можно посчитать колво циферек
        //15)бля ну что за говно отсортировать числа по убыванию суммы их цифр а остальное оставить прежним и пробелы оставить TmT
        //пусть цифры в массиве и есть суммы и тип отсортируем по убыванию
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
        fin.getline(str, 300);
        std::cout << str << '\n';
        /* char copy[300];
        strcpy(copy, str);
        char* token = strtok(copy, " ");
        size_t length_max{strlen(token)};
        int32_t counter{};
        while (token != NULL)
        {
            if (strlen(token) == length_max) 
            {
                ++counter;
            }
            if (strlen(token) > length_max) 
            {
                length_max = strlen(token);
                counter = 0;
            }
            token = strtok(NULL, " ");
        }
        strcpy(copy, str);
        char maxes[300];
        strcpy(maxes, "");
        token = strtok(copy, " ");
        while (token != NULL)
        {
            if (strlen(token) == length_max)
            {
                strcat(maxes, token);
                strcat(maxes, " ");
            }
            token = strtok(NULL, " ");
        }
        std::cout << maxes;
        fout << maxes;
        /*  char copy[300];
        strcpy(copy, str);
        char* token = strtok(copy, " ");
        char reverse[300];
        while (token != NULL)
        {
            strcpy(reverse, token);
            _strrev(reverse);
            if (strcmp(token, reverse) == 0) 
            {
            fout << token << " ";
            }
            token = strtok(NULL, " ");
        }
        /* char word[300];
        std::cin.getline(word, 300);
        size_t length{ strlen(word) };
        int32_t counter{1};
        for (size_t i{}; i < length - 1; ++i) 
        {
           
        }
        //char copy[300];
        //char alphas[]{'a','e','y','u','i','o','\0'};
        //strcpy(copy, str);
        //char* token = strtok(copy, " ");
        //char* finder;
        //int32_t counter{};
        //while (token != NULL)
        //{
        //    finder = strpbrk(token, alphas); // counter обновляется для каждого слова там запоминается и тд
        //    while (finder != NULL) 
        //    {
        //        ++counter;
        //        finder = strpbrk(finder + 1,alphas) ;
        //    }
        //    token = strtok(NULL, " ");
        //}
        /* char word[]{ "23\0" };
        _strrev(word);
        for (size_t i{ strlen(word) }; i < 5; ++i) 
        {
            strcat(word, "0");
        }
        _strrev(word);
        std::cout << word;
        int array[6];
        fin.clear();
        fin.seekg(0);
        for (int32_t i{}; i < 6; ++i)
        {
            fin >> array[i];
        }
        qsort(array, 6, sizeof(int),Compare);
        for (int32_t i{}; i < 6; ++i)
        {
            fout << array[i] << " ";
        }
        //добре а чо дальше?
        */
       //1) тип сделали
       //2) ну та же схема первый тип самый длинный потом если следующий больше то он макс
       //3) проверка на палиндром чисто переделаем с c_str в char* и в новую строку

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

   /* while (getline(fin, str))
    {
        size_t begin{};
        size_t end{};
        begin = str.find_first_not_of(" ");
        while (begin != std::string::npos)
        {
            end = str.find_first_of(" ", begin);
            if (end == std::string::npos)
            {
                end = str.length();
            }
            begin = str.find_first_not_of(" ", end);
        }
    }*/
	}
	catch (std::ios_base::failure& e)
    {
        std::cout << e.what();
	}
	return 0;
}