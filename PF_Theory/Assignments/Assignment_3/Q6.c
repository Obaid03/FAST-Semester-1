#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    float temperature;
    float rainfall;
    float windSpeed;
} WeatherForecast;

typedef struct{
    char cropType[50];
    int growthStage;
    float expectedYield;
    WeatherForecast *weatherForecast;
} Crop;

typedef struct{
    float soilHealth;
    float moistureLevel;
    float pHLevel;
    float nutrientLevel;
    struct Sensor *sensors;
}Sensor;

typedef struct{
    char equipmentType[50];
    int operationalStatus;
    float fuelLevel;
    char activitySchedule[100];
}Equipment;

typedef struct{
    float latitude;
    float longitude;
    float altitude;
    Sensor *sensors;
    Crop *crops;
    Equipment *equipment;
}Field;

typedef struct{
    Field *fields;
    int numFields;
    float aggregateYieldPrediction;
    float resourceDistribution;
    char emergencyResponsePlan[200];
}RegionalHub;

typedef struct {
    RegionalHub *hubs;
    int numHubs;
}AnalyticsServer;

void initializeWeatherForecast(WeatherForecast *forecast,float temp,float rain,float wind);
void initializeCrop(Crop *crop,const char *type,int growthStage,float yield,WeatherForecast *forecast);
void initializeSensor(Sensor *sensor,float health,float moisture,float pH,float nutrients);
void initializeEquipment(Equipment *equipment,const char *type,int status,float fuel,const char *schedule);
void initializeField(Field *field,float lat,float lon,float alt,Sensor *sensors,Crop *crops,Equipment *equip);
void initializeRegionalHub(RegionalHub *hub,Field *fields,int numFields);
void initializeAnalyticsServer(AnalyticsServer *server,RegionalHub *hubs,int numHubs);
void freeMemory(AnalyticsServer *server);

int main(){
    WeatherForecast weather;
    initializeWeatherForecast(&weather,27.5,135.0,11.0);

    Crop crop;
    initializeCrop(&crop,"Rice",2,600.0,&weather);

    Sensor sensor;
    initializeSensor(&sensor,85.0,50.0,6.2,50.0);

    Equipment equipment;
    initializeEquipment(&equipment,"Tractor",1,80.0,"Daily");

    Field field;
    initializeField(&field,25.276987,55.296249,15.0,&sensor,&crop,&equipment);

    Field fields[1]={field};
    RegionalHub hub;
    initializeRegionalHub(&hub,fields,1);

    RegionalHub hubs[1]={hub};
    AnalyticsServer server;
    initializeAnalyticsServer(&server,hubs,1);

    printf("Field at (%.2f, %.2f) with Crop: %s, Growth Stage: %d\n",
           field.latitude,field.longitude,field.crops->cropType,field.crops->growthStage);

    freeMemory(&server);

    return 0;
}

void initializeWeatherForecast(WeatherForecast *forecast,float temp,float rain,float wind) {
    forecast->temperature=temp;
    forecast->rainfall=rain;
    forecast->windSpeed=wind;
}

void initializeCrop(Crop *crop,const char *type,int growthStage,float yield,WeatherForecast *forecast) {
    strcpy(crop->cropType,type);
    crop->growthStage=growthStage;
    crop->expectedYield=yield;
    crop->weatherForecast=forecast;
}

void initializeSensor(Sensor *sensor,float health,float moisture,float pH,float nutrients) {
    sensor->soilHealth=health;
    sensor->moistureLevel=moisture;
    sensor->pHLevel=pH;
    sensor->nutrientLevel=nutrients;
}

void initializeEquipment(Equipment *equipment,const char *type,int status,float fuel,const char *schedule) {
    strcpy(equipment->equipmentType,type);
    equipment->operationalStatus=status;
    equipment->fuelLevel = fuel;
    strcpy(equipment->activitySchedule,schedule);
}

void initializeField(Field *field,float lat,float lon,float alt,Sensor *sensors,Crop *crops,Equipment *equip) {
    field->latitude=lat;
    field->longitude=lon;
    field->altitude=alt;
    field->sensors=sensors;
    field->crops=crops;
    field->equipment=equip;
}

void initializeRegionalHub(RegionalHub *hub,Field *fields,int numFields) {
    hub->fields=fields;
    hub->numFields=numFields;
    hub->aggregateYieldPrediction=5000.0;
    hub->resourceDistribution=75.0;
    strcpy(hub->emergencyResponsePlan,"Plan to irrigate, deploy drones, and call emergency services.");
}

void initializeAnalyticsServer(AnalyticsServer *server,RegionalHub *hubs,int numHubs) {
    server->hubs=hubs;
    server->numHubs=numHubs;
}

void freeMemory(AnalyticsServer *server) {
	int i,j;
    for(i=0; i<server->numHubs; i++) {
        for(j=0; j<server->hubs[i].numFields; j++) {
            free(server->hubs[i].fields[j].sensors);
            free(server->hubs[i].fields[j].crops->weatherForecast);
            free(server->hubs[i].fields[j].crops);
            free(server->hubs[i].fields[j].equipment);
        }
    }
    free(server->hubs);
}
