#!/bin/bash
#SBATCH -N 1
#SBATCH -n 1
#SBATCH -p gpu
#SBATCH -t 00:05:00
#SBATCH -J test-acc
#SBATCH --gres=gpu:p100:1
#SBATCH --reservation=Summerschool  
#SBATCH -o sum_result.out

module load cuda/10.0 pgi/19.1 openmpi/3.1.4 libpng/1.6

#srun ./sum
srun nvprof  ./sum
