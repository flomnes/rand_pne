#include <cstdlib>
#include <cmath>

# define PI            3.141592653
# define PNE_RAND_MAX  1.

double PNE_Rand( double A1 )
{

A1 = A1 + PI;
A1 = pow( A1, 5. );
A1 = A1 - floor( A1 );
A1 = A1 * PNE_RAND_MAX;

if      ( A1 > PNE_RAND_MAX ) A1 = PNE_RAND_MAX;
else if ( A1 < 0.           ) A1 = 0.;

return( A1 );

}
