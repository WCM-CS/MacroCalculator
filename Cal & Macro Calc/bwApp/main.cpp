#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class Maintain{
    public: 
        float fatGrams, fatCals, proGrams, proCals, carbGrams, carbCals;
        Maintain(float bw){
            proGrams = bw;
            proCals = proGrams*4;
            carbCals = (proCals*4)*0.6;
            carbGrams = carbCals/4;
            fatCals = (proCals*4)*0.15;
            fatGrams = fatCals/9;
        }
        void printMacros(){
            printf("--------------------------------------------------------------------------------------------\nYour daily macro count is: Fats %.2f, Protein %.2f, Carbs %.2f.\n", fatGrams, proGrams, carbGrams);
        }
        void printCals(){
            printf("Your daily calorie intake is: Fats %0.2f, Protein %0.2f, Carbs %0.2f, Total %0.2f.\n--------------------------------------------------------------------------------------------\n", fatCals, proCals, carbCals, (fatCals+proCals+carbCals));
        }
};

class Bulk : public Maintain{
    public:
        Bulk(float bw) : Maintain(bw){
            proGrams = bw*1.5;
            proCals = proGrams*4;
            carbCals = (proCals*4)*0.6;
            carbGrams = carbCals/4;
            fatCals = (proCals*4)*0.15;
            fatGrams = fatCals/9;
        }
};

class Cut : public Maintain{
    public:
        Cut(float bw) : Maintain(bw){
            proGrams = bw;
            proCals = proGrams*4;
            carbCals = (proCals*3)*0.6;
            carbGrams = carbCals/4;
            fatCals = (proCals*3)*0.15;
            fatGrams = fatCals/9;
        }
};

string getOS(){
    #ifdef _WIN32
        return "Windows";
    #elif defined(unix) || defined(__unix__)
        return  "Unix";
    #elif defined(__APPLE__)
        return "macOS";
    #else
        return "Unknown";
    #endif
}

int main(){
    float bodyWeight, fatCals, fatGrams, proCals, proGrams, carbCals, carbGrams;
    bool cut, maintain, bulk;
    int choice;
    string stay;

    while(true){
        cout << "Input yout bodyweight: ";
        cin >> bodyWeight;
        while(true){
            cout << "-----------------\nSelect your goal\n----------------- \n1: Maintain \n2: Bulk \n3: Cut \nINPUT: ";
            cin >> choice;
            if (choice == 1 || choice == 2 ||choice == 3){
                break;
            }else{
                cout <<"Error: Invalid Input";
                continue;
            }
        }
      Maintain Buck(bodyWeight);
      Bulk Duck(bodyWeight);
      Cut Luck(bodyWeight);
        switch(choice){
            case 1:
                Buck.printMacros();
                Buck.printCals();
                break;
            case 2:
                Duck.printMacros();
                Duck.printCals();
                break;
            case 3:
                Luck.printMacros();
                Luck.printCals();
                break;
        }
        cout << "Continue to create a different diet plan? Enter Either Yes or No: ";
        cin >> stay;

        remove(stay.begin(), stay.end(), ' ');
        if(stay.size()>2){
            if(getOS()== "Windows"){
                system("cls");
            }else if(getOS() == "Unix" || getOS() =="macOS"){
                system("clear");
            }
            continue;
        } else{
            break;
        }
    }
    return 0;
}