#include <iostream>
template <typename T>

void pushBack(T*& array, int& size, T newValue)
{
    
    T* array1=new T[size+1];
    for(int i=0; i<size; ++i)
    {
        array1[i]=array[i];
    }
    array1[size]=newValue;
    delete[] array;
    array=array1;
    size++;
}

int main(int argc, char** argv)
{
 
    int size=3;
    int* array=new int[size]{1,2,3};
    for(int i=0; i<size; ++i)
    {
        std::cout <<array[i] <<' ';
    }
    std::cout<<std::endl;
    pushBack(array,size,5);
    for(int i=0; i<size; ++i)
    {
        std::cout <<array[i] <<' ';
    }
    delete [] array;
}