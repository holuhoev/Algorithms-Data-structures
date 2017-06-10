#include <iostream>
#include "fifo.h"

class kekShmek{
public:
    kekShmek(){}
    vector<int> myVector(){
        return vector<int>{1,2,3};
    }
};

/** --------2---------*/
template <typename T>
void swap(T& a, T& b)
{
    T temp(std::move(a));
    a = std::move(b);
    b = std::move(temp);
}

int main()
{
//    fifo sim(2);
//    sim.simulate("/Users/evgenijlebedev/ClionProjects/2_7/bigfirst.run");
    /** --------1---------*/
    std::vector<int> vector1 {1,2,3};
    std::vector<int> vector3;


    vector3 = std::move(vector1);

    cout << vector1.front();

    std::vector<std::vector<int> > vector2;




    vector2.push_back(std::move(vector1));



    //move возвращает ссылку на нечто, что содержит значение, это значение больше никому не нужно xvalue("expiring value")
    // как будто функция возвращает ссылку на значение , которое собирается помирать
    /** move - преобразование которое возвращает ссылку на rvalue, которое является xvalue , которое скоро пропадет */
    return 0;
}