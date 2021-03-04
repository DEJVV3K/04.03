#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class obrazek {
    public:
    ifstream fileIn;
    string obr [20] [20];
    string ob [20] [20];
    int licznikR;
    void run();
    void rekure(string obraz [20] [20]);
    bool rekur(string obraz [20] [20]);
};

void obrazek::run() {
    fileIn.open("dane_obrazki.txt");
    string linijka;
    string skipL;
    bool pierwszy = true;
    for(int i = 0; i < 200; i++) {
		for(int j = 0; j < 20; j++) {
            fileIn >> linijka;
            for(int l = 0 ; l < 20; l++) {
                obr [j] [l] = linijka [l];
            }
        }
        fileIn >> skipL;
        
        if(rekure(obr)) {
        	if(pierwszy == true) {
        		rekur(obr){
        			pierwszy == false
				}
				cout << "Jest obrazkiem rekurencyjnym\n";
				licznikR++
			} else {
			cout << "Nie jest obrazkiem rekurencyjnym!\n";
        }
    }
    cout << "obrazkow rekurencyjnych jest: " << licznikR"\n";
}

bool obrazek::rekur(string obr [20] [20]) {

    for(int i = 0; i < 10; i++) {
        for(int j=0;j<10;++j) {
            if(!(obr [i] [j] == obr [i + 10] [j] 
			&& obr [i] [j] == obr [i] [j + 10] 
			&& obr [i] [j] == obr [i + 10] [j + 10])) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    obrazek IsReImg;
    IsReImg.run();
    return 0;
}
