#include <iostream>
#include <iomanip>
using namespace std;

float ppl, c0, r0;
int contagiousDays, recoveryDay;

float newCases[1000000];

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    cin >> ppl >> c0 >> r0 >> contagiousDays >> recoveryDay;

    int day = 1;
    float pplNotHadCovid = ppl-c0;
    float totalCases = c0;
    float prevCatch = c0;
    float fooCatch = c0;
    float totalRecovered = 0;
    int actrecoveryDay = contagiousDays-1;
    int recoveryDayCount = 1;
    int contagiousDayCount = 1;
    cout << "----------------------------------------------------------------------------------------------------------------" << endl;

    cout << "   ___ _____   _____ ___      _ ___   __  __        _     _ _ _             ___                             \n"
            "  / __/ _ \\ \\ / |_ _|   \\ ___/ / _ \\ |  \\/  |___ __| |___| | (_)_ _  __ _  | _ \\_ _ ___ __ _ _ _ __ _ _ __  \n"
            " | (_| (_) \\ V / | || |) |___| \\_, / | |\\/| / _ / _` / -_| | | | ' \\/ _` | |  _| '_/ _ / _` | '_/ _` | '  \\ \n"
            "  \\___\\___/ \\_/ |___|___/    |_|/_/  |_|  |_\\___\\__,_\\___|_|_|_|_||_\\__, | |_| |_| \\___\\__, |_| \\__,_|_|_|_|\n"
            "                                                                    |___/              |___/                \n";

    cout << "  By Joshua Koh" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------" << endl;

    cout << endl;

    cout << "Input: " << endl;

    cout << endl;

    cout << "Population: " << ppl << endl;
    cout << "Population Infected on Day 1: " << c0 << endl;
    cout << "r0 Number: " << r0 << endl;
    cout << "Day in Cycle for Spreading Virus :" << contagiousDays << endl;
    cout << "Day in Cycle for Recovery: " << recoveryDay << endl;

    cout << endl;
    cout << endl;

    cout << "Results (Modelled Table):"<< endl;

    cout << "----------------------------------------------------------------------------------------------------------------\n";
    cout << setw(5) << "Day" << setw(20) << "Active Infections:" << setw(20) << "Total Recovered:" << setw(35) << "Total Recovered + Infections:" << setw(30) << "Never Infected Population:" << endl;
    cout << "----------------------------------------------------------------------------------------------------------------\n";

    while (pplNotHadCovid > 0 || totalCases > 0) {
        if ((day-1-recoveryDay) % actrecoveryDay == 0 && day >= recoveryDay) {
            totalCases = totalCases - prevCatch;
            totalRecovered = totalRecovered + prevCatch;
            prevCatch = newCases[recoveryDayCount];
            recoveryDayCount++;
        }
        if ((day-1) % (contagiousDays-1) == 0 && day != 1) {
            fooCatch = fooCatch * r0;
            totalCases = totalCases + fooCatch;
            if(totalCases > ppl-totalRecovered) {
                totalCases = ppl - totalRecovered;
                pplNotHadCovid = 0;
            } else pplNotHadCovid = pplNotHadCovid - fooCatch;
            newCases[contagiousDayCount] = fooCatch;
            contagiousDayCount++;
        }
        if(totalCases < 0) totalCases = 0;
        if(totalRecovered > ppl) totalRecovered = ppl;
        cout << setw(5) << day << setw(20) << totalCases << setw(20) << totalRecovered << setw(35)<< totalRecovered+totalCases << setw(30) << pplNotHadCovid << endl;
        day++;
    }
    cout << endl;
    cout << "Days Until Fully Recovered Population: " << day << endl;
    cout << "----------------------------------------------------------------------------------------------------------------\n";

    return 0;
}