#include <iostream>
#include <string>

class smart_array {
public:

    smart_array(smart_array & src)
    {
        kol_elem = src.kol_elem_massiv();
        kol_elem_max = src.max_kol_eleme_massiv();
        ptr = new int[kol_elem_max] {0};
        for (int i = 0; i < kol_elem; i++)
        {
            ptr[i] = src.get_element(i);
        }

    }

    smart_array& operator=( smart_array& src)
{
    // проверяем на самоприсваивание
    if(this==&src)
    {
        return *this;
    }

    // освобождаем занятую память

    delete[] ptr;

    // выделяем память

    kol_elem = src.kol_elem_massiv();
    kol_elem_max=src.max_kol_eleme_massiv();
    ptr = new int[kol_elem_max] {0};
    for (int i = 0; i < kol_elem; i++)
    {
        ptr[i] = src.get_element(i);
    }

    // возвращаем ссылку на перезаписанный объект

    return *this;
}

    smart_array(int size)
    {
        ptr = new int[size] {0};
        kol_elem_max = size;
    }
    ~smart_array()
    {
        delete[] ptr;
    }
    void add_element(int new_elem)
    {



        if (kol_elem < kol_elem_max)
        {
            ptr[kol_elem++] = new_elem;
        }
        else
        {
            throw std::exception("dostignuto maksimalnoe kolishesytvo elementov.dobavit nelsia.");
        }

    }
    int get_element(int num)
    {

        if ((num >= 0) && (num <= kol_elem))
        {
            return ptr[num];
        }
        else
        {
            throw std::exception("zatrebovanni element vihodit za predeli massiva.");
        }
    }
    int del_element()
    {
        if (kol_elem > 0)
        {
            return ptr[kol_elem--];
        }
        else
        {
            throw std::exception("Vse elementi udaleni. udaliat neshego.");
        }

    }
    int kol_elem_massiv()
    {
        return kol_elem;
    }
    int max_kol_eleme_massiv()
    {
        return kol_elem_max;
    }
    std::string vivod(int num)
    {

        std::string message = "Затребованный элемент массива с номером (" + std::to_string(num) + ")=" + std::to_string(ptr[num]);
        return message;
    }
private:
    int kol_elem = 0;
    int kol_elem_max;
    int* ptr;





};

int main()
{

    setlocale(LC_ALL, "Russian");

    smart_array arr(5);
    arr.add_element(1);
    arr.add_element(4);
    arr.add_element(155);

    smart_array new_array(2);
    new_array.add_element(44);
    new_array.add_element(34);
    std::cout << "Объект new_array. " << new_array.vivod(1) << std::endl;
    std::cout << "Объект arr. "<<arr.vivod(1) << std::endl;
    arr = new_array;
    std::cout << "Объект new_array. " <<new_array.vivod(1)<<std::endl;
    std::cout << "Объект arr. " << arr.vivod(1) << std::endl;

    smart_array new_array_2(arr);
    std::cout << "Объект new_array_2. " << new_array_2.vivod(1) << std::endl;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
