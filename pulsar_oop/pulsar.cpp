#include <iostream> 
#include <string>
#include <cmath> // pow
#include <cstdlib> // abs

using namespace std;

// we use cgs
#define  C_LIGHT 3e10

class Pulsar {
        string jname;
        long double F0, F1;
    public:
        // What's a pulsar but a name, a frequency and its derivative ?
        Pulsar (string, long double,long double);

        // let's be able to fetch the above.
        string giveJname (void)  {return (jname);}
        long double giveF0 (void) {return (F0) ;}
        long double giveF1 (void) {return (F1) ;}

        // Optional info for our guy.
        long double F2;
        long double NGlt;

        // Easily calculatable quantities.
        long double p (void) {return (1/F0);}
        long double pdot (void) {return (1/F1);}
        long double p2dots (void) {return (1/F2);}

        // Not so easily calculatable quantities (but still easy)

        long double n (void) { // braking index
            long double dummy = p()*p2dots() / pow(pdot(),2);
            return dummy;
        }

        long double Bsurf (void) { // surface mag field
            long double dummy = abs( p() * pdot() );
            return (3.2e19 * sqrt(dummy)); // gauss
        }

        long double Edot (void) { //energy loss
            double R = 1e5; // 10 km in cgs. Typical value

            /* there is a sinα in this equation, where α the inclination angle
            given that its value lies between 0 and 1, I've elected to ignore it */

            long double dummy = -pow(Bsurf(),2) * pow(R,6) *pow(F0,4) / (6*pow(C_LIGHT,3));
            return dummy;
        } 

        long double T_ch (void) { // spin down age, atnf assumes n=3
            long double dummy = p() / ( (n()-1) * pdot());
            return dummy*3.17098e-8; // years
        }

        // Glitch subclass. Needs DeltaP, DeltaPdot

};

// Pulsar Constructor
Pulsar::Pulsar (string a, long double b, long double c) {
    jname=a;
    F0=b;
    F1=c;
}

int main (void) {
    Pulsar psrJ0014p4746 ("J0014+4746",0.8,-3.6E-16);
    psrJ0014p4746.F2 = 7.3e-28;
    cout << "jname: " << psrJ0014p4746.giveJname() << endl;
    cout << "braking index: " << psrJ0014p4746.n() << endl;
    cout << "Age: " << psrJ0014p4746.T_ch() << endl;
    cout << "Bsurf: " << psrJ0014p4746.Bsurf() << endl;
    cout << "Edot: " << psrJ0014p4746.Edot() << endl;
    return 0;
}