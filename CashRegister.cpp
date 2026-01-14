#include <iostream>
#include <iomanip>
#include <list>
#include <fstream>
#include <cmath>
#include <vector>

//#include <CL/opencl.hpp>
//#define CL_HPP_ENABLE_EXCEPTIONS   

double TotalCost, CashReceived, Change;
int Cents, ChangeBills, NumHundreds, ChangeAfterHundreds, NumFifties, ChangeAfterFifties, NumTwenties, ChangeAfterTwenties, 
NumTens,ChangeAfterTens, NumFives,ChangeAfterFives, NumOnes, ChangeAfterOnes, 
NumQuarters, ChangeAfterQ, NumDimes, ChangeAfterD, NumNickels,ChangeAfterN, NumPennies, ChangeVar;

bool BillChange = false;
bool alreadyNegative = false;

int randTest = rand();

std::list<std::list<int>> changeBoring;
std::list<std::list<int>> changeExciting;

// numTotalCents sets the limit for the total individual cases. The number is converted into a dollar amount by
// dividing by 100. 18641 is $186.41 which is one of each type of bill and one of each type of coin.

int numTotalCents = 18641;
double amtGiven;

clock_t StartTimer() {
    clock_t startTime = clock();
    return startTime;
}

clock_t StopTimer(clock_t startTime) {
    clock_t totalTime = clock() - startTime;
    return totalTime;
}

void PrintTime(clock_t totalTime) {
    std::cout << "Total Time: " << (float)totalTime / CLOCKS_PER_SEC << " seconds.";
}

void printCoinAmounts(int numPennies, int numNickels, int numDimes, int numQuarters) {
    std::cout << " Pennies: " << numPennies << " Nickels: " << numNickels << " Dimes: "
         << numDimes << " Quarters: " << numQuarters << std::endl;
}

std::vector<double> createCostAmtGiven() {
    double cost = 0.00;
    std::vector<double> costAmtGivenList;
    std::list<double> costList;
    std::list<double> amtGivenList;
    std::list<double> differenceList;

    for(int i = 0; i < numTotalCents; i++) {
        cost += 0.01;
        costList.push_back(cost);
        amtGivenList.push_back(cost);
        }
    amtGiven = static_cast<double>(numTotalCents) / 100;
    
    for(double cost : costList) {
        double difference = amtGiven - cost;
        costAmtGivenList.insert(costAmtGivenList.end(), difference);
    }

    return costAmtGivenList;
}
std::list<std::list<int>> boringMethod(std::vector<double> costsOfItems) {
    std::list<std::list<int>> boringList;
    std::list<int> coinsList;
        for(double cost : costsOfItems) {  
            Change = CashReceived - cost;
            ChangeBills = Change;
            NumHundreds = ChangeBills / 100;
            ChangeAfterHundreds = ChangeBills % 100;
            NumFifties = ChangeAfterHundreds / 50;
            ChangeAfterFifties = ChangeAfterHundreds % 50;
            NumTwenties = ChangeAfterFifties / 20;
            ChangeAfterTwenties = ChangeAfterFifties % 20;
            NumTens = ChangeAfterTwenties / 10;
            ChangeAfterTens = ChangeAfterTwenties % 10;
            NumFives = ChangeAfterTens / 5;
            ChangeAfterFives = ChangeAfterTens % 5;
            NumOnes = ChangeAfterFives / 1;
            ChangeAfterOnes = ChangeAfterFives % 1;
            ChangeVar = (int)std::round(100 * Change);
            ChangeAfterOnes = ChangeVar % 100;
            NumQuarters = ChangeAfterOnes / 25; 
            ChangeAfterQ = ChangeAfterOnes % 25;
            NumDimes = ChangeAfterQ / 10;
            ChangeAfterD = ChangeAfterQ % 10;
            NumNickels = ChangeAfterD / 5;
            ChangeAfterN = ChangeAfterD % 5;
            NumPennies = ChangeAfterN;   
            coinsList = {NumHundreds, NumFifties, NumTwenties, NumTens, NumFives, NumOnes, NumQuarters, NumDimes, NumNickels, NumPennies};
            boringList.push_back(coinsList);
        }
    return boringList;
}

// Finds out the values of each list of coins, to later compare with actual value.
double multiplyChange(std::list<int> coinList) {
    double currencyValues[10] = {0.01, 0.05, 0.1, 0.25, 1, 5, 10, 20, 50, 100};
    int i;
    i = 10;
    double totalAmount;
    for(int coin : coinList) {
         i--;
        totalAmount += coin * currencyValues[i];
    }
    return totalAmount;
}

//Double check how the function works from start to finish with current setup
std::list<std::list<int>> excitingApproach(std::vector<double> costsOfItems) {
    std::list<std::list<int>> excitingList;
    std::list<int> excitingCoins;

     for(double cost : costsOfItems) {  
        NumHundreds = 0;
        NumFifties = 0;
        NumTwenties = 0;
        NumTens = 0;
        NumFives = 0;
        NumOnes = 0;
        NumQuarters = 0;
        NumNickels = 0;
        NumPennies = 0;
        NumDimes = 0;
        Change = CashReceived - cost;
        NumPennies = (int)std::round(100 * Change);
        while(NumPennies > 4) {
            NumNickels++;
            NumPennies -= 5;
        }
        while(NumNickels > 4) {
            NumQuarters++;
            NumNickels -= 5;
        }
        while(NumNickels > 1) {
            NumDimes++;
            NumNickels -= 2;
        }
        while(NumQuarters > 3) {
            NumOnes++;
            NumQuarters -= 4;
        }
        while(NumOnes > 4) {
            NumFives++;
            NumOnes -= 5;
        }
        while(NumFives > 1) {
            NumTens++;
            NumFives -= 2;
        }
        while(NumTens > 4) {
            NumFifties++;
            NumTens -= 5;
        }
        while(NumTens > 1) {
            NumTwenties++;
            NumTens -= 2;
        }
        while(NumFifties > 1) {
            NumHundreds++;
            NumFifties -= 2;
        }

        excitingCoins = {NumHundreds, NumFifties, NumTwenties, NumTens, NumFives, NumOnes, NumQuarters, NumDimes, NumNickels, NumPennies};
        excitingList.push_back(excitingCoins);
    }

    return excitingList;
}

int main() {
    std::ofstream fileBoring("boringFile.csv");
    std::ofstream fileExciting("excitingFile.csv");
    
    // Modifyable variables
	bool inputMode = false;
    bool weWantBoring = false;
    bool hasDifference = false;

    std::list<std::list<int>> boringList;
    std::list<std::list<int>> excitingList;
    std::vector<double> costAmtGivenList = createCostAmtGiven();
    CashReceived = amtGiven;

    std::list<int> errorsList;

    clock_t boringStartTime = StartTimer();
    //Both methods running to compare later
    boringList = boringMethod(costAmtGivenList);
    clock_t boringTime = StopTimer(boringStartTime);
    clock_t excitingStartTime = StartTimer();
    excitingList = excitingApproach(costAmtGivenList);
    clock_t excitingTime = StopTimer(excitingStartTime);
    int i = numTotalCents - 1;
    std::cout << "Boring Method: " << std::endl;
    for(std::list<int> boringCoins : boringList) {
        for(int boringCoin : boringCoins) {
            if(i < 20) {
                std::cout << boringCoin;
            }
        }
        double totalAmount = multiplyChange(boringCoins);
        i--;
        double difference = totalAmount - costAmtGivenList[i];
        if(difference > 0.005 && i > 0) {
            hasDifference = true;
            errorsList.push_back(difference);
        }

        if(i < 20) {
            std::cout << std::endl;
        }
        fileBoring << "\n";
    }
    std::cout << " " << std::endl;

    std::cout << "Exciting Approach: " << std::endl;
    for(std::list<int> excitingCoins : excitingList) {
        for(int excitingCoin : excitingCoins) {
            if(i < 20) {
                std::cout << " " << excitingCoin << " ";
                }
        }
                double totalAmount = multiplyChange(excitingCoins);
        i--;
        if(i < 20) {
            std::cout << " "<< i;
        }

        double difference = totalAmount - costAmtGivenList[i];
        if(i < 20) {
                   std::cout << "Difference: " << difference;
            std::cout << std::endl;
        }

        if(difference > 0.005 && i > 0) {
            hasDifference = true;
            errorsList.push_back(difference);
        }
    }

    std::cout << "Boring time: " << (float)boringTime / CLOCKS_PER_SEC << std::endl;
    std::cout << "Exciting time: " << (float)excitingTime / CLOCKS_PER_SEC << std::endl;

    if(hasDifference == false) {
            std::cout << "Perfect, no errors here!:";
        } else {
            std::cout << " There were errors :(((( ";
            for(int error : errorsList) {
                std::cout << error << std::endl;
            }
        }
}
