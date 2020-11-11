#include <iostream>
#include <stdio.h>
#include <cstring>

struct note
{
    std::string name;
    int tele;            
    int  bday[3];     
};

int main(int argc, char* argv[]) {
    const int max_blocknote = 8;
    note blocknote[max_blocknote];
    note blocknote1;
    std::string test;
    std::string test1;
    std::string result;
    bool flag = false;

    for (int i = 0; i < max_blocknote; i++) {
        std::string name;
        std::string surname;
        std::cout << "Vvedite famil_imea : ";
        std::cin >> name >> surname;
        blocknote[i].name = name + " " + surname;
        std::cout << "Vvedite nomer : ";
        std::cin >> blocknote[i].tele;
        std::cout << "Den rojdenia : ";
        std::cin >> blocknote[i].bday[0];
        std::cout << "Meseac rojdenia : ";
        std::cin >> blocknote[i].bday[1];
        std::cout << "god rojdenia : ";
        std::cin >> blocknote[i].bday[2];
    };

    for (int i = 0; i < max_blocknote; i++) {
        for (int j = i + 1; j < max_blocknote; j++) {
            if (blocknote[i].tele/100000 > blocknote[j].tele/100000){
                blocknote1 = blocknote[i];
                blocknote[i] = blocknote[j];
                blocknote[j] = blocknote1;
            }
        }
    };

    std::cout << "Vvedite vashu familiy i imea" << std::endl;
    std::cin >> test >> test1;
    result = test + " " + test1;

    for (int i = 0; i < max_blocknote; i++) {
        if (blocknote[i].name == result) {
            std::cout << "Imea i familia: " << blocknote[i].name << "Nomer telefona: " << blocknote[i].tele << "den rojdenia: ";
            flag = true;
            for (int j = 0; j < 3; j++) {
                std::cout << blocknote[i].bday[j] << "/";
            };
        };
    };
    if (!flag) {
        std::cout << "Takogo celoveka net";
    };
    return 0;
}