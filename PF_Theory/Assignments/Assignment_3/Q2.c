#include <stdio.h>
#include <string.h>

struct Player{
    int ballScores[12];
    char playerName[50];
    int totalScore;
};

int validateScore(int score){
    if(score>=0 && score<=6){
        return score;
    }
    return -1;
}

void playGame(struct Player* player) {
    int score;
    
    int i;
    for (i=0; i<12; i++){
        printf("%s, Enter score for ball %d (0-6): ",player->playerName,i+1);
        scanf("%d",&score);

        score=validateScore(score);
        if (score!=-1) {
            player->ballScores[i]=score;
        } else {
            printf("Invalid score! Ball %d will be marked as 0.\n",i+1);
            player->ballScores[i]=0;
        }
    }
}

void calculateTotalScore(struct Player* player){
    player->totalScore=0;
    int i;
    for(i=0; i<12; i++){
        player->totalScore+=player->ballScores[i];
    }
}

void findWinner(struct Player player1,struct Player player2){
    printf("Final Scores\n");
    printf("%s: %d\n",player1.playerName,player1.totalScore);
    printf("%s: %d\n",player2.playerName,player2.totalScore);

    if(player1.totalScore>player2.totalScore){
        printf("\nWinner: %s\n",player1.playerName);
    }else if(player1.totalScore<player2.totalScore){
        printf("Winner: %s\n",player2.playerName);
    }else{
        printf("It's a Tie!\n");
    }
}

void displayMatchScoreboard(struct Player player1,struct Player player2){
    printf("Match Summary:\n");

    printf("%s's Performance:\n",player1.playerName);
    printf("Ball Scores: ");
    int i;
    for(i=0; i<12; i++){
        printf("%d ",player1.ballScores[i]);
    }
    printf("\nTotal Score: %d\n",player1.totalScore);
    printf("Average Score: %.2f\n",player1.totalScore / 12.0);

    printf("\n%s's Performance:\n",player2.playerName);
    printf("Ball Scores: ");
    for(i=0; i<12; i++){
        printf("%d ",player2.ballScores[i]);
    }
    printf("\nTotal Score: %d\n",player2.totalScore);
    printf("Average Score: %.2f\n",player2.totalScore/12.0);
}

int main(){
    struct Player player1,player2;

    printf("Enter name of Player 1: ");
    scanf(" %[^\n]",player1.playerName);
    printf("Enter name of Player 2: ");
    scanf(" %[^\n]",player2.playerName);

    playGame(&player1);
    playGame(&player2);

    calculateTotalScore(&player1);
    calculateTotalScore(&player2);

    displayMatchScoreboard(player1,player2);

    findWinner(player1,player2);

    return 0;
}
