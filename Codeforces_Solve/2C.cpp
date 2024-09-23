#include <cstdio>
#include <cmath>
#define fr(i,j) for(int i = 0; i < j; i++)
#define p(a) ((a)*(a))
 
double s, dx = 0, dy = 0, x[3], y[3], r[3], t[3];
 
// Function to calculate the total error based on distance differences
double F(double dx, double dy) {
    double ret = 0;
    fr(i, 3) {
        t[i] = sqrt(p(dx - x[i]) + p(dy - y[i])) / r[i];  // Calculate the ratio of distance to radius
    }
    fr(i, 3) {
        ret += p(t[i] - t[(i + 1) % 3]);  // Sum of squared differences
    }
    return ret;
}
 
int main() {
    // Input for the coordinates and radii
    fr(i, 3) {
        scanf("%lf%lf%lf", &x[i], &y[i], &r[i]);
    }
 
    // Initialize the starting point as the centroid of the three points
    fr(i, 3) {
        dx += x[i] / 3;
        dy += y[i] / 3;
    }
 
    // Gradient descent-like approach to minimize the function F
    for (s = 1; s > 1e-6;) {
        if (F(dx, dy) > F(dx + s, dy)) {
            dx += s;  // Move right
        } else if (F(dx, dy) > F(dx - s, dy)) {
            dx -= s;  // Move left
        } else if (F(dx, dy) > F(dx, dy + s)) {
            dy += s;  // Move up
        } else if (F(dx, dy) > F(dx, dy - s)) {
            dy -= s;  // Move down
        } else {
            s *= 0.7;  // Reduce the step size if no improvement
        }
    }
 
    // Check if the result is sufficiently close to zero
    if (F(dx, dy) < 1e-5) {
        printf("%.5lf %.5lf\n", dx, dy);  // Print the result
    }
 
    return 0;
}
