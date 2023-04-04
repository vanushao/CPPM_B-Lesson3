#include <iostream>

class Counter {
public:
    Counter() {
        count = 1;
    }
    Counter(int count) {
        this->count = count;
    }
    
    int get_count() {
        return count;
    }
    
    void add_count() {
        ++count;
    }

    void sub_count() {
        --count;
    }

private:
    int count;
};

int main()
{
    std::setlocale(LC_ALL, "Russian");
    Counter *C;
    std::string s;
    std::cout << "Вы хотите указать начальное значение счётчика? Введите yes или no: ";
    std::cin >> s;
    if (s == "yes") {
        int start;
        std::cout << "Введите начальное значение счётчика : ";
        std::cin >> start;
        C = new Counter(start);
    }
    else {
        C = new Counter();
    }
   
    
    bool exit = false;
    char command = 'x';
    do{
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> command;

        switch (command)
        {
        case '+':
            C -> add_count();
            break;
        case '-':
            C -> sub_count();
            break;
        case '=':
            std::cout << C -> get_count() << std::endl;
            break;
        default:
            exit = true;
            break;
        }
    } while (!exit);

    std::cout << "До свидания!" << std::endl;
    delete C;

    return 0;
}