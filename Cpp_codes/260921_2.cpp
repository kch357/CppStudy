#include <iostream>
#include <cmath>

class Point {
    int x, y;

    public:
        Point(int pos_x, int pos_y) {
            x = pos_x;
            y = pos_y;
        }

        int GetX() const { return x; }
        int GetY() const { return y; }
};

class Geometry {
    // 점 100개를 보관하는 배열
    Point* point_array[100];
    int size = 0;

    public:
        Geometry(Point **point_list) {
            size = sizeof(point_list);
            if (size <= sizeof(point_array)) {
                for (int i = 0; i < size; i++) {
                    point_array[i] = point_list[i];
                }
            }
        }
        Geometry() {
            size = 0;
            for (int i = 0; i < 100; i++) {
                point_array[i] = nullptr;
            }
        }

        void AddPoint(const Point &point);
        void PrintDistance();
        void PrintNumMeets();
};

void Geometry::AddPoint(const Point &point) {
    if (size < 100) {
        //point_array[size++] = point;
    }
}

void Geometry::PrintDistance() {
    if (size < 2) {
        std::cout << "최소 2개의 점 필요." << std::endl;
        return;
    }
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            double dx = point_array[i]->GetX() - point_array[j]->GetX();
            double dy = point_array[i]->GetY() - point_array[j]->GetY();
            
            double distance = std::sqrt(dx * dx + dy * dy);

            std::cout << "점 (" << point_array[i]->GetX() << ", " << point_array[i]->GetY() << ") 과"
                    << "점 (" << point_array[j]->GetX() << ", " << point_array[j]->GetY() << ") 의 거리는 ("
                    << distance << ")입니다." << std::endl;
        }
    }
}

void Geometry::PrintNumMeets() {
    
}

int main() {
    Point A(1, 2);
    Point B(5, 7);
    Point C(1, 3);
    Point D(5, 6);

    Geometry Geo;
    Geo.AddPoint(A);
    Geo.AddPoint(B);
    Geo.PrintDistance();
    Geo.AddPoint(C);
    Geo.AddPoint(D);
    
    Geo.PrintDistance();
}