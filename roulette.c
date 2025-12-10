#include <stdio.h>
#include <stdlib.h>
#define ROSSO "\x1b[41m"
#define NERO  "\x1b[37m"
#define VERDE "\x1b[42m"
#define RESET "\x1b[0m"

int isRosso(int n) {
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
void stampatavolo() {
    
    int numeri[] = {
        0, 32, 15, 19, 4, 21, 2, 25, 17, 34,
        6, 27, 13, 36, 11, 30, 8, 23, 10, 5,
        24, 16, 33, 1, 20, 14, 31, 9, 22, 18,
        29, 7, 28, 12, 35, 3, 26
    };
    int n = sizeof(numeri)/sizeof(numeri[0]);

    printf("\n=====================================\n");
    printf("          Tavolo Roulette            \n");
    printf("=====================================\n");

    // Stampa in righe da 12 numeri
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
    printf("\nHai 1000 robux, buona fortuna.");
    while (1){
        stampatavolo();
        printf("\n99/100 dei giocatori quittano prima di vincere, vuoi uscire proprio adesso?(hai %d robux) (s/n): ", robux);
        scanf(" %c", &polenta);
        if(polenta=='s'){
            printf("\nHai quittato con %d robux in tasca", robux);
            return 0;
        }
        else{
            printf("\nQuanto scommetti?");
            scanf("%d", &porri);
            printf("\nSu cosa scommetti i tuoi %d robux?\n(0=numero preciso 20x, 1=colore 2x, 2=pari/dispari 2x): ", porri);
            scanf("%d", &clotilde);
            
            switch (clotilde)
            {
            case 0:
                printf("\nDroppa il numero bro: ");
                scanf("%d", &num); numu=rand() % 37;printf("Numero uscito: %d", numu);
                if(num==numu){
                    printf("\nGrande bro, hai vinto %d robux!", porri*20);
                    robux=robux + (porri*20);
                }
                else{
                    printf("\nHai perso i tuoi %d robux lil bro", porri);
                    robux=robux-porri;
                }
                break;
            case 1:
                printf("\nSeleziona il colore (0=nero, 1=rosso, 2=verde): ");
                scanf("%d", &num);numu=rand() % 37;printf("Numero uscito: %d", numu);
                if(isRosso(numu)&&num){printf("\nHai vinto %d robux!", porri*2);robux=robux+porri*2;}else
                if(!isRosso(numu)&&!num){printf("\nHai vinto %d robux!", porri*2);robux=robux+porri*2;}else
                if (numu==0&&num==2){printf("\nHai vinto %d robux!", porri*2);robux=robux+porri*2;}else{
                    printf("\nHai perso i tuoi %d robux lil bro", porri);robux=robux-porri;
                }
                break;
            case 2:
                printf("\n Pari o dispari (0=pari, 1=dispari): ");
                scanf("%d", &num);numu=rand() % 37;printf("Numero uscito: %d", numu);
                if(numu%2==0 && num==0){
                    printf("\nHai vinto %d robux!", porri*2);robux=robux+porri*2;
                }else{
                    if(numu%2==1 && num==1){
                        printf("\nHai vinto %d robux!", porri*2);robux=robux+porri*2;
                    }else{
                        printf("\nHai perso i tuoi %d robux lil bro", porri);robux=robux-porri;
                    }
                }
                break;
            default:
                printf("\nBro ma sei ritardato? Come punizione hai perso i tuoi %d robux", porri);
                robux=robux-porri;
            }
            
        }
    }
    return 0;
}
