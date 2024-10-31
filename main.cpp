#include <cmath>
#include <iostream>

class Vector2 {
public:
    double x {};
    double y {};

    Vector2(const double x, const double y) {
        this -> x = x;
        this -> y = y;
    }

    Vector2 Unit() {
        const double magnitude = Magnitude();
        return magnitude == 0.0 ? Vector2(0, 0) : Vector2(x / magnitude, y / magnitude);
    }

    double Magnitude() {
        return sqrt(pow(x, 2.0) + pow(y, 2.0));
    }

    double Dot(const Vector2 vector) {
        return (x * vector.x) + (y * vector.y);
    }

    bool Equals(const Vector2 vector) {
        return x == vector.x && y == vector.y;
    }
};

class Boid {
    static int SEPARATION_WEIGHT;
    static int ALIGNMENT_WEIGHT;
    static int COHESION_WEIGHT;
};

bool Expect(const double actual, const double expect, const double epsilon = 1e-9) {
    return fabs(actual - expect) < epsilon;
}

void Log(const std::string& testName, const bool success) {
    if (success) {
        std::cout << "\033[32m" << testName << " test passed." << "\033[0m" << std::endl;
    } else {
        std::cout << "\033[31m" <<  testName << " test failed." << "\033[0m" << std::endl;
    }
}

int main() {
    Vector2 v1(1, 1);
    Vector2 v2(2, 2);

    // Vector2 Class Unit Tests
    Log("Vector magnitude", Expect(v1.Magnitude(), sqrt(2)));
    Log("Unit vector", Expect(v2.Unit().Magnitude(), 1));
    Log("Vector dot-product", Expect(v1.Dot(v2), 4));
    Log("Vector equals", Expect(v1.Equals(v2), false));

    return 0;
}