#include <iostream>

int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
#include <cmath>

class Vector2 {
public:
    float x {};
    float y {};

    Vector2(const float x, const float y) {
        this -> x = x;
        this -> y = y;
    }

    Vector2 Unit() {
        double magnitude = this->Magnitude();
        return Vector2(this->x / magnitude, this->y / magnitude);
    }

    double Magnitude() {
        return sqrt(pow(this->x, 2) + pow(this->y, 2));
    }

    double Dot(const Vector2 vector) {
        return (this->x * vector.x) + (this->y * vector.y);
    }

    bool Equals(const Vector2 vector) {
        return this->x == vector.x and this->y == vector.y;
    }
};

class Boid {
    static int SEPARATION_WEIGHT;
    static int ALIGNMENT_WEIGHT;
    static int COHESION_WEIGHT;
};

int main() {
    return 0;
}