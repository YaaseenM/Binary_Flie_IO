#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "extrafile.h"

using namespace std;

void FindStrongestShip(vector<extrafile>& ship) {
    int highestPower = ship[0].GetTotalFirePower();
    int shipLoc = 0;
    for (unsigned int i = 0; i < ship.size(); i++) {
        if (ship[i].GetTotalFirePower() > highestPower) {
            highestPower = ship[i].GetTotalFirePower();
            shipLoc = i;
        }
    }
    cout << "Name: " << ship[shipLoc].GetName() << endl;
    cout << "Class: " << ship[shipLoc].GetClass() << endl;
    cout << "Length: " << ship[shipLoc].GetLength() << endl;
    cout << "Shield capacity:" << ship[shipLoc].GetShieldCapacity() << endl;
    cout << "Maximum Warp: " << ship[shipLoc].GetMaxWarp() << endl;
    cout << "Armaments: " << endl;
    for (unsigned int j = 0; j < ship[shipLoc].GetWeaponNames().size(); j++) {
        cout << ship[shipLoc].GetWeaponNames().at(j) << ", " << ship[shipLoc].GetPowerRatings().at(j) << ", "
             << ship[shipLoc].GetPowerConsumptions().at(j) << endl;
    }
    cout << "Total firepower: " << ship[shipLoc].GetTotalFirePower() << endl;

}

void FindWeakestShip(vector<extrafile>& ship) {
    int lowestPower = ship[0].GetTotalFirePower();
    int shipLoc = 0;
    for (unsigned int i = 0; i < ship.size(); i++) {
        if (ship[i].GetTotalFirePower() < lowestPower && ship[i].GetTotalFirePower() > 0) {
            lowestPower = ship[i].GetTotalFirePower();
            shipLoc = i;
        }
    }
    cout << "Name: " << ship[shipLoc].GetName() << endl;
    cout << "Class: " << ship[shipLoc].GetClass() << endl;
    cout << "Length: " << ship[shipLoc].GetLength() << endl;
    cout << "Shield capacity:" << ship[shipLoc].GetShieldCapacity() << endl;
    cout << "Maximum Warp: " << ship[shipLoc].GetMaxWarp() << endl;
    cout << "Armaments: " << endl;
    for (unsigned int j = 0; j < ship[shipLoc].GetWeaponNames().size(); j++) {
        cout << ship[shipLoc].GetWeaponNames().at(j) << ", " << ship[shipLoc].GetPowerRatings().at(j) << ", "
             << ship[shipLoc].GetPowerConsumptions().at(j) << endl;
    }
    cout << "Total firepower: " << ship[shipLoc].GetTotalFirePower() << endl;

}

void PrintAllShips(vector<extrafile>& ship) {
    for(unsigned int i = 0; i < ship.size(); i++) {
        cout << "Name: " << ship[i].GetName() << endl;
        cout << "Class: " << ship[i].GetClass() << endl;
        cout << "Length: " << ship[i].GetLength() << endl;
        cout << "Shield capacity:" << ship[i].GetShieldCapacity() << endl;
        cout << "Maximum Warp: " << ship[i].GetMaxWarp() << endl;
        cout << "Armaments: " << endl;
        if (ship[i].GetTotalFirePower() == 0) {
            cout << "Unarmed" << endl;
        } else {
            for (unsigned int j = 0; j < ship[i].GetWeaponNames().size(); j++) {
                cout << ship[i].GetWeaponNames().at(j) << ", " << ship[i].GetPowerRatings().at(j) << ", "
                     << ship[i].GetPowerConsumptions().at(j) << endl;
            }
            cout << "Total firepower: " << ship[i].GetTotalFirePower() << endl;
        }
        cout << endl;
    }
}

void FindShipStrongestWeapon(vector<extrafile>& ship) {
    int highestPowerWeapon = ship[0].GetPowerRatings().at(0);
    unsigned int shipLoc = 0;
    for (unsigned int i = 0; i < ship.size(); i++) {
        for (unsigned int j = 0; j < ship[i].GetPowerRatings().size(); j++) {
            if(ship[i].GetPowerRatings().at(j) > highestPowerWeapon) {
                highestPowerWeapon = ship[i].GetPowerRatings().at(j);
                shipLoc = i;
            }
        }
    }
    cout << "Name: " << ship[shipLoc].GetName() << endl;
    cout << "Class: " << ship[shipLoc].GetClass() << endl;
    cout << "Length: " << ship[shipLoc].GetLength() << endl;
    cout << "Shield capacity:" << ship[shipLoc].GetShieldCapacity() << endl;
    cout << "Maximum Warp: " << ship[shipLoc].GetMaxWarp() << endl;
    cout << "Armaments: " << endl;
    for (unsigned int j = 0; j < ship[shipLoc].GetWeaponNames().size(); j++) {
        cout << ship[shipLoc].GetWeaponNames().at(j) << ", " << ship[shipLoc].GetPowerRatings().at(j) << ", "
             << ship[shipLoc].GetPowerConsumptions().at(j) << endl;
    }
    cout << "Total firepower: " << ship[shipLoc].GetTotalFirePower() << endl;
}

void PrintUnarmedShips(vector<extrafile>& ship) {
    for(unsigned int i = 0; i < ship.size(); i++) {
        if (ship[i].GetTotalFirePower() == 0) {
            cout << "Name: " << ship[i].GetName() << endl;
            cout << "Class: " << ship[i].GetClass() << endl;
            cout << "Length: " << ship[i].GetLength() << endl;
            cout << "Shield capacity:" << ship[i].GetShieldCapacity() << endl;
            cout << "Maximum Warp: " << ship[i].GetMaxWarp() << endl;
            cout << "Armaments: " << endl;
            cout << "Unarmed" << endl;
            cout << endl;
        }
    }
}

void GetDataFromBinaryFile (string filePath, vector<extrafile>& ship) {

    ifstream inFile(filePath, ios_base::binary);

    unsigned int count;
    inFile.read((char*)&count, 4);
    for(unsigned int i = 0; i < count; i++) {
        int length;
        inFile.read((char*)&length, 4);
        char* buffer = new char[length];
        inFile.read(buffer, length);
        string name = buffer;
        delete[] buffer;


        inFile.read((char*)&length, 4);
        buffer = new char[length];
        inFile.read(buffer, length);
        string shipClass = buffer;
        delete[] buffer;

        int shipLength;
        inFile.read((char*)&shipLength, 2);

        int shieldCapacity;
        inFile.read((char*)&shieldCapacity, 4);

        float maxWarp;
        inFile.read((char*)&maxWarp, 4);

        unsigned int weaponCount;

        inFile.read((char*)&weaponCount, 4);
        vector<string> weaponNames;
        vector<int> powerRatings;
        vector<float> powerConsumptions;
        if (weaponCount != 0) {
            for (unsigned int j = 0; j < weaponCount; j++) {
                inFile.read((char *) &length, 4);
                buffer = new char[length];
                inFile.read(buffer, length);
                string weaponName = buffer;
                delete[] buffer;
                weaponNames.push_back(weaponName);

                int powerRating;
                inFile.read((char *) &powerRating, 4);
                powerRatings.push_back(powerRating);

                float powerConsumption;
                inFile.read((char *) &powerConsumption, 4);
                powerConsumptions.push_back(powerConsumption);
            }
        }
        extrafile newShip(name, shipClass, shipLength, shieldCapacity, maxWarp, weaponNames, powerRatings, powerConsumptions);
        ship.push_back(newShip);
    }

}

int main()
{
	cout << "Which file(s) to open?\n";
	cout << "1. friendlyships.shp" << endl;
	cout << "2. enemyships.shp" << endl;
	cout << "3. Both files" << endl;
	int option;
	cin >> option;

   /* Load files here */
    vector<extrafile> ship;
    if(option == 1) {
        GetDataFromBinaryFile("friendlyships.shp", ship);
    } else if (option == 2) {
        GetDataFromBinaryFile("enemyships.shp", ship);
    } else if (option == 3) {
        GetDataFromBinaryFile("friendlyships.shp", ship);
        GetDataFromBinaryFile("enemyships.shp", ship);
    } else {
        cout << "Option not available." << endl;
    }

	cout << "1. Print all ships" << endl;
	cout << "2. Starship with the strongest weapon" << endl;
	cout << "3. Strongest starship overall" << endl;
	cout << "4. Weakest ship (ignoring unarmed)" << endl;
	cout << "5. Unarmed ships" << endl;

	cin >> option;

	/* Work your magic here */
    if (option == 1) {
        PrintAllShips(ship);
    } else if (option == 2) {
        FindShipStrongestWeapon(ship);
    } else if (option == 3) {
        FindStrongestShip(ship);
    } else if (option == 4) {
        FindWeakestShip(ship);
    } else if (option == 5) {
        PrintUnarmedShips(ship);
    } else {
        cout << "Option not available." << endl;
    }

   return 0;
}