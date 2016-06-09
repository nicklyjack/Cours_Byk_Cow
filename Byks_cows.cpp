#include <iostream>
#include <conio.h>
#include <cstdlib> 
#include <ctime>
using namespace std;  

void input_numbers(int *randArray){
int ox = 0;
int cow = 0;
int ourArray[4];
int temp = 0;    
    //Ввод и проверка числа на парвильность ввода
    while(1){
        cout << endl << "The number must be a 4-digit. The figures should not be repeated!" <<endl <<"Input number. " << endl <<"->";
        cin >> temp;
        if ((temp>=1023)&&(temp<=9876)){
            for(int i =3;i>=0;i--){
                ourArray[i]=temp%10;
                temp=temp/10;}
            if ((ourArray[0]!=ourArray[1])&&(ourArray[0]!=ourArray[2])&&(ourArray[0]!=ourArray[3])&&
                (ourArray[1]!=ourArray[2])&&(ourArray[1]!=ourArray[3])&&
                (ourArray[2]!=ourArray[3]))
        break;
        }
    }
    //Подсчет "Быков" и "Коров"
    for(int j = 0;j<4;j++){
        for(int i = 0;i<4;i++)
            if (randArray[i] == ourArray[j])
                if ( i == j )
                        ox++;
                    else
                        cow++;
    }
    //Вывод результатов
    cout << "Byk: " << ox << endl;
    cout << "KoroB: " << cow << endl;
    if(ox == 4)
            cout << "You win!" << endl;
        else
            input_numbers(randArray);
    getch();
}

int main(){
    cout << "                       ..:: Course work. 6 variant ::.."<<endl;
    int intForRand;
    int randArray[4];
    srand(time(0)); 
    for(int i = 0;i<4;i++){
        intForRand = rand() % 9;
        randArray[i] = intForRand;
        for(int j=0;j<4;j++){
           if(randArray[i] == randArray[j] && i != j ){                                    
                   intForRand = rand() % 9;
                   randArray[i] = intForRand;
           }
        }
    }
    while(randArray[0]==0){
        intForRand = rand() % 9+1;
        randArray[0] = intForRand;
    }
    /*cout << "Set number: ";
    for (int i=0;i<4;i++)
        cout << randArray[i];*/
    input_numbers(randArray);
return 0;
}
 
