#include <iostream>
using namespace std;
class Trinomial {
private:
    double a, b, c; // Коефіцієнти при змінних у нульовій, першій та другій степені

public:
    // Конструктор без параметрів
    Trinomial() {
        a = 1;
        b = 1;
        c = 1;
    }

    // Конструктор з параметрами
    Trinomial(double a_val, double b_val, double c_val) {
        if (a_val == 0 && b_val == 0 && c_val == 0) 
            abort();
        else {
            a = a_val;
            b = b_val;
            c = c_val;
        }

    }
    Trinomial(const Trinomial& other) {
        a = other.a;
        b = other.b;
        c = other.b;
    }
    // Функція для додавання двох тричленів
    Trinomial Add(const Trinomial& other) const {
        return Trinomial(a + other.a, b + other.b, c + other.c);
    }

    // Функція для віднімання двох тричленів
    Trinomial Subtract(const Trinomial& other) const {
        return Trinomial(a - other.a, b - other.b, c - other.c);
    }

    // Функція для порівняння двох тричленів на рівність
    bool isEqual(const Trinomial& other) const {
        if (a == other.a && b == other.b && c == other.c)
            return true;
        else
            return false;
    }

    // Функція для множення тричлена на дійсне число
    Trinomial Multiply(double scalar) const {
        return Trinomial(a * scalar, b * scalar, c * scalar);
    }

    // Функція для додавання дійсного числа до тричлена
    Trinomial addScalar(double scalar) const {
        return Trinomial(a, b, c + scalar);
    }

    // Функція для обчислення значення тричлена для заданого значення змінної
    double Evaluate(double x) const {
        return (a * x * x) + (b * x) + c;
    }

    // Функція для введення коефіцієнтів тричлена з консолі
    void Input() {
        cout << "Enter coefficients (a, b, c): ";
        cin >> a >> b >> c;
    }

    // Функція для виведення коефіцієнтів тричлена на консоль
    void Output() const {
        cout << a << "x^2 + " << b << "x + " << c << endl;
    }
};

int main() {
  
    Trinomial t1, t2;

    cout << "Enter coefficients for the first trinomial:" << endl;
    t1.Input();

    cout << "Enter coefficients for the second trinomial:" << endl;
    t2.Input();

    Trinomial sum = t1.Add(t2);
    Trinomial difference = t1.Subtract(t2);
    bool isEqual = t1.isEqual(t2);
    int m;
    cout << "Enter a scalar to be multiplied on: ";
    cin >> m;
    Trinomial multiplied = t1.Multiply(m);
    int s;
    cout << "Enter a scalar to be added to: ";
    cin >> s;
    Trinomial addedScalar = t1.addScalar(s);
    int r;
    cout << "Enter a variable value: ";
    cin >> r;
    double result = t1.Evaluate(r);

    cout << "First trinomial: ";
    t1.Output();

    cout << "Second trinomial: ";
    t2.Output();

    cout << "Sum: ";
    sum.Output();

    cout << "Difference: ";
    difference.Output();

    cout << "Is equal: " << boolalpha << isEqual << endl;

    cout << "Multiplied: ";
    multiplied.Output();

    cout << "Added scalar : ";
    addedScalar.Output();

    cout << "Result for x: " << result << endl;

    return 0;

}
