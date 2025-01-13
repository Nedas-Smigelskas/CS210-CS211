#include <iostream>
#include <cmath>
using namespace std;

long double e_estimate(int trials){
    double sum = 0.0;
    for (int i = 0; i <= trials; i++) {
        double x = 0.0;
        int count = 0;
        while (x < 1.0) {
            x += (double)(rand()) / RAND_MAX;
            count++;
        }
        sum += count;
    }
    long double ee = sum / trials;
    return ee;
}

long double pi_estimate(int trials){
    double x,y;
    int pointsincircle = 0;

    for(int i = 0; i <= trials; i++){
        x = double(rand())/RAND_MAX;
        y = double(rand())/RAND_MAX;
        if(x*x+y*y <= 1){
            pointsincircle++;
        }
    }

    return (4.0*pointsincircle/trials);

}

int main() {
    int trials;
    cout << "Enter number of trials : ";
    cin >> trials;
    double e = e_estimate(trials);
    double pi = pi_estimate(trials);

    cout << "Eulers number prediction is : " << fixed << e << endl;
    cout << "Eulers absolute error is : " << fixed << abs(e-exp(1)) << endl;
    cout << "Pi's number prediction is : " << fixed << pi_estimate(trials) << endl;
    cout << "Pi's absolute error is : " << fixed << abs(pi-3.1415926535) << endl;
    return 0;
}
