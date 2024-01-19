#include <iostream>

class drawAble
{
public:
    virtual void draw() const = 0;
    virtual ~drawAble() {}

};

class circle : public drawAble
{
private:
    double radius;

public:
    circle(const double& radius) : radius(radius) {}

    void draw() const override
    {
        std::cout << "draw a circle, radius = " << radius << std::endl;
    };
};

class rectangle : public drawAble
{
private:
    double width, height;

public:
    rectangle(const double& width, const double& height) : width(width), height(height) {}
    
    void draw() const override
    {
        std::cout << "draw a rectangle, width = " << width << " height = " << height << std::endl;
    }
};

class drawSystem
{
public:
    void draw(const drawAble* shape)
    {
        (*shape).draw();
    }
    void draw(const drawAble& shape)
    {
        shape.draw();
    }
    // void draw(const drawAble shape) 错误
    // {
    //     shape.draw();
    // }
};

int main()
{
    circle circleTest = circle(3.3);
    rectangle rectangleTest = rectangle(1, 2); 
    drawAble* drawAbleTest1 = new circle(3.3);

    drawSystem drawSystemTest;
    drawSystemTest.draw(drawAbleTest1);
    drawSystemTest.draw(rectangleTest);

    delete drawAbleTest1;
    return 0;
}