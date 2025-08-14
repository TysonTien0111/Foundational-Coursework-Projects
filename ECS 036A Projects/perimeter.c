#include <stdio.h>
#include <stdlib.h>

/*
This program calculates the perimeter of a shape given its vertices in a binary file.
*/

typedef struct Point {
  /*
  This struct holds the coordinate points x and y.
  @x stores the x-coordinate
  @y stores the y-coordinate
  */

    int x;
    int y;
} Point;

void read_file(FILE* file, Point* *out_points_list, int *out_num_of_data) {
    /*
    This function reads the file.
    @num_of_data stores the integer that tells us how many vertices are in the binary file.
    @points_list holds a list of coordinate points.
    @nums stores the current coordinate points in the binary file.
    @out_num_of_data sends the num_of_data out.
    @out_points_list sends the points_list out.
    */

    int num_of_data = 0;
    Point* points_list;
    int nums[2];

    fread(&num_of_data, sizeof(int), 1, file);
    
    points_list = (Point*)calloc(num_of_data, sizeof(Point));
    
    for (int i = 0; i < num_of_data; ++i) {
        fread(nums, sizeof(int), 2, file);
        points_list[i].x = nums[0];
        points_list[i].y = nums[1];
    }

    *out_num_of_data = num_of_data;
    *out_points_list = points_list;
}

double square_root_perimeter(double vertices_value) {
    /*
    This function square roots the given vertices value.
    @square_root_number stores half of the vertices value.
    @temp stores the temporary value of the square_root_number.
    @returns the square root of the number.
    */

    double square_root_number = vertices_value / 2.0;
    double temp = 0;

    while (square_root_number != temp) {
        temp = square_root_number;
        square_root_number = ((vertices_value / temp) + temp) / 2;
    }
    
    return square_root_number;
}

void distance_between_point_formula(double* *out_distance_between_vertices_list, Point* points, int num_of_data) {
    /*
    This function uses the distance between two points formula in order to get one edge of the shape.
    @distance_between_vertices_list stores the edges of the shape in a list.
    @perimeter_square_rooted stores the edges of the shape when its value gets square rooted.
    @out_distance_between_vertices_list sends out the distance_between_vertices_list.
    */

    double* distance_between_vertices_list = (double*)calloc(num_of_data, sizeof(double));
    double perimeter_square_rooted;

    for (int i = 0; i < num_of_data - 1; ++i) {
        distance_between_vertices_list[i] = ((points[i + 1].x - points[i].x) * (points[i + 1].x - points[i].x)) + ((points[i + 1].y - points[i].y) * (points[i + 1].y - points[i].y));
    }

    distance_between_vertices_list[num_of_data - 1] = ((points[num_of_data - 1].x - points[0].x) * (points[num_of_data - 1].x - points[0].x)) + ((points[num_of_data - 1].y - points[0].y) * (points[num_of_data - 1].y - points[0].y));

    for (int i = 0; i < num_of_data; ++i) {
        perimeter_square_rooted = square_root_perimeter(distance_between_vertices_list[i]);
        distance_between_vertices_list[i] = perimeter_square_rooted;
    }

    *out_distance_between_vertices_list = distance_between_vertices_list;
}

double calculate_perimeter(int num_of_data, Point* points) {
    /*
    This function calculates the perimeter of the shape given its vertices.
    @distance_between_vertices_list stores the distance between all of the vertices.
    @perimeter_of_shape stores the perimeter of the shape.
    @returns the perimeter of the shape.
    */
    
    double* distance_between_vertices_list;
    double perimeter_of_shape = 0;
    
    distance_between_point_formula(&distance_between_vertices_list, points, num_of_data);

    for (int i = 0; i < num_of_data; ++i) {
        perimeter_of_shape += distance_between_vertices_list[i];
    }

    free(distance_between_vertices_list);

    return perimeter_of_shape;
}

void display_perimeter(double perimeter_of_shape) {
    /*
    This function displays the perimeter of the shape. 
    */

    printf("The perimeter is %.2lf", perimeter_of_shape);
}

int main(int argc, char** argv) {
    /*
    This is the main function of the program.
    @points store the vertices of the shape.
    @num_of_data stores the amount of vertices that the shape has.
    @perimeter_of_shape stores the perimeter of the shape.
    */

    Point* points;
    int num_of_data;
    double perimeter_of_shape;

    FILE* file = fopen(argv[1], "rb");
    read_file(file, &points, &num_of_data);
    perimeter_of_shape = calculate_perimeter(num_of_data, points);
    display_perimeter(perimeter_of_shape);
    free(points);
    fclose(file);

    return 0;
}