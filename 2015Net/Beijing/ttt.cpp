#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <time.h>
using namespace std;

const int maxn = 1000 + 10;
const double eps = 1e-8;
const double PI = acos(-1.0);
const int offset=1e8;
int dcmp(double x){
     if(fabs(x) < eps) return 0;
     return x < 0 ? -1 : 1;
}

struct Point{
     double x, y;
     Point(double x = 0, double y = 0) : x(x), y(y) {}
     void read(){
          scanf("%lf%lf", &x, &y);
     }
     bool operator < (const Point &rhs) const{
          if(dcmp(x - rhs.x) != 0) return x < rhs.x;
          return y < rhs.y;
     }
};

typedef Point Vector;
Vector operator + (const Vector &A, const Vector &B){ return Vector(A.x + B.x, A.y + B.y); }
bool operator == (const Vector &A, const Vector &B){ return dcmp(A.x - B.x) == 0 && dcmp(A.y - B.y) == 0; }
Vector operator - (const Vector &A, const Vector &B){ return Vector(A.x - B.x, A.y - B.y); }
Vector operator * (const Vector &A, double b){ return Vector(A.x*b, A.y*b); }
Vector operator / (const Vector &A, double b){ return Vector(A.x/b, A.y/b); }
double Dot(Point a, Point b){ return a.x * b.x + a.y * b.y; }
double Length(const Vector &A){ return sqrt(Dot(A, A)); }
double Angle(Point A, Point B){ return acos(Dot(A, B) / Length(A) / Length(B)); }
double Dist2(Point A, Point B){ return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y); }
double Cross(Point A, Point B){ return A.x * B.y - A.y * B.x; }
bool cmp_(const Point& p1, const Point& p2){ return atan2(p1.y, p1.x) > atan2(p2.y, p2.x); }

struct Line{
     Point p;
     Vector v;
     double ang;
     Line(){}
     Line(Point p, Vector v) : p(p), v(v){
          ang = atan2(v.y, v.x);
     }
     bool operator < (const Line &L)const{
          return ang < L.ang;
     }
     Point point(double t){
          return p + v * t;
     }
};
struct Circle{
     Point c;
     double r;
     Circle() {}
     Circle(Point c, double r) : c(c), r(r) {}
     Point point(double a){
          return Point(c.x + cos(a) * r, c.y + sin(a) * r);
     }
     void read(){
          c.read();
          scanf("%lf", &r);
     }
};

int n;
Point p[maxn];
Circle center;
vector<Point> intersection;//保存圆与多边形的交点
double segment, rad_len;

bool in(Point a, Point l, Point r){
     double max_x = max(l.x, r.x);
     double min_x = min(l.x, r.x);
     double max_y = max(l.y, r.y);
     double min_y = min(l.y, r.y);
     if(dcmp(max_x - a.x) >= 0 && dcmp(a.x - min_x) >= 0 && dcmp(max_y - a.y) >= 0 && dcmp(a.y - min_y) >= 0) return true;
     return false;
}

void get_Line_CircleIntersection(Line L, Circle C, vector<Point>& sol, Point A, Point B){
     double t1, t2;
     double a = L.v.x, b = L.p.x - C.c.x, c = L.v.y, d = L.p.y - C.c.y;
     double e = a * a + c * c , f = 2 * (a * b + c * d), g= b * b + d * d - C.r * C.r;
     double delta = f * f - 4 * e * g;
     Point cur;
     sol.push_back(A);
     sol.push_back(B);
     if(dcmp(delta) < 0) return;
     if(dcmp(delta) == 0){
          t1 = t2 = -f / (2 * e);
          cur = L.point(t1);
          if(in(cur, A, B)) sol.push_back(cur), intersection.push_back(cur);
          return;
     }
     t1 = (-f + sqrt(delta)) / (2 * e);
     cur = L.point(t1);
     if(in(cur, A, B)) sol.push_back(cur), intersection.push_back(cur);
     t2 = (-f - sqrt(delta)) / (2 * e);
     cur = L.point(t2);
     if(in(cur, A, B)) sol.push_back(cur), intersection.push_back(cur);
}
void init(){
     rad_len = 0;
     segment = 0;
     intersection.clear();//保存圆与多边形的交点
}
bool Point_in_Circle(Point A){
     if(dcmp(center.r * center.r - Dist2(A, center.c)) > 0) return true;
     return false;
}
void get_Circle_Segment_Intersection(Point a, Point b){
     vector<Point> save;
     get_Line_CircleIntersection(Line(a, a-b), center, save, a, b);
     int size_ = save.size();
     sort(save.begin(), save.end());
     for(int i = 0; i < size_ - 1; i++){
          Point mid = (save[i] + save[i+1]) / 2;
          if(Point_in_Circle(mid)) segment += Length(save[i] - save[i+1]);
     }
}
int Circle_in_Ploygon(const Point *arr,const int &len,const Point &A,int on_edge)
{
    Point q;
    int i=0,counter;
    while(i<len)
    {
        q.x=rand()+offset;//随机取一个足够远的点q
        q.y=rand()+offset;//以p为起点q为终点做射线L
        for(counter=i=0; i<len; i++) //依次对多边形的每条边进行考察
        {
            Point t1 = arr[i]-A;
            Point t2 = arr[(i+1)%len]-A;
            Point t3 = q-A;
            Point t4 = arr[i]-A;
            Point t5 = A-arr[i];
            Point t6 = arr[(i+1)%len]-arr[i];
            Point t7 = q-arr[i];
            if(fabs(Cross(t1,t2))<eps &&
                    (arr[i].x-A.x)*(arr[(i+1)%len].x-A.x)<eps && (arr[i].y-A.y)*(arr[(i+1)%len].y-A.y)<eps)
                return on_edge; //点p在边上,返回on_edge
            else if(fabs(Cross(t3,t4))<eps) break; //点arr[i]在射线pq上，停止本循环，另取q
            else if(Cross(t4,t3)*Cross(t2,t3)<-eps &&
                    Cross(t5,t6)*Cross(t7,t6)<-eps)
                counter++;
        }
    }
    return counter&1;
}
double Angle_(Point A){
    double ang = Angle(A, Point(1, 0));
    if(dcmp(Cross(Point(1, 0), A)) < 0) ang = - ang;
    return ang;
}
Point get_rad_midPoint(Point A, Point B){
    double rad_A_x = Angle_(A);
    double rad_B_x = Angle_(B);
    double rad_A_B = Angle(A, B);
    double rad_;
    if(dcmp(Cross(A, B) > 0)) rad_ = rad_A_x - (PI - rad_A_B / 2);
    else rad_ = rad_A_x - rad_A_B / 2;
    return Circle(Point(0, 0), center.r).point(rad_);
}
void input(){
     init();
     for(int i = 0; i < n; i++) p[i].read();
     center.read();
}
void solve_ploygon(){
     for(int i = 0; i < n; i++) get_Circle_Segment_Intersection(p[i], p[(i+1)%n]);
}
void solve_circle(){
    double sum_rad = 0;
    for(int i = 0; i < (int)intersection.size(); i++)
        intersection[i] = intersection[i] - center.c;
    sort(intersection.begin(), intersection.end(), cmp_);
    intersection.erase(unique(intersection.begin(), intersection.end()), intersection.end());
    int size_ = intersection.size();
    if(size_ <= 1 && Circle_in_Ploygon(p, n, center.point(0), 1) && Circle_in_Ploygon(p, n, center.point(1), 1)){
        rad_len = 2 * PI * center.r;
        return;
    }
    for(int i = 0; i < n; i++) p[i] = p[i] - center.c;
    for(int i = 0; i < size_; i++){
        int j = (i + 1) % size_;
        Point mid = get_rad_midPoint(intersection[i], intersection[j]);
        if(Circle_in_Ploygon(p, n, mid, 0)){
            double cur_rad = Angle(intersection[i], intersection[j]);
            if(dcmp(Cross(intersection[i], intersection[j])) > 0) cur_rad = 2 * PI - cur_rad;
            sum_rad += cur_rad;
        }
    }
    rad_len = sum_rad * center.r;
}

#include <iostream>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out1.txt","w",stdout);

     while(scanf("%d", &n) && n){
          input();
          solve_ploygon();
          solve_circle();

	//	  cout<<segment<<' '<<rad_len<<endl;

          printf("%.0lf\n", segment + rad_len);
     }
     return 0;
}
