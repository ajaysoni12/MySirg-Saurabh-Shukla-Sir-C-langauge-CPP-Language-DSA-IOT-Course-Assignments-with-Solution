#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#define pi 3.14159265358979323846

/* Function Prototype */
double deg2rad(double);
double rad2deg(double);
double find_distance(double lat1, double lon1, double lat2, double lon2, char unit);

/* Function Definition */
double find_distance(double lat1, double lon1, double lat2, double lon2, char unit)
{
    /* This Function calculates the distance between two points (given the latitude/longitude of those points) */

    /*  Definitions:
        South latitudes are negative, east longitudes are positive
        West latitudes are negative, north longitude are postive

        Passed to function:
        lat1, lon1 = Latitude and Longitude of point 1 (in decimal degrees)
        lat2, lon2 = Latitude and Longitude of point 2 (in decimal degrees)
        unit = the unit you desire for results
            where: 'M' is statute miles (By default)
                   'K' is kilometers
                   'N' is nautical miles
    */

    double theta, dist;
    if ((lat1 == lat2) && (lon1 == lon2))
    {
        return 0; // Because distance is 0
    }
    else
    {
        /* Apply Harvesine Formula */
        theta = lon1 - lon2;
        dist = sin(deg2rad(lat1)) * sin(deg2rad(lat2)) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * cos(deg2rad(theta));
        dist = acos(dist);
        dist = rad2deg(dist);
        dist = dist * 60 * 1.1515;
        switch (unit)
        {
        case 'M':
            break; // byDefault it is statute iles
        case 'K':
            dist = dist * 1.609344;
            break;
        case 'N':
            dist = dist * 0.8684;
            break;
        }
        return dist;
    }
}

/* This function converts decimal degrees to radians */
double deg2rad(double deg)
{
    return (deg * pi / 180);
}

/* This function converts radians to decimal degrees */
double rad2deg(double rad)
{
    return (rad * 180 / pi);
}

int main()
{
    printf("%lf", find_distance(28.7041, 77.1025, 25.5726, 88.3639,'K'));
    return 0;
}