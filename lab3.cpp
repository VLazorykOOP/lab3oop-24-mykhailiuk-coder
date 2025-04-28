#include <iostream>
#include <math.h>
using namespace std;

class square
{
	private:
		int side;
		unsigned int color;

	public:
		square()
		{
			side = 0;
			color = 0xFF8234; 
		}

        square(int side, unsigned int color)
		{
			this->side = side;
			this->color = color;
		}
		
		int area() { return side * side; }
		int perimeter() { return 4 * side; }
		float big_radius() { return sqrt(2) * side; }
		float small_radius() { return side / 2; }


		int returnParameters()
		{
			return side;
			return color;
			return area();
			return perimeter();
		}

		float returnRadius()
		{
			return big_radius();
			return small_radius();
		}

		void printParameters() 
		{
			cout << "Side: " << side << "\n";
			cout << "Color: " << color << "\n";
			cout << "Area: " << area() << "\n";
			cout << "Perimeter: " << perimeter() << "\n";
		}

		void printRadius() 
		{
			cout << "Big radius: " << big_radius() << "\n";
			cout << "Small radius: " << small_radius() << "\n";
		}

		void set_color(unsigned int color) { this->color = color; }
		void set_side(int side) { this->side = side; }
		
};

class Vector 
{
private:
	int size;  
    unsigned int* data;
    int state=0; 
    static int objectCount; 
public:
    Vector() : size(1), state(0) 
    {
		data = new unsigned int[1]; 
        if (!data) {
            state = 1;
        } else {
            data[0] = 0;
        }
        objectCount++;
    }

    Vector(int n)  
    {
        size = n;
        if (size < 0) {
            state = 3;
			data = nullptr; 
            return;
        }
        data = new unsigned int[n] {};
        if (!data) state = 1;
        objectCount++;
    }

    Vector(int n, unsigned int value) : size(n), state(0) {
        if (n < 0) {
            state = 3;
            data = nullptr;
            return;
        }
        data = new unsigned int[n];
        if (!data) state = 1;
        else fill(data, data + n, value);
        objectCount++;
    }

    
	Vector(const Vector& other) : size(other.size), state(other.state) { 
        data = new unsigned int[size];
        if (!data) state = 1;
		else copy(other.data, other.data + size, data); 
        objectCount++;
    }

    Vector& operator=(const Vector& other) {
        if (this == &other) return *this;
        delete[] data;
        size = other.size;
        state = other.state;
        data = new unsigned int[size];
        if (!data) state = 1;
        else copy(other.data, other.data + size, data);
        return *this;
    }

    ~Vector() {
        delete[] data;
        objectCount--;
    }

    void setElement(size_t index, unsigned int value = 0) {
        if (index >= size) {
            state = 2;
            return;
        }
        data[index] = value;
    }

    unsigned int getElement(size_t index) const {
        if (index >= size) {
            return 0;
        }
        return data[index];
    }

    void print() const {
        for (size_t i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    Vector operator+(const Vector& other) const {
        size_t minSize = min(size, other.size);
        Vector result(minSize);
        for (size_t i = 0; i < minSize; i++) {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }

    Vector operator-(const Vector& other) const {
        size_t minSize = min(size, other.size);
        Vector result(minSize);
        for (size_t i = 0; i < minSize; i++) {
            result.data[i] = data[i] - other.data[i];
        }
        return result;
    }

    Vector operator*(unsigned short scalar) const {
        Vector result(size);
        for (size_t i = 0; i < size; i++) {
            result.data[i] = data[i] * scalar;
        }
        return result;
    }

    bool operator==(const Vector& other) const {
        if (size != other.size) return false;
        for (size_t i = 0; i < size; i++) {
            if (data[i] != other.data[i]) return false;
        }
        return true;
    }

    bool operator!=(const Vector& other) const {
        return !(*this == other);
    }

    bool operator<(const Vector& other) const {
        return size < other.size;
    }

    bool operator>(const Vector& other) const {
        return size > other.size;
    }

    int getState() const { return state; }
    static int getObjectCount() { return objectCount; }
};

int Vector::objectCount = 0; 

		
int main()
{
	cout << "Lab#3_OOP\n\n";
	cout << "Task_1\n\n";
	square square1;
	square1.set_side(8);
	square1.set_color(0x00FF00); //green
	square1.printParameters();
	square1.printRadius();
	cout << "\n";

    cout << "Task_2\n\n";
    Vector v1;
    Vector v2(5);
    Vector v3(5, 10);
    Vector v4 = v3;

    cout << "Vector v1: "; v1.print();
    cout << "Vector v2: "; v2.print();
    cout << "Vector v3: "; v3.print();
    cout << "Vector v4 (copy v3): "; v4.print();

    v2.setElement(2, 20);
    cout << "New v2: "; v2.print();

    Vector v5 = v3 + v2;
    cout << "v3 + v2: "; v5.print();

    Vector v6 = v3 * 2;
    cout << "v3 * 2: "; v6.print();

    cout << "Number of objects: " << Vector::getObjectCount() << endl;

    return 0;
}