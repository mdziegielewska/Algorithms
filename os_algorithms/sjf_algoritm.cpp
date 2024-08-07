// Dzi�gielewska Marta
// SJF algorithm
// 01.04.2021

#include <iostream>
#include <cstdlib>
using namespace std;

// struktura dla ka�dego procesu
struct Process {
    int p_id; // id procesu
    int p_bt; // czas potrzebny do wykonania
    int p_at; // czas nadej�cia procesu do systemu
};

// funkcja znajduj�ca czas zako�czenia procesu
void turnaround_time(Process p[], int number_of_processes, int wt[], int tat[]) {
    // do czasu wykonania dodajemy czas oczekiwania
    for (int i=0; i<number_of_processes; i++) {
        tat[i] = p[i].p_bt + wt[i];
    }
}

// funkcja znajduj�ca czas oczekiwania na rozpocz�cie procesu
void waiting_time(Process p[], int number_of_processes, int wt[]) {
    int bt[number_of_processes];
    // przekopiowujemy czas trwania procesu ze struktury do tablicy
    for (int i=0; i<number_of_processes; i++) {
        bt[i] = p[i].p_bt;
    }

    int complete = 0;
    int t = 0;
    int minimum = INT_MAX;
    int shortest = 0;
    int finish_time;
    bool check = false;

    // wykonujemy, a� do zako�czenia wszystkich proces�w
    while (complete != number_of_processes) {
        // szukamy procesu z tych, kt�re pozosta�y, z najkr�tszym czasem wykonania
        for (int i=0; i<number_of_processes; i++) {
            if ((p[i].p_at <= t) && (bt[i] < minimum) && (bt[i] > 0)) {
                minimum = bt[i];
                shortest = i;
                check = true;
            }
        }
        if (check == false) {
            t++;
            continue;
        }

        // zmniejszamy czas do zako�czenia wszystkich proces�w
        bt[shortest]--;

        // aktualizujemy nasze minimum
        minimum = bt[shortest];
        if (minimum == 0) {
            minimum = INT_MAX;
        }

        if (bt[shortest] == 0) {
            complete++;
            check = false;

            // znajdujemy czas zako�czenia aktualnego procesu
            finish_time = t + 1;

            // wyliczamy czas oczekiwania
            wt[shortest] = finish_time - p[shortest].p_bt - p[shortest].p_at;
            if (wt[shortest] < 0) {
                wt[shortest] = 0;
            }
         }

         // zwi�kszamy czas
         t++;
   }
}
// funkcja znajduj�ca �redni czas oczekiwania oraz zako��zenia proces�w
void sjf_algorithm(Process p[], int number_of_processes) {
    int wt[number_of_processes];
    int tat[number_of_processes];
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    // wywo�ujemy funkcj� znajduj�c� czas oczekiwania dla wszystkich proces�w
    waiting_time(p, number_of_processes, wt);

    // wywo�ujemy funkcj� zajduj�c� czas zako�czenia dla wszystkich proces�w
    turnaround_time(p, number_of_processes, wt, tat);

    cout << "Process: \t"<< "Burst time: \t" << "Waiting time: \t" << "Turnaround time: " << endl;

    // obliczamy �redni czas oczekiwania i zako�czenia procesu
    for (int i=0; i<number_of_processes; i++){
        total_waiting_time = total_waiting_time + wt[i];
        total_turnaround_time = total_turnaround_time + tat[i];
    }

    double average_wt = total_waiting_time/number_of_processes;
    double average_tat = total_turnaround_time/number_of_processes;

    // wy�wietlamy informacje o ka�dym procesie
    for (int i=0; i<number_of_processes; i++) {
        cout << "P" << p[i].p_id << "\t\t" << p[i].p_bt << "\t\t" << wt[i] << "\t\t" << tat[i] <<endl;
    }

    cout << endl;
    cout << "Average waiting time: " << average_wt << endl;
    cout << "Average turnaround time: " << average_tat << endl;
}

int main() {
    int number_of_processes = 30;
    int N = 60;
    int M = 30;
    Process p[number_of_processes];

    for (int i=0; i<number_of_processes; i++) {
        p[i].p_id = i+1;
        // lodowa d�ugo�� czasu wykonania i dotarcia procesu do systemu
        int a = rand() % N + 1;
        p[i].p_bt = a;
        int b = rand() % M + 1;
        p[i].p_at = b;
    }

    sjf_algorithm(p, number_of_processes);
    return 0;
}
