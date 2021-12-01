#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int fullPopulation = 8200000, pop, activeCasesBefore = 6926, currActive, totalRecovered, day = 1, b, x, recoverTotal = 0, constDayMax = 52;
float vaccinationRate = 0.735, vaxRateIncRate = 0.0051;

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int recoveryArr[] = {788, 866, 943, 866, 814, 668, 623, 608, 594, 587, 648, 581, 479, 498};



    cout << "Results (Modelled Table):"<< endl;

    cout << "--------------------------------------------------------------------\n";
    cout << setw(5) << "Day" << setw(20) << "Active Infections:" << setw(20) << "New Cases" << setw(20) << "Total Recovered:" << endl;
    cout << "--------------------------------------------------------------------\n";

    currActive = activeCasesBefore;
    int low_dist  = 7;
    int high_dist = 50;
    time_t t;
    srand( ( unsigned int ) time(&t) );

         while (day < constDayMax) {
             high_dist = round(0.2 * recoveryArr[13]);

             for (int repetition = 0; repetition < 10; ++repetition) {
                 x = low_dist + rand() % (high_dist - low_dist);
             }

             if (rand() % 8 > 4) x = x * -1;
             if (rand() % 6 > 4) x = 0;

             currActive -= 5 * recoveryArr[0] / 6;
             recoverTotal += 5 * recoveryArr[0] / 6;
             pop = round(fullPopulation * vaccinationRate);
             b = round((recoveryArr[13] * 0.92) + x); // x is random number for random variation
             currActive += b;

             cout << setw(5) << day << setw(20) << currActive << setw(20) << b << setw(20) << recoverTotal << endl;

             day++;
             for (int i = 0; i < 14; i++) {
                 recoveryArr[i] = recoveryArr[i + 1];
             }
             recoveryArr[13] = b;
             vaccinationRate = vaccinationRate + vaxRateIncRate;
         }
     cout << "--------------------------------------------------------------------";

    return 0;
}