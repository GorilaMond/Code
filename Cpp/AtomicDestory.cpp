#include <iostream>
#include <thread>
#include <atomic>

std::atomic<bool> flag(false);  // 全局标志位，用于线程同步
std::atomic<int> counter(0);  // 全局计数器
std::atomic_flag lock = ATOMIC_FLAG_INIT;  // 自旋锁

void incrementCounter1() {
    while (lock.test_and_set(std::memory_order_acquire)) {
        // 自旋等待获取锁
    }
    std::cout <<  1 << std::endl;
    for (int i = 0; i < 100000; ++i) {
        counter = 1 + counter;
    }
    std::cout <<  "1 complete" << std::endl;
    lock.clear(std::memory_order_release);  // 释放锁
    flag = true;  // 设置标志位，表示线程已完成
}

void incrementCounter2() {
    if (lock.test_and_set(std::memory_order_acquire)) {
        lock.clear(std::memory_order_release); // 破坏锁
    }
    lock.test_and_set(std::memory_order_acquire);
    std::cout << 2 << std::endl;
    for (int i = 0; i < 100000; ++i) {
        counter = 1 + counter;
    }
    std::cout <<  "2 complete" << std::endl;
    lock.clear(std::memory_order_release);  // 释放锁
    flag = true;  // 设置标志位，表示线程已完成
}

int main() {
    std::thread t1(incrementCounter1);
    std::thread t2(incrementCounter1);
    
    t1.join();
    t2.join();
    
    std::cout << "Counter: " << counter << std::endl;
    
    return 0;
}
