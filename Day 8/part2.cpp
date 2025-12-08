#include <bits/stdc++.h>

using namespace std;


struct Point {
    long x = 0, y = 0, z = 0;
};

vector<Point> junction_boxes;
vector<int> parent;
vector<int> sizes;

void make_set(int v) {
    parent[v] = v;
    sizes[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sizes[a] < sizes[b])
            swap(a, b);
        parent[b] = a;
        sizes[a] += sizes[b];
    }

}

long long sqr_dist(const Point& a, const Point& b) {
    long dx = a.x - b.x;
    long dy = a.y - b.y;
    long dz = a.z - b.z;
    return 1LL*dx*dx + 1LL*dy*dy + 1LL*dz*dz;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;

    while(cin >> s){
        Point point;
        stringstream coords(s);
        string coord;

        getline(coords, coord, ',');
        point.x = stol(coord);
        getline(coords, coord, ',');
        point.y = stol(coord);
        getline(coords, coord, ',');
        point.z = stol(coord);

        junction_boxes.push_back(point);
    }
    parent = vector(junction_boxes.size(), -1);
    sizes = vector(junction_boxes.size(), 0);

    for (int i=0;i<junction_boxes.size();i++) {
        make_set(i);
    }

    vector<tuple<int,int,long long>> distances;
    // get all distances between boxes
    for (int i=0;i<junction_boxes.size();i++){
        for (int j=i+1;j<junction_boxes.size();j++){
            long long dist = sqr_dist(junction_boxes[i], junction_boxes[j]);
            distances.push_back({i, j, dist});
        }
    }

    // sort distances ascending
    sort(distances.begin(), distances.end(), 
        [](const tuple<int,int,long long>& a,  const tuple<int,int,long long>& b){
            return get<2>(a) < get<2>(b);
        }
    );

    tuple<int,int,long long> points_and_dist;
    for (int i=0; i < distances.size(); i++) {
        points_and_dist = distances[i];
        
        union_sets(get<0>(points_and_dist), get<1>(points_and_dist));
        if (sizes[find_set(get<0>(points_and_dist))] == junction_boxes.size()) 
            break;
    }

    cout << junction_boxes[get<0>(points_and_dist)].x * junction_boxes[get<1>(points_and_dist)].x  << endl;
    return 0;
}
