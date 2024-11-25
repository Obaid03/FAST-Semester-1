#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUPPLIES 10

void addSupplies(char*** speciesSupplies,int speciesCount,int speciesIndex,int* supplyCount) {
    char supply[100];
    printf("Enter a supply item: ");
    fgets(supply,sizeof(supply),stdin);
    supply[strcspn(supply, "\n")]='\0';

    if(*supplyCount<MAX_SUPPLIES){
        speciesSupplies[speciesIndex]=realloc(speciesSupplies[speciesIndex],(*supplyCount+1)*sizeof(char*));
        speciesSupplies[speciesIndex][*supplyCount]=malloc((strlen(supply)+1)*sizeof(char));
        strcpy(speciesSupplies[speciesIndex][*supplyCount], supply);
        (*supplyCount)++;
    }else{
        printf("Maximum supplies reached for this species.\n");
    }
}

void updateSupply(char** speciesSupplies,int supplyIndex) {
    char newSupply[100];
    printf("Enter the new supply name: ");
    fgets(newSupply, sizeof(newSupply),stdin);
    newSupply[strcspn(newSupply, "\n")]='\0';

    free(speciesSupplies[supplyIndex]);
    speciesSupplies[supplyIndex]=malloc((strlen(newSupply)+1)*sizeof(char));
    strcpy(speciesSupplies[supplyIndex],newSupply);
}

void removeSpecies(char*** speciesSupplies,int* speciesCount,int speciesIndex,int* supplyCounts) {
	int i;
    for(i=0; i<supplyCounts[speciesIndex]; i++) {
        free(speciesSupplies[speciesIndex][i]);
    }
    free(speciesSupplies[speciesIndex]);
    
    for(i=speciesIndex; i<*speciesCount-1; i++) {
        speciesSupplies[i]=speciesSupplies[i+1];
        supplyCounts[i]=supplyCounts[i+1];
    }

    (*speciesCount)--;
}

void displayInventory(char*** speciesSupplies,int speciesCount,char** speciesNames,int* supplyCounts){
    printf("\nInventory:\n");
    int i,j;
    for(i=0; i<speciesCount; i++) {
        printf("%s: \n",speciesNames[i]);
        for(j=0; j<supplyCounts[i]; j++) {
            printf("  %d. %s\n",j+1,speciesSupplies[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int speciesCount=0;
    int maxSpecies=10;
    int* supplyCounts=malloc(maxSpecies * sizeof(int));
    char*** speciesSupplies=malloc(maxSpecies * sizeof(char**));
    char** speciesNames=malloc(maxSpecies * sizeof(char*));

    int choice;
    do{
        printf("Menu:\n");
        printf("1. Add Species\n");
        printf("2. Add Supplies\n");
        printf("3. Update Supply\n");
        printf("4. Remove Species\n");
        printf("5. Display Inventory\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice){
            case 1:{
                if(speciesCount<maxSpecies){
                    char speciesName[100];
                    printf("Enter species name: ");
                    fgets(speciesName,sizeof(speciesName),stdin);
                    speciesName[strcspn(speciesName,"\n")]='\0';

                    speciesNames[speciesCount]=malloc((strlen(speciesName)+1)*sizeof(char));
                    strcpy(speciesNames[speciesCount],speciesName);

                    speciesSupplies[speciesCount]=NULL;
                    supplyCounts[speciesCount]=0;
                    speciesCount++;
                }else{
                    printf("Maximum species reached.\n");
                }
                break;
            }

            case 2:{
                int speciesIndex;
                printf("Enter species index (0 to %d): ",speciesCount-1);
                scanf("%d",&speciesIndex);
                getchar();

                if(speciesIndex>=0 && speciesIndex<speciesCount) {
                    addSupplies(speciesSupplies,speciesCount,speciesIndex,&supplyCounts[speciesIndex]);
                }else{
                    printf("Invalid species index.\n");
                }
                break;
            }

            case 3: {
                int speciesIndex,supplyIndex;
                printf("Enter species index (0 to %d): ",speciesCount-1);
                scanf("%d",&speciesIndex);
                printf("Enter supply index (0 to %d): ",supplyCounts[speciesIndex]-1);
                scanf("%d",&supplyIndex);
                getchar();

                if(speciesIndex>=0 && speciesIndex<speciesCount && supplyIndex>=0 && supplyIndex<supplyCounts[speciesIndex]) {
                    updateSupply(speciesSupplies[speciesIndex],supplyIndex);
                }else{
                    printf("Invalid species or supply index.\n");
                }
                break;
            }

            case 4:{
                int speciesIndex;
                printf("Enter species index (0 to %d): ",speciesCount-1);
                scanf("%d",&speciesIndex);
                getchar();

                if(speciesIndex>=0 && speciesIndex<speciesCount){
                    removeSpecies(speciesSupplies,&speciesCount,speciesIndex,supplyCounts);
                    printf("Species removed successfully.\n");
                }else{
                    printf("Invalid species index.\n");
                }
                break;
            }

            case 5:
                displayInventory(speciesSupplies,speciesCount,speciesNames,supplyCounts);
                break;

            case 6:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!=6);
    
    int i,j;
    for(i=0; i<speciesCount; i++) {
        free(speciesNames[i]);
        for(j=0; j<supplyCounts[i]; j++) {
            free(speciesSupplies[i][j]);
        }
        free(speciesSupplies[i]);
    }

    free(speciesNames);
    free(speciesSupplies);
    free(supplyCounts);

    return 0;
}
