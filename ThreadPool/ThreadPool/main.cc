#include "ThreadPool.hpp"
#include "Task.hpp"
#include <memory>
#include <unistd.h>

int main()
{
    ThreadPool<Task>::getInstance()->run();

    // int x,y;
    // char op;
    while(true)
    {


 
        int x = rand() % 10;
        int y = rand() % 5;
        char op = oper[rand()%oper.size()];

        // std::cout << "请输入数据1# ";
        // std::cin >> x;
        // std::cout << "请输入数据2# ";
        // std::cin >> y;
        // std::cout << "请输入你要进行的运算#";
        // std::cin >> op;
        Task t(x,y,op,mymath);
        ThreadPool<Task>::getInstance()->push(t);
        //sleep(1);



    }
}
