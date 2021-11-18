#include <iostream>
using namespace std;

int ppl, c0, r0, contagiousDays, recoveryDay;

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> ppl >> c0 >> r0 >> contagiousDays, recoveryDay;

    int day = 1;
    int pplNotHadCovid = ppl;
    int totalCases = c0;
    int prevCatch = c0;
    int totalRecovered = 0;

    cout << "Day: | Active Total COVID Cases: | Total Recovered: | Population never had COVID: ";

    while (pplNotHadCovid > 0) {
        if (day % recoveryDay == 0) {
            totalCases = totalCases - prevCatch;
            totalRecovered = prevCatch;
        }
        if (day % contagiousDays == 0) {
            totalCases = totalCases + (totalCases * r0);
            prevCatch = totalCases;
            pplNotHadCovid = pplNotHadCovid - totalCases;
        }
        cout << day << totalCases << totalRecovered << pplNotHadCovid << "\n";
        day++;
    }

    return 0;
}