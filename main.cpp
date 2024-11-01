#include <iostream>
#include <cmath>

using namespace std;

class Vector2 {
public:
    double X {};
    double Y {};

    Vector2(const double x = 0.0, const double y = 0.0) {
        this -> X = x;
        this -> Y = y;
    }

    Vector2 Unit() {
        const double magnitude = Magnitude();
        return magnitude == 0.0 ? Vector2(0, 0) : Vector2(X / magnitude, Y / magnitude);
    }

    double Magnitude() {
        return sqrt(pow(X, 2.0) + pow(Y, 2.0));
    }

    double Dot(const Vector2 vector) {
        return (X * vector.X) + (Y * vector.Y);
    }

    bool Equals(const Vector2 vector) {
        return X == vector.X && Y == vector.Y;
    }
};

bool Expect(const double actual, const double expect, const double epsilon = 1e-9) {
    return fabs(actual - expect) < epsilon;
}

void Log(const string& testName, const bool success) {
    if (success) {
        cout << "\033[32m" << testName << " test passed." << "\033[0m" << endl;
    } else {
        cout << "\033[31m" <<  testName << " test failed." << "\033[0m" << endl;
    }
}

struct Boid {
    Vector2 Position {};
    Vector2 Velocity {};
};

int main() {
    Vector2 v1(1, 1);
    Vector2 v2(2, 2);

    // Vector2 Class Unit Tests
    Log("Vector magnitude", Expect(v1.Magnitude(), sqrt(2)));
    Log("Unit vector", Expect(v2.Unit().Magnitude(), 1));
    Log("Vector dot-product", Expect(v1.Dot(v2), 4));
    Log("Vector equals", Expect(v1.Equals(v2), false));

    vector<Boid> boids;
    for (int i = 0; i < 100; i++) {
        const int posX = rand() % 10 + 1;
        const int posY = rand() % 10 + 1;
        const int velX = rand() % 5 + 1;
        const int velY = rand() % 5 + 1;

        Boid boid {
            Vector2(posX, posY),
            Vector2(velX, velY)
        };

        boids.push_back(boid);
    }

    for (int i = 0; i < boids.size(); i++) {
        Boid boid = boids.at(i);
        printf("ID: %d, Position: (%f, %f), Velocity: (%f, %f)\n", i, boid.Position.X, boid.Position.Y, boid.Velocity.X, boid.Velocity.Y);
    }

    return 0;
}