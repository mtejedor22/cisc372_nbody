#N-Body Simulation

Welcome to **CISC372 N-Body**, a parallelized N-body simulation developed for the CISC372 course. This project uses CUDA to leverage the computational power of GPUs, in addition to OpenMP for CPU-based parallelism. It simulates gravitational interactions between bodies in space, offering efficient computation for large-scale simulations.

## Table of Contents

- [Overview](#overview)
- [Installation](#installation)
- [Usage](#usage)
- [Performance](#performance)
- [Project Structure](#project-structure)

## Overview

The **CISC372 N-Body** project implements an N-body simulation to compute the gravitational forces between celestial bodies and update their positions according to Newton's laws of motion. This implementation accelerates the simulation by utilizing:

- **CUDA** for GPU parallelism, allowing computations to be distributed across thousands of CUDA cores.
- **OpenMP** for CPU parallelism on shared-memory systems.

This dual approach ensures that the simulation can take advantage of both CPUs and GPUs, making it highly scalable and efficient.

## Installation

### Prerequisites

To run this project, you'll need:

- A working C++ compiler (e.g., `g++`)
- **CUDA Toolkit** installed for GPU acceleration
- **OpenMP** for parallel CPU processing
- A CUDA-capable GPU
- `make` tool for building the project

### Installation Steps

1. Clone the repository:
    ```bash
    git clone https://github.com/mtejedor22/cisc372_nbody.git
    cd cisc372_nbody
    ```

2. Build the project using `make`:
    ```bash
    make
    ```

This will compile both the CPU (OpenMP) and GPU (CUDA) implementations of the N-body simulation.

## Usage

After building the project, you can run the N-body simulation using either the CPU (OpenMP) or GPU (CUDA).

### Running with OpenMP (CPU)

```bash
./nbody_simulation_cpu <number_of_bodies> <number_of_iterations> <time_step>
```

### Running with CUDA (GPU)

```bash
./nbody_simulation_gpu <number_of_bodies> <number_of_iterations> <time_step>
```

Where:

- `<number_of_bodies>`: The number of bodies in the simulation.
- `<number_of_iterations>`: The number of time steps to simulate.
- `<time_step>`: The duration of each time step (in seconds).

For example, to simulate 1000 bodies for 500 iterations with a time step of 0.01 seconds:

```bash
./nbody_simulation_gpu 1000 500 0.01
```

### Command-line Arguments

- `number_of_bodies`: Total number of bodies in the simulation.
- `number_of_iterations`: Number of iterations or time steps to simulate.
- `time_step`: The time step for each iteration.

### Setting OpenMP Threads

If running with OpenMP, you can specify the number of threads using the `OMP_NUM_THREADS` environment variable:

```bash
export OMP_NUM_THREADS=<number_of_threads>
./nbody_simulation_cpu 1000 500 0.01
```

## Performance

The **CISC372 N-Body** simulation demonstrates significant performance improvements when utilizing parallelism with both OpenMP and CUDA.

- **OpenMP** enables shared-memory parallelism by distributing the workload across CPU cores.
- **CUDA** offloads the computations to the GPU, allowing thousands of CUDA cores to handle the interactions, resulting in even greater speedups for large simulations.

### Example of Performance Scaling (CUDA)

| Number of Bodies | Threads | CPU Execution Time (s) | GPU Execution Time (s) |
| ---------------- | ------- | ---------------------- | ---------------------- |
| 1000             | 8       | 2.5                    | 0.4                    |
| 5000             | 8       | 14.2                   | 1.1                    |

*Performance may vary depending on hardware configuration and GPU specifications.*

## Project Structure

- `nbody_simulation_cpu.cpp`: CPU-based N-body simulation using OpenMP.
- `nbody_simulation_gpu.cu`: GPU-based N-body simulation using CUDA.
- `Makefile`: Makefile to compile both CPU and GPU versions of the project.
- `README.md`: Project documentation.
