

class UndergroundSystem {
private:
    map<pair<string, string>, pair<double, int>> avg;
    map<int, pair<string, int>> customer;
public:
    UndergroundSystem() {
        avg.clear();
        customer.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        customer[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string, int> temp = customer[id];
        customer[id] = {"", 0};
        pair<double, int> x =  avg[{temp.first, stationName}];
    
        
        x.first += (t - temp.second);
        x.second++;

        avg[{temp.first, stationName}] = x;
      
       
    }
    
    double getAverageTime(string startStation, string endStation) {
        pair<double, int> p = avg[{startStation, endStation}];
        return p.first / p.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */