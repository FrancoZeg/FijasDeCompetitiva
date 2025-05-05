#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

const double EPS = 1e-9;
const int SECONDS_PER_HOUR = 3600;

struct Racer {
    double run_speed;
    double cycle_speed;

    double time(double r, double t) const {
        double k = t - r;
        return (r / run_speed + k / cycle_speed) * SECONDS_PER_HOUR;
    }
};

double margin(double r, double t, const Racer& cheater, const vector<Racer>& others) {
    double cheater_time = cheater.time(r, t);
    double min_other_time = 1e18;
    for (const Racer& r2 : others) {
        min_other_time = min(min_other_time, r2.time(r, t));
    }
    return min_other_time - cheater_time;
}

int main() {
    double t;
    while (cin >> t) {
        int n;
        cin >> n;
        vector<Racer> others(n-1);
        for (int i = 0; i < n-1; ++i) {
            cin >> others[i].run_speed >> others[i].cycle_speed;
        }

        Racer cheater;
        cin >> cheater.run_speed >> cheater.cycle_speed;

        double left = 0.0, right = t;
        double best_r = 0.0, best_margin = -1e18;

        for (double r = left; r <= right; r += 1e-3) {
            double m = margin(r, t, cheater, others);
            if (m > best_margin + EPS) {
                best_margin = m;
                best_r = r;
            }
        }

        if (best_margin <= 0) {
            cout << "The cheater cannot win.\n";
        }
        else {
            double best_k = t - best_r;
            cout << fixed << setprecision(2);
            cout << "The cheater can win by " << (int)(best_margin + 0.5)
                << " seconds with r = " << best_r << "km and k = " << best_k << "km.\n";
        }
    }

    return 0;
}
