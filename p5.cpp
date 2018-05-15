#include <iostream>
#include <cmath>
#include <list>
#include <algorithm>
using namespace std;

list <int> requests; //2055, 1175, 2304, 2700, 513, 1680, 256, 1401, 4922, 3692
int start_position = 2255;

void initialize_list(){
    requests.push_back(2055);
    requests.push_back(1175);
    requests.push_back(2304);
    requests.push_back(2700);
    requests.push_back(513);
    requests.push_back(1680);
    requests.push_back(256);
    requests.push_back(1401);
    requests.push_back(4922);
    requests.push_back(3692);
}

//first come first serve
void FCFS()
{
    initialize_list();
    
    int total_dist = 0;
    int curr = start_position;
    int prev = start_position;

    while(!requests.empty()) {
        curr = requests.front();
        requests.pop_front();
        total_dist += abs(prev - curr);
        prev = curr;
    }
    cout << "total distance for FCFS: " << total_dist << endl;
}

//find the next element with the shortest distance with e
int element_shortest_distance(int e)
{
    int max = requests.front();
    int min_dist = abs(e - max);
    for(list<int>::iterator it = requests.begin(); it != requests.end(); ++it){
        if(abs(e - *it) < min_dist) {
            min_dist = abs(e - *it);
            max = *it;
        }
    }
    return max;
}

//sort by shortest distance apart
void SSTF()
{
    initialize_list();
    
    int total_dist = 0;
    int curr = start_position;
    int prev = start_position;
    
    int min_dist_element = 0;
    
    while (!requests.empty()) {
        min_dist_element = element_shortest_distance(curr);
        curr = min_dist_element;
        requests.remove(curr);
        total_dist += abs(prev - curr);
        prev = curr;
    }
    cout << "total distance for FCFS: " << total_dist << endl;
}

void SCAN()
{
    
}

void CSCAN()
{
    
}

void LOOK()
{
    
}

void CLOOK()
{
    
}


int main()
{
    cout<< "FCFS" << endl;
    cout << "********************" << endl;
    FCFS();
    
    cout << "SSTF" << endl;
    cout << "********************" << endl;
    SSTF();
    
    cout << "SCAN" <<endl;
    cout << "********************" << endl;
    SCAN();
    
    cout << "LOOK" << endl;
    cout << "********************" << endl;
    LOOK();
    
    cout << "CSCAN" << endl;
    cout << "********************" << endl;
    CSCAN();
    
    cout << "CLOOK" << endl;
    cout << "********************" << endl;
    CLOOK();
    
    return 0;
}

