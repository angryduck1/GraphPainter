#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Graph {
private:
	string name;
	int weight;  // Ширина графика (по оси X)
	int height; // Высота графика (по оси Y)
	int x_point; // Координата X точки
	int y_point; // Координата Y точки

public:
	Graph(string name, int x, int y) {
		this->name = name;
		this->weight = x;
		this->height = y;
		this->x_point = -1;
		this->y_point = -1;
	}

	void set_point(int x, int y) {
		this->x_point = x;
		this->y_point = y;
	}

	void paint_graph() {
		for (int y = height; y >= -height; y--) {
			for (int x = -weight; x <= weight; x++) {
				if (x == 0 && y != 0) {
					cout << "1";
				}
				else if (y == 0 && x != 0) {
					cout << "2";
				}
				else if (x == x_point && y == y_point) {
					cout << "*";
				}
				else {
					cout << " ";
				}
			}
			cout << endl;
		}


		cout << "  " << name << " Graphic" << endl;
		cout << "X: " << weight << ", Y: " << height << endl;
	}
};

int main() {
	Graph graph("Test", 12, 12);

	graph.set_point(6, 7);  // Установка координат точек

	graph.paint_graph();
}