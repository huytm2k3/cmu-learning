#include <iostream>

std::vector<std::vector<float>> convert3DTo2DCoordinates(std::vector<float> &camera, std::vector<std::vector<float>> &coords);

int main()
{
    std::vector<float> camera(3);
    std::cout << "Enter coordinate for camera: ";
    std::cin >> camera[0] >> camera[1] >> camera[2];

    int numberOfPoints;
    std::cout << "Enter the number of 3D points: ";
    std::cin >> numberOfPoints;

    std::vector<std::vector<float>> coords(numberOfPoints, std::vector<float>(3));

    for (int i = 0; i < numberOfPoints; i++)
    {
        std::cout << "Enter coordinate for point (x, y, z) " << i + 1 << ": ";
        std::cin >> coords[i][0] >> coords[i][1] >> coords[i][2];
    }

    std::vector<std::vector<float>> result(numberOfPoints, std::vector<float>(2));
    result = convert3DTo2DCoordinates(camera, coords);

    for (int i = 0; i < result.size(); i++)
    {
        std::cout << "2D point " << i + 1 << ": " << result[i][0] << ", " << result[i][1] << std::endl;
    }

    return 0;
}

// @brief Displays the raster coordinates of a line between two points.
// @param camera: Vector of camera coordinate
// @param coords: Vector of 3D point coordinates
std::vector<std::vector<float>> convert3DTo2DCoordinates(std::vector<float> &camera, std::vector<std::vector<float>> &coords)
{
    std::vector<std::vector<float>> result(coords.size(), std::vector<float>(2));


    for (int i = 0; i < coords.size(); i++)
    {
        std::vector<float> sub(3);
        sub[0] = camera[0] - coords[i][0];
        sub[1] = camera[1] - coords[i][1];
        sub[2] = camera[2] - coords[i][2];

        std::vector<float> div(2);
        div[0] = sub[0] / sub[2];
        div[1] = sub[1] / sub[2];

        result[i] = div;
    }

    return result;
}
