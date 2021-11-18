#include <iostream>
using namespace std;

int ppl, c0, r0, contagiousDays, recoveryDay;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    cin >> ppl >> c0 >> r0 >> contagiousDays >> recoveryDay;

    int day = 1;
    int pplNotHadCovid = ppl-c0;
    int totalCases = c0;
    int prevCatch = c0;
    int fooCatch = c0;
    int totalRecovered = 0;

    cout << "Day: | Active Total COVID Cases: | Total Recovered: | Population never had COVID: \n";

    while (pplNotHadCovid > 0) {
        if ((day-1) % recoveryDay == 0 && day != 1) {
            totalCases = totalCases - prevCatch;
            totalRecovered = prevCatch;
        }
        if ((day-1) % (contagiousDays-1) == 0 && day != 1) {
            fooCatch = fooCatch * r0;
            totalCases = totalCases + fooCatch;
            pplNotHadCovid = pplNotHadCovid - totalCases;
        }
        cout << day << " " << totalCases << " " << totalRecovered << " " << pplNotHadCovid << "\n";
        day++;
    }

    return 0;
}