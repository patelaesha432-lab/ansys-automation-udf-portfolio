# ANSYS Fluent Automation & Custom C UDF Suite

Automated CFD workflows using **PyAnsys (`pyfluent`)** and custom **C User Defined Functions (UDFs)** for Fluent solvers.

## Featured Code Modules

### 1. Custom C UDFs (`c-udfs/`)
* **Parabolic Velocity Profile (`parabolic_inlet_velocity.c`):** Implements a fully developed 2D parabolic velocity profile at boundary inlets using the `DEFINE_PROFILE` macro. Designed for parallel and serial execution.

### 2. PyAnsys Automation (`pyansys-automation/`)
* **Batch Solver Script (`batch_fluent_solver.py`):** Python script structure to launch ANSYS Fluent in headless mode, automate parametric iterations, and export CFD performance results.

### 3. Structural Mechanics Automation (`structural-automation/`)
* **PyMAPDL Stress Analysis Script (`pymapdl_stress_sweep.py`):** Python-driven FEA workflow to automate material definitions, boundary condition setups, structural solving, and von Mises stress extractions.
  
## Tech Stack
* **Languages:** C, Python
* **Target Software:** ANSYS Fluent, PyAnsys Core
