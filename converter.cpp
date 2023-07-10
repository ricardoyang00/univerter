#include <iostream>
#include <map>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

void print_result(const string result){
    string text = result;
    int totalWidth = 32;
    int padding = (totalWidth - text.length()) / 2;

    cout << endl;
    cout << "▼▼▼▼▼▼▼▼▼▼▼▼▼ RESULT ▼▼▼▼▼▼▼▼▼▼▼▼▼" << endl;
    cout << setw(padding+1) << "" << text << setw(totalWidth - padding - text.length()) << "" << endl;
    cout << "▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲" << endl;
}

vector<pair<string, int>> controller(const string indicator){
    vector<pair<string, int>> result;

    if (indicator == "initial_table"){
        result = {
            {"Length", 1},
            {"Temperature", 2},
            {"Area", 3},
            {"Volume", 4},
            {"Weight", 5},
            {"Time", 6},
            {"Number", 7}
        };
    }

    if (indicator == "1"){
        result = {   
            {"Meter", 1},
            {"Kilometer", 2},
            {"Centimeter", 3},
            {"Millimeter", 4},
            {"Micrometer", 5},
            {"Nanometer", 6},
            {"Mile", 7},
            {"Yard", 8},
            {"Foot", 9},
            {"Inch", 10},
            {"Light Year", 11}
        };
    }

    if (indicator == "2"){
        result = {   
            {"Celsius", 1},
            {"Kelvin", 2},
            {"Fahrenheit", 3},
        };
    }

    if (indicator == "3"){
        result = {   
            {"Square Meter", 1},
            {"Square Kilometer", 2},
            {"Square Centimeter", 3},
            {"Square Millimeter", 4},
            {"Square Micrometer", 5},
            {"Hectare", 6},
            {"Square Mile", 7},
            {"Square Yard", 8},
            {"Square Foot", 9},
            {"Square Inch", 10},
        };
    }

    if (indicator == "4"){
        result = {
            {"Cubic Meter", 1},
            {"Cubic Kilometer", 2},
            {"Cubic Centimeter", 3},
            {"Cubic Millimeter", 4},
            {"Liter", 5},
            {"Milliliter", 6},
            {"Gallon", 7},
            {"Quart", 8},
            {"Pint", 8},
            {"Cup", 9},
            {"Fluid Ounce", 10},
            {"Barrel", 11},
            {"Cubic Yard", 12},
            {"Cubic Foot", 13},
            {"Cubic Inch", 14},
            {"Teaspoon", 15},
            {"Tablespoon", 16}
        };
    }

    if (indicator == "5"){
        result = {
            {"Kilogram", 1},
            {"Gram", 2},
            {"Milligram", 3},
            {"Metric Ton", 4},
            {"Long Ton", 5},
            {"Short Ton", 6},
            {"Pound", 7},
            {"Ounce", 8},
            {"Carat", 9},
            {"Atomic Mass Unit", 10}
        };
    }

    if (indicator == "6"){
        result = {
            {"Second", 1},
            {"Millisecond", 2},
            {"Microsecond", 3},
            {"Nanosecond", 4},
            {"Minute", 5},
            {"Hour", 6},
            {"Day", 7},
            {"Week", 8},
            {"Month", 9},
            {"Year", 10},
        };
    }
    if (indicator == "7"){
        result = {
            {"Binary", 1},
            {"Decimal", 2},
            {"Octal", 3},
            {"Hexadecimal", 4}
        };
    }

    return result;
}

string get_unit_type(const string indicator){
    string name;
    int indicator_ = stoi(indicator);
    vector<pair<string, int>> names = controller("initial_table");
    
    for (auto c : names){
        if (c.second == indicator_){
            name = c.first;
            break;
        }
    }

    for (auto& c : name){
        c = toupper(c);
    }

    return name;
}

void Table_start() {
    vector<pair<string, int>> converterTable = controller("initial_table");

    cout << "+--------+-----------------------+" << endl;
    cout << "|  CODE  |    UNIT TYPE          |" << endl;
    cout << "+--------+-----------------------+" << endl;   
    for (const auto& entry : converterTable) {
        cout << "|   " << left << setw(5) << entry.second << "|    " << setw(19) << entry.first << "|" << endl;
    }
    cout << "+--------+-----------------------+" << endl << endl;
}

void Table_units(string indicator) {
    vector<pair<string, int>> converterTable = controller(indicator);

    cout << endl;
    cout << "+--------+-----------------------+" << endl;
    cout << "|  CODE  |    UNIT               |"<< endl;
    cout << "+--------+-----------------------+" << endl;   
    for (const auto& entry : converterTable) {
        cout << "|   " << left << setw(5) << entry.second << "|    " << setw(19) << entry.first << "|" << endl;
    }
    cout << "+--------+-----------------------+" << endl << endl;
}

void conversion_measure(){
    map<string,double> Factor = {
        {"Meter", 1.0},
        {"Kilometer", 1000.0},
        {"Centimeter", 0.01},
        {"Millimeter", 0.001},
        {"Micrometer", 0.000001},
        {"Nanometer", 0.000000001},
        {"Mile", 1609.344},
        {"Yard", 0.9144},
        {"Foot", 0.3048},
        {"Inch", 0.0254},
        {"Light Year", 9.461e+15}
    };
    int UnitFrom, UnitTo;
    double value;
    string UnitFrom_, UnitTo_;
    
    cout << "✤ Enter the Unit to Convert From: ";
    cin >> UnitFrom;
    cout << "✤ Enter the Unit to Convert To: ";
    cin >> UnitTo;
    cout << "✤ Enter the convert value: ";
    cin >> value;

    vector<pair<string, int>> converterTable = controller("1");

    for (auto& c : converterTable){
        if (c.second == UnitFrom){
            UnitFrom_ = c.first;
            break;
        }
    }
    for (auto& c : converterTable){
        if (c.second == UnitTo){
            UnitTo_ = c.first;
            break;
        }
    }

    string result = to_string(value * (Factor[UnitFrom_]/Factor[UnitTo_]));
    print_result(result);
}

void conversion_temperature(){
    string UnitFrom, UnitTo;
    double value;
    int precision;

    cout << "✤ Enter the Unit to Convert From: ";
    cin >> UnitFrom;
    cout << "✤ Enter the Unit to Convert To: ";
    cin >> UnitTo;
    cout << "✤ Enter the convert value: ";
    cin >> value;

    if (UnitFrom == "3"){
        value = (value - 32) * 5/9;
    }
    if (UnitFrom == "2"){
        value = value - 273.15;
    }
    if (UnitTo == "3"){
        value = (value * 9/5) + 32;
    }
    if (UnitTo == "2"){
        value = value + 273.15;
    }

    string result = to_string(value);
    print_result(result);
}

void conversion_area(){
    map<string,double> Factor = {
        {"Square Meter", 1.0},
        {"Square Kilometer", 1.0e+6},
        {"Square Centimeter", 1.0e-4},
        {"Square Millimeter", 1.0e-6},
        {"Square Micrometer", 1.0e-12},
        {"Hectare", 10000.0},
        {"Square Mile", 2.59e+6},
        {"Square Yard", 0.836127},
        {"Square Foot", 0.092903},
        {"Square Inch", 0.00064516}
    };
    int UnitFrom, UnitTo;
    double value;
    string UnitFrom_, UnitTo_;
    
    cout << "✤ Enter the Unit to Convert From: ";
    cin >> UnitFrom;
    cout << "✤ Enter the Unit to Convert To: ";
    cin >> UnitTo;
    cout << "✤ Enter the convert value: ";
    cin >> value;

    vector<pair<string, int>> converterTable = controller("3");

    for (auto& c : converterTable){
        if (c.second == UnitFrom){
            UnitFrom_ = c.first;
            break;
        }
    }
    for (auto& c : converterTable){
        if (c.second == UnitTo){
            UnitTo_ = c.first;
            break;
        }
    }

    string result = to_string(value * (Factor[UnitFrom_]/Factor[UnitTo_]));
    print_result(result);
}

void conversion_volume(){
    map<string, double> Factor = {
        {"Cubic Meter", 1.0},
        {"Cubic Kilometer", 1.0e-9},
        {"Cubic Centimeter", 1.0e+6},
        {"Cubic Millimeter", 1.0e+9},
        {"Liter", 1000.0},
        {"Milliliter", 1.0e+6},
        {"Gallon", 264.172},
        {"Quart", 1056.69},
        {"Pint", 2113.38},
        {"Cup", 4226.75},
        {"Fluid Ounce", 33814.0},
        {"Barrel", 6.28981},
        {"Cubic Yard", 1.30795},
        {"Cubic Foot", 35.3147},
        {"Cubic Inch", 61023.7},
        {"Teaspoon", 202884.0},
        {"Tablespoon", 67628.0}
    };
    int UnitFrom, UnitTo;
    double value;
    string UnitFrom_, UnitTo_;
    
    cout << "✤ Enter the Unit to Convert From: ";
    cin >> UnitFrom;
    cout << "✤ Enter the Unit to Convert To: ";
    cin >> UnitTo;
    cout << "✤ Enter the convert value: ";
    cin >> value;

    vector<pair<string, int>> converterTable = controller("4");

    for (auto& c : converterTable){
        if (c.second == UnitFrom){
            UnitFrom_ = c.first;
            break;
        }
    }
    for (auto& c : converterTable){
        if (c.second == UnitTo){
            UnitTo_ = c.first;
            break;
        }
    }

    string result = to_string(value * (Factor[UnitFrom_]/Factor[UnitTo_]));
    print_result(result);
}

void conversion_weight(){
    map<string, double> Factor = {
        {"Kilogram", 1.0},
        {"Gram", 0.001},
        {"Milligram", 1.0e-6},
        {"Metric Ton", 1000.0},
        {"Long Ton", 1016.05},
        {"Short Ton", 907.185},
        {"Pound", 0.453592},
        {"Ounce", 0.0283495},
        {"Carat", 0.0002},
        {"Atomic Mass Unit", 1.66054e-27}
    };
    int UnitFrom, UnitTo;
    double value;
    string UnitFrom_, UnitTo_;

    cout << "✤ Enter the Unit to Convert From: ";
    cin >> UnitFrom;
    cout << "✤ Enter the Unit to Convert To: ";
    cin >> UnitTo;
    cout << "✤ Enter the convert value: ";
    cin >> value;

    vector<pair<string, int>> converterTable = controller("5");

    for (auto& c : converterTable){
        if (c.second == UnitFrom){
            UnitFrom_ = c.first;
            break;
        }
    }
    for (auto& c : converterTable){
        if (c.second == UnitTo){
            UnitTo_ = c.first;
            break;
        }
    }

    string result = to_string(value * (Factor[UnitFrom_]/Factor[UnitTo_]));
    print_result(result);
}

void conversion_time(){
    map<string, double> Factor = {
        {"Second", 1.0},
        {"Millisecond", 0.001},
        {"Microsecond", 1.0e-6},
        {"Nanosecond", 1.0e-9},
        {"Minute", 60.0},
        {"Hour", 3600.0},
        {"Day", 86400.0},
        {"Week", 604800.0},
        {"Month", 2592000.0},
        {"Year", 31536000.0},
    };
    int UnitFrom, UnitTo;
    double value;
    string UnitFrom_, UnitTo_;
    
    cout << "✤ Enter the Unit to Convert From: ";
    cin >> UnitFrom;
    cout << "✤ Enter the Unit to Convert To: ";
    cin >> UnitTo;
    cout << "✤ Enter the convert value: ";
    cin >> value;

    vector<pair<string, int>> converterTable = controller("6");

    for (auto& c : converterTable){
        if (c.second == UnitFrom){
            UnitFrom_ = c.first;
            break;
        }
    }
    for (auto& c : converterTable){
        if (c.second == UnitTo){
            UnitTo_ = c.first;
            break;
        }
    }

    string result = to_string(value * (Factor[UnitFrom_]/Factor[UnitTo_]));
    print_result(result);
}

void conversion_binary(int decimal, string& result){
    string binary;

    if (decimal == 0){
        binary = '0';
    }

    while (decimal > 0){
        int remainder = decimal % 2;
        binary = to_string(remainder) + binary;
        decimal /= 2;
    }
    
    result = binary;
}

void conversion_octal(int decimal, string& result){
    string octal;

    if (decimal == 0){
        octal = '0';
    }

    while (decimal > 0){
        int remainder = decimal % 8;
        octal = to_string(remainder) + octal;
        decimal /= 8;
    }
    
    result = octal;
}

void conversion_binary_decimal(string& binary){
    int decimal = 0;
    int power = 1;

    for (int i = binary.length() - 1; i >= 0; --i){
        int digit = binary[i] - '0';
        decimal += digit * power;
        power*=2;
    }
    binary = to_string(decimal);
}

void conversion_octal_decimal(string& octal){
    int decimal = 0;
    int power = 1;
    for (int i = octal.length() - 1; i >= 0; --i){
        int digit = octal[i] - '0';
        decimal += digit * power;
        power *= 8;
    }
    octal = to_string(decimal);
}

void conversion_hexadecimal_decimal(string& hex){
    int decimal = 0;
    int power = 1;

    for (int i = hex.length() -1 ; i >= 0; --i){
        int digit;
        char character = hex[i];

        if (character >= '0' and character <= '9'){
            digit = character - '0';
        }

        if (character >= 'A' and character <= 'F'){
            digit = character - 'A' + 10;
        }

        if (character >= 'a' and character <= 'f'){
            digit = character - 'a' + 10;
        }
        
        decimal += digit * power;
        power *= 16;
    }
    hex = to_string(decimal);
}

void conversion_hexadecimal(int decimal, string& result){
    stringstream stream;
    stream << hex << decimal;
    result = stream.str();

    for (char& c : result){
        c = toupper(c);
    }
}

void conversion_number(){
    string UnitFrom, UnitTo, value, result;
    int decimal;

    cout << "✤ Enter the Unit to Convert From: ";
    cin >> UnitFrom;
    cout << "✤ Enter the Unit to Convert To: ";
    cin >> UnitTo;
    cout << "✤ Enter the convert value: ";
    cin >> value;

    if (UnitFrom != "2"){
        if (UnitFrom == "1"){
            conversion_binary_decimal(value);
        }

        if (UnitFrom == "2"){
            conversion_octal_decimal(value);
        }

        if (UnitFrom == "4"){
            conversion_hexadecimal_decimal(value);
        }
    }

    decimal = stoi(value);

    if (UnitTo == "2"){
        result = value;
    }

    if (UnitTo == "1"){
        conversion_binary(decimal, result);
    }

    if (UnitTo == "3"){
        conversion_octal(decimal, result);
    }

    if (UnitTo == "4"){
        conversion_hexadecimal(decimal, result);
    }

    print_result(result);
}

void script(const string unittype){
        if (unittype == "1"){
            Table_units(unittype);
            conversion_measure();
        }
        if (unittype == "2"){
            Table_units(unittype);
            conversion_temperature();
        }
        if (unittype == "3"){
            Table_units(unittype);
            conversion_area();
        }
        if (unittype == "4"){
            Table_units(unittype);
            conversion_volume();
        }
        if (unittype == "5"){
            Table_units(unittype);
            conversion_weight();
        }
        if (unittype == "6"){
            Table_units(unittype);
            conversion_time();
        }
        if (unittype == "7"){
            Table_units(unittype);
            conversion_number();
        }
}

int main(){
    while (true){
        cout << u8"\033[2J\033[1;1H"; 
        Table_start();
        string unittype, name_unittype;

        cout << "✤ Enter the UNIT TYPE code: ";
        cin >> unittype;
        cout << u8"\033[2J\033[1;1H"; 
        name_unittype = get_unit_type(unittype);
        cout << "+--------------------------------+" << endl;
        cout << "|  ✪        " << setw(18) << name_unittype << "✪  |";

        script(unittype);

        string again;
        cout << endl << "TRY AGAIN? (y/n): ";
        cin >> again;
        if (again == "n"){
            cout << u8"\033[2J\033[1;1H";
            cout << "Program execution completed" << endl;
            break;
        }
    }
    return 0;
}


