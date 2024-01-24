#include <iostream>
#include <chrono>
#include <thread>

void boot() {
    std::cout << "booting...";
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "loading OS...";
    std::this_thread::sleep_for(std::chrono::seconds(3));
}

int main() {
    boot();
    return 0;
}