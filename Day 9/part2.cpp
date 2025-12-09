#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;
};

long long area(const Point &bl, const Point &tr) {
    return (tr.x - bl.x + 1) * (tr.y - bl.y + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<Point> red;
    string s;
    while (cin >> s) { 
        auto pos = s.find(','); 
        long long x = stoll(s.substr(0, pos));
        long long y = stoll(s.substr(pos+1));
        red.push_back({x, y});
    }

    vector<pair<Point, Point>> pairs; // rectangles from all pairs
    vector<pair<Point, Point>> lines; // rectangles from consecutive points

    int n = red.size();

    // every single rectangle
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            Point bl{min(red[i].x, red[j].x), min(red[i].y, red[j].y)};
            Point tr{max(red[i].x, red[j].x), max(red[i].y, red[j].y)};
            pairs.push_back({bl, tr});
        }
    }

    // rectangles along polygon edges
    for (int i = 0; i < n; i++) {
        Point a = red[i];
        Point b = red[(i+1) % n];
        Point bl{min(a.x, b.x), min(a.y, b.y)};
        Point tr{max(a.x, b.x), max(a.y, b.y)};
        lines.push_back({bl, tr});
    }

    // sort rectangles by area descending
    auto by_area = [&](const pair<Point, Point> &A, const pair<Point, Point> &B) {
        return area(A.first, A.second) > area(B.first, B.second);
    };

    sort(pairs.begin(), pairs.end(), by_area);
    sort(lines.begin(), lines.end(), by_area);

    for (auto &R : pairs) {
        Point bl = R.first, tr = R.second;

        bool found = false;
        for (auto &L : lines) {
            Point p = L.first, r = L.second;
            if (p.x < tr.x && p.y < tr.y && r.x > bl.x && r.y > bl.y) {
                found = true;
                break;
            }
        }

        if (!found) {
            cout << area(bl, tr) << "\n";
            break;
        }
    }

    return 0;
}
