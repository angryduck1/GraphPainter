#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Graph {
private:
    string name;
    int weight;
    int height;
    int count_points;
    int** points;

public:
    ~Graph() {
        for (int i = 0; i < count_points; i++) {
            delete[] points[i];
        }
        delete[] points;
    }

    Graph(string name, int x, int y, int counts_points) {
        this->name = name;
        this->weight = x;
        this->height = y;
        this->count_points = counts_points;
        points = new int* [counts_points];

        for (int i = 0; i < counts_points; i++) {
            points[i] = new int[2];
        }
    }

    void set_point(int i, int x, int y) {
        if (i >= 0 && i < count_points) {
            points[i][0] = x;
            points[i][1] = y;
        }
        else {
            cout << "Index out of bounds!" << endl;
        }
    }

    void paint_graph() {
        for (int y = height; y >= -height; y--) {
            for (int x = -weight; x <= weight; x++) {
                bool isPoint = false;

                for (int point = 0; point < count_points; point++) {
                    if (x == points[point][0] && y == points[point][1]) {
                        cout << "*";
                        isPoint = true;
                        break;
                    }
                }

                if (!isPoint) {
                    if (x == 0 && y != 0) {
                        cout << "1";
                    }
                    else if (y == 0 && x != 0) {
                        cout << "2";
                    }
                    else {
                        cout << " ";
                    }
                }
            }
            cout << endl;
        }

        cout << "  " << name << " Graphic" << endl;
        cout << "X: " << weight << ", Y: " << height << endl;
    }
};

int main() {
    Graph graph("Parabola", 12, 12, 7); // Создаём график. 1 параметр - name; 2 - x; 3 - y; 4 - Количество меток(point).
    int index = 0;
    //Пример параболы

    graph.set_point(index++, -3, 9); // Установка координат точек. 1 - Номер точки; 2 - x; 3 - y.
    graph.set_point(index++, -2, 4);
    graph.set_point(index++, -1, 1);
    graph.set_point(index++, 0, 0);
    graph.set_point(index++, 1, 1);
    graph.set_point(index++, 2, 4);
    graph.set_point(index++, 3, 9);

    graph.paint_graph();

    return 0;
}
