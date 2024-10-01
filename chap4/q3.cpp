#include <iostream>

#define GRAVITY_CONST 9.8

double getTowerHeight() {
    double height;
    std::cout << "Enter the height: ";
    std::cin >> height;
    return height;
}

double calcFall(int time) {
    return GRAVITY_CONST * time * time / 2;
}

int main() {
    double towerHeight {getTowerHeight()};
    double currentHeight {towerHeight};
    for (int time {0}; currentHeight>0; time++) {
        currentHeight = towerHeight - calcFall(time);
        
        if (currentHeight < 0) {
            std::cout << "Ball is on the ground.\n\n";
        } else {
            std::cout << "Current height in "<< time << " seconds: " << currentHeight << "\n";
        }
    }

    return 0;
}
