#include <iostream>
#include <fstream>
int main (){
	std::ofstream outfile ("population.data");
	if(!outfile.is_open()){
		std::cout << "Khong the mo file" << std::endl;
		return 1;
	}
	int year, births;
	int n=0;
	std::cout << "Nhap nam va so nguoi sinh ra (nhap -1 de dung): " << std::endl;
	while(true){
		std::cin >> year;
		if (year==-1){
			break;
		}
		std::cin >> births;
		outfile << year << "   " << births << std::endl;
		n++;
	}
	
	outfile.close();
	std::ifstream infile("population.data");
    if (!infile.is_open()) {
        std::cout << "Khong the mo file" << std::endl;
        return 1;
    }
    int minYear, maxYear;
    int minBirths = INT_MAX; 
    int maxBirths = INT_MIN; 

    while (infile >> year >> births) {
        if (births < minBirths) {
            minBirths = births;
            minYear = year; 
        }
        if (births > maxBirths) {
            maxBirths = births;
            maxYear = year; 
        }
    }
    infile.close(); 

    std::cout << "Nam co so nguoi sinh ra lon nhat: " << maxYear << std::endl;
    std::cout << "Nam co so nguoi sinh ra nho nhat: " << minYear << std::endl;

    return 0;
}
