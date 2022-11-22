#include <iostream>
#include <math.h>

using namespace std;
class Photon
{
protected:
    double waveLength;
    Photon(double waveLength) { this->waveLength = waveLength / pow(10, -10); }
};
class calculatePhotonEnergy : public Photon
{
private:
    double energy;

public:
    calculatePhotonEnergy(int p) : Photon(p) {}
    void calEnergy()
    {
        // Photon energy formula
        // E = hc/lemda
        // where h = 6.626*10^-34 js
        // c = 3 * 10^-8 ms
        energy = (6.626 * (pow(10, -34)) * 3 * pow(10, 8)) / waveLength;
        cout << "\nEnergy of photon is: " << energy;
    }
};
int main()
{
    calculatePhotonEnergy e(0.5);
    e.calEnergy();
    return 0;
}