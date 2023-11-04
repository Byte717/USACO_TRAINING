#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const ll INF = 1e18;
const ll MOD = 1e9+7;
int n;
double x;
/*
What I learned Cow Steeple Chase 2:
    - for sweep line implementation:
        - Sort all points by x
        - iterate through them,
        - see if u can find them in the set
            - if u can, see if a condition holds true compared to the next and prev in the set
            - if u cant, remove it and see if u can see a condition hold true between next and prev
        - now calculate answer
    - when sorted, compare to value below and above
*/


struct Point{
    ll x, y;
    int Segmentidx;
};

struct Segment{
    Point p, q;
    int idx;
};

bool operator<(Point p1, Point p2){return ((p1.x == p2.x) ? p1.y < p2.y : p2.x < p2.x);}
int sign(ll x) { if (x==0) return 0; else return x<0 ? -1 : +1; }
int operator* (Point p1, Point p2) { return sign(p1.x * p2.y - p1.y * p2.x); }
Point operator- (Point p1, Point p2) { Point p = {p1.x-p2.x, p1.y-p2.y}; return p; }
bool operator==(Segment s1, Segment s2) { return s1.idx == s2.idx; }
bool isect(Segment &s1, Segment &s2)
{
  Point &p1 = s1.p, &q1 = s1.q, &p2 = s2.p, &q2 = s2.q;
  return ((q2-p1)*(q1-p1)) * ((q1-p1)*(p2-p1)) >= 0 && ((q1-p2)*(q2-p2)) * ((q2-p2)*(p1-p2)) >= 0;
}
double eval(Segment s) {
  if (s.p.x == s.q.x) return s.p.y;
  return s.p.y + (s.q.y-s.p.y) * (x-s.p.x) / (s.q.x-s.p.x);
}
bool operator<(Segment s1, Segment s2) { return s1.idx != s2.idx && eval(s1)<eval(s2); }

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("cowjump.in","r",stdin);
    cin >> n;
    vector<Segment> S;
    vector<Point> P;
    for(int i = 0; i < n;i++){
        Point X, Y;
        cin >> X.x >> X.y >> Y.x >> Y.y;
        Segment s;
        Y.Segmentidx = X.Segmentidx = s.idx = i;
        s.p = X, s.q = Y;
        S.push_back(s);
        P.push_back(X), P.push_back(X); 
    }
    sort(all(P));
    set<Segment> active;
    int ans1, ans2;
    for(int i = 0; i < n*2;i++){
        ans1 = P[i].Segmentidx; x = P[i].x;
        auto it = active.find(S[ans1]);
        if(it != active.end()){ // segment already exsists and we have reached it's end;
            auto after = it, before = it; after++;
            if(before != active.begin() && after != active.end()){ // check if the segments next to this one become adj after this is deleted
                before--;
                if(isect(S[before->idx], S[after->idx])){
                    ans1 = before->idx;
                    ans2 = after->idx;
                }
            }
            active.erase(it);
        }else{
            // we didn't find this segment in the active set.
            auto it = active.lower_bound(S[ans1]); // try to find a segment  that intersects
            if(it != active.end() && isect(S[it->idx], S[ans1])){ans2 = it->idx; break;} // if the segment intersects, we found an answer
            if(it != active.begin()){
                it--;
                if(isect(S[it->idx], S[ans1])){
                    ans2 = it->idx;
                    break;
                }
            }
        }
    }
    if(ans1 > ans2) swap(ans1,ans2);
    int ans2_count = 0;
    for(int i = 0; i < n;i++){
        if(S[i].idx != ans2 && isect(S[i], S[ans2])) ans2_count++;
    }
    cout << (ans2_count > 1 ? ans2+1 : ans1+1) << endl;
    return 0;
}