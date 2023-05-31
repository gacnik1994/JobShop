#include "Product.h"
#include <string>
using namespace std;
string Product::toString(){
        string toString = "Product #" + to_string(product_number) + "\n";
        if(release_day == 0){
            toString += "Product was not yet released.\n";
        }else{
            toString +=  "Release day: "+ to_string(release_day) + "\n";
        }
        for(int i = 0 ; i < 4 ; ++i ){
            toString += "Operation ";
            toString.push_back(operation[i]);
            toString +=" ";
            if(day_complete[i] == 0 ){
                toString += "____\n";
            }else if(day_complete[i] > 9){
                toString +=  " " + to_string(day_complete[i]) + "\n";
            }else{
                toString +=  "  " + to_string(day_complete[i]) + "\n";
            }
        }
        if(day_complete[3] == 0){
            toString += "Product is still in production.\n";
        }else{
            toString += "Product was completed in " + to_string(flow_days) + " days.\n";
        }
        toString += "\n\n";
        return toString;
    }
    
void Product::toConsole(){
        
        cout << "Product #" << product_number << "\n";
        if(release_day == 0){
            cout << "Product was not yet released." << "\n";
        }else{
            cout << "Release day: " << release_day << "\n";
        }
        for(int i = 0 ; i < 4 ; ++i ){
            cout << "Operation " << operation[i] << " ";
            if(day_complete[i] == 0 ){
                cout << "____\n";
            }else if(day_complete[i] > 9){
                cout << " " << day_complete[i] << "\n";
            }else{
                cout << "  " << day_complete[i] << "\n";
            }
        }
        if(day_complete[3] == 0){
            cout << "Product is still in production.\n";
        }else{
            cout << "Product was completed in " << flow_days << " days." << endl;
        }
    }


