class StockSpanner {
public:
    stack<pair<int, int>> s;
    int step = 1;
    StockSpanner() {
        s.push({INT_MAX, 0});
    }

    int next(int price) {
        //int     // pair(must be compared by an int)
        while (price >= s.top().first) {
            s.pop();
        }

        int diff = step - s.top().second;
        s.push({price, step});
        step++;

        return diff;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */