#include<string>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
using namespace std;



struct algos
{
private:
  string flowers[6] = {"Rose","Sunflower" , "Lily" , "Tulip" , "Wither" , "Popy"};
  int stock[6] = {50,50,50,50,50,50}; // Every place contains amount of flowers
  int order[6] = {0,0,0,0,0,0}; // To take input of evry orde
  public:
    int coins =0 , score =0;
    algos()
    {
      srand(time(0));
    }
    int random(int max , int min ); /*TO generate a random number which ensures the randomness
                        of buyers coming to buy plants from the shop*/
    bool order_check(); //To check if shopkeeper has the order in stock and perform it
    void assign_random(); // To randomize the order of the customer
    void order_refresh();// to referesh the order
    void input_data(); // to take input of data
    void output_data(); //to take output of data
};
