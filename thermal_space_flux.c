#include "udf.h"

/* Custom thermal profile for spaceborne instrument heat flux */
DEFINE_PROFILE(space_solar_flux, thread, position)
{
    real x[ND_ND];
    face_t f;
    
    begin_f_loop(f, thread)
    {
        F_CENTROID(x, f, thread);
        
        /* Apply a simulated directional space heat flux model (W/m^2) */
        /* Base heat flux of 150 W/m^2 with a spatial coordinate modulation */
        F_PROFILE(f, thread, position) = 150.0 + 35.0 * sin(x[0] * 3.14159);
    }
    end_f_loop(f, thread)
}
