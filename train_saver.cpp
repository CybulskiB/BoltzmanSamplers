#include <fstream>
#include <sstream>
#include "combinatorial_train.h"
#include "train_saver.h"



std::string wagonToJson(Wagon* wagon) {
    std::ostringstream ss;
    ss << "{\n\t\"planks\": [\n";
    for (size_t i = 0; i < wagon->planks.size(); ++i) {
        ss << "\t\t{ \"wheel\": " << wagon->planks[i]->wheel << " }";
        if (i != wagon->planks.size() - 1) {
            ss << ",";
        }
        ss << "\n";
    }
    ss << "\t]\n}";
    return ss.str();
}

std::string wagonWithPassengersToJson(WagonWithPassengers* wagonWithPassengers) {
    std::ostringstream ss;
    ss << "{\n\t\t\"wagon\": " << wagonToJson(wagonWithPassengers->wagon) 
       << ",\n\t\t\"passengerCount\": " << wagonWithPassengers->Passengers.size() 
       << "\n\t}";
    return ss.str();
}

std::string trainToJson(Train* train) {
    std::ostringstream ss;
    ss << "{\n\t\"locomotive\": " << wagonToJson(train->locomotive) << ",\n\t\"wagons\": [\n";
    for (size_t i = 0; i < train->wagons.size(); ++i) {
        ss << "\t\t" << wagonWithPassengersToJson(train->wagons[i]);
        if (i != train->wagons.size() - 1) {
            ss << ",";
        }
        ss << "\n";
    }
    ss << "\t]\n}";
    return ss.str();
}

void saveTrainToJson(Train* train, const std::string& filename) {
    std::string json = trainToJson(train);
    std::ofstream file(filename);
    file << json;
}