

//
//  Simulation Methods course, 2018
//  First Assignment: Molecular Dynamics (Brownian Dynamics) Simulation
//
//  We are simulating a 2D system of particles moving in a PBC box
//  the particles have an external driving force acting on them (to the left or right)
//  they also have particle-particle repulsion (screened Coulomb type force)
//
//  a) Run the system without optimization for different system sizes
//  b) Run the system with Verlet optimization for different system sizes
//  c) Run the system with Verlet + grid optimization for different system sizes
//
//  Present:
//  - a movie file with a dense system running for a long time
//  - the running time vs the system size for the three cases on the same graph
//  - be able to answer simple questions about the code probing your
//    understanding of the code and the simulation

#include <stdio.h>

#include "initializer.h"
#include "running.h"
#include "globaldata.h"

int main(int argc, const char * argv[])
{
    if(argc != 2) 
    {
        printf("usage: ./prog_name n_particles\n");
        exit(1);
    }

    printf("Simulation Methods Course, 2018\n");
    printf("#1 Assignment Molecular Dynamics (Brownian Dynamics) simulation\n");
    printf("Unpotimized version (slowest)\n");
   
    init_simulation();
    init_simulation_box();

    init_particles();
    init_files();

    global.N_particles  = atoi(argv[1]);
    
    run_simulation();
    
    return 0;
}

