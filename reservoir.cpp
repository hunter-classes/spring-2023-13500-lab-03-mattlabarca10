#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>

//gets the east basin storage of a specific date
double get_east_storage(std::string date)
{
    std::ifstream file("Current_Reservoir_Levels.tsv"); //opens file
    if(file.fail()){ //accounts for if the file cannot be opened
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1);
    }
    std::string junk;
    std::getline(file,junk); //disregards first line (header)

    std::string dates;
    double eastSt;
    while(file >> dates >> eastSt) { //loops through the east basin storage column of dataset
        if(date == dates){ //finds the date and returns value
            return eastSt;
        }
        file.ignore(INT_MAX, '\n');
    }
    file.close();
    return 0;
}

//gets the minimum storage of the east basin
double get_min_east()
{
    std::ifstream file("Current_Reservoir_Levels.tsv");
    if(file.fail()){
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1);
    }

    //ignores first line
    std::string junk;
    std::getline(file,junk);
    std::string dates;

    double eastSt;
    double minEastSt = -1; // helps indicate if it is the first value, since it can't be -1
    while(file >> dates >> eastSt) { 
        if(minEastSt == -1)
            minEastSt = eastSt; // sets first value as the minimum, to be compared to throughout the loop
        else if(eastSt<minEastSt) 
            minEastSt = eastSt;
        file.ignore(INT_MAX, '\n');
    }
    file.close();
    return minEastSt;
}

//gets the maximum storage of the east basin
double get_max_east()
{
    std::ifstream file("Current_Reservoir_Levels.tsv");
    if(file.fail()){
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1);
    }

    std::string junk;
    std::getline(file,junk);
    std::string dates;

    double eastSt;
    double maxEastSt = -1; // this method works better for maximum since the first value will always be > -1
    while(file >> dates >> eastSt) { 
        if(eastSt>maxEastSt) 
            maxEastSt = eastSt;
        file.ignore(INT_MAX, '\n'); 
    }
    file.close();
    return maxEastSt;
    return 0;
}

// compares east and west basin volume of a certain date and see which is larger
std::string compare_basins(std::string date)
{
    std::ifstream file("Current_Reservoir_Levels.tsv");
    if(file.fail()){
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1);
    }
    std::string junk;
    std::getline(file,junk);
    std::string dates;
    double eastSt;
    double eastEl;
    double westSt;
    double eastStorageValue;
    double westStorageValue;

    while(file >> dates >> eastSt) { // finds east basin storage for the date
        if(date == dates){
            eastStorageValue = eastSt;
        }
        file.ignore(INT_MAX, '\n');
    }
    while(file >> dates >> eastSt >> eastEl >> westSt) { // finds west basin storage for the date
        if(date == dates){
            westStorageValue = westSt;
        }
        file.ignore(INT_MAX, '\n');
    }
    if(eastStorageValue > westStorageValue) //checks which is greater or if they're equal and returns accordingly
        return "East";
    else if (eastStorageValue > westStorageValue)
        return "West";
    else
        return "Equal";

    file.close();
    return 0;
}