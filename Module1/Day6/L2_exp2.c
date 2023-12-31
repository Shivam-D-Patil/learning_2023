/*
Write a program to enter to Cartesian coordinate points and display the distance between them.
*/
#include <stdio.h>
#include <math.h>

struct Point {
    float x;
    float y;
};

float calculateDistance(struct Point p1, struct Point p2) {
    float distance;

    distance = sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));

    return distance;
}

int main() {
    struct Point point1, point2;

    printf("Enter the coordinates of point 1 (x y): ");
    scanf("%f %f", &point1.x, &point1.y);

    printf("Enter the coordinates of point 2 (x y): ");
    scanf("%f %f", &point2.x, &point2.y);

    float distance = calculateDistance(point1, point2);

    printf("Distance between the two points: %.2f\n", distance);

    return 0;
}
