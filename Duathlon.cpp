#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

const double EPS = 1e-9;
const int SECPERHOUR = 3600;

struct Racer {
	double running, bicycle;
	double time(double r, double t) {
		double k = t - r;
		return (r / running + k / bicycle) * SECPERHOUR;
	}
};

double margin(double r, double t, vector<Racer> racers, Racer c) {
	double c_time = c.time(r, t);
	double mintime = 1e18;
	for (int i = 0; i < racers.size(); i++) {
		mintime = min(mintime, racers[i].time(r,t));
	}
	return mintime - c_time;
}

int main(){
	double t;
	while (cin >> t){
		int n;
		cin >> n;
		vector<Racer> contest (n-1);
		for (int i = 0; i < n - 1; i++) {
			cin >> contest[i].running >> contest[i].bicycle;
		}
		Racer cheater;
		cin >> cheater.running >> cheater.bicycle;
		double best_margin = -1e18, best_r = 0.0;
		for (double r = 0.0; r <= t; r += 1e-3) {
			double m = margin(r, t, contest, cheater);
			if (m > best_margin + EPS) {
				best_margin = m;
				best_r = r;
			}
		}
		if (best_margin <= 0.0) {
			cout << "The cheater cannot win win" << endl;
		}
		else {
			double best_k = t - best_r;
			cout << fixed << setprecision(2);
			cout << "The cheater can win by " << (int)(best_margin + 0.5)
				<< " seconds with r = " << best_r << "km and k = " << best_k << "km.\n";
		}
	}
}
