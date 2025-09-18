#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <numeric>

using namespace std;

//pair<double, double>

pair <double, double> LinearRegressionFit(vector<double> x, vector<double> y) {
    double totalX = accumulate(x.begin(), x.end(), 0.0);
    double totalY = accumulate(y.begin(), y.end(), 0.0);

    vector<double> xSquared = x;
    for (double &x1 : xSquared) {
        x1 *= x1;
    }
    double sumxSquared = accumulate(xSquared.begin(), xSquared.end(), 0.0);

    vector<double> xy;
    for (int i = 0; i < x.size(); i++) {
        xy.push_back(x[i] * y[i]);
    }

    double sumxy = accumulate(xy.begin(), xy.end(), 0.0);
    double m = ((x.size() * sumxy) - (totalX * totalY)) / ((x.size() * sumxSquared) - (totalX * totalX));
    double c = ((totalY * sumxSquared) - (totalX * sumxy)) / ((x.size() * sumxSquared) - (totalX * totalX));

    return make_pair(m, c);
}

double LinearRegressionPredict(double m, double c, double x) {
    double y = (m * x) + c;
    return y;
}

int main() {
    
    pair<double, double> coefficients =  LinearRegressionFit({3, 9, 5, 3}, {8, 6, 4, 2});

    cout << LinearRegressionPredict(coefficients.first, coefficients.second, 2.5);

    return 0;
}
