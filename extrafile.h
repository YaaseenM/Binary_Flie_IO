#ifndef BINARY_FLIE_IO_EXTRAFILE_H
#define BINARY_FLIE_IO_EXTRAFILE_H
#include <string>
#include <vector>

using namespace std;

class extrafile {
    string name;
    string shipClass;
    int length;
    int shieldCapacity;
    float maxWarp;
    vector<string> weaponNames;
    vector<int> powerRatings;
    vector<float> powerConsumptions;
public:
    extrafile(string name, string shipClass, int length, int shieldCapacity, float maxWarp, vector<string> weaponNames, vector<int> powerRatings, vector<float> powerConsumptions);
    string GetName();
    string GetClass();
    int GetLength();
    int GetShieldCapacity();
    float GetMaxWarp();
    int GetTotalFirePower();
    vector<string> GetWeaponNames();
    vector<int> GetPowerRatings();
    vector<float> GetPowerConsumptions();
};

vector<string> extrafile::GetWeaponNames() {
    return weaponNames;
}

vector<int> extrafile::GetPowerRatings() {
    return powerRatings;
}

vector<float> extrafile::GetPowerConsumptions() {
    return powerConsumptions;
}

extrafile::extrafile(string name, string shipClass, int length, int shieldCapacity, float maxWarp,
                     vector<string> weaponNames, vector<int> powerRatings, vector<float> powerConsumptions) {
    this->name = name;
    this->shipClass = shipClass;
    this->length = length;
    this->shieldCapacity = shieldCapacity;
    this->maxWarp = maxWarp;
    this->weaponNames = weaponNames;
    this->powerRatings = powerRatings;
    this->powerConsumptions = powerConsumptions;
}

string extrafile::GetName() {
    return name;
}

string extrafile::GetClass() {
    return shipClass;
}

int extrafile::GetLength() {
    return length;
}

int extrafile::GetShieldCapacity() {
    return shieldCapacity;
}

float extrafile::GetMaxWarp() {
    return maxWarp;
}

int extrafile::GetTotalFirePower() {
    int totFirePower = 0;
    for(unsigned int i = 0; i < powerRatings.size(); i++) {
        totFirePower += powerRatings[i];
    }
    return totFirePower;
}


#endif //BINARY_FLIE_IO_EXTRAFILE_H
