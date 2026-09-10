"""
Thermal Field Post-Processor using Python
Designed for parsing thermal simulation data and evaluating gradients.
"""

import numpy as np

def evaluate_thermal_limits(node_temperatures, max_allowable=360.0, min_allowable=200.0):
    """Evaluates temperature extremes and thermal gradients for space instruments."""
    max_temp = np.max(node_temperatures)
    min_temp = np.min(node_temperatures)
    gradient = np.gradient(node_temperatures)
    max_gradient = np.max(np.abs(gradient))
    
    print("--- Thermal Simulation Report ---")
    print(f"Peak Temperature: {max_temp:.2f} K (Limit: {max_allowable} K)")
    print(f"Minimum Temperature: {min_temp:.2f} K (Limit: {min_allowable} K)")
    print(f"Max Thermal Gradient: {max_gradient:.2f} K/m")
    
    if max_temp > max_allowable or min_temp < min_allowable:
        print("STATUS: Warning - Temperature bounds exceeded!")
    else:
        print("STATUS: Safe within thermal operational limits.")

if __name__ == "__main__":
    sample_temps = np.linspace(285.5, 342.1, 50)
    evaluate_thermal_limits(sample_temps)
