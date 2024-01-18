#include "train_researcher.h"


ElementCounts countElements(Train* t) {
    ElementCounts counts;
    if (t->locomotive != nullptr) {
        counts.noPlanks += t->locomotive->planks.size();
        for (auto& plank : t->locomotive->planks) {
            if (plank->wheel != 0) {
                counts.noWheels++;
            }
        }
    }
    for (auto& wagonWithPassengers : t->wagonswithpassengers) {
        if (wagonWithPassengers->wagon != nullptr) {
            counts.noPlanks += wagonWithPassengers->wagon->planks.size();
            for (auto& plank : wagonWithPassengers->wagon->planks) {
                if (plank->wheel != 0) {
                    counts.noWheels++;
                }
            }
        }
        counts.noPassengers += wagonWithPassengers->Passengers.size();
    }
    counts.noWagons = t->wagonswithpassengers.size();
    return counts;
}

void process(double x, int repeat, const std::string& filepath, int train_min_len){
    std::string filepath_with_x = filepath + std::to_string(x) + ".csv";
    std::ofstream outfile(filepath_with_x, std::ios_base::app);
    outfile << "Planks;Wagons;Wheels;Passengers;Repeat;MinLenTrain\n";
    outfile.close();
    for (int i = 0; i < repeat; ++i) {
        std::string filepath_with_x = filepath + std::to_string(x) + ".csv";
        std::ofstream outfile(filepath_with_x, std::ios_base::app);
        Train *t = trainBS(x, train_min_len);
        ElementCounts counts = countElements(t);
        outfile  << counts.noPlanks << ";" << counts.noWagons << ";" << counts.noWheels << ";" << counts.noPassengers << ";" << repeat << ";" <<train_min_len << "\n";
        outfile.close();
        delete t;
    }
}

void elements_counter(double min_x, double max_x, double step, int repeat, const std::string& filepath, int train_min_len){
    std::vector<std::thread> threads;
    for (double x = min_x; x < max_x; x+=step) {
        threads.emplace_back(process, x, repeat, filepath, train_min_len);
    }
    for (auto& th : threads) {
        th.join();
    }
}