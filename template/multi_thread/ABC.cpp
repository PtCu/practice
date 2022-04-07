

#include <condition_variable>
#include <thread>
#include <iostream>

std::condition_variable cv;
std::mutex mtx;
int turn = 1;
const int N = 10;


void f1()
{
    // notify_all()后可能有多个线程被唤醒，有时为了保护临界区就需要上锁，使得只能有一个线程能运行。
    // 如果不需要对临界区进行保护就可以在wait后直接unlock()。
    // 本例中没有临界区，所以不需要加锁。但是wait的第一个参数需要用锁，所以还得加上。（锁只是个摆设）
    // 假如唤醒后有两个线程都是turn为0时才执行，那就需要加锁了
    std::unique_lock lck(mtx);
    for (int i = 0; i < N; ++i)
    {
        // wait()只有同时得到锁，并且谓词为真时才会继续，否则就会陷入等待。
        // 等待时会将锁unlock()。所以本例中锁一直处于unlock状态，只有turn为合适值即可。
        cv.wait(lck, [&]
                { return turn == 0; });
        std::cout << "A\n";
        turn = 1;
        cv.notify_all();
    }
}
void f2()
{
    std::unique_lock lck(mtx);
    for (int i = 0; i < N; ++i)
    {
        cv.wait(lck, [&]
                { return turn == 1; });
        std::cout << "B\n";
        turn = 2;
        cv.notify_all();
    }
}
void f3()
{
    std::unique_lock lck(mtx);
    for (int i = 0; i < N; ++i)
    {
        cv.wait(lck, [&]
                { return turn == 2; });
        std::cout << "C\n";
        turn = 0;
        cv.notify_all();
    }
}
int main()
{
    std::thread th1(f1);
    std::thread th2(f2);
    std::thread th3(f3);

    th1.join();
    th2.join();
    th3.join();
    return 0;
}
