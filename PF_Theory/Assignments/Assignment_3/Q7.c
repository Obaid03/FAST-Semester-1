#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_USERS 5
#define NUM_CATEGORIES 3
#define NUM_DEVICES 3
#define NUM_CONTENT 4

typedef struct{
    char title[50];
    float rating;
    int runtime;
    char encoding[20];
} ContentMetadata;

typedef struct{
    int resolution;
    int playbackHistory;
    int bandwidthUsage;
} DevicePreferences;

double** createEngagementMatrix(int numUsers,int numCategories) {
    double** matrix=(double**)malloc(numUsers * sizeof(double*));
    int i;
    for(i=0; i<numUsers; i++){
        matrix[i]=(double*)malloc(numCategories * sizeof(double));
    }
    return matrix;
}

DevicePreferences*** createDeviceMatrix(int numUsers,int numDevices) {
    DevicePreferences*** matrix=(DevicePreferences***)malloc(numUsers * sizeof(DevicePreferences**));
    int i,j;
    for(i=0; i<numUsers; i++){
        matrix[i]=(DevicePreferences**)malloc(numDevices * sizeof(DevicePreferences*));
        for(j=0; j<numDevices; j++) {
            matrix[i][j]=(DevicePreferences*)malloc(sizeof(DevicePreferences));
        }
    }
    return matrix;
}

ContentMetadata*** createContentMetadataMatrix(int numCategories,int numContent) {
    ContentMetadata*** matrix=(ContentMetadata***)malloc(numCategories * sizeof(ContentMetadata**));
    int i,j;
    for(i=0; i<numCategories; i++) {
        matrix[i]=(ContentMetadata**)malloc(numContent * sizeof(ContentMetadata*));
        for(j=0; j<numContent; j++) {
            matrix[i][j]=(ContentMetadata*)malloc(sizeof(ContentMetadata));
        }
    }
    return matrix;
}

void initEngagementMatrix(double** matrix,int numUsers,int numCategories) {
	int i,j;
    for(i=0; i<numUsers; i++){
        for(j=0; j<numCategories; j++) {
            matrix[i][j]=(i+1)*(j+1);
        }
    }
}

void initDeviceMatrix(DevicePreferences*** matrix,int numUsers,int numDevices) {
	int i,j;
    for(i=0; i<numUsers; i++) {
        for(j=0; j<numDevices; j++) {
            matrix[i][j]->resolution=(j+1)*720;
            matrix[i][j]->playbackHistory=0;
            matrix[i][j]->bandwidthUsage=1000;
        }
    }
}

void initContentMetadataMatrix(ContentMetadata*** matrix,int numCategories,int numContent) {
	int i,j;
    for(i=0; i<numCategories;i++){
        for(j=0; j < numContent; j++){
            snprintf(matrix[i][j]->title,sizeof(matrix[i][j]->title),"Content %d-%d",i+1,j+1);
            matrix[i][j]->rating=4.5;
            matrix[i][j]->runtime=120;
            snprintf(matrix[i][j]->encoding,sizeof(matrix[i][j]->encoding),"H.264");
        }
    }
}

void printEngagementMatrix(double** matrix,int numUsers,int numCategories) {
    printf("Engagement Matrix:\n");
    int i,j;
    for(i=0; i<numUsers; i++) {
        for(j=0; j<numCategories; j++) {
            printf("%.2f ",matrix[i][j]);
        }
        printf("\n");
    }
}

void printDeviceMatrix(DevicePreferences*** matrix,int numUsers,int numDevices) {
    printf("\nDevice Preferences Matrix:\n");
    int i,j;
    for(i=0; i<numUsers; i++) {
        for(j=0; j<numDevices; j++) {
            printf("User %d, Device %d - Resolution: %d, Playback History: %d, Bandwidth: %d KB\n",
                   i+1,j+1,matrix[i][j]->resolution,matrix[i][j]->playbackHistory,matrix[i][j]->bandwidthUsage);
        }
    }
}

void printContentMetadataMatrix(ContentMetadata*** matrix,int numCategories,int numContent) {
    printf("\nContent Metadata Matrix:\n");
    int i,j;
    for (i=0; i<numCategories; i++){
        for(j=0; j<numContent; j++){
            printf("Category %d, Content %d - Title: %s, Rating: %.1f, Runtime: %d min, Encoding: %s\n",
                   i+1,j+1,matrix[i][j]->title,matrix[i][j]->rating,matrix[i][j]->runtime,matrix[i][j]->encoding);
        }
    }
}

int main(){
    double** engagementMatrix=createEngagementMatrix(NUM_USERS,NUM_CATEGORIES);
    DevicePreferences*** deviceMatrix=createDeviceMatrix(NUM_USERS,NUM_DEVICES);
    ContentMetadata*** contentMetadataMatrix=createContentMetadataMatrix(NUM_CATEGORIES,NUM_CONTENT);

    initEngagementMatrix(engagementMatrix,NUM_USERS,NUM_CATEGORIES);
    initDeviceMatrix(deviceMatrix,NUM_USERS,NUM_DEVICES);
    initContentMetadataMatrix(contentMetadataMatrix,NUM_CATEGORIES,NUM_CONTENT);

    printEngagementMatrix(engagementMatrix,NUM_USERS,NUM_CATEGORIES);
    printDeviceMatrix(deviceMatrix,NUM_USERS,NUM_DEVICES);
    printContentMetadataMatrix(contentMetadataMatrix,NUM_CATEGORIES,NUM_CONTENT);
    
    int i,j;

    for(i=0; i<NUM_USERS; i++){
        free(engagementMatrix[i]);
    }
    free(engagementMatrix);

    for(i=0; i<NUM_USERS; i++){
        for(j=0; j<NUM_DEVICES; j++) {
            free(deviceMatrix[i][j]);
        }
        free(deviceMatrix[i]);
    }
    free(deviceMatrix);

    for(i=0; i<NUM_CATEGORIES; i++) {
        for(j=0; j<NUM_CONTENT; j++) {
            free(contentMetadataMatrix[i][j]);
        }
        free(contentMetadataMatrix[i]);
    }
    free(contentMetadataMatrix);

    return 0;
}
