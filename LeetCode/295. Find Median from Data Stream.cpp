class MedianFinder {
    priority_queue<int,vector<int>, greater<int>> small_half_pq;     //홀수 일때는 얘가 항상 1개 더 많도록
    priority_queue<int, vector<int>, less<int>> large_half_pq;
    int all_size = 0;

public:
    MedianFinder() : all_size(0) {}

    void addNum(const int num) {
        if (all_size % 2 == 0) {    //지금 짝수이 경우
            large_half_pq.push(num);
            small_half_pq.push(large_half_pq.top());
            large_half_pq.pop();
        }
        else {   //홀수인 경우
            small_half_pq.push(num);
            large_half_pq.push(small_half_pq.top());
            small_half_pq.pop();
        }

        ++all_size;
    }

    double findMedian() {
        if (all_size == 1) 
            return small_half_pq.top();

        if(all_size %2 ==0)
            return (double)(large_half_pq.top() + small_half_pq.top()) / 2.0l;

        return (double)small_half_pq.top();
    }
};
