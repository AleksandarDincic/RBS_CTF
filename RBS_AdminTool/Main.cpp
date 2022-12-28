#include<iostream>

void capture_flag()
{
    std::cout<<"You captured the flag!" << std::endl;
}

void changeCarPrices(long numCars, long deltaPrice) {
    long prices[4] = { 0,0,0,0 };
    for (int i = 0; i < numCars; ++i) {
        std::cout << "Old price: " << prices[i];
        prices[i] += deltaPrice;
        std::cout << " New price: " << prices[i] << std::endl;
    }
}

int main(){
    std::cout << std::hex << sizeof(long) << std::endl;
    long numCars, deltaPrice;
    std::cout << "Enter the number of cars" << std::endl;
    std::cin >> numCars;
    std::cout << "Enter price change" << std::endl;
    std::cin >> deltaPrice;
    changeCarPrices(numCars, deltaPrice);
    return 0;
    capture_flag();
}