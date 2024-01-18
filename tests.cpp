#include "tests.h"


#include <fstream>

void gf_value_test(){
    double min_x =0.01;
    double max_x = 1.0;
    double step = 0.01;
    std::string filepath = "Results/GeneratingFunctions/Test_v1/";

    std::ofstream endPointFile(filepath + "Endpoint.csv");
    endPointFile << "gf_value;x\n";

    std::ofstream cycleFile(filepath + "Cycle.csv");
    cycleFile << "gf_value;x\n";

    std::ofstream sequenceFile(filepath + "Sequence.csv");
    sequenceFile << "gf_value;x\n";

    std::ofstream setFile(filepath + "Set.csv");
    setFile << "gf_value;x\n";

    std::ofstream passengerFile(filepath + "Passenger.csv");
    passengerFile << "gf_value;x\n";

    std::ofstream plankFile(filepath + "Plank.csv");
    plankFile << "gf_value;x\n";

    std::ofstream wagonFile(filepath + "Wagon.csv");
    wagonFile << "gf_value;x\n";

    std::ofstream setPassengerFile(filepath + "SetPassenger.csv");
    setPassengerFile << "gf_value;x\n";

    std::ofstream trainLenFile(filepath + "TrainLen.csv");
    trainLenFile << "gf_value;x\n";

    for (double x = min_x; x < max_x; x+=step){
        double endPointGFValue = EndpointGF(x);
        endPointFile << endPointGFValue << ";" << x << "\n";

        double cycleGFValue = CycleGF(x);
        cycleFile << cycleGFValue << ";" << x << "\n";

        double sequenceGFValue = SequenceGF(x);
        sequenceFile << sequenceGFValue << ";" << x << "\n";

        double setGFValue = SetGF(x);
        setFile << setGFValue << ";" << x << "\n";

        double passengerGFValue = PassengerGF(x);
        passengerFile << passengerGFValue << ";" << x << "\n";

        double plankGFValue = PlankGF(x);
        plankFile << plankGFValue << ";" << x << "\n";

        double wagonGFValue = WagonGF(x);
        wagonFile << wagonGFValue << ";" << x << "\n";

        double setPassengerGFValue = SetPassengerGF(x);
        setPassengerFile << setPassengerGFValue << ";" << x << "\n";

        double trainLenGFValue = TrainGF(x);
        trainLenFile << trainLenGFValue << ";" << x << "\n";
    }

    endPointFile.close();
    cycleFile.close();
    sequenceFile.close();
    setFile.close();
    passengerFile.close();
    plankFile.close();
    wagonFile.close();
    setPassengerFile.close();
    trainLenFile.close();
}

void printWagon(Wagon* w){
    for (Plank* p: w->planks){
        std::cout << p->wheel << " ";
    }
}

void printTrain(Train* t){
    std::cout << "Lokomotywa :" ;
    printWagon(t->locomotive);
    std::cout << "\n";

    for (WagonWithPassengers* w : t->wagonswithpassengers){
        std::cout << w->Passengers.size() << ";;";

        printWagon(w->wagon);
        std::cout << "\n";
    }
}
void single_train_test(){
    Train *t = trainBS(0.44,2);
    printTrain(t);
    std::string filename_1 = "Trains/Train_one.json";
    std::string filename_2 = "Trains/Train_two.json";
    std::string filename_3 = "Trains/Train_three.json";
    saveTrainToJson(t, filename_3);

    delete t;
}

void sizes_test(){
    double min_x =0.01;
    double max_x = 0.43;
    double step = 0.01;
    int repeat = 1000;
    int train_min_len = 2;
    std::string filepath = "Results/Test_v2/X=";

    elements_counter(min_x, max_x, step, repeat, filepath, train_min_len);
}

void functionality_test(){
    double min_x =0.01;
    double max_x = 1.0;
    double step = 0.01;
    int train_min_len = 2;
    for (double x = min_x; x < max_x; x+=step){
        std::cout << "x = " << x << "\n";
        Train *t = trainBS(x,train_min_len);
    }
}