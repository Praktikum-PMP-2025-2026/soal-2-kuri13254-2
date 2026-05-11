/*
Nama            : Thoriq Al Maududi
NIM             : 13224054
Pilihan soal    : Soal 2
*/

#include <stdio.h>
#include <stdlib.h>

#define max_quest 20

void chainquest(int chain[max_quest][max_quest], int prasyarat, int quest){
    chain[quest][prasyarat] = 1;
}

int isCyclicUtil(int chain[max_quest][max_quest], int currentquest, int parent, int visited[max_quest]){
    visited[currentquest] = 1;
    
    for(int i = 0; i < max_quest; i++){
        if (chain[currentquest][i]){
            if (!visited[i]){
                if (isCyclicUtil(chain, i, currentquest, visited))
                return 1;
            }
            else if (i != parent){
                return 1;
            }
        }
    }
    return 0;
}

int loopkah(int chain[max_quest][max_quest], int node){
    int visited[max_quest] = {0};

    for(int i = 0; i < node; i++){
        if(!visited[i]){
            if (isCyclicUtil(chain, i, -1, visited))
            return 1;
        }
    }
    return 0;
}

int main(){
    int node, edge;

    scanf("%d", &node);

    int chain[max_quest][max_quest] = {0};

    scanf("%d", &edge);

    for (int i = 0; i < edge; i++){
        int prasyarat, quest;
        scanf("%d %d", &quest, &prasyarat);
    
    chainquest(chain, prasyarat, quest);
    }

    if (loopkah(chain, node))
        printf("TIDAK BISA");
    else
        printf("BISA");
    
    return 0;
}
