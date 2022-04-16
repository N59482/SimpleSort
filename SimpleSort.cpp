#include <iostream>
#include <cstdlib>

using namespace std;

class SimpleSort
    {
        private:
        int * arr;
        int SIZE;
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
    };

SimpleSort::~SimpleSort()
    {
        delete [] arr;
    };

void SimpleSort::rand_fill(const int & up_border)
    {
        if(up_border == 0) return;
        for(int i = 0; i < SIZE; i++) // оптимизировать итерацию по массиву.
            arr[i] = (rand() % up_border);
    };

bool SimpleSort::is_sorted()
    {
        for(int i = 0; i < SIZE-1; i++) // оптимизировать итерацию по массиву.
            if(arr[i] > arr[i+1]) return false;
        return true;

    }

void SimpleSort::show()
    {
        for(int i = 0; i < SIZE; i++) // оптимизировать итерацию по массиву.
            cout<<arr[i]<<" ";
        cout<<endl;
    }

void SimpleSort::InsertionSort()
    {   
        for(int it = 1; it < SIZE; it++)
            {
                int element = arr[it];
                // cout<<"берем элемент "<<element<<endl;
                int last_it = it - 1;
                // cout<<"и предыдущий за ним "<<arr[last_it]<<endl;
                while((last_it > -1) && (arr[last_it] > element))
                    {
                        // cout<<"Элемент "<<arr[last_it]<<" больше чем "<<element<<"\nпоэтому сдвигаем элементы\n";
                        arr[last_it+1] = arr[last_it]; 
                        last_it--;
                        show();
                    };
                arr[++last_it] = element;
                
            };

    };

int main()
{
    srand(time(0));
    SimpleSort arr1(5);
    arr1.rand_fill(10);
    arr1.show();
    cout<<((arr1.is_sorted()) ? "Collection is sorted\n" : "Collection is NOT sorted!\n");
    arr1.InsertionSort();
    cout<<((arr1.is_sorted()) ? "Collection is sorted\n" : "Collection is NOT sorted!\n");
    return 0;
}