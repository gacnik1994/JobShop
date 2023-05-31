#include <iostream>
#include "Product.h"
#include <random>
#include <ctime>
#include <fstream> 
#include <string>
#include <windows.h>

using namespace std;

int main() {
    //int cin_input;    
    Product product1 {1, 'A', 'B', 'C', 'D'};
    Product product2 {2, 'B', 'C', 'B', 'D'};
    Product product3 {3, 'A', 'C', 'D', 'B'};
    Product product4 {4, 'A', 'B', 'B', 'C'};
    int p1_size {5};
    int p2_size {5};
    int p3_size {5};
    int p4_size {5};
    vector<Product> products;
    vector<Product> in_production;
    vector<Product> finished;
    //vector<Product> p_buffer {product1,product2,product3,product4};
    /*vector<Product> p_buffer {product1,product1,product1,product1,product1,
                                   product2,product2,product2,product2,product2,
                                   product3,product3,product3,product3,product3,
                                   product4,product4,product4,product4,product4};*/
    
     int joke {0};
     int pb_size {0};
     do{
        cout << "Na voljo imate:" << endl;
        if(p1_size > 0){
            cout << p1_size << " * Produkt 1" << endl; 
        }
        if(p2_size > 0){
            cout << p2_size << " * Produkt 2 "<< endl;
        }
        if(p3_size > 0){
            cout << p3_size << " * Produkt 3 "<< endl;
        }
        if(p4_size > 0){
            cout << p4_size << " * Produkt 4 " << endl;
        }
         cout << "Izberite produkt, ki ga zelite dodati v vrsto s stevilko od 1-4:";
         int product_no;
         cin >> product_no;
         switch(product_no){
            case 1:
                if(p1_size == 0){
                    cout << "Napacen vnos, poskusi ponovno" << endl;
                    joke++;
                    if(joke == 3){
                        cout << "Trikrat ste napacno vnesli stevilko, BRAVO!" << endl;
                        cout << "Vec srece prihodnjic. Program se bo ugasnil cez..." <<endl;
                        for(int i = 5; i > 0  ; --i){
                            cout  << i << endl;
                            Sleep(1000);
                        }
                        return 1;
                    }
                    break;
                }
                p1_size--;
                products.push_back(product1);
                products.at(pb_size).toConsole();
                break; 
            case 2 :
                if(p2_size == 0){
                    cout << "Napacen vnos, poskusi ponovno" << endl;
                    joke++;
                    if(joke == 3){
                        cout << "Trikrat ste napacno vnesli stevilko, BRAVO!" << endl;
                        cout << "Vec srece prihodnjic. Program se bo ugasnil cez..." <<endl;
                        for(int i = 5; i > 0  ; --i){
                            cout << i << endl;
                            Sleep(1000);
                        }
                        return 1;
                    }
                    break;
                }
                p2_size--;
                products.push_back(product2);
                products.at(pb_size).toConsole();
                break;
            case 3:
                if(p3_size == 0){
                    cout << "Napacen vnos, poskusi ponovno" << endl;
                    joke++;
                    if(joke == 3){
                        cout << "Trikrat ste napacno vnesli stevilko, BRAVO!" << endl;
                        cout << "Vec srece prihodnjic. Program se bo ugasnil cez..." <<endl;
                        for(int i = 5; i > 0  ; --i){
                            cout << i << endl;
                            Sleep(1000);
                        }
                        return 1;
                    }
                    break;
                }
                p3_size--;
                products.push_back(product3);
                products.at(pb_size).toConsole();
                break;
            case 4:
                if(p4_size == 0){
                    cout << "Napacen vnos, poskusi ponovno" << endl;
                    joke++;
                    if(joke == 3){
                        cout << "Trikrat ste napacno vnesli stevilko, BRAVO!" << endl;
                        cout << "Vec srece prihodnjic. Program se bo ugasnil cez..." <<endl;
                        for(int i = 5; i > 0  ; --i){
                            cout  << i << endl;
                            Sleep(1000);
                        }
                        return 1;
                    }
                    break;
                }
                p4_size--;
                products.push_back(product4);
                products.at(pb_size).toConsole();
                break;
            default:
                cout << "Napacen vnos, poskusi ponovno" << endl;
                joke++;
                if(joke == 3){
                    cout << "Trikrat ste napacno vnesli stevilko, BRAVO!" << endl;
                    cout << "Vec srece prihodnjic. Program se bo ugasnil cez..." <<endl;
                    for(int i = 5; i > 0  ; --i){
                        cout << i << endl;
                        Sleep(1000);
                    }
                    return 1;
                }
                break;
        }
         pb_size = products.size();
    }while(pb_size < 20);
    cout << "Velikost vektorja products " << pb_size << endl;
    /*for(int i = 0 ; i  < 20 ; ++i){
        srand((unsigned) time(0));
        int p_buffer_size = p_buffer.size();
        int random_number = (rand()%p_buffer_size);
        products.push_back(p_buffer.at(random_number));
        
        for(int j = 0 ; j < random_number ; ++j){
            p_buffer.push_back(p_buffer.at(0));
            p_buffer.erase(p_buffer.begin());
        }
        p_buffer.erase(p_buffer.begin());
    }*/
    
    vector<Product> production_progress[4];
    int f_size = finished.size();
    int r {0};
    do{
        r++;
        int p_size = products.size();
        if(p_size > 0){
            products.at(0).set_release_day(r);
            in_production.push_back(products.at(0));
            products.erase(products.begin());
            //int in_size = in_production.size();
        }
        int pp0_size = production_progress[0].size();
        int pp1_size = production_progress[1].size();
        int pp2_size = production_progress[2].size();
        int pp3_size = production_progress[3].size();
        if(pp0_size > 0){
            int *oper = new int[4];
            oper = production_progress[0].at(0).get_day_complete();
            char *prog = new char[4];
            prog = production_progress[0].at(0).get_operation();
            for(int d = 0 ;  d <  4 ; ++d){
                if(prog[d] == 'A' && oper[d] == 0){
                        oper[d] = r;
                        production_progress[0].at(0).set_day_complete(oper);
                        if(d < 3){
                        in_production.push_back(production_progress[0].at(0));
                        }else{
                            production_progress[0].at(0).set_flow_days(oper[d]-production_progress[0].at(0).get_release_day());
                            finished.push_back(production_progress[0].at(0));
                        }
                        production_progress[0].erase(production_progress[0].begin());
                        break;
                }
            }
        }
        if(pp1_size > 0){
            int *oper = new int[4];
            oper = production_progress[1].at(0).get_day_complete();
            char *prog = new char[4];
            prog = production_progress[1].at(0).get_operation();
            for(int d = 0 ;  d <  4 ; ++d){
                if(prog[d] == 'B' && oper[d] == 0){
                        oper[d] = r;
                        production_progress[1].at(0).set_day_complete(oper);
                        if(d < 3){
                        in_production.push_back(production_progress[1].at(0));
                        }else{
                            production_progress[1].at(0).set_flow_days(oper[d]-production_progress[1].at(0).get_release_day());
                            finished.push_back(production_progress[1].at(0));
                        }
                        production_progress[1].erase(production_progress[1].begin());
                        break;
                }
            }
        }
        if(pp2_size > 0){
            int *oper = new int[4];
            oper = production_progress[2].at(0).get_day_complete();
            char *prog = new char[4];
            prog = production_progress[2].at(0).get_operation();
            for(int d = 0 ;  d <  4 ; ++d){
                if(prog[d] == 'C' && oper[d] == 0){
                        oper[d] = r;
                        production_progress[2].at(0).set_day_complete(oper);
                        if(d < 3){
                         in_production.push_back(production_progress[2].at(0));
                        }else{
                            production_progress[2].at(0).set_flow_days(oper[d]-production_progress[2].at(0).get_release_day());
                            finished.push_back(production_progress[2].at(0));
                        }
                            production_progress[2].erase(production_progress[2].begin());
                        break;
                }
            }
        }
        if(pp3_size > 0){
            int *oper = new int[4];
            oper = production_progress[3].at(0).get_day_complete();
            char *prog = new char[4];
            prog = production_progress[3].at(0).get_operation();
            for(int d = 0 ;  d <  4 ; ++d){
                if(prog[d] == 'D' && oper[d] == 0){
                        oper[d] = r;
                        production_progress[3].at(0).set_day_complete(oper);
                        if(d < 3){
                            in_production.push_back(production_progress[3].at(0));
                        }else{
                            production_progress[3].at(0).set_flow_days(oper[d]-production_progress[3].at(0).get_release_day());
                        finished.push_back(production_progress[3].at(0));
                        }
                        production_progress[3].erase(production_progress[3].begin());
                        break;
                }
            }
        }
        int ip_size =  in_production.size();
        if(ip_size > 0){
            do{
                Product waiting_production  = in_production.at(0);
                char *char_array = new char[4];
                char_array = waiting_production.get_operation();
                int *day_array =  new int[4];
                day_array = waiting_production.get_day_complete();
                for(int i = 0 ; i < 4 ; ++i){
                    if(day_array[i] == 0){
                            switch(char_array[i]){
                                    case 'A':
                                        production_progress[0].push_back(waiting_production);
                                        in_production.erase(in_production.begin());
                                        break;
                                    case 'B':
                                        production_progress[1].push_back(waiting_production);
                                        in_production.erase(in_production.begin());
                                        break;
                                    case 'C':
                                        production_progress[2].push_back(waiting_production);
                                        in_production.erase(in_production.begin());
                                        break;
                                    case 'D':
                                        production_progress[3].push_back(waiting_production);
                                        in_production.erase(in_production.begin());
                                        break;
                                    default:
                                        cout << "Napaka" << endl;
                                        return 1;
                            }
                        break;
                    }
                }
                ip_size = in_production.size();
            }while(ip_size != 0);
        } 
        f_size = finished.size();
    }while(f_size < 20);
    ofstream file;
    file.open("JobShop2.txt");
    for(int i = 0 ; i  < 20 ; ++i){
        file << finished.at(i).toString();
    }
    file.close();
    return 0;
}