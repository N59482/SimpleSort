#include <iostream>
#include <cstdlib>

using namespace std;

class SimpleSort
    {
        private:
        int * arr;
        int SIZE;
        int * end;
        public:
        SimpleSort(const int & SIZE);
        SimpleSort() : SimpleSort(10) { /*cout<<"Call constructor(10)\n";*/ }
        ~SimpleSort();
        void rand_fill(const int & up_border); // заполнение массива случайными элементами
        void show();
        void InsertionSort(); // сортировка вставкой
        bool is_sorted(); // проверка на сортировку.
    };

SimpleSort::SimpleSort(const int & SIZE)
    {
        this->SIZE = SIZE;
        arr = new int[SIZE];
        end = arr + SIZE;
    };

SimpleSort::~SimpleSort()
    {
        delete [] arr;
    };

void SimpleSort::rand_fill(const int & up_border)// протестить с новой итерацией
    {
        if(up_border == 0) return;
        for(int * ptr = arr; ptr < end; ptr++)
            *ptr = (rand() % up_border);
    };

bool SimpleSort::is_sorted() // протестить с новой итерацией
    {
        for(int *ptr = arr+1; ptr < end; ptr++) 
            if(*ptr < *(ptr-1)) return false;
        return true;
    }

void SimpleSort::show()
    {
        for(int *ptr = arr; ptr < end; ptr++) 
            cout<<*ptr<<" ";
        cout<<endl;
    }

void SimpleSort::InsertionSort() // протестить с новой итерацией
    {   
        for(int * ptr = arr + 1; ptr < end; ptr++) // for(int it = 1; it < SIZE; it++)
            { 
                int element = * ptr; // int element = arr[it];
                int * last_ptr = (ptr-1); // int last_it = it - 1;
                while((last_ptr >= arr) && (*last_ptr > element)) // while((last_it > -1) && (arr[last_it] > element))
                    {
                        *(last_ptr+1) = *last_ptr; // arr[last_it+1] = arr[last_it];
                        last_ptr--; //  last_it--;
                    };
                *(last_ptr++) = element; // arr[++last_it] = element;
            };
    };

int main()
{
    srand(time(0));
    SimpleSort arr1(10);
    arr1.show();
    return 0;
}