/*
 * Description: Disk Algo: FCFS, SSTF, SCAN, CSCAN, LOOK, CLOOK
 * Author: Tracy Sun
 */

#include <iostream>
#include <cmath>
#include <list>
#include <algorithm>
using namespace std;

list <int> requests; //2055, 1175, 2304, 2700, 513, 1680, 256, 1401, 4922, 3692
int start_position = 2255;
int track_start = 0;
int track_end = 4999;

//insert values into list
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
        cout << "prev: " << prev << endl;
        cout << "next: "<< curr << endl;
        requests.pop_front();
        total_dist += abs(prev - curr);
        cout << abs(prev - curr) <<endl;
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
        cout << "prev: " << prev << endl;
        cout << "next: "<< curr << endl;
        requests.remove(curr);
        total_dist += abs(prev - curr);
        cout << abs(prev - curr) <<endl;
        prev = curr;
    }
    cout << "total distance for SSTF: " << total_dist << endl;
}

//find next larger or equal element of e for SCAN
int find_next_large(int e)
{
    for (list<int>::iterator it = requests.begin(); it != requests.end(); ++it) {
        if(*it >= e){
            return *it;
        }
    }
    return -1;
}

// elevator approach move to the end of the track
void SCAN()
{
    initialize_list();
    
    int total_dist = 0;
    int curr = start_position;
    int prev = start_position;
    
    //sort by increasing order
    requests.sort();
    
    while (1) {
        curr = find_next_large(curr);
        //no more next large element
        if(curr == -1){
            curr = track_end;
            cout << "prev: " << prev << endl;
            cout << "next: "<< curr << endl;
            total_dist += abs(prev - curr);
            cout << abs(prev - curr) <<endl;
            prev = curr;
            break;
        }
        cout << "prev: " << prev << endl;
        cout << "next: "<< curr << endl;
        requests.remove(curr);
        total_dist += abs(prev - curr);
        cout << abs(prev - curr) <<endl;
        prev = curr;
    }
    
    //reverse the order
    requests.reverse();
    for(list<int>::iterator it = requests.begin(); it != requests.end(); ++it){
        curr = *it;
        cout << "prev: " << prev << endl;
        cout << "next: "<< curr << endl;
        requests.pop_front();
        total_dist += abs(prev - curr);
        cout << abs(prev - curr) <<endl;
        prev = curr;
    }
    
    cout << "total distance for SCAN: " << total_dist << endl;
}

// similar to SCAN
void CSCAN()
{
    initialize_list();
    
    int total_dist = 0;
    int curr = start_position;
    int prev = start_position;
    
    //sort by increasing order
    requests.sort();
    
    while (1) {
        curr = find_next_large(curr);
        //no more next large element... go to the start of the track
        if(curr == -1){
            prev = track_start;
            break;
        }
        cout << "prev: " << prev << endl;
        cout << "next: "<< curr << endl;
        requests.remove(curr);
        total_dist += abs(prev - curr);
        cout << abs(prev - curr) <<endl;
        prev = curr;
    }
    
    for(list<int>::iterator it = requests.begin(); it != requests.end(); ++it){
        curr = *it;
        cout << "prev: " << prev << endl;
        cout << "next: "<< curr << endl;
        requests.pop_front();
        total_dist += abs(prev - curr);
        cout << abs(prev - curr) <<endl;
        prev = curr;
    }
    
    cout << "total distance for CSCAN: " << total_dist << endl;
}


void LOOK()
{
    initialize_list();
    
    int total_dist = 0;
    int curr = start_position;
    int prev = start_position;
    
    //sort by increasing order
    requests.sort();
    
    while (1) {
        curr = find_next_large(curr);
        //no more next large element
        if(curr == -1){
            break;
        }
        cout << "prev: " << prev << endl;
        cout << "next: "<< curr << endl;
        requests.remove(curr);
        total_dist += abs(prev - curr);
        cout << abs(prev - curr) <<endl;
        prev = curr;
    }
    
    //reverse the order
    requests.reverse();
    for(list<int>::iterator it = requests.begin(); it != requests.end(); ++it){
        curr = *it;
        cout << "prev: " << prev << endl;
        cout << "next: "<< curr << endl;
        requests.pop_front();
        total_dist += abs(prev - curr);
        cout << abs(prev - curr) <<endl;
        prev = curr;
    }
    
    cout << "total distance for LOOK: " << total_dist << endl;
}

void CLOOK()
{
    initialize_list();
    
    int total_dist = 0;
    int curr = start_position;
    int prev = start_position;
    
    //sort by increasing order
    requests.sort();
    
    while (1) {
        curr = find_next_large(curr);
        //no more next large element... go to the start of the track
        if(curr == -1){
            //prev = track_start;
            break;
        }
        cout << "prev: " << prev << endl;
        cout << "next: "<< curr << endl;
        requests.remove(curr);
        total_dist += abs(prev - curr);
        cout << abs(prev - curr) <<endl;
        prev = curr;
    }
    
    for(list<int>::iterator it = requests.begin(); it != requests.end(); ++it){
        curr = *it;
        cout << "prev: " << prev << endl;
        cout << "next: "<< curr << endl;
        requests.pop_front();
        total_dist += abs(prev - curr);
        cout << abs(prev - curr) <<endl;
        prev = curr;
    }
    
    cout << "total distance for CLOOK: " << total_dist << endl;
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
    
    cout << "CSCAN" << endl;
    cout << "********************" << endl;
    CSCAN();
    
    cout << "LOOK" << endl;
    cout << "********************" << endl;
    LOOK();
    
    cout << "CLOOK" << endl;
    cout << "********************" << endl;
    CLOOK();
    
    return 0;
}

