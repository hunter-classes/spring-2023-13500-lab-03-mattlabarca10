#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <vector>

/* given two dates of an interval, this will output the dates and 
west basin storage volume in reverse chronological order */ 
void reverse_order(std::string date1, std::string date2){
    std::ifstream file("Current_Reservoir_Levels.tsv");
    if(file.fail()){
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1);
    }
    std::string junk;
    std::getline(file,junk);
    std::string date;
    double eastSt;
    double eastEl;
    double westSt;
    bool interval = false; // if this is false, date is not in the interval and won't be added to the vectors
    std::vector<std::string> revDate = {};
    std::vector<double> revWestSt = {};
    while(file >> date >> eastSt >> eastEl >> westSt) { 
        if(date==date1)
            interval = true; // turned true to be able to input
        if(interval==true){
            revDate.insert(revDate.begin(),date); // inputs date at beginning to reverse the chronological order
            revWestSt.insert(revWestSt.begin(),westSt); 
        }
        if(date==date2)
            interval = false; // stops adding to the vectors once date is out of interval
        file.ignore(INT_MAX, '\n');
    }
    for(int i = 0; i<revDate.size(); i++){
        std::cout << revDate[i]<< " " << revWestSt[i]<<std::endl; 
        //outputs the dates and west basin storage in reverse chronological order
    }
    file.close();
}