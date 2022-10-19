#include <iostream>
#include <cstdlib>
#include <cmath>
 using namespace std;

typedef struct 
{
    double x[50];double x_r[50];double P_r[50];double Q;double R;double K[50];char z[50];double P[50];
} KalmanInfo;
  KalmanInfo kalman_Structure;

void Generating_Random_Measurement()
{
    char i;
    for (i = 0; i < 50; i++)
    {
        kalman_Structure.z[i] = 47+rand() %6;
    }
    

}

void Kalman_Parameter_Init()
{   
    kalman_Structure.x[0] = 45;
    kalman_Structure.Q = 0.002;
    kalman_Structure.R = 0.05;
    kalman_Structure.P[0] = 0.008;
}

  
void Final_Calculation()
{
      char i;
      for (i = 1;i < 50; i++)
      {
      kalman_Structure.x_r[i] = kalman_Structure.x[i-1];
      kalman_Structure.P_r[i] = kalman_Structure.P[i-1] + kalman_Structure.Q;
      kalman_Structure.K[i] = kalman_Structure.P_r[i]/(kalman_Structure.P_r[i]+kalman_Structure.R);
      kalman_Structure.x[i] = kalman_Structure.x_r[i]+kalman_Structure.K[i]*(kalman_Structure.z[i] - kalman_Structure.x_r[i]);
      kalman_Structure.P[i]= (1-kalman_Structure.K[i])*kalman_Structure.P_r[i];
      cout<<"kalman_Structure.x_r[i]"<<kalman_Structure.x_r[i]<<endl;
      cout<<"kalman_Structure.P_r[i]"<<kalman_Structure.P_r[i]<<endl;
      cout<<"kalman_Structure.K[i]"<<kalman_Structure.K[i]<<endl;
      cout<<"kalman_Structure.x[i]"<<kalman_Structure.x[i]<<endl;
      cout<<"kalman_Structure.P[i]"<<kalman_Structure.P[i]<<endl;
      }
}

int main()
{
    cout<<"output"<<endl;
    Generating_Random_Measurement();
    Kalman_Parameter_Init();
    Final_Calculation();
    return 0;
}