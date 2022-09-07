/**
 * @file main.cpp
 * @author Paulina Cardoso Fuentes (A01701490)
 * @author Paola Adriana Millares Forno (A01705674)
 * @brief Encontrar los puntos mas cercanos en un plano
 * @date 2021-10-24
 * 
 */

#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

// Estructura de un punto
struct Point {
	int x, y;
};

// Funcion auxiliar para comparar puntos por coordenada x
int compareByX(const void* a, const void* b) {
	Point *p1 = (Point *)a, *p2 = (Point *)b;
	return (p1->x - p2->x);
}

// Funcion auxiliar para comparar puntos por coordenada y
int compareByY(const void* a, const void* b) {
	Point *p1 = (Point *)a, *p2 = (Point *)b;
	return (p1->y - p2->y);
}

// Calcula la distancia entre 2 puntos
float distance(Point p, Point q) {
	return sqrt( (p.x - q.x)*(p.x - q.x) + (p.y - q.y)*(p.y - q.y));
}

// Calcula los puntos mas cerca a fuerza bruta (cuando son 3 o menos puntos)
pair<Point, Point> bruteForceClosest(Point points[], int n) {
	float min = FLT_MAX;
	pair<Point, Point> closestPoints;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if ( distance(points[i], points[j]) < min)
				closestPoints = make_pair(points[i], points[j]);
				min = distance(points[i], points[j]);
		}
	}
	
	return closestPoints;
}

// Calcula los puntos mas cercanos de las seccion de en medio
pair<Point, Point> closestMiddleSet(Point middlePoints[], int n, int d) {
	float min = d;
	qsort(middlePoints, n, sizeof(Point), compareByY);

	// Puntos temporales para el caso de que no haya 
	// un par de puntos mas cercano, y que devuelva
	// un par de puntos que sean mas grande a dist 
	// para no tomarlos en cuenta
	Point temp1, temp2;
	temp1.x = 0; temp1.y = 0;
	temp2.x = d; temp2.y = d;
	pair<Point, Point> closestPoints = make_pair(temp1, temp2);

	// cout << endl << "Middle" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j<n && (middlePoints[j].y - middlePoints[i].y) < min; j++) {
			if (distance(middlePoints[i], middlePoints[j]) < min) {
				min = distance(middlePoints[i], middlePoints[j]);
                closestPoints = make_pair(middlePoints[i], middlePoints[j]);
			}
		}
	}
	
    return closestPoints;
}

// Funcion recursiva para encontrar los puntos mas cercanos
pair<Point, Point> closestDist(Point points[], int n) {
	if (n <= 3)
		return bruteForceClosest(points, n);
	
	pair<Point, Point> result; // Donde se guardaran los puntos mas cercanos a devolver

	int mid = n/2;
	Point middlePoint = points[mid];

	pair<Point, Point> slPoints = closestDist(points, mid);
	pair<Point, Point> srPoints = closestDist(points + mid, n-mid);

	float sl = distance(slPoints.first, slPoints.second); // Distancia entre los puntos del set izq
	float sr = distance(srPoints.first, srPoints.second); // Distancia entre los puntos del set der

	float d = min(sl, sr);
	if (sl < sr)
		result = slPoints;
	else
		result = srPoints;

	Point middlePoints[n];
	int j = 0;
	// cout << "variable d: " << d << endl;
	for (int i = 0; i < n; i++) {
		if (abs(points[i].x - middlePoint.x) < d) {
			// cout << "i: " << i << endl;
			middlePoints[j] = points[i];
			j++;
		}
	}

	pair<Point, Point> smPoints = closestMiddleSet(middlePoints, j, d);
	float sm = distance(smPoints.first, smPoints.second); // Distancia entre los puntos del set izq

	if (sm < d)
		result = smPoints;
	
	return result;
}

int main() {
	int n;
	cin >> n;
	Point points[n];

	for (int i = 0; i < n; i++) {
		double x, y;
		cin >> x;
		cin >> y;
		points[i].x = x;
		points[i].y = y;
	}
	qsort(points, n, sizeof(Point), compareByX); // Ordena el arreglo por la coordenada en X

	pair<Point, Point> resultPoints = closestDist(points, n);
	Point a = resultPoints.first, b = resultPoints.second;
	float dist = distance(a, b);

	printf("El par mas cercano: (%d,%d), (%d,%d)\n", a.x, a.y, b.x, b.y);
	cout << "La distancia mas corta es: " << dist << endl;
	return 0;
}
