#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double binomial_option_price(double S, double K, double T, double r, double vol, int n) {
    double dt = T / n;
    double u = exp(vol * sqrt(dt));
    double d = 1 / u;
    double p = (exp(r * dt) - d) / (u - d);
    double option_values[n + 1];
    //Calculating Option Values at Expiration
    for (int i = 0; i <= n; i++)
        /*i represents the number of "up" moves the stock price
         has taken during the n steps. Therefore, i will range from 0 to n.*/
        {
        option_values[i] = max(0.0, S * pow(u, i) * pow(d, n - i) - K);
        /*calculates the stock price at the expiration date for a specific path.
         S * pow(u, i) * pow(d, n - i) - K: This calculates the intrinsic value */
    }
// Backward Induction
    /*This set of nested loops performs backward induction to calculate the option value at each node
     *of the binomial tree, working backward from the expiration date to the present.

for (int i = 0; i <= j; i++): This inner loop iterates over the possible states at each time step j. i represents the number of up moves at time step j. Importantly, the maximum value of i is j, because you can't have more up moves than the number of time steps that have elapsed.
option_values[i] = (p * option_values[i + 1] + (1 - p) * option_values[i]) * exp(-r * dt);: This is the core of the backward induction process. It calculates the option value at a given node (time step j, state i) as the discounted expected value of the option in the next time step:*/
    for (int j = n - 1; j >= 0; j--) /*loop iterates backward in time, from the time step
        just before expiration (n - 1) down to time 0.
        j represents the time step.*/
        {
        for (int i = 0; i <= j; i++) {
            option_values[i] = (p * option_values[i + 1] + (1 - p) * option_values[i]) * exp(-r * dt);
        }
    }

    return option_values[0];
}
double black_scholes_call_price(double S, double K, double T, double r, double vol) {
    double d1 = (log(S / K) + (r + 0.5 * vol * vol) * T) / (vol * sqrt(T));
    double d2 = d1 - vol * sqrt(T);
    double N_d1 = 0.5 * (1 + erf(d1 / sqrt(2))); // Cumulative standard normal distribution function for d1
    double N_d2 = 0.5 * (1 + erf(d2 / sqrt(2))); // Cumulative standard normal distribution function for d2
    double call_price = S * N_d1 - K * exp(-r * T) * N_d2;
    return call_price;
}

int main() {
    double S = 227.63;
    double K = 227.63;
    double T = 1;
    double r = 0.045;
    double vol = 0.2303;
    int n = 100;

    double option_price = binomial_option_price(S, K, T, r, vol, n);

    cout << fixed << setprecision(4);
    cout << "European Call Option Price (Binomial): $" << option_price << endl;

    double call_price = black_scholes_call_price(S, K, T, r, vol);

    cout << fixed << setprecision(4);
    cout << "European Call Option Price (Black-Scholes): $" << call_price << endl;

    return 0;
}
