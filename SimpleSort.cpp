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
        void SelectionSort(); // сортировка выбором
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

void SimpleSort::rand_fill(const int & up_border)
    {
        if(up_border == 0) return;
        for(int * ptr = arr; ptr < end; ptr++)
            *ptr = (rand() % up_border);
    };

bool SimpleSort::is_sorted()
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

void SimpleSort::InsertionSort() 
    {   
        for(int * ptr = arr + 1; ptr < end; ptr++)
            { 
                int element = * ptr;
                int * last_ptr = (ptr-1);
                while((last_ptr >= arr) && (*last_ptr > element))
                    {
                        *(last_ptr+1) = *last_ptr;
                        last_ptr--;
                    };
                *(++last_ptr) = element; 
            };
    };

void SimpleSort::SelectionSort() 
    {
        for(int * ptr = arr; ptr < end-1; ptr++)
            {
                int * min =  ptr;
                for(int *ptr2 = ptr + 1; ptr2 < end; ptr2++)
                    {
                        if(*ptr2 < *min) min = ptr2;
                    }
                if(ptr != min) swap(*ptr,*min);
            }
    };

int main()
{
    srand(time(0));
    SimpleSort arr1(3);
    int tests = 10;
    for(int i = 0; i < tests; i++)
    {
        arr1.rand_fill(10);
        arr1.show();
        arr1.InsertionSort();
        arr1.show();
        cout<<((arr1.is_sorted())? "collection is sorted":"collection is NOT sorted")<<endl;
    };
    return 0;
}