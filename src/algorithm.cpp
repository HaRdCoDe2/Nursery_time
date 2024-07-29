// Jai Bajarangbali
#include"algorithm.hpp"



int algos::random(int max , int min )
      {
        return rand()%max + min ;
      }


void algos::assign_random()
{
  for( int i=0 ; i<6 ; i++)
  {
    order[i] = random(10 , 0);
  }
}



bool algos::order_check()
{
  for (int i =0 ; i<6 ; i++)
  {
    if(order[i] > stock[i])
    {
      return false;
    }

  }

  for(int i=0 ; i<6 ; i++)
  {
    stock[i] -= order[i];
      coins+=order[i]*(i*10+50);
      cout<<"Flower:"<<flowers[i]<<" | Ordered :"<<order[i]<<" | Price:"<<i*100+50<<" | Total:"<<order[i]*(i*100+50)<<"\n";
  }
  //cout<<"order is done "<<endl;
  return true;
}


void algos::order_refresh()
{
  //cout<<"If it is orde referesh"<<endl;
  for(int i=0 ; i<6 ; i++)// I am scared cause i am doing it all in static not dynamic , every value (T T)!
  {
    order[i]=0;
  }
  //cout<<"No fault in order_referesh"<<endl;
}

void algos::input_data()
{
  ifstream file("data/data.txt");

  if(file.is_open())
  {
    file >> coins;
    file.close();
    cout<<"Number readed into coins"<<endl;
  }
  else{
    cout<<"Cannot read numbers "<<endl;
  }
}

void algos::output_data()
{
  ofstream file("data/data.txt");

  if(file.is_open())
  {
    file << coins;
    file.close();
    cout<<"coins printed into number"<<endl;
  }
  else{
    cout<<"Cannot print numbers "<<endl;
  }
}
