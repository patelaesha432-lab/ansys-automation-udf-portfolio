/*******************************************************************************
 * File: parabolic_inlet_velocity.c
 * Description: ANSYS Fluent C UDF for a fully developed 2D parabolic velocity 
 *              profile applied at an inlet boundary condition.
 * 
 * Target Macro: DEFINE_PROFILE
 * Applicable Solvers: Pressure-Based, Serial & Parallel Execution
 ******************************************************************************/

#include "udf.h"

#define U_MEAN 5.0      /* Average inlet velocity in m/s */
#define Y_MIN -0.025    /* Lower wall coordinate in meters (-25 mm) */
#define Y_MAX  0.025    /* Upper wall coordinate in meters (+25 mm) */

DEFINE_PROFILE(inlet_parabolic_velocity, bThread, nv)
{
    face_t f;
    real x[ND_ND];              
    real y, y_mid, radius, u;

    y_mid = (Y_MAX + Y_MIN) / 2.0;
    radius = (Y_MAX - Y_MIN) / 2.0;

    begin_f_loop(f, bThread)
    {
        F_CENTROID(x, f, bThread);
        y = x[1];               

        u = 1.5 * U_MEAN * (1.0 - ((y - y_mid) * (y - y_mid)) / (radius * radius));

        F_PROFILE(f, bThread, nv) = u;
    }
    end_f_loop(f, bThread)
}
