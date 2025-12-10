#include <stdio.h>
#include <stdlib.h>
#define ROSSO "\x1b[41m"
#define NERO  "\x1b[37m"
#define VERDE "\x1b[42m"
#define RESET "\x1b[0m"

int isRosso(int n) { //check if it's red
    int rossi[] = {
        1,3,5,7,9,12,14,16,18,19,21,23,
        25,27,30,32,34,36
    };
    int len = sizeof(rossi)/sizeof(rossi[0]);
    for (int i = 0; i < len; i++) {
        if (rossi[i] == n) return 1;
    }
    return 0;
}
void stampatavolo() { //prints table
    
    int numeri[] = {
        0, 32, 15, 19, 4, 21, 2, 25, 17, 34,
        6, 27, 13, 36, 11, 30, 8, 23, 10, 5,
        24, 16, 33, 1, 20, 14, 31, 9, 22, 18,
        29, 7, 28, 12, 35, 3, 26
    };
    int n = sizeof(numeri)/sizeof(numeri[0]);

    printf("\n=====================================\n");
    printf("           Roulette Table           \n");
    printf("=====================================\n");

    
    for (int i = 0; i < n; i++) {
        int num = numeri[i];
        if (num == 0) {
            printf(VERDE "%3d " RESET, num);
        } else if (isRosso(num)) {
            printf(ROSSO "%3d " RESET, num);
        } else {
            printf(NERO "%3d " RESET, num);
        }
        if ((i+1) % 12 == 0) printf("\n");
    }
    printf("\n=====================================\n");
}
int main(){
    int robux=1000;
    char polenta;int porri;int clotilde;int num;int numu;
    printf("\nYou got 1000 robux, good luck.");
    while (1){
        stampatavolo();
        printf("\n99/100 of players quit before winning big, do you really want to quit now?( %d robux) (y/n): ", robux);
        scanf(" %c", &polenta);
        if(polenta=='y'){
            printf("\nYou quitted with %d robux in your pockets", robux);
            return 0;
        }
        else{
            printf("\nHow much are you betting?");
            scanf("%d", &porri);
            printf("\nOn what are you betting your %d robux?\n(0=exact number 20x, 1=color 2x, 2=even/odd 2x): ", porri);
            scanf("%d", &clotilde);
            
            switch (clotilde)
            {
            case 0:
                printf("\nDrop the number bro: ");
                scanf("%d", &num); numu=rand() % 37;printf("Extracted number: %d", numu);
                if(num==numu){
                    printf("\nCongrats bro, you won %d robux!", porri*20);
                    robux=robux + (porri*20);
                }
                else{
                    printf("\nYou lost %d robux lil bro", porri);
                    robux=robux-porri;
                }
                break;
            case 1:
                printf("\nChoose you color (0=black, 1=red, 2=green): ");
                scanf("%d", &num);numu=rand() % 37;printf("Extracted number %d", numu);
                if(isRosso(numu)&&num){printf("\nYou won %d robux!", porri*2);robux=robux+porri*2;}else
                if(!isRosso(numu)&&!num){printf("\nYou won %d robux!", porri*2);robux=robux+porri*2;}else
                if (numu==0&&num==2){printf("\nYou won %d robux!", porri*2);robux=robux+porri*2;}else{
                    printf("\nYou lost %d robux lil bro", porri);robux=robux-porri;
                }
                break;
            case 2:
                printf("\n Odd or even (0=odd, 1=even): ");
                scanf("%d", &num);numu=rand() % 37;printf("Extracted number: %d", numu);
                if(numu%2==0 && num==0){
                    printf("\nYou won %d robux!", porri*2);robux=robux+porri*2;
                }else{
                    if(numu%2==1 && num==1){
                        printf("\nYou won %d robux!", porri*2);robux=robux+porri*2;
                    }else{
                        printf("\nyou lost %d robux lil bro", porri);robux=robux-porri;
                    }
                }
                break;
            default:
                printf("\nBro what? I'm still taking your %d robux", porri);
                robux=robux-porri;
            }
            
        }
    }
    return 0;
}
