/*
 * ==========================================================================
 *  BEE 208 - C++ PROGRAMMING
 *  MID-SEMESTER PRACTICAL PROJECT EXAMINATION - PROJECT QUESTION 13
 *  TRANSFORMER LOAD AND EFFICIENCY CALCULATOR SYSTEM
 *
 *  Description:
 *      This program records transformer information, accepts details of
 *      several connected loads, calculates the total connected load and
 *      apparent load, estimates the transformer loading percentage,
 *      classifies the loading status, displays a full report on screen
 *      and saves the same report to "transformer_report.txt".
 *
 *  Required C++ concepts demonstrated:
 *      - Input / output (cin / cout)
 *      - Variables and data types
 *      - Operators and expressions
 *      - Conditional statements (if / else if)
 *      - Loops (for / while / do-while)
 *      - Functions
 *      - Classes and objects
 *      - Vectors (dynamic array of LoadItem objects)
 *      - File handling (ofstream)
 *      - Input validation
 * ==========================================================================
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

/* ==========================================================================
 *  CLASS: LoadItem
 *  Represents a single connected load type (e.g. Lighting Circuit).
 * ==========================================================================
 */
class LoadItem {
private:
    string loadName;
    double powerRatingWatts;
    int quantity;
    double loadPowerWatts;

public:
    // Collects and validates the details of one load type from the user
    void inputLoadDetails(int index) {
        cout << "\n--- Load Type " << index << " ---" << endl;

        cout << "Enter load name: ";
        getline(cin, loadName);

        powerRatingWatts = readValidatedDouble("Enter power rating in watts: ");
        quantity = static_cast<int>(readValidatedDouble("Enter quantity: "));

        loadPowerWatts = powerRatingWatts * quantity;
        cout << "Load Power: " << fixed << setprecision(2)
             << loadPowerWatts << " W" << endl;
    }

    // Reads a double from the console and rejects negative values.
    // Always leaves the input stream positioned right after the newline,
    // so a getline() call immediately after this one works correctly.
    double readValidatedDouble(const string &prompt) {
        double value;
        while (true) {
            cout << prompt;
            cin >> value;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a numeric value.\n";
                continue;
            }
            if (value < 0) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Value cannot be negative. Try again.\n";
                continue;
            }
            break;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return value;
    }

    double getLoadPowerWatts() const { return loadPowerWatts; }
    string getLoadName() const { return loadName; }
    double getPowerRatingWatts() const { return powerRatingWatts; }
    int getQuantity() const { return quantity; }
};

/* ==========================================================================
 *  CLASS: Transformer
 *  Represents the transformer under test and performs all calculations.
 * ==========================================================================
 */
class Transformer {
private:
    string transformerName;
    double transformerRatingKVA;
    double primaryVoltage;
    double secondaryVoltage;
    double powerFactor;
    double totalLoadWatts;
    double apparentLoadKVA;
    double loadingPercentage;
    vector<LoadItem> loads;

    // Generic validated-double reader reused for transformer-level inputs.
    // Always leaves the input stream positioned right after the newline,
    // so a getline() call immediately after this one works correctly.
    double readValidatedDouble(const string &prompt, double maxValue = -1) {
        double value;
        while (true) {
            cout << prompt;
            cin >> value;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a numeric value.\n";
                continue;
            }
            if (value < 0) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Value cannot be negative. Try again.\n";
                continue;
            }
            if (maxValue > 0 && value > maxValue) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Value out of acceptable range. Try again.\n";
                continue;
            }
            break;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return value;
    }

public:
    // Constructor initialises all numeric members to zero
    Transformer() {
        transformerRatingKVA = 0;
        primaryVoltage = 0;
        secondaryVoltage = 0;
        powerFactor = 0;
        totalLoadWatts = 0;
        apparentLoadKVA = 0;
        loadingPercentage = 0;
    }

    // Collects transformer name, rating, voltages and power factor
    void setTransformerDetails() {
        cout << "\nEnter transformer name: ";
        getline(cin, transformerName);

        transformerRatingKVA = readValidatedDouble("Enter transformer rating in kVA: ");
        primaryVoltage       = readValidatedDouble("Enter primary voltage: ");
        secondaryVoltage     = readValidatedDouble("Enter secondary voltage: ");
        powerFactor          = readValidatedDouble("Enter power factor (0 to 1): ", 1.0);
    }

    // Confirms that the entered transformer details make physical sense
    bool validateTransformerDetails() const {
        if (transformerRatingKVA <= 0) {
            cout << "Error: Transformer rating must be greater than zero.\n";
            return false;
        }
        if (primaryVoltage <= 0 || secondaryVoltage <= 0) {
            cout << "Error: Voltages must be greater than zero.\n";
            return false;
        }
        if (powerFactor <= 0 || powerFactor > 1) {
            cout << "Error: Power factor must be between 0 and 1.\n";
            return false;
        }
        return true;
    }

    // Loops through the number of load types entered by the user
    void addLoadDetails() {
        int numberOfLoads;
        cout << "\nEnter number of load types: ";
        while (true) {
            cin >> numberOfLoads;
            if (cin.fail() || numberOfLoads <= 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Enter a whole number greater than zero: ";
                continue;
            }
            break;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 1; i <= numberOfLoads; i++) {
            LoadItem item;
            item.inputLoadDetails(i);
            loads.push_back(item);
            totalLoadWatts += item.getLoadPowerWatts();
        }
    }

    // Apparent Load (kVA) = Total Load / (Power Factor x 1000)
    double calculateApparentLoad() {
        apparentLoadKVA = totalLoadWatts / (powerFactor * 1000.0);
        return apparentLoadKVA;
    }

    // Loading Percentage = (Apparent Load / Transformer Rating) x 100
    double calculateLoadingPercentage() {
        loadingPercentage = (apparentLoadKVA / transformerRatingKVA) * 100.0;
        return loadingPercentage;
    }

    // Classifies the transformer load status based on loading percentage
    string determineLoadStatus() const {
        if (loadingPercentage < 40.0) {
            return "Lightly Loaded";
        } else if (loadingPercentage <= 80.0) {
            return "Normal Operating Range";
        } else if (loadingPercentage <= 100.0) {
            return "Near Full Load";
        } else {
            return "Overloaded Transformer Warning";
        }
    }

    // Displays the full transformer load report on screen
    void displayTransformerReport() {
        string status = determineLoadStatus();

        cout << fixed << setprecision(2);
        cout << "\n==================================================\n";
        cout << "            TRANSFORMER LOAD REPORT\n";
        cout << "==================================================\n";
        cout << "Transformer Name        : " << transformerName << endl;
        cout << "Transformer Rating      : " << transformerRatingKVA << " kVA" << endl;
        cout << "Primary Voltage         : " << primaryVoltage << " V" << endl;
        cout << "Secondary Voltage       : " << secondaryVoltage << " V" << endl;
        cout << "Power Factor            : " << powerFactor << endl;
        cout << "--------------------------------------------------\n";
        cout << "Total Connected Load    : " << totalLoadWatts << " W" << endl;
        cout << "Estimated Apparent Load : " << apparentLoadKVA << " kVA" << endl;
        cout << "Loading Percentage      : " << loadingPercentage << " %" << endl;
        cout << "Load Status             : " << status << endl;
        cout << "==================================================\n";
    }

    // Saves the same report to transformer_report.txt
    void saveReportToFile() {
        ofstream outFile("transformer_report.txt");
        string status = determineLoadStatus();

        if (!outFile) {
            cout << "Error: Could not open file for writing.\n";
            return;
        }

        outFile << fixed << setprecision(2);
        outFile << "==================================================\n";
        outFile << "            TRANSFORMER LOAD REPORT\n";
        outFile << "==================================================\n";
        outFile << "Transformer Name        : " << transformerName << endl;
        outFile << "Transformer Rating      : " << transformerRatingKVA << " kVA" << endl;
        outFile << "Primary Voltage         : " << primaryVoltage << " V" << endl;
        outFile << "Secondary Voltage       : " << secondaryVoltage << " V" << endl;
        outFile << "Power Factor            : " << powerFactor << endl;
        outFile << "--------------------------------------------------\n";
        outFile << "Connected Loads:\n";
        for (size_t i = 0; i < loads.size(); i++) {
            outFile << "  " << (i + 1) << ". " << loads[i].getLoadName()
                     << " - Rating: " << loads[i].getPowerRatingWatts() << " W"
                     << ", Quantity: " << loads[i].getQuantity()
                     << ", Load Power: " << loads[i].getLoadPowerWatts() << " W\n";
        }
        outFile << "--------------------------------------------------\n";
        outFile << "Total Connected Load    : " << totalLoadWatts << " W" << endl;
        outFile << "Estimated Apparent Load : " << apparentLoadKVA << " kVA" << endl;
        outFile << "Loading Percentage      : " << loadingPercentage << " %" << endl;
        outFile << "Load Status             : " << status << endl;
        outFile << "==================================================\n";

        outFile.close();
        cout << "\nReport saved to transformer_report.txt" << endl;
    }
};

/* ==========================================================================
 *  FUNCTION: main
 * ==========================================================================
 */
int main() {
    Transformer transformer;

    cout << "==================================================\n";
    cout << "  TRANSFORMER LOAD AND EFFICIENCY CALCULATOR SYSTEM\n";
    cout << "==================================================\n";

    // Loop until valid transformer details are entered
    do {
        transformer.setTransformerDetails();
    } while (!transformer.validateTransformerDetails());

    transformer.addLoadDetails();

    transformer.calculateApparentLoad();
    transformer.calculateLoadingPercentage();

    transformer.displayTransformerReport();
    transformer.saveReportToFile();

    cout << "\nProgramme finished. Thank you for using the "
         << "Transformer Load and Efficiency Calculator System.\n";

    return 0;
}
