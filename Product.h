#ifndef _PRODUCT_H_
#define _PRODUCT_H_
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class Product
{

private:
    int product_number;
    int release_day {0};
    char operation[4];
    int day_complete[4] {0};
    int flow_days;
    
public:
    Product(int pn, char operation1, char operation2, char operation3, char operation4){
        product_number = pn;
        operation[0] = operation1;
        operation[1] = operation2;
        operation[2] = operation3;
        operation[3] = operation4;
        }
    
    int get_product_number(){
        return product_number;
    }
    
    
    int get_day_complete_at(int i){
        return day_complete[i];
        }
    char get_operation_at(int i){
        
            char t = operation[i];
        return t;
    }
    int* get_day_complete(){
        int *arr = new int[4];
        for(int i = 0; i<4;++i){
            arr[i] = day_complete[i];
        }
        return arr;
    }
    void set_day_complete(int *a){
        int *arr = new int[4];
        arr = a;
        for(int i = 0 ; i < 4 ; ++i){
            day_complete[i] = arr[i];
        }
    }
    char* get_operation(){
        char *arr = new char[4];
        for(int i = 0; i<4;++i){
            arr[i] = operation[i];
        }
        return arr;
    }
    void set_day_complete_at(int day, int index){
        day_complete[index] = day;
    }
    void set_release_day(int rd){
        release_day = rd;
    }
    void set_flow_days(int fd){
        flow_days = fd;
        }
    int get_release_day(){
        return release_day;
    }
    void toConsole();
    
    std::string toString();
};

#endif // _PRODUCT_H_
