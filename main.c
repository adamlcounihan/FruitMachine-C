#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main () {
    srand(time(NULL));
    double money = 1.00;
    int play;

    printf("--Welcome to the fruit machine--\n");
    sleep(2);
    printf("Rules:\n");
    sleep(1);
    printf("~ You start with 1.00 \n");
    sleep(1);
    printf("~ Each turn costs 0.20 \n");
    sleep(1);
    printf("~ Two of same num = +0.50\n");
    sleep(1);
    printf("~ Three of same num = +1.00\n");
    sleep(1);
    printf("~ Three Sevens = +5.00 \n");
    sleep(1);
    printf("~ Three Nines = Loose all money\n");
    sleep(1);
    printf("--------------------------------\n");
    //info displayed to user on how to play

    while (money >=0.2)
    //while user has more than 0.20 currency
    {
        printf("\nWould you like to roll? (1=yes,2=no)");
        scanf("%d", &play);

        if (play == 1)
        {
            money = money - 0.2;
            printf("Money now %.2f\n", money);

            int num1 = rand() % 9+1;
            int num2 = rand() % 9+1;
            int num3 = rand() % 9+1;
            sleep(3);
            //numbers are randomly generated

            printf("\n\n%d,%d,%d\n",num1,num2,num3);
            sleep(3);

            //if no numbers are equal
            if(num1!=num2){
                if(num2!=num3){
                    if(num3!=num1){
                        printf("\nYou won nothing :(\n");
                        sleep(2);
                        printf("\nYou still have %.2f", money);
                        sleep(2);
                    }
                }
            }

            //if all three numbers are equal
            if(num1==num2) {
                if (num2 == num3) {
                    printf("\n3 of a kind! (+1)\n");
                    money = money + 1;
                    printf("Money now %.2f\n", money);
                }
            }

            //if num1 and num2 are equal, but neither are equal to num3
            if(num1==num2){
                if(num3!=num1){
                    printf("\nTwo of a kind! (+50p)\n");
                    money = money + 0.5;
                    printf("Money now %.2f\n", money);
                }
            }
            //if num2 and num3 are equal, but neither are equal to num1
            if(num2==num3){
                if(num1!=num2){
                    printf("\nTwo of a kind! (+50p)\n");
                    money = money + 0.5;
                    printf("Money now %.2f\n", money);
                }
            }
            //if num1 and num3 are equal, but neither are equal to num2
            if(num1==num3){
                if(num2!=num1){
                    printf("\nTwo of a kind! (+50p)\n");
                    money = money + 0.5;
                    printf("Money now %.2f\n", money);
                }
            }

            //three nines are rolled
            if(num1==9){
                if(num2==9){
                    if(num3==9){
                        printf("\nThree 9s (Loose all Money)\n");
                        money = 0;
                        printf("Money now %.2f\n", money);
                    }
                }
            }
            //three sevens are rolled
            if(num1==7){
                if(num2==7){
                    if(num3==7){
                        printf("\nThree 7s! (+5)-\n");
                        money = money + 5;
                        printf("Money now %.2f\n", money);
                    }
                }
            }

        }


        //if the user doesn't wish to play, game ends
        else
        {
            printf("\nLeaving machine with %.2f", money);
            return 0;
        }
    }
    printf("\nYou do not have enough money to play. Game Ending.");
    return 0;
}
