#include <iostream>
#include <cmath>

class Point {
    int x, y;

    public:
        Point(int pos_x, int pos_y) {
            x = pos_x;
            y = pos_y;
        }

        int getX() const { return x; }
        int getY() const { return y; }
};

class Geometry {
    Point* point_array[100];
    int size;

    public:
        Geometry(Point **point_list);
        Geometry();
        ~Geometry();

        void AddPoint(const Point &point);
        void PrintDistance();
        void PrintNumMeets();
};

Geometry::Geometry(Point **point_list) {
    int count = 0;

    while (count < 100 && point_list[count] != nullptr) {
        point_array[count] = new Point(point_list[count]->getX(), point_list[count]->getY());
        count++;
    }
    size = count;
    while (count < 100) {
        point_array[count] = nullptr;
        count++;
    }
}

Geometry::Geometry() {
    for (int i = 0; i < 100; i++){
        point_array[i] = nullptr;
    }
    size = 0;
}

Geometry::~Geometry() {
    for (int i = 0; i < size; i++) {
        delete point_array[i];
    }
}

void Geometry::AddPoint(const Point &point){
    // 여기서 const Point&로 받았다는 건
    // point 안의 값이 절대로 수정되면 안된다는겁니다
    // 그럼 point 안의 method중에서 "값을 변경할 가능성이 있는 method"는 애당초 실행할 수가 없으니까
    // 무조건 const method만 실행이 가능
    if (size < 100){
        point_array[size] = new Point(point.getX(), point.getY());
        size++;
    }
}

void Geometry::PrintDistance(){
    if (size < 2) {
        std::cout << "최소 2개의 점 필요." << std::endl;
        return;
    }
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            double dx = point_array[i]->getX() - point_array[j]->getX();
            double dy = point_array[i]->getY() - point_array[j]->getY();
            
            double distance = std::sqrt(dx * dx + dy * dy);

            std::cout << "점 (" << point_array[i]->getX() << ", " << point_array[i]->getY() << ") 과"
                    << "점 (" << point_array[j]->getX() << ", " << point_array[j]->getY() << ") 의 거리는 ("
                    << distance << ")입니다." << std::endl;
        }
    }
}

void Geometry::PrintNumMeets(){

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
    return 0;
}