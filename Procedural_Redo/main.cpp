#include<iostream>
#include<conio.h>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>

void displayStopFromFile(std::string filename);
void addExtraChildren(int count, std::vector<std::vector<std::string>> plan);
void addExtraWomen(int count, std::vector<std::vector<std::string>> plan);
void stopA(std::vector<std::vector<std::string>>& planA);
void stopB(std::vector<std::vector<std::string>>& planB);
void stopC(std::vector<std::vector<std::string>>& planC);
void stopD(std::vector<std::vector<std::string>>& planD);
void stopE(std::vector<std::vector<std::string>>& planE);
void stopF(std::vector<std::vector<std::string>>& planF);
void reset(std::vector<std::vector<std::string>>& plan);

int main() {

	std::vector<std::vector<std::string>> seatingPlan
	{
		{"X", "X", "X", "X"},
		{"X", "X", "X", "X"},
		{"X", "X", "X", "X"},
		{"X", "X", "X", "X"},
		{"X", "X", "X", "X"},
		{"X", "X", "X", "X"},
		{"X", "X", "X", "X"},
		{"X", "X", "X", "X"}
	};
	
	std::cout << "----------------------------------------------------" << std::endl;
	std::cout << "|  Welcome to the bus seating allocation program!  |" << std::endl;
	std::cout << "|  X -> denotes unoccupied seats.                  |" << std::endl;
	std::cout << "|  F -> denotes female passengers                  |" << std::endl;
	std::cout << "|  C -> denotes children                           |" << std::endl;
	std::cout << "|  M -> denotes Men / Male teenagers               |" << std::endl;
	std::cout << "----------------------------------------------------" << "\n\n";

	char userInput;

	do {
		std::cout << "Press D to view all the sitting plans." << std::endl;
		std::cout << "Press any number between 1-5 to view a specific sitting plan." << std::endl;
		std::cout << "Press R to reset the plans." << std::endl;
		std::cout << "Press Q to quit." << "\n\n";

		userInput = _getch();

		switch (userInput) {
		case 'd':

			std::cout << "-------------------" << std::endl;

			stopA(seatingPlan);

			std::cout << "-------------------" << std::endl;

			stopB(seatingPlan);

			std::cout << "-------------------" << std::endl;

			stopC(seatingPlan);

			std::cout << "-------------------" << std::endl;

			stopD(seatingPlan);

			std::cout << "-------------------" << std::endl;

			stopE(seatingPlan);

			std::cout << "-------------------" << std::endl;

			stopF(seatingPlan);

			std::cout << "-------------------" << "\n\n";
			break;
		case '1':
			std::cout << "Seating plan 1: " << "\n\n";
			displayStopFromFile("viewStopA.txt");
			break;
		case '2':
			std::cout << "Seating plan 2: " << "\n\n";
			displayStopFromFile("viewStopB.txt");
			break;
		case '3':
			std::cout << "Seating plan 3: " << "\n\n";
			displayStopFromFile("viewStopC.txt");
			break;
		case '4':
			std::cout << "Seating plan 4: " << "\n\n";
			displayStopFromFile("viewStopD.txt");
			break;
		case '5':
			std::cout << "Seating plan 5: " << "\n\n";
			displayStopFromFile("viewStopE.txt");
			break;
		case 'r':
			reset(seatingPlan);
			break;
		case 'q':
			std::cout << "Thank you for using the program!" << std::endl;
			break;
		default:
			std::cout << "Invalid input!" << "\n\n";
			break;
		}
	} while (userInput != 'q');


	return 0;
}

void displayStopFromFile(std::string filename) {

	std::ifstream readPlanA(filename);
	std::string readAstr;
	
	while (std::getline(readPlanA, readAstr)) {
		std::cout << readAstr << std::endl;
	}

	readPlanA.close();

	std::cout << "\n";
}

void addExtraChildren(int count, std::vector<std::vector<std::string>> plan) {
	if (count > 0) {
		for (int i = 4; i < 8; i++) {
			for (int j = 0; j < 4; j++) {
				if (plan[i][j] == "X" && count > 0) {
					plan[i][j] = "C";
					count--;
				}
			}
		}
	}
}

void addExtraWomen(int count, std::vector<std::vector<std::string>> plan) {
	if (count > 0) {
		for (int i = 4; i < 8; i++) {
			for (int j = 0; j < 4; j++) {
				if (plan[i][j] == "X" && count > 0) {
					plan[i][j] = "F";
					count--;
				}
			}
		}
	}
}

void stopA(std::vector<std::vector<std::string>>& planA) {

	std::ifstream readStopA("stopA.txt");
	int countFemaleA = 0;
	int countMaleA = 0;
	std::string passengersEnteringA;
	std::vector<char> vectA;

	std::getline(readStopA, passengersEnteringA);
	for (int i = 0; i < passengersEnteringA.size(); i++) {
		vectA.push_back(passengersEnteringA[i]);
	}

	for (int i = 0; i < vectA.size(); i++) {
		if (vectA[i] == 'F') {
			countFemaleA++;
		}
	}

	for (int i = 0; i < vectA.size(); i++) {
		if (vectA[i] == 'M') {
			countMaleA++;
		}
	}

	std::cout << "_Stop A_" << "\n\n";
	std::cout << "Number of female passengers: " << countFemaleA << std::endl;
	std::cout << "Number of male passengers: " << countMaleA << "\n\n";

	//5 men board the bus
	for (int i = 4; i < 8; i++) {
		for (int j = 0; j < 4; j++) {
			if (planA[i][j] == "X" && countMaleA > 0) {
				planA[i][j] = "M";
				countMaleA--;
			}
		}
	}

	std::ofstream writeStopA("viewStopA.txt");

	//adding ladies and printing stop A
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 4; j++) {
			if (planA[i][j] == "X" && countFemaleA > 0) {
				planA[i][j] = "F";
				countFemaleA--;
			}
			std::cout << planA[i][j] << " ";
			writeStopA << planA[i][j] << " ";
		}
		std::cout << std::endl;
		writeStopA << "\n";
	}

	writeStopA.close();

	addExtraWomen(countFemaleA, planA);

}

void stopB(std::vector<std::vector<std::string>>& planB) {

	std::ifstream readStopB("stopB.txt");
	int countFemaleB = 0;
	int countChildrenEnteringB = 0;
	int countFemaleExitingB = 0;
	std::string passengersEnteringB;
	std::string passengersExitingB;
	std::vector<char> vectOneB;
	std::vector<char> vectTwoB;

	std::getline(readStopB, passengersEnteringB);
	for (int i = 0; i < passengersEnteringB.size(); i++) {
		vectOneB.push_back(passengersEnteringB[i]);
	}

	std::getline(readStopB, passengersExitingB);
	for (int i = 0; i < passengersExitingB.size(); i++) {
		vectTwoB.push_back(passengersExitingB[i]);
	}

	for (int i = 0; i < vectOneB.size(); i++) {
		if (vectOneB[i] == 'F') {
			countFemaleB++;
		}
	}

	for (int i = 0; i < vectOneB.size(); i++) {
		if (vectOneB[i] == 'C') {
			countChildrenEnteringB++;
		}
	}

	for (int i = 0; i < vectTwoB.size(); i++) {
		if (vectTwoB[i] == 'F') {
			countFemaleExitingB++;
		}
	}

	std::cout << "_Stop B_" << "\n\n";
	std::cout << "Number of female passengers: " << countFemaleB << std::endl;
	std::cout << "Number of child passengers: " << countChildrenEnteringB << std::endl;
	std::cout << "Number of female passengers exiting: " << countFemaleExitingB << "\n\n";

	//adding ladies of the family
	for (int i = 0; i < 8; i++) {
		for (int j = 3; j < 4; j++) {
			if (planB[i][j] == "X" && countFemaleB > 0) {
				planB[i][j] = "F";
				countFemaleB--;
			}
		}
	}

	//adding children from the family
	for (int i = 1; i < 8; i++) {
		for (int j = 0; j < 4; j++) {
			if (planB[i][j] == "X" && countChildrenEnteringB > 0 && j != 3) {
				planB[i][j] = "C";
				countChildrenEnteringB--;
			}
		}
	}

	//one passenger from previous stop left
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 4; j++) {
			if (planB[i][j] == "F" && countFemaleExitingB > 0) {
				planB[i][j] = "X";
				countFemaleExitingB--;
			}
		}
	}

	std::ofstream writeStopB("viewStopB.txt");

	//printing stop B
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << planB[i][j] << " ";
			writeStopB << planB[i][j] << " ";
		}
		std::cout << std::endl;
		writeStopB << "\n";
	}

	writeStopB.close();

	addExtraChildren(countChildrenEnteringB, planB);
	addExtraWomen(countFemaleB, planB);

}

void stopC(std::vector<std::vector<std::string>>& planC) {

	std::ifstream readStopC("stopC.txt");
	int countFemaleC = 0;
	int countMaleC = 0;
	int countFemaleExitingC = 0;
	int countChildrenExitingC = 0;
	std::string passengersEnteringC;
	std::string passengersExitingC;
	std::vector<char> vectOneC;
	std::vector<char> vectTwoC;

	std::getline(readStopC, passengersEnteringC); 
	for (int i = 0; i < passengersEnteringC.size(); i++) {
		vectOneC.push_back(passengersEnteringC[i]);
	}
	
	std::getline(readStopC, passengersExitingC);
	for (int i = 0; i < passengersExitingC.size(); i++) {
		vectTwoC.push_back(passengersExitingC[i]);
	}
	
	for (int i = 0; i < vectOneC.size(); i++) {
		if (vectOneC[i] == 'F') {
			countFemaleC++;
		}
	}

	for (int i = 0; i < vectOneC.size(); i++) {
		if (vectOneC[i] == 'M') {
			countMaleC++;
		}
	}

	for (int i = 0; i < vectTwoC.size(); i++) {
		if (vectTwoC[i] == 'F') {
			countFemaleExitingC++;
		}
	}

	for (int i = 0; i < vectTwoC.size(); i++) {
		if (vectTwoC[i] == 'C') {
			countChildrenExitingC++;
		}
	}

	std::cout << "_Stop C_" << "\n\n";
	std::cout << "Number of female passengers: " << countFemaleC << std::endl;
	std::cout << "Number of male passengers: " << countMaleC << std::endl;
	std::cout << "Number of female passengers exiting: " << countFemaleExitingC << std::endl;
	std::cout << "Number of child passengers exiting: " << countChildrenExitingC << "\n\n";

	//2 chidlren leaving the bus
	for (int i = 1; i < 8; i++) {
		for (int j = 0; j < 4; j++) {
			if (planC[i][j] == "C" && countChildrenExitingC > 0) {
				planC[i][j] = "X";
				countChildrenExitingC--;
			}
		}
	}

	//2 ladies leaving the bus
	for (int i = 0; i < 8; i++) {
		for (int j = 2; j < 4; j++) {
			if (planC[i][j] == "F" && countFemaleExitingC > 0) {
				planC[i][j] = "X";
				countFemaleExitingC--;
			}
		}
	}

	//3 men board the bus
	for (int i = 5; i < 8; i++) {
		for (int j = 1; j < 4; j++) {
			if (planC[i][j] == "X" && countMaleC > 0) {
				planC[i][j] = "M";
				countMaleC--;
			}
		}
	}

	//5 ladies board the bus
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 4; j++) {
			if (planC[i][j] == "X" && countFemaleC > 0) {
				planC[i][j] = "F";
				countFemaleC--;
			}
		}
	}

	std::ofstream writeStopC("viewStopC.txt");

	//printing stop C
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << planC[i][j] << " ";
			writeStopC << planC[i][j] << " ";
		}
		std::cout << std::endl;
		writeStopC << "\n";
	}

	writeStopC.close();

	addExtraWomen(countFemaleC, planC);

}

void stopD(std::vector<std::vector<std::string>>& planD) {

	std::ifstream readStopD("stopD.txt");
	int countMaleD = 0;
	int countFemaleD = 0;
	std::string passengersEnteringD;
	std::vector<char> vectD;

	std::getline(readStopD, passengersEnteringD);
	for (int i = 0; i < passengersEnteringD.size(); i++) {
		vectD.push_back(passengersEnteringD[i]);
	}

	for (int i = 0; i < vectD.size(); i++) {
		if (vectD[i] == 'M') {
			countMaleD++;
		}
	}

	for (int i = 0; i < vectD.size(); i++) {
		if (vectD[i] == 'F') {
			countFemaleD++;
		}
	}

	std::cout << "_Stop D_" << "\n\n";
	std::cout << "Number of male passengers: " << countMaleD << "\n\n";

	//6 men board the bus 
	for (int i = 6; i < 8; i++) {
		for (int j = 0; j < 4; j++) {
			if (planD[i][j] == "X" && countMaleD > 0) {
				planD[i][j] = "M";
				countMaleD--;
			}
		}
	}

	std::ofstream writeStopD("viewStopD.txt");

	//printing stop D
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << planD[i][j] << " ";
			writeStopD << planD[i][j] << " ";
		}
		std::cout << std::endl;
		writeStopD << "\n";
	}

	writeStopD.close();

	addExtraWomen(countFemaleD, planD);

}

void stopE(std::vector<std::vector<std::string>>& planE) {

	std::ifstream readStopE("stopE.txt");
	int countMaleTeenagers = 0;
	int countFemaleEnteringE = 0;
	int countFemaleExitingE = 0;
	int countChildrenExitingE = 0;
	std::string passengersEnteringE;
	std::string passengersExitingE;
	std::vector<char> vectOneE;
	std::vector<char> vectTwoE;

	std::getline(readStopE, passengersEnteringE);
	for (int i = 0; i < passengersEnteringE.size(); i++) {
		vectOneE.push_back(passengersEnteringE[i]);
	}

	std::getline(readStopE, passengersExitingE);
	for (int i = 0; i < passengersExitingE.size(); i++) {
		vectTwoE.push_back(passengersExitingE[i]);
	}

	for (int i = 0; i < vectOneE.size(); i++) {
		if(vectOneE[i] == 'M') {
			countMaleTeenagers++;
		}
		if (vectOneE[i] == 'F') {
			countFemaleEnteringE++;
		}
	}

	for (int i = 0; i < vectTwoE.size(); i++) {
		if (vectTwoE[i] == 'F') {
			countFemaleExitingE++;
		}
		if (vectTwoE[i] == 'C') {
			countChildrenExitingE++;
		}
	}

	std::cout << "_Stop E_" << "\n\n";
	std::cout << "Number of teenage male passengers: " << countMaleTeenagers << std::endl;
	std::cout << "Number of female passengers exiting: " << countFemaleExitingE << std::endl;
	std::cout << "Number of child passengers exiting: " << countChildrenExitingE << "\n\n";

	//1 lady leaving the bus
	for (int i = 1; i < 8; i++) {
		for (int j = 3; j < 4; j++) {
			if (planE[i][j] == "F" && countFemaleExitingE > 0) {
				planE[i][j] = "X";
				countFemaleExitingE--;
			}
		}
	}

	//2 children leaving the bus
	for (int i = 2; i < 8; i++) {
		for (int j = 0; j < 4; j++) {
			if (planE[i][j] == "C" && countChildrenExitingE > 0) {
				planE[i][j] = "X";
				countChildrenExitingE--;
			}
		}
	}

	//4 male teenagers board the bus
	for (int i = 7; i < 8; i++) {
		for (int j = 0; j < 4; j++) {
			if (planE[i][j] == "X" && countMaleTeenagers > 0) {
				planE[i][j] = "M";
				countMaleTeenagers--;
			}
		}
	}

	std::ofstream writeStopE("viewStopE.txt");

	//printing stop E
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << planE[i][j] << " ";
			writeStopE << planE[i][j] << " ";
		}
		std::cout << std::endl;
		writeStopE << "\n";
	}

	writeStopE.close();

	addExtraWomen(countFemaleEnteringE, planE);

	std::cout << std::endl;

	std::cout << "Only two male teenagers can be accomodated in stop E since the men's section is full!" << "\n";

}

void stopF(std::vector<std::vector<std::string>>& planF) {

	//print stop F
	std::cout << "_Stop F_ (End of route, everyone boards off the bus)" << "\n\n";

	std::ofstream writeStopF("viewStopF.txt");

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 4; j++) {
			if (planF[i][j] == "F" || planF[i][j] == "M" || planF[i][j] == "C") {
				planF[i][j] = "X";
			}
			std::cout << planF[i][j] << " ";
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 4; j++) {
			writeStopF << planF[i][j] << " ";
		}
		writeStopF << "\n";
	}

	writeStopF.close();

}

void reset(std::vector<std::vector<std::string>>& plan) {

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 4; j++) {
			if (plan[i][j] == "F" || plan[i][j] == "M" || plan[i][j] == "C") {
				plan[i][j] = "X";
			}
			std::cout << plan[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	//to erase the content of files.
	std::ofstream stopA;
	stopA.open("viewStopA.txt", std::ofstream::out | std::ofstream::trunc);
	stopA.close();

	std::ofstream stopB;
	stopB.open("viewStopB.txt", std::ofstream::out | std::ofstream::trunc);
	stopB.close();

	std::ofstream stopC;
	stopC.open("viewStopC.txt", std::ofstream::out | std::ofstream::trunc);
	stopC.close();

	std::ofstream stopD;
	stopD.open("viewStopD.txt", std::ofstream::out | std::ofstream::trunc);
	stopD.close();

	std::ofstream stopE;
	stopE.open("viewStopE.txt", std::ofstream::out | std::ofstream::trunc);
	stopE.close();

	std::ofstream stopF;
	stopF.open("viewStopF.txt", std::ofstream::out | std::ofstream::trunc);
	stopF.close();

	std::cout << "plans have been reset!" << "\n\n";

}