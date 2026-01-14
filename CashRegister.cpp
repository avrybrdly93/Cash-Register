#include <iostream>
#include <iomanip>
#include <list>
//#include <CL/opencl.hpp>
//#define CL_HPP_ENABLE_EXCEPTIONS   

double TotalCost, CashReceived, Change;
int Cents, ChangeBills, NumHundreds, ChangeAfterHundreds, NumFifties, ChangeAfterFifties, NumTwenties, ChangeAfterTwenties, 
NumTens,ChangeAfterTens, NumFives,ChangeAfterFives, NumOnes, ChangeAfterOnes, 
NumQuarters, ChangeAfterQ, NumDimes, ChangeAfterD, NumNickels,ChangeAfterN, NumPennies, ChangeVar;

bool BillChange = false;
bool alreadyNegative = false;

int randTest = rand();

// Array of 10 random values 
//std::list<double> costsOfItems = {0.01, 0.08, 0.15, 0.26, 0.83, 0.47, 0.63, 0.79, 0.11, 0.85, 0.02, 0.10};
std::list<std::list<int>> changeBoring;
std::list<std::list<int>> changeExciting;

// numTotalCents sets the limit for the total individual cases. The number is converted into a dollar amount by
// dividing by 100
// Values and times in seconds for CPU:
// 100000 - 277.421
// 10000 -  23.537
// 1000 - 2.767
// 100 - 0.476 seconds
// 10 - 0.029
int numTotalCents = 200;
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

std::list<double> createCostAmtGiven() {
    double cost = 0.00;
    std::list<double> costAmtGivenList;
    std::list<double> costList;
    std::list<double> amtGivenList;
    std::list<double> differenceList;

    for(int i = 0; i < numTotalCents; i++) {
        costList.push_back(cost);
        amtGivenList.push_back(cost);
        cost += 0.01;
        }
        std::cout << "asdf: " << numTotalCents;
    amtGiven = static_cast<double>(numTotalCents) / 100;

    std::cout << "amtGiven: " << amtGiven << std::endl;
    for(double cost : costList) {
        std::cout << "Cost: " << cost << std::endl;
        double difference = amtGiven - cost;
        std::cout << " " << difference << " ";
        costAmtGivenList.push_back(difference);
        // for(double amtGiven : amtGivenList) {
        //     double difference = amtGiven - cost;
        //     differenceList.push_back(difference);
        //     std::cout << " " << difference << " ";
        // }
        std::cout << std::endl;
        //costAmtGivenMatrix.push_back(costList);
    }

    return costAmtGivenList;
}


std::list<std::list<int>> boringMethod(std::list<double> costsOfItems) {
    std::list<std::list<int>> boringList;
    std::list<int> coinsList;
    // if (Change > 1) {
	// 	ChangeBills = Change;
    //     NumHundreds = ChangeBills / 100;
    //     ChangeAfterHundreds = ChangeBills % 100;
    //     NumFifties = ChangeAfterHundreds / 50;
    //     ChangeAfterFifties = ChangeAfterHundreds % 50;
	// 	NumTwenties = ChangeAfterTwenties / 20;
	// 	ChangeAfterTwenties = ChangeAfterTwenties % 20;
	// 	NumTens = ChangeAfterTwenties / 10;
	// 	ChangeAfterTens = ChangeAfterTwenties % 10;
	// 	NumFives = ChangeAfterTens / 5;
	// 	ChangeAfterFives = ChangeAfterTens % 5;
	// 	NumOnes = ChangeAfterFives;
	// 	ChangeVar = 100 * Change;
	// 	Cents = ChangeVar % 100; 
	// 	BillChange = true;
	// } else {
        for(double cost : costsOfItems) {  
            // ChangeBills = Change;
            // NumHundreds = ChangeBills / 100;
            // ChangeAfterHundreds = ChangeBills % 100;
            // NumFifties = ChangeAfterHundreds / 50;
            // ChangeAfterFifties = ChangeAfterHundreds % 50;
            // NumTwenties = ChangeAfterTwenties / 20;
            // ChangeAfterTwenties = ChangeAfterTwenties % 20;
            // NumTens = ChangeAfterTwenties / 10;
            // ChangeAfterTens = ChangeAfterTwenties % 10;
            // NumFives = ChangeAfterTens / 5;
            // ChangeAfterFives = ChangeAfterTens % 5;
            // NumOnes = ChangeAfterFives;
            ChangeVar = 100 * Change;
            Cents = ChangeVar % 100; 
            Change = CashReceived - cost;
            Cents = Change * 100;
            int Cents100 = Change * 100;
            NumQuarters = Cents / 25;
            ChangeAfterQ = Cents % 25;
            NumDimes = ChangeAfterQ / 10;
            ChangeAfterD = ChangeAfterQ % 10;
            NumNickels = ChangeAfterD / 5;
            ChangeAfterN = ChangeAfterD % 5;
            NumPennies = ChangeAfterN;   

            for(int coin : coinsList) {
                std::cout << "" << coin << " ";
            }
            std::cout << std::endl;
           // std::cout << "Cents: " << Cents << ". Quarters: " << NumQuarters << " Change: " << Change << "\n" << Cents100;
            coinsList = {NumHundreds, NumFifties, NumTwenties, NumTens, NumFives, NumOnes, NumDimes, NumNickels, NumPennies};
            boringList.push_back(coinsList);
        }
	//}
	
    return boringList;
}

//Double check how the function works from start to finish with current setup

std::list<std::list<int>> excitingApproach(std::list<double> costsOfItems) {
    std::list<std::list<int>> excitingList;
    std::list<int> excitingCoins;

     for(double cost : costsOfItems) {  
        //NumQuarters, NumNickels, NumDimes, NumPennies = 0,0,0,0;
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
        ChangeVar = 100 * Change;
        Cents = ChangeVar % 100; 
        NumPennies = Cents;
        while(NumPennies > 4) {
            NumNickels++;
            NumPennies -= 5;
            //printCoinAmounts(NumPennies, NumNickels, NumDimes, NumQuarters);
            //std::cout << "pennies to nickels." << std::endl;
        }
        while(NumNickels > 4) {
            NumQuarters++;
            NumNickels -= 5;
         //printCoinAmounts(NumPennies, NumNickels, NumDimes, NumQuarters);
          //  std::cout << "nickels to quarters." << std::endl;
        }

        while(NumNickels > 1) {
            NumDimes++;
            NumNickels -= 2;
        // printCoinAmounts(NumPennies, NumNickels, NumDimes, NumQuarters);
        // std::cout << "nickels to dimes." << std::endl;
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

        for(int coin : excitingCoins) {
                //std::cout << "" << coin << " ";
            }
        std::cout << std::endl;

        excitingCoins = {NumHundreds, NumFifties, NumTwenties, NumTens, NumFives, NumOnes, NumDimes, NumNickels, NumPennies};
        excitingList.push_back(excitingCoins);
    }

    return excitingList;
}

int main() {
    
    // Modifyable variables
	bool inputMode = false;
    bool weWantBoring = false;

    //createCostAmtGiven();

    std::list<std::list<int>> boringList;
    std::list<std::list<int>> excitingList;

    if(inputMode) {
        do {
            if(alreadyNegative) {
                std::cout << "The cost shouldn't be negative. Try entering a positive value." << std::endl;
            } else {
                std::cout << "What is the total cost?" << std::endl;
            }
            std::cin >> TotalCost;

            alreadyNegative = true;
        } while (TotalCost < 0);

        if(TotalCost > 0) {
            std::cout << "How much cash was received?" << std::endl;
            std::cin >> CashReceived;
            Change = CashReceived - TotalCost;
            std::cout << std::setprecision(2) << std::fixed;
            std::cout << "You should give $" <<  Change << " in change." << std::endl;
        } else {
            std::cout << "Please enter a valid amount." << std::endl;
        }
    } else {
        std::list<double> costAmtGivenList = createCostAmtGiven();
        CashReceived = amtGiven;

        clock_t boringStartTime = StartTimer();
        //Both methods running to compare later
        boringList = boringMethod(costAmtGivenList);
        clock_t boringTime = StopTimer(boringStartTime);
        clock_t excitingStartTime = StartTimer();
        excitingList = excitingApproach(costAmtGivenList);
        clock_t excitingTime = StopTimer(excitingStartTime);

        for(std::list<int> boringCoins : boringList) {
            for(int boringCoin : boringCoins) {
                std::cout << " " << boringCoin << " ";
            }
            std::cout << "" << std::endl;
        }
        std::cout << " " << std::endl;
        for(std::list<int> excitingCoins : excitingList) {
            for(int excitingCoin : excitingCoins) {
                std::cout << " " << excitingCoin << " ";
            }
            std::cout << "" << std::endl;
        }

        std::cout << "Boring time: " << (float)boringTime / CLOCKS_PER_SEC << std::endl;
        std::cout << "Exciting time: " << (float)excitingTime / CLOCKS_PER_SEC << std::endl;

    }
    	if (BillChange) {
		std::cout << "The change is " << NumTwenties << " twenties, " << NumTens
			 << " tens, " << NumFives << " fives, and " << NumOnes << " ones, "
			 << NumQuarters << " quarters, " << NumDimes << " dimes, "
			 << NumNickels << " nickels, and " << NumPennies << " pennies."
		   	<< std::endl;
	} else {
		std::cout << "This would be best given by giving "
		 << NumQuarters << " quarters, " << NumDimes << " dimes, "
		 << NumNickels << " nickels, and " << NumPennies << " pennies."
		 << std::endl;
		}

       // clock_t stopTime = StopTimer(startTime);
       // PrintTime(stopTime);
}
