#include <iostream>
#include <cmath>

class Point {
	int x, y;

	public:
		Point(int pos_x, int pos_y) {
			x = pos_x;
			y = pos_y;
		}
		
		int X() { return (x); }
		// int X() const { return (x); }
		// int Y() {
		// 	return (y);
		}
};

class Geometry {
	public:
		Geometry() {
			num_points = 0;
		}

		void AddPoint(const Point &point) {
			point_array[num_points ++] = new Point(point.x, point.y);
		}

		void PrintDistance() {
			double distance;

			for (int i = num_points - 1; i >= 0; i--) {
				for(int j = num_points - 1; j >= 0; j--) {
					if (i == j) {continue;}
					else {
						distance = sqrt(pow(point_array[i]->x - point_array[j]->x, 2) + pow(point_array[i]->y - point_array[j]->y, 2));
						std::cout << "distance " << i << " to " << j << distance << std::endl;
					}
				}
			}
		}
		void PrintNumMeets();

	private:
		//점 100개를 보관하는 배열
		Point* point_array[100];
		int num_points;
};

int main() {
	Geometry geo;

	Point point(3, 3);
	const Point& rpoint = point;

	rpoint.X();
	geo.AddPoint(Point(0, 0));
	geo.AddPoint(Point(2, 0));
	geo.AddPoint(Point(2, 2));
	geo.AddPoint(Point(2, 0));
	geo.PrintDistance();

}
