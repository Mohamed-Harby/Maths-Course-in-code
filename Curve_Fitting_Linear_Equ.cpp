#include<iostream>
#include<vector>
#include<iomanip>
#include<math.h>
using namespace std;

vector<pair<double,double>>points;
void printLinearForm(double a,double b){
        cout << fixed << setprecision(3)<< "The approximate linear equation is: " << a <<"*x ";
        if(b == 0) {cout << endl; return;}
         cout << '+'<< '('<< b << ')'<< endl;
}
void geterror(double a, double b){
    double sumDsq = 0;
    for(int i=0;i<points.size();i++){
        sumDsq += pow(points[i].second - (  a*points[i].first + b) ,2);        // Dsq += (Y - Yapp)^2
    }
    double error = sqrt(sumDsq/(double)points.size());
    cout << "The root mean square of the error (RMSE) is:\n";

    cout << fixed << setprecision(6) << error << endl;
    if(error > 1) cout << "The error is big,try fitting these values with another curve!!\n";
}
int main(){
    double n,x,y;
    cin>>n;          
    points = vector<pair<double,double>>(n);
    
    double sumX = 0,sumY = 0,sumXY= 0,sumXsq = 0;
    
    for(int i=0;i<n;i++) {
        cin >> x >> y;
        points[i].first = x, points[i].second = y;
        
        sumX += x,sumY += y,sumXY += x*y,sumXsq += x*x;
    }

    double a = (sumY*sumX - sumXY*n) / (sumX*sumX - n*sumXsq);
    double b = (sumY - a*sumX)/n;

    printLinearForm(a,b);
    geterror(a,b);
}   
