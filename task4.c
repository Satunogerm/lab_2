#include <stdio.h>

struct rectangle
{
    int width , height;
};

int area(struct rectangle r)
{
    return r.height * r.width;
}

int perimeter(struct rectangle r)
{
    return 2 * (r.height + r.width);
}

int main()
{
    struct rectangle r1;

    printf("Enter your rectangle height = ");
    scanf("%i", &r1.height);
    printf("Enter your rectangle width = ");
    scanf("%i", &r1.width);

    struct rectangle *r = &r1;

    printf("Rectangle area = %i\n", area(r1));
    printf("Rectangle perimeter = %i\n", perimeter(*r));

    return 0;
}