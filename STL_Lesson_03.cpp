#include <iostream>
#include <vector>

template <class T>
class OwnVector
{
private:
    T* arr;
    int size_arr;
    int counter;

    
public:
    OwnVector() {};
    OwnVector(T size)
    {
        arr = new T[size];
        this->size_arr = size;
    }
    ~OwnVector()
    {
        delete[] arr;
    }
    
    T& at(int index)
    {
        if ((index >= size_arr) || (index < 0))
        {
            throw std::runtime_error("Going outside of the array");
        }
        return arr[index];
    }
    void push_back(T value)
    {
        if (counter == (size_arr))
        {
            T* newArr = new T[size_arr];
            for (int i = 0; i < size_arr; i++)
            {
                
                newArr[i] = arr[i];
            }
            size_arr *= 2;
            arr = new T[size_arr];
            for (int i = 0; i < size_arr; i++)
            {

                arr[i] = newArr[i];
            }

            delete[] newArr;
        }
        arr[counter] = value;
        counter++;
    }
    int capacity()
    {
        return size_arr;
    }
    int size()
    {
        if (size_arr == 0)
        {
            throw std::runtime_error("Array is empty");
        }
        return counter;
    }
    

};
int main()
{
    OwnVector<int> arr(3);
    arr.push_back(1);
    arr.push_back(2);
    std::cout << "size: " << arr.size() << std::endl;
    arr.push_back(3);
    std::cout << "Capacity: " << arr.capacity() << std::endl;
    std::cout << "size: " << arr.size() << std::endl;
    std::cout << "at: " << arr.at(2) << std::endl;
    arr.push_back(4);
    std::cout << "Capacity: " << arr.capacity() << std::endl;
    std::cout << "size: " << arr.size() << std::endl;

}

