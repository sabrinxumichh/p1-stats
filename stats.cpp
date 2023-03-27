//'Project UID 5366c7e2b77742d5b2142097e51561a5'
#include <vector>
#include "stats.h"
#include "p1_library.h"
#include <cmath>
using namespace std;

vector<pair<double, int> > summarize(vector<double> v){
    int count = 1;
    vector<pair<double, int>> vp;
    sort(v);
    
    for (size_t i = 0; i < v.size(); i++) {
        if (i < v.size()-1 && v[i] == v[i+1]) {
            count++;
        } else {
            vp.push_back({v[i], count});
            count = 1;
        }
    }
    return vp;
}

int count(vector<double> v){
    return v.size();
}

double sum(vector<double> v){
    double sum = 0.0;
    for(size_t i = 0; i < v.size(); i++){
        sum+=v[i];
    }
    return sum;
}

double mean(vector<double> v){
    return (sum(v)/count(v));
}

double median(vector<double> v){
    sort(v);
    int halfIndex = v.size() / 2;

    if(v.size() % 2 == 1){
        return v[halfIndex];
    }
    else{
        return ((v[halfIndex] + v[halfIndex + 1]) / 2);
    }
}

double mode(vector<double> v){
    vector<pair<double, int>> vp = summarize(v);
    double mode = vp[0].first;
    int maxFreq = vp[0].second;
    for(size_t i = 1; i < v.size(); i++){
        if(vp[i].second > maxFreq){
            mode = vp[i].first;
            maxFreq = vp[i].second;
        }
        else if(vp[i].second == maxFreq)
        {
            if(vp[i].first < mode){
                mode = vp[i].first;
            }
        }
    }
    return mode;
}

double min(vector<double> v){
    int min;
    for(size_t i = 0; i < v.size(); i++){
        min = v[0];
        if(v[i] < min){
            min = v[i];
        }
    }
    return min;
}

double max(vector<double> v){
    int max;
    for(size_t i = 0; i < v.size(); i++){
        max = v[0];
        if(v[i] > max){
            max = v[i];
        }
    }
    return max;
}

double stdev(vector<double> v){
    double dev = 0;
    double stDev = 0;
    vector<double> devs;
   
    for(size_t i = 0; i < v.size(); i++){
        dev = v[i] - mean(v);
        dev = dev * dev;
        devs.push_back({dev});
    }

    double sum = 0;
    for(size_t j = 0; j < devs.size(); j++){
        sum+=devs[j];
    }

    stDev = sum / (v.size() - 1);

    return sqrt(stDev);
}

double percentile(vector<double> v, double p){
    sort(v);
    
    if(p == 1){
        return max(v);
    }

    double rank = 0;
    rank = p * (count(v) - 1) + 1;

    double intpart;
    double fractpart;
    fractpart = modf(rank, &intpart);

    double percentile = 0;
    percentile = v[intpart - 1] + fractpart * (v[intpart] - v[intpart - 1]);

    return percentile;
}


